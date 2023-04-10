/******************************************************************************
# Author:           Jeremiah Barro
# Assignment:       Assignment 1, Structs Review Assignment
# Date:             April 9th, 2023
# Description:      This is a console app that allows users to create, read
                    and destroy Activities which are read and stored to a local
                    file.
# Input:            String input through console and a local file input for
                    reading from storage.
# Output:           Outputs results to screen and writes to local file for
                    storage.
# Sources:          N/A
#*****************************************************************************/
#ifndef CS162STRUCTSREVIEW_MAIN_H
#define CS162STRUCTSREVIEW_MAIN_H
#include <fstream>
#include "activity.h"
using namespace std;

// function prototypes
void executeCmd(char, Activity [], int &);
void openFile(char [], ifstream &);
void openFile(char [], ofstream &);
void writeData(const Activity *, int, ofstream &);
void loadData(ifstream &, Activity [], int &);

#endif //CS162STRUCTSREVIEW_MAIN_H
