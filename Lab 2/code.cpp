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
  unordered_map <string,int> mp;         // map of classes
  unordered_map <string,int> Objmp;      // map of objects
  ifstream ip;                           // input from file
  ofstream op;                           // output from file
  //vector<string> lines;
  string s;
  string t1="",t2="",t3="";
  string inputfile;
  cout<<"Give input file: ";
  cin>>inputfile;
  ip.open(inputfile);
  int ln=0;   // line number
  while (ip)
  {
    getline(ip,s);
    ln++;

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
          if(j>=len-1)
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
        if(j<len && isquote(s[j]) && quoteflag && commentflag==false)
        {
          quoteflag=false;
        }
        if(isbackslash(s[j]))
        {
          j++;
          j++;
        }
        if(j<len-1 && quoteflag==false && iscomment(s[j],s[j+1])==1 && commentflag==false)
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
          if(j>=len-1)
          {
            break;
          }
          commentflag=false;
        }
        else if(j<len-1 && iscomment(s[j],s[j+1])==3 && commentflag && quoteflag==false)
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
      if(t=="class" && j<len && isspace(s[j]))

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
        if(t!="")
        {
          mp[t]=1;
          class_def++;
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
          if(t=="extends")
          {
            inh_class_def++;
          }
        }
        else
        {
          cout<<"Class declaration incomplete at line "<<ln<<endl;
        }
      }

      else if(t=="new" && j<len && isspace(s[j]))
      {
        //cout<<"found new, t1 = "<<t1<<" & t2 = "<<t2<<"\n";
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
            cout<<"constructor not called correctly while creating object at line "<<ln<<endl;
            //exit(1);
          }
          if(s[j]=='(')
          {
            //cout<<t2<< " added to object map\n";
            Objmp[t1]=1;
            obj_def++;
          }
        }
      }
      else if(t=="newInstance")
      {
        //cout<<"found newInstance, t1 = "<<t1<<" t2 = "<<t2<<" t3 = "<<t3<<"\n";
        if(t1=="class" && mp.find(t2)!=mp.end() && j<len && s[j]=='(') //Classname obj = Classname.class.newInstance();
        {
          if(Objmp[t3]){
            cout<<"ERROR, Object name declared more than once\n";
            exit(1);
          }
          //cout<<t3<< " added to object map\n";
          Objmp[t3]=1;
          obj_def++;
        }
      }
      else if(t=="clone")
      {
        //cout<<"found clone, t1 = "<<t1<<" t2 = "<<t2<<" t3 = "<<t3<<"\n";
        if(Objmp.find(t1)==Objmp.end())
        {
          cout<<"Error, parent object not defined\n";
          exit(1);
        }
        if(mp.find(t2)!=mp.end() ) //eg: Dog obj = (Dog)obj1.clone();
        {
          //cout<<t3<< " added to object map\n";
          Objmp[t3]=1;
          obj_def++;
        }
        else if(mp.find(t3)!=mp.end() && j<len && s[j]=='(')// eg: Dog obj = obj1.clone();
        {
          //cout<<t2<< " added to object map\n";
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
