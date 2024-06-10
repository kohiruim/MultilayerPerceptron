#ifndef CPP7_MLP_1_SRC_TESTER_TESTER_H_
#define CPP7_MLP_1_SRC_TESTER_TESTER_H_

#include <chrono>
#include <vector>

#include "../neural_network/neural_network.h"

namespace s21 {

class Tester {
 public:
  struct TestingInfo {
    double time = 0.0;
    double error = 0.0;
    double accuracy = 0.0;
    double precision = 0.0;
    double recall = 0.0;
    double f_measure = 0.0;
  };

  Tester(NeuralNetwork *net);
  TestingInfo AutoTest(std::vector<std::vector<float>> example, double part);
  int ManTest(const std::vector<float> &example);

 private:
  using matrix = std::vector<std::vector<float>>;
  NeuralNetwork *net_;
  TestingInfo info_;

  static double CalculatePrecision(matrix &confusion_matrix);
  static double CalculateRecall(matrix &confusion_matrix);
  static double CalculateFMeasure(double precision, double recall);
};

}  // namespace s21

#endif  // CPP7_MLP_1_SRC_TESTER_TESTER_H_
