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
		virtual void lvlUp() = 0;
		virtual string getClass() = 0;
		virtual string getName() = 0;
		virtual int getLvl() = 0;
    		virtual int getDmg() = 0;
    		virtual int getDef() = 0;
   		virtual int getCurMana() = 0;
   		virtual void setCurMana(int mana) = 0;
    		virtual int getMaxMana() = 0;
    		virtual void setLvl(int lvl) = 0;

		//virtual ~Player() = 0;
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

		int curHP = 20;
		int maxHP = 20;
		int lvl = 1;
		int curMana = 10;
		int mana = 10;
		string name;
    		int maxMana = 10;
		vector<string> achievementRecorder;

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
		int styleishSpin();
		int shieldBash();
		int demacianJudgement();
		int foolishCourage();
      //inheritance
     		int getHealth();
  		void setHealth(int hp);
  		int getMaxHP();
		void setMaxHP(int hp);
  		void lvlUp();
  		string getName();
  		int getLvl();
      		void setLvl(int lvl);
      		string getClass();
      		int getDmg();
      		int getDef();
      		int getCurMana();
      		int getMaxMana();
      		void setCurMana(int mana);
	//~Knight();
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
      		int snipe();
  		int luckyShot();
  		int hailMary();
  		int oneInAMillion();
      //inheritance
      		int getHealth();
  		void setHealth(int hp);
  		int getMaxHP();
		void setMaxHP(int hp);
  	 	void lvlUp();
  		string getName();
  		int getLvl();
      		void setLvl(int lvl);
      		string getClass();
      		int getDmg();
      		int getDef();
		int getCurMana();
      		int getMaxMana();
      		void setCurMana(int mana);
	//~Archer();
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
      		int balefulStrike();
  		int darkMatter();
  		int eventHorizon();
  		int primordialBurst();
      //inheritance
      		int getHealth();
  		void setHealth(int hp);
  		int getMaxHP();
		void setMaxHP(int hp);
  	  	void lvlUp();
  		string getName();
  		int getLvl();
      		void setLvl(int lvl);
      		string getClass();
      		int getDmg();
      		int getDef();
		int getCurMana();
      		int getMaxMana();
      		void setCurMana(int mana);
	//~Caster();
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
int main()
{

  cout << "Program ran" << endl;
	Archer *archer = new Archer(10, 5, 10, "olaf");
	cout << archer->getDmg() << endl;
	cout << archer->luckyShot() << endl;
	cout << archer->getCurMana() << endl;
	archer->lvlUp();
	cout << archer->getLvl() << endl;


}
#endif
