// Q3: Dynamic 2D seat map and RAII destructor
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
class Event {
    int rows, seatsPerRow, bookedCount=0;
    bool** seats;
    std::string name;
public:
    Event(std::string eventName,int r,int s):rows(r),seatsPerRow(s),seats(nullptr),name(std::move(eventName)){
        if(r<0||s<0) throw std::invalid_argument("negative dimensions");
        if(rows==0||seatsPerRow==0) return;
        seats=new bool*[rows]{};
        try { for(int i=0;i<rows;++i) seats[i]=new bool[seatsPerRow]{}; }
        catch(...) { for(int i=0;i<rows;++i) delete[] seats[i]; delete[] seats; throw; }
        std::cout<<"Construct "<<name<<" ("<<rows<<"x"<<seatsPerRow<<")\n";
    }
    bool book(int r,int s){ if(r<0||r>=rows||s<0||s>=seatsPerRow) return false; if(seats[r][s])return false; seats[r][s]=true;++bookedCount;return true; }
    bool cancel(int r,int s){ if(r<0||r>=rows||s<0||s>=seatsPerRow||!seats[r][s])return false;seats[r][s]=false;--bookedCount;return true; }
    ~Event(){ for(int i=0;i<rows;++i) delete[] seats[i]; delete[] seats; std::cout<<"Close "<<name<<"; booked="<<bookedCount<<'\n'; }
};
int main(){
    Event local("Local",2,3); local.book(0,1); local.book(1,2); local.cancel(0,1);
    { Event block("Block",1,2); block.book(0,0); }
    Event* heap=new Event("Heap",2,2); heap->book(1,1); delete heap;
    Event zero("ZeroRows",0,5);
}
