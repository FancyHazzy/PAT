#include <stdio.h>
int main( void )
{
  int n;
  scanf("%d",&n);
  int t = 0;
  if (n <= 0 && n>1000)
    return 0;
  
  while(n > 1)
  {
    if (n % 2 == 0)
      n = n / 2;
    else
      n = (3 * n + 1) / 2;
    t++;
  }
 printf("%d",t); 
  return 0;
}
