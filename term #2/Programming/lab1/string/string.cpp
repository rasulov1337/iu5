#include "string.h"
#include "string.h"
#include "string.h"


namespace not_std {
	String::String() {
		c_str = new char[DEFAULT_STR_LENGTH];
		c_str[0] = '\0';
		size = DEFAULT_STR_LENGTH;
	}

	String::String(const String& s) {
		size = s.length();
		c_str = new char[size];
		strcpy(c_str, s.c_str);
	}


	String::~String() {
		delete[] c_str;
	}

	String& String::operator=(const char* text) {
		delete c_str;
		size = strlen(text) + 1;
		c_str = new char[size];
		for (int i = 0; i < size; ++i)
			c_str[i] = text[i];
		c_str[size - 1] = '\0';
		return *this;
	}

	String& String::operator=(char* text) {
		delete c_str;
		size = strlen(text) + 1;
		c_str = new char[size];
		for (int i = 0; i < size; ++i)
			c_str[i] = text[i];
		c_str[size - 1] = '\0';
		return *this;
	}


	char* String::operator+(String& a)
	{
		char* c = new char[length() + a.length() + 1];
		for (int i = 0; i < length(); ++i)
			c[i] = c_str[i];
		
		for (int j = 0; j < a.length(); ++j)
			c[length() + j] = a.c_str[j];
		c[length() + a.length()] = '\0';
		
		return c;
	}

	

	int String::length() const {
		return size - 1; // Without null char
	}
}
