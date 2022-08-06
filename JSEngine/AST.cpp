#include <iostream>
#include "AST.h"
#include "Function.h"
#include "Interpreter.h"
#include "Object.h"
#include "Value.h"

namespace JS
{
	Value ScopeNode::execute(Interpreter& interpreter) const
	{
		return	interpreter.run(*this);
	}

	Value FunctionDeclaration::execute(Interpreter& interpreter) const
	{
		auto* function = new Function(name(), body());
		interpreter.global_object().put(m_name, Value(function));
		return Value(function);
	}

	Value CallExpression::execute(Interpreter& interpreter) const
	{
		auto callee = interpreter.global_object().get(name());
		_ASSERT(callee.is_object());
		Object* callee_object = callee.as_object();
		_ASSERT(callee_object->is_function());
		auto& function = (Function&)(*callee_object);
		return interpreter.run(function.body());
	}

	Value ReturnStatement::execute(Interpreter& interpreter) const
	{
		auto value = argument().execute(interpreter);
		interpreter.do_return();
		return value;
	}

	Value add(Value lhs, Value rhs)
	{
		_ASSERT(lhs.is_number());
		_ASSERT(rhs.is_number());
		return Value(lhs.as_double() + rhs.as_double());
	}

	Value sub(Value lhs, Value rhs)
	{
		_ASSERT(lhs.is_number());
		_ASSERT(rhs.is_number());
		return Value(lhs.as_double() - rhs.as_double());
	}

	Value BinaryExpression::execute(Interpreter& interpreter) const
	{
		auto lhs_result = m_lhs->execute(interpreter);
		auto rhs_result = m_rhs->execute(interpreter);

		switch (m_op)
		{
		case BinaryOp::Plus:
			return add(lhs_result, rhs_result);
		case BinaryOp::Minus:
			return sub(lhs_result, rhs_result);
		default:
			_ASSERT(false);
			return add(lhs_result, rhs_result);
		}

		_ASSERT(false);
	}

	void print_indent(int indent)
	{
		for (size_t i = 0; i < 2 * indent; i++) std::cout << " ";
	}

	void ASTNode::dump(int indent) const
	{
		print_indent(indent);
		std::cout << class_name() << std::endl;
	}

	void ScopeNode::dump(int indent) const
	{
		ASTNode::dump(indent);
		for (auto& child : children())
		{
			child->dump(indent + 1);
		}
	}

	void BinaryExpression::dump(int indent) const
	{
		ASTNode::dump(indent);
		m_lhs->dump(indent + 1);
		m_rhs->dump(indent + 1);
	}

	void CallExpression::dump(int indent) const
	{
		print_indent(indent);
		std::cout << class_name() << " " << name() << std::endl;
	}

	void Literal::dump(int indent) const
	{
		print_indent(indent);
		std::cout << (uint32_t) m_value.as_double() << std::endl;
	}

	void FunctionDeclaration::dump(int indent) const
	{
		print_indent(indent);
		std::cout << class_name() << " " << name() << std::endl;
		body().dump(indent + 1);
	}

	void ReturnStatement::dump(int indent) const
	{
		ASTNode::dump(indent);
		argument().dump(indent + 1);
	}
}