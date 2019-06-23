#include<bits/stdc++.h>
using namespace std;

char spell[10][10] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

int main(void){
    char arr[105];
    cin >> arr;
    int sum = 0;
    for (int i = 0; i < strlen(arr); i++){
        sum += arr[i] - '0';
    }

    stringstream ss;// 使用stringsteam可以吐出想要的类型
    ss << sum;
    string ch = ss.str();
    //cout << ch;

    for (int i = 0; i < ch.size(); i++){
        if (i == 0){
            cout << spell[ch[i] - '0'];
        }
        else
            cout << ' ' << spell[ch[i] - '0'];
    }



    return 0;
}
