#include <stdio.h>
int main() {
    int input, sum=0;
    while(1){
	   printf("enter positvie number :");
	   scanf("%d", &input);
	   if(input<=0){
		  break;
 	   }
	  sum += input;
    }
    printf("Sum : %d", &sum);
}
