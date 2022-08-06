#pragma once

#include <string>
#include <vector>
#include "Forward.h"
#include "Value.h"

namespace JS
{
	class ASTNode
	{
	public:
		virtual ~ASTNode() {}
		virtual const char* class_name() const = 0;
		virtual Value execute(Interpreter&) const = 0;

	protected:
		ASTNode() {}

	private:

	};

	class ScopeNode : public ASTNode
	{
	public:
		template<typename T, typename... Args>
		T& append(Args&&... args)
		{
			auto child = new T(args...);
			m_children.push_back(child);
			return (T&)m_children.back();
		}
		const std::vector<ASTNode*>& children() const { return m_children; }
		virtual Value execute(Interpreter&) const override;
	protected:
		ScopeNode() {}

	private:
		std::vector<ASTNode*> m_children;

	};

	class Program : public ScopeNode
	{
	public:
		explicit Program() {}

	private:
		virtual const char* class_name() const override { return "Program"; }
	};

	class BlockStatement : public ScopeNode
	{
	public:
		BlockStatement() {}

	private:
		virtual const char* class_name() const override { return "BlockStatement"; }
	};

	class FunctionDeclaration : public ASTNode
	{
	public:
		FunctionDeclaration(std::string name, ScopeNode* body) : m_name(name), m_body(body) {}
		std::string name() const { return m_name; }
		const ScopeNode& body() const { return *m_body; }
		virtual Value execute(Interpreter&) const override;

	private:
		virtual const char* class_name() const override { return "FunctionDeclaration"; }
		std::string m_name;
		ScopeNode* m_body;
	};

	class Expression : public ASTNode
	{
	public:

	};

	class ReturnStatement : public ASTNode
	{
	public:
		explicit ReturnStatement(Expression* argument) : m_argument(argument) {}
		const Expression& argument() const { return *m_argument; }
		virtual Value execute(Interpreter&) const override;
	private:
		virtual const char* class_name() const override { return "ReturnStatement"; }
		Expression* m_argument;
	};

	enum class BinaryOp
	{
		Plus,
		Minus
	};

	class BinaryExpression : public Expression
	{
	public:
		BinaryExpression(BinaryOp op, Expression* lhs, Expression* rhs)
			: m_op(op)
			, m_lhs(lhs)
			, m_rhs(rhs)
		{}
		virtual Value execute(Interpreter&) const override;

	private:
		virtual const char* class_name() const override { return "BinaryExpression"; }

		BinaryOp m_op;
		Expression* m_lhs;
		Expression* m_rhs;
	};

	class Literal : public Expression
	{
	public:
		explicit Literal(Value value) : m_value(value) {}
		virtual Value execute(Interpreter&) const override { return m_value; }

	private:
		virtual const char* class_name() const override { return "Literal"; }
		Value m_value;
	};

	class ExpressionStatement : public ASTNode
	{
	public:
		virtual Value execute(Interpreter&) const override;
	private:
		virtual const char* class_name() const override { return "ExpressionStatement"; }
	};

	class CallExpression : public Expression
	{
	public:
		explicit CallExpression(std::string name) : m_name(name) {}
		virtual Value execute(Interpreter&) const override;
		const std::string& name() const { return m_name; }
	private:
		virtual const char* class_name() const override { return "CallExpression"; }
		std::string m_name;
	};
}
