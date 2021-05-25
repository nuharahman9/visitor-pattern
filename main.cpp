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

    VisitorLaTeX* vPtr = new VisitorLaTeX(); 

    std::cout << add->stringify() << " => \n LaTeX: ";

    std::cout << vPtr->PrintLaTeX(add) << "\n";
      
     delete vPtr;  
    return 0;
}
