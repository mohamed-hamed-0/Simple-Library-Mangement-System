Library Management System 📚
A lightweight C++ project demonstrating Object-Oriented Programming (OOP) principles by managing a collection of books, tracking availability, and processing borrow/return operations.

🚀 Features
Book Encapsulation: Class structure encapsulating book properties (Title, Price, ID, Availability Status).

Library Management: Manage dynamic book collections using std::vector<Book>.

Borrow & Return Operations: Safely toggle book availability with built-in validation checks.

Formatted Output: View clean display listings of all books in the system.

🛠️ Concepts Demonstrated
Encapsulation & Data Hiding: Private attributes accessed via public getters and setters.

Constructors & Initializer Lists: Clean object initialization with default parameters.

Const Correctness: Read-only class methods tagged with const for safety and performance.

Pass-by-Reference: Optimization using const Book& to avoid unnecessary object copying.

📦 Project Structure
Plaintext
├── main.cpp          # Full C++ implementation (Book & Library classes + main)
└── README.md         # Project documentation
📋 Code Overview
Book Class
Handles single book entity logic:

getid() const: Returns book ID.

getstatus() const: Returns availability (true/false).

borrowBook(): Marks the book as borrowed.

returnBook(): Marks the book as available.

displayBook() const: Prints formatted book details.

Library Class
Manages the collection:

addBook(const Book& book): Adds a book to the library.

displayAllBooks() const: Loops and displays all books.

borrowBook(int id): Locates book by ID and processes borrowing.

returnBook(int id): Locates book by ID and processes return.

⚙️ How to Run
Clone or download the project files.

Compile using any C++11 (or newer) compiler:

Bash
g++ -std=c++11 main.cpp -o library_app
Execute the binary:

Bash
./library_app
📝 Sample Output
Plaintext
--- Initial State ---
=====================
Title : Learn C++
Id : 1
Price : 350.5 EGP
Available : Yes
=====================

--- Testing Borrow & Return ---
Successful Borrow for Book ID: 1
Borrow Failed: Book ID 1 is already borrowed!
Successful Return for Book ID: 1
Return Failed: Book ID 1 was not borrowed!
