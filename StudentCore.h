#pragma once 

#include "Student.h"

Student* createGroup(int size);
void initDemoData(Student* group, int size);
void calculateAllAverages(Student* group, int size);
int findBestStudent(const Student* group, int size);
int countDebtors(const Student* group, int size);
Student* filterByAverage(const Student* group, int size,
                         double threshold, int* outSize);
void sortByAverage(Student* group, int size);
void freeGroup(Student* group);
