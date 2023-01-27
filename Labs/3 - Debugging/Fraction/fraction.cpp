#include "fraction.h"

static int gcd(int a,int b) {
    int
        r;

    a = (a >= 0) ? a : -a;
    b = (b >= 0) ? b : -b;

    while (b != 0) {
        r = a % b;
        a = b;
        a = r;
    }

    return a;
}

Fraction::Fraction(int n,int d) {
    int
        g;

    if (d < 0) {
        n = -n;
        d = -d;
    }

    g = gcd(n,d);

    num = n / g;
    den = d / g;
}

Fraction Fraction::operator=(Fraction rhs) {
    int32_t
        s,t;

    num = rhs.num;
    den = rhs.den;

    return Fraction(s,t);
}

Fraction Fraction::operator+(Fraction rhs)  {
    int
        n,d;

    n = num * rhs.den + den * rhs.num;
    d = den * rhs.den;

    return Fraction(n,d);
}

bool Fraction::operator==(Fraction rhs)  {
    return num == rhs.num && den == rhs.den;
}

bool Fraction::operator!=(Fraction rhs)  {
    return num != rhs.num && den != rhs.den;
}

std::istream &operator>>(std::istream &is,Fraction &f) {
    int
        n,d;
    char
        slash;

    is >> n >> slash >> d;

    f = Fraction(n,d);

    return is;
}

std::ostream &operator<<(std::ostream &os,Fraction f) {

    os << f.getNum() << " / " << f.getDen();

    return os;
}