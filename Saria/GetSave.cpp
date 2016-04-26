#include "GetSave.h"

GetSave::GetSave()
{
    
    //"C:\\Users\\Rezniren\\Documents\\"
}

void GetSave::saveQuest(string Quest, string questFile) {
    
    string quest = Quest;
    string questfile = questFile;
    ofstream myfilewrite;
    myfilewrite.open(questfile);
    myfilewrite << quest;
    
    
}

void GetSave::saveTimeHour(string Hour, string hourFile) {
    
    string hour = Hour;
    string hourfile = hourFile;
    ofstream myfilewrite;
    myfilewrite.open(hourfile);
    myfilewrite << hour;
    
    
}

void GetSave::saveTimeMin(string Min, string minFile) {
    
    string min = Min;
    string minfile = minFile;
    ofstream myfilewrite;
    myfilewrite.open(minfile);
    myfilewrite << min;
    
}

// what does Quest do? I see what questFileLoad does, but what does Quest do? is is just a way of saving the line?
void GetSave::loadQuestFile(string Quest, string questFileLoad) {
    string quest = Quest;
    string questfileload = questFileLoad;
    string line;
    
    ifstream myfileread;
    myfileread.open(questfileload);
    if (myfileread.is_open())
    {
        while (getline(myfileread, line))
        {
            cout << line << '\n';
            quest = line;
            
            
        }
        myfileread.close();
    }
}
void GetSave::loadHourFile(string hourFileLoad) {
    
    string hourfileload = hourFileLoad;
    string line;
    //int thehour = 0;
    
    
    ifstream myfilereadHour;
    myfilereadHour.open(hourfileload);
    if (myfilereadHour.is_open()) {
        myfilereadHour >> line;
        
        
        //int thehour = stoi(hour);
        //cout << "hour: " << thehour << endl;
        myfilereadHour.close();
    }
    //return thehour;
    
}
void GetSave::loadMinFile(string Minute, string minFileLoad) {
    string min = Minute;
    string minfileload = minFileLoad;
    string line;
    
    ifstream myfilereadMin;
    myfilereadMin.open(minfileload);
    if (myfilereadMin.is_open()) {
        while (getline(myfilereadMin, line)) {
            cout << line << '\n';
            min = line;
        }
        myfilereadMin.close();
    }
}