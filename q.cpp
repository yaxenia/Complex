//
// Created by Кссения Якунина on 2019-03-04.
//

#include <iostream>
#include <math.h>

class Complex {
public:
    double re, im;
    // creating a complex number:
    Complex (double re = 0, double im = 0) : re(re), im(im) {}
    //binary operations with to complex:
    //sum:
    Complex operator+ (const Complex & oper) {
        double real, imag;
        real = this -> re + oper.re;
        imag = this -> im + oper.im;
        return Complex (real, imag);
    }
    //subsrt:
    Complex operator- (const Complex & oper) {
        double real, imag;
        real = this -> re - oper.re;
        imag = this -> im - oper.im;
        return Complex (real, imag);
    }
    //
    //product
    Complex operator* (const Complex & oper) {
        double real, imag;
        real = this -> re * oper.re - this -> im * oper.im;
        imag = this -> re * oper.im + this -> im * oper.re;
        return Complex (real, imag);
    }
    //
    //division:
    Complex operator/ (const Complex & oper) {
        double real, imag, div = (pow(oper.re, 2.) + pow(oper.im, 2.));
        real = (this -> re * oper.re + this -> im * oper.im)/div;
        imag = (this -> im * oper.re - this -> re * oper.im)/div;
        return Complex (real, imag);
    }
    //
    /*
     now let's make those with real numbers :
     */
    // postoperators: preoperators are defined out of the class
    Complex operator+ (const int oper) {
        double real, imag;
        real = this -> re + oper;
        imag = this -> im;
        return Complex (real, imag);
    }
    //
    Complex operator- (const int oper) {
        double real, imag;
        real = this -> re - oper;
        imag = this -> im;
        return Complex (real, imag);
    }
    //
    Complex operator* (const int oper) {
        double real, imag;
        real = this -> re * oper;
        imag = this -> im * oper;
        return Complex (real, imag);
    }
    //
    Complex operator/ (const int oper) {
        double real, imag;
        real = this -> re / oper;
        imag = this -> im / oper;
        return Complex (real, imag);
    }
    /*
     now let's do the rest :
     */
    //equality
    bool operator== (const Complex & oper) {
        if (this -> re == oper.re and this -> im == oper.im) {
            return true;
        } else {
            return false;
        }
    }
    //unequality
    bool operator!= (const Complex & oper) {
        if (this -> re != oper.re or this -> im != oper.im) {
            return true;
        } else {
            return false;
        }
    }
    //unary operators :
    //sum
    Complex operator+ () {
        return Complex (this -> re, this -> im);;
    }
    //substr
    Complex operator- () {
        return Complex (-1 * this -> re, -1 * this -> im);
    }
    // real and imag parts of z
    double Re() const;
    double Im() const;
};

//abs
double abs (const Complex num) {
    return sqrt(pow(num.re, 2.) + pow(num.im, 2.));
}
// real part :
double Complex::Re() const {
    return this -> re;
}
// imaginary part :
double Complex::Im() const {
    return this -> im;
}
/*
 now let's defined preoperators:
 */
// addition :
Complex operator+ (const int oper, const Complex & num) {
    return Complex (num.re + oper, num.im);
}
// sunstr :
Complex operator- (const int oper, const Complex & num) {
    return Complex (num.re - oper, num.im);
}
// product :
Complex operator* (const int oper, const Complex & num) {
    return Complex (num.re * oper, num.im * oper);
}
// division :
Complex operator/ (const int oper, const Complex & num) {
    return Complex (num.re / oper, num.im / oper);
}

//output
std::ostream& operator<< (std::ostream & os, const Complex num) {
    os << num.re << " + " << num.im << 'i' << std::endl;
    return os;
}

int main() {
    Complex a (1, 1), b (1, 1), z (10, 17);
    if (a == b) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 2 << std::endl;
    }
    std::cout << z.Re() << " " << z.Im() << std::endl;
    std::cout << a * 2 << 23 * b;
    std::cout << a + 2 << 23 + b << std::endl;
    return 0;
}