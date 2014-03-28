//COMP2300 Lab2
//Sum to 100 n^2 version(currenct lab record holder)
//By Huang Geyang

#include <stdio.h>

void main(){
    int value;
    int num [10000] = {0};
    int d2 [10000000] ={0};
    int count = 0;
    int d2count = 0;
    int flag = 0;
    int i = 0;

    while(scanf("%d",&value)==1) {

        if (flag==0){
            num[count] = value;
            count += 1;

            if (count>2){
                for (i=0;i<d2count;i++){
                    if (value+d2[i]==100){
                        flag = 1;
                        break;
                    }
                }
            }

            if (count>1 && flag == 0){
                for (i=0;i<count-1;i++){
                    d2[d2count]=value+num[i];
                    d2count += 1;
                    //printf("%d\n",d2[d2count-1]);
                }
            }


        }

    }

    if (flag == 1){
        printf("yes\n");
    } else {
        printf("no\n");
    }
}
