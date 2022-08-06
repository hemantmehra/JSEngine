#pragma once

#include <iostream>
#include <string>
#include "Forward.h"

namespace JS
{
	class Value
	{
	public:
		enum class Type
		{
			Undefined,
			Null,
			Number,
			String,
			Object,
			Boolean
		};

		explicit Value(double value) : m_type(Type::Number)
		{
			m_value.as_double = value;
		}

		explicit Value(uint32_t value) : m_type(Type::Number)
		{
			m_value.as_double = value;
		}

		Value(Type type) : m_type(type) {}

		Type type() const { return m_type; }

		double as_double() const
		{
			_ASSERT(type() == Type::Number);
			return m_value.as_double;
		}

		bool as_bool() const
		{
			_ASSERT(type() == Type::Boolean);
			return m_value.as_bool;
		}

	private:
		Type m_type{ Type::Undefined };

		union
		{
			bool as_bool;
			double as_double;
			std::string* as_string;
			Object* object;
		} m_value;
	};

	inline Value js_undefined()
	{
		return Value(Value::Type::Undefined);
	}

	inline Value js_Null()
	{
		return Value(Value::Type::Null);
	}

	std::ostream& operator<<(std::ostream& stream, const Value& value)
	{
		switch (value.type())
		{
		case Value::Type::Boolean:
			stream << value.as_bool();
			break;
		case Value::Type::Number:
			stream << (uint32_t) value.as_double();
			break;
		default:
			_ASSERT(false);
			break;
		}

		return stream;	
	}
}
