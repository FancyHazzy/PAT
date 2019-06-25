#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;


int main(void){
    string s;
    int N, j;
    cin >> s >> N;
    for (int cnt = 1; cnt < N; cnt++){
        string t;
        for (int i = 0; i < s.length(); i = j){
            for (j = i; j < s.length() && s[i] == s[j]; j++);
            //使用一个循环来移动 j 下标到最后一个不相等的下标处
                t += s[i] + to_string(j - i);

        }
        s = t;
    }

    cout << s;
    return 0;
}
