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

###################正确版本############


#include<iostream>
using namespace std;

int main (void)
{
    int A[1010] = {0};
    int max_num = 0;
    int N,M;
    cin >> N >> M;
    //scanf("%d%d", &N, &M);

    for (int i = 0;i < M;i++){
        for (int j = 0;j < N;j++){
            int t;
            scanf("%d", &t);
            A[j] += t;
            if (max_num < A[j]) max_num = A[j];
        }
    }

    cout << max_num << endl;
    //printf("%d\n", max_num);
    int flag = 0;
    for (int i = 0; i < N ;i++){
        if (A[i] == max_num){
            if (flag == 0) flag = 1;
            else printf(" ");
            cout << i+1;
        }
    }

    return 0;
}

