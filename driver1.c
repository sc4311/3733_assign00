/*
 * File: driver1.c
 * YOUR NAME ... YOU NEED TO IMPLEMENT THE main() + additional functions if needed
 *
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylinkedlist.h"

/* 
 * Function: ReadLine
 * Usage: s = ReadLine();
 * ---------------------
 * ReadLine reads a line of text from standard input and returns
 * the line as a string.  The newline '\n' character that terminates
 * the input is not stored as part of the string.
 */
char *ReadLine(void);



int main(int argc, char *argv[]) {
    linked_list_T *list = NewLinkedList();
    int choice;

    do {
        printf("\n1 - Add a new student\n2 - Remove the first student\n3 - Print the number of students\n");
        printf("4 - Print a student's details\n5 - Print all students\n6 - Print GPA stats\n");
        printf("7 - Remove the student with the highest GPA\n8 - Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id;
                double gpa;
                char *name;


                printf("Enter the student's ID: ");
                scanf("%d", &id);
                if (studentExists(list, id)) {
                    printf("A student with this ID already exists.\n");
                    break;
                }

                printf("Enter the student's GPA: ");
                scanf("%lf", &gpa);

                printf("Enter the student's name: ");
                scanf(" "); // Skip any whitespace characters
                name = ReadLine();

                student_cell_T *student = NewStudentCell(id, gpa, name);
                Enlist(list, student);
                break;
            }
            case 2: {
                student_cell_T *student = Delist(list);
                if (student != NULL) {
                    printStudent(student);
                    free(student->name);
                    free(student);
                }
                break;
            }
            case 3: {
                printf("Number of students: %d\n", LinkedListLength(list));
                break;
            }
            case 4: {
                int index;
                printf("Enter the index of the student: ");
                scanf("%d", &index);
                student_cell_T *student = GetLinkedListElement(list, index);
                if (student != NULL) {
                    printStudent(student);
                }
                break;
            }
            case 5: {
                printAllStudents(list);
                break;
            }
            case 6: {
                printGPAStats(list);
                break;
            }
            case 7: {
                removeHighestGPA(list);
                break;
            }
            case 8: {
                FreeLinkedList(list);
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    } while (choice != 8);

    return 0;
}

/* 
 * IMPLEMENTATION of ReadLine();
 * Function: ReadLine
 * Usage: s = ReadLine();
 * ---------------------
 * ReadLine reads a line of text from standard input and returns
 * the line as a string.  The newline '\n' character that terminates
 * the input is not stored as part of the string.
 *
 * In contrast to standard I/O functions (e.g., scanf with "%s", fgets) 
 * that can read strings into a given static size buffer, ReadLine function 
 * should read the given input line of characters terminated by a newline 
 * character ('\n') into a dynamically allocated and resized buffer based on 
 * the length of the given input line. 
 *
 * When implementing this function you can use standard I/O functions. 
 * We just want you to make sure you allocate enough space for the entered data. 
 * So don't simply allocate 100 or 1000 bytes every time. 
 * If the given input has 5 characters, you need to allocate space for 6 characters.
 *
 * Hint: initially dynamically allocate an array of char with size 10. 
 * Then, read data into that array character by charecter (e.g, you can use getchar()). 
 * If you see '\n' char before reading 10th character, you are done. And you know the 
 * exact length of the input string. So, accordingly allocate enough space and copy the 
 * data into new char array, insert '\0' instead of '\n' and free the original array. 
 * Then return the new string. However, if you DO NOT see '\n' char after 10th character, 
 * then you need larger space. Accordingly, resize your original array and double its size 
 * and continue reading data character by character as in the first step... 
 * Hope you got the idea! 
 *
 * Also please check for possible errors (e.g., no memory etc.) and appropriately handle 
 * them. For example, if malloc returns NULL, free partially allocated space and return 
 * NULL from this function. The program calling this function may take other actions, 
 * e.g., stop the program!
 */
char *ReadLine(){
    int size = 10;
    char *buffer = malloc(size);
    if (buffer == NULL) {
        return NULL;
    }

    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        buffer[i++] = ch;

        if (i == size) {
            size *= 2;
            char *newBuffer = realloc(buffer, size);
            if (newBuffer == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = newBuffer;
        }
    }

    buffer[i] = '\0';
    return buffer;
}
/*
 *
 * This function will read a line from the standard input and return it as a dynamically allocated string.
 * The size of the string will be exactly the length of the input line plus one for the null character.
 * If there is an error allocating memory, the function will free any partially allocated buffer and return NULL.
 *
 */

   