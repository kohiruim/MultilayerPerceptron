#include "tester.h"

namespace s21 {
Tester::Tester(NeuralNetwork *net) : net_(net) {}

Tester::TestingInfo Tester::AutoTest(std::vector<std::vector<float> > example,
                                     double part) {
  info_.error = 0.0;
  auto start = std::chrono::high_resolution_clock::now();
  int count_rights = 0;
  int size = static_cast<int>(example.size() * part);
  matrix confusion_matrix(26, std::vector<float>(26));
  for (int i = 0; i != size; ++i) {
    int expected = static_cast<int>(example[i].front());
    std::vector<float> input = example[i];
    net_->SetInput(input);
    net_->ForwardPropagation();
    if (net_->GetPredictionIndex() == expected) ++count_rights;
    confusion_matrix[net_->GetPredictionIndex() - 1][expected] += 1;
    info_.error += net_->GetError(expected);
  }
  auto end = std::chrono::high_resolution_clock::now();
  info_.accuracy = count_rights * 100.0 / size;
  info_.time = ((std::chrono::duration<float>)(end - start)).count();
  info_.error /= size;
  info_.precision = CalculatePrecision(confusion_matrix);
  info_.recall = CalculateRecall(confusion_matrix);
  info_.f_measure = CalculateFMeasure(info_.precision, info_.recall);
  return info_;
}

int Tester::ManTest(const std::vector<float> &example) {
  net_->SetInput(example);
  net_->ForwardPropagation();
  return net_->GetPredictionIndex();
}

double Tester::CalculatePrecision(s21::Tester::matrix &confusion_matrix) {
  double precision = 0;
  int count = 0;
  for (std::size_t i = 0; i != 26; ++i) {
    double sum = 0;
    for (std::size_t j = 0; j != 26; ++j) {
      sum += confusion_matrix[i][j];
    }
    if (confusion_matrix[i][i] != 0) {
      precision += confusion_matrix[i][i] / sum;
      ++count;
    }
  }
  return static_cast<double>(precision / count);
}

double Tester::CalculateRecall(s21::Tester::matrix &confusion_matrix) {
  double recall = 0;
  int count = 0;
  for (std::size_t i = 0; i != 26; ++i) {
    double sum = 0;
    for (std::size_t j = 0; j != 26; ++j) {
      sum += confusion_matrix[j][i];
    }
    if (sum > 0) {
      recall += confusion_matrix[i][i] / sum;
      ++count;
    }
  }
  return static_cast<double>(recall / count);
}

double Tester::CalculateFMeasure(double precision, double recall) {
  return 2 * (precision * recall) / (precision + recall);
}
}  // namespace s21
