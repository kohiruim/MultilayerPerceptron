#include "graph_net.h"

namespace s21 {

void GraphNet::SetArchitecture(const std::vector<int>& layer_sizes) {
  layers_number_ = layer_sizes.size();
  geometry_ = layer_sizes;

  net_.clear();
  net_.reserve(layers_number_);

  for (int i = 0; i < layers_number_; ++i) {
    if (i > 0) {
      net_.emplace_back(geometry_[i], &net_[i - 1]);
    } else {
      net_.emplace_back(geometry_[i], nullptr);
    }
  }
}

void GraphNet::InitializeRandomWeights() {
  for (int i = 1; i < layers_number_; ++i) {
    net_[i].SetRandomWeights();
  }
}

int GraphNet::SetInput(const std::vector<float>& input) {
  if (input.size() - 1 == net_[0].GetLayerSize()) {
    net_[0].SetInput(input);
    return 0;
  } else {
    return 1;
  }
}

int GraphNet::LoadWeights(
    const std::vector<std::vector<std::vector<float>>>& load_input) {
  std::vector<std::vector<std::vector<float>>> weights =
      Inverse3DVector(load_input);
  int error = 0;
  for (size_t i = 0; i < weights.size(); ++i) {
    error = net_[i + 1].LoadLayerWeights(weights[i]);
  }
  return error;
}

void GraphNet::ForwardPropagation() {
  for (int i = 1; i < layers_number_; ++i) {
    net_[i].EvaluateNeurons();
  }
}

int GraphNet::GetPredictionIndex() {
  const std::vector<float>& output = net_.back().GetLayerResult();
  auto max_it = std::max_element(output.begin(), output.end());
  return std::distance(output.begin(), max_it) + 1;
}

void GraphNet::BackwardPropagation(float learning_rate, float alpha,
                                   int expected) {
  net_.back().CalculeOutputError(expected);
  for (int i = layers_number_ - 1; i > 0; --i) {
    net_[i].UpdateErrorForLeftNeuron();
    net_[i].UpdateWeights(learning_rate, alpha);
  }
}

double GraphNet::GetError(size_t expected) {
  return pow(net_.back().GetErrorValue(expected) - 1, 2);
}

std::vector<std::vector<std::vector<float>>> GraphNet::Getweights() {
  std::vector<std::vector<std::vector<float>>> weights{};
  weights.clear();
  for (int i = 1; i < layers_number_; ++i) {
    weights.push_back(net_[i].GetWeights());
  }
  return Inverse3DVector(weights);
}

std::vector<std::vector<std::vector<float>>> GraphNet::Inverse3DVector(
    const std::vector<std::vector<std::vector<float>>>& input) {
  size_t x_size = input.size();
  std::vector<std::vector<std::vector<float>>> output(x_size);

  for (size_t i = 0; i < input.size(); ++i) {
    size_t y_size = input[i].size();
    size_t z_size = input[i][0].size();
    output[i].resize(z_size, std::vector<float>(y_size));

    for (size_t j = 0; j < y_size; ++j) {
      for (size_t k = 0; k < z_size; ++k) {
        output[i][k][j] = input[i][j][k];
      }
    }
  }
  return output;
}

}  // namespace s21
