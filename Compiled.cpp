/*
 * testing.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: Alex Jasper
 */

#include "floor.h"
#include "combatSystem.h"
#include "monsterGeneration.h"
#include "characterCreation.h"
#include "userInterface.h"
#include <thread>
#include <Windows.h>
#include <iostream>
#include "FloorDesign.h"
#include "CombatSystem.h"
#include "MonsterGeneration.h"
#include "CharacterCreation.h"
#include "UserInterface.h"

int monsterCount = 0;
int lootCount = 0;
int goldCount = 0;
vector<string> achievementRecorder;
int timeTaken1 = 0;
int timeTaken2 = 0;

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

//Will also take the character as a parameter
Floor::Floor(int level, Player* hero) {
	this->level = level;
	this->hero = hero;
	//cout << "Floor constructor" << endl;
	//cout << hero->getHealth() << endl;


}

//bool Floor::run() {
//	bool fail = false;
//	int outcome = 0;
//	//int loot = 0;
//	if(this->runShop()) {
//		if(level < 5) {
//			for(int i=0; i<level*2; i++) {
//				outcome = rand()%10;
//				if(outcome >= 0 && outcome < 5) {
//					if(!this->runMonster()) {
//						fail = true;
//						return false;
//						break;
//					}
//
//				} else if(outcome >= 5 && outcome < 9) {
//					this->runLoot();
//				} else if(outcome == 9) {
//					this->runNothing();
//				}
//			}
//			if(!fail) {
//				this->runStairs();
//			}
//		} else if(level == 5) {
//			if(!this->runBoss()) {
//				return false;
//			}
//
//		}
//	} else {
//		return false;
//	}
//
//	return true;
//
//}

bool Floor::run() {

	//cout << hero->getHealth() << endl;

	//cout << "In health check" << endl;
	//cout << hero->getHealth() << endl;
	if(hero->getHealth() <= 0) {

		return false;
	}
	bool fail = true;
	int outcome = 0;

	time_t timer;
	//int loot = 0;
	//Run shop and check if the method runs

	//If not the boss level

	if(level < 5) {
		//Run through each room
		for(int i=0; i<level*2; i++) {
			if(hero->getHealth() <= 0) {
				return false;
			}

			if(!fail) {
				break;
			}
			//Randomly generate room type
			time(&timer);
			srand(timer);
			outcome = rand()%10;

			if(outcome >= 0 && outcome < 5 && fail) {
				//Call monster method and check if they survived
				fail = this->runMonster();
				if(!fail) {
					//fail = true;
					return false;
					//break;
				} else {

				}

				//Run loot method
			} else if(outcome >= 5 && outcome < 9 && fail) {
				this->runLoot();
				//Run nothing method
			} else if(outcome == 9 && fail) {
				this->runNothing();
			}
		}
		//If they clear the floor, continue
		if(fail) {
			this->runStairs();
		}
		//If it is the boss level, run the boss method

	}
	if(this->level == 5) {
		if(!this->runBoss()) {
			return false;
		}

	}
		//Return true if they cleared the floor, false if they failed
	if(!fail) {
		return false;
	} else {
		return true;
	}
	return true;

}

//Unused
bool Floor::runShop() {
	//call store class
	return true;
}

//Run end floor text and level up/heal hero
void Floor::runStairs() {
	cout << "Congratulations! You have completed floor " << this->level
			<< "! Beware, even greater dangers lie ahead." << endl;
	if(this->level == 4) {
		cout << "You'd best prepare yourself, for your greatest challenge lies below" << endl;
	}

	hero->lvlUp(this->level);
	hero->setHealth(hero->getMaxHP());
	hero->setCurMana(hero->getMaxMana());

	char choice;
	do {
		cout << "Press c to continue." << endl;
		cin >> choice;
	} while(choice != 'c');

	if(this->level == 4) {
		char partc;


		if(hero->getName().compare("Olaf") == 0) {
			cout << "You have called upon the ancient weapon of house Olaf, the holy blade of Fuck You" << endl;
			hero->setDmg(1569325055);
		}

		achievementRecorder.push_back("Cleared floor 4!");

	}
}

