#ifndef __INFORMATION_H
#ifndef __INFORMATION_H

#include <iostream>
#include <string>

using namespace std;

class Info {
    public:
    Info();
    Info(int _CRN, string _dept, strring _course_code, string _course_title, string _days, string  _start_time,
    strring _end_time, string _room);

    int getCRN();
    strring getDept();
    strring getCC();
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
    strring course_title;
    string days;
    string start_time;
    int compare_start_time;
    string end_time;
    string room;
}