/*----------------------------------------------------------------
file: str.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has str class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef str_H
#define str_H

#include "../darray/darray.h"

/*----------------------------------------------------------------
Declaration of str class
-----------------------------------------------------------------*/
class str {
public:
   str(const char* p, bool verbose=false);
   str(char p, bool verbose=false);
   ~str();
   str(const str& s);
   void reverse();
   friend int string_compare(str s1, str s2);
   friend bool operator==(const str& s1, const str& s2);
   friend bool operator!=(const str& s1, const str& s2);
   friend ostream& operator<<(ostream& o, const str& s);
   friend str operator+(const str &s1, char ch);
   friend str operator+(char ch, const str &s1);
   friend str operator+(const str& s1, const char * p);
   char getChar(int i) const;
   int getSize() const;

private:
  bool _display;
  darray<char> _string;
  int _size;
};

#endif

//EOF

