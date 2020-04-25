#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  vector<int> b;
  b.push_back(5);
  b.push_back(6);
  for(int i=0;i<a.size();i++)
  {
    cout<<a[i]<< " ";
  }
  cout<<endl;
  a=b;
  for(int i=0;i<a.size();i++)
  {
    cout<<a[i]<< " ";
  }
}
