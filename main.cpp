/*
Program Name: main.cpp
Date: June 5 2023
Description: The program manages student data and performs various operations on
it. It includes a Student class to represent a student object with attributes
such as student number, first name, last name, grades in different subjects, and
average. The program uses a vector called students to store multiple student
objects. It also writes the data of the student to the file.
*/

#include <algorithm> // for the max method
#include <fstream>   // for writing to the file
#include <iostream>
#include <limits> // for error handling
#include <vector> // for using vectors

using namespace std;

/*
Create a new student
*/
class Student {

private:      // Access specifier
  int stuNum; // variable for storing the student number
  string fName, lName; // variable for storing the first and last name of the student
  int math, eng, sci, bui, gym, average; // variable for storing the subject grades and the average

public:
  /*
  Constructs a new book with the attributes listed in the
  parameters and the calculate their average

  param int sn = represents the student number
  param string fn = represents the first name
  param string ln = represents the last name
  param int m = represents the math grade
  param int e = represents the english grade
  param int sc = represents the science grade
  param int b = represents the buisness grade
  param int g = represents the gym grade
  */
  Student(int sn, string fn, string ln, int m, int e, int sc, int b, int g) {
    stuNum = sn;
    fName = fn;
    lName = ln;
    math = m;
    eng = e;
    sci = sc;
    bui = b;
    gym = g;
    average = (math + eng + sci + bui + gym) / 5;
  }

  // accessor method for student number
  int getStuNum() { return stuNum; }

  // acessor method for the first name
  string getFName() { return fName; }

  // aceessor method for the last name
  string getLName() { return lName; }

  // accessor method fpr the math grade
  int getMath() { return math; }

  // accessor method fpr the english grade
  int getEng() { return eng; }

  // accessor method fpr the science grade
  int getSci() { return sci; }

  // accessor method fpr the buisness grade
  int getBui() { return bui; }

  // accessor method fpr the gym grade
  int getGym() { return gym; }

  // accessor method fpr the average
  int getAverage() { return average; }

  // method for writing the student's data to the file
  void writeToFile() {
    fstream MyFile12;
    MyFile12.open("grade12.txt", ofstream::app);
    MyFile12 << "Student Number: " << stuNum << "\n"
             << "First Name: " << fName << "\n"
             << "Last Name: " << lName << "\n"
             << "Math(%): " << math << "\n"
             << "English(%): " << eng << "\n"
             << "Science(%): " << sci << "\n"
             << "Buisness(%): " << bui << "\n"
             << "Gym(%): " << gym << "\n"
             << "Average(%): " << average << "\n"
             << "*************************"
             << "\n";
    MyFile12.close();
  }

  // use to swap the information of the two students
  friend void swap(Student &, Student &);

};

// contains the objects of the student class
vector<Student> students;

/*
Recursive method that find the highest average from the student objects
by calling them from the vector students

param int index - the index the method want to access average of
returns an integer that will be the highest average
*/
int recursiveMax(int index) {
  if (index == 0) {
    return students.at(index).getAverage();
  } else {
    return max(students.at(index).getAverage(), recursiveMax(index - 1));
  }
}

/*
Recursive method that find the sum of thstudents averages by calling the
student objects from the vecotr students

param int n - the index the method want to access average of
returns an int that is the total of the averages of the students
*/
int recursiveAvgSum(int n) {
  if (n == 0) {
    return students.at(n).getAverage();
  } else {
    return students.at(n).getAverage() + recursiveAvgSum(n - 1);
  }
}

/*
Recursive method that find the sum of thstudents math grade by calling the
student objects from the vecotr students

param int n - the index the method want to access math grade of
returns an int that is the total of the math grades of the students
*/
int recursiveMathSum(int n) {
  if (n == 0) {
    return students.at(n).getMath();
  } else {
    return students.at(n).getMath() + recursiveMathSum(n - 1);
  }
}

/*
Recursive method that find the sum of the students english grade by calling
the student objects from the vector students

param int n - the index the method want to access english grade of
returns an int that is the total of the english grades of the students
*/
int recursiveEngSum(int n) {
  if (n == 0) {
    return students.at(n).getEng();
  } else {
    return students.at(n).getEng() + recursiveEngSum(n - 1);
  }
}

