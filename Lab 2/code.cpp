// not yet considered cases where a declaration or definition goes onto multiple lines
// also not handled if multiple commands in single line separated by ;
// also not handled if erroneous input like class <no name mentioned> or if extends unknown class
// not handled obscure ways of creating object like Class.forName, clone(),desrealization etc.
// just checks using new keyword and a previously defined class name
// can check function definitions
// ignore if comments are there

//object declaration with contructor class karna hai?? https://www.javatpoint.com/how-many-ways-to-create-an-object-in-java
#include <bits/stdc++.h>
using namespace std;
bool isbackslash(char c)
{
  if(c=='\\')
  {
    return true;
  }
  return false;
}
int iscomment(char c,char d)
{
  if(c=='/')
  {
    if(d=='/')
    {
      return 1;
    }
    else if(d=='*')
    {
      return 2;
    }
  }
  else if(c=='*')
  {
    if(d=='/')
    {
      return 3;
    }
  }
  return 0;
}
bool isquote(char c)
{
  if(c=='"')
  {
    return true;
  }
  return false;
}
int main()
{
  int obj_def=0;
  int class_def=0;
  int constr_def=0;
  int inh_class_def=0;
  bool commentflag=false;
  bool quoteflag=false;
  unordered_map <string,int> mp;
  unordered_map <string,int> Objmp;
  ifstream ip;
  ofstream op;
  vector<string> lines;
  string s;
  string t1="",t2="",t3="";
  ip.open("fakeip.txt");
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
      t3=t2;
      t2=t1;
      t1=t;
      t="";
      if(commentflag || quoteflag)
      {
        if(commentflag)
        {
          while(j<len-1 && iscomment(s[j],s[j+1])!=3)
          {
            if(isbackslash(s[j]))
            {
              j++;
            }
            j++;
          }
          if(j>=len)
          {
            break;
          }
          commentflag=false;
        }
        if(quoteflag)
        {
          while(j<len && !isquote(s[j]))
          {
            if(isbackslash(s[j]))
            {
              j++;
            }
            j++;
          }
          if(j>=len)
          {
            break;
          }
          quoteflag=false;
        }
      }
      while(j<len && (isspace(s[j]) || !isalnum(s[j])))
      {
        if(isbackslash(s[j]))
        {
          j++;
          j++;
        }
        if(j<len && isquote(s[j]) && quoteflag==false && commentflag==false)
        {
          quoteflag=true;
          j++;
          while(j<len && !isquote(s[j]))
          {
            if(isbackslash(s[j]))
            {
              j++;
            }
            j++;
          }
          if(j>=len)
          {
            break;
          }
          quoteflag=false;
        }
        else if(j<len && isquote(s[j]) && quoteflag && commentflag==false)
        {
          quoteflag=false;
        }
        if(isbackslash(s[j]))
        {
          j++;
          j++;
        }
        if(j<len-1 && quoteflag==false && iscomment(s[j],s[j+1])==1)
        {
          j=len;
          break;
        }
        if(j<len-1 && quoteflag==false && iscomment(s[j],s[j+1])==2 && commentflag==false)
        {
          commentflag=true;
          j++;
          while(j<len-1 && iscomment(s[j],s[j+1])!=3)
          {
            if(isbackslash(s[j]))
            {
              j++;
            }
            j++;
          }
          if(j>=len)
          {
            break;
          }
          commentflag=false;
        }
        else if(j<len-1 && iscomment(s[j],s[j+1]) && commentflag && quoteflag==false)
        {
          commentflag=false;
        }
        j++;
      }
      while(j<len && isalnum(s[j]))
      {
        t+=s[j];
        j++;
      }
      //cout<<"t = "<<t<<" t1 = "<<t1<<" t2 = "<<t2<<" t3 = "<<t3<<"\n";
      if(t=="class" && mp.find(t1)==mp.end()) 
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
        //cout<<"found new, t1 = "<<t1<<" & t2 = "<<t2<<"\n";
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
            Objmp[t1]=1;
            obj_def++;
          }
        }
      }
      else if(t=="newInstance")
      {
        //cout<<"found newInstance, t1 = "<<t1<<" t2 = "<<t2<<" t3 = "<<t3<<"\n";
        if(t1=="class" && mp.find(t2)!=mp.end() && j<len && s[j]=='(')
        {
          if(Objmp[t3]){
            cout<<"ERROR, Object name declared more than once";
            exit(1);
          }
          Objmp[t3]=1;
          obj_def++;
        }
        else if(j<len && s[j]=='(')
        {
          obj_def++;
        }
      }
      else if(t=="clone")
      {
        //cout<<"found clone, t1 = "<<t1<<" t2 = "<<t2<<" t3 = "<<t3<<"\n";
        if(Objmp.find(t1)==Objmp.end())
        {
          cout<<"Error, parent object not defined";
          exit(1);
        }
        if(mp.find(t2)!=mp.end() && j<len && s[j]=='(') //eg: Dog obj = (Dog)obj1.clone();
        {
          Objmp[t3]=1;
          obj_def++;
        }
        else if(mp.find(t3)!=mp.end() && j<len && s[j]=='(')// eg: Dog obj = obj1.clone();
        {
          Objmp[t2]=1;
          obj_def++;
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
