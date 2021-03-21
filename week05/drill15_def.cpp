//Órai megoldás

#include "std_lib_facilities.h"
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

#undef vector

struct Person {
    Person(std::string first_name, std::string second_name, int age) {
        if (age < 0 || age > 150)
            error("Ilyen nincs\n");
        else
            m_age = age;

        std::string forbidden{";:\"'[]*&^%$#@"};
        for (auto c : forbidden) {
            if (first_name.find(c) != std::string::npos)
                error("Nem kéne\n");
        }

        for (auto c : forbidden) {
            if (second_name.find(c) != std::string::npos)
                error("Nem kéne\n");
        }

        m_first_name = first_name;
        m_second_name = second_name;
    }
    int age() const {
        return m_age;
    }

    std::string first_name() const {
        return m_first_name;
    }

    std::string second_name() const {
        return m_second_name;
    }

    std::string name() const {
        return m_first_name + " " + m_second_name;
    }

private:
    std::string m_first_name;
    std::string m_second_name;
    int         m_age;
};

std::ostream &operator<<(std::ostream &o, Person p) {
    o << p.name() << " " << p.age() << '\n';
    return o;
}

std::istream &operator>>(std::istream &i, Person &p) {
    std::string tmp_first_name, tmp_second_name;
    int         tmp_age;

    i >> tmp_first_name >> tmp_second_name >> tmp_age;
    p = Person{tmp_first_name, tmp_second_name, tmp_age};

    return i;
}

int main() {
    Person bufer{"", "", 0};

    std::vector<Person> person_vec;

    while (std::cin >> bufer) {
        person_vec.push_back(bufer);
    }

    for (auto i : person_vec)
        std::cerr << i;
}
