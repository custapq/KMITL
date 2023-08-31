#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(){
    pid_t cpid;
    pid_t gcpid;

    cpid = fork();

    if(cpid == 0){
        gcpid = fork();
        
        if(gcpid == 0){
            printf("Can you see this3?\n");
            exit(0);
        }
        if(execlp("/bin/1ls","ls","-la",NULL)){/*A*/
            exit(0);
            printf("can you see this2?\n");/*B*/
        }
        
    }
    // else{
    //     printf("can you see this1?\n");/*C*/
    //     wait(NULL);
    //     printf("received Child Complete\n");
    //     exit(0);
    // }
    printf("can you see this1?\n");/*C*/
    return 0;
}