/**
*Created By: Dylan Alvarez
*Contains:The methods that go with the classes defined by the Character_Creation_H
*/

#include "CharacterCreation.h"

//Defining the methods inherited from the abstract Player class, Mutator and Accessor Methods
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
/*This method increases the stats of the player when he levels up.
*@param floolLevel is the floor that the player levels up on 
*/
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


//Defining the methods inherited from the abstract Player class, Mostly consists of mutator and accessor methods
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
/*This method increases the stats of the player when he levels up.
*@param floolLevel is the floor that the player levels up on 
*/
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


//Defining the methods inherited from the abstract Player class, mostly consists of mutator and accessor methods
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
/*This method increases the stats of the player when he levels up.
*@param floolLevel is the floor that the player levels up on 
*/
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

