#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    string cmd;
    int n;
    string arrayString;
    deque<int> dq;

    while (T--) {
        cin >> cmd;
        cin >> n;
        cin >> arrayString;
        bool isForward = true; // right or left
        bool errorFlag = false;

        arrayString = arrayString.substr(1, arrayString.size() - 2);
        istringstream iss(arrayString);
        string temp;
        while (getline(iss, temp, ',')) {
            dq.push_back(stoi(temp));
        }

        for (auto c: cmd) {
            if (c == 'D') {
                if (dq.empty()) {
                    cout << "error" << '\n';
                    errorFlag = true;
                    break;
                }

                if (isForward) {
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }
            } else { // c == 'R'
                isForward = !isForward;
            }
        }

        if (!errorFlag) {
            cout << "[";
            bool first = true;
            if(isForward) {
                for(auto i : dq) {
                    if(!first) {
                        cout << ",";
                    }
                    cout << i;
                    first = false;
                }
            } else {
                reverse(dq.begin(), dq.end());
                for(auto i : dq) {
                    if(!first) {
                        cout << ",";
                    }
                    cout << i;
                    first = false;
                }
            }
            cout << "]\n";
        }
        dq.clear();
    }
}