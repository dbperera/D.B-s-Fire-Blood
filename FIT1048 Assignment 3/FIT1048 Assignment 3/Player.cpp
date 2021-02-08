//Written by Dhanushka Perera (26930994)

#include <string>
#include <ctime>
#include "Player.h"
#include <windows.h>
using namespace std;

//Define the player's stats.
Player::Player(string newPlayerName, int newPlayerHealth, int newPlayerAttack, int newPlayerDefence, int newPlayerSpecial, int newPlayerCash) {
	PlayerName = new string (newPlayerName);
	PlayerHealth = new int (newPlayerHealth);
	PlayerAttack = new int (newPlayerAttack);
	PlayerDefence = new int (newPlayerDefence);
	PlayerSpecial = new int (newPlayerSpecial);
	PlayerCash = new int (newPlayerCash);
}

Player::~Player() {
	delete PlayerName;
	delete PlayerHealth;
	delete PlayerAttack;
	delete PlayerDefence;
	delete PlayerSpecial;
	delete PlayerCash;
}

//Create a function that will return the player's health.
int Player::getPlayerHealth() {
	return *PlayerHealth;
}

//Create a function that will update the player's health.
void Player::setPlayerHealth(int setHealth) {
	*PlayerHealth = setHealth;
}

//Create a function that will update the player's attack.
void Player::setPlayerAttack(int setAttack) {
	*PlayerAttack = setAttack;
}

//Create a function that will update the player's defence.
void Player::setPlayerDefence(int setDefence) {
	*PlayerDefence = setDefence;
}

//Create a function that will update the player's special.
void Player::setPlayerSpecial(int setSpecial) {
	*PlayerSpecial = setSpecial;
}

//Create a function that will represent the player's attack damage for that turn.
int Player::PlayerAttackRoll() {
	srand(time(NULL));
	Sleep(500);
	int attackValue = *PlayerAttack + rand() % 6 + 1;
	return attackValue;
}

//Create a function that will represent the player's blockability for that turn.
int Player::PlayerDefenceRoll() {
	srand(time(NULL));
	Sleep(500);
	int defenceValue = *PlayerDefence + rand() % 6 + 1;
	return defenceValue;
}

//Create a function that will represent the player's special for that turn.
int Player::PlayerSpecialRoll() {
	srand(time(NULL));
	Sleep(500);
	int specialValue = *PlayerAttack + *PlayerSpecial + rand() % 3 + 4;
	return specialValue;
}

//Returns the amount of cash the player has.
int Player::getPlayerCash() {
	return *PlayerCash;
}

//Adds an amount to the player's current amount of cash.
void Player::addToPlayerCash(int addPlayerCash) {
	*PlayerCash = *PlayerCash + addPlayerCash;
}

//Subtracts an amount from the player's current amount of cash.
void Player::subtractFromPlayerCash(int subtractPlayerCash) {
	*PlayerCash = *PlayerCash - subtractPlayerCash;
}

//Adds 5 to the player's current health.
int Player::Heal(int Health) {
	int newHealth = Health + 5;
	if (Health > *PlayerHealth) {
		Health = *PlayerHealth;
	}
	return newHealth;
}

//Removes a certain amount from the player's health.
int Player::TakeDamage(int Health, int DamageTaken) {
	int newHealth = Health - DamageTaken;
	return newHealth;
}