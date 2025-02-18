#include <stdio.h>

struct Student {
    char name[50];
    float subject1, subject2, subject3;
    char grade;
    float average;
};

// Function to calculate the average and grade
void calculateAverageAndGrade(struct Student* student) {
    student->average = (student->subject1 + student->subject2 + student->subject3) / 3.0;

    // Assign grade based on average
    if (student->average >= 90) {
        student->grade = 'A';
    } else if (student->average >= 80) {
        student->grade = 'B';
    } else if (student->average >= 70) {
        student->grade = 'C';
    } else if (student->average >= 60) {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}

int main() {
    int numStudents, i;
    char more = 'y';

    // Ask how many students
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents]; // Array of students

    // Input loop for multiple students
    for (i = 0; i < numStudents; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        
        // Get the student's name
        printf("Enter name: ");
        getchar();  // To clear the buffer before taking string input
        fgets(students[i].name, sizeof(students[i].name), stdin);

        // Get the marks for three subjects
        printf("Enter marks for Subject 1: ");
        scanf("%f", &students[i].subject1);
        printf("Enter marks for Subject 2: ");
        scanf("%f", &students[i].subject2);
        printf("Enter marks for Subject 3: ");
        scanf("%f", &students[i].subject3);
        
        // Calculate average and grade
        calculateAverageAndGrade(&students[i]);

        printf("\nStudent %d Details:\n", i + 1);
        printf("Name: %s", students[i].name);  // Name already includes newline from fgets
        printf("Average: %.2f\n", students[i].average);
        printf("Grade: %c\n", students[i].grade);
    }

    return 0;
}
