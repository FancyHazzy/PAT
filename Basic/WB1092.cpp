#include <iostream>
#include <map>
using namespace std;

int main(void){
  
  long long A [1010] = {0};
  int N,M;
  cin >> N >> M;
  for (int i = 0;i < M;i++){
    for (int j = 0; j < N;j++){
      long long t ;
      scanf("%lld",&t);
      A[j] += t;
    }
  }
  
map<long long, string >m;
for (int k = 0;k < N;k++){
  if ( m.count(A[k]) == 0 ){
    m[A[k]] = k;
  }
  m[A[k]] = m[A[k]] + ' ' + to_string(k);
}

cout << m.begin()->first << endl << m.begin()->second ;

  
  return 0;
}
