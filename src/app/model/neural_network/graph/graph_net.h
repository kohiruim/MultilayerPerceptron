#ifndef _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_GRAPH_GRAPH_NET_H_
#define _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_GRAPH_GRAPH_NET_H_

#include <algorithm>
#include <fstream>
#include <vector>

#include "../neural_network.h"
#include "graph_layer.h"

namespace s21 {

class GraphNet : public NeuralNetwork {
 public:
  GraphNet() = default;
  ~GraphNet() = default;

  int SetInput(const std::vector<float>& input) override;
  int GetPredictionIndex() override;
  void SetArchitecture(const std::vector<int>& layer_sizes) override;
  void InitializeRandomWeights() override;
  void ForwardPropagation() override;
  void BackwardPropagation(float learning_rate, float alpha,
                           int expected) override;
  int LoadWeights(
      const std::vector<std::vector<std::vector<float>>>& load_input) override;
  double GetError(size_t expected) override;
  std::vector<std::vector<std::vector<float>>> Getweights() override;

 private:
  std::vector<std::vector<std::vector<float>>> Inverse3DVector(
      const std::vector<std::vector<std::vector<float>>>& input);
  int layers_number_{};
  std::vector<int> geometry_;
  std::vector<GraphLayer> net_;
};

}  // namespace s21
#endif  // _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_GRAPH_GRAPH_NET_H_
