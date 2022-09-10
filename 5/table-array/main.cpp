#include <ctime>
#include <iostream>

const int QUESTION_COUNT = 10;
const int MIN_NUMBER = 1;
const int MAX_NUMBER = 10;

int main()
{
    using namespace std;

    srand(time(NULL));
    int answers[QUESTION_COUNT];
    int errorCount = 0;
    for (size_t i = 0; i < QUESTION_COUNT; ++i) {
        int a = MIN_NUMBER + rand() % (MAX_NUMBER - MIN_NUMBER + 1);
        int b = MIN_NUMBER + rand() % (MAX_NUMBER - MIN_NUMBER + 1);
        cout << a << " * " << b << " = ";
        cin >> answers[i];
        if (a * b != answers[i]) {
            ++errorCount;
            cout << "Error: " << a << " * " << b << " = " << a * b << '\n';
        }
    }
    cout << "Error count: " << errorCount << '\n';
    cout << "Answers:\n";
    for (size_t i = 0; i < QUESTION_COUNT; ++i) {
        cout << answers[i] << " ";
    }
    cout << endl;
    return 0;
}