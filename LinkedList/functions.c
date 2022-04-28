#include "func.h"

int menu(){
	int n;
	printf("1) append to a list\n");
	printf("2) push to a list\n");
	printf("3) remove from list\n");
	printf("4) find number\n");
	printf("5) add number after number\n");
	printf("6) print list\n");
	printf("0) end\n");
	printf("Choice: ");
	scanf("%d", &n);
	return n;
}

void print_list(struct Node* node){
	if(node==NULL){
		printf("List is empty\n");
	}else{
		printf("Printing list\n");
		printf("[");
		while(node->next!=NULL){
			printf("%d, ", node->data);
			node = node->next;
		}
		
		printf("%d]\n", node->data);
	}
}

void remove_node(struct Node **head, int x){
	struct Node *node = *head, *prev;
	if(node!=NULL && node->data==x){
		*head = node->next;
		free(node);
		return;
	}
	while(node!=NULL && node->data!=x){
		prev = node;
		node = node->next;
	}
	if(node==NULL){
		printf("No such number in list\n");
		return;
	}
	prev->next = node->next;
	printf("%d removed\n", x);
	free(node);
	return;
}

void append(struct Node **head, int x){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *head;
	node->data = x;
	node->next = NULL;
	if(*head == NULL){
		*head = node;
		printf("List was empty, %d added\n", x);
		return;
	}
	while(last->next!=NULL){
		last = last->next;
	}
	last->next = node;
	printf("%d added\n", x);
	return;
}

void push(struct Node **head, int x){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));

	node->data = x;
	node->next = *head;
	*head = node;
	printf("Number %d pushed\n", x);
}

int search_node(struct Node **head, int x){
	int count=1;
	struct Node *node = *head;
	if(node==NULL){
		return 0;
	}
	while(node!=NULL){
		if(node->data==x){
			return count;
		}
		node = node->next;
		count += 1;
	}
	free(node);
	return 0;
}

void input_nude(struct Node **head, int x, int key){
	struct Node *nd = *head;
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	
	node->data = x;
	node->next = NULL;
	
	if(nd==NULL){
		printf("List empty, adding %d\n", x);
		*head = node;
		return;
	}
	while(nd!=NULL){
		if(nd->data==key){
			printf("Key found %d added\n", x);
			node->next = nd->next;
			nd->next = node;
			return;
		}
		nd = nd->next;
	}
	printf("Number %d not found in list\n", key);
	return;
}
