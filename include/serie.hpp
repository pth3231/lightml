#pragma once

#include <vector>
#include "stdint.h"

template <typename T>
class Serie 
{
  std::vector<T> data_serie;

  public:
  
  Serie();
  Serie(uint32_t size);
  Serie(std::vector<T>& vect);
  ~Serie();

  uint32_t  get_size();

  T         get_at(int pos);
  void      set_at(int pos, T value);

  void      push_back(T value);
  void      pop_back();
};