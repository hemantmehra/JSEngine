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
		~Interpreter();

		Value run(const ScopeNode&);

		Object& global_object() { return *m_global_object; }
		const Object& global_object() const { return *m_global_object; }

		void do_return();
	
	private:
		void enter_scope(const ScopeNode&);
		void exit_scope(const ScopeNode&);

		std::vector<ScopeFrame> m_scope_stack;

		Object* m_global_object {nullptr};
	};
}