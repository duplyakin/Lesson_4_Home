#include <stdio.h>
#include <string.h>
#include "logger.h"

namespace sort {

void insertion(char* array[], size_t size) {
  for (size_t j = 1; j < size; ++j) {
    char* key = array[j];
    int i = j - 1;
    while (i >= 0 && (strcmp(array[i], key) > 0)) { //array[i] > key
      array[i + 1] = array[i];
      --i;
    }
    array[i + 1] = key;
  }
}

}

void print(char* array[], size_t size) {
  std::string devider = " ";
  for (size_t i = 0; i < size; ++i) {
    //printf("%i ", array[i]);
    std::cout << devider << array[i];
    devider = " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: Номе 15");

  char* array[27] = {"mathematics", "physics", "biology",
         "psychology", "geometry", "geography", "geology",
         "bioinformatics", "science", "scifi", "pharmacology",
         "musics", "analysis", "policy", "geopolicy",
         "politology", "demonology", "demonstations",
         "bioengineering", "modeling", "algebra", "literature",
         "liberation", "listing", "society", "scene", "lighting"};

  print(array, 27);
  INF("After sorting");
  sort::insertion(array, 27);
  print(array, 27);

  DBG("[Lesson 1]: Номе 15 [END]");
  return 0;
}

