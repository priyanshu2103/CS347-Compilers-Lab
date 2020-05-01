#include "helper.h"

bool searchNonFuncVariable(scope s1,char* var_name,int var_type)
{
    vector<func_arg*> variables=s1->variables;
    for(auto it=variables.begin(),it!=variables.end();it++)
    {
        if(strcmp(*it.arg_name,var_name)==0&&*it.arg_type==var_type)
            return true;
    }
    return false;
}