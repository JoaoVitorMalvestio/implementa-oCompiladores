/*
 * errormsg.cpp - functions used in all phases of the compiler to give
 *                error messages about the Tiger program.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include "util.hpp"
#include "errormsg.hpp"

using namespace std;

bool anyErrors = false;

static string fileName = (char *)"";

static int lineNum = 1;

int EM_tokPos = 0;

FILE *yyin;

typedef struct intList
{
    int i;
    struct intList *rest;
} * IntList;

static IntList intList(int i, IntList rest)
{
    IntList l;
    l->i = i;
    l->rest = rest;
    return l;
}

static IntList linePos = NULL;

void EM_newline(void)
{
    lineNum++;
    linePos = intList(EM_tokPos, linePos);
}

void EM_error(int pos, char *message, ...)
{
    va_list ap;
    IntList lines = linePos;
    int num = lineNum;
    anyErrors = true;

    while (lines && lines->i >= pos)
    {
        lines = lines->rest;
        num--;
    }

    if (!fileName.empty())
        cout << stderr << fileName;
    if (lines)
        cout << stderr << num << "." << pos - lines->i << ": ";
    va_start(ap, message);
    vfprintf(stderr, message, ap);
    va_end(ap);
    cout << stderr << "\n";
}

void EM_reset(string fname)
{
    anyErrors = false;
    fileName = fname;
    lineNum = 1;
    linePos = intList(0, NULL);
    const char *cstr = fname.c_str();
    yyin = fopen(cstr, "r");
    if (!yyin)
    {
        EM_error(0, (char *)"cannot open");
        exit(1);
    }
}
