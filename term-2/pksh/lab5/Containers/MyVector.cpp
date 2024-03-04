#include "MyVector.h"

MyVector::MyVector(char* el, int maxsz) {
	maxsize = maxsz;
	pdata = new char* [maxsize];
	size = 0;
	
	if (!el)
		return;

	add_element(el);
}


MyVector::MyVector(const MyVector& v) {
	maxsize = v.Maxsize();
	size = v.Size();
	pdata = new char* [size];
	for (int i = 0; i < size; ++i) {
		pdata[i] = new char[strlen(v[i]) + 1];
		strcpy(pdata[i], v[i]);
	}
}

MyVector::~MyVector() {
	if (pdata) {
		for (int i = 0; i < size; ++i)
			delete[] pdata[i];
		delete[] pdata;
	}
}

MyVector& MyVector::operator=(const MyVector& v) {
	if (this == &v)
		return *this;

	this->~MyVector();
	maxsize = v.Maxsize();
	size = v.Size();
	pdata = new char* [size];
	for (int i = 0; i < size; ++i) {
		pdata[i] = new char[strlen(v[i]) + 1];
		strcpy(pdata[i], v[i]);
	}
	return *this;
}

void MyVector::add_element(char* el) {
	char* cpy = new char[strlen(el) + 1];
	strcpy(cpy, el);

	pdata[size++] = cpy;
	resize();
}


bool MyVector::delete_element(int i) {
	if (i < 0 || i >= size)
		return false;
	delete[] pdata[i];
	for (int k = i; k < size; ++k)
		pdata[k] = pdata[k + 1];
	--size;
	resize();
	return true;
}

void MyVector::resize() {
	int newMaxSize;
	if (maxsize == size)
		newMaxSize = size * 1.5;
	else if (size < maxsize / 2)
		newMaxSize = MAX((int)(size / 1.5), MAX_SIZE);
	else
		return;
	char** newPointer = new char* [newMaxSize];
	if (pdata) {
		for (int i = 0; i < size; ++i)
			newPointer[i] = pdata[i];
		delete[] pdata;
	}

	pdata = newPointer;
	maxsize = newMaxSize;
}


int MyVector::find(char* el) const {
	for (int i = 0; i < size; ++i)
		if (strcmp(el, pdata[i]) == 0)
			return i;
	return -1;
}

char* MyVector::operator[](int i) const {
	if (i < 0 || i > size)
		return nullptr;
	return pdata[i];
}


void MyVector::sort() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == j)
				continue;
			if (strcmp(pdata[i], pdata[j]) < 0) {
				std::swap(pdata[i], pdata[j]);
			}
		}
	}
}

std::ostream& operator<<(std::ostream& out, const MyVector& v)
{
	if (v.Size() == 0) {
		out << "{}";
		return out;
	}

	out << '{' << '"' << v[0] << '"';

	for (int i = 1; i < v.Size(); ++i)
		out << ", \"" << v[i] << '"';
	out << "}\n";
	return out;
}
