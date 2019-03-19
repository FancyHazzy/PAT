#include<iostream>
#include<set>
using namespace std;
#define MAX  10010

int main (void){
  int cp[MAX][2];
  set<int> num_set;
  int N ,M;
  cin >> N >> M;
  for (int i = 0;i < N; i++){
    cin >> cp[i][0] >> cp[i][1];
  }
  
  for (int j = 0;j < M; j++){
    int k ;
    cin  >> k;
    for (int p = 0;p < k;p++){
      int e;
      cin >> e;
      num_set.insert(e); 
    }
    bool flag = true;
    for (int kkk = 0;kkk < N;kkk++){
      if (  (num_set.find(cp[kkk][0]) != num_set.end())  &&  ( num_set.find(cp[kkk][1]) != num_set.end()) )
      flag = false;
    }
    cout << ((flag) ? "Yes":"No") << endl;
    num_set.clear();
  }
  return 0;
}

//使用集合中的 find 方法进行查找，降低复杂度。如果找到，返回该元素迭代器；如果没有找到，返回 end 迭代器，即 s.end() ，使用完记得 s.clear()
