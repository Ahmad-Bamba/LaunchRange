#include "range.hpp"

#include <vector>

using int_range           = launchrange::range_<int>;
using float_range         = launchrange::range_<float>;
using int_point           = launchrange::point_<int>;
using double_point        = launchrange::point_<double>;

template<typename T>
using discontinuous_range = std::vector<launchrange::range_<T>>;

using dc_int_range        = discontinuous_range<int>;
using dc_float_range      = discontinuous_range<float>;
