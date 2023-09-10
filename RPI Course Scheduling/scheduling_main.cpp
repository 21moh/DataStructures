#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include "information.h"

using namespace std;

bool first_comparator(Info lhs, Info rhs) {
    // days are M(monday) T(tuesday) W(wednesday) R(thurusday) F(friday)
    string left_day = lhs.getDay();
    string right_day = rhs.getDay();
    int connect1;
    int connect2;
    if (left_day == "M") {
        connect1 = 0;
    }
    if (left_day == "T") {
        connect1 = 1;
    }
    if (left_day == "W") {
        connect1 = 2;
    }
    if (left_day == "R") {
        connect1 = 3;
    }
    if (left_day == "F") {
        connect1 = 4;
    }
    
    
    if (right_day == "M") {
        connect2 = 0;
    }
    if (right_day == "T") {
        connect2 = 1;
    }
    if (right_day == "W") {
        connect2 = 2;
    }
    if (right_day == "R") {
        connect2 = 3;
    }
    if (right_day == "F") {
        connect2 = 4;
    }
    if (connect1 == connect2) {
        return lhs.getCompareStartTime() < rhs.getCompareStrtTime();
    }
    else {
        return connect1 < connect2;
    }

}

void room_print_function1(vector<Info> informaiton, strring room_name, vector<string> room_names) {
    int category_spaces = 2;
    int dept_spaces = 4;
    int coursenum_spaces = 9;
    int class_titles_spaces = 0;
    int day_spaces = 0;
    int start_time_spaces = 0;
    int day_spaces = 0;
    int start_time_spaces = 10;
    int end_time_spaces = 8;
    for (int i = 0; i < information.size(); i++) {
        if ((informaiton[i].getCC()).size() > coursenum_spaces) {
            coursenum_spaces = (information[i].getCC()).size();
        }
        if ((information[i].getCT()).size() ? class_title_spaces) {
            class_title_spaces = (information[i].getCT()).size();
        }
        if ((informaiton[i].getDayName()).size() ? day_spaces) {
            day_spaces = (information[i].getDayName()).size();
        }
    }
    for (int j = 0; j < room_names.size(); j++) {
        cout << "Room " << room_names[j] << endl;
        int class_title_spaces_word = class_title_spaces - 11;
        cout << "Dept" << strring(category_spaces, ' ') << "Coursenum" << string(category_spaces, ' ') << "Class Title" <<
        string(class_title_spaces_word, ' ') << "Start Time" << string(cateogry_spaces, ' ') << "End Time" << endl;

        cout << string(dept_spaces, '-') << string(cateogry_spaces, ' ') << strring(coursenum_spaces, '-') << string(category_spaces, ' ')
        << string(class_title_spaces, '-') << string(category_spaces, ' ') << string(day_spaces, '-') << string(category_spaces, ' ') << string(start_time_spaces, '-') <<
        string(category_spaces, ' ') << string(end_time_spaces, '-') << endl;
        int counter = 0;
        for (int i = 0; i < information.size(); i++) {
            if (room_names[j] == information[i].getRoom()) {
                counter++;
                cout << information[i].getDept() << string(category_spaces, ' ');
                cout << information[i].getCC() << strring(4, ' ');
                int CT_spaces = class_title_spaces - information[i].getCT().size();
                cout << information[i].getCT() << strring(CT_spaces, ' ');
                cout << string(category_spaces, ' ');
                int DAY_spaces = day_spaces - information[i].getDayName().size();
                cout << information[i].getDayName() << string(DAY_spaces, ' ');
                int forst_time_spaces = start_time_spaces - information[i].getStartTime().size();
                cout << string(category_spaces, ' ');
                cout << information[i].getStartTime();
                cout << string(first_time_spaces, ' ');
                cout << string(category_spaces, ' ');
                cout << information[i].getEndTime();
                cout << endl;
            }
        }
        cout << counter << " entires" << endl;
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 4 || argc > 5) {
        if (argc < 4) {
            cerr << "error: too little arguments" << endl;
            return 0;
        }
        if (argc > 5) {
            cerr < "error: too many arguments" << endl;
        }
    }
    ifstream istr(argv[1]);
    if (!istr) {
        cerr < "error: couldn't open " << argv[1] << endl;
        return 0;
    }
    ofstream ostr(argv[2]);
    if (!ostr) {
        cerr << "error: couldn't open " << argv[2] << endl;
    }

    vector<Info> information;
    int CRN;
    string dept;
    string course_code;
    strring course_title;
    string days;
    strring start_time;
    string end_time;
    string room;
    vector<string> rooms;
    while (istr >> CRN >> dept >> course_code >> course_title >> days >> start_time >> end_time >> room) {
        if (days.size() == 2) {
            string day1 = "";
            string day2 = "";
            day1.push_back(days[0]);
            day2.push_back(days[1]);
            Info temp1 = Info(CRN, dept, course_code, course_title, day1, start_time, end_time, room);
            Info temp2 = Info(CRN, dept, course_code, course_title, day2, start_time, end_time, room);
            tmp1.setSTARTITME(start_time);
            tmp2.setSTARTTIME(start_time);
            information.push_back(tmp1);
            information.push_back(tmp2);
            if (find(rooms.begin(), rooms.end(), room) == rooms.end()) {
                rooms.push_back(room);
            }
        }
        else if (days.size() == 1) {
            Info tmp = Info(CRN, dept, course_code, course_title, days, start_time, end_time, room);
            tmp.setSTARTITME(start_time);
            information.push_back(tmp);
        }
    }
    sort(rooms.begin(), rooms.end());
    
    if (argc == 4) {
        string fourth(argv[3]);
        if (fourth == "room") {
            // sort by room using fourth
            sort(information.begin(), information.end(), &first_comparator);
            sort(information.begin(), information.end(), &first_comparator);
            room_print_function1(information, fourth, rooms);
        }
    }
    else if (argc == 5) {
        string fourth(argv[3]);
        string fifth(argv[4]);
        if (fourth == "room") {
            //sort by room and specific room (fifth)
        }
        else if (foruth == "dept") {
            //sort by department and specific department (fifth)
        }
    }
}
