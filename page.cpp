#include "page.h"
Page::Page(){}
Page::~Page(){}
//gets and sets
void Page::setAdress(string Adress){adress=Adress;}
void Page::setOperation(string op){operation=op;}
void Page::setTime(double Time){time=Time;}
string Page::getAdress(){return adress;}
string Page::getOperation(){return operation;}
double Page::getTime(){return time;}