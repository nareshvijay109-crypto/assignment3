#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Staff{std::string name_;int id_;double basic_;protected:Staff(std::string n,int i,double b):name_(n),id_(i),basic_(b){}double basic()const{return basic_;}public:virtual ~Staff()=default;virtual double pay()const=0;void print()const{std::cout<<name_<<" #"<<id_<<" pay="<<pay()<<'\n';}};
class Professor:public Staff{double research_;public:Professor(std::string n,int i,double b,double r):Staff(n,i,b),research_(r){}double pay()const override{return basic()*1.42+research_;}};
class LabAssistant:public Staff{public:LabAssistant(std::string n,int i,double b):Staff(n,i,b){}double pay()const override{return basic()*1.42;}};
class GuestFaculty:public Staff{double hours_,rate_;public:GuestFaculty(std::string n,int i,double h,double r):Staff(n,i,0),hours_(h),rate_(r){}double pay()const override{return hours_*rate_;}};
int main(){std::vector<std::unique_ptr<Staff>> v;v.emplace_back(std::make_unique<Professor>("Anita",101,50000,8000));v.emplace_back(std::make_unique<LabAssistant>("Bala",102,30000));v.emplace_back(std::make_unique<GuestFaculty>("Charan",103,80,600));double total=0;for(auto&x:v){x->print();total+=x->pay();}std::cout<<"Total="<<total<<'\n';}
