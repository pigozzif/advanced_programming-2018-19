#include <iostream>


// Exercise one

enum class Month {january=1, february, march, april, may,
        june, july, august, september, october, november, december};


class Date {
    int _day;
    Month _month;
    int _year;
    public:
        Date (const int day, const int month, const int year) : _day{day}, _month{Month(month)}, _year{year} {}
        int day() const {
            return _day;
        }
        int month() const noexcept {
            return int(_month);
        }
        int year() const noexcept {
            return _year;
        }
        void add_days(const unsigned int n) noexcept {
            for (int i=0; i < n; i++) add_day();
        }
    private:
        void add_day() noexcept;
};

void Date::add_day() noexcept {
    switch (_month) {
        case Month::january : case Month::march : case Month::may :
        case Month::july : case Month::august : case Month::october :
            ++_day;
            if (_day == 32) {
                _day = 1;
                _month = Month(int(_month) + 1);
            }
            break;
        case Month::april : case Month::june : case Month::september : case Month::november :
            ++_day;
            if (_day == 31) {
                _day = 1;
                _month = Month(int(_month) + 1);
            }
            break;
        case Month::february :
            ++_day;
            if (_day == 30) {
                _day = 1;
                _month = Month(3);
            }
            break;
       case Month::december :
           ++_day;
           if (_day == 32) {
                _day = 1;
                _month = Month(1);
                ++_year;
           }
           break;
    }
}


// Exercise two

bool operator==(const Date& lhs, const Date& rhs) {
    if (lhs.day() == rhs.day() && lhs.month() == rhs.month() && lhs.year() == rhs.year()) return true;
    else return false;
}


bool operator!=(const Date& lhs, const Date& rhs) {
    return !(lhs==rhs);
}


std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.day() << "/" << date.month() << "/" << date.year() << std::endl;
    return os;
}


bool is_leap(const int y) {
    return (y % 4 == 0 && y % 400 != 0);
}


// Exercises three and four

template<typename num>
class Vector {
    num* elem;
    std::size_t _size;
    public:
        Vector(std::size_t size) : elem{nullptr}, _size{size} {
            try {
                elem = new num[size];
            }
            catch (...) {
                delete[] elem;
                throw;
            }
        }

        ~Vector() noexcept {delete[] elem;}

        num* begin() noexcept {return &elem[0];}
        num* begin() const noexcept {return &elem[0];}
        num* end() noexcept {return &elem[_size];}
        num* end() const noexcept {return &elem[_size];}

        std::size_t size() const noexcept {return _size;}

        auto& operator[](const std::size_t pos) const noexcept {return elem[pos];}    // Switched to "auto" return type
};


template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
    for (auto& x : vector) os << x << std::endl;
}

// In general, I think that C++ 14 moved in the direction of improved "ease of writing" for the programmer side (sometimes at the expense of readability,
//as we can see from the opportunity to return auto


// Main function

int main() {
    Vector<double> test{10};
    for (auto i=0u; i < 10; i++) test[i] = i;
    std::cout << test;
    return 0;
}
