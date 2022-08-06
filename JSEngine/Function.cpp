#include "Function.h"

namespace JS
{
	Function::Function(std::string name, const ScopeNode& body)
		: m_name(name)
		, m_body(body)
	{}

	Function::~Function() {}
}