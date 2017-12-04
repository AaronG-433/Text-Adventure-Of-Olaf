#include "FloorDesign.h"

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
	goldCount += loot;
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
