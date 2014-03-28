// COMP2300 Lab4
// By Huang Geyang
#include <stdio.h>

struct person{
    char name[30];
    float height;
};


void main(){
    FILE *ifp;
    struct person people [101];
    int count = 0;
    struct person single;
    ifp = fopen("data.txt","r");
    float sum = 0;
    float max = 0;
    float min = 10000000;

    while (fscanf(ifp, "%s %f", single.name, &single.height) != EOF) {
        people[count] = single;
        sum += single.height;
        max = single.height > max ? single.height:max;
        min = single.height < min ? single.height:min;
        count += 1;
    }


    printf("Of the %d people the average height is %fm, the tallest person is Jill at %fm, and shortest is Bill at %fm.\n", count, sum/count, max, min);
}