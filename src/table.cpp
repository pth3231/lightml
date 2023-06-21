#include <vector>
#include <iostream>

#include "stdint.h"
#include "../include/table.hpp"

template class Table<int>;
template class Table<float>;
template class Table<double>;
template class Table<unsigned long>;
template class Table<unsigned long long>;
template class Table<long>;
template class Table<long long>;
template class Table<long double>;

template <typename T>
Table<T>::Table(){}

template <typename T>
Table<T>::Table(uint32_t row, uint32_t col)
{
  std::vector<std::vector<T>> init(row, std::vector<T>(col, 0));
  Table::data_table = init;
}

template <typename T>
Table<T>::Table(uint32_t row, uint32_t col, T init_value)
{
  std::vector<std::vector<T>> init(row, std::vector<T>(col, init_value));
  Table::data_table = init;
}

template <typename T>
Table<T>::Table(std::vector<std::vector<T>>& vect_2d)
{
  try {
    uint32_t _COL_CAPACITY = vect_2d[0].size();
    for (uint32_t _INDEX = 1; _INDEX < vect_2d.size(); ++_INDEX)
      if (vect_2d[_INDEX].size() != _COL_CAPACITY)
        throw std::bad_alloc();
  } catch (...) {
    std::cout << "[Exception] -> Table<T>::Table(std::vector<std::vector<T>>): Failed to convert a 2d_vector into a Table<T>" << std::endl;
    exit(1);
  }
  Table::data_table = vect_2d;
}

template <typename T>
Table<T>::~Table()
{
  //delete Table::data_table;
} 

template <typename T>
uint32_t   Table<T>::get_num_col()
{
  return (data_table.size() == 0) ? 0 : data_table[0].size();
}

template <typename T>
uint32_t   Table<T>::get_num_row()
{
  return data_table.size();
}

template <typename T>
T     Table<T>::get_at(uint32_t row, uint32_t col)
{
  try 
  {
    if (get_num_row() == 0 || row > get_num_row())
      throw new std::out_of_range("Row out of range");
    if (get_num_col() == 0 || col > get_num_col())
      throw new std::out_of_range("Col out of range");
    return Table::data_table[row][col];
  } catch (...)
  {
    std::cout << "[Exception] -> Table<T>::get_at(uint32_t, uint32_t): Failed to get the value inside data_table[][]" << std::endl;
    exit(1);
  }
}

template <typename T>
void  Table<T>::set_at(uint32_t row, uint32_t col, T value)
{
  try 
  {
    if (get_num_row() == 0 || row > get_num_row())
      throw std::out_of_range("Row out of range");
    if (get_num_col() == 0 || col > get_num_col())
      throw std::out_of_range("Col out of range");
    Table::data_table[row][col] = value;
  } catch (...)
  {
    std::cout << "[Exception] -> Table<T>::set_at(uint32_t, uint32_t, T): Failed to set the value inside data_table[][]" << std::endl;
    exit(1);
  }
}
