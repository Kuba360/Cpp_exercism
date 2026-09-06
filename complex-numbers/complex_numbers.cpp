#include "complex_numbers.h"
#include <cmath>
namespace complex_numbers {

// TODO: add your solution here
            double Complex::real() const{
                return r;
            }
            double Complex::imag() const{
                return i;
            }
            double Complex::abs() const{
                return std::sqrt(std::pow(r,2)+std::pow(i,2));
            }
            Complex Complex::conj()const{
                Complex nc(r,-i);
                return nc;
            }
            Complex Complex::exp()const{
                
                Complex nc(std::exp(r)*std::cos(i),std::exp(r)*std::sin(i));
                return nc;
            }
            Complex Complex::Complex::operator*(const Complex& other)const{
                return Complex{r*other.real()-i*other.imag(),i*other.real()+r*other.imag()};
            };
            Complex Complex::operator+(const Complex& other)const{
                return Complex{r+other.real(),i+other.imag()};
            };
            Complex Complex::operator-(const Complex& other)const{
                return Complex{r-other.real(),i-other.imag()};
            };
            Complex Complex::operator/(const Complex& other)const{
                return Complex{(r*other.real()+i*other.imag())/(other.real()*other.real()+other.imag()*other.imag()),
                    (i*other.real()-r*other.imag())/(other.real()*other.real()+other.imag()*other.imag())};
            };
            Complex Complex::operator+(const double& other)const{
                return Complex{r+other,i};
            };
            Complex Complex::operator*(const double& other)const{
                return Complex{r*other,i*other};
            };
            Complex Complex::operator-(const double& other)const{
                return Complex{r-other,i};
            };
            Complex Complex::operator/(const double& other)const{
                return Complex{r/other,i/other};
            };

    Complex operator+(double d,const Complex& c){
        return Complex{d+c.real(),c.imag()};
    }
    Complex operator*(double d,const Complex& c){
        return Complex{c.real()*d,c.imag()*d};
    }
    Complex operator-(double d,const Complex& c){
        return Complex{d-c.real(),-c.imag()};
    }
    Complex operator/(double d,const Complex& c){
        return Complex{d*(c.real()/(c.real()*c.real()+c.imag()*c.imag())),
            -d*(c.imag()/(c.real()*c.real()+c.imag()*c.imag()))};
    }
}  // namespace complex_numbers
