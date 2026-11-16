// Q4: Money arithmetic and stream operator overloading
#include <iostream>
#include <iomanip>
#include <cstdlib>
class Money {
    long long paise;
public:
    Money(long long rupees=0,int p=0):paise(rupees*100+p){}
    explicit Money(long long totalPaise,bool raw):paise(raw?totalPaise:totalPaise*100){}
    Money operator+(const Money& rhs)const{return Money(paise+rhs.paise,true);}
    Money operator-(const Money& rhs)const{return Money(paise-rhs.paise,true);}
    Money& operator+=(const Money& rhs){paise+=rhs.paise;return *this;}
    bool operator==(const Money& rhs)const{return paise==rhs.paise;}
    bool operator<(const Money& rhs)const{return paise<rhs.paise;}
    friend std::ostream& operator<<(std::ostream& os,const Money& m){
        long long v=std::llabs(m.paise); if(m.paise<0)os<<'-';
        return os<<"Rs "<<v/100<<'.'<<std::setw(2)<<std::setfill('0')<<v%100<<std::setfill(' ');
    }
    friend std::istream& operator>>(std::istream& is,Money& m){ long long r; int p; char dot; if(is>>r>>dot>>p&&dot=='.')m.paise=r*100+p;else is.setstate(std::ios::failbit);return is;}
};
int main(){Money a(120,75),b(79,25);Money c=a+b;std::cout<<c<<'\n'<<std::boolalpha<<(c==Money(200))<<'\n';Money carry(0,75),half(0,50);std::cout<<carry+half<<'\n';std::cout<<Money(1,0)-Money(2,25)<<'\n';}
