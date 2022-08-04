#pragma once

#include <string>

namespace JS::Bytecode
{
	class Interpreter
	{
	public:
		~Interpreter() {}
	};

	class Instruction
	{
	public:
		virtual ~Instruction() {}
		virtual void execute(Interpreter&) const = 0;
		virtual std::string to_string() const = 0;
	};

	class Load final : public Instruction
	{
	public:
		virtual ~Load() override {}
		virtual void execute(Interpreter&) const override;
		virtual std::string to_string() const override;
	};
}
