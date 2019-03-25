#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct program
{
  string name, surname;
  vector<float> homework;
  float exam, final_mark;
};

int main()
{
    float grade;
    vector<program> student;
    int i;
    for(i=0; i<999; i++)
    {
        string name_temporary, surname_temporary;
        cout << "Please enter student's name: \n";
        cin >> name_temporary;
        if (name_temporary == "0") break;

        cout << "Enter student's surname: \n";
        cin >> surname_temporary;
        if (surname_temporary == "0") break;
        student.push_back(program());

        student[i].name = name_temporary;
        student[i].surname = surname_temporary;

        float total_homework_temporary;
        int k;
        for ( k=0; k<999; k++)
        {
            float homework_temporary;
            cout << "Enter value of homework " << k+1 << ":\n";
            cin >> homework_temporary;
            student[i].homework.push_back(float());
            student[i].homework[k] = homework_temporary;
            if (!cin || homework_temporary == 0 || homework_temporary > 10) break;

            total_homework_temporary += homework_temporary;
        }

        cout << "Enter student's mark for the exam: \n";
        float exam_temporary;
        cin >> exam_temporary;
        student[i].exam = exam_temporary;
        float final_mark_temporary;
        final_mark_temporary = 0.4 * total_homework_temporary / (k+1) + 0.6 * exam_temporary;
        student[i].final_mark = final_mark_temporary;
    }

    cout << left << setw(20) << "Name" << setw(20) << "Surname" << right << setw(25) << "Final grade (Avg.)" << left << setw(25) << "/ Final grade (Med.)" << '\n';
    cout << setw(90)<< setfill('*') << '\n';
    cout << setfill(' ') << right << setw(20) << "LOL";
    return 0;
}
