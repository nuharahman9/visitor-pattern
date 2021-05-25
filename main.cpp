#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

#include<iomanip>
#include <iostream>
#include <string>
std::string PrintLaTeX(Base* ptr){
    Iterator* itPtr = new Iterator(ptr);

    VisitorLaTeX* vPtr = new VisitorLaTeX();
	for(itPtr; !itPtr->is_done(); itPtr->next()){
		itPtr->current_node()->accept(vPtr,itPtr->current_index());
	}
    return vPtr->getString();
}

int main() {
    Base* op1 = new Op(1);
    Base* op2 = new Op(2);
    Base* op3 = new Op(3);

    Sub* sub1 = new Sub(op2, op1);
    Mult* mult1  = new Mult(op3, op2);
    Div* div1 = new Div(mult1, sub1);

    Pow* pow1 = new Pow(op2, op3);
    Add* add1 = new Add(op2, op3);
    Sub* sub2 = new Sub(pow1, add1);

    Add* add = new Add(div1, sub2);

    std::cout << add->stringify() << " => \n LaTeX: ";

    std::cout << PrintLaTeX(add) << "\n";
    return 0;
}