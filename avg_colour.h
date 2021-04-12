#pragma once

#include <vector>

using namespace std;

vector<size_t>
bin_height(const vector<size_t>& bins, bool scaling_needed, size_t max_count, size_t MAX_ASTERISK, int BLOCK_WIDTH);

double
avg(const vector<size_t>& heights);
