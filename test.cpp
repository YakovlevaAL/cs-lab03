#include "histogram.h"
#include "avg_colour.h"

#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-4, -5, -2}, min, max);
    assert(min == -5);
    assert(max == -2);

    find_minmax({2, 2, 2}, min, max);
    assert(min == 2);
    assert(max == 2);
}

void
test_equal() {
    double min = 0;
    double max = 0;
    find_minmax({2, 2, 2}, min, max);
    assert(min == 2);
    assert(max == 2);
}

void
test_one() {
    double min = 0;
    double max = 0;
    find_minmax({5}, min, max);
    assert(min == 5);
    assert(max == 5);
}

void test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void
test_colour_first() {
    vector<size_t> bins = {5, 6, 7};
    bool scaling_needed = false;
    size_t max_count = 7;
    size_t MAX_ASTERISK = 330;
    int BLOCK_WIDTH = 10;

    auto result11 = bin_height(bins, scaling_needed, max_count, MAX_ASTERISK, BLOCK_WIDTH);

    vector<size_t> answ = {5, 6, 7};
    assert(result11 == answ);

    auto result12 = avg(result11);
    assert(result12 == 6);

    auto result13 = color(result11[1], result12);
    assert(result13 == "green");
}

void
test_colour_second() {
    vector<size_t> bins = {10, 12, 20};
    bool scaling_needed = true;
    size_t max_count = 18;
    size_t MAX_ASTERISK = 330;
    int BLOCK_WIDTH = 60;

    auto result21 = bin_height(bins, scaling_needed, max_count, MAX_ASTERISK, BLOCK_WIDTH);

    vector<size_t> answ = {3, 3, 6};
    assert(result21 == answ);

    auto result22 = avg(result21);
    assert(result22 == 4);

    auto result23 = color(result21[1], result22);
    assert(result23 == "green");
}

int
main() {
    test_positive();
    test_negative();
    test_equal();
    test_one();
    test_empty();
    test_colour_first();
    test_colour_second();
}
