// not yet considered cases where a declaration or definition goes onto multiple lines
// also not handled if multiple commands in single line separated by ;
// also not handled if erroneous input like class <no name mentioned> or if extends unknown class
// not handled obscure ways of creating object like Class.forName, clone(),desrealization etc.
// just checks using new keyword and a previously defined class name
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int obj_def=0;
  int class_def=0;
  int constr_def=0;
  int inh_class_def=0;
  unordered_map <string,int> mp;
  ifstream ip;
  ofstream op;
  vector<string> lines;
  string s;
  ip.open("input.txt");
  int ln=0;   // line number
  while (ip)
  {
    getline(ip,s);
    ln++;
  //   lines.push_back(s);
  // }
  // int ln=lines.size();
  //
  // for (int i=0;i<ln;i++)
  // {
  // s=lines[i];
    string t="";
    int len=s.length();
    int j=0;
    bool class_flag=false;
    while(j<len)
    {
      t="";
      while(j<len && (isspace(s[j]) || !isalnum(s[j])))
      {
        j++;
      }
      while(j<len && isalnum(s[j]))
      {
        t+=s[j];
        j++;
      }
      if(t=="class")
      {
        class_def++;
        if(j>=len)
        {
          cout<<"class name not in line "<<ln<<endl;
          exit(1);
        }
        t="";
        while(j<len && (isspace(s[j]) || !isalnum(s[j])))
        {
          j++;
        }
        while(j<len && isalnum(s[j]))
        {
          t+=s[j];
          j++;
        }
        if(t=="")
        {
          cout<<"class name not in line "<<ln<<endl;
          exit(1);
        }
        mp[t]=1;
        class_flag=true;
      }
      else if(t=="extends")
      {
        if(class_flag)
        {
          inh_class_def++;
          class_flag=false;
        }
      }
      else if(t=="new")
      {
        if(j>=len)
        {
          cout<<"class name not in line "<<ln<<endl;
          exit(1);
        }
        t="";
        while(j<len && (isspace(s[j]) || !isalnum(s[j])))
        {
          j++;
        }
        while(j<len && isalnum(s[j]))
        {
          t+=s[j];
          j++;
        }
        if(mp.find(t)!=mp.end())
        {
          if(j>=len)
          {
            cout<<"constructor not called correctly while creating object "<<ln<<endl;
            exit(1);
          }
          if(s[j]=='(')
          {
            obj_def++;
          }
        }
      }
      else if(mp.find(t)!=mp.end())
      {
        if(s[j]=='(')
        {
          constr_def++;
        }
      }
    }
  }
  ip.close();
  op.open("output.txt");
  op<<"Object Declarations: "<<obj_def<<endl;
  op<<"Class Definitions: "<<class_def<<endl;
  op<<"Constructor Definitions: "<<constr_def<<endl;
  op<<"Inherent Class Definitions: "<<inh_class_def<<endl;
  op.close();
  return 0;
}
