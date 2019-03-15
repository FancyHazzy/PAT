#include<iostream>
using namespace std;

int main(void){
  
  char a[128]={0};
  string A , B, C;
  getline(cin, A);
  getline(cin, B);
  C = A + B;
  for (int i = 0;i < C.length();i++)
  {
    
    if( a[C[i]] == 0){
      cout << C[i];
     //printf("%c",C[i]);
      a[C[i]]++;
    }
  }
  
  
  
  return 0;
}
