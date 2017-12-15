#include <vector>

#include "point.hpp"

namespace launchrange {
    template<typename T>
    struct range_ {
        point_<T> begin;
        point_<T> end;

        bool operator==(const range_<T>& other) const {
            return other.begin == this->begin && other.end == this->end;
        }

        bool operator !=(const range_<T>& other) const {
            return !((*this) == other);
        }

        std::vector<range_<T>> operator-(const range_<T>& other) const {
            if (this->begin < other.begin && this->end > other.end)
                return { range_<T> { this->begin, point_<T> { other.begin.at, (other.begin.state == point_state::OPEN ? point_state::CLOSED : point_state::OPEN) } },
                         range_<T> { point_<T> { other.end.at, (other.end.state == point_state::OPEN ? point_state::CLOSED : point_state::OPEN) }, this->end } };
            else if (other.begin < this->begin && other.end > this->end)
                return { };
            else if (other.begin.at == this->begin.at && this->end < other.end) {
                if (other.begin.state == point_state::CLOSED)
                    return { };
                else {
                    if (this->begin.state == point_state::CLOSED)
                        return { range_<T> { this->begin, this->begin } };
                    else
                        return { };
                }
            } else if (this->begin.at > other.begin.at && this->end == other.end) {
                if (other.end.state == point_state::CLOSED)
                    return { };
                else {
                    if (this->end.state == point_state::CLOSED)
                        return { range_<T> { this->end, this->end } };
                    else
                        return { };
                }
            } else
                return { };
        }

        template<typename T0>
        friend std::ostream& operator<<(std::ostream& os, const range_<T0>& next);
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const range_<T>& next) {
        os << "[ from " << next.begin << " to " << next.end << " ]";
        return os;
    }
}
