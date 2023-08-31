#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    char userChoide = 'z';
    while(userChoide != 'q'){
        printf("---------------------\n");
        printf("a: ls \n");
        printf("b: ps \n");
        printf("c: who \n");
        printf("q for quit \n");
        printf("---------------------\n");
        scanf(" %c", &userChoide);
        
        pid_t pid = fork();

        if(pid == 0){
            if(userChoide == 'a'){
                execlp("/usr/bin/ls","ls",NULL);
            }
            else if(userChoide == 'b'){
                execlp("/usr/bin/ps","ps",NULL);
            }
            else if(userChoide == 'c'){
                execlp("/usr/bin/whoami","whoami",NULL);
            }
            else if(userChoide == 'q'){
                exit(0);
            }
        }
        else {
            wait(NULL);
        }
    }
    printf("parent terminated\n");
    return 0;
}