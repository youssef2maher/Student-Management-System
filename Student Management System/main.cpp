#include <iostream>

using namespace std;

class courseList
{
private:

    class course
    {
        public:
        string name;    //The course name
        float total;    //The course total degree
        string grade;   //The course grade
        float point;    //The course GPA points
        course* nextCourse; //Pointer points to the next course in the course linked list
    };

    //This head pointer points to the first course in the course linked list
    course* head = new course;

public:


    /** This constructor sets the value of the head
    with NULL value */
    courseList()
    {
     head = NULL;
    }



    /** This function adds course to the course linked list
    it also adds the course name, total, grade and point */
    addCourse(string name, float total, string grade, float point)
    {
        course* newCourse = new course;
        newCourse->name = name;
        newCourse->total = total;
        newCourse->grade = grade;
        newCourse->point = point;

        if (head == NULL){
            head = newCourse;
            newCourse->nextCourse = NULL;
        }

        else {
            newCourse->nextCourse = head;
            head = newCourse;
        }
    }




    /** This function prints each course info. int the course linked list */
    void print()
    {
        course* trail = new course;
        trail = head;

        while(trail != NULL){
            cout << "\n\n\n\t\t\tCourse name: " << trail->name;
            cout << "\n\n\t\t\tTotal degree: " << trail->total;
            cout << "\n\n\t\t\tGrade: " << trail->grade;
            cout << "\n\n\t\t\tPoint: " << trail->point;
            trail = trail->nextCourse;
        }
    }


};


/** The student linked list*/
class studentList
{
private:

    /** This class stores the info of the student*/
    class student
    {
        public:
        string name;        //The student name
        string department;  //The student department
        int courseNumber;   //The number of registered courses of the student
        courseList courses;  //The registered courses of the student
        student* nextStudent; //Pointer to the next student in the linked list
    };

    //pointer to points to the first student in the student linked list
    student* head = new student;

public:

    /** This constructor sets the value of the head
    with NULL value */
    studentList()
    {
        head = NULL;
    }



    /** This function adds a new student in the student linked list
    it also adds the student name, department, courseNumber */
    void addStudent(string name, string department, int courseNumber)
    {
        student* newStudent = new student;
        newStudent->name = name;
        newStudent->department = department;
        newStudent->courseNumber = courseNumber;

        for (int i = 0; i < courseNumber; i++){

            cout << "\n\n\t\tEnter Course Name: ";
            string courseName;    cin >> courseName;

            cout << "\n\n\t\tEnter Course Total Degree: ";
            float courseTotal;    cin >> courseTotal;

            cout << "\n\n\t\tEnter Course Grade: ";
            string courseGrade;   cin >> courseGrade;

            cout << "\n\n\t\tEnter Course Point: ";
            float coursePoint;    cin >> coursePoint;

            newStudent->courses.addCourse(courseName, courseTotal, courseGrade, coursePoint);
        }

        if (head == NULL){
            head = newStudent;
            newStudent->nextStudent = NULL;
        }

        else {
            newStudent->nextStudent = head;
            head = newStudent;
        }
    }




    /** This function prints students subjects and grades */
    void print()
    {
        student* trail = new student;
        trail = head;

        while(trail != NULL){
            cout << "\n\n\t\t Name: " << trail->name;
            cout << "\n\n\t\t Department: " << trail->department;
            cout << "\n\n\t\t coursesNumber: " << trail->courseNumber;
            cout << "\n\n\t\t Courses: "; trail->courses.print();
            trail = trail->nextStudent;
        }
    }

};

int main()
{

    studentList sl;
    cout << "\n\n\tEnter Students Number: ";
    int studentsNumber; cin >> studentsNumber;

    for (int i = 0; i < studentsNumber; i++){

        cout << "\n\n\tEnter Student Name: ";
        string name;        cin >> name;

        cout << "\n\n\tEnter Student Department: ";
        string department;  cin >> department;

        cout << "\n\n\tEnter Student Courses Number: ";
        int coursesNumber;  cin >> coursesNumber;

        sl.addStudent(name, department, coursesNumber);
    }

    sl.print();

    return 0;
}
