#include <iostream>
#include <string>
class Person{protected:std::string name_;int id_;std::string phone_;public:Person(std::string n,int i,std::string p):name_(n),id_(i),phone_(p){}virtual ~Person()=default;};
class Student:virtual public Person{protected:std::string programme_;double cgpa_;public:Student(std::string n,int i,std::string p,std::string pr,double c):Person(n,i,p),programme_(pr),cgpa_(c){}};
class Staff:virtual public Person{protected:std::string dept_;double salary_;public:Staff(std::string n,int i,std::string p,std::string d,double s):Person(n,i,p),dept_(d),salary_(s){}};
class TeachingAssistant:public Student,public Staff{public:TeachingAssistant(std::string n,int i,std::string p,std::string pr,double c,std::string d,double s):Person(n,i,p),Student(n,i,p,pr,c),Staff(n,i,p,d,s){}void print()const{std::cout<<name_<<" "<<programme_<<" "<<dept_<<" "<<cgpa_<<" "<<salary_<<'\n';}};
class ResearchScholar:public Student{double fellowship_;public:ResearchScholar(std::string n,int i,std::string p,std::string pr,double c,double f):Person(n,i,p),Student(n,i,p,pr,c),fellowship_(f){}void print()const{std::cout<<name_<<" "<<programme_<<" fellowship="<<fellowship_<<'\n';}};
int main(){TeachingAssistant t("Kavya",501,"9000000001","MTech",8.7,"CSE",42000);ResearchScholar r("Mohan",502,"9000000002","PhD",9.1,25000);t.print();r.print();std::cout<<"TA size="<<sizeof(t)<<'\n';}
