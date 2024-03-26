#ifndef BILL_H
#define BILL_H
#include <iostream>

using namespace std;

class Bill {
private:
    string item;
    double price;
    int quantity;
public:
    Bill(){};
    Bill(string item,double price,int quantity);
    void setItem(string item);
    void setPrice(double price);
    void setQuantity(int quantity);
    string getItem();
    double getPrice();
    int getQuantity();
    void printBill();
    void addItem(Bill b);
    void clearScreen();
};


#endif