//Run monster room event
bool Floor::runMonster() {
	//Create monster
	monster* monst = new monster(this->level);

//	monst->setHP(this->level);
//	monst->setDAMAGE(this->level);
//	monst->setDEFENSE(this->level);
//	monst->setLOOT();

	cout << "A " << monst->getMONSTER()
			<< " has appeared! It moves to attack you.  Defend yourself!" << endl;


	if(combatSystem(this->hero, monst)) {
		cout << "Monster slain" << endl;
		monsterCount++;
		cout << "You have defeated the monster! Most impressive." << endl;
		cout << "You find " << monst->getLOOT() << " loot on the monster's corpse.  Well earned." << endl;
		cout << "You move on with " << hero->getHealth() << " health and " << hero->getCurMana() << " mana." << endl;
		lootCount += monst->getLOOT();
		//std::chrono::duration<int, std::milli> timespan(1000);
		char choice;
		do {
			cout << "Press c to continue." << endl;
			cin >> choice;
		} while(choice != 'c');
		return true;
	} else {
		//If fail
		cout << "You have been killed.  The monster feeds on your lifeless corpse..." << endl;
		//std::chrono::duration<int, std::milli> timespan(1000);
		char choice;
		do {
			cout << "Press c to continue...to the afterlife" << endl;
			cin >> choice;
		} while(choice != 'c');
		return false;
	}



	//Return true if successful, false if death
	//return true;
}

//Unused?
void Floor::runLoot() {
	time_t timer;
	time(&timer);
	srand(timer);
	int loot = (rand()%20) + 1;
	goldCount += loot;
	cout << "You cautiously enter the room, but only find a simple unassuming chest. "
			<< "You open the chest to find " << loot << " gold coins! "
					 << "You take it and run." << endl;
	//Store loot

	//std::chrono::duration<int, std::milli> timespan(1000);
	//sleep_for(std::chrono::seconds(1));
	char choice;
	do {
		cout << "Press c to continue." << endl;
		cin >> choice;
	} while(choice != 'c');
}

//Text for nothing happening
void Floor::runNothing() {
	cout << "You bust down the door ready to fight!" << endl;
	cout << "....\n...\nBut nothing happens?" << endl;
	cout << "You continue on, confused and slightly disappointed." << endl;
	//std::chrono::duration<int, std::milli> timespan(1000);
	char choice;
	do {
		cout << "Press c to continue." << endl;
		cin >> choice;
	} while(choice != 'c');
}

//Run boss battle
bool Floor::runBoss() {
	//Create boss
	boss* Olaf = new boss();
	//Olaf = boss();

	cout << "You crack open the door and peak through, seeing only darkness." << endl;
	cout << "Suddenly, the door is pulled open, and you are pulled into the chamber and thrown against the opposite wall!" << endl;
	cout << "Fire erupts along the walls, revealing a demon beyond description blocking the only entrance." << endl;
	cout << "Shaken, you raise your weapon and prepare for the fight of your life." << endl;
	cout << "...Good luck.  You'll need it." << endl;

	//run combat
	if (combatSystem(this->hero, Olaf)) {
		//If Victory (lol)
		cout << "You have apparently hacked the game.  Well done I suppose.  Take your loot and get out." << endl;
		achievementRecorder.push_back("Hacker -_-");
		return true;
	} else {
		//When failure
		cout << "After a heroic but futile effort, you lie before the demon in defeat." << endl;
		cout << "The beast makes a disturbing guttural sound that could be a laugh or cheer." << endl;
		cout << "You vision goes dark as your life fades, and you lay defeated at the foot of the monster, thankful for the release of death." << endl;
		return false;
	}
	//return true if success, false if death
	return true;

}


int Floor::getLevel() {
	return this->level;
}





/*
 *Setters for the monster generation.
 *Generate a monster name.
 *@return: monster name.
 */
