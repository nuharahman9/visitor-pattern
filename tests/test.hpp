#ifndef __TEST__
#define __TEST__
#include "gtest/gtest.h" 
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

#endif
