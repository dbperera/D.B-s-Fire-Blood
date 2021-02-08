//Written by Dhanushka Perera (26930994)

#ifndef Player_h
#define Player_h

#include <string>
using namespace std;

//Create a player class for the playable character, including all her stats and functions.
class Player {
private:
	int* PlayerAttack;
	int* PlayerDefence;
	int* PlayerSpecial;
public:
	Player(string newPlayerName, int newPlayerHealth, int newPlayerAttack, int newPlayerDefence, int newPlayerSpecial, int newPlayerCash);
	~Player();
	string* PlayerName;
	int* PlayerCash;
	int* PlayerHealth;
	int getPlayerHealth();
	void setPlayerHealth(int setHealth);
	void setPlayerAttack(int setAttack);
	void setPlayerDefence(int setDefence);
	void setPlayerSpecial(int setSpecial);
	int PlayerAttackRoll();
	int PlayerDefenceRoll();
	int PlayerSpecialRoll();
	int getPlayerCash();
	void addToPlayerCash(int addPlayerCash);
	void subtractFromPlayerCash(int subtractPlayerCash);
	int Heal(int Health);
	int TakeDamage(int Health, int DamageTaken);
};

#endif
