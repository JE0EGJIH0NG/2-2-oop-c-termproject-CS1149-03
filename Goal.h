#pragma once
using namespace std;

class isGoal {

public:
	
	static bool goalCheck(int x ) {
		if (x == 2) {
			return true;
		}
		else
			return false;
	}

	static bool allGoal(int a, int b, int c, int d) {
		if (a == 3 && b == 3 && c == 3 && d == 3) {
			return true;
		}
		else
			return false;
	
	}
};