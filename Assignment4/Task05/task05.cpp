#include <iomanip>
#include <iostream>
#include <string>
class Cart{std::string items_[10];double prices_[10]{};int n_=0;double discount_=0;public:Cart&add(const std::string&i,double p){if(n_<10){items_[n_]=i;prices_[n_++]=p;}return *this;}Cart&setDiscount(double discount){this->discount_=discount;return *this;}double total()const{double t=0;for(int i=0;i<n_;++i)t+=prices_[i];return t*(100-discount_)/100;}};
int main(){Cart c;c.add("Rice",60).add("Dal",120).setDiscount(10);Cart*p=&c;p->add("Oil",180);std::cout<<std::fixed<<std::setprecision(2)<<p->total()<<'\n';Cart*heap=new Cart;heap->add("Milk",50);std::cout<<heap->total()<<'\n';delete heap;Cart*customers[]={&c};Cart*highest=customers[0];for(Cart*x:customers)if(x->total()>highest->total())highest=x;std::cout<<"Highest="<<highest->total()<<'\n';}
