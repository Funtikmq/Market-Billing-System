#include <limits>
#include <iostream>
#include "Bill.h"
#include <chrono>

using namespace std;

int main(){
    auto start = chrono::steady_clock::now();
    Bill bill;
    bool exit = false;
    while(!exit){
        int val;
        cout << "Welcome to Supermarket Billing System"<< endl;
        cout << "**************************************"<< endl;
        cout << "1.Add Item"<< endl;
        cout << "2.Print Bill"<< endl;
        cout << "3.Exit"<< endl;
        cout << "Enter Your Choice:"<<endl;
        while(!(cin>>val)){
            cerr<<"Invalid input. Please enter 1,2 or 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        switch (val) {
            case 1:
                bill.addItem(&bill);
                break;
            case 2:
                bill.printBill();
                break;
            case 3: exit=true;
                break;
            default:cerr<<"There is no such a option!"<<endl;
                break;
        }
    }
}

