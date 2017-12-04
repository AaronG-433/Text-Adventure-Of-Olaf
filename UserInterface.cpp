
#include "UserInterface.h"




int monsterCount = 0;
int lootCount = 0;
int goldCount = 0;
vector<string> achievementRecorder;
int timeTaken1 = 0;
int timeTaken2 = 0;

Player* chooseClass() {

	cout << "Choose your class:\n1: Archer\n2: Caster\n3: Knight" << endl;
	string choice = "";
	int intChoice = 0;


	//Needs to be idiot proofed
	cin >> choice;
	intChoice = intCheck(choice);


	Player *hero;
	switch (intChoice) {
	case 1:
		hero = new Archer(10, 1, 10, "");
		break;
	case 2:
		hero = new Caster(10, 1, 10, "");
		break;
	case 3:
		hero = new Knight(10, 1, 10, "");
		break;
	default:
		cout << "Invalid Input!" << endl;
	}
	achievementRecorder.push_back("Character Created - Doing the bare minimum");


	return hero;
}

bool UserInterface:: createStory () {
    int part = this->storyPart;
    string partc;
    Player* hero;
    Floor* floor;
    //Use after character creation in story.
    if (part == 0) {
        cout << "You lay awake on a stone cold floor in a dank, lifeless dungeon. Your mind stirs for you name...\n\nEnter c to continue.\n\n";

        while (partc != "c") {
            cin >> partc;
            if (partc == "c") {
            	hero = chooseClass();
            	cout << hero->getName() << ", yes, that's it..\n\nEven with your name remembered, there still lies a thick fog over your memory as you take your first steps into the dimly lit darkness ahead." << endl;
            }
            else {
                cout << "Press c to clear your mind.\n\n";
            }
        }
        partc = " ";
    }

    //Use on first monster encounter.
    if (part == 1) {
    	string parta = "";
    	cout << "\n\nYou feel a cool breeze which you decide to follow.\nAs the gusts become more forceful, you spot a spiralling passage into your grim future";
    	elipsis();
    	cout << "\n\nEnter c to continue.\n" << endl;
    	while (parta != "c") {
    		cin >> parta;
    	    if (parta == "c") {
    	    	cout << "\nYour hands and face become cold as you move by feeling along the wall for guidance.\nYou finally reach the end only to find another dimly lit room.\nWith a heart full of fear, you attempt to peer through the veil of darkness.\n\n" << endl;
    	        lag(20);

    	    }
    	    else {
    	    	cout << "\nEnter c to encounter your fate.\n" << endl;
    	    }
    	}
    	parta = " ";
    	//cout << "Test2 Floor 1" << endl;
    	floor = new Floor(1, hero);
    	if(!floor->run()) {
    		return false;
    	}

        cout << "\n\nSomething lurks in the shadows.. A MONSTER STRIKES!? What hellish nightmare is this? As your panic heightens, as does a surge of energy through your veins. You remember your years training. Kill or be killed.\n\n";
    }
    //Use after first level.
    if (part == 2) {
    	string parta = "";
    	 cout << "\n\nYou feel power flowing through your veins.\nA surge of excitement takes over as you plunge into the shadows ahead.\n\nEnter c to have your confidence shattered.\n" << endl;
    	            while (parta != "c") {
    	                cin >> parta;
    	                if (parta == "c") {
    	                    cout << "\nYou trip on the only stone in the room and stub your toe.\nWith indescribable pain and embarrassment, you trudge onwards to face the inevitable hell that lies ahead.";
    	                    lag(20);
    	                    elipsis();
    	                    cout << "\n\n" << endl;
    	                }
    	                else {
    	                    cout << "\nEnter c to feel inadequate.\n" << endl;
    	                }
    	            }
    	        parta = " ";
    	floor = new Floor(2, hero);
    	if(!floor->run()) {
    		return false;
    	}
        cout << "";
    } else if (part == 3) {
    	string parta = "";
    	cout << "Searching your mind for any semblance of a memory, you faintly remember a family...\n Something is there. Something is blocking your memories.\nIt's not amnesia.. It's almost like a presence has hold of your consciousness";
    	        elipsis();
    	        cout << "\n\nEnter c to focus harder.\n\n" << endl;
    	            while (parta != "c") {
    	                cin >> parta;
    	                if (parta == "c") {
    	                    cout << "\nIt feels like your mind is drowning. You're trying to draw on anything.\nFamily, friends, everyone";
    	                    elipsis();
    	                    cout << " All gone. You don't remember why, but sadness takes over nonetheless.\nYou walk somberly through the unending darkness.\n\n" << endl;
    	                    lag(20);
    	                }
    	                else if (parta != "c"){
    	                    cout << "\nEnter c to focus your thoughts.\n" << endl;
    	                }
    	            }
    	        parta = " ";
    	floor = new Floor(3, hero);
    	if(!floor->run()) {
    	    		return false;
    	    	}
    } else if (part == 4) {
    	floor = new Floor(4, hero);
    	if(!floor->run()) {
    	    		return false;
    	    	}
    } else if (part == 5) {
    	floor = new Floor(5, hero);
    	if(!floor->run()) {
    	    		return false;
    	    	}
    }
    return true;
}

int UserInterface:: getStoryPart () {
    return this->storyPart;
}

void UserInterface:: setStoryPart (int part) {
    this->storyPart = part;
}

//*****ADDED******************
#include <cwchar>

