#include <iostream>
#include <list>

using namespace std;

int josephus(int n, int k) {
    list<int> people;

    // 初始化人数
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }

    auto it = people.begin();
    while (people.size() > 1) {
        for (int i = 1; i < k; ++i) {
            ++it;
            if (it == people.end()) {
                it = people.begin();
            }
        }

        it = people.erase(it);

        if (it == people.end()) {
            it = people.begin();
        }
    }

    return people.front();
}

int main() {
    int n, k;
    cout << "Enter the number of people (n): ";
    cin >> n;
    cout << "Enter the counting number (k): ";
    cin >> k;

    int survivor = josephus(n, k);

    cout << "The person surviving in the Josephus problem is: " << survivor << endl;

    return 0;
}
