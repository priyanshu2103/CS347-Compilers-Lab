#include "codegenHelpers.h"



void patchDT(eletype var_type, vector<typeRecord*> &var_list, int sc)
{
    int i;

    for(i = 0; i < var_list.size(); i++)
    {
        var_list[i]->sc = sc;
        var_list[i]->eleType = var_type;
    }
    return;
}

//Adds the newly declared variables to the variable list of corresponding function
void insertSymTable(vector<typeRecord*> &decl_var_list, funcEntry* present_func)
{
    if(present_func == NULL)
        return;

    int i;
    for(i = 0; i < decl_var_list.size(); i++)
        present_func->variableList.push_back(decl_var_list[i]);
    return;
}

//Adds the declared variables to the list of global variables
void insertGVars(vector<typeRecord*> &decl_var_list, vector<typeRecord*> &global_var_list)
{
    int i;

    for(i = 0; i < decl_var_list.size(); i++)
        global_var_list.push_back(decl_var_list[i]);
    return;
}

//Removes the variables associated to a given function
void delVarLst(funcEntry* present_func, int sc)
{
    if(present_func == NULL)
        return;

    int i;
    vector <typeRecord*> list_of_variables;

    list_of_variables = present_func->variableList;
    for(i = 0; i < list_of_variables.size(); i++)
        if(list_of_variables[i]->sc == sc)
            list_of_variables[i]->isValid = false;
    return;
}

//Checks if a variable is being redeclared within its sc
void searchVars(string var_name, funcEntry* present_func, int &is_exist, typeRecord *&ret_ptr, int sc)
{
    if(present_func == NULL)
        return;

    int i, j;
    vector <typeRecord*> list_of_variables;

    list_of_variables = present_func->variableList;
    j = 0;
    for(i = 0; i < list_of_variables.size(); i++)
        if(var_name == list_of_variables[i]->name && sc == list_of_variables[i]->sc)
        {
            ret_ptr = list_of_variables[i];
            j = 1;
        }

    if(j == 1)
    {
        is_exist = 1;
        return;
    }
    is_exist = 0;
    ret_ptr = NULL;
    return;
}

void searchGVars(string global_var_name, vector<typeRecord*> &global_var_list, int &is_exist, typeRecord *&ret_ptr, int sc)
{
    int i, j;

    j = 0;
    for(i = 0; i < global_var_list.size(); i++)
        if(global_var_name == global_var_list[i]->name && sc == global_var_list[i]->sc)
        {
            ret_ptr = global_var_list[i];
            j = 1;
        }

    if(j == 1)
    {
        is_exist = 1;
        return;
    }
    is_exist = 0;
    ret_ptr = NULL;
    return;
}

void searchCallVars(string var_name, funcEntry* present_func, int &is_exist, typeRecord *&ret_ptr, vector<typeRecord*> &global_var_list)
{
    if(present_func == NULL)
        return;

    int i, max_scope = 0, is_present = 0;
    vector<typeRecord*> list_of_variables;

    list_of_variables = present_func->variableList;
    for(i = 0; i < list_of_variables.size(); i++)
        if(var_name == list_of_variables[i]->name && list_of_variables[i]->isValid == true)
        {
            if(max_scope < list_of_variables[i]->sc)
            {
                max_scope = list_of_variables[i]->sc;
                ret_ptr = list_of_variables[i];
            }
            is_present = 1;
        }

    if(is_present == 1)
    {
        is_exist = 1;
        return;
    }

    for(i = 0; i < global_var_list.size(); i++)
        if(var_name == global_var_list[i]->name && global_var_list[i]->isValid == true)
        {
            is_present = 1;
            ret_ptr = global_var_list[i];
            break;
        }

    if(is_present == 1)
    {
        is_exist = 1;
        return;
    }

    is_exist = 0;
    ret_ptr = NULL;
    return;
}

void searchPars(string parameter_name, vector<typeRecord*> &parameter_list, int &is_exist, typeRecord *&pn)
{
    int i;

    for(i = 0; i < parameter_list.size(); i++)
        if(parameter_name == parameter_list[i]->name)
        {
            is_exist = 1;
            pn = parameter_list[i];
            return;
        }
    is_exist = 0;
    pn = NULL;
    return;
}

void searchFunction(funcEntry* present_func, vector<funcEntry*> &decl_func_list, int &is_exist)
{
    funcEntry *temp;
    int i;

    for(i = 0; i < decl_func_list.size(); i++)
    {
        temp = decl_func_list[i];
        if(temp->name == present_func->name)
        {
            is_exist = 1;
            return;
        }
    }
    is_exist = 0;
    return;
}

