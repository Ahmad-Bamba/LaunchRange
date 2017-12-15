#include <cassert>
#include <iostream>
#include <iostream>
#include <launchrange.h>


#define TESTS 2
using namespace launchrange;

int main( ) {
    assert(true);

    float_point p1 = { -0.27f, point_state::OPEN };
    float_point p2 = { 31.41, point_state::CLOSED };
    float_point p3 = { 2.5f, point_state::CLOSED };
    float_point p4 = { 15.01f, point_state::CLOSED };

    float_range r1 = { p1, p2 };
    float_range r2 = { p3, p4 };

    assert((r1 - r2) == (dc_float_range { float_range { p1, float_point { p3.at, point_state::OPEN } },
                                          float_range { float_point { p4.at, point_state::OPEN }, p2 } }));

    std::cout << "All " << TESTS << " passed!\n";
    return 0;
}
