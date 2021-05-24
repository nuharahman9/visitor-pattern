#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include <sstream>
#include <string>

using namespace std;

class Sub : public Base {
	private:
		Base* left_child;
		Base* right_child;
	public:
		Sub(Base* left, Base* right){
			left_child = left;
			right_child = right;
		}
		virtual double evaluate(){
			return left_child->evaluate() - right_child->evaluate();
		}
		virtual string stringify(){
			stringstream number;
			number << "(" << left_child->stringify() << " - " << right_child->stringify() << ")";

			string out = number.str();
			return out;
		}
		virtual int number_of_children() { 
			return 2;  
		  }
        	virtual Base* get_child(int i) {
			if (i == 0) { 
			   return left_child; 
			} 
			else { return right_child; }	
		}

	};

#endif //__SUB_HPP__
