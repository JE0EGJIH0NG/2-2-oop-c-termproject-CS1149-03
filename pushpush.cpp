#include <iostream>
using namespace std;
#define MAP_X1 5
#define MAP_Y1 5
#include "View.h"
#include "Goal.h"
#include "Maps.h"
#include "Information.h"
#include "Sound.h"
int main() {
	int cntMap = 1;//현재 내가 몇번째 맵인지 저장하는 변수
	int goal = 0;
	int posx = 2, posy = 4;//현재 캐릭터의 위치
	int oldx, oldy;
	_setcursortype(_NOCURSOR);
	textbackground(WHITE);
	clrscr();
	View::drawMap();
	View::drawCharacter(posx, posy);
	int move = 0;//캐릭터의 이동 횟수를 나타내는 변수
	int* pMove = &move;//이동횟수 증가를 위해 포인터를 매개변수로 넘길 예정
	Inform::InforInit();//오른쪽 게임 내용을 알리는 창을 그린다.
	while (1) {

		Inform::mapNum(cntMap);//오른쪽에 몇 번째 맵인지 알리는 창을 그린다..
		Inform::move(pMove, cntMap);//캐력터 이동 횟수를 처리하는 함수
		
		Play::move();//캐릭터 이동 사운드 효과 처리 함수
		textcolor(CYAN);

		int key = View::getkey();
		int nposx = oldx = posx;
		int nposy = oldy = posy;
		//case 2에서 사용할 위치 포인터(loadMove)
		int* pPosx = &posx;
		int* pPosy = &posy;
		
		switch (key) {
		case M_LEFTKEY:nposx --; break;
		case M_UPKEY: nposy--; break;
		case M_DOWNKEY: nposy++; break;
		case M_RIGHTKEY:nposx ++; break;
		}
		switch (mapData[nposy][nposx])//위에서 감소시킨 맵 데이터의 좌표기준으로 캐릭터이동 계산
		{
		case 0://path
			posx = nposx; posy = nposy;	
			break;
		case 4://Goal
			break;
		case 5://왼쪽으로만 이동 가능
			if ((nposx < posx)) {
				posx = nposx; posy = nposy;
			}
			break;
		case 6://오른쪽으로만 이동 가능
			if (nposx > posx) {
				posx = nposx; posy = nposy;
			}
			break;
		case 3://*
		case 1://==
			break;
/*------------------------------------bomb----------------------------------*/
		case 7:
			if (nposx < posx) {//왼쪽 이동
				//폭탄 왼쪽좌표에 벽,단방향 이동, 공 인 경우
				if ((mapData[nposy][ nposx-1] == 1) || (mapData[nposy][nposx - 1] == 5) || (mapData[nposy][nposx - 1] == 6) || (mapData[nposy][nposx - 1] == 2)) {
					Boom::delWallL(nposx-1 , nposy);//해당 좌표 데이터 변수를 0으로 변경
					View::drawCell(nposx - 1, nposy);//원래 폭탄 위치 및 파과한 장해물 좌표 셀을 다시 그린다
					View::drawCell(nposx, nposy);
					posx = nposx; posy = nposy;//캐릭터 이동
					Play::bomb();//폭탄 사운드 효과
					break;
				}
				//폭탄 왼쪽이 목표물 혹은 완료된 목표물인 경우
				if (mapData[nposy][nposx - 1] == 3 || mapData[nposy][nposx - 1] == 4) {
					clrscr();
					Inform::goalDestroyed(cntMap);//게임 종료
					break;
				}
				/*폭탄 이동 처리*/
				mapData[nposy][nposx - 1] = 7;
				mapData[nposy][nposx] = 0;
				View::drawCell(nposx - 1, nposy);
				View::drawCell(nposx, nposy);
				posx = nposx; posy = nposy;
				break;
			}
			else if (nposx > posx) {//오른쪽 이동
				//폭탄 오른쪽좌표에 벽,단방향 이동, 공 인 경우
				if ((mapData[nposy][nposx+1] == 1)|| (mapData[nposy][nposx + 1] == 6) || (mapData[nposy][nposx + 1] == 5) || (mapData[nposy][nposx + 1] == 2)) {				
					Boom::delWallR(nposx + 1, nposy);//해당 좌표 데이터 변수를 0으로 변경
					View::drawCell(nposx +1, nposy);//원래 폭탄 위치 및 파과한 장해물 좌표 셀을 다시 그린다
					View::drawCell(nposx, nposy);
					posx = nposx; posy = nposy;//캐릭터 이동
					Play::bomb();//폭탄 사운드 효과
					break;
				}
				//폭탄 오른쪽이 목표물 혹은 완료된 목표물인 경우
				if (mapData[nposy][nposx + 1] == 3 || mapData[nposy][nposx + 1] == 4) {
					clrscr();
					Inform::goalDestroyed(cntMap);//게임 종료
					break;
				}
				/*폭탄 이동 처리*/
				mapData[nposy][nposx + 1] = 7;
				mapData[nposy][nposx] = 0;
				View::drawCell(nposx + 1, nposy);
				View::drawCell(nposx, nposy);
				posx = nposx; posy = nposy;
				break;
			}
			//위로 이동
			else if (nposy < posy) {

				if (mapData[nposy-1][nposx ] == 1 || (mapData[nposy-1][nposx ] == 6) || (mapData[nposy-1][nposx ] == 5) || (mapData[nposy - 1][nposx] == 2)) {
					Boom::delWallUp(nposx , nposy-1);
					View::drawCell(nposx , nposy-1);
					View::drawCell(nposx, nposy);
					posx = nposx; posy = nposy;
					Play::bomb();
					break;
				}
				if (mapData[nposy-1][nposx ] == 3 || mapData[nposy-1][nposx ] == 4) {
					clrscr();
					Inform::goalDestroyed(cntMap);
					break;
				}
				mapData[nposy-1][nposx ] = 7;
				mapData[nposy][nposx] = 0;
				View::drawCell(nposx , nposy-1);
				View::drawCell(nposx, nposy);
				posx = nposx; posy = nposy;
				break;
			}
			//아래로 이동
			else if (nposy > posy) {

				if (mapData[nposy + 1][nposx] == 1 || (mapData[nposy+1][nposx ] == 6) || (mapData[nposy+1][nposx ] == 5) || (mapData[nposy + 1][nposx] == 2)) {
					Boom::delWallDown(nposx, nposy + 1);
					View::drawCell(nposx, nposy + 1);
					View::drawCell(nposx, nposy);
					posx = nposx; posy = nposy;
					Play::bomb();
					break;
				}
				if (mapData[nposy + 1][nposx] == 3 || mapData[nposy + 1][nposx] == 4) {
					clrscr();
					Inform::goalDestroyed(cntMap);
					break;
				}
				mapData[nposy + 1][nposx] = 7;
				mapData[nposy][nposx] = 0;
				View::drawCell(nposx, nposy + 1);
				View::drawCell(nposx, nposy);
				posx = nposx; posy = nposy;
				break;
			}
/*------------------------load-----------------------------------------*/
		case 2://load
			textbackground(YELLOW);
			//왼쪽이동
			if (nposx < posx) {
				//공끼리 충돌, 단방향 이동 구간 충돌
				if (Crush::crushBallL(nposy, nposx) == true) {
					break;
				}
				View::loadMoveL(nposx, nposy, pPosx, pPosy);

			}
			//오른쪽 이동
			else if (nposx > posx) {
				//공끼리 충돌, 단방향 이동 구간 충돌
				if (Crush::crushBallR(nposy, nposx) == true) {
					break;
				}
				View::loadMoveR(nposx, nposy, pPosx, pPosy);
			}
			//위로 이동
			else if (nposy < posy) {
				//공끼리 충돌, 단방향 이동 구간 충돌
				if (Crush::crushBallUp(nposy, nposx) == true) {
					break;
				}
				View::loadMoveUp(nposx, nposy, pPosx, pPosy);
			}
			//아래로 이동
			else if (nposy > posy) {
				//공끼리 충돌, 단방향 이동 구간 충돌
				if (Crush::crushBallDown(nposy, nposx) == true) {
					break;
				};
				View::loadMoveDown(nposx, nposy, pPosx, pPosy);
			};
			
			break;
		}

		if (oldx != posx || oldy != posy) {
			View::drawCell(oldx, oldy);//원래 위치의 심볼을 mapData에서 가져와서 그린다.
			View::drawCharacter(posx, posy);//움작일 위치에 가서 캐릭터를 그린다
		}
/*-------------------맵 완료 되었는지 체크한다-------------------------*/
		if ((isGoal::allGoal(mapData[1][1], mapData[18][8], mapData[2][17], mapData[13][14]) == true)&&cntMap==1) {
			MapUpdate::update2();
			View::drawMap();
			posx = 2, posy = 4;
			View::drawCharacter(posx, posy);
			cntMap += 1;
			Play::nextStage();
		};
		if ((isGoal::allGoal(mapData[1][1], mapData[18][8], mapData[2][17], mapData[13][14]) == true)&&cntMap==2) {
			MapUpdate::update3();
			View::drawMap();
			posx = 2, posy = 4;
			View::drawCharacter(posx, posy);
			cntMap += 1;
			Play::nextStage();
		};
		if ((isGoal::allGoal(mapData[1][1], mapData[18][8], mapData[2][17], mapData[13][14]) == true) && cntMap == 3) {
			MapUpdate::update4();
			View::drawMap();
			posx = 2, posy = 4;
			View::drawCharacter(posx, posy);
			cntMap += 1;
			Play::nextStage();
		};
		if ((isGoal::allGoal(mapData[1][1], mapData[18][8], mapData[2][17], mapData[13][14]) == true) && cntMap == 4) {
			MapUpdate::update5();
			View::drawMap();
			posx = 2, posy = 4;
			View::drawCharacter(posx, posy);
			cntMap += 1;
			Play::nextStage();
		};
		if ((isGoal::allGoal(mapData[1][1], mapData[18][8], mapData[2][17], mapData[13][14]) == true) && cntMap == 5) {
			Inform::clearGame();
		}
	}


}