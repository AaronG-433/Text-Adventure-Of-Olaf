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
#include <chrono>
#include <iostream>

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

bool combatSystem(Player* player, boss* mon)
{
	//set up values for player
	string choice = "";
	int intChoice = 0;
	int charHealth = player->getHealth();
	int charMana = player->getCurMana();
	int charDamage = player->getDmg();
	int charDefense = player->getDef();

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
		cout << "You have " << charHealth << " HP and " << charDamage << " attack." <<endl;

		//ask for user's choice
		cout << "What would you like to do?\n";
		cout << "1.) Basic Attack\n2.) Use Skill\n3.) Use Item" << endl;
		cin >> choice;
		//verify that it is an integer
		intChoice = intCheck(choice);

		//perform action based on user choice
		switch(intChoice)
		{
			case 1: cout << "You strike the " << monName << " It takes " << charAttack << " damage." << endl;
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
			case 2:			//TODO: implement skills
					break;
			case 3:			//TODO: instead of item do block/dodge?
					break;
			default: cout << "Invalid choice!" << endl;
		}

		//Check if the player is dead
		if(charHealth <= 0)
		{
			return false;
		}

		//output how much health the monster has
		cout << "The vile " << monName << " still has " << monHealth << " HP left!" << endl;
	}
}

bool combatSystem(Player* player, monster* mon)
{
	//set up values for player
	string choice = "";
	int intChoice = 0;
	int charHealth = player->getHealth();
	int charMana = player->getCurMana();
	int charDamage = player->getDmg();
	int charDefense = player->getDef();

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
		cout << "You have " << charHealth << " HP and " << charDamage << " attack." <<endl;

		//ask for user's choice
		cout << "What would you like to do?\n";
		cout << "1.) Basic Attack\n2.) Use Skill\n3.) Use Item" << endl;
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
			case 2:			//TODO: implement skills
					break;
			case 3:			//TODO: instead of item do block/dodge?
					break;
			default: cout << "Invalid choice!" << endl;
		}

		//Check if the player is dead
		if(charHealth <= 0)
		{
			return false;
		}

		//output how much health the monster has
		cout << "The vile " << monName << " still has " << monHealth << " HP left!" << endl;
	}
}

