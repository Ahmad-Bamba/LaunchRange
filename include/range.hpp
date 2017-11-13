#include "point.hpp"

namespace launchrange {
    template<typename T>
    class range_ {
        point_<T> begin;
        point_<T> end;

        bool operator==(range_<T>& other) {
            return other.begin == this->begin && other.end == this->end;
        }
    };

    template<>
    class range_<float> {
        point_<float> begin;
        point_<float> end;


    };
}
