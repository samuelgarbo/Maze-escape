#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int value; //0 = way, 1 = wall, 2 = entrance, 3 = exit
	struct node *right;
	struct node *left;
	struct node *up;
	struct node *down;
}node;

void print_maze();

node *head = NULL;

int main() {
	
	print_maze();
	return 0;
}
void print_maze() {
	node *temp, *row;
	row = temp = head;
	while (row != NULL) {
		while (temp != NULL) {
			switch (temp->value) {
			case 1:
				printf("#");
				break;
			case 0:
				printf(" ");
				break;
			}

			temp = temp->right;
		}
		printf("\n");
		row = row->down;
		temp = row;
	}
}