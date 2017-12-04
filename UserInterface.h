#ifndef UserInterface_h
#define UserInterface_h
using namespace std;
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include "FloorDesign.h"
#include "CharacterCreation.h"
//#include "MonsterGeneration.h"



class UserInterface {
private:
   // int selectionNum;
    int storyPart;

public:

    //Creates the story and accesses different parts
    bool createStory ();
    int getStoryPart ();
    void setStoryPart (int part);
    void finishLvl(int part);
    void beginEnd(int x);
    void elipsis();
    void opener(const string& message);
    void lag(int n);



};


#endif
