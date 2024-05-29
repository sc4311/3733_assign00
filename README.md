Assignment 00 - CS 3733 Operating Systems
Overview
This repository contains the implementation of Assignment 00 for the CS 3733 Operating Systems course. The goal of this assignment is to develop a simple linked list library in C and create a driver program to interact with it. The repository includes source files, a Makefile, and a report detailing the implementation process.
Files
•	assign00.pdf: Assignment instructions.
•	driver1.c: Main driver program.
•	mylinkedlist.c: Implementation of the linked list library.
•	mylinkedlist.h: Header file for the linked list library.
•	CMakeLists.txt: CMake build configuration.
•	Makefile: Makefile for building the project.
•	REPORT.txt: Report describing the implementation process and answering specific questions.
Build and Run Instructions
Using CMake
1.	Create a build directory:
mkdir build cd build 
2.	Generate build files using CMake:
cmake .. 
3.	Build the project:
make 
4.	Run the driver program:
./assign0


Using Makefile
1.	Build the project:
make 
2.	Run the driver program:
./driver1 
Functionality
The driver program (driver1.c) interacts with the user to manage a linked list of student records. The user can perform the following actions:
1.	Add a new student record.
2.	Remove the first student record.
3.	Print the number of students.
4.	Print a specific student record by index.
5.	Print all student records.
6.	Print the minimum, average, and maximum GPAs.
7.	Remove the student record with the highest GPA.
8.	Exit the program.


Report Summary
•	Collaboration: No collaboration with other individuals.
•	Correctness: All functionalities work as described in the assignment instructions.
•	Non-Working Parts: Not applicable, everything is functioning correctly.
•	Comments: The assignment was interesting and engaging, with debugging being a notable challenge due to incorrect project setup in CLion.
For more details, refer to REPORT.txt.


Grading
This assignment is worth 30 points:
•	10 points for implementing existing functions in the library.
•	10 points for implementing new functions in the library.
•	10 points for the driver program.

