//Written by Dhanushka Perera (26930994)

#include <string>
#include <ctime>
#include "Enemy.h"
#include "Boss.h"
#include <windows.h>
#include <iostream>
using namespace std;

Boss::Boss(string newEnemyName, int newEnemyHealth, int newEnemyAttack, int newEnemyDefence, char newEnemyPorM, int newBossSpecial) :Enemy(newEnemyName, newEnemyHealth, newEnemyAttack, newEnemyDefence, newEnemyPorM) {
	BossSpecial = new int (newBossSpecial);
}

Boss::~Boss() {
	delete BossSpecial;
}

int Boss::BossSpecialRoll() {
	srand(time(NULL));
	Sleep(500);
	int specialValue = *EnemyAttack + *BossSpecial + rand() % 3 + 4;
	return specialValue;
}

void Boss::BossFocusShift() {
	srand(time(NULL));
	int PorMShift = rand() % 2;
	if (PorMShift == 0) {
		cout << "Judicant shifted his focus to Physical!" << endl;
		*EnemyPorM = 'P';
	}
	else if (PorMShift == 1) {
		cout << "Judicant shifted his focus to Magical!" << endl;
		*EnemyPorM = 'M';
	}
}