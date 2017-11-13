namespace launchrange {
    enum class point_state {
        CLOSED,
        OPEN
    };

    template<typename T>
    struct point_ {
        T at;
        point_state state;

        bool operator==(point_<T>& other) {
            return other.at == this->at && other.state == this->state;
        }

        bool operator<=(point_<T>& other) {
            return (*this) == other || this->at < other.at;
        }

        bool operator<(point_<T>& other) {
            return (*this) != other && (*this) <= other;
        }

        bool operator>(point_<T>& other) {
            return !((*this) <= other);
        }

        bool operator>=(point_<T>& other) {
            return (*this) == other || this->at > other.at;
        }
    };
}
