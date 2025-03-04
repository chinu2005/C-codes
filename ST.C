#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX_STUDENTS 100

// Structure to store student data
typedef struct {
    int rollNo;
    char name[50];
    float marks;
} Student;

Student students[MAX_STUDENTS];
int count = 0;  // Number of students in the system

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();

void main() {
    int choice;
    while (1) {
	printf("\nStudent Management System\n");
	printf("1. Add Student\n");
	printf("2. Display Students\n");
	printf("3. Search Student\n");
	printf("4. Delete Student\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1: addStudent(); break;
	    case 2: displayStudents(); break;
	    case 3: searchStudent(); break;
	    case 4: deleteStudent(); break;
	    case 5: printf("Exiting...\n"); exit(0);
	    default: printf("Invalid choice! Try again.\n");
	}
    }
    getch();
}

// Function to add a student
void addStudent() {
    if (count >= MAX_STUDENTS) {
	printf("Cannot add more students, storage full!\n");
	return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &students[count].rollNo);
    printf("Enter Name: ");
    scanf("%s", &students[count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    int i;
    if (count == 0) {
	printf("No student records available!\n");
	return;
    }

    printf("\nStudent Records:\n");
    printf("----------------------------\n");
    for ( i = 0; i < count; i++) {
	printf("Roll No: %d\n", students[i].rollNo);
	printf("Name: %s\n", students[i].name);
	printf("Marks: %.2f\n", students[i].marks);
	printf("----------------------------\n");
    }
}

// Function to search for a student
void searchStudent() {
	int rollNo, found = 0 , i;
    if (count == 0) {
	printf("No student records available!\n");
	return;
    }


    printf("Enter Roll No to search: ");
    scanf("%d", &rollNo);

    for ( i = 0; i < count; i++) {
	if (students[i].rollNo == rollNo) {
	    printf("Record Found:\n");
	    printf("Roll No: %d\n", students[i].rollNo);
	    printf("Name: %s\n", students[i].name);
	    printf("Marks: %.2f\n", students[i].marks);
	    found = 1;
	    break;
	}
    }

    if (!found) {
	printf("No student found with Roll No %d\n", rollNo);
    }
}

// Function to delete a student
void deleteStudent() {

	int rollNo, found = 0 ,i, j;
    if (count == 0) {
	printf("No student records available!\n");
	return;
    }


    printf("Enter Roll No to delete: ");
    scanf("%d", &rollNo);

    for ( i = 0; i < count; i++) {
	if (students[i].rollNo == rollNo) {
	    found = 1;
	    for ( j = i; j < count - 1; j++) {
		students[j] = students[j + 1];  // Shift elements left
	    }
	    count--;
	    printf("Student with Roll No %d deleted successfully!\n", rollNo);
	    break;
	}
    }

    if (!found) {
	printf("No student found with Roll No %d\n", rollNo);
    }
}

