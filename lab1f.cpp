#include "lab1.h"
int isnt_clean(int a){
    if (a < 0) a = a * (-1);
    while (a > 0){
        if (a%10 >= ((a/10) % 10)) a/=10;
        else {
            return 1;
        }
    }
    return 0;
}