#include <iostream>
#include <string>
class Address{std::string city_;int pin_;public:Address(std::string c,int p):city_(c),pin_(p){std::cout<<"Address+ ";}~Address(){std::cout<<"Address- ";}std::string str()const{return city_+"-"+std::to_string(pin_);}};
class Person{protected:std::string name_;int age_;Address home_;public:Person(std::string n,int a,std::string c,int p):name_(n),age_(a),home_(c,p){std::cout<<"Person+ ";}virtual ~Person(){std::cout<<"Person- ";}};
class Course{std::string code_;public:Course(std::string c):code_(c){std::cout<<"Course+ ";}~Course(){std::cout<<"Course- ";}};
class Student:public Person{long long reg_;Course course_;public:Student(std::string n,int a,long long r,std::string c,int p,std::string co):Person(n,a,c,p),reg_(r),course_(co){std::cout<<"Student+ ";}~Student(){std::cout<<"Student- ";}void print()const{std::cout<<reg_<<" "<<name_<<" ("<<age_<<") "<<home_.str()<<'\n';}};
int main(){{Student s("Kavya",19,192311001,"Salem",636001,"CS101");s.print();std::cout<<"| ";}std::cout<<'\n';}
