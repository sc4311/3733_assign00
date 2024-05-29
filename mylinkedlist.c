/*
 * File: mylinkedlist.c
 * YOUR NAME ... 
 * YOU NEED TO IMPLEMENT THE FUNCTIONS  here
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylinkedlist.h"
 
/*
 * Function: NewStudentCell
 * Usage: student_cell_T *element;
 *        element = NewStudentCell(int id, double gpa, char *name);
 * --------------------------
 * This function allocates space for a student cell and intilize its fileds
 */
student_cell_T *NewStudentCell(int id, double gpa, char *name){
   student_cell_T *element;
  
   element = (student_cell_T *) malloc( sizeof(student_cell_T) );
   if( !element){
     fprintf(stderr,"NewStudentCell cannot allocate memory\n");
     return NULL;
   }
   element->id = id;
   element->gpa = gpa;
   element->name = name;

  return element;
}


/*
 * Function: NewLinkedList
 * Usage: linked_list_T *list;
 *        list = NewLinkedList();
 * --------------------------
 * This function allocates and returns an empty linked list.
 */
linked_list_T *NewLinkedList(void){
   linked_list_T *list;
  
   list = (linked_list_T *) malloc( sizeof(linked_list_T) );
   if( !list){
     fprintf(stderr,"NewLinkedList cannot allocate memory\n");
     return NULL;
   }

   list->head = NULL;
   list->tail = NULL;

  return list;
}


/*
 * Function: FreeLinkedList
 * Usage: FreeLinkedList(list);
 * ------------------------
 * This function frees the storage associated with list.
 */
void FreeLinkedList(linked_list_T *list){
    student_cell_T *current = list->head;
    student_cell_T *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->name); // free the memory allocated for the name
        free(current); // free the memory allocated for the node
        current = next;
    }

    free(list); // free the memory allocated for the list
}

/*
 * Function: Enlist
 * Usage: Enlist(list, element);
 * -------------------------------
 * This function adds a student cell pointed by element to the end of the list.
 *
 * This function first checks if the list is empty.
 * If it is, it makes the new element both the head and the tail of the list.
 * If the list is not empty, it adds the new element to the end of the list by setting the next pointer of the current tail to the new element and then updating the tail to the new element.
 * Finally, it ensures that the next pointer of the new element is NULL, as it is now the last element in the list.
 *
 */
void Enlist(linked_list_T *list, student_cell_T *element){
    // If the list is empty, make the new element the head and tail
    if (list->head == NULL) {
        list->head = element;
        list->tail = element;
    } else {
        // Otherwise, add the new element to the end of the list
        list->tail->next = element;
        list->tail = element;
    }

    // The next pointer of the new element should be NULL, as it is now the last element
    element->next = NULL;
}



/*
 * Function: Delist
 * Usage: element = Delist(list);
 * --------------------------------
 * This function removes the student cell at the head of the list
 * and returns its address to the caller (client).  If the list is empty, Delist
 * prints an Error with an appropriate message and returns NULL.
 *
 *
 * This function first checks if the list is empty.
 * If it is, it prints an error message and returns NULL.
 * If the list is not empty, it saves the head of the list in a temporary variable and updates the head of the list to the next element.
 * If the list is now empty after removing the head, it updates the tail to NULL.
 * Finally, it ensures that the next pointer of the removed element is NULL and returns the removed element.
 */
student_cell_T *Delist(linked_list_T *list){
    // If the list is empty, print an error and return NULL
    if (list->head == NULL) {
        fprintf(stderr, "Delist: Error - list is empty\n");
        return NULL;
    }

    // Save the head of the list in a temporary variable
    student_cell_T *temp = list->head;

    // Update the head of the list to the next element
    list->head = list->head->next;

    // If the list is now empty, update the tail to NULL
    if (list->head == NULL) {
        list->tail = NULL;
    }

    // The next pointer of the removed element should be NULL
    temp->next = NULL;

    // Return the removed element
    return temp;
}



/*
 * Functions: LinkedListIsEmpty, LinkedListIsFull
 * Usage: if (LinkedListIsEmpty(list)) . . .
 *        if (LinkedListIsFull(list)) . . .
 * -------------------------------------
 * These functions test whether the list is empty or full.
 */
