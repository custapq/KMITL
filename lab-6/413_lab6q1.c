#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int csum;
int msum;

void *runner(void *param);
void *runner2(void *param);

int main(int argc,char *argv[]){

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    int num = atoi(argv[1]);
    if(num > 0){
        for(int i=0;i<=num;i++){
            msum+=i;
        }
    }

    pthread_create(&tid, &attr, runner,argv[1]);
    // pthread_join(tid,NULL);
    printf("sum = %d\n",msum);
    printf("csum = %d\n",csum);

    int diff = csum - msum;
    printf("differance csum and msum =%d\n",diff);
    return 0;
}

void *runner(void *param) {
    int n = atoi(param);
    csum = 0; 
    for (int i=1;i<=n*2;i++) {
        csum += i;
    }
    pthread_exit(0);
}