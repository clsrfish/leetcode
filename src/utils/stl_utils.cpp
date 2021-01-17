#include "stl_utils.hpp"

std::string int_vector2str(const std::vector<int> &v) {
  std::stringstream ss;
  ss << "[";
  for (size_t i = 0; i < v.size(); i++) {
    ss << v[i];
    if (i != v.size() - 1) {
      ss << ", ";
    }
  }
  ss << "]";
  return ss.str();
}