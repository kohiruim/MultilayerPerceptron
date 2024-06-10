#ifndef _CPP7_MLP_SRC_MODEL_MODEL_H_
#define _CPP7_MLP_SRC_MODEL_MODEL_H_

#include <string>
#include <vector>

#include "neural_network/graph/graph_net.h"
#include "neural_network/matrix/matrix_net.h"
#include "neural_network/neural_network.h"
#include "parser/parserData.h"
#include "parser/parserWeights.h"
#include "tester/tester.h"
#include "trainer/trainer.h"

namespace s21 {
class ModelFacade {
 public:
  ModelFacade() = default;
  ~ModelFacade();

  void CreateNetwork(int type, int number_of_layers, bool random_weights);
  char ManTest(const std::vector<float>& example);
  bool LoadData(const std::string& file);
  bool LoadWeights(int type, const std::string& file);
  bool SaveWeights(const std::string& file);
  std::vector<Trainer::TrainerInfo> Training(int countEpochs, int groups);
  Tester::TestingInfo AutoTest(double part);
  std::vector<std::vector<float>> GetData();
  int TestIMG(const std::vector<float>& example);
  bool DataIsEmpty() const;
  bool WeightsIsEmpty() const;
  void Clear();
  double Experiment(int times);

 private:
  NeuralNetwork* neural_network_ = nullptr;
  Trainer* trainer_ = nullptr;
  Tester* tester_ = nullptr;
  ParserData data_;
  ParserWeights loaded_weights_;
};
}  // namespace s21

#endif  // _CPP7_MLP_SRC_MODEL_MODEL_H_
