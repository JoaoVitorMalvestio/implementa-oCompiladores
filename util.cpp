/*
 * util.cpp - commonly used utility functions.
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "util.hpp"

using namespace std;

void *checked_malloc(int len)
{
  void *p = malloc(len);
  if (!p) {
    cout << "\nRan out of memory!\n";
    exit(1);
  }
  return p;
}

//string String(char *s)
//{
  //char* p = checked_malloc(strlen(s)+1);
  //strcpy(p,s);
  //return s;
//}

U_boolList U_BoolList(bool head, U_boolList tail)
{ 
  //U_boolList list = checked_malloc(sizeof(*list));
  U_boolList list;
  list->head = head;
  list->tail = tail;
  return list;
}