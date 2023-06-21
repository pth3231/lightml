#include <iostream>
#include <vector>
#include "../include/table.hpp"

int main()
{
  std::vector<std::vector<int>> a = { {1, 2, 3}, 
                                      {4, 5}};
  Table<int>* tb = new Table<int>(a);
  tb->set_at(1, 2, 5);
  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 3; ++j)
      std::cout << tb->get_at(i, j) << ' ';
    std::cout << std::endl;
  }
  std::cout << tb->get_num_row() << ' ' << tb->get_num_col() << std::endl;
  return 0;
}