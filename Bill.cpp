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

    ofstream out("C:\\Facultate\\C++\\Market-Billing-System\\bill.txt");
    if (!out) {
        cerr << "Error: Could Not Open The File." << endl;
        return;
    }

    bool close = false;
    bool found = false;
    string item;
    int quantity;
    double total = 0.0;
    while (!close) {
        cout << "Enter Item Or Press Enter For Exit: " << endl;
        cin.ignore();
        getline(cin, item);
        if (!item.empty()) {
            ifstream in("C:\\Facultate\\C++\\Market-Billing-System\\inventory.txt");
            if (!in) {
                cerr << "Error: Could Not Open The File." << endl;
                return;
            }

            string line;
            while (getline(in, line)) {
                stringstream ss(line);
                string itemName, itemPString, itemQString;
                double itemPrice;
                int itemQuantity;
                char delimiter;

                getline(ss, itemName, ',');
                getline(ss, itemPString, ',');
                getline(ss, itemQString, ',');

                itemPrice = stod(itemPString);
                itemQuantity = stoi(itemQString);

                if (item == itemName) {
                    found = true;
                    cout << "Enter the Quantity: " << endl;
                    while (!(cin >> quantity)) {
                        cerr << "Invalid input. Please enter valid number ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if (quantity <= itemQuantity) {
                        double amount = itemPrice * quantity;
                        total += amount;
                        cout << "Item" << "|" << "Price" << "|" << "Quantity" << "|" << "Amount" << endl;
                        cout << itemName << "|" << itemPrice << "$" << "|" << quantity << "|" << amount << "$" << endl;
                        clearScreen();
                        out << itemName << "|" << itemPrice << "$" << "|" << quantity << "|" << amount << "$" << endl;
                        itemQuantity -= quantity;
                    } else {
                        cout << "We Don't Have This Quantity. The Quantity We Have: " << itemQuantity << endl;
                    }
                }
            }

            if (!found) {
                cerr << "Item Is Unavailable!" << endl;
            }

            in.close();
        } else {
            close = true;
            clearScreen();
            cout << "Counting Total Bill" << endl;
            cout << "*******************" << endl << "\t" << total << "$" << endl << endl << endl;
            out << "*******************" << endl << "\t\t" << total << "$";
        }
    }

    out.close();
}
void Bill::addItem(Bill* b) {
    bool close = false;
    while (!close) {
        string item;
        int price, quantity;
        cout << "Enter Item Or Press Enter To Exit" << endl;
        cin.ignore();
        getline(cin, item);
        b->setItem(item);

        if (!item.empty()) {
            cout << "Enter Item's Price: " << endl;
            while (!(cin >> price)) {
                cerr << "Invalid Input. Please Enter A Valid Price: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            b->setPrice(price);

            cout << "Enter Item's Quantity: " << endl;
            while (!(cin >> quantity)) {
                cerr << "Invalid Input. Please Enter A Valid Quantity: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            b->setQuantity(quantity);
            clearScreen();

            ofstream out("C:\\Facultate\\C++\\Market-Billing-System\\inventory.txt", ios::app);
            if (!out) {
                cerr << "Error: Could Not Open The File." << endl;
            }
            else {
                out << b->getItem() << "," << b->getPrice() << "," << b->getQuantity() << endl;
                cout << "Item Was Added To The Database" << endl;
            }
            out.close();
        }
        else {
            close = true;
            clearScreen();
            cout << "Back to Main Menu" << endl;
        }
    }
}
