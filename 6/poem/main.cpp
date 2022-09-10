#include <fstream>
#include <iostream>
#include <string>

int main()
{
    using namespace std;

    ofstream out ("poem.txt", ios::out);
    if (!out) {
        cout << "Could not open file poem.txt\n";
        return 1;
    }
    string tmp;
    getline(cin, tmp);
    while (tmp != "") {
        out << tmp << '\n';
            getline(cin, tmp);
    }
    out.close();
    return 0;
}