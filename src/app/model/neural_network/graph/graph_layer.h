#ifndef _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_GRAPH_GRAPH_LAYER_H_
#define _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_GRAPH_GRAPH_LAYER_H_

#include <cmath>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

#include "graph_neuron.h"

namespace s21 {
class GraphLayer {
 public:
  explicit GraphLayer(int size, GraphLayer *prev_layer);
  void SetRandomWeights();
  void EvaluateNeurons();
  std::vector<float> GetLayerResult();
  size_t GetLayerSize();
  std::vector<std::vector<float>> GetWeights();
  void SetInput(const std::vector<float> &input);
  void CalculeOutputError(size_t expected);
  int LoadLayerWeights(std::vector<std::vector<float>> &load_input);
  int UpdateWeights(float learning_rate, float alpha);
  int UpdateErrorForLeftNeuron();
  std::vector<Neuron> GetLayer();
  float GetErrorValue(size_t expected);

 private:
  void InitializeWeights();
  std::function<float(float)> sigmoid_ = [](float x) {
    return 1 / (1 + std::exp(-x));
  };

  size_t size_{};
  std::vector<Neuron> layer_;
  GraphLayer *prev_layer_;
};

}  // namespace s21
#endif  // _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_GRAPH_GRAPH_LAYER_H_
