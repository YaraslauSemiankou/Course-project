#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>


struct program
{
  std::string name, surname;
  std::vector<int> homework;
  int exam;
  float final_mark, final_mark_median;
};

float final_mark_average_function ( std::vector<int> homework_data, int exam_function )
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

float final_mark_median_function (std::vector<int> homework_data_2, int exam_function_2)
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
