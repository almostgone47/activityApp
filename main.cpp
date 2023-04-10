/******************************************************************************
# Author:           Jeremiah Barro
# Assignment:       Assignment 1, Structs Review Assignment
# Date:             April 9th, 2023
# Description:      This is a console app that allows users to create, read
                    and destroy Activities which are read and stored to a local
                    file.
# Input:            String input through console and a file input for storage.
# Output:           Outputs results to screen and writes to local file.
# Sources:          N/A
#*****************************************************************************/
#include <iostream>
#include <fstream>
#include "activity.h"
#include "main.h"
using namespace std;


//Name:   executeCmd()
//Desc:   Takes user input and executes the matching command.
//input:  userInput representing desired command, activities currently in
//        memory, number of activities in memory.
//output: none
//return: none
void executeCmd(char userInput, Activity activities[], int &numActivities)
{
    Activity activity;
    switch (tolower(userInput))
    {
        case 'a':
            if(numActivities == 30)
            {
                cout << "Your list is Full! Movie not added!! ";
                return;
            }
            addActivity(activity);
            addActivity(activities, numActivities, activity);
            showActivities(activities, numActivities);
            break;
        case 'b':
            showActivities(activities, numActivities);
            break;
        case 'c':
            searchActivitiesByLocation(activities, numActivities);
            break;
        case 'd':
            searchActivitiesByType(activities, numActivities);
            break;
        case 'e':
            showActivities(activities, numActivities);
            removeActivity(activities, numActivities);
            showActivities(activities, numActivities);
            break;
        case 'f':
            searchActivitiesByName(activities, numActivities);
            break;
        case 'q':
            break;
        default:
            cout << "Invalid option!! Please try again! " << endl;
    }
}

//Name:   openFile()
//Desc:   Uses ifstream to open local file.
//input:  inFile buffer to read to, file name where data is being read from.
//output: none
//return: none
void openFile(char fileName[], ifstream &inFile)
{
    inFile.open(fileName);
    if(!inFile)
    {
        cout << "Input file did not open!! Program exiting!!! " << endl;
        exit(0);
    }
}

//Name:   openFile()
//Desc:   Uses ofstream to open local file.
//input:  outFile buffer to write from, file name where data is being written to.
//output: none
//return: none
void openFile(char fileName[], ofstream &outFile)
{
    outFile.open(fileName);
    if(!outFile)
    {
        cout << "Input file did not open!! Program exiting!!! " << endl;
        exit(0);
    }
}

//Name:   writeData()
//Desc:   Uses ofstream to write data from local file.
//input:  outFile to write to, all current activities in memory, number of activities
//output: A small response showing user has saved data.
//return: none
void writeData(const Activity *activities, int numActivities, ofstream &outFile) {
    for(int i = 0; i < numActivities; i++)
    {
        outFile << activities[i].name << ";" << activities[i].location << ";" << activities[i].level << ";" << activities[i].rating << ";" << activities[i].type << endl;
    }
    outFile.close();
    cout << "Activities written to file! Thank you for using my program!! " << endl;
}

//Name:   loadData()
//Desc:   Uses ifstream to read data from local file.
//input:  inFile to read from, all current activities in memory, number of activities
//output: none
//return: none
void loadData(ifstream &inFile, Activity activities[], int &numActivities)
{
    char tempType[MAXCHAR];
    inFile.get(activities[numActivities].name, MAXCHAR, ';');
    while(inFile)
    {
        inFile.ignore(MAXCHAR, ';');
        inFile.get(activities[numActivities].location, MAXCHAR, ';');
        inFile.ignore(MAXCHAR, ';');
        inFile.get(activities[numActivities].level, MAXCHAR, ';');
        inFile.ignore(MAXCHAR, ';');
        inFile >> activities[numActivities].rating;
        inFile.ignore(MAXCHAR, ';');
        inFile.get(tempType, 2, ';');
        // showing int char in tempType, not a string, need to change the comparison
        if(strcmp(tempType, "0") == 0)
        {
            activities[numActivities].type = athletic;
        }
        else if(strcmp(tempType, "1") == 0)
        {
            activities[numActivities].type = food;
        }
        else if(strcmp(tempType, "2") == 0)
        {
            activities[numActivities].type = arts;
        }
        else if(strcmp(tempType, "3") == 0)
        {
            activities[numActivities].type = games;
        }
        else
        {
            activities[numActivities].type = other;
        }
        inFile.ignore(100, '\n');
        numActivities++;
        inFile.get(activities[numActivities].name, MAXCHAR, ';');
    }
    inFile.close();
}

//Name:   main()
//Desc:   This the entry point to the application.
//input:  None
//output: prompt
//return: int 0 for program finished
int main() {
    char fileName[MAXCHAR] = "activities.txt";
    Activity activities[30];
    int numActivities = 0;
    char userInput;
    ifstream inFile;
    ofstream outFile;
    openFile(fileName, inFile);
    loadData(inFile, activities, numActivities);
    do
    {
        displayActivityMenu();

        userInput = getUserInput();

        executeCmd(userInput, activities, numActivities);

    } while (tolower(userInput != 'q'));
    openFile(fileName, outFile);
    writeData(activities, numActivities, outFile);
    return 0;
}
