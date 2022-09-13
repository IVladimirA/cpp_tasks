#include "books.h"

int main() {
    using namespace std;

    Item* books[100];
    size_t n = 0;
    char choice;
    do {
        cout << "Paperbook (p) or audiobook (a)?";
        cin >> choice;
        switch (choice) {
            case 'p':
                books[n] = new PaperBook;
                break;
            case 'a':
                books[n] = new AudioBook;
                break;
            default:
                cout << "Incorrect book type\n";
                throw std::logic_error("Incorrect book type");
        }
        books[n++]->input();
        cout << "Continue (y/n)?\n";
        cin >> choice;
    } while(choice == 'y');

    for (size_t i = 0; i < n; ++i) {
        books[i]->print();
    }
    cout << endl;

    return 0;  
}
