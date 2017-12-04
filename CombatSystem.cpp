//============================================================================
// Name        : CombatSystem.cpp
// Author      : Aaron Gaskin
// Description : Combat System method, will take in a character and monster object.
//				 Then it will take in player choice as the character fights the monster.
//============================================================================

#include "CombatSystem.h"

/******************
 * Name: intCheck
 * Needs: string
 * Outputs: int
 * Purpose: checks a string of user input to verify that it is an integer
 ******************/
int intCheck(string userChoice)
{
	//initializing variables for later use
	bool check = true;
	int x = 0;

	//loop that checks the users choice is an int
	do
	{
		//parsing input string to determine if it's an int
		//copied from my pa1.cpp assignment
		//obtained from stack Overflow "Check if the input is a number or string in C++"
		stringstream userParse(userChoice);

		//checking if the parse can be put into an int
		if(!(userParse >> x).fail())
		{
			userParse >> x;			//passing parse value to x
			check = false;
		}
		else			//if parse test fails, asks user for an integer
		{
			cout << "Invalid input!" << "\n" << "Please enter a valid integer: ";
			cin >> userChoice;
		}
	}while(check);

	//return valid integer
	return x;
}

//combat for fighting normal monsters
bool combatSystem(Player* player, monster* mon)
{
	//set up values for player
	string choice = "";
	int intChoice = 0;
	int charHealth = player->getHealth();
	int charMana = player->getCurMana();
	int charDamage = player->getDmg();
	int charDefense = player->getDef();
	int skillAttack = 0;

	//set up values for monster
	int monHealth = mon->getHP();
	int monDamage = mon->getDAMAGE();
	int monDefense = mon->getDEFENSE();
	string monName = mon->getMONSTER();

	//setting damage values
	int charAttack = charDamage - monDefense;
	if(charAttack <= 0)		//ensuring the player deals at least 1 damage
	{
		charAttack = 1;
	}
	int monAttack = monDamage - charDefense;
	if(monAttack <= 0)		//ensuring monster deals at least 1 damage
	{
		monAttack = 1;
	}
	while(true)
		{
			//outputs info to user
			cout << "You have " << charHealth << " HP, " << charDamage << " attack, and " << charMana << " mana." <<endl;

			//output how much health the monster has
			cout << "The vile " << monName << " still has " << monHealth << " HP left!" << endl;

			//ask for user's choice
			cout << "What would you like to do?\n";
			cout << "1.) Basic Attack\n2.) Use Skill\n3.) Take a breather" << endl;
			cin >> choice;
			//verify that it is an integer
			intChoice = intCheck(choice);

			//perform action based on user choice
			switch(intChoice)
			{
				case 1: cout << "You strike the " << monName << ". It takes " << charAttack << " damage." << endl;
						monHealth = monHealth - charAttack;
						//check if monster is dead
						if(monHealth <= 0)
						{
							return true;
						}
						//if not dead then monster hits player
						cout << "The " << monName << " fights back! Take " << monAttack << " damage." << endl;
						player->setHealth(charHealth - monAttack);
						charHealth = player->getHealth();
						break;
				//getting which skill the user wants and checking if they can wield it
				case 2:	cout << "Which skill would you like to use?\n Skill [1] for 2 mana, Skill [2] for 4 mana, Skill [3] for 6 mana, or Skill [4] for 8 mana?" << endl;
						cout << "Warning! You must reach the corresponding floor to use said skill. Ex. Floor 2 to use 1st skill." << endl;
						cin >> choice;
						intChoice = intCheck(choice);

						//switch for skills
						switch(intChoice)
						{
							case 1: if((skillAttack = player->skill1()) != -1)
									{
										monHealth = monHealth - skillAttack;
										//check if monster is dead
										if(monHealth <= 0)
										{

											return true;
										}
										//if not dead then monster hits player
										cout << "The " << monName << " fights back! Take " << monAttack << " damage." << endl;
										player->setHealth(charHealth - monAttack);
										charHealth = player->getHealth();
										charMana = player->getCurMana();
									}
									else {cout << "Not enough mana/ not high enough level!" << endl;}
									break;
							case 2: if((skillAttack = player->skill2()) != -1)
									{
										monHealth = monHealth - skillAttack;
										//check if monster is dead
										if(monHealth <= 0)
										{
											return true;
										}
										//if not dead then monster hits player
										cout << "The " << monName << " fights back! Take " << monAttack << " damage." << endl;
										player->setHealth(charHealth - monAttack);
										charHealth = player->getHealth();
										charMana = player->getCurMana();
									}
									else {cout << "Not enough mana/ not high enough level!" << endl;}
									break;
							case 3: if((skillAttack = player->skill3()) != -1)
									{
										monHealth = monHealth - skillAttack;
										//check if monster is dead
										if(monHealth <= 0)
										{
											return true;
										}
										//if not dead then monster hits player
										cout << "The " << monName << " fights back! Take " << monAttack << " damage." << endl;
										player->setHealth(charHealth - monAttack);
										charHealth = player->getHealth();
										charMana = player->getCurMana();
									}
									else {cout << "Not enough mana/ not high enough level!" << endl;}
									break;
							case 4: if((skillAttack = player->skill4()) != -1)
									{
										monHealth = monHealth - skillAttack;
										//check if monster is dead
										if(monHealth <= 0)
										{
											return true;
										}
										//if not dead then monster hits player
										cout << "The " << monName << " fights back! Take " << monAttack << " damage." << endl;
										player->setHealth(charHealth - monAttack);
										charHealth = player->getHealth();
										charMana = player->getCurMana();
									}
									else {cout << "Not enough mana/ not high enough level!" << endl;}
									break;
							default: cout << "Invalid skill choice!" << endl;
						}
						break;
				case 3:
						cout << "You retreat a short distance from the beast to rest your tired limbs." << endl; //healing player HP
						charHealth = charHealth + player->getLvl();
						player->setHealth(charHealth);
						//restoring some player mana
						charMana = player->getCurMana() + player->getLvl();
						player->setCurMana(charMana);
						cout << "Restored " << player->getLvl() << " health and mana." << endl;
						cout << "Feeling slightly better you charge back into the fray only to get immediatley hit in your haste!" << endl;
						player->setHealth(charHealth - monAttack);
						charHealth = player->getHealth();
						break;
				default: cout << "Invalid choice!" << endl;
			}

		//Check if the player is dead
		if(charHealth <= 0)
		{
			return false;
		} else {

		}

	}
}

