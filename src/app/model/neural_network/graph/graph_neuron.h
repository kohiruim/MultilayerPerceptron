#ifndef _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_GRAPH_GRAPH_NEURON_H_
#define _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_GRAPH_GRAPH_NEURON_H_

#include <vector>

namespace s21 {

struct Neuron {
  float result = 0;
  float error = 0;
  std::vector<float> weight_delta;
  std::vector<float> weights;
};

}  // namespace s21
#endif  // _CPP7_MLP_SRC_MODEL_NEURAL_NETWORK_GRAPH_GRAPH_NEURON_H_
