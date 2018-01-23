#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void subir(int);
void bajar(int);
void terminate(int);
void parado(int);

int n_subidas, n_bajadas, salir, T_PISO;
int piso, piso_max, piso_min;
int control;

int main(int argc, char* argv[]){
  n_subidas = 0;
  n_bajadas = 0;
  control =0;
  salir = 0;
  T_PISO = 1;
  piso_max = atoi(argv[1]);
  piso_min = atoi(argv[2]);
  piso = atoi(argv[3]);
  int status, i;
  struct sigaction act;
  printf("PID DEL PROCESO: %d\n",getpid());
  for(i=1; i<65; i++){
    act.sa_handler = SIG_IGN;
    if(i==10){
      act.sa_handler = subir;
    }
    else if(i==12){
      act.sa_handler = bajar;
    }
    else if(i==3){
      act.sa_handler = terminate;
    }
    else if(i==14){
      act.sa_handler = parado;
    }
    sigaction(i, &act, NULL);
  }
  while(salir!=1){
    pause();
  }
  return 0;
}

void subir(int signal){
  if((piso+1)>piso_max){
    
  }
  printf("Sube el ascensor\n");
  n_subidas++;
  alarm(T_PISO);
  control = 0;
  while(control!=1)
    printf("Subiendo");
}

void bajar(int signal){
  printf("Baja el ascensor\n");
  n_bajadas++;
  alarm(T_PISO);
  control = 0;
  while(control!=1)
    printf("Bajando");
}

void terminate(int signal){
  salir = 1;
  printf("FIN\n");
}

void parado(int signal){
  control =1;
  printf("Parado\n");
}
