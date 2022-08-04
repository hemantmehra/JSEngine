#include "Bytecode.h"

namespace JS::Bytecode
{
	std::string Load::to_string() const
	{
		return "Load";
	}

	void Load::execute(Interpreter& interpreter) const
	{

	}
}
