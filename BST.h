#include<iostream>
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class BST {
private:

    Node* root;
    int nextId;      
    int comparisons;  


    void printEvent(const Event& e) const;
    Node* insertRec(Node* node, const Event& e, int& comp);
    Node* searchRec(Node* node, int ts, int& comp) const;
    Node* minValueNode(Node* node) const;
    Node* deleteRec(Node* node, int ts, int& comp);
    void inorderRec(Node* node) const;
    void rangeRec(Node* node, int t1, int t2, vector<Event>& res, int& comp) const;
    void findClosestHelper(Node* node, int t, Event& closest, int& minDiff, int& comp) const;
    void countCatRec(Node* node, int t1, int t2,vector<string>& cats, vector<int>& counts, int& comp) const;
    int  heightRec(Node* node) const;
    void depthSumRec(Node* node, int depth, long long& sum, int& cnt) const;
   

public:
    BST(){
        root = nullptr;
        nextId = 1;
        comparisons = 0;
    };
    void insert(int timestamp, const string& category, const string& description);
    void remove(int timestamp);
    void search(int timestamp) const;
    void showAllInOrder() const;

    void getEventsBetween(int t1, int t2) const;
    void findClosest(int t) const;
    void countCategories(int t1, int t2) const;

    void showStatistics() const;
};
// Basic Functions:

void BST::printEvent(const Event& e) const {
    cout << "ID: "<< e.id<< endl;
    cout << "Time: "<< e.timestamp<< endl;
    cout << "Cat: "<< e.category<< endl;
    cout << "Desc: "<< e.description<< endl;
}
//--------------------------------------------------------------------------------
// insert 
void BST::insert(int timestamp, const string& category, const string& description) {
    Event e(nextId++, timestamp, category, description);
    
    comparisons = 0;
    root = insertRec(root, e, comparisons);
    cout <<"Added (ID): "<<e.id<<" , comparisons: "<<comparisons<<endl;
}
Node* BST::insertRec(Node* node, const Event& e, int& comp) {
    if (node == nullptr) {
        Node *temp = new Node(e);
        return temp;
    }
    
    comp++; 
    
    if (e.timestamp < node->data.timestamp) {
        node->left = insertRec(node->left, e, comp);
    } else {
        node->right = insertRec(node->right, e, comp);
    }
    
    return node;
}
//--------------------------------------------------------------------------------
// search
void BST::search(int timestamp) const {
    int comp = 0;
    Node* found = searchRec(root, timestamp, comp);
    
    if (found) {
        cout<<"End"<<endl;
        printEvent(found->data);
    } else {
        cout <<"Not found"<<endl;
    }
    cout<<"comparisons: "<<comp<<endl;
}
Node* BST::searchRec(Node* node, int ts, int& comp) const {
    if (node == nullptr) {
        return nullptr;
    }
    
    comp++;
    
    if (ts == node->data.timestamp) {
        return node;
    }
    
    if (ts < node->data.timestamp) {
        return searchRec(node->left, ts, comp);
    }
    
    return searchRec(node->right, ts, comp);
}
//--------------------------------------------------------------------------------
// delete
void BST::remove(int timestamp) {
    comparisons = 0;
    root = deleteRec(root, timestamp, comparisons);
    cout<<"Deleted - "<<"comparisons: "<<comparisons<<endl;

}
Node* BST::deleteRec(Node* node, int ts, int& comp) {
    if (node == nullptr){
         return node;
    }
    
    comp++;
    
    if (ts < node->data.timestamp) {
        node->left = deleteRec(node->left, ts, comp);
    }
    else if (ts > node->data.timestamp) {
        node->right = deleteRec(node->right, ts, comp);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        
        
        Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteRec(node->right, temp->data.timestamp, comp);
    }
    
    return node;
}
Node* BST::minValueNode(Node* node) const {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}
//--------------------------------------------------------------------------------
// inorder
void BST::showAllInOrder() const {
    if (root == nullptr) {
        cout<<"The Tree is empty"<<endl;
        return;
    }
    cout<<"Event in chronological order"<<endl;
    inorderRec(root);
}
void BST::inorderRec(Node* node) const {
    if (node) {
        inorderRec(node->left);
        printEvent(node->data);
        inorderRec(node->right);
    }
}