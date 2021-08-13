#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out2.txt", "w", stdout);
    int T; cin >> T;
    while(T--) {
        int count_turns = 0;
        string a, b; cin >> a >> b;
        deque<char> jane, john, stack1, stack2;
        for(char c : a) jane.push_back(c);
        for(char c : b) john.push_back(c);
        bool jane_wins = 0, john_wins = 0;
        while(count_turns < 1000) {
            //winning positions
            assert(jane.size() + stack1.size() <= a.size() * 2);
            assert(john.size() + stack2.size() <= a.size() * 2);
            if(jane.size() + stack1.size() == a.size() * 2) {
                jane_wins = true;
                break;
            }
            if(john.size() + stack2.size() == a.size() * 2) {
                john_wins = true;
                break;
            }
            
            //jane or john runs out of cards, but there are still more in their stack
            if(jane.empty()) {
                for(int i = 0; i < (int) stack1.size(); i++) {
                    jane.push_front(stack1[i]);
                }
                stack1.clear();
                continue;
            }
            if(john.empty()) {
                for(int i = 0; i < (int) stack2.size(); i++) {
                    john.push_front(stack2[i]);
                }
                
                stack2.clear();
                continue;
            }
            
            //calls snap
            assert(john.size() && jane.size());
            if(jane.front() == john.front()) {
                char turn = jane.front();
                stack1.push_front(turn);
                stack2.push_front(turn);
                jane.pop_front(); john.pop_front();
                bool cur = random() / 141 % 2;
                if(!cur) {
                    //jane wins
                    for(int i = (int) stack2.size() - 1; i >= 0; i--) {
                        stack1.push_front(stack2[i]);
                    }
                    stack2.clear();
                    cout << "Snap! for Jane: ";
                    for(auto &x : stack1) {
                        cout << x;
                    }
                    cout << "\n";
                }else {
                    //jane wins
                    for(int i = (int) stack1.size() - 1; i >= 0; i--) {
                        stack2.push_front(stack1[i]);
                    }
                    stack1.clear();
                    cout << "Snap! for John: ";
                    for(auto &x : stack2) {
                        cout << x;
                    }
                    cout << "\n";
                }
            }else {
                stack1.push_front(jane.front());
                stack2.push_front(john.front());
                jane.pop_front();
                john.pop_front();
            }
            count_turns++;
        }
        if(jane_wins) {
            cout << "Jane wins.";
        }else if(john_wins) {
            cout << "John wins.";
        }else if(!jane_wins && !john_wins) {
            cout << "Keeps going and going ...";
        }
        cout << "\n";
        if(T >= 1) {
            cout << "\n";
        }
    }
}
