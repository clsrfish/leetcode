/**
 * @file stl_utils.hpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 工具类
 * @version 0.1
 * @date 2021-01-17
 *
 * @copyright Copyright (c) 2021
 *
 */
#if !defined(STL_UTILS_H)
#define STL_UTILS_H
#include <sstream>
#include <string>
#include <vector>

template <class T>
std::string vector2str(const std::vector<T> &v) {
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

#endif  // STL_UTILS_H
