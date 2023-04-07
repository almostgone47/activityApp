#include <iostream>
#include <fstream>
#include "activity.h"

using namespace std;

void displayActivityMenu()
{
    cout << endl << "Welcome !" << endl;
    cout << "This program will help you manage your activities." << endl << endl;
    cout << "Pick an option from below:" << endl << endl;
    cout << "(a)Add a new activity" << endl;
    cout << "(b)List activities by name" << endl;
    cout << "(c)List activities by location" << endl;
    cout << "(d)List activities by Type" << endl;
    cout << "(e)Remove an activity" << endl;
    cout << "(f)Search by activity name" << endl;
    cout << "(q)Quit" << endl;
}

char getUserInput()
{
    char input;
    cin >> input;
    cin.ignore(100, '\n');
    return input;
}

void showActivities(const Activity activities[], const int numActivities) {
    for(int i = 0; i < numActivities; i++)
    {
        cout << i+1 << "." << activities[i].name << ";" << activities[i].location << ";" << activities[i].level << ";" << activities[i].rating << ";" << activities[i].type << endl;
    }
    cout << endl;
};


int readInt(char prompt[])
{
    int temp = 0;
    cout << prompt;
    cin >> temp;
    //data validation
    while (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid rating! Please enter a valid rating!";
        cin >> temp;
    }
    cin.ignore(100, '\n');

    return temp;
}

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

void searchActivitiesByType(const Activity activities[], int numActivities) {
    char letter;
    Type type;
    cout << "Enter Type number(0-Athletic, 1-Food, 2-Arts, 3-Games, 4-Other):";
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
        cout << "Activity not found!!" << endl;
    }
}

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
    cout << "Activity removed!" << endl;
}

void addActivity(Activity activities[], int &numActivities, const Activity &activity)
{
    activities[numActivities++] = activity;
}

void addActivity(Activity &activity)
{
    char letter;
    char ratingPrompt[30] = "Enter the activity rating:";
    cout << "Enter the activity name (50 characters or less):";
    cin.get(activity.name, MAXCHAR, '\n');
    cin.ignore(100, '\n');
    cout << "Enter the activity location (50 characters or less):";
    cin.get(activity.location, MAXCHAR, '\n');
    cin.ignore(100, '\n');
    cout << "Enter the activity level:";
    cin.get(activity.level, MAXCHAR, '\n');
    cin.ignore(100, '\n');
    activity.rating = readInt(ratingPrompt);
    cout << "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and 4-Others): " ;
    cin >> letter;
    cin.ignore(100, '\n');
    activity.type = readType(letter);
    cout << "Activity added!" << endl;
}
