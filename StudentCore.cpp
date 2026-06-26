
#include "StudentCore.h"
#include <cstring>

Student* createGroup(int size) {
 Student* group = new Student[size];
return group;

}

void freeGroup(Student* group)
{
    delete[] group;
}

void initDemoData(Student* group, int size)
{
    for (int i = 0; i < size; i++)
    {
        group[i].id = i + 1;

        strcpy_s(group[i].fullName
        , "Student");

        group[i].scores[0] = 5;
        group[i].scores[1] = 4;
        group[i].scores[2] = 5;
        group[i].scores[3] = 3;
        group[i].scores[4] = 4;

        group[i].averagescore = 0;
    }
}


void calculateAllAverages(Student* group, int size)
{
    for (int i = 0; i < size; i++)
    {
        double sum = 0;

        for (int j = 0; j < 5; j++)
        {
            sum += group[i].scores[j];
        }

        group[i].averagescore = sum / 5;
    }
}
int findBestStudent(const Student* group, int size)
{
    int best = 0;

    for (int i = 1; i < size; i++)
    {
        if (group[i].averagescore > group[best].averagescore)
        {
            best = i;
        }
    }

    return group[best].id;
}

int countDebtors(const Student* group, int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (group[i].scores[j] < 3)
            {
                count++;
                break;
            }
        }
    }

    return count;
}

Student* filterByAverage(const Student* group,
                         int size,
                         double threshold,
                         int* outSize)
{
    *outSize = 0;

    for (int i = 0; i < size; i++)
    {
        if (group[i].averagescore >= threshold)
        {
            (*outSize)++;
        }
    }

    Student* result = new Student[*outSize];

    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (group[i].averagescore >= threshold)
        {
            result[index] = group[i];
            index++;
        }
    }

    return result;
}


void sortByAverage(Student* group, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (group[j].averagescore < group[j + 1].averagescore)
            {
                Student temp = group[j];
                group[j] = group[j + 1];
                group[j + 1] = temp;
            }
        }
    }
}