string monster::setMONSTER(){
	string monsterSelection[]={"Slime","Goblin","Wyvern","Mummy","Orc","Imp","Dark Phantom","Vampire","Minotaur","Skeletal"};
	srand(time(0));
	int numMonster = rand()%10;
	string monsterName = monsterSelection[numMonster];
	return monsterName;
}
/*
 * Generate monster's hp.
 * @return: HP of monster
 */
int monster::setHP(int level){
	srand(time(0));
	int floorLevel = level;
	int numHP = rand()%5+floorLevel;
	return numHP;
}
/*
 * Generate monster's damage.
 * @return: Damage of monster
 */
int monster::setDAMAGE(int level){
	srand(time(0));
	int floorLevel = level;
	int numDamage = rand()%3+floorLevel;
	return numDamage;
}
/*
 * Generate monster's defense.
 * @return: Defense of monster
 */
int monster::setDEFENSE(int level){
	srand(time(0));
	int floorLevel = level;
	int numDefense = rand()%2+floorLevel;
	return numDefense;
}
/*
 * Generate monster's loot.
 * @return: Loot of monster
 */
int monster::setLOOT(){
	srand(time(0));
	int numLoot = rand()%10+1;
	return numLoot;
}

/*
 * Getters to get monster information.
 */
string monster::getMONSTER(){
	return this->name;
}
int monster::getHP(){
	return this->hp;
}
int monster::getDAMAGE(){
	return this->damage;
}
int monster::getDEFENSE(){
	return this->defense;
}
int monster::getLOOT(){
	return this ->loot;
}

/*
 * Getters to get boss information
 */
string boss::getBOSS(){
	return this->name;
}
int boss::getHPBoss(){
	return this->hp;
}
int boss::getDAMAGEBoss(){
	return this->damage;
}
int boss::getDEFENSEBoss(){
	return this->defense;
}

/**
*Created By: Dylan Alvarez
*Contains:The methods that go with the classes defined by the Character_Creation_H
*/
#include <iostream>
#include <string>
#include "CharacterCreation.h"

//Defining the methods inherited from the abstract Player class
int Knight::getDmg()
{
  return this->dmg;
}
void Knight::setDmg(int dmg)
{
	this->dmg = dmg;
}
int Knight::getDef()
{
  return this->def;
}
void Knight::setDef(int def) {
	this->def = def;
}
int Knight::getCurMana()
{
  return this->curMana;
}
void Knight::setCurMana(int mana)
{
  this->curMana = mana;
}
int Knight::getMaxMana()
{
  return this->maxMana;
}
void Knight::setMaxMana(int maxMana)
{
	this->maxMana = maxMana;
}
int Knight::getLvl()
{
  return this->lvl;
}
string Knight::getName()
{
  return this->name;
}
void Knight::setLvl(int lvl)
{
  (this->lvl) = lvl;
}
void Knight::lvlUp(int floorLevel)
{
  this->setLvl(this->getLvl()+1);
  this->setMaxHP(this->getMaxHP()+5);
  this->setDmg(this->getDmg() + floorLevel);
  this->setMaxMana(this->getMaxMana() + 5);
  this->setDef(this->getDef() + 1);
}
int Knight::getHealth()
{
  return this->curHP;
}
void Knight::setHealth(int health)
{
  this->curHP = health;
}
int Knight::getMaxHP()
{
  return this->maxHP;
}
void Knight::setMaxHP(int hp)
{
	this->maxHP = hp;
}
string Knight::getClass()
{
  return className;
}

