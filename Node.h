#include<iostream>
#include"Event.h"
using namespace std;
class Node {
public:
    Event data;
    Node* left;
    Node* right;
    Node(Event e){
        data = e;
        left = nullptr;
        right = nullptr;
    }
};
