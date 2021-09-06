#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
};

void
find_minmax(const vector<double>& numbers, double& min, double& max);

vector<size_t>
make_histogram(Input data);

void
show_histogram_text(vector<size_t> bins);
