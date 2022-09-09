#include <array>
#include <iostream>

const std::array<uint64_t, 4> COIN_VALUES{1, 2, 5, 10};

int main()
{
    using namespace std;

    cout << "Enter amount of money: ";
    uint64_t money;
    cin >> money;
    std::array<uint64_t, 4> coinCounts{0, 0, 0, 0};
    for (size_t i = COIN_VALUES.size() - 1; i >= 0; --i) {
        if (money < COIN_VALUES[i]) {
            continue;
        }
        coinCounts[i] = money / COIN_VALUES[i];
        money %= COIN_VALUES[i];
        if (money == 0) {
            break;
        }
    }
    cout << "Coins:\n";
    for (size_t i = 0; i < COIN_VALUES.size(); ++i) {
        cout << COIN_VALUES[i] << " rub - " << coinCounts[i] << '\n'; 
    }
    return 0;
}