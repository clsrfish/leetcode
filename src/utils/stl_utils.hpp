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
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

template <class T>
std::string vector2str(const std::vector<T> &v, int len = -1) {
  std::stringstream ss;
  if (len < 0) {
    len = v.size();
  }
  int vSize = v.size();
  len = std::min(len, vSize);

  ss << "[";
  for (size_t i = 0; i < len; i++) {
    ss << v[i];
    if (i != len - 1) {
      ss << ", ";
    }
  }
  ss << "]";
  return ss.str();
}

#endif  // STL_UTILS_H
