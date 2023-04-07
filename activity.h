//
// Created by Jeremiah Barro on 6/4/2023.
//
#ifndef CS162STRUCTSREVIEW_ACTIVITY_H
#define CS162STRUCTSREVIEW_ACTIVITY_H
const int MAXCHAR = 51;

enum Type {athletic, food, arts, games, other};

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
