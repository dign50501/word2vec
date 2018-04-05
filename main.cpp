#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main() {
    pid_t child_pid, grand_pid;
    int status = 0;
    int i;
    int j;
    for (i = 1; i <= 3; i++) {
        if ((child_pid = fork()) == 0) {
            if (i == 1) {
                for (j = 0; j < 2; j++) {
                    if ((grand_pid = fork()) == 0) {
                        printf("%d My PID : %d My Parents PID %d\n", j+5, getpid(), getppid());
                        exit(0);
                    }

                }
                while ((wait(&status)) > 0);
                printf("%d My PID : %d My Parents PID %d\n", i+1, getpid(), getppid());
            } else {
                while ((wait(&status)) > 0);
                sleep(1);
                printf("%d My PID : %d My Parents PID %d\n", i+1, getpid(), getppid());
            }


            exit(0);
        }
    }

    while ((wait(&status)) > 0);
    printf("1 My PID : %d\n", getpid());


}