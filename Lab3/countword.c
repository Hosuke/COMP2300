# include <stdio.h>
# define MAXLEN 300

void main(){
    int count = 0;
    char str [MAXLEN];
    char c;
    while (scanf("%c",c)==1){
        count+=1

    }
    /*while (scanf("%s\n",str)==1){
        count += 1;
    }*/
    printf("%d\n",count);
}