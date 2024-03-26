#include "Bill.h"
#include <iostream>
#include<fstream>
#include <sstream>
#include <limits>
using namespace std;


Bill::Bill(string item,double price,int quantity):item(item),price(price),quantity(quantity){}

void Bill::clearScreen(){
    for(int i=0;i<10;i++){
        cout<< endl;
    }
}
void Bill::setItem(string item) {this->item=item;}
void Bill::setPrice(double price) {this->price=price;}
void Bill::setQuantity(int quantity)  {this->quantity=quantity;}
string Bill::getItem() {return item;};
double Bill::getPrice() {return price;};
int Bill::getQuantity() {return quantity;};
void Bill::printBill() {
    remove("C:\\Facultate\\C++\\Market-Billing-System\\bill.txt");
    ofstream out("C:\\Facultate\\C++\\Market-Billing-System\\bill.txt",ios::app);
    if(!out){
        cerr << "Error: Could not open the file." <<endl;
    }

    bool close = false;
    bool found=false;
    int choice;
    double total = 0.0;
    while (!close) {
        cout << "1. Add Bill" << endl;
        cout << "2. Close Session" << endl;
        cout << "Enter Your Choice: " << endl;
        while (!(cin>>choice)) {
            cout << "Invalid input. Please enter 1 or 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (choice == 1) {
            ifstream in("C:\\Facultate\\C++\\Market-Billing-System\\inventory.txt");
            if (!in) {
                cerr << "Error: Could not open the file." << endl;
            }
            string line;
            getline(in,line);
            string item;
            int quantity;
            cout << "Enter Item: " << endl;
            cin.ignore();
            cin>>item;
            string itemName;
            double itemPrice;
            int itemQuantity;
            char delimiter;

            while (getline(in, line)) {
                stringstream ss(line);
                ss >> itemName >> delimiter >> itemPrice >> delimiter >> itemQuantity;
                if(item==itemName){
                    found=true;
                    cout << "Enter the Quantity: " << endl;
                    while (!(cin>>quantity)) {
                        cout << "Invalid input. Please enter valid number ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if(quantity<=itemQuantity){
                        double amount=itemPrice*quantity;
                        total+=amount;
                        cout<<"Item"<<"|"<<"Price"<<"|"<<"Quantity"<<"|"<<"Amount"<<endl;
                        cout<<itemName<<"|"<<itemPrice<<"$"<<"|"<<quantity<<"|"<<amount<<"$"<<endl;
                        clearScreen();
                        out<<itemName<<"|"<<itemPrice<<"$"<<"|"<<quantity<<"|"<<amount<<"$"<<endl;
                        itemQuantity -= quantity;
                    }
                    else{
                        cout<<"We Don't Have This Quantity.The Quantity We Have : " <<itemQuantity<<endl;
                    }
                }
            }
            if(!found){
                cout<<"Item Is Unavailable!"<<endl;
            }
            in.close();
        } else if (choice == 2) {
            close = true;
            clearScreen();
            cout << "Counting Total Bill" << endl;
            cout<<"*******************"<<endl<<"\t"<<total<<"$"<<endl<<endl<<endl;
            out<<"*******************"<<endl<<"\t\t"<<total<<"$";
        } else{
            cout << "There Is No Such Option!" << endl;
        }
    }
}
void Bill::addItem(Bill b){
    bool close=false;
    while(!close){
        int choice=0;
        cout<<"1.Add"<<endl;
        cout<<"2.Close"<<endl;
        cout<<"Enter Choice:";
        while (!(cin>>choice)) {
            cout << "Invalid input. Please enter 1 or 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(choice==1){
            string item;
            int price,quantity;
            cout <<"Enter Item's Name: "<<endl;
            cin.ignore();
            getline(cin,item);
            b.setItem(item);
            cout <<"Enter Item's Price: "<<endl;
            while (!(cin >> price)) {
                cout << "Invalid input. Please enter a valid price: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            b.setPrice(price);

            cout <<"Enter Item's Quantity: "<<endl;
            while (!(cin >> quantity)) {
                cout << "Invalid input. Please enter a valid quantity: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            b.setQuantity(quantity);
            clearScreen();

            ofstream out("C:\\Facultate\\C++\\Market-Billing-System\\inventory.txt",ios::app);
            if(!out){
                cout<<"File Can't Be Openned!";
            }
            else{
                out<<b.getItem()<<" : "<<b.getPrice()<<" : "<<b.getQuantity()<<endl;
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