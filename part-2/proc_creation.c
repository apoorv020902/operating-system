#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_multiple_children(int num_children) {
    for (int i = 0; i < num_children; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Failed to create child process");
            exit(1);
        } else if (pid == 0) {
            // Child process
            printf("Hello from child process with PID: %d\n", getpid());
            exit(0);
        }
    }

    // Parent waits for all children to finish
    for (int i = 0; i < num_children; i++) {
        wait(NULL);
    }
}

void create_process_chain(int num_children) {
    pid_t pid;
    for (int i = 0; i < num_children; i++) {
        pid = fork();
        if (pid < 0) {
            perror("Failed to create child process");
            exit(1);
        } else if (pid == 0) {
            // If this is the last child in the chain
            if (i == num_children - 1) {
                printf("Hello from the last child in chain with PID: %d\n", getpid());
            }
            // Continue to the next child in the chain
        } else {
            // Parent waits for its child before exiting
            wait(NULL);
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <mode> <num_children>\n", argv[0]);
        fprintf(stderr, "mode 1: multiple children, mode 2: process chain\n");
        return 1;
    }

    int mode = atoi(argv[1]);
    int num_children = atoi(argv[2]);

    if (mode == 1) {
        create_multiple_children(num_children);
    } else if (mode == 2) {
        create_process_chain(num_children);
    } else {
        fprintf(stderr, "Invalid mode. Use 1 for multiple children or 2 for process chain.\n");
        return 1;
    }

    return 0;
}
