#include <iostream>
#include "Functions.h"
#include <fstream>
#include <chrono>

using namespace std;

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

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
            student.push_back(program());
            student[i].name = name_temporary;
            if (name_temporary == "0") break;

            cout << "Enter student's surname: \n";
            try
            {
                cin >> surname_temporary;
                if (surname_temporary == "0")
                    throw "Incorrect input!";
                student[i].surname = surname_temporary;
            }
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
                if (student[i].homework[0]==0 || student[i].exam==0)
                    throw "The student can not be evaluated because:";
                student[i].final_mark_median = final_mark_median_function(student[i].homework, student[i].exam);
                student[i].final_mark = final_mark_average_function(student[i].homework, student[i].exam);
            }
            catch(const char* msg)
            {
                cout << msg << endl;
                cout << "  1) They does not have any evaluated homework;\n  2) They did not take the final exam."<< endl;
            }

        }
        break;}

    default:
        cout << "Incorrect input!";
        break;
    }
    try
    {
        if ((decision_2 != 'y' && decision_2 != 'n') || student[0].name == "0")
            throw "No data to output!";
        vector<program> failed_vector;
        vector<program> passed_vector;
        ofstream failed, passed;
        for (int i=0; i<student.size(); i++)
        {
            if(student[i].final_mark<5)
            {
                failed_vector.push_back(student[i]);
            }
        else
            passed_vector.push_back(student[i]);
        }
        student.clear();
        student.shrink_to_fit();

        failed.open("failed.txt");
        failed << left << setw(85) << " List of students who failed the subject";
        failed << setfill('*') << setw(85) << "*" << setfill(' ') << endl;
        failed << left << setw(20) << "Name" << setw(20) << "Surname" << right << setw(25) << "Final grade (Avg.)" << left << setw(25) << "/ Final grade (Med.)" << endl;
        failed << setfill('*') << setw(85) << "*" << setfill(' ') << endl;
        for (int i=0; i<failed_vector.size(); i++)
        {
            failed << left << setw(20) << failed_vector[i].name << setw(20) << failed_vector[i].surname
                << right << setw(25) << setprecision(2) << fixed << failed_vector[i].final_mark << right << setw(20) << failed_vector[i].final_mark_median << '\n';
        }
        failed.close();

        passed.open("passed.txt");
        passed << left << setw(85) << " List of students who passed the subject";
        passed << setfill('*') << setw(85) << "*" << setfill(' ') << endl;
        passed << left << setw(20) << "Name" << setw(20) << "Surname" << right << setw(25) << "Final grade (Avg.)" << left << setw(25) << "/ Final grade (Med.)" << endl;
        passed << setfill('*') << setw(85) << "*" << setfill(' ') << endl;
        for (int i=0; i<passed_vector.size(); i++)
        {
            passed << left << setw(20) << passed_vector[i].name << setw(20) << passed_vector[i].surname
                << right << setw(25) << setprecision(2) << fixed << passed_vector[i].final_mark << right << setw(20) << passed_vector[i].final_mark_median << '\n';
        }
        passed.close();

        cout << '\n' << left << setw(20) << "Name" << setw(20) << "Surname" << right << setw(25) << "Final grade (Avg.)" << left << setw(25) << "/ Final grade (Med.)" << endl;
        cout << setfill('*') << setw(85) << "*" << setfill(' ') << endl;
        cout << setfill('*') << left << setw(85) << "List of students who passed the subject" << endl;
        cout << setw(85) << "*" << setfill(' ') << endl;
        for (int i=0; i<passed_vector.size(); i++)
        {
            cout << left << setw(20) << passed_vector[i].name << setw(20) << passed_vector[i].surname
                << right << setw(25) << setprecision(2) << fixed << passed_vector[i].final_mark << right << setw(20) << passed_vector[i].final_mark_median << '\n';
        }
        cout << setfill('*') << setw(85) << "*" << setfill(' ') << endl;
        cout << setfill('*') << left << setw(85) << "List of students who failed the subject" << endl;
        cout << setw(85) << "*" << setfill(' ') << endl;
        for (int i=0; i<failed_vector.size(); i++)
        {
            cout << left << setw(20) << failed_vector[i].name << setw(20) << failed_vector[i].surname
                << right << setw(25) << setprecision(2) << fixed << failed_vector[i].final_mark << right << setw(20) << failed_vector[i].final_mark_median << '\n';
        }

    }
    catch(const char* no_data)
    {
        cout << no_data << endl;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout << "Elapsed time: " << elapsed.count() << " s\n";
    return 0;
}
