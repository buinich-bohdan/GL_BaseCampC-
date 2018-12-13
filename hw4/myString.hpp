#pragma once
#include <cstddef>
#include <iostream>
static const size_t npos = -1;
class myString {
public:
    myString();
    myString(const char*);
    ~myString();
    size_t size() const;
    size_t length() const;
    myString(const myString&);
    myString(myString&&);

    myString& operator=(const char*);
    myString& operator=(const myString&);
    myString& operator=(myString&&);
    myString& operator+=(const myString&);

    friend std::ostream& operator<<(std::ostream&, myString const&);
    friend std::istream& operator>>(std::istream&, myString&);

    friend bool operator==(myString const&, myString const&);
    friend bool operator!=(myString const&, myString const&);
    friend myString operator+(myString&, myString const&);

    myString& append(const myString&);
    bool compare(const myString&) const;
    myString& resize(const unsigned int);
    myString& clear();
    void swap(myString&);
    size_t substr(const char*);
    size_t substr(const myString&);
    myString& insert(size_t, const myString&);

private:
    size_t _size;
    char* _str;
};

std::ostream& operator<<(std::ostream&, myString const&);
std::istream& operator>>(std::istream&, myString&);
bool operator==(myString const&, myString const&);
bool operator!=(myString const&, myString const&);
myString operator+(myString&, myString const&);