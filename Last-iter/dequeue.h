/*
    Examen 2 parte asíncrona
    David Hernández
    José Hurtado
*/

#ifndef DEQUEUE_H_
#define DEQUEUE_H_

#include "datatypes.h"

struct STR_DEQUEUE_NODE {
/*
Define los elementos que debe tener esta estructura que serán los nodos de la cola doblemente terminada que deben ser
- El elemento que se almacena
- El o los apuntadores a los nodos que pueden ser previo y/o siguiente
*/

    // Se crea un elemento TYPE
    TYPE elem;
    // Indicamos apuntadores para los nodos siguientes y previos
    struct STR_DEQUEUE_NODE *next,*prior;

};

struct STR_DEQUEUE {
/*
Define los elementos que debe tener esta estructura que contiene la información de la cola doblemente terminada como:
- Apuntadores al nodo frontal y trasero de la cola doblemente terminada
- Tamaño de la cola doblemente terminada, es decir la cantidad de elementos
*/
    // Indicamos el tamaño de la estructura
    int size;
    // Nodos que apuntan al inicio y final de la cola
    struct STR_DEQUEUE_NODE *front, *rear;

};

typedef struct STR_DEQUEUE * DEQUEUE;

DEQUEUE dequeue_create();
void dequeue_insf(DEQUEUE d,TYPE e);
void dequeue_insr(DEQUEUE d,TYPE e);
BOOL dequeue_empty(DEQUEUE d);
int dequeue_size(DEQUEUE d);
TYPE dequeue_rmf(DEQUEUE d);
TYPE dequeue_rmr(DEQUEUE d);
TYPE dequeue_peekf(DEQUEUE d);
TYPE dequeue_peekr(DEQUEUE d);
void dequeue_destroy(DEQUEUE d);


#endif /* DEQUEUE_H_ */
