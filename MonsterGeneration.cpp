#include "MonsterGeneration.h"
using namespace std;


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
