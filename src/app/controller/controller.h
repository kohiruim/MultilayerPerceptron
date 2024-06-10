#ifndef CPP7_MLP_SRC_CONTROLLER_CONTROLLER_H_
#define CPP7_MLP_SRC_CONTROLLER_CONTROLLER_H_
#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  Controller(s21::ModelFacade* model) : model_(model) {}
  ~Controller() = default;
  bool DataIsEmpty() const;
  bool WeightsIsEmpty() const;
  void CreateNetwork(int type, int number_of_layers, bool random_weights);
  bool ParseData(const std::string& filename);
  bool ParseWeights(int type, const std::string& filename);
  void SaveWeights(const std::string& file);
  std::vector<Trainer::TrainerInfo> Training(int countEpochs, int groups);
  Tester::TestingInfo Testing(double part);
  int TestIMG(const std::vector<float>& example);
  double Experiment(int times);
  void Clear();

 private:
  ModelFacade* model_;
};
}  // namespace s21

#endif  // CPP7_MLP_SRC_CONTROLLER_CONTROLLER_H_
