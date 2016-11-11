#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
void setcolor(int color)//색깔함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void SetColor(int backcolor, int fontcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backcolor * 16 + fontcolor);
}
void gotoxy(int x, int y)//좌표함수
{
	COORD Pos = {x-1, y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
enum {
	BLACK,     //0 : 검정
	D_BLUE,    //1 : 어두운 파랑
	D_GREEN,   //2 : 어두운 초록
	D_SKYBLUE, //3 : 어두운 하늘
	D_RED,     //4 : 어두운 빨강
	D_VIOLET,  //5 : 어두운 보라
	D_YELLOW,  //6 : 어두운 노랑
	GRAY,      //7 : 회색
	D_GRAY,    //8 : 어두운 회색
	BLUE,      //9 : 파랑
	GREEN,     //10 : 초록
	SKYBLUE,   //11 : 하늘
	RED,       //12 : 빨강
	VIOLET,    //13 : 보라
	YELLOW,    //14 : 노랑
	WHITE,     //15 : 흰색
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
	int show; //다음화면
	int color1; //색깔반짝 반복
	int i = 1;
	printf("    ┌──────────────────────────────────┐\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
    printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    │                                                                    │\n");
	printf("    └──────────────────────────────────┘\n");
	printf("                                 ┌─────┐ \n");
	printf("                                 │          │ \n");
	printf("                                 │          │ \n");
	printf("                                 │          │ \n");
	printf("                                 └─────┘ \n");
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
	printf(" 1.시작");
	gotoxy(37,22);
	printf(" 2.랭킹");
	gotoxy(37,23);
	printf(" 3.종료");
	
	while(1)//반짝이 효과
	{
		if (_kbhit()) break;
		for (color1 = 10; color1 < 15; color1++) //컬러 10~15반복
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
	setcolor(15); //칼라 흰색(15)으로 초기화
	while (_kbhit()) _getch(); //버퍼에 기록된 키값을 버림
	
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
	printf("캐릭터출력");//캐릭터넣어야함
}

void ranking()
{
	printf("랭킹출력");//랭킹넣어야함
}
