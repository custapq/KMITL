#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define clear_buffer() while(getchar() != '\n')

int main() {
    pid_t pid[3], w;
    int num, sum = 0;
    int i, status;
    printf("Enter a positive number: ");
    num = getchar() - 48; 
    clear_buffer();
    for (i = 0; i < 3; i++) {
        pid[i] = fork();
        if (pid[i] == -1) {
            perror("fork() error");
            exit(EXIT_FAILURE);
        }
        if (pid[i] == 0) {
            printf("I am child on %d. my copy of num %d\n", i, num);
            exit(i);
        }
    }
    for (i = 0; i < 3; i++) {
        w = waitpid(pid[i], &status, 0);
        if (w != -1) {
            printf("Wait on PID: %d returns value of: %d\n", w, WEXITSTATUS(status));
        }
    }
    return 0;
}
