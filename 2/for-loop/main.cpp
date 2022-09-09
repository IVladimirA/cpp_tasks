#include <ctime>
#include <iostream>

const int QUESTION_COUNT = 10;
const int MIN_NUMBER = 1;
const int MAX_NUMBER = 10;

int main()
{
    using namespace std;

    srand(time(NULL));
    int k, m;
    cout << "k = ";
    cin >> k;
    cout << "m = ";
    cin >> m;
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        if (i > k && i < m) {
            continue;
        }
        sum += i;
    }
    cout << "Sum = " << sum << '\n';
    int errorCount = 0;
    for (int i = 0; i < QUESTION_COUNT; ++i) {
        int a = MIN_NUMBER + rand() % (MAX_NUMBER - MIN_NUMBER + 1);
        int b = MIN_NUMBER + rand() % (MAX_NUMBER - MIN_NUMBER + 1);
        cout << a << " * " << b << " = ";
        int answer;
        cin >> answer;
        if (a * b != answer) {
            ++errorCount;
            cout << "Error: " << a << " * " << b << " = " << a * b << '\n';
        }
    }
    cout << "Error count: " << errorCount << '\n';
    return 0;
}