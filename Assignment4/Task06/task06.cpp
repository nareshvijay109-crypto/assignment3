#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Vehicle{std::string reg_;double rate_;bool rented_=false;public:Vehicle(std::string r,double d):reg_(r),rate_(d){}virtual~Vehicle()=default;std::string reg()const{return reg_;}double rate()const{return rate_;}void rent(){if(rented_)throw std::logic_error("already rented");rented_=true;}void giveBack(){if(!rented_)throw std::logic_error("not rented");rented_=false;}virtual double charge(int days)const=0;virtual std::string type()const=0;};
class Bicycle:public Vehicle{public:using Vehicle::Vehicle;double charge(int d)const override{return rate()*d;}std::string type()const override{return "Bicycle";}};
class MotorVehicle:public Vehicle{double fuel_;std::string service_;protected:MotorVehicle(std::string r,double d,double f,std::string s):Vehicle(r,d),fuel_(f),service_(s){}};
class TwoWheeler:public MotorVehicle{public:TwoWheeler(std::string r,double d,double f,std::string s):MotorVehicle(r,d,f,s){}double charge(int n)const override{return rate()*n;}std::string type()const override{return "TwoWheeler";}};
class Car:public MotorVehicle{int seats_;public:Car(std::string r,double d,double f,std::string s,int seats):MotorVehicle(r,d,f,s),seats_(seats){}double charge(int n)const override{return rate()*n+100;}std::string type()const override{return "Car";}};
class ElectricCar:public Vehicle{double battery_;public:ElectricCar(std::string r,double d,double b):Vehicle(r,d),battery_(b){}double charge(int n)const override{return rate()*n+battery_*2.5;}std::string type()const override{return "ElectricCar";}};
class ElectricBus:public Vehicle{int capacity_;public:ElectricBus(std::string r,double d,int c):Vehicle(r,d),capacity_(c){}double charge(int n)const override{return rate()*n+capacity_*5;}std::string type()const override{return "ElectricBus";}};
int main(){std::vector<std::unique_ptr<Vehicle>> f;f.emplace_back(std::make_unique<Bicycle>("CYC01",100));f.emplace_back(std::make_unique<TwoWheeler>("TN01",250,70,"2026-12-01"));f.emplace_back(std::make_unique<Car>("TN02",1500,60,"2026-12-15",5));f.emplace_back(std::make_unique<ElectricCar>("EV03",1800,60));f.emplace_back(std::make_unique<ElectricBus>("EB04",4000,30));for(auto&v:f){v->rent();std::cout<<v->type()<<" "<<v->reg()<<" charge="<<v->charge(2)<<'\n';v->giveBack();std::cout<<"Returned with late fee total="<<v->charge(3)+250<<'\n';}}
