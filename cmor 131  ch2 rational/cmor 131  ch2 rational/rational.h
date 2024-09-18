#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b); // Greatest common divisor

public:
    //constructor
    Rational(int num = 0, int denom = 1);

    //function that normalizes the rational number that the object represents
    void normalize();

    //accessor to check value before division
    int getNumerator() const;

    Rational add(const Rational& other) const;
    Rational operator+(Rational const& obj);

    Rational subtract(const Rational& other) const;
    Rational operator-(Rational const& obj);

    Rational multiply(const Rational& other) const;
    Rational operator*(Rational const& obj);

    Rational divide(const Rational& other) const;
    Rational operator/(Rational const& obj);

    bool operator==(Rational const& obj);
    bool operator<(Rational const& obj);

    bool isEqual(const Rational& other) const;
    bool isLessThan(const Rational& other) const;

    friend ostream& operator<<(ostream& os, const Rational& rational);
    friend istream& operator>>(istream& is, Rational& rational);
};
