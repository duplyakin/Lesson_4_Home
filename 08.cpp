#include <cstdio>
#include <cstring>
#include "logger.h"

#define SIZE 5

/* Stack */
// ----------------------------------------------------------------------------
int head = 0;
int stack[SIZE];

void push(int i) {
  if (head == SIZE) {
    ERR("Stack overflow!");
    return;
  }

  stack[head++] = i;
}

void pop() {
  if (head == 0) {
    ERR("Stack underflow!");
    return;
  }

  --head;
}

void printStack() {
  for (int i = 0; i < head; ++i) {
    printf("%i ", stack[i]);
  }
  printf("\n");
}


/* Main */
// ----------------------------------------------------------------------------
int main(int argc, char** argv) {
  DBG("[Lesson 4]: Home 08");
  
  for(int i = 0; i < SIZE; ++i) {
    push(getchar());
  }

  printStack();

  DBG("[Lesson 4]: Home 08 [END]");
  return 0;
}

