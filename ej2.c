#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]){

  int pid= atoi(argv[1]);
  int signal= atoi(argv[2]);

  printf("Se ha introducido el pid: %i y el ID de senhal: %i",pid,signal);
  kill(pid,signal);

}
