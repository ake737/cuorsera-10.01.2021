#pragma once
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <string>
#include <vector>
#include <functional>
#include "date.h"

using namespace std;


class Database {
public:
    void Add(const Date& date, const string& event);

    template <typename Predicate> int RemoveIf(const Predicate& predicate){
        int count=0;
        set<string> s;
       for (auto &i:storagev){
           set<string> s=storages[i.first];
            Date d =i.first;
           auto it=remove_if (begin(i.second), end(i.second),
                      [&d,&predicate, &count,&s](const string& event) {if (predicate(d, event)){
                          count++;
                          s.erase(event);
                      return true;}
               return false ;
           });
           i.second.erase(it, end(i.second));
           storages[i.first]=s;
           }
       cerr<<count;

       auto i=storagev.begin();
       auto j=i;
       while (i!=storagev.end()){
           j=i;
           j++;
           if (!i->second.size()){
              storages.erase(i->first);
              storagev.erase(i->first);
           }
           i=j;
       }
       return count;
    }


    set<string> Find(const Date& date) const ;

    void Print(ostream& ss) const ;
    string Last(const Date& d) const ;

    map<Date, set<string>> storages;
    map<Date, vector<string>> storagev;
};