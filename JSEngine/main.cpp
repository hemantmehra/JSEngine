// JSEngine.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "AST.h"

int main()
{
	JS::AST::Node* p = new JS::AST::Program();
	JS::AST::Node* e = new JS::AST::Expression();

	p->add_child(e);
	e->add_child(new JS::AST::NumericLiteral(100));
	e->add_child(new JS::AST::Operator("+"));
	e->add_child(new JS::AST::NumericLiteral(50));

	JS::AST::print_ast(p);
	return 0;
}
