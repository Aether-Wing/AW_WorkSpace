#include "GetTime.h"
GetTime::GetTime() {
    gotTime();
}

void GetTime::gotTime() {
    time_t now;
    struct tm *now_tm;
    
    
    now = time(NULL);//
    now_tm = localtime(&now);
    hour = now_tm->tm_hour;
    minute = now_tm->tm_min;
    second = now_tm->tm_sec;
    
}