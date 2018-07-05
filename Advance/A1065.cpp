//本题目中要考虑到溢出问题，采用long double即可不用考虑溢出
#include<iostream>
using namespace std ;
int main()
{
	int T ;
	cin >> T ;
	for( int i = 1; i <= T; ++i )
	{
	long double a, b, c, ans ;
	cin >> a >> b >> c ;
	cout << "Case #"<< i <<": " << (a+b>c ? "true" : "false") << endl ;
}
return 0 ;
}  


//如果使用long long，判断条件为正正和为负，负负和为正，即溢出。
