#include <iostream>
#include <unordered_map>
using namespace std;

class Bank {
    unordered_map<int, int> acc;

public:

    bool CREATE(int user, int money) {
        if (acc.find(user) == acc.end()) {
            acc[user] = money;
            return true;
        } else {
            acc[user] += money;
            return false;
        }
    }

    bool DEBIT(int user, int money) {
        if (acc.find(user) == acc.end() || acc[user] < money)
            return false;

        acc[user] -= money;
        return true;
    }

    bool CREDIT(int user, int money) {
        if (acc.find(user) == acc.end())
            return false;

        acc[user] += money;
        return true;
    }

    int BALANCE(int user) {
        if (acc.find(user) == acc.end())
            return -1;

        return acc[user];
    }
};
int main() {
    Bank b;   

    cout << (b.CREATE(1, 1000) ? "true" : "false") << endl;
    cout << (b.CREATE(1, 500) ? "true" : "false") << endl;
    cout << (b.DEBIT(1, 300) ? "true" : "false") << endl;
    cout << (b.CREDIT(1, 200) ? "true" : "false") << endl;
    cout << b.BALANCE(1) << endl;
    cout << b.BALANCE(2) << endl;

    return 0;
}
