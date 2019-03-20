#include<iostream>
#include<cmath>
using namespace std;
#include <set>

int main (void)
{
    int N ;
    scanf("%d", &N);
    set<int> s;
    for (int i = 1; i <= N;i++){
    	
    	s.insert(i / 2 + i / 3 + i / 5);
    }

    cout << s.size();
    
    return 0;
}
