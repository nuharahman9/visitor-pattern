#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Rand : public Base {
	public:
		Rand() : Base() {   }
	        virtual double evaluate() { 
	        	value1 = rand() % 100;
	    		return value1; 
		}
	virtual std::string stringify() { return std::to_string(value1);}
		virtual int number_of_children() { return 0; } 
                virtual Base* get_child(int i) { return nullptr; }
		
		virtual void accept(Visitor* visitor, int index) {
			visitor->visit_rand(this);
		}
	private:
	double value1;
};

#endif //__RAND_HPP__
