/*----------------------------------------------------------------
file: ulongnum.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ulongnum.h"

/*----------------------------------------------------------------
Definition of routines of ulongnum class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Constructor
-----------------------------------------------------------------*/
ulongnum::ulongnum(int number, bool verbose): _s("", verbose), _display(verbose)
{
    if (_display) {
        cout<<"In first ulongnum constructor "<<endl;
    }

    if (number == 0) 
    {
        char c = number + '0';
        _s = _s + c;
    }
    while (number > 0)
    {
        int digit = number % 10;
        char c = digit + '0';
        _s = _s + c;
        number = number / 10;
    }
    _s.reverse();
}

ulongnum::ulongnum(const char* p, bool verbose): _s("", verbose), _display(verbose)
{
    if (_display) {
        cout<<"In second ulongnum constructor"<<endl;
    }
    _s = p;
}

ulongnum::ulongnum(char p, bool verbose): _s("", verbose), _display(verbose)
{
    if (_display) {
        cout<<"In third ulongnum constructor"<<endl;
    }
    _s = p;
}
/*----------------------------------------------------------------
Destructor
-----------------------------------------------------------------*/
ulongnum::~ulongnum() {
    if (_display) {
        cout<<"In ulongnum destructor"<<endl;
    }
}

/*----------------------------------------------------------------
Helper: copy function
-----------------------------------------------------------------*/
void ulongnum::_copy(const ulongnum& from)
{
    _s = from._s;
}

/*----------------------------------------------------------------
Copy constructor
-----------------------------------------------------------------*/
ulongnum::ulongnum(const ulongnum& u): _s("", u._display), _display(u._display)
{
    if (_display) {
        cout<<"In ulongnum copy constructor"<<endl;
    }
    _copy(u);
}

/*----------------------------------------------------------------
EQUAL operator
-----------------------------------------------------------------*/
ulongnum& ulongnum::operator=(const ulongnum& rhs)
{
    if (_display) {
        cout<<"In ulongnum = operator"<<endl;
    }
    if (this != &rhs) {
        _copy(rhs);
    }
    return *this;
}

/*----------------------------------------------------------------
PLUS operator
-----------------------------------------------------------------*/
ulongnum operator+(const ulongnum& u, int number)
{
    if (u._display) {
        cout<<"In first + operator:"<<endl;
    }
    int i = 0;
    int carry = 0;
  
    ulongnum temp = 0;
    ulongnum temp_2 = u;
    temp_2._s.reverse();
    
    while (temp_2._s.getChar(i) != '\0' && number != 0)
    {
        int digit = number % 10;
        int u1 = temp_2._s.getChar(i) - '0';
        int u2 = digit;
        int sum = u1 + u2 + carry;
        
        char append = (sum % 10) + '0';
        carry = sum/10;
        if (i == 0) temp._s = append;
        else temp._s = temp._s + append;
        
        i++;
        number = number / 10;
    }
    if (number == 0)
    {
        while (temp_2._s.getChar(i) != '\0')
        {
            int u1 = (temp_2._s.getChar(i) - '0');
            int sum = u1 + carry;
            char append = (sum % 10) + '0';
            carry = sum/10;
            temp._s = temp._s + append;
            i++;
        }
    }
    if (temp_2._s.getChar(i) != '\0')
    {
        while (number != 0)
        {
            int u1 = number % 10;
            int sum = u1 + carry;
            char append = (sum % 10) + '0';
            carry = sum/10;
            temp._s = temp._s + append;
            number = number / 10;
        }
    }
    temp._s.reverse(); 
    return temp;
}

ulongnum operator+(int number, const ulongnum& u)
{
    if (u._display) {
        cout<<"In second + operator:"<<endl;
    }
    ulongnum temp = u + number;
    return temp;
}

