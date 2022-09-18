
#include <stdio.h>
#include <conio.h>

// GPA TABLE

double calcGpa(marks1);
int main()
{
    int marks1, marks2, marks3;
    double eng, urdu, math;

    printf("Enter marks of English: ");
    scanf("%d", &marks1);
    eng = calcGpa(marks1);

    printf("Enter marks of Urdu: ");
    scanf("%d", &marks2);
    urdu = calcGpa(marks2);

    printf("Enter marks of Maths: ");
    scanf("%d", &marks3);
    math = calcGpa(marks3);

    double avgGPA = (eng+urdu+math)/3;

    printf("\nGPA in English: %f", eng);
    printf("\nGPA in Urdu: %f", urdu);
    printf("\nGPA in Maths:%f", math);

    printf("\n-----------------------------\nTotal GPA: %f\n", avgGPA);

    return 0;
}




double calcGpa(marks1)
{
    double gpa1;

    if (marks1 >= 85) {
        gpa1 = 4.0;
    }
    else if (marks1 >= 80 && marks1 <= 84) {
        gpa1 = 3.8;
    }
    else if (marks1 >= 75 && marks1 <= 79) {
        gpa1 = 3.4;
    }
    else if (marks1 >= 71 && marks1 <= 74) {
        gpa1 = 3.0;
    }
    else if (marks1 >= 68 && marks1 <= 70) {
        gpa1 = 2.8;
    }
    else if (marks1 >= 64 && marks1 <= 67) {
        gpa1 = 2.4;
    }
    else if (marks1 >= 61 && marks1 <= 63) {
        gpa1 = 2.0;
    }
    else if (marks1 >= 57 && marks1 <= 60) {
        gpa1 = 1.8;
    }
    else if (marks1 >= 53 && marks1 <= 56) {
        gpa1 = 1.4;
    }
    else if (marks1 >= 50 && marks1 <= 52) {
        gpa1 = 1.0;
    }
    else {
        gpa1 = 0.0;
    }

    return gpa1;
}


