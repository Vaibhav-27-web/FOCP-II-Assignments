#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class MovieTicket {
    unordered_map<int, unordered_set<int>> data;

public:

    bool BOOK(int user, int movie) {
        if (data[movie].count(user)) return false;
        if (data[movie].size() == 100) return false;

        data[movie].insert(user);
        return true;
    }

    bool CANCEL(int user, int movie) {
        if (!data[movie].count(user)) return false;

        data[movie].erase(user);
        return true;
    }

    bool IS_BOOKED(int user, int movie) {
        return data[movie].count(user);
    }

    int AVAILABLE_TICKETS(int movie) {
        return 100 - data[movie].size();
    }
};
int main() {
    MovieTicket a;

    cout << (a.BOOK(1, 101) ? "true" : "false") << endl;
    cout << (a.CANCEL(2, 101) ? "true" : "false") << endl;
    cout << (a.IS_BOOKED(1, 101) ? "true" : "false") << endl;
    cout << (a.CANCEL(1, 101) ? "true" : "false") << endl;
    cout << (a.IS_BOOKED(1, 101) ? "true" : "false") << endl;
    cout << a.AVAILABLE_TICKETS(101) << endl;

    return 0;
}

 
