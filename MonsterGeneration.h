#ifndef monster_H
#define monster_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 *monster.h
 *Summary: Monster/Boss Generation method: Be able to return a monster/boss when called.
 *Include a variety of monsters to be encountered with various base stats.
 *Author: Johnny Li
 *COP 3503 Section Number: 128D
 */

/*
 * Monster class - create a randomly generated monster.
 */
class monster{
//Monster information
private:
	string name;
	int hp;
	int damage;
	int defense;
	int loot;

public:
	monster(int level);
	//Setters
	string setMONSTER();
	int setHP(int level);
	int setDAMAGE(int level);
	int setDEFENSE(int level);
	int setLOOT();

	//Getters
	string getMONSTER();
	int getHP();
	int getDAMAGE();
	int getDEFENSE();
	int getLOOT();
};

//Monster Constructor
monster::monster(int level){

	name =setMONSTER();
	hp =setHP(level);
	damage =setDAMAGE(level);
	defense =setDEFENSE(level);
	loot =setLOOT();
}

/*
* Boss class - general final boss of the game.
*/
class boss{
private:
	string name;
	int hp;
	int damage;
	int defense;

public:
	boss();
	//Getters
	string getBOSS();
	int getHPBoss();
	int getDAMAGEBoss();
	int getDEFENSEBoss();
};

//Boss Constructor
boss::boss(){
	name ="Olaf";
	hp =9000;
	damage =666;
	defense =401;
}

#endif
