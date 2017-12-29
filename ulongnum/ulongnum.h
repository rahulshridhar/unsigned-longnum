/*----------------------------------------------------------------
file: ulongnum.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ulongnum class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ulongnum_H
#define ulongnum_H

#include "../str/str.h"

/*--------------------------------------------------------
class ulongnum
----------------------------------------------------------*/
class ulongnum {
public:
  ulongnum(int number=0, bool verbose=false);
  ulongnum(const char* p, bool verbose=false);
  ulongnum(char p, bool verbose=false);
  ~ulongnum();
  ulongnum(const ulongnum& u);
  ulongnum& operator=(const ulongnum& rhs);
  friend ulongnum operator+(const ulongnum& u, int number);
  friend ulongnum operator+(int number, const ulongnum& u);
  friend ulongnum operator+(const ulongnum& u1, const ulongnum& u2);
  friend ulongnum operator-(const ulongnum& u1, const ulongnum& u2);
  friend ulongnum operator*(ulongnum& u1, ulongnum& u2);
  friend bool operator==(const ulongnum& u, int number);
  friend bool operator==(const ulongnum& u, const ulongnum& u2);
  friend ostream& operator<<(ostream& o, const ulongnum& u);
  friend ulongnum mult(ulongnum& u1, ulongnum& u2);
  void set_display(bool verbose);
  void factorial(int number);

private:
  bool _display;
  str _s;
  void _copy(const ulongnum& u);

};

#endif
//EOF

