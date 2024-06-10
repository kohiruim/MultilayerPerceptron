#ifndef CPP7_MLP_SRC_MODEL_PARSER_PARSERWEIGHTS_H_
#define CPP7_MLP_SRC_MODEL_PARSER_PARSERWEIGHTS_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../neural_network/neural_network.h"

namespace s21 {
class ParserWeights {
 public:
  ParserWeights() = default;
  ~ParserWeights() = default;
  void ReadWeights(const std::string &path);
  void WriteWeights(const std::string &path,
                    std::vector<std::vector<std::vector<float>>> weights);
  std::vector<std::vector<std::vector<float>>> GetWeights();
  std::vector<int> GetTopology();
  bool GetError() const;
  bool IsEmpty() const;
  void Clear();

 private:
  std::vector<std::vector<std::vector<float>>> weights_ = {};
  std::vector<int> topology_ = {};
  bool error_ = 0;

  void ReadTopology_(std::ifstream &file);
  void ReadWeights_(std::ifstream &file);
  void WriteTopology_();
  void WriteWeights_();
};
}  // namespace s21

#endif  // CPP7_MLP_SRC_MODEL_PARSER_PARSERWEIGHTS_H_
