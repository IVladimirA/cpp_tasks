#include <fstream>
#include <iostream>

int main()
{
    using namespace std;

    const size_t n = 100;
    double nums[n];
    for (size_t i = 0; i < n; ++i) {
        nums[i] = (rand() % 100);
    }

    ofstream out ("test.txt", ios::out | ios::binary);
    if (!out) {
        cout << "Could not open file text.txt\n";
        return 1;
    }
    out.write((char *) nums, sizeof(nums));
    out.close();
    ifstream in("test.txt", ios::in | ios::binary);
    if(!in) {
        cout << "Could not open file text.txt\n";
        return 1;
    }
    in.read((char *) &nums, sizeof(nums));
    size_t k = sizeof(nums) / sizeof(double);
    double sum = 0;
    for (size_t i = 0; i < k; ++i) {
        sum = sum + nums[i];
        cout << nums[i] << ' ';
    }
    cout << "\nsum = " << sum << endl;
    in.close();
    return 0;
}