#ifndef __OP_HPP__
#define __OP_HPP__

#include <iostream>

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
	if (index == 0) { 
	  visitor->visit_op(this); 
	  }
 }



private: 
    double value;   
  }; 
 #endif


