#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node *next;
};

int menu();
void print_list(struct Node* node);
void remove_node(struct Node **head, int x);
void append(struct Node **head, int x);
void push(struct Node **head, int x);
int search_node(struct Node **head, int x);
void input_nude(struct Node **head, int x, int key);