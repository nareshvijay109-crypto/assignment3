// Q1: Book constructors, delegation, validation and explicit conversion
#include <iostream>
#include <stdexcept>
#include <string>
class Book {
    std::string title;
    int copies;
    std::string author;
    static int checked(int n) {
        if (n < 0) throw std::invalid_argument("number of copies cannot be negative");
        return n;
    }
public:
    Book() : Book("Untitled", 0, "Unknown") {}
    explicit Book(const std::string& t) : Book(t, 1, "Unknown") {}
    Book(const std::string& t, int c) : Book(t, c, "Unknown") {}
    Book(const std::string& t, int c, const std::string& a)
        : title(t), copies(checked(c)), author(a) {}
    void print() const { std::cout << title << " | " << author << " | copies=" << copies << '\n'; }
};
int main() {
    Book empty;
    Book donated("The Alchemist");
    Book limited("Clean Code", 4);
    Book complete("C++ Primer", 8, "Lippman");
    empty.print(); donated.print(); limited.print(); complete.print();
    try { Book invalid("Invalid", -2); invalid.print(); }
    catch (const std::invalid_argument& e) { std::cout << "Rejected: " << e.what() << '\n'; }
    // Book implicitBook = std::string("Implicit conversion"); // fails: constructor is explicit
    Book explicitBook(std::string("Explicit conversion")); explicitBook.print();
}
