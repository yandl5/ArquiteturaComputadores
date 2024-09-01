#ifndef PAGE
#define PAGE
#include <string>
using namespace std;
class Page
{
private:
	string adress;
	string operation;
	double time;
public:
	Page();
	~Page();
	//gets and sets
	void setAdress(string Adress);
	void setOperation(string op);
	void setTime(double Time);
	string getAdress();
	string getOperation();
	double getTime();
};
#endif