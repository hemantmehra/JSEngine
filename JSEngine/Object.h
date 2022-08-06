#pragma once

#include <hash_map>
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

	private:
		std::hash_map<std::string, Value> m_properties;
	};
}