ulongnum operator+(const ulongnum& u1, const ulongnum& u2)
{
    if (u1._display) {
        cout<<"In third + operator:"<<endl;
    }
    int i = 0;
    int carry = 0;
  
    ulongnum temp = 0;
    ulongnum temp_1 = u1;
    ulongnum temp_2 = u2;
    temp_1._s.reverse();
    temp_2._s.reverse();
    
    while (temp_1._s.getChar(i) != '\0' && temp_2._s.getChar(i) != '\0')
    {
        int u1 = temp_1._s.getChar(i) - '0';
        int u2 = temp_2._s.getChar(i) - '0';
        int sum = u1 + u2 + carry;
        
        char append = (sum % 10) + '0';
        carry = sum/10;
        if (i==0) temp._s = append;
        else temp._s = temp._s + append;
        
        i++;
    }
    if (temp_1._s.getChar(i) == '\0' && temp_2._s.getChar(i) == '\0')
    {
        if (carry) {
            temp._s = temp._s + ((carry%10) + '0');
        }
        temp._s.reverse(); 
        return temp;
    }
    if (temp_1._s.getChar(i) != '\0')
    {
        while (temp_1._s.getChar(i) != '\0')
        {
            int u1 = (temp_1._s.getChar(i) - '0');
            int sum = u1 + carry;
            char append = (sum % 10) + '0';
            carry = sum/10;
            temp._s = temp._s + append;
            i++;
        }
        if (carry) {
            temp._s = temp._s + ((carry%10) + '0');
        }
        temp._s.reverse(); 
        return temp;
    }
    if (temp_2._s.getChar(i) != '\0')
    {
        while (temp_2._s.getChar(i) != '\0')
        {
            int u1 = (temp_2._s.getChar(i) - '0');
            int sum = u1 + carry;
            char append = (sum % 10) + '0';
            carry = sum/10;
            temp._s = temp._s + append;
            i++;
        }
    }
    if (carry) {
        temp._s = temp._s + ((carry%10) + '0');
    }
    temp._s.reverse(); 
    return temp;
}

/*----------------------------------------------------------------
EQUAL EQUAL Operator
-----------------------------------------------------------------*/
bool operator==(const ulongnum& u, int number)
{
    if (u._display) {
        cout<<"In == operator:"<<endl;
    }
    int i = 0;
    int carry = 0;
  
    ulongnum temp = 0;
    
    while (number != 0)
    {
        int digit = number % 10;
        int u1 = digit;
        char append = (u1 % 10) + '0';
        if (i == 0) temp._s = append;
        else temp._s = temp._s + append;
        number = number / 10;
        i++;
    }
    temp._s.reverse();

    return (u._s == temp._s);    
}

bool operator==(const ulongnum& u1, const ulongnum& u2)
{
    return (u2._s == u1._s);
}

/*----------------------------------------------------------------
Partial product algorithm to multiply large numbers
-----------------------------------------------------------------*/
ulongnum mult(ulongnum& u1, ulongnum& u2)
{
    if (u1._display) {
        cout<<"In mult:"<<endl;
    }
    int i = 0;
    int carry = 0;
    int size_u1 = u1._s.getSize()-1;
    int size_u2 = u2._s.getSize()-1;
    int dup_u2 = size_u2;
    int dup_u1 = size_u1;
    int result = 0;

    ulongnum sum = 0;
    int step = 0;
    while (dup_u2 >= 0)
    {
        int inside_step = 0;
        ulongnum temp = 0;
        dup_u1 = size_u1;
        for (i = size_u2; i > dup_u2; i--)
        {
            if (inside_step == 0)
            {
                temp._s = '0';
                inside_step++;
            }
            else temp._s = temp._s + '0';
        }
        int digit_u2 = u2._s.getChar(dup_u2) - '0';
        while (dup_u1 >= 0)
        {
            int digit_u1 = u1._s.getChar(dup_u1) - '0';
            int product = digit_u1 * digit_u2 + carry;
            result = product % 10;
            carry = product/10;
            
            if (inside_step == 0)
            {
                temp._s = (result+'0');
                inside_step++;
            }
            else temp._s = temp._s + (result+'0');

            dup_u1--;
        }
        if (carry) {
            temp._s = temp._s + (carry + '0');
            carry = 0;
        }
        temp._s.reverse();
        sum = sum + temp;
        
        dup_u2--;
    }
    
    return sum;
}

/*----------------------------------------------------------------
Multiply Operator (*)
-----------------------------------------------------------------*/
ulongnum operator*(ulongnum& u1, ulongnum& u2)
{
    if (u1._display) {
        cout<<"In * operator:"<<endl;
    }
    
    ulongnum temp = mult(u1, u2);
    return temp;
}

/*----------------------------------------------------------------
<< Operator
-----------------------------------------------------------------*/
ostream& operator<<(ostream& o, const ulongnum& u)
{
    o << u._s;
    return o;
}

void ulongnum::set_display(bool verbose)
{
    _display = verbose;
}

void ulongnum::factorial(int number)
{
    ulongnum fact = 1;
    for (int i = 2; i <= number; i++)
    {
        ulongnum num = i;
        fact = fact * num;
    }
    *this = fact;
}


//EOF


