#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <sstream>
#include <string>

using namespace std;

class Div : public Base {
	private:
		Base* left_child;
		Base* right_child;
	public:
		Div(Base* left, Base* right){
			left_child = left;
			right_child = right;
		}
		virtual double evaluate(){
			return left_child->evaluate() / right_child->evaluate();
		}
		virtual string stringify(){
			stringstream number;
			number << "(" << left_child->stringify() << " / " << right_child->stringify() << ")";
			string out = number.str();
			return out;
		}
		 virtual int number_of_children() { return 2; } 
        	virtual Base* get_child(int i) { 
			if (i == 0) { return left_child; } 
			else { return right_child; }
		}
		void accept(Visitor* visitor, int index) { 
			if (i == 0) { 
			  visitor->visit_div_begin(this); 
			}
			else if (i == 1) { visitor->visit_div_middle(this); }  
			else if (i == 2) { visitor->visit_div_end(this); } 
			else { cout << "Invalid input" << endl; }
  		 }
};

#endif //__DIV_HPP__
