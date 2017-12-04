#include "FloorDesign.h"
using namespace std;

//Takes floor level and player as parameters
Floor::Floor(int level, Player* hero) {
	this->level = level;
	this->hero = hero;
	
}

bool Floor::run() {
	
	//Check hero health
	if(hero->getHealth() <= 0) {
		return false;
	}
	bool fail = true;
	int outcome = 0;

	time_t timer;
	

	//If not the boss level
	if(level < 5) {
		//Run through each room
		for(int i=0; i<level*2; i++) {
			//Check hero health
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
				//50%: Call monster method and check if they survived
				fail = this->runMonster();
				if(!fail) {
					//fail = true;
					return false;
					//break;
				} else {

				}

				//40%: Run loot method
			} else if(outcome >= 5 && outcome < 9 && fail) {
				this->runLoot();
				//10%: Run nothing method
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
		//Call boss method and check if they survive
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

	//Achievement Check
	if(this->level == 4) {
		char partc;


		if(hero->getName().compare("Olaf") == 0) {
			cout << "You have called upon the ancient weapon of house Olaf, the holy blade of Fuck You" << endl;
			hero->setDmg(1569325055);
		}

		achievementRecorder.push_back("Cleared floor 4!");

	}
}

//Run monster room event, return true if successful, false if death
bool Floor::runMonster() {
	//Create monster
	monster* monst = new monster(this->level);

	cout << "A " << monst->getMONSTER()
			<< " has appeared! It moves to attack you.  Defend yourself!" << endl;

	//Call combat system and check if they survive
	if(combatSystem(this->hero, monst)) {
		
		//Increment monster slain count
		monsterCount++;
		cout << "You have defeated the monster! Most impressive." << endl;
		cout << "You find " << monst->getLOOT() << " loot on the monster's corpse.  Well earned." << endl;
		cout << "You move on with " << hero->getHealth() << " health and " << hero->getCurMana() << " mana." << endl;
		//Incrememt Loot count
		lootCount += monst->getLOOT();
	
		char choice;
		do {
			cout << "Press c to continue." << endl;
			cin >> choice;
		} while(choice != 'c');
		return true;
	} else {
		//If fail
		cout << "You have been killed.  The monster feeds on your lifeless corpse..." << endl;
		
		char choice;
		do {
			cout << "Press c to continue...to the afterlife" << endl;
			cin >> choice;
		} while(choice != 'c');
		return false;
	}
}


void Floor::runLoot() {
	//Randomly generate loot
	time_t timer;
	time(&timer);
	srand(timer);
	int loot = (rand()%20) + 1;
	goldCount += loot;
	cout << "You cautiously enter the room, but only find a simple unassuming chest. "
			<< "You open the chest to find " << loot << " gold coins! "
					 << "You take it and run." << endl;
	
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
	
	char choice;
	do {
		cout << "Press c to continue." << endl;
		cin >> choice;
	} while(choice != 'c');
}

//Run boss battle, return true if success, false if death
bool Floor::runBoss() {
	//Create boss
	boss* Olaf = new boss();

	cout << "You crack open the door and peak through, seeing only darkness." << endl;
	cout << "Suddenly, the door is pulled open, and you are pulled into the chamber and thrown against the opposite wall!" << endl;
	cout << "Fire erupts along the walls, revealing a demon beyond description blocking the only entrance." << endl;
	cout << "Shaken, you raise your weapon and prepare for the fight of your life." << endl;
	cout << "...Good luck.  You'll need it." << endl;

	//run combat, check for survival
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
	
	return true;

}


int Floor::getLevel() {
	return this->level;
}
