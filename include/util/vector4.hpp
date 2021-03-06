/**
 *  Mana - 3D Game Engine
 *  Copyright (C) 2021  Julian Zampiccoli
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef VECTOR4_HPP
#define VECTOR4_HPP

#include <cmath>

template<typename T>
class Vector4 {
public:
    T x;
    T y;
    T z;
    T w;

    Vector4()
            : x(0), y(0), z(0), w(0) {
    }

    explicit Vector4(T v)
            : x(v), y(v), z(v), w(v) {
    }

    Vector4(T x, T y, T z, T w)
            : x(x), y(y), z(z), w(w) {
    }

    Vector4<T> &operator+=(const Vector4<T> &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }

    Vector4<T> &operator-=(const Vector4<T> &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return *this;
    }

    Vector4<T> &operator*=(const Vector4<T> &v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        w *= v.w;
        return *this;
    }

    Vector4<T> &operator/=(const Vector4<T> &v) {
        v /= v.x;
        y /= v.y;
        z /= v.z;
        w /= v.w;
        return *this;
    }

    Vector4<T> &operator*=(const T &v) {
        x *= v;
        y *= v;
        z *= v;
        w *= v;
        return *this;
    }

    Vector4<T> &operator/=(const T &v) {
        x /= v;
        y /= v;
        z /= v;
        w /= v;
        return *this;
    }

    friend Vector4<T> operator+(const Vector4<T> &lhs, const Vector4<T> &rhs) {
        return Vector4<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
    }

    friend Vector4<T> operator-(const Vector4<T> &lhs, const Vector4<T> &rhs) {
        return Vector4<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
    }

    friend Vector4<T> operator*(const Vector4<T> &lhs, const T &rhs) {
        return Vector4<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
    }

    friend Vector4<T> operator/(const Vector4<T> &lhs, const T &rhs) {
        return Vector4<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
    }

    friend Vector4<T> operator*(const Vector4<T> &lhs, const Vector4<T> &rhs) {
        return Vector4<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
    }

    friend Vector4<T> operator/(const Vector4<T> &lhs, const Vector4<T> &rhs) {
        return Vector4<T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
    }

    friend bool operator==(const Vector4<T> &lhs, const Vector4<T> &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
    }

    friend bool operator!=(const Vector4<T> &lhs, const Vector4<T> &rhs) {
        return lhs.x != rhs.x && lhs.y != rhs.y && lhs.z != rhs.z && lhs.w != rhs.w;
    }

    //https://en.wikipedia.org/wiki/Euclidean_distance
    static double distance(const Vector4<T> &start, const Vector4<T> end) {
        return std::sqrt(
                std::pow(start.x - end.x, 2) + std::pow(start.y - end.y, 2) + std::pow(start.z - end.z, 2) +
                std::pow(start.w - end.w, 2));
    }
};

typedef Vector4<bool> Vec4b;
typedef Vector4<int> Vec4i;
typedef Vector4<float> Vec4f;
typedef Vector4<double> Vec4d;

#endif //VECTOR4_HPP