/*
Recursive method that find the sum of the students science grade by calling
the student objects from the vector students

param int n - the index the method want to access science grade of
returns an int that is the total of the science grades of the students
*/
int recursiveSciSum(int n) {
  if (n == 0) {
    return students.at(n).getSci();
  } else {
    return students.at(n).getSci() + recursiveSciSum(n - 1);
  }
}

/*
Recursive method that find the sum of the students buisness grade by calling
the student objects from the vector students

param int n - the index the method want to access buisness grade of
returns an int that is the total of the buisness grades of the students
*/
int recursiveBuiSum(int n) {
  if (n == 0) {
    return students.at(n).getBui();
  } else {
    return students.at(n).getBui() + recursiveBuiSum(n - 1);
  }
}

/*
Recursive method that find the sum of the students gym grade by calling
the student objects from the vector students

param int n - the index the method want to access gym grade of
returns an int that is the total of the gym grades of the students
*/
int recursiveGymSum(int n) {
  if (n == 0) {
    return students.at(n).getGym();
  } else {
    return students.at(n).getGym() + recursiveGymSum(n - 1);
  }
}

/*
Method used to print the student's data to the screen

param int i - the index of the student object in the vector
*/
void print(int i) {
  cout << "Student Number: " << students.at(i).getStuNum() << "\n"
       << "First Name: " << students.at(i).getFName() << "\n"
       << "Last Name: " << students.at(i).getLName() << "\n"
       << "Math(%): " << students.at(i).getMath() << "\n"
       << "English(%): " << students.at(i).getEng() << "\n"
       << "Science(%): " << students.at(i).getSci() << "\n"
       << "Buisness(%): " << students.at(i).getBui() << "\n"
       << "Gym(%): " << students.at(i).getGym() << "\n"
       << "Average(%): " << students.at(i).getAverage() << "\n\n";
}

