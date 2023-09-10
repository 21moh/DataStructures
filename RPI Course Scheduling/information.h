#ifndef __INFORMATION_H
#define __INFORMATION_H

#include <iostream>
#include <string>

using namespace std;

class Info {
    public:
    Info();
    Info(int _CRN, string _dept, string _course_code, string _course_title, string _days, string  _start_time,
    string _end_time, string _room);

    int getCRN();
    string getDept();
    string getCC();
    string getCT();
    string getDay();
    string getStartTime();
    int getCompareStartTime();
    string getEndTime();
    string getRoom();
    string getDayName();

    void setSTARTTIME(string _start_time);

private:
    int CRN;
    string dept;
    string course_code;
    string course_title;
    string days;
    string start_time;
    int compare_start_time;
    string end_time;
    string room;
};

#endif
