#pragma once
#include <iostream>
#include <time.h>

#pragma warning(disable:4996)

using namespace std;


class GetTime {
public:
    GetTime();
    void gotTime();
    int hour;
    int minute;
    int second;
};

