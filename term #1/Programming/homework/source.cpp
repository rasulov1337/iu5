#include "header.h"


char* getInput() {
	char* text = new char[BUFF_SIZE];
	int len = 0;

	char c = ' ';
	while (c != '.')
	{
		c = _getch();

		if ((c >= 'a' && c <= 'z') || c == ' ')
		{
			_putch(c);
			text[len] = c;
			++len;
		}
		else if (c == '.')
			_putch('.');
		else if (c == '\b' && len != 0)
		{
			--len;
			_putch('\b');
			_putch(' ');
			_putch('\b');
		}
	}
	_putch('\n');
	text[len] = '\0';
	return text;
}

bool strEq(char* str1, char* str2) {
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0') {
		if (str1[i] != str2[i])
			return false;
		++i;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return true;
	return false;
}

void strCpy(char* dest, char* src, int len) {
	for (int i = 0; i < len; ++i)
		dest[i] = src[i];
}

int strLen(char* str) {
	int i = 0;
	while (str[i] != '\0') 
		++i;
	return i;
}

char* getLastWord(char* str) {
	int b = strLen(str);
	while (str[b] == ' ' || str[b] == '\0') {
		--b;
	}

	int a = b;
	while (a != 0 && str[a - 1] != ' ') {
		--a;
	}

	int subLen = b - a + 1;

	char* res = new char[subLen + 1];
	strCpy(res, str + a, subLen);
	res[subLen] = '\0';
	return res;
}

bool eachLetterAppearsAtLeastTwice(char* str) {
	int i = 0, stats[256];
	for (; i < 256; ++i)
		stats[i] = 0;
	
	i = 0;
	while (str[i] != '\0') {
		++stats[str[i]];
		++i;
	}

	for (i = 0; i < 256; ++i)
		if (stats[i] == 1)
			return false;
	return true;
}

void strPrint(char* str) {
	for (int i = 0; str[i] != '\0'; ++i)
		_putch(str[i]);
}