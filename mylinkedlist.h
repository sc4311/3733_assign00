/*
 * File: mylinkedlist.h

 * YOUR NAME ... 
 * DO NOT CHANGE THE EXISTING STRUCT OR FUNCTION NAMES HERE
 *
 * WHEN ADDING NEW FUNCTIONS, e.g., listing all students, 
 *       finding min, max, avg gpa, and removing the student with highest gpa etc.
 * YOU CAN NAME THEM AS YOU WISH, BUT TRY TO USE THE SAME NAMING CONVENTION  
 *
 * THIS IS JUST AN INTERFACE, SO DO NOT WRITE ANY IMPLEMENTATION/CODE HERE
 * ALL IMPLEMENTATION/CODE FOR THE BELOW FUNCTIONS MUST BE in mylinkedlist.c 
 *  
 * -----------------------------------------------------
 * This is just an interface  for a basic library of linked list of students.
 * In future assignments, you will use linked list structure for other purposes 
 * and accordingly reuse/modify functions you develop here... 
 */

#ifndef _mylinkedlist_h
#define _mylinkedlist_h

/*
 * Type: student_cell_T
 * -----------
 * This type defines the cells used for the linked list that
 * stores the student information we use in assing0  
 * You can change this structure later on for other assignments!
 */
typedef struct student_cell_T {
   int     id;      
   double  gpa;       
   char   *name;  //  name is just a pointer here, you need to allocate space for name
   struct student_cell_T *next;
} student_cell_T;


/*
 * Type: linked_list_T
 * --------------
 * This type defines the concrete representation of a linked list of student cells.
 * The head field points to the first element in the linked list.
 * The tail field points to the last element in the linked list.
 * The empty linked list is indicated by a NULL head pointer.
 */
typedef struct linked_list_T {
    student_cell_T *head;
    student_cell_T *tail;
} linked_list_T;


/*
 * Function: NewStudentCell
 * Usage: student_cell_T *element;
 *        element = NewStudentCell(id, gpa, name);
 * --------------------------
 * This function allocates space for a student cell and intilize its fileds
 */
student_cell_T *NewStudentCell(int id, double gpa, char *name);


/*
 * Function: NewLinkedList
 * Usage: linked_list_T *list;
 *        list = NewLinkedList();
 * --------------------------
 * This function allocates and returns an empty linked list.
 */
linked_list_T *NewLinkedList(void);


/*
 * Function: FreeLinkedList
 * Usage: FreeLinkedList(list);
 * ------------------------
 * This function frees the storage associated with list.
 */
void FreeLinkedList(linked_list_T *list);

/*
 * Function: Enlist
 * Usage: Enlist(list, element);
 * -------------------------------
 * This function adds a student cell pointed by element to the end of the list.
 */
void Enlist(linked_list_T *list, student_cell_T *element);

/*
 * Function: Delist
 * Usage: element = Delist(list);
 * --------------------------------
 * This function removes the student cell at the head of the list
 * and returns its address to the caller (client).  If the list is empty, Delist
 * prints an Error with an appropriate message and returns NULL.
 */
student_cell_T *Delist(linked_list_T *list);

/*
 * Functions: LinkedListIsEmpty, LinkedListIsFull
 * Usage: if (LinkedListIsEmpty(list)) . . .
 *        if (LinkedListIsFull(list)) . . .
 * -------------------------------------
 * These functions test whether the list is empty or full.
 */
int LinkedListIsEmpty(linked_list_T *list);
int LinkedListIsFull(linked_list_T *list);

/*
 * Function: LinkedListLength
 * Usage: n = LinkedListLength(list);
 * ------------------------------
 * This function returns the number of elements in the list.
 */
int LinkedListLength(linked_list_T  *list);

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
 */
student_cell_T *GetLinkedListElement(linked_list_T *list, int index);

