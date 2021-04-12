#include "avg_colour.h"

vector<size_t>
bin_height(const vector<size_t>& bins, bool scaling_needed, size_t max_count, size_t MAX_ASTERISK, int BLOCK_WIDTH)
{
    vector<size_t> result(bins.size());
    size_t i = 0;
    for (size_t bin : bins)
    {
        result[i] = bin;
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / (max_count * BLOCK_WIDTH);
            result[i] = (size_t)(bin * scaling_factor);
        }
        i++;
    }
    return result;
}

double
avg(const vector<size_t>& heights)
{
    double avg = 0;
    for (size_t height : heights)
    {
        avg += height;
    }

    avg /= heights.size();

    return avg;
}

string
color(size_t height, double heights_average)
{
    if (height > heights_average)
            return "red";
        else
            return "green";
}
