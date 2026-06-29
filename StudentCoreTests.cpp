#include <gtest/gtest.h>
#include "StudentCore.h"

TEST(StudentCoreTest, AverageCalculation)
{
    Student* group = createGroup(1);

    group[0].scores[0] = 5;
    group[0].scores[1] = 5;
    group[0].scores[2] = 5;
    group[0].scores[3] = 5;
    group[0].scores[4] = 5;

    calculateAllAverages(group, 1);

    EXPECT_DOUBLE_EQ(group[0].averagescore, 5.0);

    freeGroup(group);
}

TEST(StudentCoreTest, FindBestStudent)
{
    Student* group = createGroup(3);

    group[0].id = 1;
    group[0].averagescore = 3.5;

    group[1].id = 2;
    group[1].averagescore = 4.8;

    group[2].id = 3;
    group[2].averagescore = 4.2;

    EXPECT_EQ(findBestStudent(group, 3), 2);

    freeGroup(group);
}

TEST(StudentCoreTest, DebtorsCount)
{
    Student* group = createGroup(2);

    group[0].scores[0] = 5;
    group[0].scores[1] = 5;
    group[0].scores[2] = 5;
    group[0].scores[3] = 5;
    group[0].scores[4] = 5;

    group[1].scores[0] = 2;
    group[1].scores[1] = 4;
    group[1].scores[2] = 5;
    group[1].scores[3] = 3;
    group[1].scores[4] = 4;

    EXPECT_EQ(countDebtors(group, 2), 1);

    freeGroup(group);
}

TEST(StudentCoreTest, FilterByAverage)
{
    Student* group = createGroup(3);

    group[0].averagescore = 4.5;
    group[1].averagescore = 3.0;
    group[2].averagescore = 4.8;

    int outSize = 0;

    Student* filtered =
        filterByAverage(group, 3, 4.0, &outSize);

    EXPECT_EQ(outSize, 2);

    freeGroup(filtered);
    freeGroup(group);
}
