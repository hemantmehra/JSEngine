#include "AST.h"
#include "Interpreter.h"
#include "Value.h"


namespace JS
{
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

	void Interpreter::enter_scope(const ScopeNode& scope_node)
	{
		m_scope_stack.pop_back();
	}
}