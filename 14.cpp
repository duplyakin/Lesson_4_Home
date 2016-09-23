#include <stdio.h>
#include <string.h>
#include "logger.h"

#define SIZE 16 

namespace sort {

void insertion(int array[], size_t size) {
  for (size_t j = 1; j < size; ++j) {
    int key = array[j];
    int i = j - 1;
    while (i >= 0 && array[i] > key) {
      array[i + 1] = array[i];
      --i;
    }
    array[i + 1] = key;
  }
}

}

bool binarySearch(int x, int array[], size_t size) {
  size_t first = 0;
  size_t last = size;

  while (first < last) {
    size_t mid = first + (last - first) / 2;

    if (x <= array[mid]) {
      last = mid;
    } else {
      first = mid + 1;
    }
  }

  if (last < size && array[last] == x) {
    return true;
  } else {
    return false;
  }

}

void print(int array[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    printf("%i ", array[i]);
  }
  printf("\n");
}

int main(int argc, char** argv) {
  DBG("[Lesson 4]: Home 14");

  int* array = new int[SIZE];
  memset(array, 0, SIZE);
  std::cout << "Enter array" << std::endl;
  for (int i = 0; i < SIZE; ++i ) {
    std::cin >> array[i];
  }
  int number;
  std::cout << "number" << std::endl;
  std::cin >> number;

  print(array, SIZE);
  INF("After sorting");
  sort::insertion(array, SIZE);
  print(array, SIZE);

  if (binarySearch(number, array, SIZE)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  DBG("[Lesson 4]: Home 14 [END]");
  return 0;
}