//enter this after each level is finished for specified story part.
void UserInterface::finishLvl(int part) {

    int v = part;

    string parta;
    string partb;
    if (v == 0) {
//        cout << "\n\nYou feel a cool breeze which you decide to follow.\nAs the gusts become more forceful, you spot a spiralling passage into your grim future";
//        elipsis();
//        cout << "\n\nEnter c to continue.\n" << endl;
//            while (parta != "c") {
//                cin >> parta;
//                if (parta == "c") {
//                    cout << "\nYour hands and face become cold as you move by feeling along the wall for guidance.\nYou finally reach the end only to find another dimly lit room.\nWith a heart full of fear, you attempt to peer through the veil of darkness.\n\n" << endl;
//                    lag(20);
//
//                }
//                else {
//                cout << "\nEnter c to encounter your fate.\n" << endl;
//                }
//            }
//        parta = " ";
    }
    else if (v == 1) {
//        cout << "\n\nYou feel power flowing through your veins.\nA surge of excitement takes over as you plunge into the shadows ahead.\n\nEnter c to have your confidence shattered.\n" << endl;
//            while (parta != "c") {
//                cin >> parta;
//                if (parta == "c") {
//                    cout << "\nYou trip on the only stone in the room and stub your toe.\nWith indescribable pain and embarrassment, you trudge onwards to face the inevitable hell that lies ahead.";
//                    lag(20);
//                    elipsis();
//                    cout << "\n\n" << endl;
//                }
//                else {
//                    cout << "\nEnter c to feel inadequate.\n" << endl;
//                }
//            }
//        parta = " ";
    }
    else if (v == 2) {
//        cout << "Searching your mind for any semblance of a memory, you faintly remember a family...\n Something is there. Something is blocking your memories.\nIt's not amnesia.. It's almost like a presence has hold of your consciousness";
//        elipsis();
//        cout << "\n\nEnter c to focus harder.\n\n" << endl;
//            while (parta != "c") {
//                cin >> parta;
//                if (parta == "c") {
//                    cout << "\nIt feels like your mind is drowning. You're trying to draw on anything.\nFamily, friends, everyone";
//                    elipsis();
//                    cout << " All gone. You don't remember why, but sadness takes over nonetheless.\nYou walk somberly through the unending darkness.\n\n" << endl;
//                    lag(20);
//                }
//                else if (parta != "c"){
//                    cout << "\nEnter c to focus your thoughts.\n" << endl;
//                }
//            }
//        parta = " ";
    }
    else if (v == 3) {
        cout << "Exhausted and beaten, you see a light shining in the distance. Freedom? Safety?\nEven if you ended up in the bottom pits of hell, it would still be better than an endless life of whatever this was, you think";
        elipsis();
        lag(20);
            cout << "\n\nEnter c to complete your journey.\n" << endl;
            while (parta != "c") {
                cin >> parta;
                if (parta == "c") {
                    cout << "\nA completely empty room?";
                    elipsis();
                    cout << " This must be a mistake";
                    elipsis();
                    cout << " Whoever is controlling your fate must be toying with you for their amusement";
                    elipsis();
                    cout << "\n\nEnter c to focus your thoughts.\n" << endl;
                    while (partb != "c") {
                        cin >> partb;
                        if (partb == "c") {
                            cout << "\n\nColors shade in from the black ahead. You feel the light, but don't see it directly.\nWhatever is stopping your memory is also blocking your vision. But, soon, everything is revealed";
                            elipsis();
                            cout << "\n\n";
                        }
                        else {
                            cout << "\n\nEnter c to search your mind!" << endl;
                        }
                    }
                }
                else if (parta != "c") {
                    cout << "\nEnter c to finish this!\n\n" << endl;
                }
            }
        parta = " ";
    }
}

void UserInterface::elipsis() {
    for (int i = 0; i<3;i++) {
        cout << ".";
        lag(5);
    }
}

void UserInterface::opener(const string& message) {
    cout << message << endl;
}

//n = 5 for about 1 second and n = 15 for about 4 second break.
void UserInterface::lag(int n) {
    int j = 0;
    //50000000 for 125 millis

    for (int i = 0; i < 1*n; i++) {
        j++;
        j--;
    }
}

//********EXTRA EXTRA**********************
//title and credits
void UserInterface::beginEnd(int x) {
    if (x == 0) {
        cout << "========================================";
        cout << "\n\t";
        opener("THE ADVENTURES OF OLAF!\n");
        cout << "========================================\n\n";
    }
    if (x == 1) {
        cout << "\n\n";
        cout << "Achievements:" << endl;
        for(int i = 0; i < achievementRecorder.size(); i++) {
            cout << achievementRecorder.at(i) << endl;
        }
        cout << "Slain monsters: " << monsterCount << endl;
        cout << "Total gold pillaged: " << goldCount << endl;
        cout << "Total loot collected: " << lootCount << endl;
        cout << "Total time taken: " << timeTaken2 - timeTaken1 << " seconds." << endl;

        opener("\n\nCREDITS\n\n");
        cout << "User Interface:";
        opener(" Matthew Leonard\n\n");
        cout << "Character Creation:";
        opener(" Dylan Alvarez\n\n");
        cout << "Floor Design:";
        opener(" Alexander Jasper\n\n");
        cout << "Monster Creation:";
        opener(" Johnny Li\n\n");
        cout << "Combat System:";
        opener(" Aaron Gaskin");


    }
}



int main() {

	timeTaken1 = time(0);
	UserInterface UI;
	bool alive = true;
	int i = 0;
	UI.beginEnd(0);

	while(alive && i <= 5) {
		UI.setStoryPart(i);
		alive = UI.createStory();
		i++;

	}

	timeTaken2 = time(0);
    UI.beginEnd(1);
}
