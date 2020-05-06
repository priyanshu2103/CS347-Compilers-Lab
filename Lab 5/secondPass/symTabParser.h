#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <fstream>
#include <utility>
using namespace std;

#define RST   "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST

#define BOLD(x) "\x1B[1m" x RST

enum eletype {INTEGER, FLOATING, NULLVOID, BOOLEAN, ERRORTYPE};
enum varType {SIMPLE, ARRAY};
enum Tag {PARAMAETER, VARIABLE};

struct typeRecord {
    string name;
    eletype eleType;
    int sc;
    int variableoffset;
}; 

struct funcEntry {
    string name;
    eletype retType;
    int functionOffset;
    int numPars;
    vector <typeRecord*> varLst;
    vector <typeRecord*> parLst;
}; 


int getParset(vector<funcEntry> &decl_func_list, string func_name);
void rdSymTab(vector<funcEntry> &functionList, vector<typeRecord> &globalVariables);
string eletypeMapper(eletype ret_type);
int intMapper(eletype ret_type);
eletype getEleType(string ret_type);
int getset(vector<funcEntry> &decl_func_list, vector<typeRecord> &global_var_list, string func_name, string var_name, int this_offset, bool &global_flag);int getFunctionOffset(vector<funcEntry> &decl_func_list,string func_name);
