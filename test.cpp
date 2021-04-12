#include "histogram.h"

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

int
main() {
    test_positive();
    test_negative();
    test_equal();
    test_one();
    test_empty();
}