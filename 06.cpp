#include <cstdio>
#include <cstring>
#include "logger.h"

#define SIZE 100
#define LEAST '*'

/* Stack */
// ----------------------------------------------------------------------------
int head1 = 0;
int head2 = 0;
char stack1[SIZE];
char stack2[SIZE];

void push1(char i) {
  if (head1 == SIZE) {
    ERR("Stack overflow!");
    return;
  }

  stack1[head1++] = i;
}

void push2(char i) {
  if (head2 == SIZE) {
    ERR("Stack overflow!");
    return;
  }

  stack2[head2++] = i;
}

char pop1() {
  if (head1 == 0) {
    ERR("Stack underflow!");
    return LEAST; 
  }

  return stack1[--head1];
}

char pop2() {
  if (head2 == 0) {
    ERR("Stack underflow!");
    return LEAST; 
  }

  return stack2[--head2];
}

void printStack1() {
  for (int i = 0; i < head1; ++i) {
    printf("%c ", stack1[i]);
  }
  printf("\n");
}

void printStack2() {
  for (int i = 0; i < head2; ++i) {
    printf("%c ", stack2[i]);
  }
  printf("\n");
}

bool CheckIfPalindrom() {
  int length = head1 / 2;
  while (head1 != length) {
    char ch = pop1();
    push2(ch);
  }

  char copy[length];
  memcpy(copy, stack2, length * sizeof(char));
  
  if (strncmp(stack1, copy, length) == 0) {
    return true;
  } else {
    return false;
  }

}


/* Main */
// ----------------------------------------------------------------------------
int main(int argc, char** argv) {
  DBG("[Lesson 4]: Home 06");

  char c;
  while((c = getchar()) != '\n') {
    push1(c);
  }

  if(CheckIfPalindrom()) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  DBG("[Lesson 4]: Home 06 [END]");
  return 0;
}

