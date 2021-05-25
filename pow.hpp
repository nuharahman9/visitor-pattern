#ifndef __POW_HPP__
#define __POW_HPP__
#include <sstream>
#include <cmath> 
#include <string>
#include "base.hpp"
#include "visitor.hpp"

using namespace std;

class Pow: public Base {
public: 
  Pow(Base* left, Base* right) { 
    baseNum = left; 
    exponent = right; 
  }
  virtual double evaluate() { 
    return pow(baseNum->evaluate(), exponent->evaluate()); 
  }
  virtual string stringify() { 
    stringstream out; 
    out << "(" << baseNum->stringify() << ")**(" << exponent->stringify() << ")";         
    string output = out.str(); 
    return output; 
  }
  virtual int number_of_children() {
  	int num = 0;
        if(baseNum!= nullptr)
        	++num;
        if(exponent!= nullptr)
        	++num;
        return num;
   }

  virtual Base* get_child(int i) {
  	if(i < number_of_children()){
        	if(i == 0){
                	return baseNum;
                }
                if(i == 1){
                        return exponent;
                                }
                        }

   }

virtual void accept(Visitor* visitor, int index) {
                        if(index == 0)
                                visitor->visit_pow_begin(this);
                        if(index == 1)
                                visitor->visit_pow_middle(this);
                        if(index == 2)
                                visitor->visit_pow_end(this);
		}

     void accept(Visitor* visitor, int index) { 
	if (i == 0) { 
	  visitor->visit_pow_begin(this); 
	}
	else if (i == 1) { visitor->visit_pow_middle(this); }  
	else if (i == 2) { visitor->visit_pow_end(this); } 
	else { cout << "Invalid input" << endl; }
   }

private: 
  Base* baseNum = nullptr; 
  Base* exponent = nullptr; 

};
#endif




