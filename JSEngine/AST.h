#pragma once

#include <string>
#include <vector>

namespace JS::AST
{
	class Node
	{
	public:
		std::vector<Node*> m_children;

		Node(std::string name) : m_name(name) {}
		std::string get_name() const;
		void add_child(Node* child);
		virtual std::string to_string() = 0;

	private:
		std::string m_name;
	
	};

	class Program : public Node
	{
	public:
		Program() : Node("Program") {}
		std::string to_string() override;
	};

	class Expression : public Node
	{
	public:
		Expression() : Node("Expression") {}
		std::string to_string() override;
	};

	class Literal : public Node
	{
	public:
		Literal() : Node("Literal") {}
		std::string to_string() override;
	};

	class NumericLiteral : public Literal
	{
	private:
		int m_value;
	public:
		NumericLiteral(int x) : Literal(), m_value(x) {}
		std::string to_string() override;
	};

	class Operator : public Node
	{
	public:
		Operator(std::string op) : Node(op) {}
		std::string to_string() override;
	};

	void print_ast_helper(Node* node, int indent);
	void print_ast(Node* node);
}
