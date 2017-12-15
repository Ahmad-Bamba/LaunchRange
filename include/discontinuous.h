#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "range.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<launchrange::range_<T>> next) {
    if (next.empty())
        os << "Empty";
    std::stringstream ss;
    for (const auto& thing : next)
        ss << thing << " U ";
    std::string s = ss.str();
    s.pop_back();
    s.pop_back();
    s.pop_back(); // remove trailing " U "
    os << s;
    return os;
}

namespace launchrange {
    // helper functions for using std::vector<launchrange::range_<T>>

    template<typename T>
    std::vector<range_<T>> add_dc_range(std::vector<range_<T>> dc1,
                                        std::vector<range_<T>> dc2) {
        return dc1.insert(dc1.end(), dc2.begin(), dc2.end());
    }

    template<typename T>
    std::vector<range_<T>> subtract_dc_range(std::vector<range_<T>> dc1,
                                             std::vector<range_<T>> dc2) {
        std::vector<range_<T>> res { };
        for (auto& cr0 : dc1)
            for (auto& cr1 : dc2) {
                auto diff = cr0 - cr1;
                res.insert(res.end(), diff.begin(), diff.end());
            }
        return res;
    }

    template<typename T>
    std::vector<range_<T>> subtract_dc_range(std::vector<range_<T>> dc, range_<T> cr) {
        return { };
    }

    template<typename T>
    std::vector<range_<T>> union_dc_range() {
        return { };
    }

    template<typename T>
    std::vector<range_<T>> simplify_dc() {
        return { };
    }

    template<typename T>
    range_<T> simplify_singleton(std::vector<range_<T>> dc) {
        return dc[0];
    }
}
