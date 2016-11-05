#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
	int value;
	struct node *right;
	struct node *left;
	struct node *up;
	struct node *down;
}node;

void insert(char *buffer, int i);
void insert2(char *buffer, int i);
int isEmpty();
void print(node *head);
void create_maze();

node *head = NULL, *tail = NULL, *current = NULL, *follow = NULL;

int main() {
	create_maze();
	return 0;
}
void create_maze() {
	FILE *fp;
	int len, i;
	char buffer[100];
	fp = fopen("maze1.txt", "r");
	while (fgets(buffer, 100, fp) != NULL) {
		len = strlen(buffer);
		if (isEmpty()) {
			for (i = 0; i < len - 1; i++) {
				insert(buffer, i);
			}
		}
		else {
			for (i = 0; i < len - 1; i++) {
				insert2(buffer, i);
			}
		}
		print(head);
	}
}
void insert(char *buffer, int i) {		//insert a new node 
	char c[2];
	//	create new node
	node *newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->up = NULL;
	newnode->down = NULL;
	//	taking one char from string and converting to int
	strncpy(c, &buffer[i], 1);
	newnode->value = atoi(c);
	//	linking nodes
	if (isEmpty()) {
		tail = newnode;
		head = newnode;
	}
	else {
		tail->right = newnode;
		newnode->left = tail;
		tail = newnode;
	}
}
void insert2(char *buffer, int i) {
	char c[2];
	//	create new node
	node *newnode, *tmp = NULL;
	newnode = (node*)malloc(sizeof(node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->up = NULL;
	newnode->down = NULL;
	//	taking one char from string and converting to int
	strncpy(c, &buffer[i], 1);
	newnode->value = atoi(c);

	if (i == 0) {	// if new row move current to new row's first node position
		current = follow = head;
		while (current != NULL) {
			follow = current;
			current = current->down;
		}
		//	connect new node to list
		newnode->up = follow;
		follow->down = newnode;
		current = newnode;
	}
	else {
		follow = follow->right;	//	moving pointer to next location		
		while (current != NULL) {	//	moving pointer to next location
			tmp = current;
			current = current->right;
		}
		//	linking new node up and left
		newnode->up = follow;
		follow->down = newnode;
		newnode->left = tmp;
		tmp->right = newnode;
		current = newnode;
	}
}
int isEmpty() {	//	check if linked list is empty
	if (head == NULL) {
		return 1;
	}
	else return 0;
}
void print(node *head) {
	node *temp1, *temp2;
	temp1 = temp2 = head;
	while (temp1->down != NULL) {
		temp2 = temp1;
		temp1 = temp1->down;
	}
	while (temp1 != NULL) {
		printf("%d", temp1->value);
		temp1 = temp1->right;
	}
	printf("\n");
}
