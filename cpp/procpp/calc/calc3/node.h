#pragma once
#include <string>
#include <vector>

enum ERegister
{
	EAX,
	EBX,
	ECX,
	EDX
};

struct CodeContext
{
	bool bAxInUse;
	bool bBxInUse;
	bool bCxInUse;
	bool bDxInUse;
	ERegister eReturnReg;
	std::vector<std::string> ops;
	
	CodeContext()
		: bAxInUse(false)
		, bBxInUse(false)
		, bCxInUse(false)
		, bDxInUse(false)
	{

	}
};

class Node
{
public:
	virtual void debugOut() = 0;
	virtual void codeGen(CodeContext& c) = 0;
protected:
	void AddOp(CodeContext& c, const std::string& opName);
};

class NInteger : public Node
{
public:
	NInteger(std::string& value);
	void debugOut();
	virtual void codeGen(CodeContext& c);
private:
	int m_int;
	std::string m_sint;
};

class NAdd : public Node
{
public:
	NAdd(Node* lhs, Node* rhs);
	void debugOut();
	virtual void codeGen(CodeContext& c);
private:
	Node* m_lhs;
	Node* m_rhs;
};

class NSub : public Node
{
public:
	NSub(Node* lhs, Node* rhs);
	void debugOut();
	virtual void codeGen(CodeContext& c);
private:
	Node* m_lhs;
	Node* m_rhs;
};

class NMult : public Node
{
public:
	NMult(Node* lhs, Node* rhs);
	void debugOut();
	virtual void codeGen(CodeContext& c);
private:
	Node* m_lhs;
	Node* m_rhs;
};

class NDiv : public Node
{
public:
	NDiv(Node* lhs, Node* rhs);
	void debugOut();
	virtual void codeGen(CodeContext& c);
private:
	Node* m_lhs;
	Node* m_rhs;
};
