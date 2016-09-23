#include <cstdio>
#include <cstring>
#include "logger.h"

#define SIZE 10
#define LEAST -100

/* Stack */
// ----------------------------------------------------------------------------
int head1 = 0;
int head2 = 0;
int stack1[SIZE];
int stack2[SIZE];

void push1(int i) {
  if (head1 == SIZE) {
    ERR("Stack overflow!");
    return;
  }

  stack1[head1++] = i;
}

void push2(int i) {
  if (head2 == SIZE) {
    ERR("Stack overflow!");
    return;
  }

  stack2[head2++] = i;
}

int pop1() {
  if (head1 == 0) {
    ERR("Stack underflow!");
    return LEAST; 
  }

  return stack1[--head1];
}

int pop2() {
  if (head2 == 0) {
    ERR("Stack underflow!");
    return LEAST; 
  }

  return stack2[--head2];
}

void printStack1() {
  for (int i = 0; i < head1; ++i) {
    printf("%i ", stack1[i]);
  }
  printf("\n");
}

void printStack2() {
  for (int i = 0; i < head2; ++i) {
    printf("%i ", stack2[i]);
  }
  printf("\n");
}


int getMax1() {
  int max = LEAST;
  int value = 0;
  while((value = pop1()) != LEAST) {
    if (value > max) {
      max = value;
    }
    push2(value);
  }

  while((value = pop2()) != LEAST) {
    push1(value);
  }

  return max;
}

/* Main */
// ----------------------------------------------------------------------------
int main(int argc, char** argv) {
  DBG("[Lesson 4]: Home 01");

  std::cout << "SIZE: " << SIZE << std::endl;
  for(int i = 0; i < SIZE; ++i) {
    push1(rand() % 10);
  }

  
  printStack1();
  std::cout << "-------------" << std::endl;
  std::cout << "max: " << getMax1() << std::endl;


  DBG("[Lesson 4]: Home 01 [END]");
  return 0;
}

