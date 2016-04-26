#pragma once
#include "QuestGetter.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;


class GetSave
{
public:
    GetSave();
    void saveQuest(string Quest, string questFile);
    void saveTimeHour(string Hour, string hourFile);
    void saveTimeMin(string Min, string minFile);
    void loadQuestFile(string Quest, string questFileLoad);
    void loadHourFile(string hourFileLoad);
    void loadMinFile(string Minute, string minFileLoad);
    
    string pausing;
};


