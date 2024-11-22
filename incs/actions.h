#ifndef ACTIONS_H
#define ACTIONS_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "unistd.h"
#include "structs.h"
#include "semfits.h"

Procedure InicializarFilosofos(Filosofo*);
Procedure InicializarTenedores(void);
Procedure TomarTenedores(Filosofo*);
Procedure SoltarTenedores(Filosofo*);
Procedure Comer(Filosofo*);
Procedure Pensar(Filosofo*);
void* FilosofoX(void* arg);
Procedure DestruirTenedores(void);

#endif  // ACTIONS_H