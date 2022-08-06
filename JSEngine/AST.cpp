#include <iostream>
#include "AST.h"
#include "Value.h"

namespace JS
{
	Value FunctionDeclaration::execute(Interpreter& interpreter) const
	{
		global_object.put(m_name, Value(new Function(name(), body()));
	}
}