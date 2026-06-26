#include <iostream>
#include <cstring>
#include "StudentCore.h"

using namespace std;


int main()
{
    int size = 3;

    Student* group = createGroup(size);

    initDemoData(group, size);

    calculateAllAverages(group, size);

    cout << "Лучший студент ID: "
         << findBestStudent(group, size)
         << endl;

    cout << "Количество должников: "
         << countDebtors(group, size)
         << endl;

    sortByAverage(group, size);

    int filteredSize;

    Student* filtered =
        filterByAverage(group, size, 4.0, &filteredSize);

    cout << "После фильтрации: "
         << filteredSize
         << " студентов"
         << endl;

    freeGroup(filtered);
    freeGroup(group);

    return 0;
}
