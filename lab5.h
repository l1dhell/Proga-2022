#pragma once 
#include <cmath>
#include <vector>
#include <iostream>
#include <type_traits>


template<typename T1, typename T2>
double exp(T1 num, typename std::enable_if<std::is_integral<T2>::value, T2>::type p) {
  double d = pow(num,p);
  return d;
}

class MyException {
public:
  MyException(std::string error) {
    i_err = error;
  }

  std::string what() { 
    return i_err; 
  }

private:
  std::string i_err;
};

template<int N, int M, class T> class Matrix
{
public:
  Matrix(std::vector <std::vector<T>> matrix_in) {
    matrix = matrix_in;
  }

  void show() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        std::cout << matrix[i][j] << " ";
      }
    }
    std::cout << "\n";
  }

  void show_el(int i, int j) {
    try {
      if ((i < 0 || i >= matrix.size())  (j < 0 || j >= matrix[0].size()))
        throw MyException("Index error");
      std::cout << matrix[i][j] << std::endl;
    }

    catch (MyException& err) {
      std::cout << err.what() << std::endl;
    }
  }

private:
  std::vector <std::vector<T>> matrix;
};