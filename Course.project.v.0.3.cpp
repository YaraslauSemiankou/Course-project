#include <iostream>
#include "Functions.h"
#include <fstream>

using namespace std;

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
    {
        int f=0;
        ifstream myfile("book.txt");
        if (myfile.is_open())
        {
            cout << left << setw(20) << "Name" << setw(20) << "Surname" << right << setw(25) << "Final grade (Avg.)" << left << setw(25) << "/ Final grade (Med.)" << endl;
            cout << setfill('*') << setw(85) << "*" << setfill(' ') << endl;
            int a,b,c,d,e,f_exam;
            string name_text,surname_text;
            myfile.ignore(150, '\n');

            while (myfile >> name_text >> surname_text >> a >> b >> c >> d >> e >> f_exam)
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
                }
        else {cout << "Unable to open the file";}



        break;
    }
    case 'n':
    {
        for(i=0; i<999; i++)
        {
            string name_temporary, surname_temporary;
            cout << "Please enter student's name: \n";
            cin >> name_temporary;
            if (name_temporary == "0") break;
            student.push_back(program());
            student[i].name = name_temporary;

            cout << "Enter student's surname: \n";
            try{cin >> surname_temporary;
            if (surname_temporary == "0")
                throw "Incorrect input!";
            student[i].surname = surname_temporary;}
            catch (const char* msg)
            {
                student[i].surname = "ERROR";
                cout << msg << endl;
            }


            float total_homework_temporary = 0;
            int k;
            float exam_temporary, final_mark_temporary;

            cout << "Do you want to generate random numbers as grades for homework? (y/n): \n";
            char decision;
            cin >> decision;
            switch (decision)
            {
            case 'n':
                    for ( k=0; k>-1; k++)
                    {
                        int input;
                        cout << "Enter value of homework " << k+1 << ":\n";
                        cin >> input;
                        student[i].homework.push_back(input);
                        if (!cin || input == 0 || input > 10) break;
                    }

                cout << "Enter student's mark for the exam: \n";
                cin >> exam_temporary;
                if (!cin || exam_temporary == 0 || exam_temporary > 10) break;
                student[i].exam = exam_temporary;
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
                break;

            default:
                cout << "Incorrect input!";
                break;
            }
        try
        {
            if (student[i].homework==0) throw "The student did not take the exam!";
            student[i].final_mark_median = final_mark_median_function(student[i].homework, student[i].exam);
            student[i].final_mark = final_mark_average_function(student[i].homework, student[i].exam);
        }
        catch(const char* msg)
        {
            cout << msg << endl;
        }

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
        cout << "Incorrect input!";
        break;
    }
    return 0;
}
