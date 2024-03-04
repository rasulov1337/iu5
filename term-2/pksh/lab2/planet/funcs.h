#pragma once
#include <fstream>
#include "planet.h"
#include <iomanip>

using namespace std;

#define MAX_PLANET_SIZE 20

void add(Planet*, int& n);
void add(Planet*, int& n, char* newName, int diameter, bool life, int numberOfSatelites);
void del(Planet*, int& n);
void del(Planet* arr, int& n, char* name);
int read_db(char*, Planet*);
int write_db(char*, const Planet*, const int& n);
int menu();
void print_db(Planet*, int);
int find(Planet*, int);
int find(Planet* arr, int n, char* name);
void sort_db(Planet*, int);
const int l_record = 80;

