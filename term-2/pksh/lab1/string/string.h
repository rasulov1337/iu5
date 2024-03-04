#ifndef STRING_H
#define STRING_H
#include <cstring>

#define DEFAULT_STR_LENGTH 64

namespace not_std {
    class String {
    public:
        String();
        String(const String&);

        ~String();
        String& operator=(const char*);
        String& operator=(char*);
        int length() const;

        char* c_str;

        char* operator+(String& a);
    private:
        int size;
    };
}


#endif