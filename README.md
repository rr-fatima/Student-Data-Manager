# Student-Data-Manager

The program, written in C++, manages student data and performs various operations on it. It defines a Student class, which holds attributes such as student number, first name, last name, and grades for five subjects (Math, English, Science, Business, and Gym). It also calculates the student's average grade. The program stores multiple student objects in a vector, students, and provides functionality to add new students, search for existing ones, and calculate and display overall class data. Additional operations include finding the student with the highest average and sorting students by their student number using quicksort. Data for each student is written to a file (grade12.txt).

# How-To-Use

When the program starts, you will be prompted to select one of the following options:

1. **Add a student and calculate their average**:  
   Input the student's details such as their student number, first name, last name, and grades for each subject. The program will compute and store their average.

2. **Search a student**:  
   Enter a student number to search. If found, the program will display the student's details.

3. **Output the whole class list in order of student number**:  
   Displays the entire list of students, sorted by student number.

4. **Calculate Class Average**:  
   Outputs the average of the students' averages.

5. **Name of the student with the highest average along with their relevant information**:  
   Displays the student with the highest average and their grades.

6. **Exit**:  
   Exits the program.

The program performs error handling to ensure valid input, particularly for student numbers and grades, and outputs error messages when needed.

All student data is saved to a text file (`grade12.txt`) for future reference.
