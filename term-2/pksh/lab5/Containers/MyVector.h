#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>
#include <cstring>

const int MAX_SIZE = 5;

#define MAX(a, b) (a < b) ? b : a

class MyVector {
public:
    explicit MyVector(char* el = NULL, int maxsz = MAX_SIZE);

    MyVector(const MyVector& v);

    ~MyVector();

    void add_element(char* el);

    bool delete_element(int i);

    char* operator[](int i) const;

    void sort();

    int Size() const { return size; }

    int Maxsize() const { return maxsize; }

    int find(char* el) const;

    MyVector& operator=(const MyVector& v);

    friend std::ostream& operator<<(std::ostream& out, const MyVector& v);

protected:
    int maxsize;
    int size;
    char** pdata;
private:
    void resize();
};

#endif //INHERITANCE_MYVECTOR_H
