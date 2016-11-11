#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <windows.h>
#include <dos.h>


typedef struct node {
	int value; //0 = way, 1 = wall, 2 = entrance, 3 = exit
	struct node *right;
	struct node *left;
	struct node *up;
	struct node *down;
}node;

void insert(char *buffer,int i);
void insert2(char *buffer, int i);
int isEmpty();
void print_maze();
void create_maze();
int move();
/*http://stackoverflow.com/questions/29574849/how-to-change-text-color-and-console-color-in-codeblocks */
void SetColor(int ForgC);/*
black | 0
blue | 1
green | 2
cyan | 3
red | 4
magenta | 5
brown | 6
light gray | 7
dark gray | 8
light blue | 9
light green | 10
light cyan | 11
light red | 12
light magenta | 13
yellow | 14
white | 15
*/


node *head = NULL, *tail = NULL, *current = NULL, *follow = NULL, *character = NULL;

int main() {
	int exit;	
	create_maze();
	while (1) {
		system("cls");
		print_maze();
		exit = move();
		if (exit == 1) {
			return 0;
		}
	}
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
	}
}
void insert(char *buffer,int i) {		//insert a new node 
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
	if (newnode->value == 2) {	//pointing character location to entrance
		character = newnode;
	}
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
	if (newnode->value == 2) {	//pointing character location to entrance
		character = newnode;
	}
	
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
void print_maze() {
	node *temp, *row;
	row = temp = head;
	while (row != NULL) {		
		while (temp != NULL) {
			switch (temp->value) {			
			//print out passage
			case 0:
				if (character == temp) {
					SetColor(4);					
					printf(" @ ");
					SetColor(15);
					
					break;
				}
				// passage
				printf("   ");
				break;
				//print out wall
			case 1:
				// wall	
				SetColor(6);
				printf("###");
				break;
				//print out entrance
			case 2:
				if (character == temp) {
					printf(" @ ");
					break;
				}
				// entrance
				printf("   ");
				break;
				//print out exit
			case 3:
				if (character == temp) {
					printf(" @ ");
					break;
				}
				// exit
				printf("   ");
				break;
			}
			temp = temp->right;
		}
		printf("\n");
		row = row->down;
		temp = row;
	}
}
int move() {
	int c;
	if (character->value == 3) {
		return 1;
	}
	c = getch();
	if (c == 27) {
		return 1;
	}		
	else if (c == 224) {
		c = getch();
		switch (c) {
		case 72:	//UP
			if (character->up == NULL || character->up->value == 1) {	//check for wall and no node
				break;
			}
			else
				character = character->up;			
			break;
		case 80:	//DOWN
			if (character->down == NULL || character->down->value == 1) {	//check for wall and no node
				break;
			}
			else
				character = character->down;
			break;
		case 75:	//LEFT
			if (character->left == NULL || character->left->value == 1) {	//check for wall and no node
				break;
			}
			else
				character = character->left;
			break;
		case 77:	//RIGHT
			if (character->right == NULL || character->right->value == 1) {	//check for wall and no node
				break;
			}
			else
				character = character->right;
			break;
		}
	}
	return 0;
}
void SetColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}
