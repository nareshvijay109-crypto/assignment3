// Q6: Text class implementing Rule of Three and operators
#include <iostream>
#include <cstring>
class Text {
    char* data;
public:
    explicit Text(const char* s=""){std::size_t n=std::strlen(s);data=new char[n+1];std::memcpy(data,s,n+1);}
    Text(const Text& other){std::size_t n=std::strlen(other.data);data=new char[n+1];std::memcpy(data,other.data,n+1);std::cout<<"[copy] ";}
    Text& operator=(const Text& other){if(this!=&other){std::size_t n=std::strlen(other.data);char* fresh=new char[n+1];std::memcpy(fresh,other.data,n+1);delete[] data;data=fresh;}return *this;}
    ~Text(){delete[] data;}
    Text operator+(const Text& rhs)const{std::size_t a=std::strlen(data),b=std::strlen(rhs.data);char* temp=new char[a+b+1];std::memcpy(temp,data,a);std::memcpy(temp+a,rhs.data,b+1);Text result(temp);delete[] temp;return result;}
    bool operator==(const Text& rhs)const{return std::strcmp(data,rhs.data)==0;}
    bool operator!=(const Text& rhs)const{return !(*this==rhs);}
    friend std::ostream& operator<<(std::ostream& os,const Text& t){return os<<t.data;}
};
int main(){Text a("Hello "),b("World"),c("!");Text message=a+b+c;std::cout<<'\n'<<message<<'\n';Text empty;Text copy=message;copy=copy;std::cout<<std::boolalpha<<(copy==message)<<' '<<(empty!=message)<<'\n';}
