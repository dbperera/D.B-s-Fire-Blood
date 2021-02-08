//Written by Dhanushka Perera (26930994)

#ifndef Enemy_h
#define Enemy_h

#include <string>
using namespace std;

//Create an enemy class for the enemies, denoting all the basic enemy stats and functions.
class Enemy {
public:
	Enemy(string newEnemyName, int newEnemyHealth, int newEnemyAttack, int newEnemyDefence, char newPorM);
	~Enemy();
	string *EnemyName;
	int *EnemyHealth;
	int *EnemyAttack;
	int *EnemyDefence;
	char *EnemyPorM;
	int getEnemyHealth();
	int EnemyAttackRoll();
	int EnemyDefenceRoll();
	int TakeDamage(int Health, int DamageTaken);
	char getEnemyPorM();
	int EndonSiphon(int Health);
};

#endif