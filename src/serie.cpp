#include "../include/serie.hpp"  
#include <vector>  
#include <iostream>

template class Serie<int>;
template class Serie<long>;
template class Serie<long long>;
template class Serie<unsigned int>;
template class Serie<unsigned long>;
template class Serie<unsigned long long>;
template class Serie<float>;
template class Serie<double>; 

template <typename T>  
Serie<T>::Serie(){}

template <typename T>  
Serie<T>::Serie(uint32_t size) 
{
  try {
    if (size < 0)
      throw std::bad_alloc();
    std::vector<T> vect(size);
    Serie::data_serie = vect;
  }
  catch (...)
  {
    std::cout << "[Exception] -> Series<T>::Serie(uint32_t): Failed to initialize a new Serie" << std::endl;
    exit(1);
  }
}
  
template <typename T>    
Serie<T>::Serie(std::vector<T>& vect)
{
  try
  {
    if (vect.size() != get_size())
      throw std::bad_alloc();
    Serie::data_serie = vect;
  } 
  catch (...)
  {
    std::cout << "[Exception] -> Series<T>::Serie(std::vector<T>& ): Failed to initialize a new Serie" << std::endl;
  }
}
  
template <typename T>  
Serie<T>::~Serie(){}

template <typename T>  
uint32_t  Serie<T>::get_size()
{
  return Serie::data_serie.size();
}

template <typename T>  
T         Serie<T>::get_at(int pos)
{
  try
  {
    return Serie::data_serie.at(pos);
  }
  catch(std::exception& e)
  {
    std::cout << e.what() << std::endl;
    exit(1);
  }
}

template <typename T>  
void      Serie<T>::set_at(int pos, T value)
{
  try 
  {
    if (pos >= get_size() || pos < 0)
      throw std::out_of_range();
    
    Serie::data_serie[pos] = value;
  }
}

template <typename T>  
void      Serie<T>::push_back(T value)
{
  //Serie::data_serie.push_back(value);
  /*
    Use emplace_back() only in c++17 because it have an outgoing performance
  */
  Serie::data_serie.emplace_back(value);  
}

template <typename T>  
void      Serie<T>::pop_back()
{
  Serie::data_serie.pop_back();
}