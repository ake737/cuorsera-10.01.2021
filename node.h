#pragma  once
#include <iostream>
#include <algorithm>
#include <memory>
#include <stack>
#include <vector>
#include <string>
#include <cstdint>
#include "database.h"
#include "enum.h"




using namespace std;
struct Node {
    virtual bool Evaluate( const Date& date, const string& theevent) const = 0;
};

struct DateComparisonNode : public Node {
    DateComparisonNode(const Comparison &x, const Date &e) ;

    bool Evaluate(const Date& date, const string& theevent) const override;

private:
    const Date &thedate;
    const   Comparison &comp;

};

struct EventComparisonNode : public Node {
    EventComparisonNode(const  Comparison &x, const string &e) ;

    bool Evaluate(const Date& date, const string& event) const override;
private:
    const string &theevent;
    const  Comparison &comp;
};

struct EmptyNode : public Node{
    bool Evaluate(const Date& date, const string& event) const override;
};
struct LogicalOperationNode : public Node {
    LogicalOperationNode(const LogicalOperation& op,const shared_ptr<Node>& left,const shared_ptr<Node>& right );

   bool Evaluate(const Date& date, const string& theevent) const override ;

//private:
    LogicalOperation _op;
    shared_ptr<Node> _left, _right;
};
