//COMP2300 Lab1
//square
//By Huang Geyang

#include <stdio.h>
#define SIZE 4
void main(){
	printf("+");
	for (int i=0;i<SIZE;i++){
		printf("-");
	}
	printf("+\n");

	for (int i=0;i<SIZE;i++){
		printf("|");
		for (int j=0;j<SIZE;j++){
			printf(" ");
		}
		printf("|\n");
	}

	printf("+");
	for (int i=0;i<SIZE;i++){
		printf("-");
	}
	printf("+\n");
}