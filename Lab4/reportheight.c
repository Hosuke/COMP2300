// COMP2300 Lab4
// By Huang Geyang
// use system call open and read in future
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
    //f= open()//give back integer
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


    printf("Of the %d people the average height is %2.1fm, the tallest person is Jill at %2.1fm, and shortest is Bill at %2.1fm.\n", count, sum/count, max, min);
}