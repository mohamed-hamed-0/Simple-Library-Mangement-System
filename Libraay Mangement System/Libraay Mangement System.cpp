#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string _title;
    float _price;
    int _id;
    bool _isAvailable;

public:
    Book(string title, float price, int id, bool isAva = true) {
        this->_title = title;
        this->_price = price;
        this->_id = id;
        this->_isAvailable = isAva;
    }

   
    int getid() const { return _id; }
    bool getstatus() const { return _isAvailable; }

    
    void borrowBook() {
        _isAvailable = false;
    }

    void returnBook() {
        _isAvailable = true;
    }

    void displayBook() const {
        cout << "=====================\n";
        cout << "Title : " << _title << endl;
        cout << "Id : " << _id << endl;
        cout << "Price : " << _price << " EGP\n";
        cout << "Available : " << (_isAvailable ? "Yes" : "No") << endl;
        cout << "=====================\n";
    }
};

class Library {
private:
    vector<Book> vb;

public:
    void addBook(const Book& book) {
        vb.push_back(book);
    }

    void displayAllBooks() const {
        for (const auto& book : vb) {
            book.displayBook();
        }
    }

    void borrowBook(int id) {
        for (int i = 0; i < vb.size(); i++) {
            if (vb[i].getid() == id) {
                if (vb[i].getstatus()) {
                    vb[i].borrowBook();
                    cout << "Successful Borrow for Book ID: " << id << "\n";
                }
                else {
                    cout << "Borrow Failed: Book ID " << id << " is already borrowed!\n";
                }
                return; 
            }
        }
        cout << "Borrow Failed: Book ID " << id << " Not Found!\n";
    }

    void returnBook(int id) {
        for (int i = 0; i < vb.size(); i++) {
            if (vb[i].getid() == id) {
                if (!vb[i].getstatus()) { 
                    vb[i].returnBook();
                    cout << "Successful Return for Book ID: " << id << "\n";
                }
                else {
                    cout << "Return Failed: Book ID " << id << " was not borrowed!\n";
                }
                return;
            }
        }
        cout << "Return Failed: Book ID " << id << " Not Found!\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Library l;
    l.addBook(Book("Learn C++", 350.5, 1));
    l.addBook(Book("Learn OOP", 300.5, 2));
    l.addBook(Book("Learn Data Structure", 500.7, 3));

    cout << "--- Initial State ---\n";
    l.displayAllBooks();

    cout << "\n--- Testing Borrow & Return ---\n";
    l.borrowBook(1); 
    l.returnBook(1); 
    l.borrowBook(1);
    /*
    http://www.youtube.com/@CyberAlgorithms
    http://linkedin.com/in/mohamed-abo-elsoud-95131337a
    https://www.facebook.com/profile.php?id=61574877993467
    https://github.com/mohamed-hamed-0
    */
    return 0;
}