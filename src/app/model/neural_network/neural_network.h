#ifndef _CPP7_MLP_SRC_NEURAL_NETWORK_NEURAL_NETWORK_H_
#define _CPP7_MLP_SRC_NEURAL_NETWORK_NEURAL_NETWORK_H_

#include <string>
#include <vector>

namespace s21 {
class NeuralNetwork {
 public:
  NeuralNetwork() = default;
  virtual ~NeuralNetwork() = default;

  virtual int SetInput(const std::vector<float> &) { return 0; }
  virtual int GetPredictionIndex() { return 0; }
  virtual void SetArchitecture(const std::vector<int> &) {}
  virtual void InitializeRandomWeights() {}
  virtual void ForwardPropagation() {}
  virtual void BackwardPropagation(float, float, int) {}
  virtual int LoadWeights(
      const std::vector<std::vector<std::vector<float>>> &) {
    return 0;
  }
  virtual double GetError(size_t) { return 0; }
  virtual std::vector<std::vector<std::vector<float>>> Getweights() {
    return {};
  }
};
}  // namespace s21

#endif  //_CPP7_MLP_SRC_NEURAL_NETWORK_NEURAL_NETWORK_H_
