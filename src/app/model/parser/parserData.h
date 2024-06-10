#ifndef CPP7_MLP_SRC_MODEL_PARSER_PARSERDATA_H_
#define CPP7_MLP_SRC_MODEL_PARSER_PARSERDATA_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace s21 {
class ParserData {
 public:
  ParserData() = default;
  ~ParserData() = default;
  void Parse(const std::string& path);
  bool GetError() const;
  const std::vector<std::vector<float>>& GetData() const;
  bool IsEmpty() const;
  void Clear();

 private:
  std::vector<std::vector<float>> data_ = {};
  std::string line_;
  bool error_ = 0;

  int ReadLine_();
};
}  // namespace s21

#endif  //  CPP7_MLP_SRC_MODEL_PARSER_PARSERDATA_H_
