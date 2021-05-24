#ifndef __POW_HPP__
#define __POW_HPP__
#include <sstream>
#include <cmath> 
#include <string>
#include "base.hpp"

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
          virtual int number_of_children() { return 2; }
        virtual Base* get_child(int i) { 
	  if (i == 0) { return baseNum; } 
	  else { return exponent; }
	}

private: 
  Base* baseNum; 
  Base* exponent; 

};
#endif




