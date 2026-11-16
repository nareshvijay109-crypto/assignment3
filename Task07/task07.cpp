// Q7: Complex impedance calculator from first principles
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
class Complex {
    double re,im;
public:
    Complex():re(0),im(0){}
    Complex(double real):re(real),im(0){}
    Complex(double real,double imag):re(real),im(imag){}
    double real()const{return re;} double imag()const{return im;}
    Complex operator+(const Complex& z)const{return {re+z.re,im+z.im};}
    Complex operator-(const Complex& z)const{return {re-z.re,im-z.im};}
    Complex operator*(const Complex& z)const{return {re*z.re-im*z.im,re*z.im+im*z.re};}
    Complex operator/(const Complex& z)const{double d=z.re*z.re+z.im*z.im;if(d==0.0)throw std::domain_error("division by zero impedance");return {(re*z.re+im*z.im)/d,(im*z.re-re*z.im)/d};}
    bool operator==(const Complex& z)const{return std::abs(re-z.re)<1e-9&&std::abs(im-z.im)<1e-9;}
    double magnitude()const{return std::hypot(re,im);}
    friend std::ostream& operator<<(std::ostream& os,const Complex& z){return os<<std::fixed<<std::setprecision(3)<<z.re<<(z.im<0?" - j":" + j")<<std::abs(z.im);}
};
Complex parallel(const Complex&a,const Complex&b){return (a*b)/(a+b);}
int main(){
    const double pi=std::acos(-1.0),f=50.0,w=2*pi*f,L=0.1,C=100e-6;
    Complex R(10),XL(0,w*L),XC(0,-1.0/(w*C));
    Complex series=R+XL+XC;
    Complex parallelZ=parallel(R,XL);
    std::cout<<"R="<<R<<" ohm, |R|="<<R.magnitude()<<'\n';
    std::cout<<"Series RLC impedance="<<series<<" ohm, magnitude="<<series.magnitude()<<'\n';
    std::cout<<"Parallel R-L impedance="<<parallelZ<<" ohm\n";
    try{Complex zero;std::cout<<(R/zero)<<'\n';}catch(const std::domain_error&e){std::cout<<"Safe error: "<<e.what()<<'\n';}
}
