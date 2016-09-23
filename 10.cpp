#include <cstdio>
#include <cstring>
#include "logger.h"

#define SIZE 10
#define LEAST '*'

/* Stack */
// ----------------------------------------------------------------------------
int head = 0;
char stack[SIZE];

void push(char i) {
  if (head == SIZE) {
    ERR("Stack overflow!");
    return;
  }

  stack[head++] = i;
}

char pop() {
  if (head == 0) {
    ERR("Stack underflow!");
    return LEAST;
  }

  return stack[--head];
}

void printStack() {
  for (int i = 0; i < head; ++i) {
    printf("%c ", stack[i]);
  }
  printf("\n");
}


/* Main */
// ----------------------------------------------------------------------------
int main(int argc, char** argv) {
  DBG("[Lesson 4]: Home 10");
  
  char c;
  while((c = getchar()) != '\n') {
    push(c);
  }
  int length = head;
  for(int i = 0; i < length; ++i) {
    std::cout  << pop();
  }


  DBG("[Lesson 4]: Home 10 [END]");
  return 0;
}

