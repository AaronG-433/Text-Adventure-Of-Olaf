/*
 /*
 * CombatSystem.h
 *
 *  Created on: Nov 30, 2017
 *      Author: Owner
 */


using namespace std;
#include <iostream>
#include <string>
#include <sstream>		//imports the stringstream function
#include <cctype>		//imports the isspace() function
#include "CharacterCreation.h"
#include "CharacterCreation.cpp"
#include "MonsterGeneration.h"
#include "MonsterGeneration.cpp"


class CombatSystem {
public:
	CombatSystem();
	virtual ~CombatSystem();
};
