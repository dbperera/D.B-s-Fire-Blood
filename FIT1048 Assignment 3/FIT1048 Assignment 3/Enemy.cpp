//Written by Dhanushka Perera (26930994)

#include <string>
#include <ctime>
#include "Enemy.h"
#include <windows.h>
using namespace std;

//Define the enemy's stats.
Enemy::Enemy(string newEnemyName, int newEnemyHealth, int newEnemyAttack, int newEnemyDefence, char newEnemyPorM) {
	EnemyName = new string (newEnemyName);
	EnemyHealth = new int (newEnemyHealth);
	EnemyAttack = new int (newEnemyAttack);
	EnemyDefence = new int (newEnemyDefence);
	EnemyPorM = new char (newEnemyPorM);
}

Enemy::~Enemy() {
	delete EnemyName;
	delete EnemyHealth;
	delete EnemyAttack;
	delete EnemyDefence;
	delete EnemyPorM;
}

////Create a function that will return the enemy's health.
int Enemy::getEnemyHealth() {
	return *EnemyHealth;
}

//Create a function that will represent the enemy's attack damage for that turn.
int Enemy::EnemyAttackRoll() {
	srand(time(NULL));
	Sleep(500);
	int attackValue = *EnemyAttack + rand() % 6 + 1;
	return attackValue;
}

//Create a function that will represent the enemy's blockability for that turn.
int Enemy::EnemyDefenceRoll() {
	srand(time(NULL));
	Sleep(500);
	int defenceValue = *EnemyDefence + rand() % 6 + 1;
	return defenceValue;
}

//Removes a certain amount from the enemy's health.
int Enemy::TakeDamage(int Health, int DamageTaken) {
	int newHealth = Health - DamageTaken;
	return newHealth;
}

//Returns whether the enemy is doing a physical or magical attack.
char Enemy::getEnemyPorM() {
	return *EnemyPorM;
}

int Enemy::EndonSiphon(int Health) {
	Health += 2;
	return Health;
}