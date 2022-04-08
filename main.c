#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

void handler_div_0(int signalNum)
{
    perror("dividing by zero is illigal. SIGFPE.");
    int a[5];
    a[100000] = 9;
    printf("%d", a[6]);
    exit(1);
}

void handler_inv_mem(int signalNum)
{
    perror("cannot address this memory address. SIGSEGV ");
    __pid_t pid = fork();
    if(pid != 0)
    {
        kill(pid, SIGTERM);
    }
    else{
        while(1);
    }
    exit(1);
}
void handler_abort(int signalNum)
{
    perror("aborting process. SIGABRT. ");
    raise(SIGINT);
    exit(1);
}
void handler_kill(int signalNum)
{
    fprintf(stderr, "Process %d has been terminated. SIGTERM ", getpid());
    perror("");
    abort();
    exit(1);
    
}
void handler_interrupt(int signalNum)
{
    fprintf(stderr, "interrupt error. SIGINT ");
    perror("");
    exit(1);
}

int main()
{
    signal(SIGFPE, &handler_div_0);
    signal(SIGSEGV, &handler_inv_mem);
    signal(SIGABRT, &handler_abort);
    signal(SIGTERM, &handler_kill);
    signal(SIGINT, &handler_interrupt);
    int a = 1/0;
    printf("%d",a);

    
    return 0;
}


