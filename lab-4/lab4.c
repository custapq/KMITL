#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    pid_t pid;
    int i;
    int sum = 3;

    pid = fork();
    if(pid < 0) exit(-1);
    if(pid > 0){
        i = 1;
        sum += i;
        printf("my copy of i is %d\n",i);
    }
    else {
        i = 2;
        sum += i;
        printf("my copy of i is %d\n",i);
    }
    printf("my sum is:%d\n",sum);
    wait(NULL);
    return 0;
}

/*
    Q1 เกิดได้ 3 แบบ
    1 : my copy of i is 1 แม่เกิดก่อนลูก
        my copy of i is 2
    2 : my copy of i is 2 ลูกเกิดก่อนแม่
        my copy of i is 1
    3 : my copy of i is 2 แม่ลูกเกิดพร้อมกัน
        my copy of i is 1
        my copy of i is 2
        my copy of i is 1
    
    Q2 เพราะมี wait()ทำให้แม่ รอให้ลูกเสร็จก่อน แล้วแม่จึงสั่งจบการทำงาน
    1 : my copy of i is 1 แม่เกิดก่อนลูก
        my copy of i is 2
    2 : my copy of i is 2 ลูกเกิดก่อนแม่
        my copy of i is 1

    Q4 1 ครั้ง

    Q5 
    
*/
