/*
 * CharacterCreation.h
 *
 *  Created on: Nov 30, 2017
 *      Author: Owner
 */

#include <iostream>
#include <string>
using namespace std;
class Player
{
	//Any accessor methods, as well as the player constructor are here
	public:

		//General stats not depending on class
		virtual int getHealth() = 0;
		virtual void setHealth(int hp) = 0;
		virtual int getMaxHP() = 0;
		virtual void lvlUp() = 0;
		virtual string getClass();
		virtual string getName() = 0;
		virtual int getLvl() = 0;
		virtual int getDmg() = 0;
		virtual int getDef() = 0;
		virtual int getCurMana() = 0;
		virtual void setCurMana(int mana) = 0;
		virtual int getMaxMana() = 0;
		virtual void setLvl(int lvl) = 0;
		virtual ~Player();

	protected:

		Player ()
    	{
				this -> maxHP = 20;
				this -> lvl = 1;
				this -> maxMana = 10;
				cout << "What is the name of your character" << endl;
				cin >> this -> name;
    	}

	//These are the general player states

		int curHP = 20;
		int maxHP = 20;
		int lvl = 1;
		int curMana = 10;
		int mana = 10;
		string name;
		int maxMana = 10;

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
			string className = "";

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
  			~Knight();

  		//Constructor for subclass knight
		Knight(): Player()
		{
			dmg = 1;
			def = 2;
			className = "Knight";
		}

};

/*
The archer subclass
Tip:If you try and use a skill you cannot actually use because of lack of mana/level, it return's -1, so check for that in combat
*/
class Archer : public Player
{

	//Define a bunch of extra skill methods and stats
	private:
			int dmg = 0;
			int def = 0;
			string className = "";

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

			//Constructor for subclass knight
			Archer(): Player()
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
    string className = "";

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

      //Constructor for subclass knight
		Caster(): Player()
		{
			dmg = 2;
			def = 1;
      className = "Caster";
		}
};
