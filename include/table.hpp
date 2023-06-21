#pragma once

#include <vector>
#include "stdint.h"
#include "serie.hpp"

template <typename T>
class Table 
{
  std::vector<std::vector<T>> data_table;

  public:

  Table();
  Table(uint32_t row, uint32_t col);
  Table(uint32_t row, uint32_t col, T init_value);
  Table(std::vector<std::vector<T>>& vect_2d);
  ~Table(); 

  uint32_t   get_num_col();
  uint32_t   get_num_row();

  T     get_at(uint32_t row, uint32_t col);
  void  set_at(uint32_t row, uint32_t col, T value);

  void  push_back(std::vector<T>& vect_2d);
  void  push_back(Serie<T>* serie);
  void  push_at(uint32_t row);
};