int LinkedListIsEmpty(linked_list_T *list){
    return list->head == NULL ? 1 : 0;
}

int LinkedListIsFull(linked_list_T *list){
    int count = 0;
    student_cell_T *current = list->head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    if (count >= 100)
    {
        return 1; // The linked list is considered full
    }
    else
    {
        return 0; // The linked list is not full
    }
}




/*
 * Function: LinkedListLength
 * Usage: n = LinkedListLength(list);
 * ------------------------------
 * This function returns the number of elements in the list.
 *
 * The LinkedListLength function starts a count at 0 and then iterates over each element in the linked list, incrementing the count for each element.
 * It then returns the count.
 *
 */
int LinkedListLength(linked_list_T  *list){
    int count = 0;
    student_cell_T *current = list->head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

/*
 * Function: GetLinkedListElement
 * Usage: element = GetLinkedListElement(list, index);
 * -----------------------------------------------
 * This function returns the element at the specified index in the
 * list, where the head of the list is defined as index 0. For
 * example, calling GetLinkedListElement(list, 0) returns the initial
 * element from the list without removing it.  If the caller tries
 * to select an element that is out of range, GetLinkedListElement prints
 * Error and returns NULL.  Note: This function is not a fundamental list operation
 * and is instead provided mainly to facilitate debugging.
 *
 *
 * The GetLinkedListElement function also starts a count at 0 and then iterates over each element in the linked list.
 * If the count matches the specified index, it returns the current element.
 * If it reaches the end of the list without finding the specified index, it prints an error message and returns NULL.
 *
 */


student_cell_T *GetLinkedListElement(linked_list_T *list, int index){
    int count = 0;
    student_cell_T *current = list->head;

    while (current != NULL)
    {
        if (count == index)
        {
            return current;
        }

        count++;
        current = current->next;
    }

    fprintf(stderr, "GetLinkedListElement: Error - index out of range\n");
    return NULL;
}

// Function to check if a student with a given id already exists in the list
int studentExists(linked_list_T *list, int id) {
    student_cell_T *current = list->head;
    while (current != NULL) {
        if (current->id == id) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to print a student's details
void printStudent(student_cell_T *student) {
    printf("ID: %d, GPA: %.2f, Name: %s\n", student->id, student->gpa, student->name);
}

// Function to print all students in the list
void printAllStudents(linked_list_T *list) {
    student_cell_T *current = list->head;
    while (current != NULL) {
        printStudent(current);
        current = current->next;
    }
}

// Function to calculate and print the min, average, and max GPA
void printGPAStats(linked_list_T *list) {
    if (LinkedListIsEmpty(list)) {
        printf("The list is empty.\n");
        return;
    }

    double minGPA = list->head->gpa;
    double maxGPA = list->head->gpa;
    double totalGPA = 0.0;
    int count = 0;

    student_cell_T *current = list->head;
    while (current != NULL) {
        double gpa = current->gpa;
        if (gpa < minGPA) minGPA = gpa;
        if (gpa > maxGPA) maxGPA = gpa;
        totalGPA += gpa;
        count++;
        current = current->next;
    }

    printf("Min GPA: %.2f, Average GPA: %.2f, Max GPA: %.2f\n", minGPA, totalGPA / count, maxGPA);
}

// Function to find and remove the student with the highest GPA
void removeHighestGPA(linked_list_T *list) {
    if (LinkedListIsEmpty(list)) {
        printf("The list is empty.\n");
        return;
    }

    student_cell_T *current = list->head;
    student_cell_T *highestGPAStudent = current;
    while (current != NULL) {
        if (current->gpa > highestGPAStudent->gpa) {
            highestGPAStudent = current;
        }
        current = current->next;
    }

    // Remove the student with the highest GPA
    if (highestGPAStudent == list->head) {
        Delist(list);
    } else {
        student_cell_T *prev = list->head;
        while (prev->next != highestGPAStudent) {
            prev = prev->next;
        }
        prev->next = highestGPAStudent->next;
        if (highestGPAStudent == list->tail) {
            list->tail = prev;
        }
    }

    // Print the student's details and free the memory
    printStudent(highestGPAStudent);
    free(highestGPAStudent->name);
    free(highestGPAStudent);
}



  