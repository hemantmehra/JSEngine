#pragma once

#include <unordered_map>
#include <string>
#include "Value.h"
#include "Forward.h"

namespace JS
{
	class Object
	{
	public:
		Object() {}

		Value get(const std::string& property_name) const;
		void put(const std::string& property_name, Value);

		virtual bool is_function() const { return true; }

		virtual const char* class_name() const { return "Object"; }
	private:
		std::unordered_map<std::string, Value> m_properties;
	};
}