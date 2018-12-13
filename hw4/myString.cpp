#include "myString.hpp"
#include <cstring>

myString::myString()
    : _size(0)
    , _str(nullptr)
{
}

myString::myString(const char* str)
{
    if (!str)
        return;
    _size = strlen(str);
    _str = new char[_size + 1];
    strncpy(_str, str, _size + 1);
}

myString::myString(const myString& String)
{
    std::cout << "Copy const" << std::endl;
    _size = String._size;
    _str = new char[_size + 1];
    strncpy(_str, String._str, _size + 1);
}

myString::myString(myString&& String)
{
    std::cout << "move const" << std::endl;
    _size = String._size;
    _str = String._str;
    String._str = nullptr;
}

myString& myString::operator=(const myString& String)
{
    std::cout << "copy assignment" << std::endl;
    if (this == &String)
        return *this;
    delete[] _str;
    _size = String._size;
    char* new_data = new char[_size + 1];
    strncpy(new_data, String._str, _size + 1);
    _str = new_data;
    return *this;
}

myString& myString::operator=(myString&& String)
{
    std::cout << "move assignment" << std::endl;
    using std::swap;
    swap(_str, String._str);
    swap(_size, String._size);
    return *this;
}

myString::~myString()
{
    if (_str != nullptr) {
        delete[] _str;
        _size = 0;
    }
}

size_t myString::size() const
{
    return _size;
}

myString& myString::operator=(const char* str)
{
    if (!str)
        return *this;

    this->~myString();
    _size = strlen(str);
    _str = new char[_size + 1];
    strncpy(_str, str, _size + 1);
    return *this;
}

myString operator+(myString& String1, myString const& String2)
{
    String1 += String2;
    return String1;
}

myString& myString::operator+=(const myString& String)
{
    _size = _size + String._size;

    char* tmp = new char[_size + 1];
    strncpy(tmp, _str, _size);
    strncat(tmp, String._str, _size);

    delete[] _str;
    _str = tmp;

    return *this;
}
std::ostream& operator<<(std::ostream& os, myString const& String)
{
    os << String._str;
    return os;
}

std::istream& operator>>(std::istream& is, myString& String)
{
    if (String._str)
        String.~myString();

    String._str = new char[256];
    is.getline(String._str, 255);
    String._size = strlen(String._str);

    return is;
}

bool operator==(myString const& String1, myString const& String2)
{
    return !(strcmp(String1._str, String2._str));
}

bool operator!=(myString const& String1, myString const& String2)
{
    return !(operator==(String1, String2));
}

myString& myString::append(const myString& String)
{
    _size = String._size + _size;
    _str = (char*)realloc(_str, _size + 1);
    strcat(_str, String._str);
    return *this;
}

bool myString::compare(const myString& String) const
{
    return !(operator==(*this, String));
}
size_t myString::length() const
{
    return _size;
}

myString& myString::resize(const unsigned int size)
{
	char *tmp = new char[size + 1];
	if (_str)
	{
		strncpy(tmp, _str, size);
		tmp[size] = '\0';
	}
	else
		memset(tmp, '\0', size + 1);

	if (_str)
		delete [] _str;
	_str = tmp;
	_size = size;
	return *this;
}

myString& myString::clear()
{
    this->~myString();
    return *this;
}

void myString::swap(myString& String)
{
    std::swap(*this, String);
}

size_t myString::substr(const char* str)
{
    if (!_str || !str)
        return npos;

    if (*str == '\0')
        return npos;

    int i = 0, j = 0, k = 0;
    while (_str[i] != '\0') {
        k = i;
        while (_str[k] == str[j]) {
            ++k;
            ++j;
            if (str[j] == '\0')
                return i;
        }
        ++i;
    }
    return npos;
}

size_t myString::substr(const myString& String)
{
    if (!_str || !String._str)
        return npos;

    if (*String._str == '\0')
        return npos;

    int i = 0, j = 0, k = 0;
    while (_str[i] != '\0') {
        k = i;
        while (_str[k] == String._str[j]) {
            ++k;
            ++j;
            if (String._str[j] == '\0')
                return i;
        }
        ++i;
    }
    return npos;
}

myString& myString::insert(size_t pos, const myString& String)
{
    if (!_str || !String._str || pos < 0 || pos >= _size)
        return *this;

    _size = _size + String._size;
    char* tmp = new char[_size + 1];

    strncpy(tmp, _str, pos);
    strncpy(tmp + pos, String._str, String._size);
    strncpy(tmp + pos + String._size, _str + pos, _size - pos);

    tmp[_size] = '\0';
    delete[] _str;
    _str = tmp;
    return *this;
}