#include "group.h"

class AbstractExpression{
public:
    virtual bool evaluate(std::string s) = 0;
};

class TerminalExpression : public AbstractExpression{
public:
    TerminalExpression(std::string s) : context(s) {}

    bool evaluate(std::string s){
        if( s.find(context) == std::string::npos )
            return false;
        else
            return true;
    }

private:
    std::string context;
};

class OrExpression : public AbstractExpression{
public:
    OrExpression(AbstractExpression* a1, AbstractExpression* a2) : expression1(a1), expression2(a2) {}

    bool evaluate(std::string s){
        return expression1->evaluate(s) || expression2->evaluate(s);
    }

private:
    AbstractExpression* expression1;
    AbstractExpression* expression2;
};

class AndExpression : public AbstractExpression{
public:
    AndExpression(AbstractExpression* a1, AbstractExpression* a2) : expression1(a1), expression2(a2) {}

    bool evaluate(std::string s){
        return expression1->evaluate(s) && expression2->evaluate(s);
    }

private:
    AbstractExpression* expression1;
    AbstractExpression* expression2;
};