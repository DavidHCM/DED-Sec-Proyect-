/*
 * testdequeue.c
 *
 *  Created on: 20 mar 2023
 *      Author: jluis
 */
#include <stdio.h>

#include "dequeue.h"

int main()
{
	DEQUEUE dq1 = dequeue_create();	// Crear una cola

	int i;
	int *num;

	/*********************************************************/
	printf("\n\nPrueba 1, inserta al final y retira del frente\n");

	for(i=0;i<5;i++)
	{
		printf("Insertando al final de la cola doblemente terminada: %d\n",i);
		dequeue_insr(dq1,int_create(i));
	}

	printf("\nEl tamaño de la cola doblemente terminada es %d\n",dequeue_size(dq1));

	num = dequeue_peekf(dq1);
	printf("El elemento al frente es %d ",*num);
	num = dequeue_peekr(dq1);
	printf("y el elemento en la parte trasera es %d\n\n",*num);

	while(!dequeue_empty(dq1))
	{
		num = dequeue_rmf(dq1);
		printf("Retirando del frente de la cola doblemente terminada: %d\n",*num);
	}

	/*********************************************************/
	printf("\n\nPrueba 2, inserta al frente y retira del final\n");

	for(i=5;i<10;i++)
	{
		printf("Insertando al frente de la cola doblemente terminada: %d\n",i);
		dequeue_insf(dq1,int_create(i));
	}

	printf("\nEl tamaño de la cola doblemente terminada es %d\n",dequeue_size(dq1));

	num = dequeue_peekf(dq1);
	printf("El elemento al frente es %d ",*num);
	num = dequeue_peekr(dq1);
	printf("y el elemento en la parte trasera es %d\n\n",*num);


	while(!dequeue_empty(dq1))
	{
		num = dequeue_rmr(dq1);
		printf("Retirando del final de la cola doblemente terminada: %d\n",*num);
	}

	/*********************************************************/
	printf("\n\nPrueba 3, inserta al frente y retira del frente\n");


	for(i=10;i<15;i++)
	{
		printf("Insertando al frente de la cola doblemente terminada: %d\n",i);
		dequeue_insf(dq1,int_create(i));
	}

	printf("\nEl tamaño de la cola doblemente terminada es %d\n",dequeue_size(dq1));

	num = dequeue_peekf(dq1);
	printf("El elemento al frente es %d ",*num);
	num = dequeue_peekr(dq1);
	printf("y el elemento en la parte trasera es %d\n\n",*num);

	while(!dequeue_empty(dq1))
	{
		num = dequeue_rmf(dq1);
		printf("Retirando del frente de la cola doblemente terminada: %d\n",*num);
	}

	/*********************************************************/
	printf("\n\nPrueba 4, inserta al final y retira del final\n");

	for(i=15;i<20;i++)
	{
		printf("Insertando al final de la cola doblemente terminada: %d\n",i);
		dequeue_insr(dq1,int_create(i));
	}

	printf("\nEl tamaño de la cola doblemente terminada es %d\n",dequeue_size(dq1));

	num = dequeue_peekf(dq1);
	printf("El elemento al frente es %d ",*num);
	num = dequeue_peekr(dq1);
	printf("y el elemento en la parte trasera es %d\n\n",*num);

	while(!dequeue_empty(dq1))
	{
		num = dequeue_rmr(dq1);
		printf("Retirando del final de la cola doblemente terminada: %d\n",*num);
	}


	dequeue_destroy(dq1);
}

