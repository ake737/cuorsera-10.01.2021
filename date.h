#pragma once
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
    class Date {
    public:
        // конструктор выбрасывает исключение, если его аргументы некорректны
        Date(int new_year, int new_month, int new_day) ;

        int GetYear() const ;
        int GetMonth() const ;
        int GetDay() const ;

    private:
        int year;
        int month;
        int day;
    };

    bool operator<(const Date& lhs, const Date& rhs) ;
bool operator==(const Date& lhs, const Date& rhs) ;

// даты будут по умолчанию выводиться в нужном формате
ostream& operator<<(ostream& stream, const Date& date) ;


Date ParseDate( istream& date_stream) ;