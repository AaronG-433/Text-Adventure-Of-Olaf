 /*
 * CharacterCreation.h
 *
 *  Created on: Nov 30, 2017
 *      Author: Dylan Alvarez
 */

#ifndef Character_Creation_H
#define Character_Creation_H
#include <iostream>
#include <string>
using namespace std;
#include <vector>
class Player
{
//Any accessor methods, as well as the player constructor are here
	public:

		//General stats not depending on class
		virtual int getHealth() = 0;
		virtual void setHealth(int hp) = 0;
		virtual int getMaxHP() = 0;
		virtual void setMaxHP(int hp) = 0;
		virtual void lvlUp(int floorLevel) = 0;
		virtual string getClass() = 0;
		virtual string getName() = 0;
		virtual int getLvl() = 0;
		virtual int getDmg() = 0;
		virtual void setDmg(int dmg) = 0;
		virtual int getDef() = 0;
		virtual void setDef(int def) = 0;
   		virtual int getCurMana() = 0;
   		virtual void setCurMana(int mana) = 0;
		virtual int getMaxMana() = 0;
		virtual void setMaxMana(int maxMana) = 0;
		virtual void setLvl(int lvl) = 0;

		//skills
		virtual int skill1() = 0;
		virtual int skill2() = 0;
		virtual int skill3() = 0;
		virtual int skill4() = 0;

		virtual ~Player() = 0;				//////////////Added {} instead of =0 and we good
  protected:

			//////////////////////TODO: do the constructors need inputs since we set values ahead of time?

    Player (int maxHP, int lvl, int maxMana, string name)
    {
    this -> maxHP = maxHP;
    this -> lvl = lvl;
    this -> maxMana = maxMana;
    cout << "What is the name of your character" << endl;
    cin >> this -> name;
		//this -> name = "Olaf";
    }

	//These are the general player states

		int curHP = 10;
		int maxHP = 10;
		int lvl = 1;
		int curMana = 10;
		int mana = 10;
		string name;
    		int maxMana = 10;
		//vector<string> achievementRecorder;

};

/*
The knight subclass
Tip:If you try and use a skill you cannot actually use because of lack of mana/level, it return's -1, so check for that in combat
*/
class Knight : public Player
{


	//Define a bunch of extra skill methods and stats
	private:
		int dmg = 0;
		int def = 0;
    		string className;

	public:
	//skills
    	int skill1();
    	int skill2();
    	int skill3();
    	int skill4();
      //inheritance
     	int getHealth();
  		void setHealth(int hp);
  		int getMaxHP();
		void setMaxHP(int hp);
  		void lvlUp(int floorLevel);
  		string getName();
  		int getLvl();
		void setLvl(int lvl);
		string getClass();
		int getDmg();
		void setDmg(int dmg);
		int getDef();
		void setDef(int def);
		int getCurMana();
		int getMaxMana();
		void setCurMana(int mana);
		void setMaxMana(int maxMana);
	~Knight();
      //Constructor for subclass knight
		Knight(int maxHP, int lvl, int maxMana, string name): Player(maxHP,lvl, maxMana,name)
		{
			dmg = 1;
			def = 2;
      			className = "Knight";
		}

};

/*
The knight subclass
Tip:If you try and use a skill you cannot actually use because of lack of mana/level, it return's -1, so check for that in combat
*/
class Archer : public Player
{


	//Define a bunch of extra skill methods and stats
	private:
		int dmg = 0;
		int def = 0;
   		string className;

	public:
			//skills
   		int skill1();
		int skill2();
		int skill3();
		int skill4();

      //inheritance
		int getHealth();
  		void setHealth(int hp);
  		int getMaxHP();
		void setMaxHP(int hp);
  	 	void lvlUp(int floorLevel);
  		string getName();
  		int getLvl();
		void setLvl(int lvl);
		string getClass();
		int getDmg();
		void setDmg(int dmg);
		int getDef();
		void setDef(int def);
		int getCurMana();
		int getMaxMana();
		void setCurMana(int mana);
		void setMaxMana(int maxMana);
	~Archer();
      //Constructor for subclass knight
		Archer(int maxHP, int lvl, int maxMana, string name): Player(maxHP,lvl, maxMana,name)
		{
			dmg = 1;
			def = 1;
      			className = "Archer";
		}

};

/*
The knight subclass
Tip:If you try and use a skill you cannot actually use because of lack of mana/level, it return's -1, so check for that in combat
*/
class Caster : public Player
{


	//Define a bunch of extra skill methods and stats
	private:
		int dmg = 0;
		int def = 0;
    		string className;

	public:
		//skills
		int skill1();
		int skill2();
		int skill3();
		int skill4();

      //inheritance
		int getHealth();
  		void setHealth(int hp);
  		int getMaxHP();
		void setMaxHP(int hp);
  	  	void lvlUp(int floorLevel);
  		string getName();
  		int getLvl();
		void setLvl(int lvl);
		string getClass();
		int getDmg();
		void setDmg(int dmg);
		int getDef();
		void setDef(int def);
		int getCurMana();
		int getMaxMana();
		void setCurMana(int mana);
		void setMaxMana(int maxMana);
	~Caster();
      //Constructor for subclass knight
		Caster(int maxHP, int lvl, int maxMana, string name): Player(maxHP,lvl, maxMana,name)
		{
			dmg = 2;
			def = 1;
      			className = "Caster";
		}

};


//If we use this, we can turn this into selecting a class to spawn

/*
void chooseClass(Player* player, String* class)
{
	int classDecision = 0;
	//Force the player to input a correct input that leads to a valid class which is set with a seperate method.
	while((classDecision < 1) || (classDecision > 3) || (int(classDecision) != classDecision))
	{
		cout << "What class will you choose? Will you be a Knight[1], a Caster[2], or an Archer	[3]?" << endl;
		cin >> 	classDecision;
		switch(classDecision)
		{
		case 1:
			player.setKnightClass();
			break;
		case 2:
			player.setCasterClass();
			break;
		case 3:
			player.setArcherClass();
			break;
		default:
			cout << "Please choose one of the classes available!" << endl;
		}
	}
}
*/

#endif
