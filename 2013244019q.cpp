#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
void setcolor(int color)//�����Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void SetColor(int backcolor, int fontcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backcolor * 16 + fontcolor);
}
void gotoxy(int x, int y)//��ǥ�Լ�
{
	COORD Pos = {x-1, y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
enum {
	BLACK,     //0 : ����
	D_BLUE,    //1 : ��ο� �Ķ�
	D_GREEN,   //2 : ��ο� �ʷ�
	D_SKYBLUE, //3 : ��ο� �ϴ�
	D_RED,     //4 : ��ο� ����
	D_VIOLET,  //5 : ��ο� ����
	D_YELLOW,  //6 : ��ο� ���
	GRAY,      //7 : ȸ��
	D_GRAY,    //8 : ��ο� ȸ��
	BLUE,      //9 : �Ķ�
	GREEN,     //10 : �ʷ�
	SKYBLUE,   //11 : �ϴ�
	RED,       //12 : ����
	VIOLET,    //13 : ����
	YELLOW,    //14 : ���
	WHITE,     //15 : ���
};
void gotoxy(int x, int y);
void showcharacter();
void ranking();
typedef struct node {
	int value;
	struct node *right;
	struct node *left;
	struct node *up;
	struct node *down;
}node;
int main(void)
{
	int show; //����ȭ��
	int color1; //�����¦ �ݺ�
	int i = 1;
	printf("    ������������������������������������������������������������������������\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
    printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ��                                                                    ��\n");
	printf("    ������������������������������������������������������������������������\n");
	printf("                                 �������������� \n");
	printf("                                 ��          �� \n");
	printf("                                 ��          �� \n");
	printf("                                 ��          �� \n");
	printf("                                 �������������� \n");
	gotoxy(8,2);
	printf("/$$      /$$");Sleep(50);
	gotoxy(7,3);
	printf("| $$$    /$$$");Sleep(50);
	gotoxy(7,4);
	printf("| $$$$  /$$$$  /$$$$$$  /$$$$$$$$  /$$$$$$");Sleep(50);
	gotoxy(7,5);
	printf("| $$ $$/$$ $$ |____  $$|____ /$$/ /$$__  $$");Sleep(50);
	gotoxy(7,6);
	printf("| $$  $$$| $$  /$$$$$$$   /$$$$/ | $$$$$$$$");Sleep(50);
	gotoxy(7,7);
	printf("| $$\  $ | $$ /$$__  $$  /$$__/  | $$_____/");Sleep(50);
	gotoxy(7,8);
	printf("| $$ \/  | $$|  $$$$$$$ /$$$$$$$$|  $$$$$$$");Sleep(50);
	gotoxy(7,9);
	printf("|__/     |__/ \_______/|________/ \_______/");Sleep(50);
	gotoxy(16,10);
	printf("/$$$$$$   /$$$$$$$  /$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$");Sleep(50);
	gotoxy(15,11);
	printf("/$$__  $$ /$$_____/ /$$_____/ |____  $$ /$$__  $$ /$$__  $$");Sleep(50);
	gotoxy(14,12);
	printf("| $$$$$$$$|  $$$$$$ | $$        /$$$$$$$| $$  \  $$| $$$$$$$$");Sleep(50);
	gotoxy(14,13);
	printf("| $$_____/ \ ____  $$| $$       /$$__  $$| $$  | $$| $$_____/");Sleep(50);
	gotoxy(14,14);
	printf("|  $$$$$$$ /$$$$$$$/|  $$$$$$$|  $$$$$$$| $$$$$$$/|  $$$$$$$");Sleep(50);
	gotoxy(15,15);
	printf("\ _______/|_______/  \_______/ \  _______/| $$____/  \_______/");Sleep(50);
	gotoxy(54,16);
	printf("| $$");Sleep(50);
	gotoxy(54,17);
	printf("| $$");Sleep(50);
	gotoxy(54,18);
	printf("|__/\n\n");Sleep(50);
	
	gotoxy(37,21);
	printf(" 1.����");
	gotoxy(37,22);
	printf(" 2.��ŷ");
	gotoxy(37,23);
	printf(" 3.����");
	
	while(1)//��¦�� ȿ��
	{
		if (_kbhit()) break;
		for (color1 = 10; color1 < 15; color1++) //�÷� 10~15�ݺ�
		{
			setcolor(color1);
			gotoxy(8,2);
			printf("/$$      /$$");
			gotoxy(7,3);
			printf("| $$$    /$$$");
			gotoxy(7,4);
			printf("| $$$$  /$$$$  /$$$$$$  /$$$$$$$$  /$$$$$$");
			gotoxy(7,5);
			printf("| $$ $$/$$ $$ |____  $$|____ /$$/ /$$__  $$");
			gotoxy(7,6);
			printf("| $$  $$$| $$  /$$$$$$$   /$$$$/ | $$$$$$$$");
			gotoxy(7,7);
			printf("| $$\  $ | $$ /$$__  $$  /$$__/  | $$_____/");
			gotoxy(7,8);
			printf("| $$ \/  | $$|  $$$$$$$ /$$$$$$$$|  $$$$$$$");
			gotoxy(7,9);
			printf("|__/     |__/ \_______/|________/ \_______/");
			gotoxy(16,10);
			printf("/$$$$$$   /$$$$$$$  /$$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$");
			gotoxy(15,11);
			printf("/$$__  $$ /$$_____/ /$$_____/ |____  $$ /$$__  $$ /$$__  $$");
			gotoxy(14,12);
			printf("| $$$$$$$$|  $$$$$$ | $$        /$$$$$$$| $$  \  $$| $$$$$$$$");
			gotoxy(14,13);
			printf("| $$_____/ \ ____  $$| $$       /$$__  $$| $$  | $$| $$_____/");
			gotoxy(14,14);
			printf("|  $$$$$$$ /$$$$$$$/|  $$$$$$$|  $$$$$$$| $$$$$$$/|  $$$$$$$");
			gotoxy(15,15);
			printf("\ _______/|_______/  \_______/ \  _______/| $$____/  \_______/");
			gotoxy(54,16);
			printf("| $$");
			gotoxy(54,17);
			printf("| $$");
			gotoxy(54,18);
			printf("|__/\n\n");
			Sleep(100);
		}
	}
	setcolor(15); //Į�� ���(15)���� �ʱ�ȭ
	while (_kbhit()) _getch(); //���ۿ� ��ϵ� Ű���� ����
	
	scanf("%d",&show);
	system("cls");
	if(show==1)
	{
		showcharacter();
	}
	else if(show != 2)
	{
		ranking();
	}

	system("pause");

}
void showcharacter()
{
	printf("ĳ�������");//ĳ���ͳ־����
}

void ranking()
{
	printf("��ŷ���");//��ŷ�־����
}
