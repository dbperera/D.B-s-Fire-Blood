//Written by Dhanushka Perera (26930994)

#include <string>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {

	cout << "Welcome to D.B's Fire & Blood, the best game you will every play in your life!" << endl;
	Sleep(1000);
	cout << "\n";
	Sleep(1000);
	cout << "The game will now be loaded for you..." << endl;
	Sleep(1000);
	cout << "\n";
	system("pause");
	system("cls");
	
	//Creating the player, enemies, and boss.
	Player Amelith("Amelith", 10, 3, 2, 2, 0);

	//Declare integers and characters to be used in battle.
	int AmelithHealth = Amelith.getPlayerHealth();
	char AmelithPorM;
	int SpecialCounter = 0;
	int DamageDealt;

	//Create Nahniga.
	Enemy Nahniga("Nahniga", 10, 1, 1, 'M');
	int NahnigaHealth = Nahniga.getEnemyHealth();
	
	//Announce battle with Nahniga.
	cout << "Battle Begins! Opponent: Nahniga\n" << endl;

	//Begin battle with Nahniga.
	while (AmelithHealth > 0 && NahnigaHealth > 0) {

		//Display stats.
		cout << "--Amelith--" << endl;
		cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
		cout << "--Nahniga--" << endl;
		cout << "Health: " << NahnigaHealth << "/" << Nahniga.getEnemyHealth() << "\n" << endl;

		//Input an attack.
		Sleep(1000);
		cout << "You are attacking Nahniga! Choose between a physical, magical, or special attack[P/M/S]: ";
		cin >> AmelithPorM;
		cout << "\n";

		//If the input is invalid, choose an attack again.
		while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M' && AmelithPorM != 's' && AmelithPorM != 'S') {
			cout << "That is an invalid input. Please choose another attack[P/M/S]: ";
			cin >> AmelithPorM;
			cout << "\n";
		}

		//For special attacks...
		while (AmelithPorM == 's' || AmelithPorM == 'S') {

			//If the special attack has not been used before, the player is entitled to use it.
			if (SpecialCounter == 0) {
				cout << "Amelith activates Fallen Tear, her special ability!" << endl;
				AmelithPorM = 'A';
				SpecialCounter += 1;
				DamageDealt = Amelith.PlayerSpecialRoll() - Nahniga.EnemyDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith deals " << DamageDealt << " damage!" << endl;
					NahnigaHealth = Nahniga.TakeDamage(NahnigaHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Nahniga successfully defends!" << endl;
				}

				//If Amelith defeats Nahniga, show health and end the fight.
				if (NahnigaHealth <= 0) {
					NahnigaHealth = 0;
					Sleep(2000);
					system("cls");
					cout << "--Amelith--" << endl;
					cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
					cout << "--Nahniga--" << endl;
					cout << "Health: " << NahnigaHealth << "/" << Nahniga.getEnemyHealth() << "\n" << endl;
					Sleep(1000);
					cout << "Amelith defeated Nahniga!" << endl;
				}
				cout << "\n";
				Sleep(1000);
				system("pause");
				system("cls");
			}

			//If the special attack has been used before, the player is not entitled to use it.
			else if (SpecialCounter == 1) {
				while (AmelithPorM == 's' || AmelithPorM == 'S') {
					cout << "You have already used your special attack for this round. Please choose another attack[P/M]: ";
					cin >> AmelithPorM;
				}
			}
		}

		//Autocorrecting lowercase p's and m's to upper case.
		if (AmelithPorM == 'p') {
			AmelithPorM = 'P';
		}
		else if (AmelithPorM == 'm') {
			AmelithPorM = 'M';
		}

		//If the attack is a physical or magical attack...
		if (AmelithPorM == 'P' || AmelithPorM == 'M') {

			//If the type of attack is the same as the enemy's defence, deal 0 damage.
			if (AmelithPorM == Nahniga.getEnemyPorM()) {
				cout << "Amelith fires non-elemental energy at Nahniga!" << endl;
				Sleep(1000);
				cout << "Nahniga is immune to magical attacks!" << endl;
				Sleep(1000);
				cout << "Amelith deals 0 damage!" << endl;
			}

			//If the type of attack is different from the enemy's defence, deal attack damage.
			else if (AmelithPorM != Nahniga.getEnemyPorM()) {
				cout << "Amelith slashes her sword at Nahniga!" << endl;
				DamageDealt = Amelith.PlayerAttackRoll() - Nahniga.EnemyDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith deals " << DamageDealt << " damage!" << endl;
					NahnigaHealth = Nahniga.TakeDamage(NahnigaHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Nahniga successfully defends!" << endl;
				}
			}

			//If Amelith defeats Nahniga, show health and end the fight.
			if (NahnigaHealth <= 0) {
				NahnigaHealth = 0;
				Sleep(2000);
				system("cls");
				cout << "--Amelith--" << endl;
				cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
				cout << "--Nahniga--" << endl;
				cout << "Health: " << NahnigaHealth << "/" << Nahniga.getEnemyHealth() << "\n" << endl;
				Sleep(1000);
				cout << "Amelith defeated Nahniga!" << endl;
			}
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}
		
		//If Nahniga is still alive, run the defence part of the battle.
		if (NahnigaHealth > 0) {

			//Display stats.
			cout << "--Amelith--" << endl;
			cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
			cout << "--Nahniga--" << endl;
			cout << "Health: " << NahnigaHealth << "/" << Nahniga.getEnemyHealth() << "\n" << endl;
			
			//Input defensive measures.
			Sleep(1000);
			cout << "Nahniga is attacking Amelith! Choose between physical or magical defence[P/M]: ";
			cin >> AmelithPorM;
			cout << "\n";

			//If the input is invalid, choose a defence again.
			while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M') {
				cout << "That is an invalid input. Please choose another defensive measure[P/M]: ";
				cin >> AmelithPorM;
				cout << "\n";
			}

			//Autocorrecting lowercase p's and m's to upper case.
			if (AmelithPorM == 'p') {
				AmelithPorM = 'P';
			}
			else if (AmelithPorM == 'm') {
				AmelithPorM = 'M';
			}

			//Describe the attack.
			cout << "Nahniga fires ice at Amelith!" << endl;

			//If the type of defence is the same as the enemy's attack, do normal defence.
			if (AmelithPorM == Nahniga.getEnemyPorM()) {
				Sleep(1000);
				cout << "Amelith created a magical barrier around herself!" << endl;
				DamageDealt = Nahniga.EnemyAttackRoll() - Amelith.PlayerDefenceRoll();
				if (DamageDealt > 0) {
					cout << "The magical barrier protects Amelith from some of the damage!" << endl;
					Sleep(1000);
					cout << "Amelith takes " << DamageDealt << " damage!" << endl;
					AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Nahniga's attack has no effect!" << endl;
					Sleep(1000);
					cout << "Amelith successfully defends!" << endl;
				}
			}

			//If the type of defence is different from the enemy's attack, ignore defence.
			else if (AmelithPorM != Nahniga.getEnemyPorM()) {
				Sleep(1000);
				cout << "Amelith blocks with her sword!" << endl;
				Sleep(1000);
				cout << "The attack cuts right through her defence!" << endl;
				Sleep(1000);
				cout << "Amelith's defence has no effect!" << endl;
				DamageDealt = Nahniga.EnemyAttackRoll();
				Sleep(500);
				cout << "Amelith takes " << DamageDealt << " damage!" << endl;
				AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
			}
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}

		//If Amelith was defeated, she respawns.
		if (AmelithHealth <= 0) {
			cout << "Amelith was defeated by Nahniga!" << endl;
			cout << "\n";
			Sleep(1000);
			cout << "Amelith: I won't let you beat me..." << endl;
			cout << "\n";
			Sleep(1000);
			cout << "Amelith revives and tries again!" << endl;
			AmelithHealth = Amelith.getPlayerHealth();
			NahnigaHealth = Nahniga.getEnemyHealth();
			SpecialCounter = 0;
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}
	}

	//Delete Nahniga.
	Nahniga.~Enemy();

	//Reset SpecialCounter
	SpecialCounter = 0;

	//Level up Amelith.
	cout << "----Level up!----\n" << endl;
	Sleep(1000);
	Amelith.setPlayerHealth(20);
	cout << "Amelith's health is now 20!" << endl;
	Sleep(1000);
	Amelith.setPlayerAttack(4);
	cout << "Amelith's attack has increased!" << endl;
	Sleep(1000);
	Amelith.setPlayerDefence(3);
	cout << "Amelith's defence has increased!" << endl;
	Sleep(1000);
	Amelith.setPlayerSpecial(3);
	cout << "Amelith's special ability has increased in power!" << endl;
	cout << "\n";
	Sleep(1000);
	system("pause");
	system("cls");

	//Reset Amelith's health back to full.
	AmelithHealth = Amelith.getPlayerHealth();

	//Create Lucian.
	Enemy Lucian("Lucian", 20, 3, 2, 'P');
	int LucianHealth = Lucian.getEnemyHealth();

	//Announce battle with Lucian.
	cout << "Battle Begins! Opponent: Lucian\n" << endl;

	//Begin battle with Lucian.
	while (AmelithHealth > 0 && LucianHealth > 0) {

		//Display stats.
		cout << "--Amelith--" << endl;
		cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
		cout << "--Lucian--" << endl;
		cout << "Health: " <<LucianHealth << "/" << Lucian.getEnemyHealth() << "\n" << endl;

		//Input an attack.
		Sleep(1000);
		cout << "You are attacking Lucian! Choose between a physical, magical, or special attack[P/M/S]: ";
		cin >> AmelithPorM;
		cout << "\n";

		//If the input is invalid, choose an attack again.
		while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M' && AmelithPorM != 's' && AmelithPorM != 'S') {
			cout << "That is an invalid input. Please choose another attack[P/M/S]: ";
			cin >> AmelithPorM;
			cout << "\n";
		}

		//For special attacks...
		while (AmelithPorM == 's' || AmelithPorM == 'S') {

			//If the special attack has not been used before, the player is entitled to use it.
			if (SpecialCounter == 0) {
				cout << "Amelith activates Fallen Tear, her special ability!" << endl;
				AmelithPorM = 'A';
				SpecialCounter += 1;
				DamageDealt = Amelith.PlayerSpecialRoll() - Lucian.EnemyDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith deals " << DamageDealt << " damage!" << endl;
					LucianHealth = Lucian.TakeDamage(LucianHealth, DamageDealt);;
				}
				else if (DamageDealt <= 0) {
					cout << "Lucian successfully defends!" << endl;
				}

				//If Amelith defeats Lucian, show health and end the fight.
				if (LucianHealth <= 0) {
					LucianHealth = 0;
					Sleep(2000);
					system("cls");
					cout << "--Amelith--" << endl;
					cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
					cout << "--Lucian--" << endl;
					cout << "Health: " << LucianHealth << "/" << Lucian.getEnemyHealth() << "\n" << endl;
					Sleep(1000);
					cout << "Amelith defeated Lucian!" << endl;
				}
				cout << "\n";
				Sleep(1000);
				system("pause");
				system("cls");
			}

			//If the special attack has been used before, the player is not entitled to use it.
			else if (SpecialCounter == 1) {
				while (AmelithPorM == 's' || AmelithPorM == 'S') {
					cout << "You have already used your special attack for this round. Please choose another attack[P/M]: ";
					cin >> AmelithPorM;
					cout << "\n";
				}
			}
		}

		//Autocorrecting lowercase p's and m's to upper case.
		if (AmelithPorM == 'p') {
			AmelithPorM = 'P';
		}
		else if (AmelithPorM == 'm') {
			AmelithPorM = 'M';
		}

		//If the attack is a physical or magical attack...
		if (AmelithPorM == 'P' || AmelithPorM == 'M') {

			//If the type of attack is the same as the enemy's defence, deal 0 damage.
			if (AmelithPorM == Lucian.getEnemyPorM()) {
				cout << "Amelith slashes her sword at Lucian!" << endl;
				Sleep(1000);
				cout << "Lucian is immune to physical attacks!" << endl;
				Sleep(1000);
				cout << "Amelith deals 0 damage!" << endl;
			}

			//If the type of attack is different from the enemy's defence, deal attack damage.
			else if (AmelithPorM != Lucian.getEnemyPorM()) {
				cout << "Amelith fires non-elemental energy at Lucian!" << endl;
				DamageDealt = Amelith.PlayerAttackRoll() - Lucian.EnemyDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith deals " << DamageDealt << " damage!" << endl;
					LucianHealth = Lucian.TakeDamage(LucianHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Lucian successfully defends!" << endl;
				}
			}

			//If Amelith defeats Lucian, show health and end the fight.
			if (LucianHealth <= 0) {
				LucianHealth = 0;
				Sleep(2000);
				system("cls");
				cout << "--Amelith--" << endl;
				cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
				cout << "--Lucian--" << endl;
				cout << "Health: " << LucianHealth << "/" << Lucian.getEnemyHealth() << "\n" << endl;
				Sleep(1000);
				cout << "Amelith defeated Lucian!" << endl;
			}
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}

		//If Lucian is still alive, run the defence part of the battle.
		if (LucianHealth > 0) {

			//Display stats.
			cout << "--Amelith--" << endl;
			cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
			cout << "--Lucian--" << endl;
			cout << "Health: " << LucianHealth << "/" << Lucian.getEnemyHealth() << "\n" << endl;

			//Input defensive measures.
			Sleep(1000);
			cout << "Lucian is attacking Amelith! Choose between physical or magical defence[P/M]: ";
			cin >> AmelithPorM;
			cout << "\n";

			//If the input is invalid, choose a defence again.
			while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M') {
				cout << "That is an invalid input. Please choose another defensive measure[P/M]: ";
				cin >> AmelithPorM;
				cout << "\n";
			}

			//Autocorrecting lowercase p's and m's to upper case.
			if (AmelithPorM == 'p') {
				AmelithPorM = 'P';
			}
			else if (AmelithPorM == 'm') {
				AmelithPorM = 'M';
			}

			//Describe the attack.
			cout << "Lucian swings his sword at Amelith!" << endl;

			//If the type of defence is the same as the enemy's attack, do normal defence.
			if (AmelithPorM == Lucian.getEnemyPorM()) {
				Sleep(1000);
				cout << "Amelith blocks with her sword!" << endl;
				DamageDealt = Lucian.EnemyAttackRoll() - Amelith.PlayerDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith's sword protects her from some of the damage!" << endl;
					Sleep(1000);
					cout << "Amelith takes " << DamageDealt << " damage!" << endl;
					AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Lucian's attack has no effect!" << endl;
					Sleep(1000);
					cout << "Amelith successfully defends!" << endl;
				}
			}

			//If the type of defence is different from the enemy's attack, ignore defence.
			else if (AmelithPorM != Lucian.getEnemyPorM()) {
				Sleep(1000);
				cout << "Amelith created a magical barrier around herself!" << endl;
				Sleep(1000);
				cout << "The attack cuts right through her defence!" << endl;
				Sleep(1000);
				cout << "Amelith's defence has no effect!" << endl;
				DamageDealt = Lucian.EnemyAttackRoll();
				Sleep(500);
				cout << "Amelith takes " << DamageDealt << " damage!" << endl;
				AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
			}
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}

		//If Amelith was defeated, she respawns.
		if (AmelithHealth <= 0) {
			cout << "Amelith was defeated by Lucian!" << endl;
			cout << "\n";
			Sleep(1000);
			cout << "Amelith: I won't let you beat me..." << endl;
			cout << "\n";
			Sleep(1000);
			cout << "Amelith revives and tries again!" << endl;
			AmelithHealth = Amelith.getPlayerHealth();
			LucianHealth = Lucian.getEnemyHealth();
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}
	}

	//Delete Lucian.
	Lucian.~Enemy();

	//Reset SpecialCounter
	SpecialCounter = 0;

	//Level up Amelith.
	cout << "----Level up!----\n" << endl;
	Sleep(1000);
	Amelith.setPlayerHealth(30);
	cout << "Amelith's health is now 30!" << endl;
	Sleep(1000);
	Amelith.setPlayerAttack(5);
	cout << "Amelith's attack has increased!" << endl;
	Sleep(1000);
	Amelith.setPlayerDefence(5);
	cout << "Amelith's defence has increased!" << endl;
	Sleep(1000);
	Amelith.setPlayerSpecial(5);
	cout << "Amelith's special ability has increased in power!" << endl;
	cout << "\n";
	Sleep(1000);
	system("pause");
	system("cls");

	//Reset Amelith's health back to full.
	AmelithHealth = Amelith.getPlayerHealth();

	//Create The Supremacy Sisters - Steel & Sorcery.
	Enemy Steel("Steel", 15, 3, 4, 'P');
	int SteelHealth = Steel.getEnemyHealth();
	Enemy Sorcery("Sorcery", 15, 3, 4, 'M');
	int SorceryHealth = Sorcery.getEnemyHealth();
	int SteelorSorcery;

	//Announce battle with The Supremacy Sisters.
	cout << "Battle Begins! Opponent: The Supremacy Sisters - Steel & Sorcery\n" << endl;

	//Begin battle with The Supremacy Sisters.
	while (AmelithHealth > 0 && (SteelHealth > 0 || SorceryHealth > 0)) {

		//Display stats.
		cout << "--Amelith--" << endl;
		cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
		cout << "--Steel--" << endl;
		cout << "Health: " << SteelHealth << "/" << Steel.getEnemyHealth() << "\n" << endl;
		cout << "--Sorcery--" << endl;
		cout << "Health: " << SorceryHealth << "/" << Sorcery.getEnemyHealth() << "\n" << endl;

		//Choose a sister to attack.
		Sleep(1000);
		cout << "Choose either [1.Steel] or [2.Sorcery] to attack[1/2]: ";
		cin >> SteelorSorcery;
		cout << "\n";

		//If the input is invalid, choose a sister again.
		while (SteelorSorcery != 1 && SteelorSorcery != 2) {
			cout << "That is an invalid input. Please choose another attack[P/M/S]: ";
			cin >> SteelorSorcery;
			cout << "\n";
		}

		//If Amelith attacks Steel...
		if (SteelorSorcery == 1) {

			//Input an attack.
			cout << "You have chosen to attack Steel! Choose between a physical, magical, or special attack[P/M/S]: ";
			cin >> AmelithPorM;
			cout << "\n";

			//If the input is invalid, choose an attack again.
			while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M' && AmelithPorM != 's' && AmelithPorM != 'S') {
				cout << "That is an invalid input. Please choose another attack[P/M/S]: ";
				cin >> AmelithPorM;
				cout << "\n";
			}

			//For special attacks...
			while (AmelithPorM == 's' || AmelithPorM == 'S') {

				//If the special attack has not been used before, the player is entitled to use it.
				if (SpecialCounter == 0) {
					cout << "Amelith activates Fallen Tear, her special ability!" << endl;
					AmelithPorM = 'A';
					SpecialCounter += 1;
					DamageDealt = Amelith.PlayerSpecialRoll() - Steel.EnemyDefenceRoll();
					if (DamageDealt > 0) {
						cout << "Amelith deals " << DamageDealt << " damage!" << endl;
						SteelHealth = Steel.TakeDamage(SteelHealth, DamageDealt);
					}
					else if (DamageDealt <= 0) {
						cout << "Steel successfully defends!" << endl;
					}

					//If Amelith defeats Steel, show health and revenge strike.
					if (SteelHealth <= 0) {
						SteelHealth = 0;
						Sleep(1000);
						cout << "\n";
						cout << "Amelith defeated Steel!" << endl;
						Sleep(1000);
						DamageDealt = 10;
						cout << "Sorcery deals " << DamageDealt << " damage as revenge!" << endl;
						AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
					}
					cout << "\n";
					Sleep(1000);
					system("pause");
					system("cls");
				}

				//If the special attack has been used before, the player is not entitled to use it.
				else if (SpecialCounter == 1) {
					while (AmelithPorM == 's' || AmelithPorM == 'S') {
						cout << "You have already used your special attack for this round. Please choose another attack[P/M]: ";
						cin >> AmelithPorM;
						cout << "\n";
					}
				}
			}

			//Autocorrecting lowercase p's and m's to upper case.
			if (AmelithPorM == 'p') {
				AmelithPorM = 'P';
			}
			else if (AmelithPorM == 'm') {
				AmelithPorM = 'M';
			}

			//If the attack is a physical or magical attack...
			if (AmelithPorM == 'P' || AmelithPorM == 'M') {

				//If the type of attack is the same as the enemy's defence, deal 0 damage.
				if (AmelithPorM == Steel.getEnemyPorM()) {
					cout << "Amelith slashes her sword at Steel!" << endl;
					Sleep(1000);
					cout << "Steel is immune to physical attacks!" << endl;
					Sleep(1000);
					cout << "Amelith deals 0 damage!" << endl;
				}

				//If the type of attack is different from the enemy's defence, deal attack damage.
				else if (AmelithPorM != Steel.getEnemyPorM()) {
					cout << "Amelith fires non-elemental energy at Steel!" << endl;
					DamageDealt = Amelith.PlayerAttackRoll() - Steel.EnemyDefenceRoll();
					if (DamageDealt > 0) {
						cout << "Amelith deals " << DamageDealt << " damage!" << endl;
						SteelHealth = Steel.TakeDamage(SteelHealth, DamageDealt);
					}
					else if (DamageDealt <= 0) {
						cout << "Steel successfully defends!" << endl;
					}
				}

				//If Amelith defeats Steel, show health and revenge strike.
				if (SteelHealth <= 0) {
					SteelHealth = 0;
					Sleep(1000);
					cout << "\n";
					cout << "Amelith defeated Steel!" << endl;
					Sleep(1000);
					DamageDealt = 10;
					cout << "Sorcery deals " << DamageDealt << " damage as revenge!" << endl;
					AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
				}
				cout << "\n";
				Sleep(1000);
				system("pause");
				system("cls");
			}
		}

		//If Amelith attacks Sorcery...
		else if (SteelorSorcery == 2) {

			//Input an attack.
			cout << "You have chosen to attack Sorcery! Choose between a physical, magical, or special attack[P/M/S]: ";
			cin >> AmelithPorM;
			cout << "\n";

			//If the input is invalid, choose an attack again.
			while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M' && AmelithPorM != 's' && AmelithPorM != 'S') {
				cout << "That is an invalid input. Please choose another attack[P/M/S]: ";
				cin >> AmelithPorM;
				cout << "\n";
			}

			//For special attacks...
			while (AmelithPorM == 's' || AmelithPorM == 'S') {

				//If the special attack has not been used before, the player is entitled to use it.
				if (SpecialCounter == 0) {
					cout << "Amelith activates Fallen Tear, her special ability!" << endl;
					AmelithPorM = 'A';
					SpecialCounter += 1;
					DamageDealt = Amelith.PlayerSpecialRoll() - Sorcery.EnemyDefenceRoll();
					if (DamageDealt > 0) {
						cout << "Amelith deals " << DamageDealt << " damage!" << endl;
						SorceryHealth = Sorcery.TakeDamage(SorceryHealth, DamageDealt);
					}
					else if (DamageDealt <= 0) {
						cout << "Sorcery successfully defends!" << endl;
					}

					//If Amelith defeats Sorcery, show health and revenge strike.
					if (SorceryHealth <= 0) {
						SorceryHealth = 0;
						Sleep(1000);
						cout << "\n";
						cout << "Amelith defeated Sorcery!" << endl;
						Sleep(1000);
						DamageDealt = 10;
						cout << "Steel deals " << DamageDealt << " damage as revenge!" << endl;
						AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
					}
					cout << "\n";
					Sleep(1000);
					system("pause");
					system("cls");
				}

				//If the special attack has been used before, the player is not entitled to use it.
				else if (SpecialCounter == 1) {
					while (AmelithPorM == 's' || AmelithPorM == 'S') {
						cout << "You have already used your special attack for this round. Please choose another attack[P/M]: ";
						cin >> AmelithPorM;
						cout << "\n";
					}
				}
			}

			//Autocorrecting lowercase p's and m's to upper case.
			if (AmelithPorM == 'p') {
				AmelithPorM = 'P';
			}
			else if (AmelithPorM == 'm') {
				AmelithPorM = 'M';
			}

			//If the attack is a physical or magical attack...
			if (AmelithPorM == 'P' || AmelithPorM == 'M') {

				//If the type of attack is the same as the enemy's defence, deal 0 damage.
				if (AmelithPorM == Sorcery.getEnemyPorM()) {
					cout << "Amelith fires non-elemental energy at Sorcery!" << endl;
					Sleep(1000);
					cout << "Sorcery is immune to magical attacks!" << endl;
					Sleep(1000);
					cout << "Amelith deals 0 damage!" << endl;
				}

				//If the type of attack is different from the enemy's defence, deal attack damage.
				else if (AmelithPorM != Sorcery.getEnemyPorM()) {
					cout << "Amelith slashes her sword at Sorcery!" << endl;
					DamageDealt = Amelith.PlayerAttackRoll() - Sorcery.EnemyDefenceRoll();
					if (DamageDealt > 0) {
						cout << "Amelith deals " << DamageDealt << " damage!" << endl;
						SorceryHealth = Sorcery.TakeDamage(SorceryHealth, DamageDealt);
					}
					else if (DamageDealt <= 0) {
						cout << "Sorcery successfully defends!" << endl;
					}
				}

				//If Amelith defeats Sorcery, show health and revenge strike.
				if (SorceryHealth <= 0) {
					SorceryHealth = 0;
					Sleep(1000);
					cout << "\n";
					cout << "Amelith defeated Sorcery!" << endl;
					Sleep(1000);
					DamageDealt = 10;
					cout << "Steel deals " << DamageDealt << " damage as revenge!" << endl;
					AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
				}
				cout << "\n";
				Sleep(1000);
				system("pause");
				system("cls");
			}
		}

		//If The Supremacy Sisters are still alive, run the defence part of the battle.
		if (SteelHealth > 0 && SorceryHealth > 0) {

			//Display stats.
			cout << "--Amelith--" << endl;
			cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
			cout << "--Steel--" << endl;
			cout << "Health: " << SteelHealth << "/" << Steel.getEnemyHealth() << "\n" << endl;
			cout << "--Sorcery--" << endl;
			cout << "Health: " << SorceryHealth << "/" << Sorcery.getEnemyHealth() << "\n" << endl;

			//Input defensive measures.
			Sleep(1000);
			cout << "Steel is attacking Amelith! Choose between physical or magical defence[P/M]: ";
			cin >> AmelithPorM;
			cout << "\n";

			//If the input is invalid, choose a defence again.
			while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M') {
				cout << "That is an invalid input. Please choose another defensive measure[P/M]: ";
				cin >> AmelithPorM;
				cout << "\n";
			}

			//Autocorrecting lowercase p's and m's to upper case.
			if (AmelithPorM == 'p') {
				AmelithPorM = 'P';
			}
			else if (AmelithPorM == 'm') {
				AmelithPorM = 'M';
			}

			//Describe the attack.
			cout << "Steel thrusts her blade at Amelith!" << endl;

			//If the type of defence is the same as the enemy's attack, do normal defence.
			if (AmelithPorM == Steel.getEnemyPorM()) {
				Sleep(1000);
				cout << "Amelith blocks with her sword!" << endl;
				DamageDealt = Steel.EnemyAttackRoll() - Amelith.PlayerDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith's sword protects her from some of the damage!" << endl;
					Sleep(1000);
					cout << "Amelith takes " << DamageDealt << " damage!" << endl;
					AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Steel's attack has no effect!" << endl;
					Sleep(1000);
					cout << "Amelith successfully defends!" << endl;
				}
			}

			//If the type of defence is different from the enemy's attack, ignore defence.
			else if (AmelithPorM != Steel.getEnemyPorM()) {
				Sleep(1000);
				cout << "Amelith created a magical barrier around herself!" << endl;
				Sleep(1000);
				cout << "The attack cuts right through her defence!" << endl;
				Sleep(1000);
				cout << "Amelith's defence has no effect!" << endl;
				DamageDealt = Steel.EnemyAttackRoll();
				Sleep(500);
				cout << "Amelith takes " << DamageDealt << " damage!" << endl;
				AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
			}

			//Input defensive measures.
			Sleep(1000);
			cout << "\n";
			cout << "Sorcery is attacking Amelith! Choose between physical or magical defence[P/M]: ";
			cin >> AmelithPorM;
			cout << "\n";

			//If the input is invalid, choose a defence again.
			while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M') {
				cout << "That is an invalid input. Please choose another defensive measure[P/M]: ";
				cin >> AmelithPorM;
				cout << "\n";
			}

			//Autocorrecting lowercase p's and m's to upper case.
			if (AmelithPorM == 'p') {
				AmelithPorM = 'P';
			}
			else if (AmelithPorM == 'm') {
				AmelithPorM = 'M';
			}

			//Describe the attack.
			cout << "Sorcery throws a fireball at Amelith!" << endl;

			//If the type of defence is the same as the enemy's attack, do normal defence.
			if (AmelithPorM == Sorcery.getEnemyPorM()) {
				Sleep(1000);
				cout << "Amelith created a magical barrier around herself!" << endl;
				DamageDealt = Sorcery.EnemyAttackRoll() - Amelith.PlayerDefenceRoll();
				if (DamageDealt > 0) {
					cout << "The magical barrier protects Amelith from some of the damage!" << endl;
					Sleep(1000);
					cout << "Amelith takes " << DamageDealt << " damage!" << endl;
					AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Sorcery's attack has no effect!" << endl;
					Sleep(1000);
					cout << "Amelith successfully defends!" << endl;
				}
			}

			//If the type of defence is different from the enemy's attack, ignore defence.
			else if (AmelithPorM != Sorcery.getEnemyPorM()) {
				Sleep(1000);
				cout << "Amelith blocks with her sword!" << endl;
				Sleep(1000);
				cout << "The attack cuts right through her defence!" << endl;
				Sleep(1000);
				cout << "Amelith's defence has no effect!" << endl;
				DamageDealt = Sorcery.EnemyAttackRoll();
				Sleep(500);
				cout << "Amelith takes " << DamageDealt << " damage!" << endl;
				AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
			}
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}

		//If only Steel is alive, start a new battle loop that will continue until either Amelith or Steel is defeated.
		else if (SteelHealth > 0 && SorceryHealth <= 0) {
			while (AmelithHealth > 0 && SteelHealth > 0) {

				//Display stats.
				SorceryHealth = 0;
				cout << "--Amelith--" << endl;
				cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
				cout << "--Steel--" << endl;
				cout << "Health: " << SteelHealth << "/" << Steel.getEnemyHealth() << "\n" << endl;
				cout << "--Sorcery--" << endl;
				cout << "Health: " << SorceryHealth << "/" << Sorcery.getEnemyHealth() << "\n" << endl;

				//Input an attack.
				Sleep(1000);
				cout << "You are attacking Steel! Choose between a physical, magical, or special attack[P/M/S]: ";
				cin >> AmelithPorM;
				cout << "\n";

				//If the input is invalid, choose an attack again.
				while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M' && AmelithPorM != 's' && AmelithPorM != 'S') {
					cout << "That is an invalid input. Please choose another attack[P/M/S]: ";
					cin >> AmelithPorM;
					cout << "\n";
				}

				//For special attacks...
				while (AmelithPorM == 's' || AmelithPorM == 'S') {

					//If the special attack has not been used before, the player is entitled to use it.
					if (SpecialCounter == 0) {
						cout << "Amelith activates Fallen Tear, her special ability!" << endl;
						AmelithPorM = 'A';
						SpecialCounter += 1;
						DamageDealt = Amelith.PlayerSpecialRoll() - Steel.EnemyDefenceRoll();
						if (DamageDealt > 0) {
							cout << "Amelith deals " << DamageDealt << " damage!" << endl;
							SteelHealth = Steel.TakeDamage(SteelHealth, DamageDealt);
						}
						else if (DamageDealt <= 0) {
							cout << "Steel successfully defends!" << endl;
						}

						//If Amelith defeats Steel, show health and end the fight.
						if (SteelHealth <= 0) {
							SteelHealth = 0;
							Sleep(2000);
							system("cls");
							cout << "--Amelith--" << endl;
							cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
							cout << "--Steel--" << endl;
							cout << "Health: " << SteelHealth << "/" << Steel.getEnemyHealth() << "\n" << endl;
							cout << "--Sorcery--" << endl;
							cout << "Health: " << SorceryHealth << "/" << Sorcery.getEnemyHealth() << "\n" << endl;
							Sleep(1000);
							cout << "Amelith defeated Steel!" << endl;
							Sleep(1000);
							cout << "Amelith defeated The Supremacy Sisters!" << endl;
						}
						cout << "\n";
						Sleep(1000);
						system("pause");
						system("cls");
					}

					//If the special attack has been used before, the player is not entitled to use it.
					else if (SpecialCounter == 1) {
						while (AmelithPorM == 's' || AmelithPorM == 'S') {
							cout << "You have already used your special attack for this round. Please choose another attack[P/M]: ";
							cin >> AmelithPorM;
							cout << "\n";
						}
					}
				}

				//Autocorrecting lowercase p's and m's to upper case.
				if (AmelithPorM == 'p') {
					AmelithPorM = 'P';
				}
				else if (AmelithPorM == 'm') {
					AmelithPorM = 'M';
				}

				//If the attack is a physical or magical attack...
				if (AmelithPorM == 'P' || AmelithPorM == 'M') {

					//If the type of attack is the same as the enemy's defence, deal 0 damage.
					if (AmelithPorM == Steel.getEnemyPorM()) {
						cout << "Amelith slashes her sword at Steel!" << endl;
						Sleep(1000);
						cout << "Steel is immune to physical attacks!" << endl;
						Sleep(1000);
						cout << "Amelith deals 0 damage!" << endl;
					}

					//If the type of attack is different from the enemy's defence, deal attack damage.
					else if (AmelithPorM != Steel.getEnemyPorM()) {
						cout << "Amelith fires non-elemental energy at Steel!" << endl;
						DamageDealt = Amelith.PlayerAttackRoll() - Steel.EnemyDefenceRoll();
						if (DamageDealt > 0) {
							cout << "Amelith deals " << DamageDealt << " damage!" << endl;
							SteelHealth = Steel.TakeDamage(SteelHealth, DamageDealt);
						}
						else if (DamageDealt <= 0) {
							cout << "Steel successfully defends!" << endl;
						}
					}

					//If Amelith defeats Steel, show health and end the fight.
					if (SteelHealth <= 0) {
						SteelHealth = 0;
						Sleep(2000);
						system("cls");
						cout << "--Amelith--" << endl;
						cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
						cout << "--Steel--" << endl;
						cout << "Health: " << SteelHealth << "/" << Steel.getEnemyHealth() << "\n" << endl;
						cout << "--Sorcery--" << endl;
						cout << "Health: " << SorceryHealth << "/" << Sorcery.getEnemyHealth() << "\n" << endl;
						Sleep(1000);
						cout << "Amelith defeated Steel!" << endl;
						Sleep(1000);
						cout << "Amelith defeated The Supremacy Sisters!" << endl;
					}
					cout << "\n";
					Sleep(1000);
					system("pause");
					system("cls");
				}

				//If Steel is still alive, run the defence part of the battle.
				if (SteelHealth > 0) {

					//Display stats.
					cout << "--Amelith--" << endl;
					cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
					cout << "--Steel--" << endl;
					cout << "Health: " << SteelHealth << "/" << Steel.getEnemyHealth() << "\n" << endl;
					cout << "--Sorcery--" << endl;
					cout << "Health: " << SorceryHealth << "/" << Sorcery.getEnemyHealth() << "\n" << endl;

					//Input defensive measures.
					Sleep(1000);
					cout << "Steel is attacking Amelith! Choose between physical or magical defence[P/M]: ";
					cin >> AmelithPorM;
					cout << "\n";

					//If the input is invalid, choose a defence again.
					while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M') {
						cout << "That is an invalid input. Please choose another defensive measure[P/M]: ";
						cin >> AmelithPorM;
						cout << "\n";
					}

					//Autocorrecting lowercase p's and m's to upper case.
					if (AmelithPorM == 'p') {
						AmelithPorM = 'P';
					}
					else if (AmelithPorM == 'm') {
						AmelithPorM = 'M';
					}

					//Describe the attack.
					cout << "Steel thrusts her blade at Amelith!" << endl;

					//If the type of defence is the same as the enemy's attack, do normal defence.
					if (AmelithPorM == Steel.getEnemyPorM()) {
						Sleep(1000);
						cout << "Amelith blocks with her sword!" << endl;
						DamageDealt = Steel.EnemyAttackRoll() - Amelith.PlayerDefenceRoll();
						if (DamageDealt > 0) {
							cout << "Amelith's sword protects her from some of the damage!" << endl;
							Sleep(1000);
							cout << "Amelith takes " << DamageDealt << " damage!" << endl;
							AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
						}
						else if (DamageDealt <= 0) {
							cout << "Steel's attack has no effect!" << endl;
							Sleep(1000);
							cout << "Amelith successfully defends!" << endl;
						}
					}

					//If the type of defence is different from the enemy's attack, ignore defence.
					else if (AmelithPorM != Steel.getEnemyPorM()) {
						Sleep(1000);
						cout << "Amelith created a magical barrier around herself!" << endl;
						Sleep(1000);
						cout << "The attack cuts right through her defence!" << endl;
						Sleep(1000);
						cout << "Amelith's defence has no effect!" << endl;
						DamageDealt = Steel.EnemyAttackRoll();
						Sleep(500);
						cout << "Amelith takes " << DamageDealt << " damage!" << endl;
						AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
					}
					cout << "\n";
					Sleep(1000);
					system("pause");
					system("cls");
				}
			}
		}

		//If only Sorcery is alive, start a new battle loop
		else if (SteelHealth <= 0 && SorceryHealth > 0) {
			while (AmelithHealth > 0 && SorceryHealth > 0) {

				//Display stats.
				SteelHealth = 0;
				cout << "--Amelith--" << endl;
				cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
				cout << "--Steel--" << endl;
				cout << "Health: " << SteelHealth << "/" << Steel.getEnemyHealth() << "\n" << endl;
				cout << "--Sorcery--" << endl;
				cout << "Health: " << SorceryHealth << "/" << Sorcery.getEnemyHealth() << "\n" << endl;

				//Input an attack.
				Sleep(1000);
				cout << "You are attacking Sorcery! Choose between a physical, magical, or special attack[P/M/S]: ";
				cin >> AmelithPorM;
				cout << "\n";

				//If the input is invalid, choose an attack again.
				while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M' && AmelithPorM != 's' && AmelithPorM != 'S') {
					cout << "That is an invalid input. Please choose another attack[P/M/S]: ";
					cin >> AmelithPorM;
					cout << "\n";
				}

				//For special attacks...
				while (AmelithPorM == 's' || AmelithPorM == 'S') {

					//If the special attack has not been used before, the player is entitled to use it.
					if (SpecialCounter == 0) {
						cout << "Amelith activates Fallen Tear, her special ability!" << endl;
						AmelithPorM = 'A';
						SpecialCounter += 1;
						DamageDealt = Amelith.PlayerSpecialRoll() - Sorcery.EnemyDefenceRoll();
						if (DamageDealt > 0) {
							cout << "Amelith deals " << DamageDealt << " damage!" << endl;
							SorceryHealth = Sorcery.TakeDamage(SorceryHealth, DamageDealt);
						}
						else if (DamageDealt <= 0) {
							cout << "Sorcery successfully defends!" << endl;
						}

						//If Amelith defeats Sorcery, show health and end the fight.
						if (SorceryHealth <= 0) {
							SorceryHealth = 0;
							Sleep(2000);
							system("cls");
							cout << "--Amelith--" << endl;
							cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
							cout << "--Steel--" << endl;
							cout << "Health: " << SteelHealth << "/" << Steel.getEnemyHealth() << "\n" << endl;
							cout << "--Sorcery--" << endl;
							cout << "Health: " << SorceryHealth << "/" << Sorcery.getEnemyHealth() << "\n" << endl;
							Sleep(1000);
							cout << "Amelith defeated Sorcery!" << endl;
							Sleep(1000);
							cout << "Amelith defeated The Supremacy Sisters!" << endl;
						}
						cout << "\n";
						Sleep(1000);
						system("pause");
						system("cls");
					}

					//If the special attack has been used before, the player is not entitled to use it.
					else if (SpecialCounter == 1) {
						while (AmelithPorM == 's' || AmelithPorM == 'S') {
							cout << "You have already used your special attack for this round. Please choose another attack[P/M]: ";
							cin >> AmelithPorM;
							cout << "\n";
						}
					}
				}

				//Autocorrecting lowercase p's and m's to upper case.
				if (AmelithPorM == 'p') {
					AmelithPorM = 'P';
				}
				else if (AmelithPorM == 'm') {
					AmelithPorM = 'M';
				}

				//If the attack is a physical or magical attack...
				if (AmelithPorM == 'P' || AmelithPorM == 'M') {

					//If the type of attack is the same as the enemy's defence, deal 0 damage.
					if (AmelithPorM == Sorcery.getEnemyPorM()) {
						cout << "Amelith fires non-elemental energy at Sorcery!" << endl;
						Sleep(1000);
						cout << "Sorcery is immune to magical attacks!" << endl;
						Sleep(1000);
						cout << "Amelith deals 0 damage!" << endl;
					}

					//If the type of attack is different from the enemy's defence, deal attack damage.
					else if (AmelithPorM != Sorcery.getEnemyPorM()) {
						cout << "Amelith slashes her sword at Sorcery!" << endl;
						DamageDealt = Amelith.PlayerAttackRoll() - Sorcery.EnemyDefenceRoll();
						if (DamageDealt > 0) {
							cout << "Amelith deals " << DamageDealt << " damage!" << endl;
							SorceryHealth = Sorcery.TakeDamage(SorceryHealth, DamageDealt);
						}
						else if (DamageDealt <= 0) {
							cout << "Sorcery successfully defends!" << endl;
						}
					}

					//If Amelith defeats Sorcery, show health and end the fight.
					if (SorceryHealth <= 0) {
						SorceryHealth = 0;
						Sleep(2000);
						system("cls");
						cout << "--Amelith--" << endl;
						cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
						cout << "--Steel--" << endl;
						cout << "Health: " << SteelHealth << "/" << Steel.getEnemyHealth() << "\n" << endl;
						cout << "--Sorcery--" << endl;
						cout << "Health: " << SorceryHealth << "/" << Sorcery.getEnemyHealth() << "\n" << endl;
						Sleep(1000);
						cout << "Amelith defeated Sorcery!" << endl;
						Sleep(1000);
						cout << "Amelith defeated the Supremacy Sisters!" << endl;
					}
					cout << "\n";
					Sleep(1000);
					system("pause");
					system("cls");
				}

				//If Sorcery is still alive, run the defence part of the battle.
				if (SorceryHealth > 0) {

					//Display stats.
					cout << "--Amelith--" << endl;
					cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
					cout << "--Steel--" << endl;
					cout << "Health: " << SteelHealth << "/" << Steel.getEnemyHealth() << "\n" << endl;
					cout << "--Sorcery--" << endl;
					cout << "Health: " << SorceryHealth << "/" << Sorcery.getEnemyHealth() << "\n" << endl;

					//Input defensive measures.
					Sleep(1000);
					cout << "Sorcery is attacking Amelith! Choose between physical or magical defence[P/M]: ";
					cin >> AmelithPorM;
					cout << "\n";

					//If the input is invalid, choose a defence again.
					while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M') {
						cout << "That is an invalid input. Please choose another defensive measure[P/M]: ";
						cin >> AmelithPorM;
						cout << "\n";
					}

					//Autocorrecting lowercase p's and m's to upper case.
					if (AmelithPorM == 'p') {
						AmelithPorM = 'P';
					}
					else if (AmelithPorM == 'm') {
						AmelithPorM = 'M';
					}

					//Describe the attack.
					cout << "Sorcery throws a fireball at Amelith!" << endl;

					//If the type of defence is the same as the enemy's attack, do normal defence.
					if (AmelithPorM == Sorcery.getEnemyPorM()) {
						Sleep(1000);
						cout << "Amelith created a magical barrier around herself!" << endl;
						DamageDealt = Sorcery.EnemyAttackRoll() - Amelith.PlayerDefenceRoll();
						if (DamageDealt > 0) {
							cout << "The magical barrier protects Amelith from some of the damage!" << endl;
							Sleep(1000);
							cout << "Amelith takes " << DamageDealt << " damage!" << endl;
							AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
						}
						else if (DamageDealt <= 0) {
							cout << "Sorcery's attack has no effect!" << endl;
							Sleep(1000);
							cout << "Amelith successfully defends!" << endl;
						}
					}

					//If the type of defence is different from the enemy's attack, ignore defence.
					else if (AmelithPorM != Sorcery.getEnemyPorM()) {
						Sleep(1000);
						cout << "Amelith blocks with her sword!" << endl;
						Sleep(1000);
						cout << "The attack cuts right through her defence!" << endl;
						Sleep(1000);
						cout << "Amelith's defence has no effect!" << endl;
						DamageDealt = Sorcery.EnemyAttackRoll();
						Sleep(500);
						cout << "Amelith takes " << DamageDealt << " damage!" << endl;
						AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
					}
					cout << "\n";
					Sleep(1000);
					system("pause");
					system("cls");
				}
			}
		}
		
		//If Amelith was defeated, she respawns.
		if (AmelithHealth <= 0) {
			cout << "Amelith was defeated by The Supremacy Sisters!" << endl;
			cout << "\n";
			Sleep(1000);
			cout << "Amelith: I won't let you beat me..." << endl;
			cout << "\n";
			Sleep(1000);
			cout << "Amelith revives and tries again!" << endl;
			AmelithHealth = Amelith.getPlayerHealth();
			SteelHealth = Steel.getEnemyHealth();
			SorceryHealth = Sorcery.getEnemyHealth();
			SpecialCounter = 0;
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}
	}

	//Delete The Supremacy Sisters - Steel & Sorcery.
	Steel.~Enemy();
	Sorcery.~Enemy();

	//Reset SpecialCounter
	SpecialCounter = 0;

	//Level up Amelith.
	cout << "----Level up!----\n" << endl;
	Sleep(1000);
	Amelith.setPlayerHealth(40);
	cout << "Amelith's health is now 40!" << endl;
	Sleep(1000);
	Amelith.setPlayerAttack(8);
	cout << "Amelith's attack has increased!" << endl;
	Sleep(1000);
	Amelith.setPlayerDefence(8);
	cout << "Amelith's defence has increased!" << endl;
	Sleep(1000);
	Amelith.setPlayerSpecial(7);
	cout << "Amelith's special ability has increased in power!" << endl;
	cout << "\n";
	Sleep(1000);
	system("pause");
	system("cls");

	//Reset Amelith's health back to full.
	AmelithHealth = Amelith.getPlayerHealth();
	
	//Create Endon.
	Enemy Endon("Endon", 40, 6, 7, 'P');
	int EndonHealth = Endon.getEnemyHealth();
	int EndonRegenCounter = 0;

	//Announce battle with Endon.
	cout << "Battle Begins! Opponent: Endon\n" << endl;

	//Begin battle with Endon.
	while (AmelithHealth > 0 && EndonHealth > 0) {

		//Start Endon Regen Counter.
		EndonRegenCounter++;

		//Display stats.
		cout << "--Amelith--" << endl;
		cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
		cout << "--Endon--" << endl;
		cout << "Health: " << EndonHealth << "/" << Endon.getEnemyHealth() << "\n" << endl;

		//Input an attack.
		Sleep(1000);
		cout << "You are attacking Endon! Choose between a physical, magical, or special attack[P/M/S]: ";
		cin >> AmelithPorM;
		cout << "\n";

		//If the input is invalid, choose an attack again.
		while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M' && AmelithPorM != 's' && AmelithPorM != 'S') {
			cout << "That is an invalid input. Please choose another attack[P/M/S]: ";
			cin >> AmelithPorM;
			cout << "\n";
		}

		//For special attacks...
		while (AmelithPorM == 's' || AmelithPorM == 'S') {

			//If the special attack has not been used before, the player is entitled to use it.
			if (SpecialCounter == 0) {
				cout << "Amelith activates Fallen Tear, her special ability!" << endl;
				AmelithPorM = 'A';
				SpecialCounter += 1;
				DamageDealt = Amelith.PlayerSpecialRoll() - Endon.EnemyDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith deals " << DamageDealt << " damage!" << endl;
					EndonHealth = Endon.TakeDamage(EndonHealth, DamageDealt);;
				}
				else if (DamageDealt <= 0) {
					cout << "Endon successfully defends!" << endl;
				}

				//If Amelith defeats Endon, show health and end the fight.
				if (EndonHealth <= 0) {
					EndonHealth = 0;
					Sleep(2000);
					system("cls");
					cout << "--Amelith--" << endl;
					cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
					cout << "--Endon--" << endl;
					cout << "Health: " << EndonHealth << "/" << Endon.getEnemyHealth() << "\n" << endl;
					Sleep(1000);
					cout << "Amelith defeated Endon!" << endl;
				}
				cout << "\n";
				Sleep(1000);
				system("pause");
				system("cls");
			}

			//If the special attack has been used before, the player is not entitled to use it.
			else if (SpecialCounter == 1) {
				while (AmelithPorM == 's' || AmelithPorM == 'S') {
					cout << "You have already used your special attack for this round. Please choose another attack[P/M]: ";
					cin >> AmelithPorM;
					cout << "\n";
				}
			}
		}

		//Autocorrecting lowercase p's and m's to upper case.
		if (AmelithPorM == 'p') {
			AmelithPorM = 'P';
		}
		else if (AmelithPorM == 'm') {
			AmelithPorM = 'M';
		}

		//If the attack is a physical or magical attack...
		if (AmelithPorM == 'P' || AmelithPorM == 'M') {

			//If the type of attack is the same as the enemy's defence, deal 0 damage.
			if (AmelithPorM == Endon.getEnemyPorM()) {
				cout << "Amelith slashes her sword at Endon!" << endl;
				Sleep(1000);
				cout << "Endon is immune to physical attacks!" << endl;
				Sleep(1000);
				cout << "Amelith deals 0 damage!" << endl;
			}

			//If the type of attack is different from the enemy's defence, deal attack damage.
			else if (AmelithPorM != Endon.getEnemyPorM()) {
				cout << "Amelith fires non-elemental energy at Endon!" << endl;
				DamageDealt = Amelith.PlayerAttackRoll() - Endon.EnemyDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith deals " << DamageDealt << " damage!" << endl;
					EndonHealth = Endon.TakeDamage(EndonHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Endon successfully defends!" << endl;
				}
			}

			//If Amelith defeats Endon, show health and end the fight.
			if (EndonHealth <= 0) {
				EndonHealth = 0;
				Sleep(2000);
				system("cls");
				cout << "--Amelith--" << endl;
				cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
				cout << "--Endon--" << endl;
				cout << "Health: " << EndonHealth << "/" << Endon.getEnemyHealth() << "\n" << endl;
				Sleep(1000);
				cout << "Amelith defeated Endon!" << endl;
			}
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}

		//If Endon is still alive, run the defence part of the battle.
		if (EndonHealth > 0) {

			//Display stats.
			cout << "--Amelith--" << endl;
			cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
			cout << "--Endon--" << endl;
			cout << "Health: " << EndonHealth << "/" << Endon.getEnemyHealth() << "\n" << endl;

			//Input defensive measures.
			Sleep(1000);
			cout << "Endon is attacking Amelith! Choose between physical or magical defence[P/M]: ";
			cin >> AmelithPorM;
			cout << "\n";

			//If the input is invalid, choose a defence again.
			while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M') {
				cout << "That is an invalid input. Please choose another defensive measure[P/M]: ";
				cin >> AmelithPorM;
				cout << "\n";
			}

			//Autocorrecting lowercase p's and m's to upper case.
			if (AmelithPorM == 'p') {
				AmelithPorM = 'P';
			}
			else if (AmelithPorM == 'm') {
				AmelithPorM = 'M';
			}

			//Describe the attack.
			cout << "Endon drives his sword at Amelith!" << endl;

			//If the type of defence is the same as the enemy's attack, do normal defence.
			if (AmelithPorM == Endon.getEnemyPorM()) {
				Sleep(1000);
				cout << "Amelith blocks with her sword!" << endl;
				DamageDealt = Endon.EnemyAttackRoll() - Amelith.PlayerDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith's sword protects her from some of the damage!" << endl;
					Sleep(1000);
					cout << "Amelith takes " << DamageDealt << " damage!" << endl;
					AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Endon's attack has no effect!" << endl;
					Sleep(1000);
					cout << "Amelith successfully defends!" << endl;
				}
			}

			//If the type of defence is different from the enemy's attack, ignore defence.
			else if (AmelithPorM != Endon.getEnemyPorM()) {
				Sleep(1000);
				cout << "Amelith created a magical barrier around herself!" << endl;
				Sleep(1000);
				cout << "The attack cuts right through her defence!" << endl;
				Sleep(1000);
				cout << "Amelith's defence has no effect!" << endl;
				DamageDealt = Endon.EnemyAttackRoll();
				Sleep(500);
				cout << "Amelith takes " << DamageDealt << " damage!" << endl;
				AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
			}

			//After five turns, Endon siphons health from Amelith.
			if (EndonRegenCounter == 5 && EndonHealth > 0) {
				EndonRegenCounter = 0;
				Sleep(1500);
				cout << "\n";
				cout << "Endon activates Drain, his power ability!" << endl;
				Sleep(1000);
				cout << "Endon siphons 2 health from Amelith!" << endl;
				DamageDealt = 2;
				AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
				EndonHealth = Endon.EndonSiphon(EndonHealth);

				//If Endon's health is greater than the max, set health to max.
				if (EndonHealth > Endon.getEnemyHealth()) {
					EndonHealth = Endon.getEnemyHealth();
				}
			}

			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}

		//If Amelith was defeated, she respawns.
		if (AmelithHealth <= 0) {
			cout << "Amelith was defeated by Endon!" << endl;
			cout << "\n";
			Sleep(1000);
			cout << "Amelith: I won't let you beat me..." << endl;
			cout << "\n";
			Sleep(1000);
			cout << "Amelith revives and tries again!" << endl;
			AmelithHealth = Amelith.getPlayerHealth();
			EndonHealth = Endon.getEnemyHealth();
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}
	}

	//Delete Endon.
	Endon.~Enemy();

	//Reset SpecialCounter
	SpecialCounter = 0;

	//Level up Amelith.
	cout << "----Level up!----\n" << endl;
	Sleep(1000);
	Amelith.setPlayerHealth(50);
	cout << "Amelith's health is now 50!" << endl;
	Sleep(1000);
	Amelith.setPlayerAttack(10);
	cout << "Amelith's attack has increased!" << endl;
	Sleep(1000);
	Amelith.setPlayerDefence(10);
	cout << "Amelith's defence has increased!" << endl;
	Sleep(1000);
	Amelith.setPlayerSpecial(10);
	cout << "Amelith's special ability has increased in power!" << endl;
	cout << "\n";
	Sleep(1000);
	system("pause");
	system("cls");

	//Reset Amelith's health back to full.
	AmelithHealth = Amelith.getPlayerHealth();

	//Create Judician.
	Boss Judician("Judician", 50, 8, 8, 'P', 5);
	int JudicianHealth = Judician.getEnemyHealth();
	int JudicianSpecialCounter = 0;
	int JudicianShiftCounter = 0;
	char JudicianSpecialUsed = 'N';

	//Introduction to Boss fight.
	Sleep(1000);
	cout << "Amelith has angered the Coliseum Overlord, Judician!" << endl;
	Sleep(3000);
	cout << "Judician rises from his throne and lands in the arena!" << endl;
	cout << "\n";
	Sleep(3000);
	cout << "Judician: Your skill has won you the crowd, but you will lose this battle..." << endl;
	cout << "\n";
	Sleep(3000);
	system("pause");
	system("cls");

	//Announce battle with Judician.
	cout << "Boss Battle Begins! Opponent: Judician\n" << endl;

	//Begin battle with Judician.
	while (AmelithHealth > 0 && JudicianHealth > 0) {

		//Start counter that will shift Judician's focus every three turns.
		JudicianShiftCounter++;

		//Set Judician's special such that it hasn't been used this round.
		JudicianSpecialUsed = 'N';

		//Display stats.
		cout << "--Amelith--" << endl;
		cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
		cout << "--Judician--" << endl;
		cout << "Health: " << JudicianHealth << "/" << Judician.getEnemyHealth() << "\n" << endl;

		//Input an attack.
		Sleep(1000);
		cout << "You are attacking Judician! Choose between a physical, magical, or special attack[P/M/S]: ";
		cin >> AmelithPorM;
		cout << "\n";

		//If the input is invalid, choose an attack again.
		while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M' && AmelithPorM != 's' && AmelithPorM != 'S') {
			cout << "That is an invalid input. Please choose another attack[P/M/S]: ";
			cin >> AmelithPorM;
			cout << "\n";
		}

		//For special attacks...
		while (AmelithPorM == 's' || AmelithPorM == 'S') {

			//If the special attack has not been used before, the player is entitled to use it.
			if (SpecialCounter == 0) {
				cout << "Amelith activates Fallen Tear, her special ability!" << endl;
				AmelithPorM = 'A';
				SpecialCounter += 1;
				DamageDealt = Amelith.PlayerSpecialRoll() - Judician.EnemyDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith deals " << DamageDealt << " damage!" << endl;
					JudicianHealth = Judician.TakeDamage(JudicianHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Judician successfully defends!" << endl;
				}

				//If Amelith defeats Judician, show health and end the fight.
				if (JudicianHealth <= 0) {
					JudicianHealth = 0;
					Sleep(3000);
					cout << "\n";
					cout << "Judician: So...this is how...it ends..." << endl;
					Sleep(3000);
					cout << "\n";
					system("pause");
					system("cls");
					cout << "--Amelith--" << endl;
					cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
					cout << "--Judician--" << endl;
					cout << "Health: " << JudicianHealth << "/" << Judician.getEnemyHealth() << "\n" << endl;
					Sleep(1000);
					cout << "Amelith defeated Judician!" << endl;
				}
				cout << "\n";
				Sleep(1000);
				system("pause");
				system("cls");
			}

			//If the special attack has been used before, the player is not entitled to use it.
			else if (SpecialCounter == 1) {
				while (AmelithPorM == 's' || AmelithPorM == 'S') {
					cout << "You have already used your special attack for this round. Please choose another attack[P/M]: ";
					cin >> AmelithPorM;
				}
			}
		}

		//Autocorrecting lowercase p's and m's to upper case.
		if (AmelithPorM == 'p') {
			AmelithPorM = 'P';
		}
		else if (AmelithPorM == 'm') {
			AmelithPorM = 'M';
		}

		//If the attack is a physical or magical attack...
		if (AmelithPorM == 'P' || AmelithPorM == 'M') {

			//If the type of attack is the same as the enemy's defence, deal 0 damage.
			if (AmelithPorM == Judician.getEnemyPorM()) {
				if (AmelithPorM == 'P') {
					cout << "Amelith slashes her sword at Judician!" << endl;
					Sleep(1000);
					cout << "Judician is immune to physical attacks!" << endl;
				}
				else if (AmelithPorM == 'M') {
					cout << "Amelith fires non-elemental energy at Judician!" << endl;
					Sleep(1000);
					cout << "Judician is immune to magical attacks!" << endl;
				}
				Sleep(1000);
				cout << "Amelith deals 0 damage!" << endl;
			}

			//If the type of attack is different from the enemy's defence, deal attack damage.
			else if (AmelithPorM != Judician.getEnemyPorM()) {
				if (AmelithPorM == 'P') {
					cout << "Amelith slashes her sword at Judician!" << endl;
				}
				else if (AmelithPorM == 'M') {
					cout << "Amelith fires non-elemental energy at Judician!" << endl;
				}
				DamageDealt = Amelith.PlayerAttackRoll() - Judician.EnemyDefenceRoll();
				if (DamageDealt > 0) {
					cout << "Amelith deals " << DamageDealt << " damage!" << endl;
					JudicianHealth = Judician.TakeDamage(JudicianHealth, DamageDealt);
				}
				else if (DamageDealt <= 0) {
					cout << "Judician successfully defends!" << endl;
				}
			}

			//If Amelith defeats Judician, show health and end the fight.
			if (JudicianHealth <= 0) {
				JudicianHealth = 0;
				Sleep(3000);
				cout << "\n";
				cout << "Judician: So...this is how...it ends..." << endl;
				Sleep(3000);
				cout << "\n";
				system("pause");
				system("cls");
				cout << "--Amelith--" << endl;
				cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
				cout << "--Judician--" << endl;
				cout << "Health: " << JudicianHealth << "/" << Judician.getEnemyHealth() << "\n" << endl;
				Sleep(1000);
				cout << "Amelith defeated Judician!" << endl;
			}
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}

		//If Judician is still alive, run the defence part of the battle.
		if (JudicianHealth > 0) {

			//Display stats.
			cout << "--Amelith--" << endl;
			cout << "Health: " << AmelithHealth << "/" << Amelith.getPlayerHealth() << "\n" << endl;
			cout << "--Judician--" << endl;
			cout << "Health: " << JudicianHealth << "/" << Judician.getEnemyHealth() << "\n" << endl;

			//Create a function that will determine if Judician's special activates. 
			if (JudicianSpecialCounter == 0) {
				int JudicianSpecialChance = 1 + rand() % 10;
				if (JudicianSpecialChance == 10) {
					JudicianSpecialCounter = 1;
					JudicianSpecialUsed = 'Y';
					cout << "Judician activates Judgement, his special ability!" << endl;
					DamageDealt = Judician.BossSpecialRoll() - Amelith.PlayerDefenceRoll();
					if (DamageDealt > 0) {
						cout << "Amelith takes " << DamageDealt << " damage!" << endl;
						AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
					}
					else if (DamageDealt <= 0) {
						cout << "Judgement has no effect!" << endl;
						Sleep(1000);
						cout << "Amelith successfully defends!" << endl;
					}
				}
			}

			//Input defensive measures (unless Judician already used his special abiity for this round).
			if (JudicianSpecialUsed == 'N') {
				Sleep(1000);
				cout << "Judician is attacking Amelith! Choose between physical or magical defence[P/M]: ";
				cin >> AmelithPorM;
				cout << "\n";

				//If the input is invalid, choose a defence again.
				while (AmelithPorM != 'p' && AmelithPorM != 'P' && AmelithPorM != 'm' && AmelithPorM != 'M') {
					cout << "That is an invalid input. Please choose another defensive measure[P/M]: ";
					cin >> AmelithPorM;
					cout << "\n";
				}

				//Autocorrecting lowercase p's and m's to upper case.
				if (AmelithPorM == 'p') {
					AmelithPorM = 'P';
				}
				else if (AmelithPorM == 'm') {
					AmelithPorM = 'M';
				}

				//Describe the attack.
				if (Judician.getEnemyPorM() == 'P') {
					cout << "Judician crashes his giant blade down upon Amelith!" << endl;
				}
				else if (Judician.getEnemyPorM() == 'M') {
					cout << "Judician forms a hailstorm of non-elemental energy to rain on Amelith!" << endl;
				}

				//If the type of defence is the same as the enemy's attack, do normal defence.
				if (AmelithPorM == Judician.getEnemyPorM()) {
					Sleep(1000);
					if (AmelithPorM == 'P') {
						cout << "Amelith blocks with her sword!" << endl;
						DamageDealt = Judician.EnemyAttackRoll() - Amelith.PlayerDefenceRoll();
						if (DamageDealt > 0) {
							cout << "Amelith's sword protects her from some of the damage!" << endl;
							Sleep(1000);
							cout << "Amelith takes " << DamageDealt << " damage!" << endl;
							AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
						}
						else if (DamageDealt <= 0) {
							cout << "Judician's attack has no effect!" << endl;
							Sleep(1000);
							cout << "Amelith successfully defends!" << endl;
						}
					}
					else if (AmelithPorM == 'M') {
						cout << "Amelith created a magical barrier around herself!" << endl;
						DamageDealt = Judician.EnemyAttackRoll() - Amelith.PlayerDefenceRoll();
						if (DamageDealt > 0) {
							cout << "The magical barrier protects Amelith from some of the damage!" << endl;
							Sleep(1000);
							cout << "Amelith takes " << DamageDealt << " damage!" << endl;
							AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
						}
						else if (DamageDealt <= 0) {
							cout << "Judician's attack has no effect!" << endl;
							Sleep(1000);
							cout << "Amelith successfully defends!" << endl;
						}
					}
				}

				//If the type of defence is different from the enemy's attack, ignore defence.
				else if (AmelithPorM != Judician.getEnemyPorM()) {
					if (AmelithPorM == 'P') {
						Sleep(1000);
						cout << "Amelith blocks with her sword!" << endl;
					}
					else if (AmelithPorM == 'M') {
						Sleep(1000);
						cout << "Amelith created a magical barrier around herself!" << endl;
					}
					Sleep(1000);
					cout << "The attack cuts right through her defence!" << endl;
					Sleep(1000);
					cout << "Amelith's defence has no effect!" << endl;
					DamageDealt = Judician.EnemyAttackRoll();
					Sleep(500);
					cout << "Amelith takes " << DamageDealt << " damage!" << endl;
					AmelithHealth = Amelith.TakeDamage(AmelithHealth, DamageDealt);
				}
			}

			//If two turns have passed, shift Judician's focus.
			if (JudicianShiftCounter == 2) {
				JudicianShiftCounter = 0;
				Sleep(1000);
				cout << "\n";
				Judician.BossFocusShift();
			}

			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}

		//If Amelith was defeated, she respawns.
		if (AmelithHealth <= 0) {
			cout << "Amelith was defeated by Judician!" << endl;
			cout << "\n";
			Sleep(1000);
			cout << "Amelith: I won't let you beat me..." << endl;
			cout << "\n";
			Sleep(1000);
			cout << "Amelith revives and tries again!" << endl;
			AmelithHealth = Amelith.getPlayerHealth();
			JudicianHealth = Judician.getEnemyHealth();
			SpecialCounter = 0;
			cout << "\n";
			Sleep(1000);
			system("pause");
			system("cls");
		}
	}

	//Delete Judician.
	Judician.~Boss();

	//End statement.
	Sleep(1000);
	cout << "You are the champion of the arena!" << endl;
	Sleep(1000);
	cout << "\n";
	cout << "The End. Thanks for playing!\n" << endl;
	Sleep(1000);
	system("pause");
}