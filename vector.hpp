#ifndef vector_hpp
#define vector_hpp

template <typename T>
class Vector2 {
public:
    T x;
    T y;

    Vector2() : x(T(0)), y(T(0)) {}
    Vector2(const T &x, const T &y) : x(x), y(y) {}

    Vector2 operator+(const Vector2 &v) const {
        return Vector2(x + v.x, y + v.y);
    }
    Vector2 operator-(const Vector2 &v) const {
        return Vector2(x - v.x, y - v.y);
    }
    Vector2 operator*(const Vector2 &v) const {
        return Vector2(x * v.x, y * v.y);
    }
    Vector2 operator/(const Vector2 &v) const {
        return Vector2(x / v.x, y / v.y);
    }
};

#endif
