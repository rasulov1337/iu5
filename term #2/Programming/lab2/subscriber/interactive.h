#include "subscriber.h"
#include <iomanip>

using namespace std;

#define MAX_SUBS_NUM 100

void add(Subscriber*, int& n);
void del(Subscriber*, int& n);
int read_db(char*, Subscriber*);
int write_db(char*, const Subscriber*, const int& n);
int menu();
void print_db(Subscriber*, int);
int find(Subscriber*, int);
void sort_db(Subscriber*, int);

int interactive();