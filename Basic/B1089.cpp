#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main (void)
{
  int N;
	cin >> N;
	vector<int> v(N+1);

	for (int i = 1; i <= N; i++) 
		cin >> v[i];
	for (int i = 1; i <= N; i++){
		for (int j = i + 1; j <= N;j++){
			vector <int> lie, a(N+1, 1);
			a[i] = a[j] = -1;
			for (int k = 1;k <= N; k++)
				if (v[k] * a[abs(v[k])] < 0)//异号说明k的话与假设不同，即假话
					lie.push_back(k);//把 k 的值保存下来
			if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0){
			  cout << i << " " << j;
			  return 0;
			}
				
			
		} 
	}  
	cout << "No Solution" ;

	return 0;
}


//使用 v 记录下来输入，同时开个 a，作为假设。初始值都为 +1，表示好人；-1表示狼人。
//假设i，j为狼人，a[i] = a[j] = -1, 输入和假设如果异号，说明该人说假话，记录下来。
//输出i，j值，结束。
