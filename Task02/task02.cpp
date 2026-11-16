// Q2: Prescription with Rule of Three and deep copying
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
class Prescription {
    int n;
    std::string* medicines;
public:
    explicit Prescription(int count) : n(count), medicines(count > 0 ? new std::string[count] : nullptr) {
        if (count < 0) throw std::invalid_argument("negative medicine count");
    }
    Prescription(const Prescription& other)
        : n(other.n), medicines(n > 0 ? new std::string[n] : nullptr) {
        for (int i=0;i<n;++i) medicines[i]=other.medicines[i];
        std::cout << "[copy constructor] ";
    }
    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            std::string* fresh = other.n > 0 ? new std::string[other.n] : nullptr;
            for (int i=0;i<other.n;++i) fresh[i]=other.medicines[i];
            delete[] medicines; medicines=fresh; n=other.n;
        }
        return *this;
    }
    ~Prescription() { delete[] medicines; }
    void set(int i,const std::string& m){ if(i<0||i>=n) throw std::out_of_range("medicine index"); medicines[i]=m; }
    std::string get(int i) const { if(i<0||i>=n) throw std::out_of_range("medicine index"); return medicines[i]; }
};
void byValue(Prescription p) { (void)p; }
void byConstReference(const Prescription& p) { (void)p; }
int main(){
    Prescription p(2); p.set(0,"Paracetamol"); p.set(1,"ORS");
    Prescription q=p; q.set(1,"Cetirizine");
    Prescription r(1); r=p; p.set(0,"Ibuprofen"); r=r;
    std::cout<<p.get(0)<<' '<<p.get(1)<<" | "<<q.get(0)<<' '<<q.get(1)
             <<" | "<<r.get(0)<<' '<<r.get(1)<<'\n';
    byValue(p); byConstReference(p);
}