//Skill: returns an int for now, can become its own algorithm though
int Knight::skill1()
{
  if((this->getLvl() < 2) || (curMana < 2)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "Stylish Spin!" << endl;
     curMana = curMana - 2;
	   return 2 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

int Knight::skill2()
{
  if((this->getLvl() < 3) || (curMana < 4)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "Shield Bash!" << endl;
     curMana = curMana - 4;
	   return 3 + ((this->getLvl())*.5) + (this->getDmg());
  }
}
int Knight::skill3()
{
  if((this->getLvl() < 4) || (curMana < 6)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "Demacian Judgment!" << endl;
     curMana = curMana - 6;
     return 4 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

int Knight::skill4()
{
  if((this->getLvl() < 5) || (curMana < 8)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "'SQUARE UP!!!' You yell as you charge headlong at the monster." << endl;
     curMana = curMana - 8;
	   return 5 + ((this->getLvl())*.5) + (this->getDmg());
  }
}


//Defining the methods inherited from the abstract Player class
int Archer::getDmg()
{
  return this->dmg;
}
void Archer::setDmg(int dmg)
{
	this->dmg = dmg;
}
int Archer::getDef()
{
  return this->def;
}
void Archer::setDef(int def) {
	this->def = def;
}
int Archer::getCurMana()
{
  return this->curMana;
}
void Archer::setCurMana(int mana)
{
  this->curMana = mana;
}
int Archer::getMaxMana()
{
  return this->maxMana;
}
void Archer::setMaxMana(int maxMana)
{
	this->maxMana = maxMana;
}
int Archer::getLvl()
{
  return this->lvl;
}
string Archer::getName()
{
  return this->name;
}
void Archer::setLvl(int lvl)
{
  (this->lvl) = lvl;
}
void Archer::lvlUp(int floorLevel)
{
  this->setLvl(this->getLvl()+1);
  this->setMaxHP(this->getMaxHP()+5);
  this->setDmg(this->getDmg() + floorLevel);
  this->setMaxMana(this->getMaxMana() + 5);
  this->setDef(this->getDef() + 1);
}
int Archer::getHealth()
{
  return this->curHP;
}
void Archer::setHealth(int health)
{
  this->curHP = health;
}
int Archer::getMaxHP()
{
  return this->maxHP;
}
void Archer::setMaxHP(int hp)
{
	this->maxHP = hp;
}
string Archer::getClass()
{
  return className;
}

//Skill: returns an int for now, can become its own algorithm though
int Archer::skill1()
{
  if((this->getLvl() < 2) || (curMana < 2)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	 cout << "Snipe!" << endl;
     curMana = curMana - 2;
	 return 2 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

int Archer::skill2()
{
  if((this->getLvl() < 3) || (curMana < 4)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "Lucky Shot!" << endl;
     curMana = curMana - 4;
	   return 3 + ((this->getLvl())*.5) + (this->getDmg());
  }
}
int Archer::skill3()
{
  if((this->getLvl() < 4) || (curMana < 6)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "Hail Mary!" << endl;
     curMana = curMana - 6;
     return 4 + ((this->getLvl())*.5) + (this->getDmg());
  }
}


int Archer::skill4()
{
  if((this->getLvl() < 5) || (curMana < 8)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "'Well, here goes nothing!' You shout as you fire wildly at the beast." << endl;
     curMana = curMana - 8;
	   return 5 + ((this->getLvl())*.5) + (this->getDmg());
  }
}


//Defining the methods inherited from the abstract Player class
int Caster::getDmg()
{
  return this->dmg;
}
void Caster::setDmg(int  dmg)
{
	this->dmg = dmg;
}
int Caster::getDef()
{
  return this->def;
}
void Caster::setDef(int def) {
	this->def = def;
}
int Caster::getCurMana()
{
  return this->curMana;
}
void Caster::setCurMana(int mana)
{
  this->curMana = mana;
}
int Caster::getMaxMana()
{
  return this->maxMana;
}
void Caster::setMaxMana(int maxMana)
{
	this->maxMana = maxMana;
}
int Caster::getLvl()
{
  return this->lvl;
}
string Caster::getName()
{
  return this->name;
}
void Caster::setLvl(int lvl)
{
  (this->lvl) = lvl;
}
void Caster::lvlUp(int floorLevel)
{
  this->setLvl(this->getLvl()+1);
  this->setMaxHP(this->getMaxHP()+5);
  this->setDmg(this->getDmg() + floorLevel);
  this->setMaxMana(this->getMaxMana() + 5);
  this->setDef(this->getDef() + 1);
}
int Caster::getHealth()
{
  return this->curHP;
}
void Caster::setHealth(int health)
{
  this->curHP = health;
}
int Caster::getMaxHP()
{
  return this->maxHP;
}
void Caster::setMaxHP(int hp)
{
	this->maxHP = hp;
}
string Caster::getClass()
{
  return className;
}

//Skill: returns an int for now, can become its own algorithm though
int Caster::skill1()
{

  if((this->getLvl() < 2) || (curMana < 2)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "Baleful Strike!" << endl;
     curMana = curMana - 2;
	   return 2 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

int Caster::skill2()
{
  if((this->getLvl() < 3) || (curMana < 4)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "Dark Matter!" << endl;
     curMana = curMana - 4;
	   return 3 + ((this->getLvl())*.5) + (this->getDmg());
  }
}
int Caster::skill3()
{
  if((this->getLvl() < 4) || (curMana < 6)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "Event Horizon!" << endl;
     curMana = curMana - 6;
     return 4 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

int Caster::skill4()
{
  if((this->getLvl() < 5) || (curMana < 8)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
	  cout << "'Face my ultimate spell!!!' You declare as you lob a massive ball of energy at the beast." << endl;
     curMana = curMana - 8;
	   return 5 + ((this->getLvl())*.5) + (this->getDmg());
  }
}


//Creates the story and accesses different parts

Player* chooseClass() {

	cout << "Choose your class:\n1: Archer\n2: Caster\n3: Knight" << endl;
	string choice = "";
	int intChoice = 0;


	//Needs to be idiot proofed
	cin >> choice;
	intChoice = intCheck(choice);


	Player *hero;
	switch (intChoice) {
	case 1:
		hero = new Archer(10, 1, 10, "");
		break;
	case 2:
		hero = new Caster(10, 1, 10, "");
		break;
	case 3:
		hero = new Knight(10, 1, 10, "");
		break;
	default:
		cout << "Invalid Input!" << endl;
	}
	achievementRecorder.push_back("Character Created - Doing the bare minimum");


	return hero;
}

bool UserInterface:: createStory () {
    int part = this->storyPart;
    string partc;
    Player* hero;
    Floor* floor;
    //Use after character creation in story.
    if (part == 0) {
        cout << "You lay awake on a stone cold floor in a dank, lifeless dungeon. Your mind stirs for you name...\n\nEnter c to continue.\n\n";

        while (partc != "c") {
            cin >> partc;
            if (partc == "c") {
            	hero = chooseClass();
            	cout << hero->getName() << ", yes, that's it..\n\nEven with your name remembered, there still lies a thick fog over your memory as you take your first steps into the dimly lit darkness ahead." << endl;
            }
            else {
                cout << "Press c to clear your mind.\n\n";
            }
        }
        partc = " ";
    }

    //Use on first monster encounter.
    if (part == 1) {
    	string parta = "";
    	cout << "\n\nYou feel a cool breeze which you decide to follow.\nAs the gusts become more forceful, you spot a spiralling passage into your grim future";
    	elipsis();
    	cout << "\n\nEnter c to continue.\n" << endl;
    	while (parta != "c") {
    		cin >> parta;
    	    if (parta == "c") {
    	    	cout << "\nYour hands and face become cold as you move by feeling along the wall for guidance.\nYou finally reach the end only to find another dimly lit room.\nWith a heart full of fear, you attempt to peer through the veil of darkness.\n\n" << endl;
    	        lag(20);

    	    }
    	    else {
    	    	cout << "\nEnter c to encounter your fate.\n" << endl;
    	    }
    	}
    	parta = " ";
    	//cout << "Test2 Floor 1" << endl;
    	floor = new Floor(1, hero);
    	if(!floor->run()) {
    		return false;
    	}

        cout << "\n\nSomething lurks in the shadows.. A MONSTER STRIKES!? What hellish nightmare is this? As your panic heightens, as does a surge of energy through your veins. You remember your years training. Kill or be killed.\n\n";
    }
    //Use after first level.
    if (part == 2) {
    	string parta = "";
    	 cout << "\n\nYou feel power flowing through your veins.\nA surge of excitement takes over as you plunge into the shadows ahead.\n\nEnter c to have your confidence shattered.\n" << endl;
    	            while (parta != "c") {
    	                cin >> parta;
    	                if (parta == "c") {
    	                    cout << "\nYou trip on the only stone in the room and stub your toe.\nWith indescribable pain and embarrassment, you trudge onwards to face the inevitable hell that lies ahead.";
    	                    lag(20);
    	                    elipsis();
    	                    cout << "\n\n" << endl;
    	                }
    	                else {
    	                    cout << "\nEnter c to feel inadequate.\n" << endl;
    	                }
    	            }
    	        parta = " ";
    	floor = new Floor(2, hero);
    	if(!floor->run()) {
    		return false;
    	}
        cout << "";
    } else if (part == 3) {
    	string parta = "";
    	cout << "Searching your mind for any semblance of a memory, you faintly remember a family...\n Something is there. Something is blocking your memories.\nIt's not amnesia.. It's almost like a presence has hold of your consciousness";
    	        elipsis();
    	        cout << "\n\nEnter c to focus harder.\n\n" << endl;
    	            while (parta != "c") {
    	                cin >> parta;
    	                if (parta == "c") {
    	                    cout << "\nIt feels like your mind is drowning. You're trying to draw on anything.\nFamily, friends, everyone";
    	                    elipsis();
    	                    cout << " All gone. You don't remember why, but sadness takes over nonetheless.\nYou walk somberly through the unending darkness.\n\n" << endl;
    	                    lag(20);
    	                }
    	                else if (parta != "c"){
    	                    cout << "\nEnter c to focus your thoughts.\n" << endl;
    	                }
    	            }
    	        parta = " ";
    	floor = new Floor(3, hero);
    	if(!floor->run()) {
    	    		return false;
    	    	}
    } else if (part == 4) {
    	floor = new Floor(4, hero);
    	if(!floor->run()) {
    	    		return false;
    	    	}
    } else if (part == 5) {
    	floor = new Floor(5, hero);
    	if(!floor->run()) {
    	    		return false;
    	    	}
    }
    return true;
}

int UserInterface:: getStoryPart () {
    return this->storyPart;
}

void UserInterface:: setStoryPart (int part) {
    this->storyPart = part;
}

//*****ADDED******************
#include <cwchar>

//enter this after each level is finished for specified story part.
void UserInterface::finishLvl(int part) {

    int v = part;

    string parta;
    string partb;
    if (v == 0) {
//        cout << "\n\nYou feel a cool breeze which you decide to follow.\nAs the gusts become more forceful, you spot a spiralling passage into your grim future";
//        elipsis();
//        cout << "\n\nEnter c to continue.\n" << endl;
//            while (parta != "c") {
//                cin >> parta;
//                if (parta == "c") {
//                    cout << "\nYour hands and face become cold as you move by feeling along the wall for guidance.\nYou finally reach the end only to find another dimly lit room.\nWith a heart full of fear, you attempt to peer through the veil of darkness.\n\n" << endl;
//                    lag(20);
//
//                }
//                else {
//                cout << "\nEnter c to encounter your fate.\n" << endl;
//                }
//            }
//        parta = " ";
    }
    else if (v == 1) {
//        cout << "\n\nYou feel power flowing through your veins.\nA surge of excitement takes over as you plunge into the shadows ahead.\n\nEnter c to have your confidence shattered.\n" << endl;
//            while (parta != "c") {
//                cin >> parta;
//                if (parta == "c") {
//                    cout << "\nYou trip on the only stone in the room and stub your toe.\nWith indescribable pain and embarrassment, you trudge onwards to face the inevitable hell that lies ahead.";
//                    lag(20);
//                    elipsis();
//                    cout << "\n\n" << endl;
//                }
//                else {
//                    cout << "\nEnter c to feel inadequate.\n" << endl;
//                }
//            }
//        parta = " ";
    }
    else if (v == 2) {
//        cout << "Searching your mind for any semblance of a memory, you faintly remember a family...\n Something is there. Something is blocking your memories.\nIt's not amnesia.. It's almost like a presence has hold of your consciousness";
//        elipsis();
//        cout << "\n\nEnter c to focus harder.\n\n" << endl;
//            while (parta != "c") {
//                cin >> parta;
//                if (parta == "c") {
//                    cout << "\nIt feels like your mind is drowning. You're trying to draw on anything.\nFamily, friends, everyone";
//                    elipsis();
//                    cout << " All gone. You don't remember why, but sadness takes over nonetheless.\nYou walk somberly through the unending darkness.\n\n" << endl;
//                    lag(20);
//                }
//                else if (parta != "c"){
//                    cout << "\nEnter c to focus your thoughts.\n" << endl;
//                }
//            }
//        parta = " ";
    }
    else if (v == 3) {
        cout << "Exhausted and beaten, you see a light shining in the distance. Freedom? Safety?\nEven if you ended up in the bottom pits of hell, it would still be better than an endless life of whatever this was, you think";
        elipsis();
        lag(20);
            cout << "\n\nEnter c to complete your journey.\n" << endl;
            while (parta != "c") {
                cin >> parta;
                if (parta == "c") {
                    cout << "\nA completely empty room?";
                    elipsis();
                    cout << " This must be a mistake";
                    elipsis();
                    cout << " Whoever is controlling your fate must be toying with you for their amusement";
                    elipsis();
                    cout << "\n\nEnter c to focus your thoughts.\n" << endl;
                    while (partb != "c") {
                        cin >> partb;
                        if (partb == "c") {
                            cout << "\n\nColors shade in from the black ahead. You feel the light, but don't see it directly.\nWhatever is stopping your memory is also blocking your vision. But, soon, everything is revealed";
                            elipsis();
                            cout << "\n\n";
                        }
                        else {
                            cout << "\n\nEnter c to search your mind!" << endl;
                        }
                    }
                }
                else if (parta != "c") {
                    cout << "\nEnter c to finish this!\n\n" << endl;
                }
            }
        parta = " ";
    }
}

void UserInterface::elipsis() {
    for (int i = 0; i<3;i++) {
        cout << ".";
        lag(5);
    }
}

void UserInterface::opener(const string& message) {
    for (const char c: message) {
        cout << c;
        //lag(1);
        //std::this_thread::sleep_for (std::chrono::milliseconds(125));
    }
}

//n = 5 for about 1 second and n = 15 for about 4 second break.
void UserInterface::lag(int n) {
    int j = 0;
    //50000000 for 125 millis

    for (int i = 0; i < 1*n; i++) {
        j++;
        j--;
    }
}

//********EXTRA EXTRA**********************
//title and credits
void UserInterface::beginEnd(int x) {
    if (x == 0) {
        cout << "========================================";
        cout << "\n\t";
        opener("THE ADVENTURES OF OLAF!\n");
        cout << "========================================\n\n";
    }
    if (x == 1) {
        cout << "\n\n";
        cout << "Achievements:" << endl;
        for(int i = 0; i < achievementRecorder.size(); i++) {
            cout << achievementRecorder.at(i) << endl;
        }
        cout << "Slain monsters: " << monsterCount << endl;
        cout << "Total gold pillaged: " << goldCount << endl;
        cout << "Total loot collected: " << lootCount << endl;
        cout << "Total time taken: " << timeTaken2 - timeTaken1 << " seconds." << endl;

        opener("\n\nCREDITS\n\n");
        cout << "User Interface:";
        opener(" Matthew Leonard\n\n");
        cout << "Character Creation:";
        opener(" Dylan Alvarez\n\n");
        cout << "Floor Design:";
        opener(" Alexander Jasper\n\n");
        cout << "Monster Creation:";
        opener(" Johnny Li\n\n");
        cout << "Combat System:";
        opener(" Aaron Gaskin");


    }
}



//int main() {

//	timeTaken1 = time(0);
//	UserInterface UI;
//	bool alive = true;
//	int i = 0;
//	UI.beginEnd(0);

//	while(alive && i <= 5) {
//		UI.setStoryPart(i);
//		alive = UI.createStory();
//		i++;

//	}

//	timeTaken2 = time(0);
  //  UI.beginEnd(1);
//}
