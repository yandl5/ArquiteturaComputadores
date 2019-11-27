#include "page.h"
Page::Page(){}
Page::~Page(){}
//gets and sets
void Page::setAdress(string Adress){adress=Adress;}
void Page::setOperation(string op){operation=op;}
string Page::getAdress(){return adress;}
string Page::getOperation(){return operation;}