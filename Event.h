#include<iostream>
using namespace std;

class Event {
public:
    int id;
    int timestamp;
    string category;
    string description;

    Event(){
        id = 0;
        timestamp = 0;
    }
    Event(int i, int ts, string cat, string des){
        id = i;
        timestamp = ts;
        category = cat;
        description = des;
    }
};
