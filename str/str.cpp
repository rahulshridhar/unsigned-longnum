/*----------------------------------------------------------------
file: str.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "str.h"

/*----------------------------------------------------------------
Definition of routines of str class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Constructor
-----------------------------------------------------------------*/
str::str(const char* p, bool verbose): _display(verbose)
{
    if (_display) {
        cout << "Inside str constructor 1"<<endl;
    }

    _string = darray<char>(strlen(p)+1, verbose);
    _size = strlen(p);
    
    for (int i = 0; i < _size; i++)
    {
        _string[i] = p[i];
    }

    _string[_size] = '\0';
}

str::str(char p, bool verbose): _display(verbose)
{
    if (_display) {
        cout << "Inside str constructor 2"<<endl;
    }

    _string = darray<char>(1, verbose);
    _size = 1;
    _string[0] = p;
    _string[_size] = '\0';
}

/*----------------------------------------------------------------
Destructor
-----------------------------------------------------------------*/
str::~str() {
    if (_display) {
        cout << "Inside str destructor "<<endl;
    }
}

/*----------------------------------------------------------------
Copy constructor
-----------------------------------------------------------------*/
str::str(const str& s): _display(s._display), _size(s._size), _string(s._string)
{
    if (_display) {
        cout << "Inside str copy constructor "<<endl;
    }
}

/*----------------------------------------------------------------
Function to reverse a string
-----------------------------------------------------------------*/
void str::reverse()
{
    if (_size == 1) return;
    for (int i = 0; i < _size/2; i++)
    {
        swap(_string[i], _string[_size-i-1]);
    }
}

/*----------------------------------------------------------------
Function to compare two strings
-----------------------------------------------------------------*/
int string_compare(str s1, str s2)
{
    int i, j; 
    for (i = 0, j = 0; s1._string[i]!='\0', s2._string[j]!='\0'; i++, j++)
    {
        if (s1._string[i] > s2._string[j]) return 1;
        if (s1._string[i] < s2._string[j]) return -1;    
    } 
    if (s1._string[i] == '\0') return 1;
    if (s2._string[j] == '\0') return -1;
    return 0;
}

/*----------------------------------------------------------------
EQUAL EQUAL operator
-----------------------------------------------------------------*/
bool operator==(const str& s1, const str& s2)
{
    if (s1._display) {
        cout << "Inside EQUAL operator "<<endl;
    }
    
    if (s1._size != s2._size)
    {
        return false;
    }

    bool equal = true;
    int i = 0;
    while (s1._string[i] != '\0')
    {
        if (s1._string[i] != s2._string[i])
        {
            equal = false;
            break;
        }
        i++;
    }
    return equal;
}

/*----------------------------------------------------------------
NOT EQUAL operator
-----------------------------------------------------------------*/
bool operator!=(const str& s1, const str& s2)
{
    if (s1._display) {
        cout << "Inside NOT EQUAL operator "<<endl;
    }
    return (!(s1 == s2));
}

/*----------------------------------------------------------------
<< operator
-----------------------------------------------------------------*/
ostream& operator<<(ostream& o, const str& s)
{
    if (s._display) {
        cout << "Inside << operator "<<endl;
    }
    int i = 0;
    while (s._string[i] != '\0')
    {
        o << s._string[i];
        i++;
    }
    return o;
}

/*----------------------------------------------------------------
+ operator
-----------------------------------------------------------------*/
str operator+(const str& s1, char ch)
{
    if (s1._display) {
        cout << "Inside first operator"<<endl;
    }
    str temp = s1;
    temp._string[temp._size] = ch;
    temp._string[temp._size+1] = '\0';
    temp._size++;
    return temp;
}

str operator+(char ch, const str& s1)
{
    if (s1._display) {
        cout << "Inside second operator"<<endl;
    }
    str temp = ch;
    int i = 0;
    while (s1._string[i] != '\0')
    {
        temp._string[i+1] = s1._string[i];
        temp._size++;
        i++;
    }
    temp._string[temp._size] = '\0';
    return temp;
}

str operator+(const str& s1, const char* p)
{
    if (s1._display) {
        cout << "Inside third operator"<<endl;
    }
    str temp = s1;
    for (int i = 0; i < strlen(p); i++)
    {
        temp._string[s1._size+i] = p[i];
        temp._size++;
    }
    temp._string[temp._size] = '\0';
    return temp;
}

char str::getChar(int i) const
{
    return _string[i];
}

int str::getSize() const
{
    return _size;
}

//EOF


