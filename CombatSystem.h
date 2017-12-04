/*
 /*
 * CombatSystem.h
 *
 *  Created on: Nov 30, 2017
 *      Author: Aaron Gaskin
 */


using namespace std;
#include "CharacterCreation.cpp"
#include "MonsterGeneration.cpp"
#include <iostream>
#include <string>
#include <sstream>		//imports the stringstream function
#include <cctype>		//imports the isspace() function
//#include "CharacterCreation.h"
//#include "MonsterGeneration.h"


class CombatSystem {
public:
	CombatSystem();
	virtual ~CombatSystem();
};
