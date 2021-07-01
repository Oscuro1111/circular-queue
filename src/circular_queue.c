#include <stdio.h>
#include <stdlib.h>
#include "../include/circular_queue.h"



Queue_Node *cq_allocate_node(){
	return (Queue_Node *)malloc(sizeof(Queue_Node));
}

//interface
int cq_queue(queue *cq, void *ele)
{
	Queue_Node *node;

	if (
	    cq != NULL &&
	    ele!=NULL
	    )
	{
		if(cq->head==NULL){
			cq->head = cq_allocate_node();
			
			//Error Check
			if(cq->head==NULL){
			_error:
				fprintf(stderr,"cq_allocate_node():Unabel allcate memory for the node.");				
				return -1;
			}
			cq->head->element = ele;
			cq->head->next    = NULL;

			cq->tail = cq->head;
			return 0;
		}

		if(cq->tail!=NULL){
			node=cq_allocate_node();
			
			if(node==NULL) goto _error;

			node->element = ele;

			node->next = NULL;

			cq->tail->next = node;

			cq->tail = node;
			return 0;
		}

		return -1;
	}

	return -1;
}

void *cq_dqueue(queue *cq)
{
	Queue_Node *node;

	void *ele;
	
	if(cq!=NULL&&cq->head!=NULL&&cq->tail!=NULL){
		node = cq->head;

		//if node next node found then we are at tail node and last node of the queue so set all both pointers to NULL 
		 if(node->next==NULL){
			 cq->head =NULL;
			 cq->tail =NULL;
		 }else{
			 //Move head pointer one step closer to tail in each dqueue
			 cq->head=node->next;
		 }

		 ele = node->element;

		 free(node);

		 return ele;		 
	}

	return NULL;
}

queue *allocate_queue(){
	queue *cq = (queue *)malloc(sizeof(queue));
	if(cq!=NULL){
		cq->head=NULL;
		cq->tail=NULL;

		return cq;
	}
	return NULL;
}

void cq_free(queue *cq){
	if(cq!=NULL){

		while(cq_dqueue(cq)!=NULL);	
		
		free(cq);
	}
}