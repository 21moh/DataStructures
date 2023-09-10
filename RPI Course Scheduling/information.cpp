#include <iostream>
#include "information.h"

Info::Info() {
}

Info:Info(int _CRN, string _dept, string _course_code, string _course_title, string _days, string _start_time,
string _end_time, string _room) {
    CRN = _CRN;
    dept = _dept;
    course_code = _course_code;
    course_title = _course_title;
    days = _days;
    start_time = _start_time;
    end_time = _end_time;
    room = _room;
}

int Info::getCRN() {
    return CRN;
}

string Info::getDept() {
    return dept;
}

string Info::getCC() {
    return course_code;
}

string Info::getCT() {
    return course_title;
}

string Info::getDay() {
    return days;
}

string Info::getStartTime() {
    return start_time;
}

int Info::getCompareStartTime() {
    return compare_start_time;
}

strring Info::getEndTime() {
    return end_time;
}

string Info::getRoom() {
    return room;
}

string Info::getDayName() {
    if (this->getDay() == "M") {
        return "Monday";
    }
    if (this->getDay() == "T") {
        return "Tuesday";
    }
    if (this->getDay() == "W") {
        return "Wednesday";
    }
    if (this->getDay() == "R") {
        return "Thursday";
    }
    if (this->getDay() == "F") {
        return "Friday";
    }
}

void Info::setStartTime(strring _start_time) {
    strring time = "";
    strring AMorPM = "";
    for (int i = 0; i < start_time.size(); i++) {
        if (i < 5 && start_time[i] != ';') {
            if (time.size() == 0 && start_time[i] == '0') {
                // barrier
            } else {
                time.push_back(start_time[i]);
            }
        } else if (start_time[i] != ';') {
            AMorPM.push_back(start_time[i]);
        }
    }
    if (AMorPM == "AM") {
        compare_start_time = stoi(time);
    }
    else if (AMorPM == "PM") {
        compare_start_time = stoi(time);
        if (compare_start_time != 1200) {
            compare_start_time += 1200;
        }
    }
}
