#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
// #include <algorithm>
#include <utility>
#include <fstream>
using namespace std;
typedef struct func_arg
{
  char *arg_name;
  int arg_type;
  int i_val;
  float f_val;
} func_arg;

typedef struct func_call_details
{
  int f_type;
  char *f_name;
  int i_val;
  float f_val;
  int n_args;
  vector <func_arg *> args;
} func_call_details;
