//COMP2300 Lab2
//welcome
//By Huang Geyang

#include <stdio.h>

void main(){
    char name [80];
    if (scanf("%79s",name)>0) {
        printf("Hello %s\n",name);
    }
}