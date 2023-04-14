#pragma once
#include <conio.h>

using namespace std;

bool strEq(char* str1, char* str2);
char* getLastWord(char* str);
bool eachLetterAppearsAtLeastTwice(char* str);
void strPrint(char* str);
void strCpy(char* dest, char* src, int len);
int strLen(char* str);

char* getInput();

#define BUFF_SIZE 256
