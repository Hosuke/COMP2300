#include <stdio.h>

char *choices[3]={"Scissors","Rock","Paper"};
int yourchoice(char u){
    if(u=='s'){
        return 0;
    }else if(u=='r'){
        return 1;
    }else if(u=='p'){
        return 2;
    }else{
        return -1;
    }
}

int win(int a,int b){
    if(a==b){
        return 0;
    }else if((a-b)==1||(a-b)==-2){
        return 1;
    }else{
        return 2;
    }
}

void main(){
    char userChoice [20];
    char u;
    int user = 20;
    int uscore=0;
    int cscore=0;

    while(user!=-1){

        printf("Rock, Paper, Scissors.  Enter one of: 'r', 'p', 's' \n");
        scanf("%s",&u);
        user = yourchoice(u);
        int comp=rand()%3;
        if(user==-1){
            break;
    }
        printf("You selected: %s  Computer selected: %s\n",choices[user],choices[comp]);
        int e=win(user,comp);
    if(e==0){
        printf("draw\n");
    }else if(e==1){
        uscore++;
        printf("You win.:(\n");
    }else if(e==2){
        cscore++;
        printf("Computer wins. :)\n");
    }
    printf("Your score: %d  Computer : %d\n",uscore,cscore);

    }
}
