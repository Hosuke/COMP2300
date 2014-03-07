//COMP2300 Lab1
//triangle
//By Huang Geyang

#include <stdio.h>
#define SIZE 4
void main(){
    printf("+\n");

    for (int i=0;i<SIZE;i++){
        printf("|");
        for (int j=0;j<i;j++){
            printf(" ");
        }
        printf("\\");
        printf("\n");
    }

    printf("+");
    for (int i=0;i<SIZE;i++){
        printf("-");
    }
    printf("+\n");
}