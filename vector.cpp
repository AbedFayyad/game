#include "vector.hpp"

template <typename T>
Vector2<T>::Vector2() : x(T(0)), y(T(0)) {}

template <typename T>
Vector2<T>::Vector2(const T &x, const T &y) : x(x), y(y) {}
