#include<iostream>
#include<string>
#include<limits>
#include"BST.h"

using namespace std;
int main()
{
    BST tree;               

    int choice;           
    int ts, t1, t2;         
    string cat, desc;  
    
    
    tree.insert(1,"a1","1_a1");
    tree.insert(2,"a2","2_a2");
    tree.insert(3,"a3","3_a3");
    tree.insert(4,"a4","4_a4");
    tree.insert(5,"a5","5_a5");
    tree.insert(6,"a6","6_a6");
    tree.insert(7,"a7","7_a7");



    

    while (true)            
    {
        cout << "1. Insert event\n";
        cout << "2. Delete event\n";
        cout << "3. Search by timestamp\n";
        cout << "4. Show events in time range\n";
        cout << "5. Find closest event\n";
        cout << "6. Show tree statistics\n";
        cout << "7. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        

        if (choice == 1)
        {
            cout<<"|| insert ||"<<endl;
            cout << "Timestamp: ";   
            cin >> ts;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Category: ";   
            getline(cin, cat);
            cout<<endl;
            cout << "Description: ";
            getline(cin, desc);
            tree.insert(ts, cat, desc);
        }
        else if (choice == 2)
        {
            cout <<"|| remove ||"<<endl;
            cout <<"Timestamp: "<<endl;
            cin >> ts;
            tree.remove(ts);
        }
        else if (choice == 3)
        {
            cout <<"|| search ||"<<endl;
            cout << "Timestamp: ";
            cin >> ts;
            tree.search(ts);
        }
        else if (choice == 4)
        {
            cout <<"|| get Event Between(t1 to t2) ||"<<endl;
            cout <<"start: ";
            cin >> t1;
            // cout<<endl;
            cout <<"end: ";
            cin >> t2;
            tree.getEventsBetween(t1, t2);
        }
        else if (choice == 5)
        {
            cout <<"|| find Closest ||"<<endl;
            cout <<"time? :";
            cin >> ts;
            tree.findClosest(ts);
        }
        else if (choice == 6)
        {
            cout <<"|| show statistice ||"<<endl;
            tree.showStatistics();
        }
        else if (choice == 7)
        {
            break;       
        }
        else if(choice == 8){
            tree.showAllInOrder();
        }
        else if(choice == 9){
            int t1;
            cin>>t1;
            int t2;
            cin>>t2;
            tree.countCategories(t1,t2);
        }
        else
        {
            cout <<"please choose the correct number!!";
        }

        cout <<endl;
    }
    cout<<"Thank you, Good luke";

    return 0;
}





