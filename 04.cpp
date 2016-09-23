#include <cstdio>
#include <cstring>
#include "logger.h"


#include <stdio.h>
int main(int argc, char** argv) {
  DBG("[Lesson 4]: Home 04");
    int ch, a = 0;
    while (ch != '\n') {
        ch = getchar();
        if (ch == '(') 
           a++;
        else 
           if (ch == ')') 
               if(--a < 0) 
                   break;
    } 
    if (a == 0) 
        printf ("Правильное\n");
    else 
        printf ("Не правильное\n");
    DBG("[Lesson 4]: Home 04 [END]");
    return 0;
}