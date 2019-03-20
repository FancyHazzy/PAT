//模拟方程计算。一直答案错误，找了很久才发现是for里面再次int jia，由于定义域不同，所以两个jia值不一样。


#include<iostream>
#include<cmath>
using namespace std;
const string out1="Cong";
const string out2="Ping";
const string out3="Gai";
const string out4="No Solution";

int main (void)
{
    //模拟方程
    int jia, yi, M, X, Y;
    double bing;

    cin >> M >> X >> Y;
    for (jia = 99;jia > 9;jia-- ){
        yi = ((jia % 10) * 10 + jia / 10);
        bing = (double)(abs(jia - yi)) / X;
        if (yi == Y * bing)
        	break;
    }

    if (jia == 9)
    	cout << out4;
    else {
    	cout << jia << " ";
    	if (M == jia) cout << out2 << " ";
    	else if (M < jia) cout << out1 << " ";
    	else cout << out3 << " ";

    	if (M == yi) cout << out2 << " ";
    	else if (M < yi) cout << out1 << " ";
    	else cout << out3 << " ";

    	if (M == bing) cout << out2;
    	else if (M < bing) cout << out1;
    	else cout << out3;    	
    } 



    return 0;
}
