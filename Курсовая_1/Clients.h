#ifndef INC_1_2_CLIENTS_H
#define INC_1_2_CLIENTS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
struct PHONE {
    int number;

    PHONE(int);
    ~PHONE() = default;

    PHONE() : number() {}

    bool operator>(const PHONE&) const;
    bool operator==(const PHONE&) const;
    bool operator<(const PHONE&) const;
    bool operator>=(const PHONE&) const;
    bool operator<=(const PHONE&) const;
    bool operator!=(const PHONE&) const;
    operator std::string() const {
        std::string s = "";
        msclr::interop::marshal_context context;
        s += context.marshal_as<std::string>(number.ToString());
        return s;
    };
    friend std::ostream& operator<<(std::ostream&, const PHONE&);
};

struct FIO {
    std::string surname;
    std::string name;
    std::string f_name;

    FIO(std::string, std::string, std::string);
    ~FIO() = default;

    FIO() : surname(""), name(""), f_name("") {}

    bool operator>(const FIO&) const;
    bool operator==(const FIO&) const;
    bool operator<(const FIO&) const;
    bool operator>=(const FIO&) const;
    bool operator<=(const FIO&) const;
    bool operator!=(const FIO&) const;
    operator std::string() const {
        std::string s = "";
        s += surname + name + f_name;
        return s;
    }
    friend std::ostream& operator<<(std::ostream&, const FIO&);
};

struct DB {
    int day;
    int month;
    int year;

    DB(int, int, int);
    ~DB() = default;

    DB() : day(), month(), year() {}

    bool operator>(const DB&) const;
    bool operator==(const DB&) const;
    bool operator<(const DB&) const;
    bool operator>=(const DB&) const;
    bool operator<=(const DB&) const;
    bool operator!=(const DB&) const;
    operator std::string() const {
        std::string s = "";
        msclr::interop::marshal_context context;
        s += context.marshal_as<std::string>(day.ToString() + "." + month.ToString() + "." + year.ToString());
        return s;
    }
    friend std::ostream& operator<<(std::ostream&, const DB&);
};

struct Adress {
    std::string address;

    Adress(std::string);
    ~Adress() = default;

    Adress() : address("") {}

    bool operator>(const Adress&) const;
    bool operator==(const Adress&) const;
    bool operator<(const Adress&) const;
    bool operator>=(const Adress&) const;
    bool operator<=(const Adress&) const;
    bool operator!=(const Adress&) const;
    operator std::string() const {
        return address;
    }
    friend std::ostream& operator<<(std::ostream&, const Adress&);
};

class Person {
public:
    PHONE phone;
    FIO fio;
    DB date;
    Adress address;

public:
    Person(int, std::string, std::string, std::string, int, int, int, std::string);
    Person();
    ~Person() = default;
    friend std::ostream& operator<<(std::ostream&, const Person&);

    const FIO& getFIO() const {
        return fio;
    };

    const Adress& getADRESS() const {
        return address;
    };

    const DB& getDB() const {
        return date;
    };

    const PHONE& getNUM() const {
        return phone;
    };
};

#endif //INC_1_2_CLIENTS_H