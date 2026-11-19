#include <iostream>
#include <memory>
#include <vector>
class Account{public:virtual double rate()const{return 3.5;}virtual ~Account(){std::cout<<"~Account ";}};
class SeniorAccount:public Account{double* history_;public:SeniorAccount():history_(new double[100]{}){}double rate()const override{return 4.0;}~SeniorAccount()override{delete[]history_;std::cout<<"~Senior ";}};
int main(){std::vector<std::unique_ptr<Account>> a;a.emplace_back(std::make_unique<Account>());a.emplace_back(std::make_unique<SeniorAccount>());for(auto&x:a)std::cout<<x->rate()<<'\n';Account sliced=SeniorAccount();std::cout<<"sliced="<<sliced.rate()<<'\n';}
