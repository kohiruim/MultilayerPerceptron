#ifndef _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_MATRIX_MATRIX_NET_H_
#define _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_MATRIX_MATRIX_NET_H_

#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

#include "../neural_network.h"

namespace s21 {

class MatrixNet : public NeuralNetwork {
 public:
  MatrixNet() = default;
  ~MatrixNet() = default;

  int SetInput(const std::vector<float>& input) override;
  int GetPredictionIndex() override;
  void SetArchitecture(const std::vector<int>& layer_sizes) override;
  void InitializeRandomWeights() override;
  void ForwardPropagation() override;
  void BackwardPropagation(float learning_rate, float alpha,
                           int expected) override;
  int LoadWeights(const std::vector<std::vector<std::vector<float>>>&
                      loaded_weights) override;
  double GetError(size_t expected) override;
  std::vector<std::vector<std::vector<float>>> Getweights() override;

 private:
  using matrix = std::vector<std::vector<float>>;
  void CalculeOutputError(size_t expected);
  void UpdateWeights(float learning_rate, float alpha);
  void UpdateErrorForLeftNeuron();

  matrix neuron_value_;
  matrix neuron_error_;
  std::vector<matrix> weights_delta_;
  std::vector<matrix> weights_;
  std::function<float(float)> sigmoid_ = [](float x) {
    return 1 / (1 + std::exp(-x));
  };
};

}  // namespace s21
#endif  //_CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_MATRIX_MATRIX_NET_H_
