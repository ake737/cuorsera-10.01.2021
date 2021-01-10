#include "database.h"
#include <iterator>
using namespace std;

    void Database::Add(const Date& date, const string& event) {
        storages[date].insert(event);
        storagev[date].push_back(event);
    }


    set<string> Database::Find(const Date& date) const {
        return {};
    }

    void Database::Print(ostream& ss) const {
        for (const auto& item : storagev) {
            for (const string& event : item.second) {
                ss << item.first << " " << event << endl;

            }
        }
    }
    string Database::Last(const Date& d) const {
        stringstream  ss;
        auto thedate=storagev.upper_bound(d);
        if (thedate==storagev.begin()){
            throw invalid_argument("");
        }
        thedate--;
        ss<<thedate->first<<" "<<thedate->second[thedate->second.size()-1]<<endl;
        string ans;
        getline(ss,ans);


        return ans;
    }
