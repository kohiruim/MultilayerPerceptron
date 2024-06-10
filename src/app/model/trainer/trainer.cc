#include "trainer.h"

namespace s21 {

Trainer::Trainer(s21::NeuralNetwork *net) : net_(net) {}

void Trainer::SetDefaultInfo() {
  info_.accuracy = 0.0;
  info_.error = 0.0;
  info_.time = 0.0;
}

Trainer::TrainerInfo Trainer::Training(
    const std::vector<std::vector<float>> &data_set) {
  SetDefaultInfo();
  auto start = std::chrono::high_resolution_clock::now();
  int count_rights = 0;
  for (const auto &data : data_set) {
    int expected = static_cast<int>(data.front());
    std::vector<float> input(data.begin(), data.end());
    net_->SetInput(input);
    net_->ForwardPropagation();
    if (net_->GetPredictionIndex() == expected) count_rights++;
    info_.error += net_->GetError(expected);
    net_->BackwardPropagation(0.3, 0.1, expected);
  }

  auto end = std::chrono::high_resolution_clock::now();
  info_.accuracy = count_rights * 100. / static_cast<double>(data_set.size());
  info_.time = ((std::chrono::duration<float>)(end - start)).count();
  info_.error /= static_cast<int>(data_set.size());

  return info_;
}

Trainer::TrainerInfo Trainer::TrainingWithCrossValidation(
    const std::vector<std::vector<float>> &data_set, int groups) {
  SetDefaultInfo();
  auto start = std::chrono::high_resolution_clock::now();
  int data_set_size = static_cast<int>(data_set.size());
  int lines = data_set_size / groups;
  int count_rights = 0;
  for (int i = 0, ie = groups; i != ie; ++i) {
    TrainCrossValidation(i, lines, data_set);
    TestCrossValidation(i, lines, count_rights, data_set);
  }
  auto end = std::chrono::high_resolution_clock::now();

  info_.accuracy = count_rights * 100. / static_cast<double>(data_set.size());
  info_.time = ((std::chrono::duration<float>)(end - start)).count();
  info_.error /= static_cast<int>(data_set.size());
  return info_;
}

void Trainer::TrainCrossValidation(
    int number, int lines, const std::vector<std::vector<float>> &data_set) {
  int i = 0;
  for (int j = 0, je = static_cast<int>(data_set.size()); j != je; ++j) {
    if (j == number * lines) {
      j = lines * (number + 1) - 1;
      i += lines;
    } else {
      int expected = static_cast<int>(data_set[i].front());
      std::vector<float> input = data_set[i];
      // input.erase(input.begin());
      net_->SetInput(input);
      net_->ForwardPropagation();
      net_->BackwardPropagation(0.3, 0.1, expected);
      ++i;
    }
  }
}

void Trainer::TestCrossValidation(
    int number, int lines, int &count_rights,
    const std::vector<std::vector<float>> &data_set) {
  int i = 0;
  for (int j = 0, je = static_cast<int>(data_set.size()); j != je; ++j) {
    if (j >= number * lines && j < lines * (number + 1)) {
      int expected = static_cast<int>(data_set[i].front());
      std::vector<float> input = data_set[i];
      net_->SetInput(input);
      net_->ForwardPropagation();
      int prediction = net_->GetPredictionIndex();
      if (prediction == expected) {
        ++count_rights;
      }
      info_.error += net_->GetError(expected);
      ++i;
    } else {
      i += lines;
      j += lines - 1;
    }
  }
}
}  // namespace s21
