#ifndef SEMFITS_H
#define SEMFITS_H

#include "semaphore.h"

#define wait(semaphore) sem_wait(&semaphore)
#define signal(semaphore) sem_post(&semaphore)
#define NRO_FILOSOFOS 5
#define NRO_TENEDORES NRO_FILOSOFOS
#define LOOP while (1)
#define TIEMPO_SIMULACION 30

typedef sem_t Semaphore;

#endif  // SEMFITS_H