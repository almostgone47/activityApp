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

using namespace std;
//Name:   displayActivityMenu()
//Desc:   Displays menu of all user options.
//input:  none
//output: Displays all menu options.
//return: none
void displayActivityMenu()
{
    cout << endl << "Welcome! " << endl;
    cout << "This program will help you manage your activities. " << endl << endl;
    cout << "Pick an option from below: " << endl << endl;
    cout << "(a)Add a new activity " << endl;
    cout << "(b)List activities by name " << endl;
    cout << "(c)List activities by location " << endl;
    cout << "(d)List activities by Type " << endl;
    cout << "(e)Remove an activity " << endl;
    cout << "(f)Search by activity name " << endl;
    cout << "(q)Quit " << endl;
}

//Name:   getUserInput()
//Desc:   Accepts user input.
//input:  Any char
//output: none
//return: A single char.
char getUserInput()
{
    char input;
    cin >> input;
    cin.ignore(100, '\n');
    return input;
}

//Name:   showActivities()
//Desc:   Displays all activities currently in memory.
//input:  all activities currently in memory, the number of all activities
//output: Displays all activities with a number at the start of each line.
//return: none
void showActivities(const Activity activities[], const int numActivities) {
    for(int i = 0; i < numActivities; i++)
    {
        cout << i+1 << "." << activities[i].name << ";" << activities[i].location << ";" << activities[i].level << ";" << activities[i].rating << ";" << activities[i].type << endl;
    }
    cout << endl;
};

//Name:   readInt()
//Desc:   Prompts user for an integer which is used to the rating of an activity
//        when adding a new activity.
//input:  int representing the rating being input.
//output: Displays prompt for user to enter a rating.
//return: The integer representing the user's rating of the activity.
int readInt()
{
    int temp = 0;
    cout << "Enter the activity rating: ";
    cin >> temp;

    while (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid rating! Please enter a valid rating! ";
        cin >> temp;
    }
    cin.ignore(100, '\n');

    return temp;
}

//Name:   readType()
//Desc:   Matches an input char to the corresponding Enum Type.
//input:  char representing the type being input.
//output: none
//return: The corresponding type to the input char.
Type readType(char num)
{
    Type tempType;
    switch(num)
    {
        case '0':
            tempType = static_cast<Type>(0);
            break;
        case '1':
            tempType = static_cast<Type>(1);
            break;
        case '2':
            tempType = static_cast<Type>(2);
            break;
        case '3':
            tempType = static_cast<Type>(3);
            break;
        default:
            tempType = static_cast<Type>(4);
    }
    return tempType;
}

//Name:   searchActivitiesByType()
//Desc:   Asks user for type of activity to search for and prints all activities that match
//        the input string.
//input:  array holding all activities currently in memory, number of activities in memory
//output: All activities matching search.
//return: none
void searchActivitiesByType(const Activity activities[], int numActivities) {
    char letter;
    Type type;
    cout << "Enter Type number(0-Athletic, 1-Food, 2-Arts, 3-Games, 4-Other): ";
    cin >> letter;
    type = readType(letter);
    for(int i = 0; i < numActivities; i++)
    {
        if(type == activities[i].type)
        {
            cout << i+1 << "." << activities[i].name << ";" << activities[i].location << ";" << activities[i].level << ";" << activities[i].rating << ";" << activities[i].type << endl;
        }
    }
}

//Name:   searchActivitiesByLocation()
//Desc:   Asks user for location of activity to search for and prints all activities that match
//        the input string.
//input:  array holding all activities currently in memory, number of activities in memory
//output: All activities matching search.
//return: none
void searchActivitiesByLocation(const Activity activities[], int numActivities) {
    char searchLocation[MAXCHAR];
    cout << "Enter location name: ";
    cin.get(searchLocation, MAXCHAR, '\n');
    cout << endl;

    for(int i = 0; i < numActivities; i++)
    {
        if(strstr(searchLocation, activities[i].location) != NULL)
        {
            cout << i+1 << "." << activities[i].name << ";" << activities[i].location << ";" << activities[i].level << ";" << activities[i].rating << ";" << activities[i].type << endl;
        }
    }
}

//Name:   searchActivitiesByName()
//Desc:   Asks user for name of activity to search for and prints all activities that match
//        the input string.
//input:  array holding all activities currently in memory, number of activities in memory
//output: All activities matching search.
//return: none
void searchActivitiesByName(const Activity activities[], int numActivities) {
    char searchName[MAXCHAR];
    cout << "Enter the activity name (50 characters or less): ";
    cin.get(searchName, MAXCHAR, '\n');
    cout << endl;

    bool activityFound = false;
    for(int i = 0; i < numActivities; i++)
    {
        if(strstr(searchName, activities[i].name) != NULL)
        {
            activityFound = true;
            cout << i+1 << "." << activities[i].name << ";" << activities[i].location << ";" << activities[i].level << ";" << activities[i].rating << ";" << activities[i].type << endl;
        }
    }
    if (!activityFound) {
        cout << "Activity not found!! " << endl;
    }
}

//Name:   removeActivity()
//Desc:   Removes activity from all activities in array stored in memory.
//input:  array holding all activities currently in memory, number of activities in memory
//output: none
//return: none
void removeActivity(Activity activities[], int &numActivities) {
    int index;
    cout << "Pick the index to remove: ";
    cin >> index;
    cin.ignore(100, '\n');
    cout << endl;

    if(index < numActivities && index > -1)
    {
        for(int i = index; i < numActivities; i++)
        {
            activities[i-1] = activities[i];
        }
    }
    numActivities--;
    cout << "Activity removed! " << endl;
}

//Name:   addActivity()
//Desc:   Adds ref to newly created activity to array of all activities in memory.
//input:  array holding all activities currently in memory, number of activities in memory,
//        ref to activity being created.
//output: none
//return: none
void addActivity(Activity activities[], int &numActivities, const Activity &activity)
{
    activities[numActivities++] = activity;
}

//Name:   addActivity()
//Desc:   Collects data from user to create a new activity.
//input:  reference to activity bing created.
//output: Prompts for each of the data points required to create an activity.
//return: none
void addActivity(Activity &activity)
{
    char letter;
    cout << "Enter the activity name (50 characters or less): ";
    cin.get(activity.name, MAXCHAR, '\n');
    cin.ignore(100, '\n');
    cout << "Enter the activity location (50 characters or less): ";
    cin.get(activity.location, MAXCHAR, '\n');
    cin.ignore(100, '\n');
    cout << "Enter the activity level: ";
    cin.get(activity.level, MAXCHAR, '\n');
    cin.ignore(100, '\n');
    activity.rating = readInt();
    cout << "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and 4-Others): " ;
    cin >> letter;
    cin.ignore(100, '\n');
    activity.type = readType(letter);
    cout << "Activity added! " << endl;
}
