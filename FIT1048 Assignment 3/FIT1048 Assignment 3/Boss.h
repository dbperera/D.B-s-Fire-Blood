//Written by Dhanushka Perera (26930994)

#ifndef Boss_h
#define Boss_h

#include <string>
using namespace std;

//Create an enemy class for the enemies, denoting all the basic enemy stats and functions.
class Boss : public Enemy {
private:
	int* BossSpecial;
public:
	Boss(string newEnemyName, int newEnemyHealth, int newEnemyAttack, int newEnemyDefence, char newEnemyPorM, int newBossSpecial);
	~Boss();
	int BossSpecialRoll();
	void BossFocusShift();
};

#endif
