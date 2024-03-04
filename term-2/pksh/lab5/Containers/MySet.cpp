#include "MySet.h"

bool MySet::operator==(const MySet& s)
{
	if (size != s.Size())
		return false;
	
	for (int i = 0; i < size; ++i)
		if (strcmp(pdata[i], s[i]) != 0)
			return false;
	return true;
}

MySet& MySet::operator+=(const MySet& s)
{
	for (int i = 0; i < s.Size(); ++i)
		add_element(s[i]);
	return *this;
}

MySet& MySet::operator-=(const MySet& s)
{
	for (int i = 0; i < s.Size(); ++i) {
		delete_element(s[i]);
	}
	return *this;
}

MySet& MySet::operator*=(const MySet& s)
{
	MySet toDelete;
	for (int i = 0; i < Size(); ++i) {
		if (!s.is_element(pdata[i])) {
			toDelete.add_element(s[i]);
		}
	}

	for (int i = 0; i < toDelete.Size(); ++i)
		delete_element(toDelete[i]);
	return *this;
}

void MySet::add_element(char* el)
{
	if (is_element(el))
		return;

	this->MyVector::add_element(el);
	this->MyVector::sort();
}

void MySet::delete_element(char* el)
{
	int ind = q_find(el);
	if (ind != -1)
		MyVector::delete_element(ind);
}

bool MySet::is_element(char* el) const
{
	return q_find(el) != -1;
}


int MySet::q_find(char* el) const {
	int l = 0;
	int r = size - 1;

	while (l <= r) {
		int mid = (r + l) / 2;
		if (strcmp(pdata[mid], el) == 0) {
			return mid;
		}
		else if (strcmp(pdata[mid], el) > 0)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}


MySet operator+(const MySet& s1, const MySet& s2)
{
	MySet newSet;
	for (int i = 0; i < s1.Size(); ++i)
		newSet.add_element(s1[i]);
	for (int i = 0; i < s2.Size(); ++i)
		newSet.add_element(s2[i]);
	return newSet;
}

MySet operator-(const MySet& s1, const MySet& s2)
{
	MySet newSet(s1);
	for (int i = 0; i < s2.Size(); ++i) {
		newSet.delete_element(s2[i]);
	}
	return newSet;
}

MySet operator*(const MySet& s1, const MySet& s2)
{
	MySet newSet;
	for (int i = 0; i < s1.Size(); ++i)
		if (s2.is_element(s1[i]))
			newSet.add_element(s1[i]);
	return newSet;
}
