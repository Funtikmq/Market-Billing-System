#ifndef BILL_H
#define BILL_H
#include <iostream>

using namespace std;

class Bill {
private:
    string item;
    int rate,quantity;
public:
    Bill(string item,int rate,int quantity);
    Bill(string item,int rate);
    void setItem(string item);
    void setRate(int rate);
    void setQuantity(int quantity);
    string getItem();
    int getRate();
    int getQuantity();
};


#endif