//Will also take the character as a parameter
Floor::Floor(int level, Player* hero) {
	this->level = level;
	this->hero = hero;

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
		cout << "You have defeated the monster! Most impressive." << endl;
		cout << "You find " << monst->getLOOT() << " loot on the monster's corpse.  Well earned." << endl;
		cout << "You move on with " << hero->getHealth() << " health and " << hero->getCurMana() << " mana." << endl;

		std::chrono::duration<int, std::milli> timespan(1000);
		char choice;
		do {
			cout << "Press c to continue." << endl;
			cin >> choice;
		} while(choice != 'c');
		return true;
	} else {
		//If fail
		cout << "You have been killed.  The monster feeds on your lifeless corpse..." << endl;
		std::chrono::duration<int, std::milli> timespan(1000);
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
	cout << "You cautiously enter the room, but only find a simple unassuming chest. "
			<< "You open the chest to find " << loot << " gold coins! "
					 << "You take it and run." << endl;
	//Store loot

	std::chrono::duration<int, std::milli> timespan(1000);
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
	std::chrono::duration<int, std::milli> timespan(1000);
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
#include "CharacterCreation.h"				/////////////////////////Don't forget to include the header!


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
void Knight::setDef(int def)
{
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
int Knight::styleishSpin()
{
  if((this->getLvl() < 2) && (curMana >= 2)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 2;
	   return 2 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

int Knight::shieldBash()
{
  if((this->getLvl() < 3) && (curMana >= 4)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 4;
	   return 3 + ((this->getLvl())*.5) + (this->getDmg());
  }
}
int Knight::demacianJudgement()
{
  if((this->getLvl() < 4) && (curMana >= 6)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 6;
     return 4 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

int Knight::foolishCourage()
{
  if((this->getLvl() < 5) && (curMana >= 8)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
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
void Archer::setDef(int def)
{
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
int Archer::snipe()
{
  if((this->getLvl() < 2) && (curMana >= 2)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 2;
	   return 2 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

int Archer::luckyShot()
{
  if((this->getLvl() < 3) && (curMana >= 4)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 4;
	   return 3 + ((this->getLvl())*.5) + (this->getDmg());
  }
}
int Archer::hailMary()
{
  if((this->getLvl() < 4) && (curMana >= 6)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 6;
     return 4 + ((this->getLvl())*.5) + (this->getDmg());
  }
}


int Archer::oneInAMillion()
{
  if((this->getLvl() < 5) && (curMana >= 8)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 8;
	   return 5 + ((this->getLvl())*.5) + (this->getDmg());
  }
}


//Defining the methods inherited from the abstract Player class
int Caster::getDmg()
{
  return this->dmg;
}
void Caster::setDmg(int dmg)
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
int Caster::balefulStrike()
{
  if((this->getLvl() < 2) && (curMana >= 2)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 2;
	   return 2 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

int Caster::darkMatter()
{
  if((this->getLvl() < 3) && (curMana >= 4)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 4;
	   return 3 + ((this->getLvl())*.5) + (this->getDmg());
  }
}
int Caster::eventHorizon()
{
  if((this->getLvl() < 4) && (curMana >= 6)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 6;
     return 4 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

int Caster::primordialBurst()
{
  if((this->getLvl() < 5) && (curMana >= 8)) //Check if player is high enough level to use new skill
  {
    return -1;
  }
  else
  {
     curMana = curMana - 8;
	   return 5 + ((this->getLvl())*.5) + (this->getDmg());
  }
}

//Creates the story and accesses different parts

Player* chooseClass() {

	cout << "Choose your class:\n1: Archer\n2: Caster\n3: Knight" << endl;
	int choice = 0;
	cin >> choice;
	//Needs to be idiot proofed
	Player *hero;
	switch (choice) {
	case 1:
		hero = new Archer(10, 1, 10, "");
		break;
	case 2:
		hero = new Caster(10, 1, 10, "");
		break;
	case 3:
		hero = new Knight(10, 1, 10, "");
		break;
	}
	return hero;
}

void UserInterface:: createStory () {
    int part = this->storyPart;
    string parta;
    Player* hero;
    Floor* floor;
    //Use after character creation in story.
    if (part == 0) {
        cout << "You lay awake on a stone cold floor in a dank, lifeless dungeon. Your mind stirs for you name...\n\nEnter c to continue.\n\n";

        while (parta != "c") {
            cin >> parta;
            if (parta == "c") {
            	hero = chooseClass();
                cout << hero->getName() << ", yes, that's it..\n\nEven with your name remembered, there still lies a thick fog over your memory as you take your first steps into the dimly lit darkness ahead." << endl;
            }
            else {
                cout << "Press c to clear your mind.\n\n";
            }
        }
        parta = " ";
    }

    //Use on first monster encounter.
    if (part == 1) {
    	floor = new Floor(1, hero);
    	floor->run();
        cout << "\n\nSomething lurks in the shadows.. A MONSTER STRIKES!? What hellish nightmare is this? As your panic heightens, as does a surge of energy through your veins. You remember your years training. Kill or be killed.\n\n";
    }
    //Use after first level.
    if (part == 2) {
    	floor = new Floor(2, hero);
    	floor->run();
        cout << "";
    } else if (part == 3) {
    	floor = new Floor(3, hero);
    	floor->run();
    } else if (part == 4) {
    	floor = new Floor(4, hero);
    	floor->run();
    } else if (part == 5) {
    	floor = new Floor(5, hero);
    	floor->run();
    }
}

int UserInterface:: getStoryPart () {
    return this->storyPart;
}

void UserInterface:: setStoryPart (int part) {
    this->storyPart = part;
}


int main() {
    UserInterface UI;
    UI.setStoryPart(0);
    UI.createStory();
    UI.setStoryPart(1);
    UI.createStory();
    UI.setStoryPart(2);
    UI.createStory();
    UI.setStoryPart(3);
    UI.createStory();
    UI.setStoryPart(4);
    UI.createStory();
    UI.setStoryPart(5);
    UI.createStory();
}
