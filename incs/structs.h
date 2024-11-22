#ifndef STRUCTS_H
#define STRUCTS_H

#include "types.h"

typedef enum Status Status;
typedef struct Filosofo Filosofo;

enum Status
{
    Pensando,
    Hambriento,
    Comiendo
};

struct Filosofo
{
    Natural ID;
    Status Estado;
};

#endif  // STRUCTS_H