#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>
#include <time.h>


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
void create_maze1();
void create_maze2();
void create_maze3();
int move();
//http://stackoverflow.com/questions/29574849/how-to-change-text-color-and-console-color-in-codeblocks 
void Set_Color(int ForgC);/*
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
void setcolor(int color)//»ö±òÇÔ¼ö
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void SetColor(int backcolor, int fontcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backcolor * 16 + fontcolor);
}
void gotoxy(int x, int y)//ÁÂÇ¥ÇÔ¼ö
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
enum {
	BLACK,     //0 : °ËÁ¤
	D_BLUE,    //1 : ¾îµÎ¿î ÆÄ¶û
	D_GREEN,   //2 : ¾îµÎ¿î ÃÊ·Ï
	D_SKYBLUE, //3 : ¾îµÎ¿î ÇÏ´Ã
	D_RED,     //4 : ¾îµÎ¿î »¡°­
	D_VIOLET,  //5 : ¾îµÎ¿î º¸¶ó
	D_YELLOW,  //6 : ¾îµÎ¿î ³ë¶û
	GRAY,      //7 : È¸»ö
	D_GRAY,    //8 : ¾îµÎ¿î È¸»ö
	BLUE,      //9 : ÆÄ¶û
	GREEN,     //10 : ÃÊ·Ï
	SKYBLUE,   //11 : ÇÏ´Ã
	RED,       //12 : »¡°­
	VIOLET,    //13 : º¸¶ó
	YELLOW,    //14 : ³ë¶û
	WHITE,     //15 : Èò»ö
};
void gotoxy(int x, int y);
int startingPage();
double game();
void freeList();

node *head = NULL, *tail = NULL, *current = NULL, *follow = NULL, *character = NULL;

int main() {
	system("mode con:cols=200 lines=200");//changes console size
	int input;
	double result;
	while (1) {
		input = startingPage();
		switch (input) {
		case 1:
			result = game();
			break;
		case 2:
			system("cls");
			printf("ranking\n");
			break;
		case 3:
			return 0;
		}
	}
}
void create_maze1() {
	FILE *fp;
	int len, i;
	char buffer[100];
	fp = fopen("level1.txt", "r");
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
void create_maze2() {
	FILE *fp;
	int len, i;
	char buffer[100];
	fp = fopen("level2.txt", "r");
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
void create_maze3() {
	FILE *fp;
	int len, i;
	char buffer[100];
	fp = fopen("level3.txt", "r");
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
					Set_Color(4);					
					printf("@ ");
					Set_Color(15);
					
					break;
				}
				// passage
				printf("  ");
				break;
				//print out wall
			case 1:
				// wall	
				//Set_Color(6);
				printf("##");
				break;
				//print out entrance
			case 2:
				if (character == temp) {
					Set_Color(4);
					printf("@ ");
					Set_Color(15);
					break;
				}
				// entrance
				printf("  ");
				break;
				//print out exit
			case 3:
				if (character == temp) {
					printf("@ ");
					break;
				}
				// exit
				printf("  ");
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
				return 2;
				break;
			}
			else
				character = character->up;			
			break;
		case 80:	//DOWN
			if (character->down == NULL || character->down->value == 1) {	//check for wall and no node
				return 2;
				break;
			}
			else
				character = character->down;
			break;
		case 75:	//LEFT
			if (character->left == NULL || character->left->value == 1) {	//check for wall and no node
				return 2;
				break;
			}
			else
				character = character->left;
			break;
		case 77:	//RIGHT
			if (character->right == NULL || character->right->value == 1) {	//check for wall and no node
				return 2;
				break;
			}
			else
				character = character->right;
			break;
		}
	}
	return 0;
}
void Set_Color(int ForgC)
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
int startingPage() {
	int show; //다음화면
	int color1; //색깔반짝 반복
	int i = 1;
	printf("    ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¢                                                                    ¦¢\n");
	printf("    ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	printf("                               ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¤ \n");
	printf("                               ¦¢            ¦¢ \n");
	printf("                               ¦¢            ¦¢ \n");
	printf("                               ¦¢            ¦¢ \n");
	printf("                               ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ \n");
	gotoxy(8, 2);
	printf("/$$      /$$"); Sleep(50);
	gotoxy(7, 3);
	printf("| $$$    /$$$"); Sleep(50);
	gotoxy(7, 4);
	printf("| $$$$  /$$$$  /$$$$$$  /$$$$$$$$  /$$$$$$"); Sleep(50);
	gotoxy(7, 5);
	printf("| $$ $$/$$ $$ |____  $$|____ /$$/ /$$__  $$"); Sleep(50);
	gotoxy(7, 6);
	printf("| $$  $$$| $$  /$$$$$$$   /$$$$/ | $$$$$$$$"); Sleep(50);
	gotoxy(7, 7);
	printf("| $$\  $ | $$ /$$__  $$  /$$__/  | $$_____/"); Sleep(50);
	gotoxy(7, 8);
	printf("| $$ \/  | $$|  $$$$$$$ /$$$$$$$$|  $$$$$$$"); Sleep(50);
	gotoxy(7, 9);
	printf("|__/     |__/ \_______/|________/ \_______/"); Sleep(50);
	gotoxy(16, 10);
	printf("/$$$$$$   /$$$$$$$  /$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$"); Sleep(50);
	gotoxy(15, 11);
	printf("/$$__  $$ /$$_____/ /$$_____/ |____  $$ /$$__  $$ /$$__  $$"); Sleep(50);
	gotoxy(14, 12);
	printf("| $$$$$$$$|  $$$$$$ | $$        /$$$$$$$| $$  \  $$| $$$$$$$$"); Sleep(50);
	gotoxy(14, 13);
	printf("| $$_____/ \ ____  $$| $$       /$$__  $$| $$  | $$| $$_____/"); Sleep(50);
	gotoxy(14, 14);
	printf("|  $$$$$$$ /$$$$$$$/|  $$$$$$$|  $$$$$$$| $$$$$$$/|  $$$$$$$"); Sleep(50);
	gotoxy(15, 15);
	printf("\ _______/|_______/  \_______/ \  _______/| $$____/  \_______/"); Sleep(50);
	gotoxy(54, 16);
	printf("| $$"); Sleep(50);
	gotoxy(54, 17);
	printf("| $$"); Sleep(50);
	gotoxy(54, 18);
	printf("|__/\n\n"); Sleep(50);

	gotoxy(35, 21);
	printf(" 1.START");
	gotoxy(35, 22);
	printf(" 2.RANKING");
	gotoxy(35, 23);
	printf(" 3.EXIT");
	while(1) {
		while (1)//반짝이 효과
		{
			if (_kbhit()) break;
			for (color1 = 10; color1 < 15; color1++) //컬러 10~15반복
			{
				setcolor(color1);
				gotoxy(8, 2);
				printf("/$$      /$$");
				gotoxy(7, 3);
				printf("| $$$    /$$$");
				gotoxy(7, 4);
				printf("| $$$$  /$$$$  /$$$$$$  /$$$$$$$$  /$$$$$$");
				gotoxy(7, 5);
				printf("| $$ $$/$$ $$ |____  $$|____ /$$/ /$$__  $$");
				gotoxy(7, 6);
				printf("| $$  $$$| $$  /$$$$$$$   /$$$$/ | $$$$$$$$");
				gotoxy(7, 7);
				printf("| $$\  $ | $$ /$$__  $$  /$$__/  | $$_____/");
				gotoxy(7, 8);
				printf("| $$ \/  | $$|  $$$$$$$ /$$$$$$$$|  $$$$$$$");
				gotoxy(7, 9);
				printf("|__/     |__/ \_______/|________/ \_______/");
				gotoxy(16, 10);
				printf("/$$$$$$   /$$$$$$$  /$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$");
				gotoxy(15, 11);
				printf("/$$__  $$ /$$_____/ /$$_____/ |____  $$ /$$__  $$ /$$__  $$");
				gotoxy(14, 12);
				printf("| $$$$$$$$|  $$$$$$ | $$        /$$$$$$$| $$  \  $$| $$$$$$$$");
				gotoxy(14, 13);
				printf("| $$_____/ \ ____  $$| $$       /$$__  $$| $$  | $$| $$_____/");
				gotoxy(14, 14);
				printf("|  $$$$$$$ /$$$$$$$/|  $$$$$$$|  $$$$$$$| $$$$$$$/|  $$$$$$$");
				gotoxy(15, 15);
				printf("\ _______/|_______/  \_______/ \  _______/| $$____/  \_______/");
				gotoxy(54, 16);
				printf("| $$");
				gotoxy(54, 17);
				printf("| $$");
				gotoxy(54, 18);
				printf("|__/\n\n");
				Sleep(100);
			}
		}
		setcolor(15); //칼라 흰색(15)으로 초기화
		
		show = _getch();
		switch (show) {
		case 49:
			return 1;
		case 50:
			return 2;
		case 51:
			return 3;
		}
	}
}
double game() {
	int input = 0;
	clock_t before;
	double result;

	create_maze1();	
	before = clock();
	while (1) {	//level 1
		if (input == 0) {	//first loop and if character moved
			system("cls");
			print_maze();
		}
		input = move();
		if (input == 1) {	//finishes maze and goes to the next level
			break;
		}
	}	
	//linked list removing function
	freeList();
	head = NULL;
	input = 0;
	create_maze2();
	while (1) {	//level 2
		if (input == 0) {	//if character moved
			system("cls");
			print_maze();
		}
		input = move();
		if (input == 1) {	//finishes maze and goes to the next level
			break;
		}
	}
	//linked list removing function
	freeList();
	head = NULL;
	input = 0;
	create_maze3();
	while (1) {	//level 3
		if (input == 0) {	//if character moved
			system("cls");
			print_maze();
		}
		input = move();
		if (input == 1) {	//finishes last maze
			//Tick단위를 초단위로 환산해주는 코드 http://www.sarangnamu.net/basic/basic_view.php?no=2245&page=81&sCategory=0
			result = (double)(clock() - before) / CLOCKS_PER_SEC;
			return result;
		}
	}
}
void freeList() {
	node *temp;
	follow = current = head;	
	while (follow != NULL) {	//moving to last row
		current = follow;
		follow = follow->down;		
			for (temp = current; temp != NULL; temp = current) {
			current = temp->right;
			free(temp);
		}		
	}
}
