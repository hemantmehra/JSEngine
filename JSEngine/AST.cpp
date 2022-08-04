#include <iostream>
#include "AST.h"

namespace JS::AST {
	std::string Node::get_name() const
	{
		return m_name;
	}

	void Node::add_child(Node* child)
	{
		m_children.push_back(child);
	}

	std::string Program::to_string()
	{
		return get_name();
	}

	std::string Expression::to_string()
	{
		return get_name();
	}

	std::string BinaryExpression::to_string()
	{
		return get_name() + " " + m_op;
	}

	std::string Literal::to_string()
	{
		return get_name();
	}

	std::string NumericLiteral::to_string()
	{
		return "NumericLiteral " + std::to_string(m_value);
	}

	void print_ast_helper(Node* node, int indent)
	{
		for (size_t i = 0; i < indent; i++) std::cout << "  ";
		std::cout << node->to_string() << '\n';
		if (node->m_children.empty()) return;
		for (auto i : node->m_children) print_ast_helper(i, indent + 1);
	}

	void print_ast(Node* node)
	{
		print_ast_helper(node, 0);
	}

}
