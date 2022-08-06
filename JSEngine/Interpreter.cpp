#include "AST.h"
#include "Interpreter.h"
#include "Object.h"
#include "Value.h"


namespace JS
{
	Interpreter::Interpreter()
	{
		m_global_object = new Object;
	}

	Interpreter::~Interpreter()
	{
		delete m_global_object;
	}

	Value Interpreter::run(const ScopeNode& scope_node)
	{
		enter_scope(scope_node);
		Value last_value = js_undefined();
		for (auto& node : scope_node.children())
		{
			last_value = node->execute(*this);
		}
		exit_scope(scope_node);
		return last_value;
	}

	void Interpreter::enter_scope(const ScopeNode& scope_node)
	{
		m_scope_stack.push_back({ scope_node });
	}

	void Interpreter::exit_scope(const ScopeNode& scope_node)
	{
		m_scope_stack.pop_back();
	}

	void Interpreter::do_return()
	{
		std::cout << "FIXME: Implement Interpreter::do_return()" << std::endl;
	}
}