#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include "MyVector.h"

class MySet : public MyVector {
public:
    explicit MySet(char* el = NULL) : MyVector(el) {};

    friend MySet operator+(const MySet& s1, const MySet& s2);

    friend MySet operator-(const MySet& s1, const MySet& s2);

    friend MySet operator*(const MySet& s1, const MySet& s2);

    bool operator==(const MySet& s);

    MySet& operator+=(const MySet& s);

    MySet& operator-=(const MySet& s);

    MySet& operator*=(const MySet& s);

    void add_element(char* el);

    void delete_element(char* el);

    bool is_element(char* el) const;
private:
    int q_find(char* el) const;
};

#endif //INHERITANCE_MYSET_H
