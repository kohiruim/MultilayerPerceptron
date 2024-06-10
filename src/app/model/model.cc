#include "model.h"

namespace s21 {

ModelFacade::~ModelFacade() { Clear(); }

void ModelFacade::CreateNetwork(int type, int number_of_layers,
                                bool random_weights) {
  if (neural_network_ == nullptr) {
    if (type == 0) {
      neural_network_ = new GraphNet;
    } else {
      neural_network_ = new MatrixNet;
    }
  }
  std::vector<int> topology;
  topology.clear();
  topology.emplace_back(784);
  for (int i = 0; i < number_of_layers; ++i) {
    topology.emplace_back(100);
  }
  topology.emplace_back(26);
  neural_network_->SetArchitecture(topology);
  if (random_weights) {
    neural_network_->InitializeRandomWeights();
  }
}

bool ModelFacade::LoadData(const std::string& file) {
  data_.Parse(file);
  return data_.GetError();
}

bool ModelFacade::LoadWeights(int type, const std::string& file) {
  loaded_weights_.ReadWeights(file);
  CreateNetwork(type, loaded_weights_.GetTopology().size() - 2, false);
  neural_network_->LoadWeights(loaded_weights_.GetWeights());
  return loaded_weights_.GetError();
}

bool ModelFacade::SaveWeights(const std::string& file) {
  loaded_weights_.WriteWeights(file, neural_network_->Getweights());
  return loaded_weights_.GetError();
}

std::vector<Trainer::TrainerInfo> ModelFacade::Training(int countEpochs,
                                                        int groups) {
  trainer_ = new Trainer(neural_network_);
  std::vector<Trainer::TrainerInfo> infoTest = {};
  if (groups == 0) {
    for (int i = 0; i < countEpochs; i++) {
      infoTest.push_back(trainer_->Training(data_.GetData()));
    }
  } else {
    for (int i = 0; i < countEpochs; i++) {
      infoTest.push_back(
          trainer_->TrainingWithCrossValidation(data_.GetData(), groups));
    }
  }
  return infoTest;
}

Tester::TestingInfo ModelFacade::AutoTest(double part) {
  if (tester_ == nullptr) {
    tester_ = new Tester(neural_network_);
  }
  return tester_->AutoTest(data_.GetData(), part);
}

int ModelFacade::TestIMG(const std::vector<float>& example) {
  if (tester_ == nullptr) {
    tester_ = new Tester(neural_network_);
  }
  return tester_->ManTest(example);
}

std::vector<std::vector<float>> ModelFacade::GetData() {
  return data_.GetData();
}

bool ModelFacade::DataIsEmpty() const { return data_.IsEmpty(); }

bool ModelFacade::WeightsIsEmpty() const { return loaded_weights_.IsEmpty(); }

void ModelFacade::Clear() {
  if (neural_network_ != nullptr) {
    delete neural_network_;
    neural_network_ = nullptr;
  }
  if (trainer_ != nullptr) {
    delete trainer_;
    trainer_ = nullptr;
  }
  if (tester_ != nullptr) {
    delete tester_;
    tester_ = nullptr;
  }
}

double ModelFacade::Experiment(int times) {
  double time = 0;
  s21::Tester::TestingInfo info;
  if (tester_ == nullptr) {
    tester_ = new Tester(neural_network_);
  }
  for (int i = 0; i < times; ++i) {
    info = tester_->AutoTest(data_.GetData(), 1);
    time += info.time;
  }
  return time;
}

}  // namespace s21
