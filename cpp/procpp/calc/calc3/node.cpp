#include "node.h"
#include <iostream>


void Node::AddOp( CodeContext& c, const std::string& opName)
{
	std::string temp("pop ebx");
	c.ops.push_back(temp);
	temp = "pop eax";
	c.ops.push_back(temp);
	if (opName == "idiv")
	{
		temp = "cdq";
		c.ops.push_back(temp);
	}

	if (opName == "add" || opName == "sub")
	{
		temp = opName + " eax,ebx";
	}
	else
	{
		temp = opName + " ebx";
	}

	c.ops.push_back(temp);

	temp = "push eax";
	c.ops.push_back(temp);
}

NInteger::NInteger( std::string& value )
{
	m_int = std::atoi(value.c_str());
	m_sint = value;
}

void NInteger::debugOut()
{
	std::cout << m_int;
}

void NInteger::codeGen( CodeContext& c )
{
	std::string temp = "push " + m_sint;
	c.ops.push_back(temp);
}

NAdd::NAdd( Node* lhs, Node* rhs )
	: m_lhs(lhs)
	, m_rhs(rhs)
{

}

void NAdd::debugOut()
{
	std::cout << "(";
	m_lhs->debugOut();
	std::cout << "+";
	m_rhs->debugOut();
	std::cout << ")";
}

void NAdd::codeGen( CodeContext& c )
{
	m_lhs->codeGen(c);
	m_rhs->codeGen(c);

	AddOp(c, std::string("add"));
}

NSub::NSub( Node* lhs, Node* rhs )
	: m_lhs(lhs)
	, m_rhs(rhs)
{
}

void NSub::debugOut()
{
	std::cout << "(";
	m_lhs->debugOut();
	std::cout << "-";
	m_rhs->debugOut();
	std::cout << ")";
}

void NSub::codeGen( CodeContext& c )
{
	m_lhs->codeGen(c);
	m_rhs->codeGen(c);

	AddOp(c, std::string("sub"));
}

NMult::NMult( Node* lhs, Node* rhs )
	: m_lhs(lhs)
	, m_rhs(rhs)
{

}

void NMult::debugOut()
{
	std::cout << "(";
	m_lhs->debugOut();
	std::cout << "*";
	m_rhs->debugOut();
	std::cout << ")";
}

void NMult::codeGen( CodeContext& c )
{
	m_lhs->codeGen(c);
	m_rhs->codeGen(c);

	AddOp(c, std::string("imul"));
}

NDiv::NDiv( Node* lhs, Node* rhs )
	: m_lhs(lhs)
	, m_rhs(rhs)
{

}

void NDiv::debugOut()
{
	std::cout << "(";
	m_lhs->debugOut();
	std::cout << "/";
	m_rhs->debugOut();
	std::cout << ")";
}

void NDiv::codeGen( CodeContext& c )
{
	m_lhs->codeGen(c);
	m_rhs->codeGen(c);

	AddOp(c, std::string("idiv"));
}
