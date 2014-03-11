//COMP2300 Lab2
//average
//By Huang Geyang

#include <stdio.h>

float average(float num[],int count){
    int i = 0;
    float sum = 0;
    while (i<count){
        sum += num[i];
        i += 1;
    }
    return sum/count;
}

float max(float num[],int count){
    int i = 0;
    float maxn = num[0];
    while (i<count){
        if (num[i] > maxn) {
            maxn = num[i];
        }
        i += 1;
    }
    return maxn;
}

float min(float num[],int count){
    int i = 0;
    float minn = num[0];
    while (i<count){
        if (num[i] < minn) {
            minn = num[i];
        }
        i += 1;
    }
    return minn;
}

void main(){
    float num [1000] = {0};
    int count = 0;
    float value;
    while(scanf("%f",&value)!=EOF) {
        num[count] = value;
        count += 1;
    }
    printf("average %f\n",average(num,count));
    printf("min %f\n",min(num,count));
    printf("max %f\n",max(num,count));
}
