#include "QuestGetter.h"
#include <iostream>
#include <string>
#include <list>

#include "GetTime.h"

using namespace std;

QuestGetter::QuestGetter() {
    
}

void QuestGetter::Run() {
    GetSave getsave;
    tickerQuestName = 0;
    tickerHourName = 0;
    tickerMinName = 0;
    tickerQuestNameLoad = 0;
    tickerHourNameLoad = 0;
    tickerMinNameLoad = 0;
    
    questSetup();
    
}


void QuestGetter::loadQuest() {
    /*GetSave getsave;
     
     cout << "Which quest would you like to load?\n";
     cin >> questFileNumber;
     string theQuestFileNumber = to_string(questFileNumber);
     string theQuestFileLoad = "Quest" + theQuestFileNumber + ".txt";
     
     cout << "\n";
     
     getsave.loadQuestFile(Quest, theQuestFileLoad);
     
     cout << "\nFiles Loaded... \n\n";*/
    timeChecker();
    
}



void QuestGetter::initQuest() {
    GetSave getsave;
    
    cout << "Would you like to load in quest files?\n";
    cin >> loadfile;
    if (loadfile == "Yes" || loadfile == "YES" || loadfile == "yes") {
        timeChecker();
    }
    else if (loadfile == "No" || loadfile == "NO" || loadfile == "no") {
        getQuest();
        getTimeHour();
        getTimeMin();
    }
}
void QuestGetter::questSetup() {
    initQuest();
    while (true) {
        
        cout << "Is there another quest you would like to enter? Type 'yes' or 'no'.\n";
        cin >> answer;
        if (answer == "no") {
            timeChecker();
        }
        else if (answer == "Yes" || answer == "yes") {
            
            getQuest();
            getTimeHour();
            getTimeMin();
        }
    }
}
void QuestGetter::timeChecker() {
    int x;
    x = 0;
    string line;
    while (true) {
        GetTime time;
        GetSave getsave;
        string filepath;
        filepath = "Quests\\";
        x += 1;
        string x2 = to_string(x);
        
        
        string theHourFileLoad2 = filepath +  "Hour" + x2 + ".txt";
        string theQuestFileLoad2 = filepath + "Quest" + x2 + ".txt";
        string theMinFileLoad2 = filepath + "Minute" + x2 + ".txt";
        
        string hourfileload = theHourFileLoad2;
        string minfileload = theMinFileLoad2;
        string questfileload = theQuestFileLoad2;
        
        string linehour;
        string lineminute;
        string linequest;
        
        
        ifstream myfilereadHour;
        myfilereadHour.open(hourfileload);
        ifstream myfilereadMinute;
        myfilereadMinute.open(minfileload);
        ifstream myfilereadQuest;
        myfilereadQuest.open(questfileload);
        
        
        int realHour1 = time.hour;
        int realMinute1 = time.minute;
        if (realHour1 >= 13) {
            realHour1 = 12;
        }
        string realHour = to_string(realHour1);
        string realMinute = to_string(realMinute1);
        
        //cout << realHour << ":" << realMinute << endl << endl;
        if (myfilereadHour.is_open()) {
            myfilereadHour >> linehour;
            cout << realHour << "-----------------This is The hour the computer is reading.";
            cout << linehour << "-----------------This is The hour the file is reading.";
            
            if (linehour == realHour) {
                if (myfilereadMinute.is_open()) {
                    myfilereadMinute >> lineminute;
                    if (lineminute == realMinute) {
                        if (myfilereadQuest.is_open()) {
                            getline(myfilereadQuest, linequest);
                            cout << linequest << "\n\n\n";
                            cin >> pausing;
                            
                        }
                        if (myfilereadQuest.fail()) {
                            x = 0;
                        }
                    }
                }
                if (myfilereadMinute.fail()) {
                    x = 0;
                }
            }
            
        }
        if (myfilereadHour.fail()) {
            x = 0;
        }
    }
}

void QuestGetter::getQuest() {
    GetSave getsave;
    cout << "Enter the Quest you would like to give:\n";
    cin.ignore();
    
    getline(cin, Quest);
    fileCreateQuest();
    getsave.saveQuest(Quest, questFile);
}

void QuestGetter::getTimeHour() {
    GetSave getsave;
    cout << "Enter the hour you want the quest displayed:\n";
    cin >> displayHour;
    cout << "Is this AM or PM?\n";
    cin >> AMorPM;
    if ((AMorPM == "PM" || AMorPM == "pm") && displayHour != 12) {
        displayHour = displayHour + 12;
    }
    string Hour = to_string(displayHour);
    fileCreateHour();
    getsave.saveTimeHour(Hour, hourFile);
    
}

void QuestGetter::getTimeMin() {
    GetSave getsave;
    cout << "Enter the minute of that hour that you want the quest to be displayed:\n";
    cin >> displayMinute;
    string Minute = to_string(displayMinute);
    fileCreateMin();
    getsave.saveTimeMin(Minute, minFile);
}


void QuestGetter::fileCreateQuest() {
    
    Boolean = true;
    while (Boolean == true) {
        tickerQuestName += 1;
        string questNumber = to_string(tickerQuestName);
        string filepath;
        filepath = "Quests\\";
        
        questFile = filepath + "Quest" + questNumber + ".txt";
        Boolean = false;
    }
}

void QuestGetter::fileCreateHour() {
    
    Boolean = true;
    while (Boolean == true) {
        tickerHourName += 1;
        string hourNumber = to_string(tickerHourName);
        string filepath;
        filepath = "Quests\\";
        
        hourFile = filepath + "Hour" + hourNumber + ".txt";
        Boolean = false;
    }
}

void QuestGetter::fileCreateMin() {
    
    Boolean = true;
    while (Boolean == true) {
        tickerMinName += 1;
        string minNumber = to_string(tickerMinName);
        string filepath;
        filepath = "Quests\\";
        
        minFile = filepath + "Minute" + minNumber + ".txt";
        Boolean = false;
    }
}

void QuestGetter::fileLoadQuest() {
    
    Boolean = true;
    while (Boolean == true) {
        tickerQuestNameLoad += 1;
        string questNumberLoad = to_string(tickerQuestNameLoad);
        string filepath;
        filepath = "Quests\\";
        
        questFileLoad = filepath + "Quest" + questNumberLoad + ".txt";
        Boolean = false;
    }
}

void QuestGetter::fileLoadHour() {
    
    Boolean = true;
    while (Boolean == true) {
        tickerHourNameLoad += 1;
        string hourNumberLoad = to_string(tickerHourNameLoad);
        string filepath;
        filepath = "Quests\\";
        
        hourFileLoad = filepath + "Hour" + hourNumberLoad + ".txt";
        Boolean = false;
    }
}

void QuestGetter::fileLoadMin() {
    
    Boolean = true;
    while (Boolean == true) {
        tickerMinNameLoad += 1;
        string minNumberLoad = to_string(tickerMinNameLoad);
        string filepath;
        filepath = "Quests\\";
        
        minFileLoad = filepath + "Minute" + minNumberLoad + ".txt";
        Boolean = false;
    }
}
