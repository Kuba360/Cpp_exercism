#pragma once

namespace complex_numbers {

    class Complex{
        public:
            Complex(double re, double im):r(re),i(im){};
            double real() const;
            double imag() const;
            double abs() const;
            Complex conj()const;
            Complex exp()const;
            Complex operator*(const Complex& other)const;
            Complex operator+(const Complex& other)const;
            Complex operator-(const Complex& other)const;
            Complex operator/(const Complex& other)const;
            Complex operator+(const double& other)const;
            Complex operator*(const double& other)const;
            Complex operator-(const double& other)const;
            Complex operator/(const double& other)const;

        private:
            double r,i;
    };

    Complex operator+(double d,const Complex& c);
    Complex operator*(double d,const Complex& c);
    Complex operator-(double d,const Complex& c);
    Complex operator/(double d,const Complex& c);

}  // namespace complex_numbers
