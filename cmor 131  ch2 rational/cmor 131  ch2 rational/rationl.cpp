#include "Rational.h"


//postcondition: returns the value of numerator
int Rational::getNumerator() const
{
    return numerator;
}

//precon: The function expects two integer inputs, a and b, which represent the two numbers for which the GCD needs to be calculated.
//postcon: The function returns an integer, which is the GCD of the two input integers a and b.
int Rational::gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//precon: The constructor expects two integer inputs, num and denom, which represent the numerator and denominator of a rational number.
//postcon: If the denom is not equal to zero, the constructor initializes the Rational object with the provided num, else siple form

//         
// 
Rational::Rational(int num, int denom) : numerator(num), denominator(denom)
{
    if (denominator == 0)
    {
        denominator = 1;
    }
    normalize();
}


//postcon: After the function is executed, the Rational object it was called on is modified to represent the simplified form of the rational number.
// 
//         If the numerator is zero, it sets the denominator to 1 to avoid division by zero.
//         It finds the GCD of the absolute values of the numerator and denominator, then divides both numerator and denominator by the GCD to simplify the fraction. 
//         If negative it negects eberythnig else
void Rational::normalize()
{
    if (numerator == 0)
    {
        denominator = 1; // Avoid division by zero
    }
    else
    {
        int commonDivisor = gcd(abs(numerator), abs(denominator));
        numerator /= commonDivisor;
        denominator /= commonDivisor;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
}


//postcon: After the function is executed, it returns a new Rational object that represents the result of adding the Rational object it was called on (*this)
//         and the other Rational object.
// 
//         The new Rational object is constructed with a numerator equal to(numerator* other.denominator) + (other.numerator * denominator)
//         and a denominator equal to denominator * other.denominator.
// 
//         The resulting Rational object is expected to represent the sum of the two input rational numbers.
Rational Rational::add(const Rational& other) const
{
    int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
    int newDenominator = denominator * other.denominator;
    return Rational(newNumerator, newDenominator);
}


//postcondition: returns an object with the value of *this object and the parameter object added together
Rational Rational::operator+(const Rational& other)
{
    int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
    int newDenominator = denominator * other.denominator;
    return Rational(newNumerator, newDenominator);
}


//postcon: After the function is executed, it returns a new Rational object that represents the result of subtracting the Rational object it was called on (*this)
//         and the other Rational object.
// 
//         The new Rational object is constructed with a numerator equal to(numerator* other.denominator) - (other.numerator * denominator)
//         and a denominator equal to denominator * other.denominator.
// 
//         The resulting Rational object is expected to represent the subtraction of the other rational number from the * this rational number.
Rational Rational::subtract(const Rational& other) const
{
    int newNumerator = (numerator * other.denominator) - (other.numerator * denominator);
    int newDenominator = denominator * other.denominator;
    return Rational(newNumerator, newDenominator);
}


//postcondition: returns an object with the difference value of *this object and the parameter object
Rational Rational::operator-(const Rational& other)
{
    int newNumerator = (numerator * other.denominator) - (other.numerator * denominator);
    int newDenominator = denominator * other.denominator;
    return Rational(newNumerator, newDenominator);
}


//postcon: After the function is executed, it returns a new Rational object that represents the result of multiplying the Rational object it was called on (*this)
//         and the other Rational object.
// 
//         The new Rational object is constructed with a numerator equal to numerator* other.numerator and a denominator equal to denominator* other.denominator.
// 
//         The resulting Rational object is expected to represent the multiplication of the* this rational number by the other rational number.
Rational Rational::multiply(const Rational& other) const
{
    int newNumerator = numerator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return Rational(newNumerator, newDenominator);
}


//postcondition: returns an object with the value of *this object multiplied by the parameter object
Rational Rational::operator*(const Rational& other)
{
    int newNumerator = numerator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return Rational(newNumerator, newDenominator);
}


//postcon: After the function is executed, it returns a new Rational object that represents the result of dividing the Rational object it was called on (*this)
//         by the other Rational object.
// 
//         The code checks if other.numerator is zero and prints an error message to cerr(standard error stream) if it is.
// 
//         If other.numerator is not zero, the new Rational object is constructed with a numerator equal to numerator* other.denominator
//         and a denominator equal to denominator* other.numerator.
// 
//         The resulting Rational object is expected to represent the division of the* this rational number by the other rational number.
Rational Rational::divide(const Rational& other) const
{
    if (other.numerator == 0)
    {
        cerr << "\nError: Division by zero." << endl;
    }

    int newNumerator = numerator * other.denominator;
    int newDenominator = denominator * other.numerator;
    return Rational(newNumerator, newDenominator);
}


//precondition: The Rational object passed in must not have a value of 0 in its numerator or denominator
//postcondition: returns an object with the value of *this object divided by the parameter object
Rational Rational::operator/(const Rational& other)
{
    int newNumerator = numerator * other.denominator;
    int newDenominator = denominator * other.numerator;
    return Rational(newNumerator, newDenominator);
}


//postcon: After the function is executed, it returns a boolean value.
// 
//         The function compares the product of numerator* other.denominator with the product of other.numerator* denominator
//         and returns true if they are equal, indicating that the* this object and other represent the same rational number. 
//         If the products are not equal, rerturn false.
bool Rational::isEqual(const Rational& other) const
{
    return (numerator * other.denominator == other.numerator * denominator);
}


//postcondition: returns true if the values represented by *this object and the parameter object are equal, else false
bool Rational::operator==(const Rational& other)
{
    return (numerator * other.denominator == other.numerator * denominator);
}


//postcon: After the function is executed, it returns a boolean value.
// 
//         The function compares the product of numerator* other.denominator with the product of other.numerator* denominator
//         and returns true if the former is less than the latter, indicating that the* this object represents a rational number that is less than the other rational number. 
//         If the products are not in this order, the function returns false,
//         indicating that the* this object represents a rational number that is not less than the other rational number.
bool Rational::isLessThan(const Rational& other) const
{
    return (numerator * other.denominator < other.numerator * denominator);
}


//postcondition: returns true if the value represented by *this object is less than that of the parameter object, else false
bool Rational::operator<(const Rational& other)
{
    return (numerator * other.denominator < other.numerator * denominator);
}


//postcon: After the function is executed, it returns an output stream (os).
// 
//         The function outputs the Rational object in the format numerator / denominator to the output stream.
// 
//         The resulting output stream can be used for further output operations.
ostream& operator<<(ostream& os, const Rational& rational)
{
    os << rational.numerator << "/" << rational.denominator;
    return os;
}


//postcon: After the function is executed, it returns an input stream (is).
//         The function reads the numerator and denominator values from the input stream, with a slash in the middle.
//         If the denominator is read as zero, it prints an error message to indicate that the denominator cannot be zero.

istream& operator>>(istream& is, Rational& rational)
{
    char slash;
    is >> rational.numerator >> slash >> rational.denominator;
    if (rational.denominator == 0)
    {
        cerr << "\nError: Denominator cannot be zero." << endl;
    }
    rational.normalize();
    return is;
}