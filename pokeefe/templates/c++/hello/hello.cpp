/*Orion Lawlor's Simple C++ Examples, olawlor@acm.org
Shows how to use virtual functions.
*/
#include <iostream>

class parent {
public:
	virtual void hello(void) {std::cout<<"parent::hello"<<std::endl;}
};

class child: public parent {
public:
	virtual void hello(void) {std::cout<<"child::world"<<std::endl;}
};

int main()
{
	parent *p=new parent;
	p->hello();
	
	p=new child;
	p->hello();
	delete p;
	
	return 0;
}
