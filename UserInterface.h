#ifndef UserInterface_h
#define UserInterface_h
using namespace std;
#include <string.h>

class UserInterface {
private:
    int selectionNum;
    int storyPart;
    
public:
    
    //Creates the story and accesses different parts
    void createStory ();
    int getStoryPart ();
    void setStoryPart (int part);

};


#endif
