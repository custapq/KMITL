#include <stdio.h>
int main() {
    int input, sum=0 ,count=0;
    while(1){
		
	   printf("enter positvie number :");
	   scanf("%d", &input);
	   if(input<=0){
		  break;
 	   }
	   else{
		count++;
	   }
	  sum += input;
    }
	double average = 0.0;
	if(count>0){
		average = (double)(sum/count);
	}
    printf("Arverage : %.2f \nSum :%d \n" , average,sum);
	return 0; 
}
