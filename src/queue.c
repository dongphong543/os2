#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	//struct queue_t newq = *q;
	int i = 0;
	for(i = q->size - 1; i >= 0 && q->proc[i]->priority >= proc->priority; i--)
	{ 
			q->proc[i+1] = q->proc[i];
	}
	q->proc[i+1] = proc;
	q->size = q->size + 1;
	
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	struct pcb_t* ret = q->proc[0];
	for (int i = 0; i < q->size-1; i++)
		q->proc[i] = q->proc[i + 1];
	q->proc[q->size] = NULL;
	q->size -= 1;
	return ret;
}

