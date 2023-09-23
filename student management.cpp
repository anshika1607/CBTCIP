#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_SUBJECTS 10
#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    float scores[MAX_SUBJECTS];
    int numSubjects;
};

void addStudent(struct Student students[], int *numStudents);
void calculateStatistics(struct Student students[], int numStudents);
void printStudent(struct Student student);
float calculateAverage(float scores[], int numSubjects);
float findHighest(float scores[], int numSubjects);
float findLowest(float scores[], int numSubjects);

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Calculate Statistics\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                calculateStatistics(students, numStudents);
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter student name: ");
    scanf("%s", newStudent.name);

    printf("Enter the number of subjects: ");
    scanf("%d", &newStudent.numSubjects);

    if (newStudent.numSubjects > MAX_SUBJECTS) {
        printf("Maximum number of subjects exceeded.\n");
        return;
    }

    printf("Enter scores for %s's subjects:\n", newStudent.name);
    for (int i = 0; i < newStudent.numSubjects; i++) {
        printf("Enter score for subject %d: ", i + 1);
        scanf("%f", &newStudent.scores[i]);
    }

    students[*numStudents] = newStudent;
    (*numStudents)++;

    printf("%s added successfully!\n", newStudent.name);
}

void calculateStatistics(struct Student students[], int numStudents) {
    if (numStudents == 0) {
        printf("No students added yet.\n");
        return;
    }

    printf("\nStudent Performance Summary:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student: %s\n", students[i].name);
        printf("Subject Scores: ");
        for (int j = 0; j < students[i].numSubjects; j++) {
            printf("%.2f ", students[i].scores[j]);
        }
        printf("\n");
        printf("Average Score: %.2f\n", calculateAverage(students[i].scores, students[i].numSubjects));
        printf("Highest Score: %.2f\n", findHighest(students[i].scores, students[i].numSubjects));
        printf("Lowest Score: %.2f\n", findLowest(students[i].scores, students[i].numSubjects));
        printf("\n");
    }
}

float calculateAverage(float scores[], int numSubjects) {
    float sum = 0.0;
    for (int i = 0; i < numSubjects; i++) {
        sum += scores[i];
    }
    return sum / numSubjects;
}

float findHighest(float scores[], int numSubjects) {
    float highest = scores[0];
    for (int i = 1; i < numSubjects; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

float findLowest(float scores[], int numSubjects) {
    float lowest = scores[0];
    for (int i = 1; i < numSubjects; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }
    return lowest;
}

