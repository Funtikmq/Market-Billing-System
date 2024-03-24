#include "Bill.h"
#include <iostream>
using namespace std;

Bill::Bill(string item,int rate,int quantity):item(item),rate(rate),quantity(quantity){}

void Bill::setItem(string item) {this->item=item;}
void Bill::setRate(int rate) {this->rate=rate;}
void Bill::setQuantity(int quantity)  {this->quantity=quantity;}
string Bill::getItem() {return item;};
int Bill::getRate() {return rate;};
int Bill::getQuantity() {return quantity;};
