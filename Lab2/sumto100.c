//COMP2300 Lab2
//Sum to 100
//By Huang Geyang

#include <stdio.h>

void main(){
    int value;
    int num [10000] = {0};
    int count = 0;
    int flag = 0;
    int i = 0;
    int j = 0;
    while(scanf("%d",&value)==1) {

        if (flag==0){
            num[count] = value;
            count += 1;
            for (i = 0;i<count-2;i++){
                for (j = i+1;j<count-1;j++){
                    if (num[i]+num[j]+value == 100) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1) {break;}
            }
        }

    }

    if (flag == 1){
        printf("yes\n");
    } else {
        printf("no\n");
    }
}