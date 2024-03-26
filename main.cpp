#include <iostream>
#include <fstream>
#include <sstream>
#include "Bill.h"

using namespace std;



int main(){
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
        cin>>val;
        switch (val) {
            case 1:
                bill.addItem(bill);
                break;
            case 2:
                bill.printBill();
                break;
            case 3: exit=true;
                break;
            default:cout<<"There is no such a option!";
                break;
        }
    }
}

