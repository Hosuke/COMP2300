//COMP2300 Lab2
//average
//By Huang Geyang

#include <stdio.h>


void main(){
    float sum = 0;
    int count = 0;
    float max = 0;
    float min = 0;
    float value;
    while(scanf("%f",&value)==1) {
        sum += value;
        count += 1;
        if (count == 1){
            max = value;
            min = value;
        } else{
            max = value>max? value:max;
            min = value<min? value:min;
        }
    }
    printf("average %f\n",sum/count);
    printf("min %f\n",min);
    printf("max %f\n",max);
}
