#include "matrix_net.h"

namespace s21 {

void MatrixNet::SetArchitecture(const std::vector<int>& layer_sizes) {
  size_t i_max = layer_sizes.size();
  neuron_value_.resize(i_max);
  neuron_error_.resize(i_max);

  for (size_t i = 0; i < i_max; ++i) {
    neuron_value_[i].resize(layer_sizes[i], 0.0f);
    neuron_error_[i].resize(layer_sizes[i], 0.0f);
  }

  weights_delta_.resize(i_max - 1);
  weights_.resize(i_max - 1);
  for (size_t k = 0; k < i_max - 1; ++k) {
    weights_[k].resize(layer_sizes[k]);
    weights_delta_[k].resize(layer_sizes[k]);
    for (int j = 0; j < layer_sizes[k]; ++j) {
      weights_[k][j].resize(layer_sizes[k + 1], 0.0f);
      weights_delta_[k][j].resize(layer_sizes[k + 1], 0.0f);
    }
  }
}

void MatrixNet::InitializeRandomWeights() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-0.3, 0.3);

  size_t i_max = weights_.size();
  for (size_t i = 0; i < i_max; ++i) {
    size_t j_max = weights_[i].size();
    for (size_t j = 0; j < j_max; ++j) {
      size_t k_max = weights_[i][j].size();
      for (size_t k = 0; k < k_max; ++k) {
        weights_[i][j][k] = dis(gen);
      }
    }
  }
}

int MatrixNet::SetInput(const std::vector<float>& input) {
  int result = 0;
  if (input.size() - 1 != neuron_value_[0].size()) {
    result = 1;
  } else {
    size_t i_max = neuron_value_[0].size();
    for (size_t i = 0; i < i_max; ++i) {
      neuron_value_[0][i] = input[i + 1] / 255;
    }
  }
  return result;
}

void MatrixNet::ForwardPropagation() {
  size_t i_max = neuron_value_.size();
  for (size_t i = 0; i < i_max - 1; ++i) {
    size_t j_max = neuron_value_[i + 1].size();
    for (size_t j = 0; j < j_max; ++j) {
      float sum = 0.0f;
      size_t k_max = neuron_value_[i].size();
      for (size_t k = 0; k < k_max; ++k) {
        sum += weights_[i][k][j] * neuron_value_[i][k];
      }
      neuron_value_[i + 1][j] = sigmoid_(sum);
    }
  }
}

int MatrixNet::GetPredictionIndex() {
  const std::vector<float>& output = neuron_value_.back();
  auto max_it = std::max_element(output.begin(), output.end());
  return std::distance(output.begin(), max_it) + 1;
}

void MatrixNet::BackwardPropagation(float learning_rate, float alpha,
                                    int expected) {
  CalculeOutputError(expected);
  UpdateErrorForLeftNeuron();
  UpdateWeights(learning_rate, alpha);
}

void MatrixNet::CalculeOutputError(size_t expected) {
  size_t index = 0;
  size_t i_max = neuron_value_.back().size();
  for (size_t i = 0; i < i_max; ++i) {
    int target = (index == (expected - 1)) ? 1 : 0;
    float output = neuron_value_.back()[i];
    float sigmoid_derivative = output * (1 - output);
    neuron_error_.back()[i] = -(target - output) * sigmoid_derivative;
    ++index;
  }
}

void MatrixNet::UpdateErrorForLeftNeuron() {
  for (size_t i = neuron_error_.size() - 2; i > 0; --i) {
    size_t j_max = neuron_error_[i].size();
    for (size_t j = 0; j < j_max; ++j) {
      float output = neuron_value_[i][j];
      float sigmoid_derivative = output * (1 - output);
      float sum_err = 0.0f;
      size_t k_max = neuron_error_[i + 1].size();
      for (size_t k = 0; k < k_max; ++k) {
        sum_err += weights_[i][j][k] * neuron_error_[i + 1][k];
      }
      neuron_error_[i][j] = sum_err * sigmoid_derivative;
    }
  }
}

void MatrixNet::UpdateWeights(float learning_rate, float alpha) {
  size_t i_max = weights_.size();
  for (size_t i = 0; i < i_max; ++i) {
    size_t j_max = weights_[i].size();
    for (size_t j = 0; j < j_max; ++j) {
      size_t k_max = weights_[i][j].size();
      for (size_t k = 0; k < k_max; ++k) {
        weights_delta_[i][j][k] =
            (alpha * weights_delta_[i][j][k]) +
            (1 - alpha) *
                (learning_rate * neuron_error_[i + 1][k] * neuron_value_[i][j]);
        weights_[i][j][k] -= weights_delta_[i][j][k];
      }
    }
  }
}

std::vector<std::vector<std::vector<float>>> MatrixNet::Getweights() {
  return weights_;
}

int MatrixNet::LoadWeights(
    const std::vector<std::vector<std::vector<float>>>& load_input) {
  int result = 0;
  if (load_input.size() != weights_.size() ||
      load_input[0].size() != weights_[0].size()) {
    result = 1;
  } else {
    weights_ = load_input;
  }
  return result;
}

double MatrixNet::GetError(size_t expected) {
  double error = 0.0;
  if (neuron_value_.back().size() >= expected && expected > 1) {
    error = pow(neuron_value_.back()[expected - 1] - 1, 2);
  }
  return error;
}
}  // namespace s21
