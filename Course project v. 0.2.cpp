#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

struct program
{
  string name, surname;
  vector<float> homework;
  float exam, final_mark, final_mark_median;
};

float final_mark_average_function ( vector<float> homework_data, float exam_function )
{
    float sum;
    for(int k=0; k<=homework_data.size(); k++)
    {
        sum += homework_data[k];
    }
    float r;
    r = sum / homework_data.size() * 0.4 + exam_function * 0.6;
    return r;
}

float final_mark_median_function (vector<float> homework_data_2, float exam_function_2)
{
    float median_mark_temporary;
        sort(homework_data_2.begin(), homework_data_2.end());
        if (homework_data_2.size() % 2 == 0)
            median_mark_temporary = (homework_data_2[homework_data_2.size()/2 - 1] + homework_data_2[homework_data_2.size()/2]) / 2;

        else
            median_mark_temporary = homework_data_2[homework_data_2.size()/2];
    float r_2;
    r_2 = median_mark_temporary *0.4 + 0.6 * exam_function_2;
    return r_2;
}

int main()
{
    float grade;
    vector<program> student;
    int i;
    char decision_2;
    cout << "Want to read the text file? y/n\n";
    cin >> decision_2;
    switch (decision_2)
    {
    case 'y':
        {string line;
        int f=0;
        ifstream myfile("book.txt");
        if (myfile.is_open())
        {
            cout << left << setw(20) << "Name" << setw(20) << "Surname" << right << setw(25) << "Final grade (Avg.)" << left << setw(25) << "/ Final grade (Med.)" << endl;
            cout << setfill('*') << setw(85) << "*" << setfill(' ') << endl;
            int a,b,c,d,e,f_exam;
            string name_text,surname_text;
            while (getline(myfile,line))
                {
            if (myfile >> name_text >> surname_text >> a >> b >> c >> d >> e >> f_exam)
            {
                student.push_back(program());
                student[f].name = name_text;
                student[f].surname = surname_text;
                student[f].homework.push_back(a);
                student[f].homework.push_back(b);
                student[f].homework.push_back(c);
                student[f].homework.push_back(d);
                student[f].homework.push_back(e);
                student[f].exam = f_exam;
                student[f].final_mark = final_mark_average_function(student[f].homework, student[f].exam);
                student[f].final_mark_median = final_mark_median_function(student[f].homework, student[f].exam);
                cout  << left << setw(20) << student[f].name << setw(20) << student[f].surname
        << right << setw(25) << setprecision(2) << fixed << student[f].final_mark << right << setw(20) << student[f].final_mark_median << '\n';
                f++;

            }
            else
                {cout << left << setw(20) << "Name" << setw(20) << "Surname" << right << setw(25) << "Final grade (Avg.)" << left << setw(25) << "/ Final grade (Med.)" << endl;
    cout << setfill('*') << setw(85) << "*" << setfill(' ') << endl;}
                }}
        else {cout << "Unable to open the file";}



        break;}
        case 'n':
    {
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

                }
                cout << "Enter student's mark for the exam: \n";
                cin >> exam_temporary;
                if (!cin || exam_temporary == 0 || exam_temporary > 10) break;
                student[i].exam = exam_temporary;
                student[i].final_mark = final_mark_average_function(student[i].homework, student[i].exam);
                break;


            case 'y':
                cout << "Enter number of homeworks: ";
                int number_homeworks;
                cin >> number_homeworks;
                for(int m=0; m<number_homeworks; m++)
                {
                    student[i].homework.push_back(rand()%11);

                }
                student[i].exam = rand()%11;

            default:
                break;
        }
        student[i].final_mark_median = final_mark_median_function(student[i].homework, student[i].exam);
        student[i].final_mark = final_mark_average_function(student[i].homework, student[i].exam);

    }

    cout << left << setw(20) << "Name" << setw(20) << "Surname" << right << setw(25) << "Final grade (Avg.)" << left << setw(25) << "/ Final grade (Med.)" << endl;
    cout << setfill('*') << setw(85) << "*" << setfill(' ') << endl;
    for (int l=0; l <=i; l++)
    {
        cout  << left << setw(20) << student[l].name << setw(20) << student[l].surname
        << right << setw(25) << setprecision(2) << fixed << student[l].final_mark << right << setw(20) << student[l].final_mark_median << '\n';
    }
    break;}

    default:
        break;
    }
    return 0;
}