//Checks if the function called exists and parameters requirements match
void compareFunction(funcEntry* &called_func, vector<funcEntry*> &decl_func_list, int &is_exist)
{
    int i, j, func_exist = 0, param_match = 1;

    for(i = 0; i < decl_func_list.size(); i++)
    {
        if(decl_func_list[i]->name == called_func->name && decl_func_list[i]->numofpars == called_func->numofpars)
        {
            func_exist = 1;
            for(j = 0; j < decl_func_list[i]->numofpars; j++)
            {
                if((decl_func_list[i]->parameterList[j])->eleType != called_func->parameterList[j]->eleType)
                {
                    param_match = 0;
                    break;
                }
            }
            if(func_exist == 1 && param_match == 1)
            {
                is_exist = 1;
                called_func->returnType = decl_func_list[i]->returnType;
                return;
            }
        }
    }
    if(func_exist == 0)
    {
        is_exist = 0;
        return;
    }
    if(func_exist == 1 && param_match == 0)
    {
        is_exist = -1;
        return;
    }
    return;
}

//Adds the newly declared function to list of declared functions
void addFunction(funcEntry* present_func, vector<funcEntry*> &decl_func_list)
{
    decl_func_list.push_back(present_func);
    return;
}

//Returns TRUE if integer and float expressions are calculated
//Returns FALSE if other than the two
bool arithmeticCompatible(eletype expr_type_1, eletype expr_type_2)
{
    if((expr_type_1 == INTEGER || expr_type_1 == FLOATING) && (expr_type_2 == INTEGER || expr_type_2 == FLOATING))
        return(true);
    return(false);
}

//Returns type of resulting variable type as enum value
eletype compareTypes(eletype expr_type_1, eletype expr_type_2)
{
    if(expr_type_1 != INTEGER && expr_type_1 != FLOATING)
        return(NULLVOID);
    if(expr_type_2 != INTEGER && expr_type_2 != FLOATING)
        return(NULLVOID);
    if(expr_type_1 == INTEGER && expr_type_2 == INTEGER)
        return(INTEGER);
    else
        return(FLOATING);
}

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
int eletypeIntMapper(eletype ret_type)
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

//Initializes the offsets
void populateOffsets(vector<funcEntry*> &decl_func_list, vector<typeRecord*> &global_var_list)
{
    int offset, i, j;

    for(i = 0; i < decl_func_list.size(); i++)
    {
        offset = 0;
        vector <typeRecord*> temp1;
        vector <typeRecord*> temp2;

        temp1 = decl_func_list[i]->parameterList;
        for(j = 0; j < temp1.size(); j++)
        {
            temp1[j]->varOffset = offset;
            offset = offset + 4;
        }

        offset = 92;
        temp2 = decl_func_list[i]->variableList;
        for(j = 0; j < temp2.size(); j++)
        {
            temp2[j]->varOffset = offset;
            offset = offset + 4*(temp2[j]->maxdloffset);
        }
        decl_func_list[i]->functionOffset = offset;
    }

    printSymbolTable(decl_func_list, global_var_list);
    return;
}

