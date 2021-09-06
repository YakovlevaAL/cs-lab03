#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

using namespace std;

vector<double>
input_numbers(istream& in,size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}

Input
read_input(istream& in){
Input data;
cerr<<"Enter number count: ";
size_t number_count;
in >> number_count;

cerr<<" Enter numbers: ";
data.numbers =input_numbers(in,number_count);


cerr <<"Enter bin count: ";
size_t bin_count;
in >> bin_count;

return data;
}

int
main()
{
    // Ввод данных
    read_input(cin);
    const auto input = read_input(cin);
    //Обработка данных
    const auto bins = make_histogram(input);

    // Вывод данных
    show_histogram_svg(bins);

    return 0;
}
