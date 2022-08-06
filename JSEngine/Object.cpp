#include "Object.h"
#include "Value.h"

namespace JS
{
	Value Object::get(const std::string& property_name) const
	{
		auto v = m_properties.find(property_name);
		if (v == m_properties.end()) return js_undefined();
		return v->second;
	}

	void Object::put(const std::string& property_name, Value value)
	{
		m_properties[property_name] = value;
	}
}