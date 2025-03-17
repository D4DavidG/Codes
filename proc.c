//David Gusmao

#include <stdio.h>
#include <unistd.h>    // fork()
#include <stdlib.h>    // exit()
#include <inttypes.h>  // intmax_t
#include <sys/wait.h>  // wait()
#include <string.h>    // strcspn(), strtok
#include <errno.h>     // ECHILD
#include <fcntl.h>     // O_RDONLY, open

enum { BUFSIZE = 1024, MAX_TOKENS = 100 };

int main(void) {
    char input[BUFSIZE];

    while (1) {
        printf("$ ");
        fflush(stdout);
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        input[strcspn(input, "\n")] = '\0';

        char *commands[3];
        int ncommands = 0;
        for (commands[ncommands] = strtok(input, "|"); commands[ncommands] != NULL; commands[++ncommands] = strtok(NULL, "|"));

        if (ncommands > 2) {
            fprintf(stderr, "Error: Only a single pipe is supported\n");
            continue;
        }

        if (ncommands == 1) {
            char *argv[MAX_TOKENS], *infile = NULL, *outfile = NULL;
            int argc = 0;
            for (argv[argc] = strtok(commands[0], " \t"); argv[argc] != NULL; argv[++argc] = strtok(NULL, " \t")) {
                if (argv[argc][0] == '<') {
                    if (infile || strlen(argv[argc]) == 1) {
                        fprintf(stderr, "Error: Invalid input redirect\n");
                        goto endOfCode;
                    }
                    infile = argv[argc] + 1;
                    argc--;
                } else if (argv[argc][0] == '>') {
                    if (outfile || strlen(argv[argc]) == 1) {
                        fprintf(stderr, "Error: Invalid output redirect\n");
                        goto endOfCode;
                    }
                    outfile = argv[argc] + 1;
                    argc--;
                }
            }
            argv[argc] = NULL;

            pid_t pid = fork();
            switch (pid) {
                case -1:
                    perror("fork");
                    exit(EXIT_FAILURE);
                case 0: // Child process
                    if (infile) {
                        int fd_in = open(infile, O_RDONLY);
                        if (fd_in < 0) {
                            perror("Input file open error");
                            _exit(EXIT_FAILURE);
                        }
                        dup2(fd_in, STDIN_FILENO);
                        close(fd_in);
                    }
                    if (outfile) {
                        int fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                        if (fd_out < 0) {
                            perror("Output file open error");
                            _exit(EXIT_FAILURE);
                        }
                        dup2(fd_out, STDOUT_FILENO);
                        close(fd_out);
                    }
                    execvp(argv[0], argv);
                    perror("execvp");
                    _exit(EXIT_FAILURE);
                    break;
                default: // Parent process
                    waitpid(pid, NULL, 0);
                    break;
            }
        } else if (ncommands == 2) {
            char *argvl[MAX_TOKENS], *infile1 = NULL, *argvr[MAX_TOKENS], *outfile2 = NULL;
            int argcl = 0, argcr = 0;

            for (argvl[argcl] = strtok(commands[0], " \t"); argvl[argcl] != NULL; argvl[++argcl] = strtok(NULL, " \t")) {
                if (argvl[argcl][0] == '<') {
                    if (infile1 || strlen(argvl[argcl]) == 1) {
                        fprintf(stderr, "Error: Invalid input redirect\n");
                        goto endOfCode;
                    }
                    infile1 = argvl[argcl] + 1;
                    argcl--;
                }
            }
            argvl[argcl] = NULL;

            for (argvr[argcr] = strtok(commands[1], " \t"); argvr[argcr] != NULL; argvr[++argcr] = strtok(NULL, " \t")) {
                if (argvr[argcr][0] == '>') {
                    if (outfile2 || strlen(argvr[argcr]) == 1) {
                        fprintf(stderr, "Error: Invalid output redirect\n");
                        goto endOfCode;
                    }
                    outfile2 = argvr[argcr] + 1;
                    argcr--;
                }
            }
            argvr[argcr] = NULL;

            int pipefds[2];
            if (pipe(pipefds) < 0) {
                perror("pipe");
                goto endOfCode;
            }

            pid_t left_pid = fork();
            switch (left_pid) {
                case -1:
                    perror("fork");
                    exit(EXIT_FAILURE);

                case 0: // Left process
                    if (infile1) {
                        int fd_in = open(infile1, O_RDONLY);
                        if (fd_in < 0) {
                            perror("Input file open error");
                            _exit(EXIT_FAILURE);
                        }
                        dup2(fd_in, STDIN_FILENO);
                        close(fd_in);
                    }
                    close(pipefds[0]);
                    dup2(pipefds[1], STDOUT_FILENO);
                    close(pipefds[1]);
                    execvp(argvl[0], argvl);
                    perror("execvp left");
                    _exit(EXIT_FAILURE);
                    break;
                default:
                    break;
            }

            pid_t right_pid = fork();
            switch (right_pid) {
                case -1:
                    perror("fork");
                    exit(EXIT_FAILURE);

                case 0: // Right process
                    if (outfile2) {
                        int fd_out = open(outfile2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                        if (fd_out < 0) {
                            perror("Output file open error");
                            _exit(EXIT_FAILURE);
                        }
                        dup2(fd_out, STDOUT_FILENO);
                        close(fd_out);
                    }
                    close(pipefds[1]);
                    dup2(pipefds[0], STDIN_FILENO);
                    close(pipefds[0]);
                    execvp(argvr[0], argvr);
                    perror("execvp right");
                    _exit(EXIT_FAILURE);
                    break;
                default:
                    break;
            }

            close(pipefds[0]);
            close(pipefds[1]);
            waitpid(left_pid, NULL, 0);
            waitpid(right_pid, NULL, 0);
        }
endOfCode:
        ;
    }
    return 0;
}
