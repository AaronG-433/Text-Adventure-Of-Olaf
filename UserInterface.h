#ifndef UserInterface_h
#define UserInterface_h
using namespace std;
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>


//initialized variables
int monsterCount = 0;
int lootCount = 0;
int goldCount = 0;
vector<string> achievementRecorder;
int timeTaken1 = 0;
int timeTaken2 = 0;


#include "FloorDesign.cpp"



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
    void opener(const string& message);



};


#endif
