#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct program
{
  string name, surname;
  vector<float> homework;
  float exam, final_mark, final_mark_median;
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

        float total_homework_temporary = 0;
        int k;
        float exam_temporary, final_mark_temporary;

        cout << "Do you want to generate random numbers as grades for homework? (y/n): ";
        char decision;
        cin >> decision;
        switch (decision)
        {
            case 'n':
                for ( k=0; k<999; k++)
                {

                    float homework_temporary;
                    cout << "Enter value of homework " << k+1 << ":\n";
                    cin >> homework_temporary;
                    if (!cin || homework_temporary == 0 || homework_temporary > 10) break;
                    student[i].homework.push_back(homework_temporary);
                    total_homework_temporary += homework_temporary;

                }

                if (total_homework_temporary == 0) break;
                cout << "Enter student's mark for the exam: \n";
                cin >> exam_temporary;
                if (!cin || exam_temporary == 0 || exam_temporary > 10) break;
                student[i].exam = exam_temporary;
                final_mark_temporary = 0.4 * total_homework_temporary /  k + 0.6 * exam_temporary;
                student[i].final_mark = final_mark_temporary;
                break;


            case 'y':
                cout << "Enter number of homeworks: ";
                int number_homeworks;
                cin >> number_homeworks;
                for(int m=0; m<number_homeworks; m++)
                {
                    student[i].homework.push_back(rand()%11);
                    total_homework_temporary += student[i].homework[m];

                }
                exam_temporary = rand()%11;
                final_mark_temporary = 0.4 * total_homework_temporary /  student[i].homework.size() + 0.6 * exam_temporary;
                student[i].final_mark = final_mark_temporary;

            default:
                break;
        }

        float median_mark_temporary;
        sort(student[i].homework.begin(), student[i].homework.end());
        if (student[i].homework.size() % 2 == 0)
            median_mark_temporary = (student[i].homework[student[i].homework.size()/2 - 1] + student[i].homework[student[i].homework.size()/2]) / 2;

        else
            median_mark_temporary = student[i].homework[student[i].homework.size()/2];

        float median_final_mark_temporary = median_mark_temporary * 0.4 + 0.6 * exam_temporary;
        student[i].final_mark_median = median_final_mark_temporary;


    }

    cout << left << setw(20) << "Name" << setw(20) << "Surname" << right << setw(25) << "Final grade (Avg.)" << left << setw(25) << "/ Final grade (Med.)" << endl;
    cout << setfill('*') << setw(85) << "*" << setfill(' ') << endl;
    for (int l=0; l <=i; l++)
    {
        cout  << left << setw(20) << student[l].name << setw(20) << student[l].surname << right << setw(25) << setprecision(2) << fixed << student[l].final_mark << right << setw(20) << student[l].final_mark_median << '\n';
    }
    return 0;
}