/*
Method for swapping the values of twp integers

param int &a, &b - the integers to be swapped
*/
void swapInt(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

/*
Method for swapping the values of twp strings

param string &a, &b - the strings to be swapped
*/
void swapString(string &a, string &b) {
  string temp = a;
  a = b;
  b = temp;
}

/*
Define the method declared in the student class. It swaps
the information of two student objects.

param Student &s1, Student &s2 - the student objects to be swapped
*/
void swap(Student &s1, Student &s2) { // for swapping
  swapInt(s1.stuNum, s2.stuNum);      // swap te student numbers
  swapString(s1.fName, s2.fName);     // swap the first names
  swapString(s1.lName, s2.lName);     // swapt the last names
  swapInt(s1.math, s2.math);          // swap the math grades
  swapInt(s1.eng, s2.eng);            // swap the english grades
  swapInt(s1.sci, s2.sci);            // swap the science grades
  swapInt(s1.bui, s2.bui);            // swap the buisness grades
  swapInt(s1.gym, s2.gym);            // swap the gym grades
  swapInt(s1.average, s2.average);    // swap the averages
}

/*
The method searches if the student is already present in the
vector students

param int stuNum - the student number of the student to search
*/
bool search(int stuNum) {
  bool present = false;
  for (int i = 0; i < students.size(); i++) {
    if (students.at(i).getStuNum() == stuNum) {
      present = true;
      break;
    }
  }
  return present;
}

/*
Divide the vector into smaller pieces so that they can be sorted
using quick sort from smallest student number to largest
*/
int partition(int left, int right) {
  int i = left;
  int j = right;
  int pivot = students.at((left + right) / 2).getStuNum();
  while (i <= j) {
    while (students.at(i).getStuNum() < pivot) {
      i++;
    }

    while (students.at(j).getStuNum() > pivot) {
      j--;
    }

    if (i <= j) {
      swap(students.at(i), students.at(j));
      i++;
      j--;
    }
  }
  return i;
}

/*
Method uses quick sort to sort students from smallest student number to largest
*/
void quicksort(int left, int right) {
  int index = partition(left, right);
  if (left < index - 1) {
    quicksort(left, index - 1);
  }
  if (index < right) {
    quicksort(index, right);
  }
}

int main() {

  int option; // variable used to store the users choice

  // clears the file and add ** in the start of the file
  ofstream MyMainFile12("grade12.txt");
  MyMainFile12 << "*************************\n";
  MyMainFile12.close();

  // runs until the user wants to quite (type 6)
  while (option != 6) {

    // outputs the options
    cout << "\nHi! Select the option that best suits you:\n"
         << "1) Add a student and calculate there average \n"
         << "2) Search a student \n"
         << "3) Output the whole class list in order of student number\n"
         << "4) Calculate Class Average\n"
         << "5) Name of the student with the highest average along with there relevant information\n"
         << "6) Exit\n\n";
    
    cin >> option;
    // error handling
    while (1) {
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Option should only contain numbers from 1-6\n\n";
        cin >> option;
      }
      if (!cin.fail()) break;
    }

    // if the vector is not empty it sorts it from lowest student number to largest
    if (!students.empty()) {
      quicksort(0, students.size() - 1);
    }

    if (option == 1) { // if the user wants to add a student to the class

      // varaibles for storing the students data
      int stuNum;
      string fName, lName;
      int math, eng, sci, bui, gym, average;

      // asks the user for their student number and stores it
      cout << "\nEnter student number: ";
      cin >> stuNum;

      // error handling
      while (1) {
        if (cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Error: Student number should only contain numbers\nEnter Student Number:";
          cin >> stuNum;
        }
        if (!cin.fail()) break;
      }

      if (search(stuNum) == true) { // if the student number already exists it tells the user
        cout << "Student with the same student number already exists!\n";
      } else { // if the student does not already exist it proceeds to ask for more data
        
        cout << "Enter first name: ";
        cin >> fName;
        
        cout << "Enter last name: ";
        cin >> lName;
        
        cout << "Enter Math Grade(%): ";
        cin >> math;
        // error handling
        while (1) {
          if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Math grade should only contain numbers\nEnter Math Grade(%):";
            cin >> math;
          }
          if (!cin.fail()) break;
        }
        
        cout << "Enter English Grade(%): ";
        cin >> eng;
        // error handling
        while (1) {
          if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: English grade should only contain numbers\nEnter English Grade(%):";
            cin >> eng;
          }
          if (!cin.fail()) break;
        }
        
        cout << "Enter Science Grade(%): ";
        cin >> sci;
        // error handling
        while (1) {
          if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Science grade should only contain numbers\nEnter Science Grade(%):";
            cin >> sci;
          }
          if (!cin.fail()) break;
        }
        
        cout << "Enter Buisness Grade(%): ";
        cin >> bui;
        // error handling
        while (1) {
          if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Buisness grade should only contain numbers\nEnter Buisness Grade(%):";
            cin >> bui;
          }
          if (!cin.fail()) break;
        }
        
        cout << "Enter Gym Grade(%): ";
        cin >> gym;
        // error handling
        while (1) {
          if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Gym grade should only contain numbers\nEnter Gym Grade(%):";
            cin >> gym;
          }
          if (!cin.fail()) break;
        }

        Student newStudent(stuNum, fName, lName, math, eng, sci, bui, gym);  // creates a student object based on the data given by the user
        newStudent.writeToFile(); // write the students data to the file by calling the objects method
        students.push_back(newStudent); // adds the student in the vector

        cout << "The average of the student is: " 
             << newStudent.getAverage()
             << "\n\nStudent is added successfully!\n";
      }

    } else if (option == 2) { // if the user wants to search up a student in the class

      cout << "\nDo you want to search the students by:\n"
           << "1) Student Number\n"
           << "2) First Name\n"
           << "3) Last Name \n\n";
      
      cin >> option;
      // error handling
      while (1) {
        if (cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Error: Option should only contain numbers from 1-3! \n";
          cin >> option;
        }
        if (!cin.fail()) break;
      }

      int index = -1; // stores the index where the student is found

      if (option == 1) { // if the user want to search by student number

        // asks the user for the student number and then store it in the variable created
        int stuNum;
        cout << "\nEnter the student number: \n";
        cin >> stuNum;
        
        // error handling
        while (1) {
          if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Student Number should only contain numbers!\nEnter the student number:";
            cin >> stuNum;
          }
          if (!cin.fail()) break;
        }

        // searh the student object in the vector with the same student number
        for (int i = 0; i < students.size(); i++) {
          if (students.at(i).getStuNum() == stuNum) {
            index = i;
            break;
          }
        }
        
      } else if (option == 2) { // if the uer wants to search by first name

        // asks the user the first name and store it in the variable created
        string fName;
        cout << "\nEnter the first name of the student: \n";
        cin >> fName;

        // searh the student object in the vector with the same first name
        for (int i = 0; i < students.size(); i++) {
          if (students.at(i).getFName() == fName) {
            index = i;
            break;
          }
        }
        
      } else if (option == 3) { // if the user want to search by last name

        // asks the user the last name and store it in the variable created
        string lName;
        cout << "\nEnter the last name of the student: \n";
        cin >> lName;

        // searh the student object in the vector with the same last name
        for (int i = 0; i < students.size(); i++) {
          if (students.at(i).getLName() == lName) {
            index = i;
            break;
          }
        }

      }

      if (option <1 || option > 3){
        cout << "\nYour input is invalid!\n";
      } else if(index == -1) { // if no match is found
        cout << "\nNo matching student is found!\n";
      } else { // if a match is foind it prints the object's data using the method print
        cout << "\n";
        print(index);
      }

    } else if (option == 3) { // if the user wants to output the classlist with students in order of student number

      if (students.empty()) { // if the class is empty
        cout << "\nThe class is empty!\n";
      } else { // otherwise it outputs the classlist that is already sorted in the start of the while loop
        cout << "\n";
        for (int i = 0; i < students.size(); i++) {
          print(i);
        }
      }

    } else if (option == 4) { // if the user want to see the class averages

      if (students.empty()) { // if the class is empty
        cout << "\nThe class is empty!\n";
      } else { // otheerwise display the averages

        // divide the sum of the grades of the students (calculated using recursive method) by no. of students
        cout << "\nFollowing are the class averages.\n";
        cout << "Math Class Average: "
             << (recursiveMathSum(students.size() - 1) / students.size())
             << "\n";
        cout
            << "English Class Average: "
            << (recursiveEngSum(students.size() - 1) / students.size()) 
            << "\n";
        cout
            << "Science Class Average: "
            << (recursiveSciSum(students.size() - 1) / students.size()) 
            << "\n";
        cout << "Buisness Class Average: "
             << (recursiveBuiSum(students.size() - 1) / students.size()) 
             << "\n";
        cout << "Gym Class Average: "
             << (recursiveGymSum(students.size() - 1) / students.size()) 
             << "\n";
        cout << "Overall Class Average: "
             << (recursiveAvgSum(students.size() - 1) / students.size()) 
             << "\n";
      }
      
    } else if (option == 5) { // if the user wants to see the student who got the highest average

      if (students.empty()) { // if the class is empty
        cout << "\nThe class is empty!\n";
      } else { // otherwise find the student with the highest average

        int index = -1; // stores the index of the student object with the highest average
        int maxAverage = recursiveMax(students.size() - 1); // find the highest average using recursive method

        // finds the student object with the highest average
        for (int i = 0; i < students.size(); i++) {
          if (students.at(i).getAverage() == maxAverage) {
            index = i;
            break;
          }
        }

        // prints the information of the student with the highest average
        cout << "\nFollowing are the details of the student with the highest "
                "average: \n\n";
        print(index);
      }

    } else if (option == 6) { // if the user wants to exit
      break;
    } else { // otherwise tells the user that their input is wrong
      cout << "\n The input is invalid!\n";
    }
    
  }

  cout << "\nThanks for using our program! Please do download the text file as when the program runs again,"
       << " it will clear the file. \nHope to see you again!";
  
}
