#pragma once

#include "Student.h"

#ifdef STUDENTDLL_EXPORTS
#define STUDENT_API __declspec(dllexport)
#else
#define STUDENT_API __declspec(dllimport)
#endif

extern "C" STUDENT_API Student* createGroup(int size);
extern "C" STUDENT_API void initDemoData(Student* group, int size);
extern "C" STUDENT_API void calculateAllAverages(Student* group, int size);
extern "C" STUDENT_API int findBestStudent(const Student* group, int size);
extern "C" STUDENT_API int countDebtors(const Student* group, int size);
extern "C" STUDENT_API Student* filterByAverage(const Student* group, int size,
                                                double threshold, int* outSize);
extern "C" STUDENT_API void sortByAverage(Student* group, int size);
extern "C" STUDENT_API void freeGroup(Student* group);