/*
 * The function int studentExists(linked_list_T *list, int id); is a function declaration in C that takes two parameters:
 * a pointer to a linked_list_T structure and an integer id.
 * The purpose of this function is to check if a student with a given id already exists in the linked list.
 * It iterates over each element in the linked list and compares the id of the current element with the id passed to the function.
 * If it finds a match, it returns 1, indicating that a student with the given id exists in the list.
 * If it doesn't find a match and reaches the end of the list, it returns 0, indicating that no student with the given id exists in the list.
 * This function is useful for ensuring uniqueness of id among students in the list or for checking the existence of
 * a specific student in the list before performing operations like update or delete.
 */
int studentExists(linked_list_T *list, int id);

/*
 * The function void printStudent(student_cell_T *student); is a function declaration in C that takes one parameter:
 * a pointer to a student_cell_T structure.  The purpose of this function is to print the details of a student.
 * It accesses the id, gpa, and name fields of the student_cell_T structure that the student pointer is pointing to,
 * and prints these details in a formatted manner.
 * This function is useful for displaying the information of a specific student in a readable format.
 * It can be used in various scenarios, such as displaying the details of a student after a search operation,
 * or printing all students' details in the list by calling this function in a loop.
 */
void printStudent(student_cell_T *student);

/*
 * The function void printAllStudents(linked_list_T *list); is a function declaration in C that takes one parameter: a pointer to a linked_list_T structure.
 * The purpose of this function is to print the details of all students in the linked list.
 * It starts from the head of the list and iterates over each element in the linked list.
 * For each student, it calls the printStudent(student_cell_T *student) function to print the details of the student.
 * This function is useful for displaying the information of all students in the list in a readable format.
 * It can be used in various scenarios, such as displaying all students' details for a report, or for debugging purposes to check the current state of the list.
 */
void printAllStudents(linked_list_T *list);

/*
 * The function void printGPAStats(linked_list_T *list); is a function declaration in C that takes one parameter: a pointer to a linked_list_T structure.
 * The purpose of this function is to calculate and print the minimum, average, and maximum GPA of all students in the linked list.
 * It starts from the head of the list and iterates over each element in the linked list.
 * For each student, it accesses the gpa field of the student_cell_T structure that the current element is pointing to.
 * During the iteration, it keeps track of the minimum and maximum GPA it has encountered so far, and also accumulates the total GPA and the count of students.
 * After the iteration, it calculates the average GPA by dividing the total GPA by the count of students.
 * Finally, it prints the minimum, average, and maximum GPA in a formatted manner.
 * This function is useful for getting a quick statistical overview of the GPAs of all students in the list.
 * It can be used in various scenarios, such as generating a report of GPA statistics, or for debugging purposes to check the current state of the GPAs in the list.
 */
void printGPAStats(linked_list_T *list);

/*
 * The function void removeHighestGPA(linked_list_T *list); is a function declaration in C that takes one parameter: a pointer to a linked_list_T structure.
 * The purpose of this function is to find and remove the student with the highest GPA from the linked list.
 * It starts from the head of the list and iterates over each element in the linked list.
 * For each student, it accesses the gpa field of the student_cell_T structure that the current element is pointing to.
 * During the iteration, it keeps track of the student with the highest GPA it has encountered so far.
 * After the iteration, it removes the student with the highest GPA from the list.
 * If the student with the highest GPA is at the head of the list, it updates the head of the list to the next element.
 * If the student with the highest GPA is at the tail of the list, it updates the tail of the list to the previous element.
 * If the student with the highest GPA is in the middle of the list, it updates the next pointer of the previous element to the next element of the student with the highest GPA.
 * After removing the student with the highest GPA from the list, it prints the student's details and frees the memory allocated for the student's name and the student cell itself.
 * This function is useful for managing the list based on the GPA of the students.
 * It can be used in various scenarios, such as maintaining a list of students with GPA below a certain threshold, or for debugging purposes to check the functionality of the list operations.
 */
void removeHighestGPA(linked_list_T *list);

/* OTHER FUNCTIONS YOU WOULD NEED....
 * EXPORT THEM HERE, BUT IMPLMENT THEM in mylinkedlist.c 
 */

#endif
