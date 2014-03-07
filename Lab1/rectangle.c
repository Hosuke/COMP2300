//COMP2300 Lab1
//rectangle
//By Huang Geyang

#include <stdio.h>
#define WIDTH 4
#define HEIGHT 6
void main(){
    printf("+");
    for (int i=0;i<WIDTH;i++){
        printf("-");
    }
    printf("+\n");

    for (int i=0;i<HEIGHT;i++){
        printf("|");
        for (int j=0;j<WIDTH;j++){
            printf(" ");
        }
        printf("|\n");
    }

    printf("+");
    for (int i=0;i<WIDTH;i++){
        printf("-");
    }
    printf("+\n");
}