#include "Bill.h"
#include <iostream>
#include<fstream>
#include <sstream>
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
    bool close = false;
    bool found=false;
    int choice;
    double total = 0.0;

    ifstream in("C:\\Facultate\\C++\\Market-Billing-System\\inventory.txt"); //
    if (!in) {
        cerr << "Error: Could not open the file." << endl;
    }
    while (!close) {
        cout << "1. Add Bill" << endl;
        cout << "2. Close Session" << endl;
        cout << "Enter Your Choice: " << endl;
        cin >> choice;

        if (choice == 1) {
            string line;
            string item;
            int quantity;
            cout << "Enter Item: " << endl;
            cin >> item;
            string itemName;
            double itemPrice;
            int itemQuantity;
            char delimiter;
            getline(in,line);
            while (getline(in, line)) {
                stringstream ss(line);
                ss >> itemName >> delimiter >> itemPrice >> delimiter >> itemQuantity;
                if(item==itemName){
                    found=true;
                    cout << "Enter the Quantity: " << endl;
                    cin >> quantity;
                    if(quantity<=itemQuantity){
                        double amount=itemPrice*quantity;
                        total+=amount;
                        cout<<"Item"<<"|"<<"Price"<<"|"<<"Quantity"<<"|"<<"Amount"<<endl;
                        cout<<itemName<<"|"<<itemPrice<<"|"<<quantity<<"|"<<amount<<endl;
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
            cout << "Counting Total Bill" << endl;
            cout<<"****************"<<total<<endl;
        } else{
            cout << "There Is No Such Option!" << endl;
        }
    }
}
void Bill::addItem(Bill b){
    bool close=false;
    while(!close){
        int choice;
        cout<<"\t1.Add"<<endl;
        cout<<"\t2.Close"<<endl;
        cout<<"\tEnter Choice:";
        cin>>choice;

        if(choice==1){
            string item;
            int price,quantity;
            cout << "Enter Item's Name: "<< endl;
            cin.ignore();
            getline(cin,item);
            b.setItem(item);
            cout << "Enter Item's Price: "<< endl;
            cin >> price;
            b.setPrice(price);
            cout << "Enter Item's Quantity: "<< endl;
            cin >> quantity;
            b.setQuantity(quantity);

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