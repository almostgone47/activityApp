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
#ifndef CS162STRUCTSREVIEW_ACTIVITY_H
#define CS162STRUCTSREVIEW_ACTIVITY_H
const int MAXCHAR = 51;

// the different types of activities an Activity can be selected as.
enum Type {athletic, food, arts, games, other};

// Object for holding all activity info for a single object.
struct Activity {
    char name[MAXCHAR];
    char location[MAXCHAR];
    char level[MAXCHAR];
    int rating;
    Type type;
};

// Function prototypes
void displayActivityMenu();
char getUserInput();
void showActivities(const Activity [], const int);
void searchActivitiesByType(const Activity [], const int);
void searchActivitiesByLocation(const Activity [], const int);
void searchActivitiesByName(const Activity [], const int);
void removeActivity(Activity [], int &);
void addActivity(Activity &);
void addActivity(Activity [], int &, const Activity &);

#endif //CS162STRUCTSREVIEW_ACTIVITY_H
