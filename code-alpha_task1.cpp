#include <iostream>
#include <vector>
#include <iomanip>  // for setprecision

using namespace std;

struct Course {
    string name;
    double grade;       // grade points (e.g., 9 for A, 8 for B, etc.)
    int creditHours;
};

int main() {
    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    double totalCredits = 0, totalGradePoints = 0;

    // Input course details
    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << " name: ";
        cin >> courses[i].name;

        cout << "Enter grade points (e.g., 10 for O, 9 for A, etc.): ";
        cin >> courses[i].grade;

        cout << "Enter credit hours: ";
        cin >> courses[i].creditHours;

        totalCredits += courses[i].creditHours;
        totalGradePoints += courses[i].grade * courses[i].creditHours;
    }

    // GPA calculation
    double GPA = totalGradePoints / totalCredits;

    // Display results
    cout << "\n--- Semester Report ---\n";
    for (int i = 0; i < numCourses; i++) {
        cout << "Course: " << courses[i].name
             << " | Grade: " << courses[i].grade
             << " | Credits: " << courses[i].creditHours << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << "\nSemester GPA: " << GPA << endl;

    // For CGPA, assume multiple semesters → extend logic
    // Example: store GPA of each semester in a vector and average them
    int numSemesters;
    cout << "\nEnter number of semesters completed: ";
    cin >> numSemesters;

    vector<double> semesterGPA(numSemesters);
    double cgpaSum = 0;

    for (int i = 0; i < numSemesters; i++) {
        cout << "Enter GPA for semester " << i + 1 << ": ";
        cin >> semesterGPA[i];
        cgpaSum += semesterGPA[i];
    }

    double CGPA = cgpaSum / numSemesters;
    cout << "\nOverall CGPA: " << CGPA << endl;

    return 0;
}