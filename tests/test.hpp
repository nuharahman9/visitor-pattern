#ifndef __TEST__
#define __TEST__
#include "gtest/gtest.h"
#include "../visitor.hpp" 
#include "../iterator.hpp"
#include "../sub.hpp"
#include "../add.hpp" 
#include "../div.hpp"
#include "../mult.hpp"
#include "../pow.hpp"
#include "../rand.hpp"
#include "../base.hpp"
#include "../op.hpp"

TEST(numChildren, Add) { 
   Base* op = new Op(16); 
   Base* add = new Add(op, new Op(17)); 
   EXPECT_EQ(add->number_of_children(), 2);  
}

TEST(numChildren, Sub) {
   Base* op = new Op(16);
   Base* sub  = new Sub(op, new Op(17));
   EXPECT_EQ(sub->number_of_children(), 2);
}

TEST(numChildren, Div) {
   Base* op = new Op(16);
   Base* div  = new Div(op, new Op(17));
   EXPECT_EQ(div->number_of_children(), 2);
}

TEST(numChildren, Mult) {
   Base* op = new Op(16);
   Base* mult  = new Mult(op, new Op(17));
   EXPECT_EQ(mult->number_of_children(), 2);
}

TEST(numChildren, Op) {
   Base* op = new Op(16);
   EXPECT_EQ(op->number_of_children(), 0);
}

TEST(numChildren, Rand) {
   Base* op = new Rand(); 
   EXPECT_EQ(op->number_of_children(), 0);

}

TEST(getChild, Op) {
   Base* op = new Op(16);
   EXPECT_EQ(op->get_child(1), nullptr);
}

TEST(getChild, Rand) {
   Base* op = new Rand();
   EXPECT_EQ(op->get_child(1), nullptr);
}

TEST(getChild, Add) {
   Base* op = new Op(16);
   Base* op2 = new Op(17); 
   Base* add = new Add(op, op2);
   EXPECT_EQ(add->get_child(0), op);
   EXPECT_EQ(add->get_child(1), op2);
}

TEST(getChild, Sub) {
   Base* op = new Op(16);
   Base* op2 = new Op(17);
   Base* eqn  = new Sub(op, op2);
   EXPECT_EQ(eqn->get_child(0), op);
   EXPECT_EQ(eqn->get_child(1), op2);
}

TEST(getChild, Div) {
   Base* op = new Op(16);
   Base* op2 = new Op(17);
   Base* eqn  = new Div(op, op2);
   EXPECT_EQ(eqn->get_child(0), op);
   EXPECT_EQ(eqn->get_child(1), op2);
}

TEST(getChild, Mult) {
   Base* op = new Op(16);
   Base* op2 = new Op(17);
   Base* eqn  = new Mult(op, op2);
   EXPECT_EQ(eqn->get_child(0), op);
   EXPECT_EQ(eqn->get_child(1), op2);
}

TEST(getChild, Pow) {
   Base* op = new Op(16);
   Base* op2 = new Op(17);
   Base* eqn  = new Pow(op, op2);
   EXPECT_EQ(eqn->get_child(0), op);
   EXPECT_EQ(eqn->get_child(1), op2);
}
TEST(PrintLatex, compositeOne) { 
  Base* op1 = new Op(1); 
  Base* eqn = new Sub(new Op(5), new Op(0));
  Base* root = new Add(op1, eqn); 
    
    VisitorLaTeX* vPtr = new VisitorLaTeX(); 
    EXPECT_EQ(vPtr->PrintLaTeX(root), "${({1}+{({5}-{0})})}$"); 

}
TEST(PrintLatex, Power) {
  Base* op1 = new Op(5);
  Base* root = new Pow(op1, new Op(2));
      
    VisitorLaTeX* vPtr = new VisitorLaTeX();
    EXPECT_EQ(vPtr->PrintLaTeX(root), "${({5}^{2})}$");

} 
TEST(PrintLatex, Multiply) {
  Base* op1 = new Op(5);
  Base* root = new Mult(new Op(2), op1);

    VisitorLaTeX* vPtr = new VisitorLaTeX();
    EXPECT_EQ(vPtr->PrintLaTeX(root), "${({2}\cdot{5})}$");
}
TEST(PrintLatex, Subtract) {
  Base* op1 = new Op(5);
  Base* root = new Sub(new Op(2), op1);
    VisitorLaTeX* vPtr = new VisitorLaTeX();
    EXPECT_EQ(vPtr->PrintLaTeX(root), "${({2}-{5})}$");
}
TEST(PrintLatex, Add) {
  Base* op1 = new Op(5);
  Base* root = new Add(new Op(2), op1);
    VisitorLaTeX* vPtr = new VisitorLaTeX();
    EXPECT_EQ(vPtr->PrintLaTeX(root), "${({2}+{5})}$");
}

TEST(PrintLatex, Divide) {
  Base* op1 = new Op(2);
  Base* root = new Div(new Op(2), op1);

    VisitorLaTeX* vPtr = new VisitorLaTeX();
    EXPECT_EQ(vPtr->PrintLaTeX(root), "${\frac{2}{2}}$");
}
TEST(PrintLatex, compositeTwo) {
  Base* op1 = new Op(2);
  Base* multiply = new Mult(op1, new Op(5)); 
  Base* power = new Pow(new Op(5), new Op(2));
  Base* root = new Div(multiply, power); 

    VisitorLaTeX* vPtr = new VisitorLaTeX();
    EXPECT_EQ(vPtr->PrintLaTeX(root), "${\frac{({2}\cdot{5})}{({5}^{2})}}$");
}

#endif