void printSymbolTable(vector<funcEntry*> &decl_func_list, vector<typeRecord*> &global_var_list)
{
    int i, j;
    ofstream output_sym_tab;

    output_sym_tab.open("output/symtab.txt");
    output_sym_tab.flush();

    // Printing Global Variables
    output_sym_tab << "$$" << endl;
    output_sym_tab << "GLOBAL " << "EMPTY " << global_var_list.size() << " 0 " << endl;
    output_sym_tab << "$1" << endl;

    for(i = 0; i < global_var_list.size(); i++)
    {
        output_sym_tab << "_" << global_var_list[i]->name << "_" << eletypeMapper(global_var_list[i]->eleType) << "_" << global_var_list[i]->sc << " " << eletypeIntMapper(global_var_list[i]->eleType) << " " ;
        output_sym_tab << global_var_list[i]->sc << " " << global_var_list[i]->maxdloffset << endl;
    }
    
    output_sym_tab << "$2 0" << endl;

    // Printing Local Function Variables
    for(i = 0; i < decl_func_list.size(); i++)
    {
        output_sym_tab << "$$" << endl;

        if(decl_func_list[i]->name != "main")
            output_sym_tab << "_" << decl_func_list[i]->name << " " << eletypeMapper(decl_func_list[i]->returnType) << " ";
        else
            output_sym_tab << decl_func_list[i]->name << " " << eletypeMapper(decl_func_list[i]->returnType) << " ";

        output_sym_tab << decl_func_list[i]->numofpars << " " << decl_func_list[i]->functionOffset << endl;
        output_sym_tab << "$1" << endl;

        vector <typeRecord*> temp1;
        vector <typeRecord*> temp2;

        temp1 = decl_func_list[i]->parameterList;
        temp2 = decl_func_list[i]->variableList;

        for(j = 0; j < temp1.size(); j++)
        {
            output_sym_tab << "_" << temp1[j]->name << "_" << eletypeMapper(temp1[j]->eleType) << "_" << temp1[j]->sc << " " << eletypeIntMapper(temp1[j]->eleType) << " " ;
            output_sym_tab << temp1[j]->sc << " " << temp1[j]->varOffset << endl;
        }

        output_sym_tab << "$2 " << decl_func_list[i]->variableList.size() << endl;

        for(j = 0; j < temp2.size(); j++)
        {
            output_sym_tab << "_" << temp2[j]->name << "_" << eletypeMapper(temp2[j]->eleType) << "_" << temp2[j]->sc << " " << eletypeIntMapper(temp2[j]->eleType) << " " ;
            output_sym_tab << temp2[j]->sc << " " << temp2[j]->varOffset << endl;
        }
    }

    output_sym_tab.flush();
    output_sym_tab.close();
}



//Sets an integer valued register
string registerSet::getRegister()
{
    string reg_name = "";

    if(tempRegister.size() == 0)
    {
        cout << "FATAL ERROR : Exceeded maximum temporary Int registers" << endl;
        exit(1);
        return(reg_name);
    }

    reg_name = reg_name + "T";
    int reg_int_val = tempRegister[tempRegister.size() - 1];
    reg_name = reg_name + to_string(reg_int_val);
    tempRegister.pop_back();
    return(reg_name);
}

string registerSet::getFloatRegister()
{
    string reg_name = "";

    if(floatRegister.size() == 0)
    {
        cout << "FATAL ERROR : Exceeded maximum temporary Float registers" << endl;
        exit(1);
        return(reg_name);
    }

    reg_name = reg_name + "F";
    int reg_int_val = floatRegister[floatRegister.size() - 1];
    reg_name = reg_name + to_string(reg_int_val);
    floatRegister.pop_back();
    return(reg_name);
}

//Free the given register
void registerSet::freeRegister(string reg_name)
{
    if(reg_name[0] == 'F')
    {
        reg_name[0] = '0';
        int reg_int_val, i;

        reg_int_val = stoi(reg_name);
        for(i = 0; i < floatRegister.size(); i++)
            if(floatRegister[i] == reg_int_val)
                return;
        floatRegister.push_back(reg_int_val);
    }
    else if(reg_name[0] == 'T')
    {
        reg_name[0] = '0';
        int reg_int_val, i;

        reg_int_val = stoi(reg_name);
        for(i = 0; i < tempRegister.size(); i++)
            if(tempRegister[i] == reg_int_val)
                return;
        tempRegister.push_back(reg_int_val);
    }
    else
        cout << "Not a Temp Variable : " << reg_name << endl;
}

//Adds instructions to intermediate code file "intermediate.txt"
void gen(vector<string> &output_intermediate_instrs, string next_instr, int &nextQuad)
{
    output_intermediate_instrs.push_back(next_instr);
    nextQuad++;
    return;
}

//Adds instructions of labels to added to intermediate code file
void backpatch(vector<int> *&inst_num, int lbl_num, vector<string> &output_intermediate_instrs)
{
    if(inst_num == NULL)
    {
        cout << "Given line numbers for "<<lbl_num<<" is NULL"<<endl;
        return;
    }

    for(int i : (*inst_num))
        output_intermediate_instrs[i] = output_intermediate_instrs[i] + (to_string(lbl_num));

    inst_num->clear();
}

//Merges two lists
void merge(vector<int> *&list_1, vector<int> *&list_2)
{
    if(list_1 == NULL || list_2 == NULL)
        return;

    for(int i : (*list_2))
        list_1->push_back(i);
    list_2->clear();
    return;
}

//Merges two pair lists
void mergeSwitch(vector<pair<string,int>> *&pair_list_1,vector<pair<string,int>> *&pair_list_2)
{
    if(pair_list_2 == NULL || pair_list_1 == NULL)
        return;

    for(auto i : (*pair_list_2))
        pair_list_1->push_back(i);
    pair_list_2->clear();
    return;
}