#pragma once

#include <vector>
#include "Forward.h"

namespace JS
{
	struct ScopeFrame
	{
		const ScopeNode& scope_node;
	};
	
	class Interpreter
	{
	public:
		Interpreter();

		Value run(const ScopeNode&);
	
	private:
		void enter_scope(const ScopeNode&);
		void exit_scope(const ScopeNode&);

		std::vector<ScopeFrame> m_scope_stack;
	};
}