//combat for fighting boss
bool combatSystem(Player* player, boss* mon)
{
	//set up values for player
	string choice = "";
	int intChoice = 0;
	int charHealth = player->getHealth();
	int charMana = player->getCurMana();
	int charDamage = player->getDmg();
	int charDefense = player->getDef();
	int skillAttack = 0;

	//set up values for monster
	int monHealth = mon->getHPBoss();
	int monDamage = mon->getDAMAGEBoss();
	int monDefense = mon->getDEFENSEBoss();
	string monName = mon->getBOSS();

	//setting damage values
	int charAttack = charDamage - monDefense;
	if(charAttack <= 0)		//ensuring the player deals at least 1 damage
	{
		charAttack = 1;
	}
	int monAttack = monDamage - charDefense;
	if(monAttack <= 0)		//ensuring monster deals at least 1 damage
	{
		monAttack = 1;
	}
	while(true)
			{
			//outputs info to user
			cout << "You have " << charHealth << " HP, " << charDamage << " attack, and " << charMana << " mana." <<endl;

			//output how much health the monster has
			cout << "The vile " << monName << " still has " << monHealth << " HP left!" << endl;

			//ask for user's choice
			cout << "What would you like to do?\n";
			cout << "1.) Basic Attack\n2.) Use Skill\n3.) Take a breather" << endl;
			cin >> choice;
			//verify that it is an integer
			intChoice = intCheck(choice);

			//perform action based on user choice
			switch(intChoice)
			{
				case 1: cout << "You strike the " << monName << ". It takes " << charAttack << " damage." << endl;
						monHealth = monHealth - charAttack;
						//check if monster is dead
						if(monHealth <= 0)
						{
							return true;
						}
						//if not dead then monster hits player
						cout << "The " << monName << " fights back! Take " << monAttack << " damage." << endl;
						player->setHealth(charHealth - monAttack);
						charHealth = player->getHealth();
						break;
				//getting which skill the user wants and checking if they can wield it
				case 2:	cout << "Which skill would you like to use?\n Skill [1] for 2 mana, Skill [2] for 4 mana, Skill [3] for 6 mana, or Skill [4] for 8 mana?" << endl;
						cout << "Warning! You must reach the corresponding floor to use said skill. Ex. Floor 2 to use 2nd skill." << endl;
						cin >> choice;
						intChoice = intCheck(choice);

						//switch for skills
						switch(intChoice)
						{
							case 1: if((skillAttack = player->skill1()) != -1)
									{
										monHealth = monHealth - skillAttack;
										//check if monster is dead
										if(monHealth <= 0)
										{
										return true;
										}
										//if not dead then monster hits player
										cout << "The " << monName << " fights back! Take " << monAttack << " damage." << endl;
										player->setHealth(charHealth - monAttack);
										charHealth = player->getHealth();
										charMana = player->getCurMana();
									}
									else {cout << "Not enough mana/ not high enough level!" << endl;}
									break;
							case 2: if((skillAttack = player->skill2()) != -1)
									{
										monHealth = monHealth - skillAttack;
										//check if monster is dead
										if(monHealth <= 0)
										{
											return true;
										}
										//if not dead then monster hits player
										cout << "The " << monName << " fights back! Take " << monAttack << " damage." << endl;
										player->setHealth(charHealth - monAttack);
										charHealth = player->getHealth();
										charMana = player->getCurMana();
									}
									else {cout << "Not enough mana/ not high enough level!" << endl;}
									break;
							case 3: if((skillAttack = player->skill3()) != -1)
									{
										monHealth = monHealth - skillAttack;
										//check if monster is dead
										if(monHealth <= 0)
										{
											return true;
										}
										//if not dead then monster hits player
										cout << "The " << monName << " fights back! Take " << monAttack << " damage." << endl;
										player->setHealth(charHealth - monAttack);
										charHealth = player->getHealth();
										charMana = player->getCurMana();
									}
									else {cout << "Not enough mana/ not high enough level!" << endl;}
									break;
							case 4: if((skillAttack = player->skill4()) != -1)
									{
										monHealth = monHealth - skillAttack;
										//check if monster is dead
										if(monHealth <= 0)
										{
											return true;
										}
										//if not dead then monster hits player
										cout << "The " << monName << " fights back! Take " << monAttack << " damage." << endl;
										player->setHealth(charHealth - monAttack);
										charHealth = player->getHealth();
										charMana = player->getCurMana();
									}
									else {cout << "Not enough mana/ not high enough level!" << endl;}
									break;
							default: cout << "Invalid skill choice!" << endl;
						}
						break;
				case 3:
						cout << "You retreat a short distance from the beast to rest your tired limbs." << endl; //healing player HP
						charHealth = charHealth + player->getLvl();
						player->setHealth(charHealth);
						//restoring some player mana
						charMana = player->getCurMana() + player->getLvl();
						player->setCurMana(charMana);
						cout << "Restored " << player->getLvl() << " health and mana." << endl;
						cout << "Feeling slightly better you charge back into the fray only to get immediatley hit in your haste!" << endl;
						player->setHealth(charHealth - monAttack);
						charHealth = player->getHealth();
						break;
				default: cout << "Invalid choice!" << endl;
			}

		//Check if the player is dead
		if(charHealth <= 0)
		{
			return false;
		}

	}
}

//int main()
//{
//	Player* player;
//	player = new Archer(10,5,10,"");
//	monster* mon = new monster(5);
//	combatSystem(player, mon);

//	return 0;
//}
