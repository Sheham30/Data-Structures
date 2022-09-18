#include <stdio.h>
#include <stdlib.h>

// Node 1
struct Student
{
    int SId;
    int semester;
    struct Student *stuNext;
};

// Node 2
struct Course
{
    int CNo;
    char CName;
    struct Course *CNext;
    struct Student *stuStart;
};

struct Course *CStart = NULL;


// --------------FUNCTIONS-------------------
// ****01****
int AddC()
{
    struct Course *tmp = (struct Course *)malloc(sizeof(struct Course));

    printf("\nEnter Course Number: ");
    scanf("%d", &tmp->CNo);
    printf("\nEnter Course Name: ");
    scanf("%s", &tmp->CName);

    tmp->CNext = NULL;
    tmp->stuStart = NULL;

    if (CStart == NULL)
    {
        CStart = tmp;
    }
    else
    {
        struct Course *cur = CStart;

        while (cur->CNext != NULL)
        {
            cur = cur->CNext;
        }
        cur->CNext = tmp;
    }
}

// ****02****
int PrintC()
{
    struct Course *curr = CStart;

    while (curr != NULL)
    {
        printf("\nCourse Number: %d", curr->CNo);
        printf("\nCourse Name: %c\n\n", curr->CName);
        curr = curr->CNext;
    }
}

// ****03****
int SearchC()
{
    int a;
    int flag = 0;
    struct Course *serCur = CStart;
    printf("\nEnter a Course Number to Search: ");
    scanf("%d", &a);

    while (serCur != NULL)
    {

        if (a == serCur->CNo)
        {
            printf("\nFound");
            flag = 1;
            break;
        }
        serCur = serCur->CNext;
    }

    if (flag == 0)
    {
        printf("Not Found");
    }
}

// ****04****
int DeleteC()
{
    struct Course *prev = CStart;
    struct Course *curr;
    int toDelete;
    int flag = 0;

    printf("Enter a Course number to delete: ");
    scanf("%d", &toDelete);

    if (toDelete == CStart->CNo)
    {
        CStart = CStart->CNext;
        free(prev);
    }
    else
    {
        curr = CStart->CNext;
        prev = CStart;

        while (curr != NULL)
        {
            if (toDelete == curr->CNo)
            {
                prev->CNext = curr->CNext;
                free(curr);
                flag = 1;
                break;
            }
            curr = curr->CNext;
            prev = prev->CNext;
        }
        if (flag == 0)
        {
            printf("Not Found");
        }
    }
}

// ****05****
int AddS()
{
    int i;
    int flagC = 0;

    printf("Enter Course Number: ");
    scanf("%d", &i);

    struct Course *curr = CStart;
    // curr->stuStart = NULL;

    while (curr != NULL)
    {
        if (curr->CNo == i)
        {
            flagC = 1;
            struct Student *tmp2 = (struct Student *)malloc(sizeof(struct Student));

            printf("\nEnter Student Id: ");
            scanf("%d", &tmp2->SId);
            printf("\nEnter Semester: ");
            scanf("%d", &tmp2->semester);

            tmp2->stuNext = NULL;

            if (curr->stuStart == NULL)
            {
                curr->stuStart = tmp2;
            }
            else
            {
                struct Student *cur = curr->stuStart;

                while (cur->stuNext != NULL)
                {
                    cur = cur->stuNext;
                }
                cur->stuNext = tmp2;
            }
        }
        curr = curr->CNext;
    }
    if (flagC == 0)
    {
        printf("\nNot Found\n");
    }
}

// ***06****
int PrintS()
{
    int j, flagS = 0;
    printf("\nEnter Course id from which you want to Print the stuents: ");
    scanf("%d", &j);
    struct Course *currC = CStart;
    // curr->stuStart = NULL;

    while (currC != NULL)
    {
        if (currC->CNo == j)
        {
            flagS = 1;

            struct Student *cur2 = currC->stuStart;
            while (cur2 != NULL)
            {
                printf("\nStudent Id: %d", cur2->SId);
                printf("\nSemester: %d\n", cur2->semester);
                cur2 = cur2->stuNext;
            }
        }
        currC = currC->CNext;
    }
    if (flagS == 0)
    {
        printf("Not Found");
    }
}

// ****07****
int SearchS()
{
    int j, flagS = 0;
    printf("\nEnter Course id from which you want to Search the students: ");
    scanf("%d", &j);
    struct Course *currC = CStart;
    // curr->stuStart = NULL;

    while (currC != NULL)
    {
        if (currC->CNo == j)
        {
            flagS = 1;

            int k, flag2 = 0;
            struct Student *cur2 = currC->stuStart;

            printf("\nEnter Student Id to Search: ");
            scanf("%d", &k);

            while (cur2 != NULL)
            {
                if (k == cur2->SId)
                {
                    printf("\nFound");
                    flag2 = 1;
                    break;
                }
                cur2 = cur2->stuNext;
            }
            if (flag2 == 0)
            {
                printf("Student Not Found");
            }
        }
        currC = currC->CNext;
    }
    if (flagS == 0)
    {
        printf("Course Not Found");
    }
}

// ****08*****
int DeleteS()
{
    int i, flag = 0;
    struct Course *cur = CStart;

    printf("\nEnter a Course no. from which you want to delete the student: ");
    scanf("%d", &i);

    while (cur != NULL)
    {
        if (i == cur->CNo)
        {
            flag = 1;

            struct Student *prev = cur->stuStart;
            struct Student *sCurr;
            int j, flag2 = 0;

            printf("Enter A Student Id to Delete: ");
            scanf("%d", &j);

            if (j == cur->stuStart->SId)
            {
                cur->stuStart = cur->stuStart->stuNext;
                free(cur->stuStart);
                flag2 = 1;
            }
            else
            {
                sCurr = cur->stuStart->stuNext;
                prev = cur->stuStart;

                while (sCurr != NULL)
                {
                    if (j == sCurr->SId)
                    {
                        prev->stuNext = sCurr->stuNext;
                        flag2 = 1;
                        free(sCurr);
                        break;
                    }

                    sCurr = sCurr->stuNext;
                    prev = prev->stuNext;
                }
            }
            if (flag2 == 0)
            {
                printf("Student Not Foumd");
            }
        }
        cur = cur->CNext;
    }
    if (flag == 0)
    {
        printf("Course Not Found");
    }
}


// ***********************MAIN****************************

int main()
{
    printf("\n****Data Structure Student App (MLL)****\n");
    int i;

    while (i != 9)
    {
        printf("\nPress\n1. AddC\t2. PrintC\t3. SearchC\t4. DeleteC\n");
        printf("5. AddS\t6. PrintS\t7. SearchS\t8. DeleteS\t 9. Exit\n");
        scanf("%d", &i);

        if (i == 1)
        {
            AddC();
        }
        if (i == 2)
        {
            PrintC();
        }
        if (i == 3)
        {
            SearchC();
        }
        if (i == 4)
        {
            DeleteC();
        }
        if (i == 5)
        {
            AddS();
        }
        if (i == 6)
        {
            PrintS();
        }
        if (i == 7)
        {
            SearchS();
        }
        if (i == 8)
        {
            DeleteS();
        }
    }

    return 0;
}