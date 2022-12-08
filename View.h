#pragma once

#include <iostream>
using namespace std;
#include <conio.h>
#include "keycode.h"
#include "Consola.h"
#include "CrushCheck.h"
#include "Goal.h" 
#include "Maps.h"
#define MAP_WIDTH 20
#define MAP_HEIGHT 20
class View {
	
public:
	static int getkey() {//키 입력
		int ch = _getch();
		return (ch == 0xe0) ? (0xe000 | _getch()) : ch;
	}
	static void xyputstr(int x, int y, const char* str) {
		gotoxy(x * 2, y);//정사각형 좌표계
		cout << str;
	}
	static void drawBox(int x1, int y1, int x2, int y2, int color) {
		textcolor(color);
		for (int i = x1; i < x2; ++i) {
			xyputstr(i, y1, "-------");
			xyputstr(i, y2, "-------");
		}
		for (int i = y1; i < y2; ++i) {
			xyputstr(x1, i, "|");
			xyputstr(x2, i, "|");
		}
		xyputstr(x1, y1, "┌");
		xyputstr(x2, y1, "┐");
		xyputstr(x1, y2, "└");
		xyputstr(x2, y2, "┘");
	}
	static void drawCharacter(int col, int row) {
		gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
		puts("Ω");
	}
	static void drawCell(int col, int row) {
		const char* cellSymbol[] = { "  ","==","ο","* ","Π","<<",">>","@ "};
		int cell = mapData[row][col];
		textbackground((cell == 1) ? BROWN : YELLOW);
		textcolor((cell == 1) ? MAGENTA : CYAN);
		//textcolor(CYAN);
		gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
		puts(cellSymbol[cell]);
	}
	static void drawMap() {
		for (int row = 0; row < MAP_HEIGHT; ++row)
			for (int col = 0; col < MAP_WIDTH; ++col)
				drawCell(col, row);
	}

	static void loadMoveL(int oldLX , int oldLY,int *posx,int *posy ) {
		if (oldLX==1) {//이동할 곳이 벽인 경우(게임창 안벗어나기 위해서)
			return;
		}
		//벽과 총돌하는지 검사한다.
		if (Crush::crushWallL(oldLX,oldLY,mapData) == 0) {
			return;

		}
		*posx = oldLX; *posy = oldLY;//캐릭터 이동을 위해서 포인터로 받은 값을 변경
		mapData[oldLY][oldLX] = 0;//공이 있던 자리를 path로
		mapData[oldLY][oldLX-1] = 2;//공을 왼쪽으로 이동 처리
		gotoxy((MAP_X1 + oldLX ) * 2, MAP_Y1 + oldLY + 1);//공을 그릴 위치로 이동
		puts("ο");//공 그린다
		if (isGoal::goalCheck(mapData[18][8]) == true) {//골인
			mapData[18][8] = 3;//*로 변경
			drawCell(8, 18);//해당 셀을 다시 그린다
		}
		else if (isGoal::goalCheck(mapData[2][17]) == true) {//골
			mapData[2][17] = 3;//*로 변경
			drawCell(17, 2);//해당 셀을 다시 그린다
		}
		else if (isGoal::goalCheck(mapData[13][14]) == true) {//골
			mapData[13][14] = 3;//*로 변경
			drawCell(14, 13);
		}
		else if ((isGoal::goalCheck(mapData[1][1]) == true)) {//골
			mapData[1][1] = 3;//*로 변경
			drawCell(1, 1);//해당 셀을 다시 그린다
		}
	
	}

	static void loadMoveR(int oldLX, int oldLY, int* posx, int* posy) {
		if (oldLX == 18 ) {//이동할 곳이 벽인 경우(게임창 안벗어나기 위해서)
			return;
		}
		//벽과 총돌하는지 검사한다.
		if (Crush::crushWallR(oldLX, oldLY,mapData) == 0) {
			return;
		}
		*posx = oldLX; *posy = oldLY;
		mapData[oldLY][oldLX] = 0;
		mapData[oldLY][oldLX + 1] = 2;
		gotoxy((MAP_X1 + oldLX+2) * 2, MAP_Y1 + oldLY + 1);
		puts("ο");
		if (isGoal::goalCheck(mapData[18][8]) == true) {
			mapData[18][8] = 3;
			drawCell(8, 18);
		}
		else if (isGoal::goalCheck(mapData[2][17]) == true) {
			mapData[2][17] = 3;
			drawCell(17, 2);
		}
		else if (isGoal::goalCheck(mapData[13][14]) == true) {
			mapData[13][14] = 3;
			drawCell(14, 13);
		}
		else if ((isGoal::goalCheck(mapData[1][1]) == true)) {
			mapData[1][1] = 3;
			drawCell(1, 1);
		}
	}

	static void loadMoveUp(int oldLX, int oldLY, int* posx, int* posy) {
		if (oldLY == 1) {//이동할 곳이 벽인 경우(게임창 안벗어나기 위해서)
			return;
		}
		//벽과 총돌하는지 검사한다.
		if (Crush::crushWallUp(oldLX, oldLY,mapData) == 0) {
			return;
		}
		*posx = oldLX; *posy = oldLY;
		mapData[oldLY][oldLX] = 0;
		mapData[oldLY-1][oldLX ] = 2;
		gotoxy((MAP_X1 + oldLX+1) * 2, MAP_Y1 + oldLY );
		puts("ο");
		if (isGoal::goalCheck(mapData[18][8]) == true) {
			mapData[18][8] = 3;
			drawCell(8, 18);
		}
		else if (isGoal::goalCheck(mapData[2][17]) == true) {
			mapData[2][17] = 3;
			drawCell(17, 2);
		}
		else if (isGoal::goalCheck(mapData[13][14]) == true) {
			mapData[13][14] = 3;
			drawCell(14, 13);
		}
		else if ((isGoal::goalCheck(mapData[1][1]) == true)) {
			mapData[1][1] = 3;
			drawCell(1, 1);
		}
	}

	static void loadMoveDown(int oldLX, int oldLY, int* posx, int* posy) {
		if (oldLY == 18) {//이동할 곳이 벽인 경우(게임창 안벗어나기 위해서)
			return;
		}
		//벽과 총돌하는지 검사한다.
		if (Crush::crushWallDown(oldLX, oldLY,mapData) == 0) {
			return;
		}
		*posx = oldLX; *posy = oldLY;
		mapData[oldLY][oldLX] = 0;
		mapData[oldLY+1][oldLX ] = 2;
		gotoxy((MAP_X1 + oldLX + 1) * 2, MAP_Y1 + oldLY+2 );
		puts("ο");
		if (isGoal::goalCheck(mapData[18][8]) == true) {
			mapData[18][8] = 3;
			drawCell(8, 18);
		}
		else if (isGoal::goalCheck(mapData[2][17]) == true) {
			mapData[2][17] = 3;
			drawCell(17, 2);
		}
		else if (isGoal::goalCheck(mapData[13][14]) == true) {
			mapData[13][14] = 3;
			drawCell(14, 13);
		}
		else if ((isGoal::goalCheck(mapData[1][1]) == true)) {
			mapData[1][1] = 3;
			drawCell(1, 1);
		}

	}
};

