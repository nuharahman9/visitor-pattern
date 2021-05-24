#ifndef __MULT_HPP__
#define __MULT_HPP__
#include <sstream>
#include <string>
#include "base.hpp"

using namespace std;

class Mult: public Base {
public: 
  Mult(Base* left, Base* right) { 
    leftOp = left; 
    rightOp = right; 
  }
  virtual double evaluate() { 
    return leftOp->evaluate() * rightOp->evaluate(); 
  }
  virtual string stringify() { 
    stringstream out; 
    out << "(" << leftOp->stringify() << " * " << rightOp->stringify() << ")";         
    string output = out.str(); 
    return output; 
  }
   virtual int number_of_children() { return 2; }
    virtual Base* get_child(int i) { 
	if (i == 0) { return leftOp; }
	else { return rightOp; } 
    }

private: 
  Base* leftOp; 
  Base* rightOp; 

};
#endif