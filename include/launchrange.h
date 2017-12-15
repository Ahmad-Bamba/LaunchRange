#include "discontinuous.h"

#include <vector>

using int_point           = launchrange::point_<int>;
using int_range           = launchrange::range_<int>;
using float_point         = launchrange::point_<float>;
using float_range         = launchrange::range_<float>;
using double_range        = launchrange::range_<double>;
using double_point        = launchrange::point_<double>;

template<typename T>
using discontinuous_range = std::vector<launchrange::range_<T>>;

using dc_int_range        = discontinuous_range<int>;
using dc_float_range      = discontinuous_range<float>;
using dc_double_range     = discontinuous_range<double>;
