#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <utility>
#include <fstream>
using namespace std;

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST

#define BOLD(x) "\x1B[1m" x RST

class registerSet {
private:
    vector<int> tempRegister;
    vector<int> floatRegister;
public:
    registerSet(){
        tempRegister.clear();
        for(int i=9; i>=0; i--){
            tempRegister.push_back(i);
        }
        floatRegister.clear();
        for(int i=10; i>=0; i--){
            if(i==0||i==12){
                continue;
            }
            floatRegister.push_back(i);
        }
    }
    string getRegister();
    string getFloatRegister();
    void freeRegister(string reg_name);
};


enum eletype {INTEGER, FLOATING, NULLVOID, BOOLEAN, ERRORTYPE};
enum varType {SIMPLE, ARRAY};
enum Tag{PARAMAETER, VARIABLE};

struct expression{
    eletype type;
    string* registerName;
    string* offsetRegName;
};



struct whileexp {
    int begin;
    vector<int> *falseList;
};

struct typeRecord {
    string name;
    varType type;
    eletype eleType;
    vector<int> dl; 
    int varOffset;
    bool isValid;
    Tag tag;
    int sc;
    int maxdloffset;
};

struct shortcircuit{
    eletype type;
    string* registerName;
    vector<int>* jmpLst;
};

struct condition2temp{
    vector<int> *temp;
};

struct switchcaser{
    vector<int> *nxtLst;
    vector<pair<string,int>> *casepair;
    vector<int> *brkLst;
    vector<int> *contLst;
};

struct stmt {
    vector<int> *brkLst;
    vector<int> *nxtLst;
    vector<int> *contLst;
};

struct switchtemp{
    vector<pair<string,int>> *casepair;
};

 

struct funcEntry {
    string name;
    eletype returnType;
    int numofpars;
    int functionOffset;
    vector <typeRecord*> variableList;
    vector <typeRecord*> parameterList;
}; 

void patchDT(eletype var_type, vector<typeRecord*> &var_list, int sc);
void searchFunction(funcEntry* present_func, vector<funcEntry*> &decl_func_list, int &is_exist);
void compareFunction(funcEntry* &called_func, vector<funcEntry*> &decl_func_list, int &is_exist);
bool arithmeticCompatible(eletype expr_type_1, eletype expr_type_2);
eletype compareTypes(eletype expr_type_1, eletype expr_type_2);
void insertGVars(vector<typeRecord*> &decl_var_list, vector<typeRecord*> &global_var_list);
void searchGVars(string global_var_name, vector<typeRecord*> &global_var_list, int &is_exist, typeRecord *&ret_ptr, int sc);
void populateOffsets(vector<funcEntry*> &decl_func_list, vector<typeRecord*> &global_var_list);
void printSymbolTable(vector<funcEntry*> &funcEntryRecord, vector<typeRecord*> &globalVariables);
void searchVars(string var_name, funcEntry* present_func, int &is_exist, typeRecord *&ret_ptr, int sc);
void searchCallVars(string var_name, funcEntry* present_func, int &is_exist, typeRecord *&ret_ptr, vector<typeRecord*> &global_var_list);
void searchPars(string parameter_name, vector<typeRecord*> &parameter_list, int &is_exist, typeRecord *&pn);
void addFunction(funcEntry* present_func, vector<funcEntry*> &decl_func_list);
string eletypeMapper(eletype ret_type);
int eletypeIntMapper(eletype ret_type);
void insertSymTable(vector<typeRecord*> &var_list, funcEntry* present_func);
void delVarLst(funcEntry* present_func, int sc);



void gen(vector<string> &output_intermediate_instrs, string next_instr, int &nextQuad);
void backpatch(vector<int> *&inst_num, int lbl_num, vector<string> &output_intermediate_instrs);
void merge(vector<int> *&list_1, vector<int> *&list_2);
void mergeSwitch(vector<pair<string,int>> *&pair_list_1,vector<pair<string,int>> *&pair_list_2);
