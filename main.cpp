#include <bits/stdc++.h>

using namespace std;

bool eval(vector<char>& eval_sik, int n) {
    if(n < 3 && eval_sik[0] == 'T' && eval_sik[1] == '|') {
        return true;
    }
    if(n < 3 && eval_sik[0] == 'F' && eval_sik[1] == '&') {
        return false;
    }
    if(eval_sik[n-1] == 'T' && eval_sik[n-2] == '|') {
        return true;
    }
    if(eval_sik[n-1] == 'F' && eval_sik[n-2] == '&') {
        return false;
    }


    bool v = true;
    char last_oper;
    for(int i = 0 ; i < n; i++) {
        if(i == 0) {
            if(eval_sik[i] == 'F') {
                v = false;
            }
        } else {
            if(eval_sik[i] == '&' || eval_sik[i] == '|') {
                last_oper = eval_sik[i];
            } else if(eval_sik[i] == 'T') {
                if(last_oper == '&') {
                    v &= true;
                } else { // or
                    v |= true;
                }
            } else {
                if(last_oper == '&') {
                    v &= false;
                } else { // or
                    v |= false;
                }
            }
        }
    }
    return v;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string sik;
    getline(cin, sik);
    vector<char> arr;
    char w;
    cin >> w;
    bool wanted;
    if(w == 'T') {
        wanted = true;
    } else {
        wanted = false;
    }
    for (char c: sik) {
        if (c != ' ') {
            arr.push_back(c);
        }
    }

    if(eval(arr,n) == wanted) {
        cout << 0;
        return 0;
    }

    char last_mem;
    for(int i = 0; i < n; i++) {
        last_mem = arr[i];
        if(arr[i] == 'T') {
            arr[i] = 'F';
        }
        else if(arr[i] == 'F') {
            arr[i] = 'T';
        }
        else if(arr[i] == '&') {
            arr[i] = '|';
        }
        else if(arr[i] == '|') {
            arr[i] = '&';
        }
        if(eval(arr, n) == wanted) {
            cout << 1;
            return 0;
        }
        arr[i] = last_mem;
    }

    cout << 2;
    return 0;
}