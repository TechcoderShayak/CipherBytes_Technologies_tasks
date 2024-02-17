#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5

struct Student {
    char name[50];
    float scores[MAX_SUBJECTS];
    float average;
};

void inputStudentInfo(struct Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter scores for %s:\n", student->name);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &student->scores[i]);
    }
}

void calculateAverage(struct Student *student) {
    float sum = 0.0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += student->scores[i];
    }
    student->average = sum / MAX_SUBJECTS;
}

void displaySummary(struct Student *students, int numStudents) {
    float highestScore = -1.0, lowestScore = 101.0;
    int highestIndex, lowestIndex;

    printf("\nSummary of Students' Performance:\n");
    printf("-------------------------------------------------\n");
    printf("| %-20s | %-8s | %-8s |\n", "Student Name", "Average", "Status");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < numStudents; i++) {
        calculateAverage(&students[i]);

        if (students[i].average > highestScore) {
            highestScore = students[i].average;
            highestIndex = i;
        }

        if (students[i].average < lowestScore) {
            lowestScore = students[i].average;
            lowestIndex = i;
        }

        printf("| %-20s | %-8.2f | %-8s |\n", students[i].name, students[i].average,
               (students[i].average >= 60.0) ? "Pass" : "Fail");
    }

    printf("-------------------------------------------------\n");
    printf("Highest Average: %s (%.2f)\n", students[highestIndex].name, highestScore);
    printf("Lowest Average: %s (%.2f)\n", students[lowestIndex].name, lowestScore);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("Enter the number of students (up to %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);

    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Exiting program.\n");
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        inputStudentInfo(&students[i]);
    }

    displaySummary(students, numStudents);

    return 0;
}
