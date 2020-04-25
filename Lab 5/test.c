# include <stdio.h>
void f(int k);
void f(int l)
{
  l=5;
  printf("%d\n",l);
}
int main()
{
  int a=5,b=8,d,c=d=a+b;
  printf("%d %d %d %d\n",a,b,c,d);
  int l=10;
  f(l);
  return 0;
}
