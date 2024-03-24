#include <iostream>
#include <fstream>
#include <sstream>
#include "Bill.h"

using namespace std;

void clearScreen(){
    for(int i=0;i<10;i++){
        cout<< endl;
    }
}

void addItem(Bill b){
    bool close=false;
    while(!close){
        int choice;
        cout<<"\t1.Add"<<endl;
        cout<<"\t2.Close"<<endl;
        cout<<"\tEnter Choice:";
        cin>>choice;

        if(choice==1){
            string item;
            int rate,quantity;
            cout << "Enter Item's Name: "<< endl;
            cin.ignore();
            getline(cin,item);
            b.setItem(item);
            cout << "Enter Item's Rate: "<< endl;
            cin >> rate;
            b.setRate(rate);
            cout << "Enter Item's Quantity: "<< endl;
            cin >> quantity;
            b.setQuantity(quantity);

            ofstream out("C:\\Facultate\\C++\\Market-Billing-System\\bills.txt",ios::app);
            if(!out){
                cout<<"File Can't Be Openned!";
            }
            else{
            out<<b.getItem()<<" "<<b.getRate()<<" "<<b.getQuantity()<<endl;
            }
            out.close();
        cout<<"Item Were Added To the DataBase"<< endl;
        }
        else if(choice==2){
            close=exit;
            clearScreen();
            cout<<"Back to Main Menu";
        }

    }
}

int main(){
    Bill bill("bread",2,1);

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
                addItem(bill);
                break;
            case 2:
                break;
            case 3: exit=true;
                break;
            default:cout<<"There is no such a option!";
                break;
        }
    }
}

