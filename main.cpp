#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <string>
#include<windows.h>
#include <sstream>

using namespace std;

vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

string
make_info_text() {
    std::stringstream buffer;
    DWORD info =GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD version_major = version & 0x00ff;
    DWORD version_minor = version & 0xff00;
    version_minor = version >>8;
    DWORD platform = info>>16;
    DWORD build;
    if ((platform &0x8000) == 0) build =platform;
    return buffer.str();
}

int
main()
{
    make_info_text();
    return 0;
    // Ввод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    //Обработка данных
    const auto bins = make_histogram(numbers, bin_count);

    // Вывод данных
    show_histogram_svg(bins);

    return 0;
}
