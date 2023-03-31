/*
    Examen 2 parte asíncrona
    David Hernández
    José Hurtado
*/
#include "dequeue.h"
#include <stdio.h>
#include <stdlib.h>

//████████████████████████████████████████████████████████

// Creamos un nodo donde apuntamos el nodo su frente a nulo al igual que su parte trasera a nulo, donde ademas indicamos un tamaño de 0.
DEQUEUE dequeue_create() {
    /*
    Función que crea el nodo en memoria dinámica que contiene la
    información de la cola doblemente terminada.
    */
    DEQUEUE new = malloc(sizeof(struct STR_DEQUEUE));
    new->front = NULL;
    new->rear = NULL;
    new->size = 0;

    return new;
}

//████████████████████████████████████████████████████████

void dequeue_insr(DEQUEUE d, TYPE e) {
    /*
    Función para insertar un nodo en la parte trasera (al final) de la
    cola doblemente terminada
    */
    struct STR_DEQUEUE_NODE *new = malloc(sizeof(struct STR_DEQUEUE_NODE));
    new->next = NULL;
    new->prior = NULL;
    new->elem = e;

    /*  Revisar la condición donde no hay nodos
        Asignar el front y rear la dirección del primer nodo creado y aumento del tamaño
    */
    if (d->front == NULL && d->rear == NULL) {
        d->front = new;
        d->rear = new;
        d->size += 1;
    } else {
        //  Entra al else cuando no es el primer nodo
        new->next = d->rear; //El siguiente elemento del nuevo nodo apunta al último nodo ingresado
        d->rear->prior = new; // Se indica el enlace trasero previo al nuevo
        d->rear = new; // Actualizar el rear apuntándolo al nuevo nodo
        d->size += 1;
    }
}

//████████████████████████████████████████████████████████

void dequeue_insf(DEQUEUE d, TYPE e) {
    /*
            Función para insertar un nodo al frente (al principio) de la cola
       doblemente terminada
    */
    struct STR_DEQUEUE_NODE *new = malloc(sizeof(struct STR_DEQUEUE_NODE));
    new->next = NULL;
    new->prior = NULL;
    new->elem = e;

    /*  Revisar la condición donde no hay nodos
        Asignar el front y rear la dirección del primer nodo creado y aumento del tamaño
    */

    if (d->front == NULL && d->rear == NULL) {
        d->front = new;
        d->rear = new;
        d->size += 1;
    } else {
        //  Entra al else cuando no es el primer nodo
        new->prior = d->front; //El siguiente elemento del nuevo nodo apunta al último nodo ingresado
        d->front->next = new; // Se indica el enlace frontal siguiente al nuevo
        d->front = new;  // Actualizar el front apuntándolo al nuevo nodo
        d->size += 1;
    }
}

//████████████████████████████████████████████████████████

BOOL dequeue_empty(DEQUEUE d) {
    /*
      Función que regresa verdadero si la cola doblemente terminada está
       vacía
    */
    // Al indicar que el front y rear apuntan a NULL es por que no hay mas nodos en la estructura
    if (d->front == NULL && d->rear == NULL) {
        return 1;
    }
    return 0;
}

//████████████████████████████████████████████████████████

int dequeue_size(DEQUEUE d) {
    /*
      Función que regresa la cantidad de elementos que contiene la cola
      doblemente terminada
    */
    return d->size;
}

//████████████████████████████████████████████████████████

TYPE dequeue_rmf(DEQUEUE d) {
    /*
      Función que devuelve el elemento y remueve de la parte frontal de la
      cola doblemente terminada
    */
    // Se crea un nodo a destruir
    struct STR_DEQUEUE_NODE *toremove;

    // Revisar si la cola está vacía
    if (dequeue_empty(d)) {
        return 0;
    } else {
        // Se asigna el nodo a destruir al nodo frontal
        toremove = d->front;
        // Obtenemos el elemento de retorno antes de removerlo
        TYPE elem_to_return = toremove->elem;

        // Condición utilizada cuando existe un solo elemento: front y rear apuntan al mismo nodo
        if (d->front == d->rear) {
            // Se libera el nodo
            free(toremove);
            // Se actualiza la estructura apuntando el frente y la parte trasera a nulo
            d->front = NULL;
            d->rear = NULL;
            d->size -= 1;
            return elem_to_return;
        }
        // Se actualiza el nodo frontal al anterior para ser el nuevo frente
        d->front = toremove->prior;
        // El siguiente nodo del primer elemento se actualiza a NULL
        d->front->next = NULL;
        free(toremove);

        d->size -= 1;
        return elem_to_return;
    }
}

//████████████████████████████████████████████████████████

TYPE dequeue_rmr(DEQUEUE d) {
    /*
       Función que devuelve el elemento y remueve de la parte trasera de la
       cola doblemente terminada
    */

    // Se crea un nodo a destruir y se asigna al nodo trasero
    struct STR_DEQUEUE_NODE *toremove = d->rear;

    // Obtenemos el elemento de retorno antes de removerlo
    TYPE elem_to_return = toremove->elem;

    if (dequeue_empty(d)) {
        return 0;
    } else {

        // Condición utilizada cuando existe un solo elemento: front y rear apuntan al mismo nodo
        if (d->front == d->rear) {
            // Se libera el nodo
            free(toremove);
            // Se actualiza la estructura apuntando el frente y la parte trasera a nulo
            d->front = NULL;
            d->rear = NULL;
            d->size -= 1;
            return elem_to_return;
        }

        // Se actualiza el nodo trasero al anterior para ser el nuevo trasero
        d->rear = toremove->next;
        // El previo nodo del ultimo elemento se actualiza a NULL
        d->rear->prior = NULL;
        free(toremove);
        d->size -= 1;
        return elem_to_return;
    }
}

//████████████████████████████████████████████████████████

TYPE dequeue_peekf(DEQUEUE d) {
    /*
      Función que devuelve el elemento de la parte frontal de la cola
      doblemente terminada, más no lo remueve
    */
    // De estar vacia la estructura se retorna vacio
    if (dequeue_empty(d))
        return 0;
    else
        return d->front->elem; // Se envía el elemento que contiene el primer nodo
}

//████████████████████████████████████████████████████████

TYPE dequeue_peekr(DEQUEUE d) {
    /*
       Función que devuelve el elemento de la parte trasera de la cola
       doblemente terminada, más no lo remueve
    */

    // De estar vacia la estructura se retorna vacio
    if (dequeue_empty(d))
        return 0;
    else
        return d->rear->elem; // Se envía el elemento que contiene el ultimo nodo
}

//████████████████████████████████████████████████████████

void dequeue_destroy(DEQUEUE d) {
    /*
            Función que elimina todos los nodos de la cola doblemente terminada,
       liberando la memoria
    */

    // Ciclo while donde siempre y cuando la lista no este vacia se estaran sacando los nodos
    while (!dequeue_empty(d)) {
        dequeue_rmf(d);
    }
    free(d); // Liberar el espacio reservado para la estructura de datos
}

//████████████████████████████████████████████████████████
