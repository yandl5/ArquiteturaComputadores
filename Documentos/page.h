#ifndef PAGE
#define PAGE
#include <string>
using namespace std;
class Page
{
private:
	string adress;
	string operation;
public:
	Page();
	~Page();
	//gets and sets
	void setAdress(string Adress);
	void setOperation(string op);
	string getAdress();
	string getOperation();
};
#endif