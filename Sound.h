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
		while (a==0) { //폭탄 소리가 다 출력되기 위해서 O(n^2)으로 
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