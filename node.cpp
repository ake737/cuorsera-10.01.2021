#include <algorithm>
#include "node.h"
#include "database.h"
#include "condition_parser.h"

using namespace std;

EventComparisonNode::EventComparisonNode(const  Comparison &x, const string &e) : comp(x),  theevent(e) {}
    DateComparisonNode::DateComparisonNode(const  Comparison &x, const Date &e) : comp(x),  thedate(e)  {
    cerr<<"constr: "<<comp<<";";
}
LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& left,const shared_ptr<Node>& right )
        :_left(left),_right(right), _op(op){ }



bool EventComparisonNode::Evaluate(const Date &date, const string &event) const {
    cerr<<"!";
    if (comp==Comparison::Equal){
        return theevent==event;
    }
    return theevent!=event;
}



    bool DateComparisonNode::Evaluate(const Date& date, const string& event) const  {
    cerr<<"DCN: "<<this->comp<<" "<<thedate<<";   ";
        if (comp == Comparison::Less){
             return date<thedate;}
        if (comp == Comparison::Greater){
            return thedate<date;}
        if (comp == Comparison::LessOrEqual){
            cerr<<"<=";
            return date<thedate || date==thedate;}
    if (comp == Comparison::GreaterOrEqual){
    cerr<<">=";
return date==thedate || thedate<date;}
if (comp == Comparison::Equal){
    cerr<<"==";
return date==thedate;}
if (comp == Comparison::NotEqual){
    cerr<<"!=";
return !(date==thedate);}
//throw runtime_error("");
    }

    bool EmptyNode::Evaluate(const Date& date, const string& theevent) const {
        cerr<<"!!!";
        return 1;
    }



    bool LogicalOperationNode::Evaluate(const Date& date, const string& theevent) const  {
        cerr<<"!!";
        Database ans;
        if (_op == LogicalOperation::And) {
            return _left->Evaluate( date, theevent)  && _right->Evaluate(date,  theevent);
        } else if (_op == LogicalOperation::Or) {
            return _left->Evaluate( date, theevent)  || _right->Evaluate(date,  theevent);
        }
    }


