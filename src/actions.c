#include "actions.h"

Semaphore Tenedores[NRO_FILOSOFOS];

Procedure InicializarFilosofos(Filosofo* Filosofos)
{
    for (Natural i=0; i<NRO_FILOSOFOS; i++)
    {
        Filosofos[i].ID = i;
        Filosofos[i].Estado = Pensando;
    }

    return;
}

Procedure InicializarTenedores()
{
    for (Natural i=0; i<NRO_TENEDORES; i++)
    {
        sem_init(&Tenedores[i], 0, 1);
    }

    return;
}

Procedure TomarTenedores(Filosofo* F)
{
    F->Estado = Hambriento;
    wait(Tenedores[F->ID]);
    printf("El filosofo %hu ha tomado el tenedor de su izquierda.\n", F->ID);
    wait(Tenedores[(F->ID + 1) % NRO_FILOSOFOS]);
    printf("El filosofo %hu ha tomado el tenedor de su derecha.\n", F->ID);
    return;
}

Procedure SoltarTenedores(Filosofo* F)
{
    signal(Tenedores[F->ID]);
    signal(Tenedores[(F->ID + 1) % NRO_FILOSOFOS]);
    return;
}

Procedure Comer(Filosofo* F)
{
    F->Estado = Comiendo;
    printf("Filosofo %hu esta comiendo...\n", F->ID);
    sleep((rand() % 3) + 2);  // Se simula el tiempo que come
    printf("Filosofo %hu ha comido.\n", F->ID);
    return;
}

Procedure Pensar(Filosofo* F)
{
    F->Estado = Pensando;
    printf("Filosofo %hu esta pensando...\n", F->ID);
    sleep((rand() % 3) + 2);  // Se simula el tiempo que piensa
    return;
}

void* FilosofoX(void* arg)
{
    Filosofo* F = (Filosofo*) arg;

    time_t Partida = time(NULL);
    time_t Actual;

    LOOP
    {
        Pensar(F);

        Actual = time(NULL);

        time_t Diff = difftime(Actual, Partida);

        if (Diff >= TIEMPO_SIMULACION)  // Cuando el tiempo alcance o supere el minuto, cada filósofo saldrá de escena
        {
            printf("Filosofo %hu ha salido de escena luego de %ld segundos.\n", F->ID, Diff);
            break;
        }

        TomarTenedores(F);
        Comer(F);
        SoltarTenedores(F);
    }

    return NULL;
}

Procedure DestruirTenedores()
{
    for (Natural i=0; i<NRO_TENEDORES; i++)
    {
        sem_destroy(&Tenedores[i]);
    }

    return;
}