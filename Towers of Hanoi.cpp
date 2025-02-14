#include <iostream>
#include <vector>
using namespace std;

int main() {  
    vector<int> t[3];  
    int n, candidate = 1, to, from = 0, moves = 0;  
    cout << "Enter the number of rings: ";  
    cin >> n;  
    cout << endl;  

    bool even = (n % 2 == 0);  

    for (int i = n + 1; i >= 1; i--) t[0].push_back(i);  
    t[1].push_back(n + 1);  
    t[2].push_back(n + 1);  

    to = even ? 2 : 1;  

    while (t[1].size() < n + 1) {  
        cout << "Move number " << ++moves << ": Transfer ring " << candidate  
             << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;  

        t[to].push_back(t[from].back());  
        t[from].pop_back();  

        if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back())  
            from = (to + 1) % 3;  
        else  
            from = (to + 2) % 3;  

        candidate = t[from].back();  

        even = (n % 2 == 1);  
        if (even) {  
            to = (candidate < t[(from + 1) % 3].back()) ? (from + 1) % 3 : (from + 2) % 3;  
        } else {  
            to = (candidate < t[(from + 2) % 3].back()) ? (from + 2) % 3 : (from + 1) % 3;  
        }  
    }  
    return 0;  
}
