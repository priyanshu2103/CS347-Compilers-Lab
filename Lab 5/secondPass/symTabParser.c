#include "symTabParser.h"

//Returns the data type as string from enum values
string eletypeMapper(eletype ret_type)
{
    if(ret_type == INTEGER)
        return("int");
    if(ret_type == FLOATING)
        return("float");
    if(ret_type == NULLVOID)
        return("void");
    if(ret_type == BOOLEAN)
        return("bool");
    if(ret_type == ERRORTYPE)
        return("error");
    return("int");
}

//Returns the data type as int from enum values
int intMapper(eletype ret_type)
{
    if(ret_type == INTEGER)
        return(0);
    if(ret_type == FLOATING)
        return(1);
    if(ret_type == NULLVOID)
        return(2);
    if(ret_type == BOOLEAN)
        return(3);
    if(ret_type == ERRORTYPE)
        return(4);
    return(0);
}

//Returns the data type as their corresponding enum values
eletype getEleType(string ret_type)
{
    switch(ret_type[0])
    {
    	case '0': return(INTEGER);
    	case '1': return(FLOATING);
    	case '2': return(NULLVOID);
    	default : return(ERRORTYPE);
    }
}

//Returns offset of the declared global variables and variables declared in a function or label
int getset(vector<funcEntry> &decl_func_list, vector<typeRecord> &global_var_list, string func_name, string var_name, int this_offset, bool &global_flag)
{
    global_flag = false;
    int i, j;

    for(i = 0; i < decl_func_list.size(); i++)
    	if(decl_func_list[i].name == func_name)
    	{
    		vector <typeRecord*> temp;

    		temp = decl_func_list[i].varLst;
    		for(j = 0; j < temp.size(); j++)
    			if(temp[j]->name == var_name)
    				return(decl_func_list[i].functionOffset - (4 * (this_offset + 1)) - temp[j]->variableoffset);

    		temp = decl_func_list[i].parLst;
    		for(j = 0; j < temp.size(); j++)
    			if(temp[j]->name == var_name)
    				return(decl_func_list[i].functionOffset + (4 * (decl_func_list[i].numPars - this_offset - 1)) - temp[j]->variableoffset);
    	}

    for(i = 0; i < global_var_list.size(); i++)
    	if(global_var_list[i].name == var_name)
    	{
    		global_flag = true;
    		return(0);
    	}

    cout << "Variable " << var_name << " not found in " << func_name << endl;
    return(-1);
}

//Returns the offset of a function
int getFunctionOffset(vector<funcEntry> &decl_func_list,string func_name)
{
	int i;

	for(i = 0; i < decl_func_list.size(); i++)
		if(decl_func_list[i].name == func_name)
			return(decl_func_list[i].functionOffset);

    return(-1);
}

//Reads the symbol table file and stores the global declarations and function declarations
void rdSymTab(vector<funcEntry> &decl_func_list, vector<typeRecord> &global_var_list)
{
    ifstream sym_table_file;
    sym_table_file.open ("../firstPass/output/symtab.txt");
    string line;
    bool glob_flag = false;
    int i;

    while(sym_table_file >> line)
    {
        if(line == "$$")
        {
            funcEntry temp;
            sym_table_file >> temp.name;

            if(temp.name == "GLOBAL")
                glob_flag = true;
            else
                glob_flag = false;

            string str1;
            sym_table_file >> str1;
            temp.retType = getEleType(str1);
            sym_table_file >> temp.numPars;
            sym_table_file >> temp.functionOffset;
            sym_table_file >> str1;

            if(glob_flag)
            {
                for(i = 0; i < temp.numPars; i++)
                {
                    typeRecord temp_type;
                    string type;
                    sym_table_file >> temp_type.name;
                    sym_table_file >> type;
                    temp_type.eleType = getEleType(type);
                    
                    sym_table_file >> temp_type.sc;
                    sym_table_file >> temp_type.variableoffset;
                    global_var_list.push_back(temp_type);
                }
                for(i = 0; i < global_var_list.size(); i++)
                    cout << "Global Variable Name : "<< global_var_list[i].name << endl;
            }
            else
            {
                (temp.parLst).resize(temp.numPars);
                for(i = 0; i < temp.numPars; i++)
                {
                    temp.parLst[i] = new typeRecord;
                    sym_table_file >> (temp.parLst[i])->name;

                    string str2;
                    sym_table_file >> str2;
                    (temp.parLst[i])->eleType = getEleType(str2);
                    sym_table_file >> (temp.parLst[i])->sc;
                    sym_table_file >> (temp.parLst[i])->variableoffset; 
                }
            }

            sym_table_file >> str1;
            int j;
            sym_table_file >> j;
            temp.varLst.resize(j);

            for(i = 0; i < j; i++)
            {
                temp.varLst[i] = new typeRecord;
                sym_table_file >> (temp.varLst[i])->name;

                string str3;
                sym_table_file >> str3;
                (temp.varLst[i])->eleType = getEleType(str3);
                sym_table_file >> (temp.varLst[i])->sc;
                sym_table_file >> (temp.varLst[i])->variableoffset;
            }
            if(!glob_flag)
                decl_func_list.push_back(temp);
        }
    }
}

//Returns the offset of a parameter of a function
int getParset(vector<funcEntry> &decl_func_list, string func_name)
{
	int i;

	for(i = 0; i < decl_func_list.size(); i++)
		if(decl_func_list[i].name == func_name)
			return(4 * (decl_func_list[i].numPars));

    return(0);
}

