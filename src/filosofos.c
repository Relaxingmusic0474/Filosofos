#include "stdio.h"
#include "stdlib.h"
#include "types.h"
#include "pthread.h"
#include "structs.h"
#include "semfits.h"
#include "actions.h"
#include "sys/shm.h"

int main()
{
    Filosofo Filosofos[NRO_FILOSOFOS];
    pthread_t Hilos[NRO_FILOSOFOS];

    InicializarFilosofos(Filosofos);
    InicializarTenedores();

    srand(time(NULL) ^ getpid());

    for (Natural i=0; i<NRO_FILOSOFOS; i++)  // Se crean los hilos para cada filósofo
    {
        pthread_create(&Hilos[i], NULL, FilosofoX, (void*)&Filosofos[i]);
    }

    for (Natural i=0; i<NRO_FILOSOFOS; i++)  // Se espera a que cada hilo termine
    {
        pthread_join(Hilos[i], NULL);
    }

    DestruirTenedores();

    return 0;
}