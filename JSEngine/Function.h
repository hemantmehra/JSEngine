#pragma once

#include <string>
#include "Forward.h"
#include "Object.h"

namespace JS
{
	class Function : public Object
	{
	public:
		Function(std::string name, const ScopeNode& body);
		virtual ~Function();

		const std::string& name() const { return m_name; }
		const ScopeNode& body() const { return m_body; }

	private:
		virtual bool is_function() const final { return true; }

		std::string m_name;
		const ScopeNode& m_body;
	};
}