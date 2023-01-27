#include <cstdint>

#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>

class Fraction {
public:
     Fraction(int32_t n=0,int32_t d=1);
    ~Fraction() = default;

    Fraction operator=(Fraction rhs);

    Fraction operator+(Fraction rhs) ;
    Fraction operator-(Fraction rhs) ;
    Fraction operator*(Fraction rhs) ;
    Fraction operator/(Fraction rhs) ;

    bool operator==(Fraction rhs) ;
    bool operator!=(Fraction rhs) ;
    bool operator<=(Fraction rhs) ;
    bool operator>=(Fraction rhs) ;
    bool operator<(Fraction rhs) ;
    bool operator>(Fraction rhs) ;

    [[nodiscard]] int32_t getNum() const { return num; }
    [[nodiscard]] int32_t getDen() const { return den; }

private:
    int
            num,
            den;
};

std::istream &operator>>(std::istream &,Fraction &);
std::ostream &operator<<(std::ostream &,Fraction);

#endif