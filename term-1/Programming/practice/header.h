#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctype.h>

using namespace std;

#define DATA_FILENAME "data.txt"

// Авиарейс
struct Flight {
	string from; // Пункт отправления
	string to;  // Пункт прибытия
	string departureTime; // Время отправления
};

string trim(string str);

int menu();
void addFlight(vector<Flight>& flights);
void editFlight(vector<Flight>& flights);
void printFlights(vector<Flight>& flights, bool withNumeration=false);
void deleteFlight(vector<Flight>& flights);
void searchFlight(vector<Flight>& flights);
void saveData(vector<Flight>& flights);
void loadData(vector<Flight>& flights);
string getInputText();
string getTimeAsString();
int getInputInt();