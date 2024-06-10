#ifndef CPP7_MLP_1_SRC_TRAINER_TRAINER_H_
#define CPP7_MLP_1_SRC_TRAINER_TRAINER_H_

#include <chrono>
#include <memory>
#include <vector>

#include "../neural_network/neural_network.h"

namespace s21 {
class Trainer {
 public:
  struct TrainerInfo {
    double time = 0.0;
    double error = 0.0;
    double accuracy = 0.0;
  };
  Trainer(NeuralNetwork *net);
  TrainerInfo Training(const std::vector<std::vector<float>> &data_set);
  TrainerInfo TrainingWithCrossValidation(
      const std::vector<std::vector<float>> &data_set, int groups);

 private:
  NeuralNetwork *net_;
  TrainerInfo info_;

  void SetDefaultInfo();
  void TrainCrossValidation(int number, int lines,
                            const std::vector<std::vector<float>> &data_set);
  void TestCrossValidation(int number, int lines, int &count_rights,
                           const std::vector<std::vector<float>> &data_set);
};

}  // namespace s21

#endif  // CPP7_MLP_1_SRC_TRAINER_TRAINER_H_
