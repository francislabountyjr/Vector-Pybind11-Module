#pragma once

template <typename T>
class Vec3 {
public:
	Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
	Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
	Vec3(Vec3&& v) noexcept : x(v.x), y(v.y), z(v.z) { v.x = v.y = v.z = 0; }
	~Vec3() {}

	std::string toString() const {
		return "[" + std::to_string(x) + ", " + std::to_string(y) +
			", " + std::to_string(z) + "]";
	}

	Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
	Vec3& operator=(Vec3&& v) noexcept {
		x = v.x;
		y = v.y;
		z = v.z;
		v.x = v.y = v.z = 0;
		return *this;
	}
	
	Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
	Vec3& operator-=(const Vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
	Vec3& operator*=(const Vec3& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
	Vec3& operator/=(const Vec3& v) { x /= v.x; y /= v.y; z /= v.z; return *this; }
	Vec3& operator+=(T f) { x += f; y += f; z += f; return *this; }
	Vec3& operator-=(T f) { x -= f; y -= f; z -= f; return *this; }
	Vec3& operator*=(T f) { x *= f; y *= f; z *= f; return *this; }
	Vec3& operator/=(T f) { x /= f; y /= f; z /= f; return *this; }

	Vec3 operator-() const { return Vec3(-x, -y, -z); }
	Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
	Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
	Vec3 operator*(const Vec3& v) const { return Vec3(x * v.x, y * v.y, z * v.z); }
	Vec3 operator/(const Vec3& v) const { return Vec3(x / v.x, y / v.y, z / v.z); }
	Vec3 operator+(T f) const { return Vec3(x + f, y + f, z + f); }
	Vec3 operator-(T f) const { return Vec3(x - f, y - f, z - f); }
	Vec3 operator*(T f) const { return Vec3(x * f, y * f, z * f); }
	Vec3 operator/(T f) const { return Vec3(x / f, y / f, z / f); }

	Vec3 absolute() const { return Vec3(abs(x), abs(y), abs(z)); }

	friend Vec3 operator+(T f, const Vec3& v) { return Vec3(f + v.x, f + v.y, f + v.z); }
	friend Vec3 operator-(T f, const Vec3& v) { return Vec3(f - v.x, f - v.y, f - v.z); }
	friend Vec3 operator*(T f, const Vec3& v) { return Vec3(f * v.x, f * v.y, f * v.z); }
	friend Vec3 operator/(T f, const Vec3& v) { return Vec3(f / v.x, f / v.y, f / v.z); }

	bool operator==(const Vec3& v) const { return x == v.x && y == v.y && z == v.z; }
	bool operator!=(const Vec3& v) const { return x != v.x || y != v.y || z != v.z; }

	T dot(const Vec3& v) const { return (x * v.x) + (y * v.y) + (z * v.z); }

	Vec3 cross(const Vec3& v) const {
		return Vec3((y * v.z) - (z * v.y), (z * v.x) - (x * v.z), (x * v.y) - (y * v.x));
	}

	T magnitude() const { return sqrt(this->dot(*this)); }

	T angle(const Vec3& v) const { return acos(this->dot(v) / (this->magnitude() * v.magnitude())); }

	Vec3 direction() const {
		// returns unit vector in direction of original vector
		T length = magnitude();
		return Vec3(x / length, y / length, z / length);
	}

	Vec3 project(const Vec3& v) const {
		return (this->dot(v) / v.dot(v)) * v;
	}

	T x, y, z;
};