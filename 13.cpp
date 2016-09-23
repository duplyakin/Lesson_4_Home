#include <cstdio>
#include <cstring>
#include "logger.h"


/* Main */
// ----------------------------------------------------------------------------
int main(int argc, char** argv) {
  DBG("[Lesson 4]: Home 13");
  
  char* dictionary[] = {"mathematics", "physics", "biology",
         "psychology", "geometry", "geography", "geology",
         "bioinformatics", "science", "scifi", "pharmacology",
         "musics", "analysis", "policy", "geopolicy",
         "politology", "demonology", "demonstations",
         "bioengineering", "modeling", "algebra", "literature",
         "liberation", "listing", "society", "scene", "lighting"};

  //char* word = dictionary[10];

  char* find_word;

  size_t length = 0;
  char c;
  while((c = getchar()) != '\n') {
    find_word[length++] = c;
  }

  /*
  for(int i = 0; i < length; ++i) {
    std::cout << find_word[i] << " ";
  }
  */
  std::string devider = ""; 
  for(int i = 0; i < 27; ++i) {
    if(strncmp(find_word, dictionary[i], length) == 0) {
      std::cout << devider << dictionary[i];
      devider = ", ";
    }
  }


  DBG("[Lesson 4]: Home 13 [END]");
  return 0;
}

