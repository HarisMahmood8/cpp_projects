using namespace std;
#include "student.h"

 
void get_input(student &s) {
    cout << "Enter your id: ";
    cin >> s.id;
    cout << "Enter your name: ";
    cin >> s.name;
    
    cout << "Enter your finals grade: ";
    cin >> s.final;
    while(s.final < 0 || s.final > 100) {
        cout << "Invalid Entry. You cannot have a grade above 100, or a negative value\n";
        cout << "Enter another value: ";
        cin >> s.final;

    }
    cout << "Enter your midterms grade: ";
    cin >> s.midterm;
        while(s.midterm < 0 || s.midterm > 100) {
        cout << "Invalid Entry. You cannot have a grade above 100, or a negative value\n";
        cout << "Enter another value: ";
        cin >> s.midterm;

    }

    int score;
    cout << "Enter homework " << "grade: (enter -1 to end): ";
    while(cin >> score && score != -1) {
        if(score <= 100 && score >= 0) {
          cout << "Enter homework " << "grade: (enter -1 to end): ";
          s.hw_grades.push_back(score);
          }
        else(cout << "Please enter a valid homework grade(between 0 and 100)\nEnter grade: (enter -1 to end): ");
        }
    }

double average_score(student &s) {
    double hw_total = 0.0;
    double hw_average = 0.0;
    for(int i = 0; i < s.hw_grades.size(); i++) {
        hw_total = hw_total + s.hw_grades[i];
    }
    hw_average = (hw_total/s.hw_grades.size())*0.40;

    double total_average = s.final*0.30 + s.midterm*0.30 + hw_average;
    double final_avg, midterm_avg, hw_avg;
    midterm_avg = s.midterm*0.30;
    final_avg = s.final*0.30;
    cout << "Name: " << s.name << "\n";
    cout << "Midterm grade: "<< midterm_avg/0.30 << "\nFinal grade: " << final_avg/0.30 << "\nHomework average: " << hw_average/0.40 << "\n";
    cout << "Grade: " << total_average << endl;
    return total_average;
}