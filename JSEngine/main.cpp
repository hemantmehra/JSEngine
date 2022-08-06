// JSEngine.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "AST.h"
#include "Interpreter.h"
#include "Object.h"
#include "Value.h"

int main()
{
	auto program = new JS::Program();
	auto block = new JS::BlockStatement();
	block->append<JS::ReturnStatement>(
		new JS::BinaryExpression(
			JS::BinaryOp::Plus,
			new JS::Literal(JS::Value((uint32_t)1)),
			new JS::Literal(JS::Value((uint32_t)2))
		)
	);

	program->append<JS::FunctionDeclaration>("foo", block);
	program->append<JS::ExpressionStatement>(
			new JS::CallExpression("foo")
		);

	JS::Interpreter interpreter;
	auto result = interpreter.run(*program);
	
	std::cout << "Interpreter returned " << result;
	return 0;
}
