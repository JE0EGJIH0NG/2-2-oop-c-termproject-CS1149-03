#pragma once
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <conio.h>
#include <thread>
class Play {
public:
	static void move() {
		PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC );
		while (!_kbhit());
	}
	static void bomb() {
		int a = 0;
		PlaySound(TEXT("bomb.wav"), NULL, SND_FILENAME | SND_ASYNC);
		while (a==0) { //��ź �Ҹ��� �� ��µǱ� ���ؼ� O(n^2)���� 
			for (int i = 0; i < 100000; i++) {
				for (int j = 0; j < 10000; j++) {
					a++;
				}
			}
		};
	}
	static void nextStage() {
		int a = 0;
		PlaySound(TEXT("nextStage.wav"), NULL, SND_FILENAME | SND_ASYNC);
		while (a == 0) {
			for (int i = 0; i < 100000; i++) {
				for (int j = 0; j < 10000; j++) {
					a++;
				}
			}
		};
	}
};