#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

#include "GetSave.h"
#include "GetTime.h"

using namespace std;

class QuestGetter {
public:
    
    QuestGetter();
    void Run();
    void loadQuest();
    void getQuest();
    void questSetup();
    void timeChecker();
    
    void fileCreateQuest();
    void fileCreateHour();
    void fileCreateMin();
    
    
    void initQuest();
    void getTimeHour();
    void getTimeMin();
    
    void fileLoadQuest();
    void fileLoadHour();
    void fileLoadMin();
    
    bool Boolean;
    
    int tickerHourName;
    int tickerMinName;
    int tickerQuestName;
    int tickerQuestNameLoad;
    int tickerHourNameLoad;
    int tickerMinNameLoad;
    
    int displayHour;
    int displayMinute;
    
    int questFileNumber;
    
    string AMorPM;
    string Quest;
    string answer;
    string loadfile;
    string questFile;
    string hourFile;
    string minFile;
    string questFileLoad;
    string hourFileLoad;
    string minFileLoad;
    string pausing;
    
    
};
