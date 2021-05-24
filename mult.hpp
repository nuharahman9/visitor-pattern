#ifndef __MULT_HPP__
#define __MULT_HPP__
#include <sstream>
#include <string>
#include "base.hpp"
#include "visitor.hpp"

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
   virtual int number_of_children() {
   	int num = 0;
        if(leftOp!= nullptr)
        	++num;
        if(rightOp!= nullptr)
        	++num;
        return num;
   }
    virtual Base* get_child(int i) {
            if(i < number_of_children()) {
                if (i == 0){
                        return leftOp;
                }
                if (i == 1){
                        return rightOp;
                        }
                 }
        }


        virtual void accept(Visitor* visitor, int index) {
                if (index == 0)
                        visitor->visit_mult_begin(this);
                if (index == 1)
                        visitor->visit_mult_middle(this);
                if (index == 2)
                        visitor->visit_mult_end(this);
                 }


private: 
  Base* leftOp = nullptr; 
  Base* rightOp = nullptr; 

};
#endif
