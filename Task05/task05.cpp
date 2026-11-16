// Q5: Time ++ overloads and checked Playlist subscript
#include <iostream>
#include <stdexcept>
#include <string>
class Time {
    int seconds;
public:
    explicit Time(int h=0,int m=0,int s=0):seconds(h*3600+m*60+s){if(h<0||m<0||m>59||s<0||s>59)throw std::invalid_argument("invalid time");}
    Time& operator++(){++seconds;return *this;}
    Time operator++(int){Time old=*this;++seconds;return old;}
    bool operator==(const Time& t)const{return seconds==t.seconds;}
    bool operator<(const Time& t)const{return seconds<t.seconds;}
    friend std::ostream& operator<<(std::ostream& os,const Time& t){int h=t.seconds/3600,m=(t.seconds/60)%60,s=t.seconds%60;return os<<h<<':'<<(m<10?"0":"")<<m<<':'<<(s<10?"0":"")<<s;}
};
class Playlist {
    std::string* tracks; int n;
public:
    explicit Playlist(int size):tracks(new std::string[size]),n(size){}
    ~Playlist(){delete[] tracks;}
    Playlist(const Playlist&)=delete; Playlist& operator=(const Playlist&)=delete;
    std::string& operator[](int i){if(i<0||i>=n)throw std::out_of_range("playlist index");return tracks[i];}
    const std::string& operator[](int i)const{if(i<0||i>=n)throw std::out_of_range("playlist index");return tracks[i];}
    int size()const{return n;}
};
int main(){Time t(0,59,58);Time a=t++;Time b=++t;std::cout<<a<<' '<<b<<' '<<t<<'\n';Playlist p(2);p[0]="Track One";p[1]="Track Two";std::cout<<p[1]<<'\n';try{std::cout<<p[-1];}catch(const std::out_of_range&e){std::cout<<"Range error: "<<e.what()<<'\n';}}
