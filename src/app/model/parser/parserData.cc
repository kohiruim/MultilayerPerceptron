#include "parserData.h"

namespace s21 {
void ParserData::Parse(const std::string& path) {
  std::ifstream file(path);
  error_ = 0;
  data_.clear();
  if (file.is_open() && !(file.peek() == EOF)) {
    while (std::getline(file, line_)) {
      error_ = ReadLine_();
    }
    file.close();
  } else {
    error_ = 1;
  }
}

int ParserData::ReadLine_() {
  int count = 0, result = 0;
  if (!line_.empty()) {
    std::string str = "";
    std::vector<float> dataVector;
    dataVector.clear();
    for (auto iter = line_.begin(); iter != line_.end(); ++iter) {
      if (std::isdigit(*iter)) {
        str += *iter;
      }
      if ((*iter == ',' || iter == line_.end() - 1) && !str.empty()) {
        ++count;
        dataVector.push_back(std::stod(str));
        str = "";
      }
    }
    data_.push_back(dataVector);
  }
  if (count != 785) {
    result = 1;
  }
  return result;
}

bool ParserData::GetError() const { return error_; }

const std::vector<std::vector<float>>& ParserData::GetData() const {
  return data_;
}

bool ParserData::IsEmpty() const { return data_.empty(); }

void ParserData::Clear() {
  data_.clear();
  data_ = {};
  error_ = 0;
}
}  // namespace s21
