#include "parserWeights.h"

namespace s21 {
void ParserWeights::ReadWeights(const std::string &path) {
  weights_.clear();
  topology_.clear();
  error_ = 0;
  std::ifstream file(path);
  if (file.is_open() && file.peek() != EOF) {
    error_ = 0;
    ReadTopology_(file);
    ReadWeights_(file);
    file.close();
  } else {
    error_ = 1;
  }
}

void ParserWeights::WriteWeights(
    const std::string &path,
    std::vector<std::vector<std::vector<float>>> weights) {
  std::ofstream out;
  out.open(path);
  if (out.is_open()) {
    out << weights.size() + 1 << " ";
    for (auto &i : weights) {
      out << i.size() << " ";
    }
    out << "26"
        << "\n";
    for (std::size_t x = 0; x < weights.size(); x++) {
      for (std::size_t y = 0; y < weights[x].size(); y++) {
        for (std::size_t z = 0; z < weights[x][y].size(); ++z) {
          out << weights[x][y][z] << " ";
        }
      }
    }
    out.close();
  } else {
    error_ = 1;
  }
}

void ParserWeights::ReadTopology_(std::ifstream &file) {
  int count_layers, count_neurons;
  file >> count_layers;
  for (int i = 0; i < count_layers; i++) {
    file >> count_neurons;
    topology_.push_back(count_neurons);
  }
}

void ParserWeights::ReadWeights_(std::ifstream &file) {
  float value = 0.0;
  for (size_t i = 0; i < topology_.size() - 1; i++) {
    std::vector<std::vector<float>> v2;
    for (int j = 0; j < topology_[i]; j++) {
      std::vector<float> v1;
      for (int k = 0; k < topology_[i + 1]; k++) {
        file >> value;
        v1.push_back(value);
      }
      v2.push_back(v1);
    }
    weights_.push_back(v2);
  }
}

bool ParserWeights::IsEmpty() const { return !weights_.size(); }

bool ParserWeights::GetError() const { return error_; }

std::vector<std::vector<std::vector<float>>> ParserWeights::GetWeights() {
  return weights_;
}

std::vector<int> ParserWeights::GetTopology() { return topology_; }

void ParserWeights::Clear() {
  weights_.clear();
  topology_.clear();
  weights_ = {};
  topology_ = {};
  error_ = 0;
}

}  // namespace s21
