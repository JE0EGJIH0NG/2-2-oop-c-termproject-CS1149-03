#pragma once
using namespace std;
#include <iostream>
#include "Consola.h"
class Inform {
public:
	static void InforInit() {//오른쪽 게임 내용을 알리는 창을 그린다.
		textbackground(WHITE);
		textcolor(GREEN);
		gotoxy(70, 5); 
		cout << "_________________________________";
		gotoxy(70, 6);
		cout << "|                                |";
		gotoxy(70, 11);
		cout << "|\t                              |";
		gotoxy(70, 12);
		cout << "|\t캐릭터: Ω                    |";
		gotoxy(70, 13);
		cout << "|\t                              |";
		gotoxy(70, 14);
		cout << "|\t목표물: Π                    |";
		gotoxy(70, 15);
		cout << "|\t                              |";
		gotoxy(70, 16);
		cout << "|\t폭탄: @                       |";
		gotoxy(70, 17);
		cout << "|\t                              |";
		gotoxy(70, 18);
		cout << "|\t오른쪽 이동 가능: >>          |";
		gotoxy(70, 19);
		cout << "|\t                              |";
		gotoxy(70, 20);
		cout << "|\t왼쪽 이동 가능: <<            |";
		gotoxy(70, 21);
		cout << "|\t                              |";
		gotoxy(70, 22);
		cout << "|\t이동 완료시 :  *              |";
		gotoxy(70, 23);
		cout << "|\t                              |";
		gotoxy(70, 24);
		cout << "|  이동가능횟수는 1234번 입니다. |";
		gotoxy(70, 25);
		cout << "|\t                              |";
		gotoxy(70, 26);
		cout << "|________________________________|";
	}

	static void move(int *x,int y) {//이동 횟수 처리
		textbackground(WHITE);
		textcolor(GREEN);
		gotoxy(70, 7);
		cout << "|\t                              |";
		gotoxy(70, 8);
		if (*x < 10) {
			cout << "|\t나의 이동 횟수: " << *x << "번           |";
			(*x) += 1;//포인터사용
		}
		else if (*x < 100) {
			cout << "|\t나의 이동 횟수: " << *x << "번          |";
			(*x) += 1;//포인터사용
		}
		else if (*x <1000) {
			cout << "|\t나의 이동 횟수:" << *x << "번          |";
			(*x) += 1;//포인터사용
		}
		else if (*x < 1234) {
			textcolor(RED);
			cout << "|\t나의 이동 횟수:" << *x << "번         |";
			(*x) += 1;//포인터사용
		}
		else {//이동횟수 초과하여 게임 종료를 처리한다.
			clrscr();
			textcolor(BLUE);
			gotoxy(25, 10);
			cout << "이동횟수를 다 소비하여 종료되었습니다.";
			gotoxy(25, 12);
			cout << y - 1 << "맵까지 성공하였으며 " << y << "맵에서 실패하였습니다.";
			gotoxy(25, 14);
			cout << "오른쪽 상단 x버튼을 눌러서 나가실 수 있습니다.";
		}
	}

	static void mapNum(int x) {//맵 번호를 알려주는 함수
		textbackground(WHITE);
		textcolor(GREEN);
		gotoxy(70, 9);
		cout << "|\t                              |";
		gotoxy(70, 10);
		cout << "|\t맵 번호: " << x << "/5번                |";
	}
	static void goalDestroyed(int a) {//목표물 파괴시 처리 함수
		clrscr();
		textcolor(BLUE);
		gotoxy(25, 10);
		cout << "목표물을 파괴하여 종료되었습니다.";
		gotoxy(25, 12);
		cout << a - 1 << "맵까지 성공하였으며 " << a << "맵에서 실패하였습니다.";
		gotoxy(25, 14);
		cout << "종료를 위하여 아무키를 입력해주시길 바랍니다..\n\n\n\n\n\n\n";
		exit(1);
	}
	static void clearGame() {//게임 클리어 처리 함수
		clrscr();
		textcolor(BLUE);
		gotoxy(25, 10);
		cout << "게임을 클리어하셨습니다!!!!!";
		gotoxy(25, 14);
		cout << "오른쪽 상단 x버튼을 눌러서 나가실 수 있습니다.";
	}
};