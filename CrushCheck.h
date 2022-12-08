#pragma once
#include <iostream>
using namespace std;
#include "Maps.h"
class Crush {
public:

	static int crushWallL(int x, int y,int mapData[][20]) {
		if (mapData[y][x - 1] == 1) {
			return 0;
		}
	}

	static int crushWallR(int x, int y,int mapData[][20]) {
		if (mapData[y][x + 1] == 1) {
			return 0;
		}
	}

	static int crushWallUp(int x, int y, int mapData[][20]) {
		if (mapData[y - 1][x] == 1) {
			return 0;
		}
	}

	static int crushWallDown(int x, int y, int mapData[][20]) {
		if (mapData[y + 1][x]== 1) {
			return 0;
		}
	}

	static bool crushBallDown(int x, int y) {
		if (mapData[x + 1][y] == 2) {
			return true;//공끼리 충돌
		}
		//단방향 충돌
		if ((mapData[x + 1][y] == 6))return true;
		if ((mapData[x + 1][y] == 5))return true;
		else
			return false;
	}

	static bool crushBallUp(int x, int y) {
		if (mapData[x - 1][y] == 2) {
			return true;//공끼리 충돌
		}
		//단방향 충돌
		if ((mapData[x-1][y ] == 6))return true;
		if ((mapData[x-1][y] == 5))return true;
		else
			return false;
	}

	static bool crushBallR(int x, int y) {
		if (mapData[x ][y+1] == 2) {
			return true;//공끼리 충돌
		}
		//단방향 충돌
		if ((mapData[x][y + 1] == 6 ))return true;
		if ((mapData[x][y + 1] == 5))return true;
		else
			return false;
	}

	static bool crushBallL(int x, int y) {
		if (mapData[x][y - 1] == 2) {
			return true;//공끼리 충돌
		}
		//단방향 충돌
		if ((mapData[x][y - 1] == 5) )return true;
		if ((mapData[x][y - 1] == 6))return true;
		else
			return false;
	}
	
};