#pragma once
using namespace std;
#include <iostream>
#include "Consola.h"
class Inform {
public:
	static void InforInit() {//������ ���� ������ �˸��� â�� �׸���.
		textbackground(WHITE);
		textcolor(GREEN);
		gotoxy(70, 5); 
		cout << "_________________________________";
		gotoxy(70, 6);
		cout << "|                                |";
		gotoxy(70, 11);
		cout << "|\t                              |";
		gotoxy(70, 12);
		cout << "|\tĳ����: ��                    |";
		gotoxy(70, 13);
		cout << "|\t                              |";
		gotoxy(70, 14);
		cout << "|\t��ǥ��: ��                    |";
		gotoxy(70, 15);
		cout << "|\t                              |";
		gotoxy(70, 16);
		cout << "|\t��ź: @                       |";
		gotoxy(70, 17);
		cout << "|\t                              |";
		gotoxy(70, 18);
		cout << "|\t������ �̵� ����: >>          |";
		gotoxy(70, 19);
		cout << "|\t                              |";
		gotoxy(70, 20);
		cout << "|\t���� �̵� ����: <<            |";
		gotoxy(70, 21);
		cout << "|\t                              |";
		gotoxy(70, 22);
		cout << "|\t�̵� �Ϸ�� :  *              |";
		gotoxy(70, 23);
		cout << "|\t                              |";
		gotoxy(70, 24);
		cout << "|  �̵�����Ƚ���� 1234�� �Դϴ�. |";
		gotoxy(70, 25);
		cout << "|\t                              |";
		gotoxy(70, 26);
		cout << "|________________________________|";
	}

	static void move(int *x,int y) {//�̵� Ƚ�� ó��
		textbackground(WHITE);
		textcolor(GREEN);
		gotoxy(70, 7);
		cout << "|\t                              |";
		gotoxy(70, 8);
		if (*x < 10) {
			cout << "|\t���� �̵� Ƚ��: " << *x << "��           |";
			(*x) += 1;//�����ͻ��
		}
		else if (*x < 100) {
			cout << "|\t���� �̵� Ƚ��: " << *x << "��          |";
			(*x) += 1;//�����ͻ��
		}
		else if (*x <1000) {
			cout << "|\t���� �̵� Ƚ��:" << *x << "��          |";
			(*x) += 1;//�����ͻ��
		}
		else if (*x < 1234) {
			textcolor(RED);
			cout << "|\t���� �̵� Ƚ��:" << *x << "��         |";
			(*x) += 1;//�����ͻ��
		}
		else {//�̵�Ƚ�� �ʰ��Ͽ� ���� ���Ḧ ó���Ѵ�.
			clrscr();
			textcolor(BLUE);
			gotoxy(25, 10);
			cout << "�̵�Ƚ���� �� �Һ��Ͽ� ����Ǿ����ϴ�.";
			gotoxy(25, 12);
			cout << y - 1 << "�ʱ��� �����Ͽ����� " << y << "�ʿ��� �����Ͽ����ϴ�.";
			gotoxy(25, 14);
			cout << "������ ��� x��ư�� ������ ������ �� �ֽ��ϴ�.";
		}
	}

	static void mapNum(int x) {//�� ��ȣ�� �˷��ִ� �Լ�
		textbackground(WHITE);
		textcolor(GREEN);
		gotoxy(70, 9);
		cout << "|\t                              |";
		gotoxy(70, 10);
		cout << "|\t�� ��ȣ: " << x << "/5��                |";
	}
	static void goalDestroyed(int a) {//��ǥ�� �ı��� ó�� �Լ�
		clrscr();
		textcolor(BLUE);
		gotoxy(25, 10);
		cout << "��ǥ���� �ı��Ͽ� ����Ǿ����ϴ�.";
		gotoxy(25, 12);
		cout << a - 1 << "�ʱ��� �����Ͽ����� " << a << "�ʿ��� �����Ͽ����ϴ�.";
		gotoxy(25, 14);
		cout << "���Ḧ ���Ͽ� �ƹ�Ű�� �Է����ֽñ� �ٶ��ϴ�..\n\n\n\n\n\n\n";
		exit(1);
	}
	static void clearGame() {//���� Ŭ���� ó�� �Լ�
		clrscr();
		textcolor(BLUE);
		gotoxy(25, 10);
		cout << "������ Ŭ�����ϼ̽��ϴ�!!!!!";
		gotoxy(25, 14);
		cout << "������ ��� x��ư�� ������ ������ �� �ֽ��ϴ�.";
	}
};