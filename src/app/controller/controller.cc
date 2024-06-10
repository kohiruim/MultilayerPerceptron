#include "controller.h"

namespace s21 {
bool Controller::ParseData(const std::string& filename) {
  return model_->LoadData(filename);
}

bool Controller::DataIsEmpty() const { return model_->DataIsEmpty(); }

bool Controller::WeightsIsEmpty() const { return model_->WeightsIsEmpty(); }

bool Controller::ParseWeights(int type, const std::string& filename) {
  return model_->LoadWeights(type, filename);
}

void Controller::SaveWeights(const std::string& file) {
  model_->SaveWeights(file);
}

std::vector<Trainer::TrainerInfo> Controller::Training(int countEpochs,
                                                       int groups) {
  return model_->Training(countEpochs, groups);
}

Tester::TestingInfo Controller::Testing(double part) {
  return model_->AutoTest(part);
}

void Controller::CreateNetwork(int type, int number_of_layers,
                               bool random_weights) {
  model_->CreateNetwork(type, number_of_layers, random_weights);
}

int Controller::TestIMG(const std::vector<float>& example) {
  return model_->TestIMG(example);
}

double Controller::Experiment(int times) { return model_->Experiment(times); }

void Controller::Clear() { model_->Clear(); }
}  // namespace s21
