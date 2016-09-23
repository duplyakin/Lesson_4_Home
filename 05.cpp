#include <cstdio>
#include <cstring>
#include "logger.h"

/*

0. (, ), 
1. [, ], 
2. {, }, 
3. <, >

*/

#define SIZE 100
#define LEAST -1

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

int pop() {
  if (head == 0) {
    ERR("Stack underflow!");
    return LEAST;
  }

  return stack[--head];
}

void printStack() {
  printf("Stack:");
  for (int i = 0; i < head; ++i) {
    printf("%i ", stack[i]);
  }
  printf("\n");
  printf("-------------");
  printf("\n");
}



int main(int argc, char** argv) {
  DBG("[Lesson 4]: Home 05");
 
    int ch;
    int count[4] = {0, 0, 0, 0};

    while (ch != '\n') {
      ch = getchar();
      if (ch == '(') {
        //std::cout << "( :" << std::endl;
        push(0);
        ++count[0];
        //printStack();
      } else if (ch == '[') {
        push(1);
        ++count[1];
      } else if (ch == '{') {
        push(2);
        ++count[2];
      } else if (ch == '<') {
        push(3);
        ++count[3];
      } else if (ch == ')') {
        int value = pop(); 
        if (value != 0) {
          //std::cout << "Неправильный порядок Разных скобок" << std::endl;
          //std::cout << "Не правильное" << std::endl;
          //printStack();
          return 1;
        } else {
          if (--count[0] < 0) {
            //std::cout << "Неправильный порядок \"(\" скобок" << std::endl;
            //std::cout << "Не правильное" << std::endl;
            //printStack();
            return 1;
          }
        }
      } else if (ch == ']') {
          int value = pop(); 
          if (value != 1) {
            return 1;
          } else {
            if (--count[1] < 0) {
              return 1;
            }
          }
        
      } else if (ch == '}') {
          int value = pop(); 
          if (value != 2) {
            return 1;
          } else {
            if (--count[2] < 0) {
              return 1;
            }
          }
        
      } else if (ch == '>') {
          int value = pop(); 
          if (value != 3) {
            return 1;
          } else {
            if (--count[3] < 0) {
              return 1;
            }
          }
        
      }


    }


    int value = pop();
    if (count[0] == 0 && count[1] == 0 && count[2] == 0 && count[3] == 0 && value == LEAST) {
      std::cout << "  Правильное" << std::endl;
    } else {
      std::cout << "  Не правильное" << std::endl;
    }

    
    DBG("[Lesson 4]: Home 05 [END]");
    return 0;
}