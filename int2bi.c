//int2bi
//By Huang Geyang
#include<stdio.h>

void main(){
	long n = 0;
	int b[100] = {0};
	printf("Please input an integer: ");
	if (scanf("%d", &n)>0) {
		int i = 0;
		while (n > 1){
			b[i] = n%2;
			n = n/2;
			i++;
		}
		b[i] = n;
		for (int j=i;j>=0;j--) {
			printf("%d",b[j]);
		}
		printf("\n");
	}
}