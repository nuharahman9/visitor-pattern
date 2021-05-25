#ifndef __OP_HPP__
#define __OP_HPP__
#include <sstream>
#include <string>
#include <iomanip> 
#include "base.hpp"

using namespace std;

class Op: public Base {
public: 
  Op(double val) : Base() { 
    value = val;  
  }
  virtual double evaluate() { 
    return value; 
  }
  virtual string stringify() { 
    stringstream out; 
    out << setprecision(3) << value;          
    string output = out.str(); 
    return output;
  }
   virtual int number_of_children() { 
     return 0; 
   }
   virtual Base* get_child(int i) { 
	return nullptr; 
    }
      void accept(Visitor* visitor, int index) { 
	if (i == 0) { 
	  visitor->visit_op(this); 
	}
	else { cout << "Invalid input" << endl; }
   }

private: 
    double value;   
  }; 
 #endif 
