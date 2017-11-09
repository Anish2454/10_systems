#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

//2     SIGINT
//30    SIGUSR1

static void sighandler(int signo){
  if(signo == SIGINT) {
    //Write To File
    int fd = open("data.txt", O_CREAT|O_WRONLY, 0644);
    char msg[] = "EXITED DUE TO SIGINT\n";
    lseek(fd, 0, SEEK_END);
    write(fd, msg, sizeof(msg));
    close(fd);
    exit(1);
  }
  if(signo == SIGUSR1){
    printf("Parent PID: %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    printf("Process' PID: %d\n", getpid());
    sleep(1);
  }
}
