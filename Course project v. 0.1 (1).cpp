#include <iostream>
#include <vector>
#include <string>
#include <cmath>

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


    }
    return 0;
}
