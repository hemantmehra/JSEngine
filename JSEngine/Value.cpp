#include "Object.h"
#include "Value.h"

namespace JS
{
	std::string Value::to_string() const
	{
		if (is_boolean())
			return as_bool() ? "true" : "false";
		
		if (is_null())
			return "null";

		if (is_undefined())
			return "undefined";

		if (is_number())
			return std::to_string((uint32_t) as_double());

		if (is_object())
			return as_object()->class_name();

		_ASSERT(false);
	}
}