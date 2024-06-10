#include "graph_layer.h"

namespace s21 {

GraphLayer::GraphLayer(int size, GraphLayer* prev_layer)
    : size_(size), layer_(size, Neuron()), prev_layer_(prev_layer) {
  InitializeWeights();
}

void GraphLayer::InitializeWeights() {
  if (prev_layer_) {
    for (size_t i = 0; i < layer_.size(); ++i) {
      layer_[i].weights.resize(prev_layer_->size_, 0.0f);
      layer_[i].weight_delta.resize(prev_layer_->size_, 0.0f);
    }
  }
}

void GraphLayer::SetRandomWeights() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-0.3, 0.3);

  for (size_t i = 0; i < layer_.size(); ++i) {
    for (size_t j = 0; j < prev_layer_->size_; ++j) {
      layer_[i].weights[j] = dis(gen);
    }
  }
}

void GraphLayer::EvaluateNeurons() {
  for (auto& it : layer_) {
    float sum = 0.0f;
    size_t i = 0;
    for (auto& itw : it.weights) {
      sum += itw * prev_layer_->layer_[i].result;
      ++i;
    }
    it.result = sigmoid_(sum);
  }
}

std::vector<float> GraphLayer::GetLayerResult() {
  std::vector<float> res;
  res.reserve(size_);
  for (const auto& it : layer_) {
    res.emplace_back(it.result);
  }
  return res;
}

size_t GraphLayer::GetLayerSize() { return size_; }

void GraphLayer::SetInput(const std::vector<float>& input) {
  if (input.size() - 1 == size_) {
    for (size_t i = 1; i <= size_; ++i) {
      layer_[i - 1].result = input[i] / 255.0f;
    }
  }
}

void GraphLayer::CalculeOutputError(size_t expected) {
  size_t index = 0;
  for (auto& it : layer_) {
    int target = static_cast<int>((index == (expected - 1)) ? 1 : 0);
    float output = it.result;
    float sigmoid_derivative = output * (1 - output);
    it.error = -(target - output) * sigmoid_derivative;
    ++index;
  }
}

int GraphLayer::UpdateWeights(float learning_rate, float alpha) {
  size_t i_max = layer_.size();
  for (size_t i = 0; i < i_max; ++i) {
    size_t j_max = prev_layer_->layer_.size();
    for (size_t j = 0; j < j_max; ++j) {
      layer_[i].weight_delta[j] =
          (alpha * layer_[i].weight_delta[j]) +
          (1 - alpha) *
              (learning_rate * layer_[i].error * prev_layer_->layer_[j].result);
      layer_[i].weights[j] -= layer_[i].weight_delta[j];
    }
  }
  return 0;
}

int GraphLayer::UpdateErrorForLeftNeuron() {
  size_t i = 0;
  for (auto& prev_neuron : prev_layer_->layer_) {
    float output = prev_neuron.result;
    float sigmoid_derivative = output * (1 - output);
    float sum_err = 0.0f;

    for (auto& it : layer_) {
      if (i < it.weights.size()) {
        sum_err += it.weights[i] * it.error;
      } else {
        return 1;
      }
    }
    prev_neuron.error = sum_err * sigmoid_derivative;
    ++i;
  }
  return 0;
}

std::vector<std::vector<float>> GraphLayer::GetWeights() {
  std::vector<std::vector<float>> res{};
  res.clear();
  res.reserve(layer_.size());
  for (auto& it : layer_) {
    res.emplace_back(it.weights);
  }
  return res;
}

std::vector<Neuron> GraphLayer::GetLayer() { return layer_; }

int GraphLayer::LoadLayerWeights(std::vector<std::vector<float>>& load_input) {
  for (size_t i = 0; i < layer_.size(); ++i) {
    for (size_t j = 0; j < layer_[i].weights.size(); ++j) {
      layer_[i].weights[j] = load_input[i][j];
    }
  }
  return 0;
}

float GraphLayer::GetErrorValue(size_t expected) {
  float error = 0.0f;
  if (expected <= layer_.size() && expected > 1) {
    error = layer_[expected - 1].result;
  }
  return error;
}

}  // namespace s21
