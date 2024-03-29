#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include <sstream>
#include <string>

using namespace std;

class Div : public Base {
	private:
		Base* left_child = nullptr;
		Base* right_child = nullptr;
	public:
		Div(Base* left, Base* right){
			left_child = left;
			right_child = right;
		}
		~Div() { delete left_child; delete right_child; } 
		virtual double evaluate(){
			return left_child->evaluate() / right_child->evaluate();
		}
		virtual string stringify(){
			stringstream number;
			number << "(" << left_child->stringify() << " / " << right_child->stringify() << ")";
			string out = number.str();
			return out;
		}

	       
		virtual int number_of_children() {
                	int num = 0;
                	if(left_child!= nullptr)
                        	++num;
                	if(right_child!= nullptr)
                        	++num;
                	return num;
        	}

        virtual Base* get_child(int i) {
                if(i < number_of_children()){
                        if(i == 0){
                                return left_child;
                        }
                        if(i == 1){
                                return right_child;
                        }
                }
                

        }

	virtual void accept(Visitor* visitor, int index) {
                if(index == 0)
                        visitor->visit_div_begin(this);
                if(index == 1)
                        visitor->visit_div_middle(this);
                if(index == 2)
                        visitor->visit_div_end(this);
		
	}



};

#endif //__DIV_HPP__
