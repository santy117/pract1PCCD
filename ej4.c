#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void type_signal(int);
void terminate();

int fin=0;
int num_usr1=0;
int num_usr2=0;

int main(){
  printf("PID DEL PROCESO: %d",getpid());
  printf("\n");
  

  struct sigaction act;
  printf("Esperamos por una accion...\n");

  act.sa_handler = terminate;
  sigaction(15,&act, NULL);

  //Si recibimos una interrupcion 15, lo tenemos confirmado para que ejecute terminate()

  act.sa_handler = type_signal;
  sigaction(10,&act,NULL);
  act.sa_handler= type_signal;
  sigaction(12,&act,NULL);
  // si recibimos una interrupcion 10 o 12 llamamos a type_signal que incrementara el numero de usr1 o usr2 dependiendo de si se llama a 10 o a 12.

  while(fin != 1){
    pause();

  }
}

void terminate(){

  printf("NUM_USR1: %i, NUM_USR2: %i \n",num_usr1,num_usr2);
  fin = 1;
}
void type_signal(int id_sign){
  if(id_sign== 10){
    num_usr1++;
  }
  if(id_sign==12){
    num_usr2++;
  }
}
