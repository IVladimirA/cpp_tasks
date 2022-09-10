#include <ctime>
#include <iostream>
#include <vector>

const int MIN_NUMBER = 1;
const int MAX_NUMBER = 10;

int main()
{
    using namespace std;

    cout << "Enter question count: ";
    size_t questionCount;
    cin >> questionCount;

    srand(time(NULL));
    vector<int> correctAsnwers;
    vector<int> wrongAnswers;
    int errorCount = 0;
    for (size_t i = 0; i < questionCount; ++i) {
        int a = MIN_NUMBER + rand() % (MAX_NUMBER - MIN_NUMBER + 1);
        int b = MIN_NUMBER + rand() % (MAX_NUMBER - MIN_NUMBER + 1);
        cout << a << " * " << b << " = ";
        int answer;
        cin >> answer;
        if (a * b != answer) {
            ++errorCount;
            cout << "Error: " << a << " * " << b << " = " << a * b << '\n';
            wrongAnswers.push_back(answer);
        } else {
            correctAsnwers.push_back(answer);
        }
    }
    cout << "Error count: " << errorCount << '\n';
    cout << "Correct answers:\n";
    for (int ans: correctAsnwers) {
        cout << ans << " ";
    }
    cout << endl;
    cout << "Wrong answers:\n";
    for (int ans: wrongAnswers) {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}