#include "func.h"


int main(int argc, char **argv)
{
	struct Node *head = NULL;
	int n, x, y;
	printf("Testing linked list\n");
	n=1;
	while(n!=0){
		printf("\n");
		n = menu();
		if(n==0){
			printf("Ending\n");
		}else if(n==1){
			printf("Give number to add to list: ");
			scanf("%d", &x);
			append(&head, x);
			
		}else if(n==2){
			printf("Give number to push to list: ");
			scanf("%d", &x);
			push(&head, x);
		}else if(n==3){
			printf("Which number to delete: ");
			scanf("%d", &x);
			remove_node(&head, x);
		}else if(n==4){
			printf("Which number to find: ");
			scanf("%d", &x);
			y = search_node(&head, x);
			if(y==0){
				printf("Number not found\n");
			}else{
				if(y==1){
					printf("Number %d is first in list\n", x);
				}else if(y==2){
					printf("Number %d is second in list\n", x);
				}else if(y==3){
					printf("Number %d is third in list\n", x);
				}else{
					printf("Number %d is %dth in the list\n", x, y);
				}
			}
		}else if(n==5){
			printf("Give number and key: ");
			scanf("%d %d", &x, &y);
			input_nude(&head, x, y);
		}else if(n==6){
			print_list(head);
		}else{
			printf("Choice not recognized\n");
		}
	}
	return 0;
}
