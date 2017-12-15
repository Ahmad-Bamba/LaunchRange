#include <iostream>

namespace launchrange {
    enum class point_state {
        CLOSED,
        OPEN
    };

    template<typename T>
    struct point_ {
        T at;
        point_state state;

        bool operator==(const point_<T>& other) const {
            return other.at == this->at && other.state == this->state;
        }

        bool operator!=(const point_<T>& other) const {
            return !((*this) == other);
        }

        bool operator<=(const point_<T>& other) const {
            return (*this) == other || this->at < other.at;
        }

        bool operator<(const point_<T>& other) const {
            return (*this) != other && (*this) <= other;
        }

        bool operator>(const point_<T>& other) const {
            return !((*this) <= other);
        }

        bool operator>=(point_<T>& other) {
            return (*this) == other || this->at > other.at;
        }
        template<typename T0>
        friend std::ostream& operator<<(std::ostream& os, const point_<T0>& next);
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const point_<T>& next) {
        os << '{' << (next.state == point_state::OPEN ? " not including " : " including ") << next.at << ' ' << '}';
        return os;
    }
}
