#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    double grade;
    int credits;
};

double calculateGPA(const vector<Course>& courses) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        totalGradePoints += course.grade * course.credits;
        totalCredits += course.credits;
    }
    
    return (totalCredits == 0) ? 0.0 : totalGradePoints / totalCredits;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    
    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter course name: ";
        cin >> courses[i].name;
        cout << "Enter grade (on a 4.0 scale): ";
        cin >> courses[i].grade;
        cout << "Enter credit hours: ";
        cin >> courses[i].credits;
    }
    
    double cgpa = calculateGPA(courses);
    cout << fixed << setprecision(2);
    cout << "\nTotal CGPA: " << cgpa << endl;
    
    return 0;
}
