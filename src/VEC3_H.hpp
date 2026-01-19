
#ifndef VEC3_H
#define VEC3_H
#include <cmath>
#include <ostream>

// // My implementation of the vec3 class.
// class Vec3{

//     private:

//     double x;  
//     double y;
//     double z;
    
//     public:

//     Vec3(double xVal, double yVal, double zVal);
//     // Overloading the Vec3 operator
//     Vec3 operator+(const Vec3& other) const {
//         return Vec3(x + other.x, y + other.y, z + other.z);
//     }

//     Vec3 operator-(const Vec3& other) const {
//         return Vec3(x - other.x, y - other.y, z - other.z);
//     }

//     Vec3 operator*(const Vec3& other) const {
//         return Vec3(x * other.x, y * other.y, z * other.z);
//     }



//     const double getX() const;
//     const double getY() const;
//     const double getZ() const;
//     void setX(double newXVal);
//     void setY(double newYVal);
//     void setZ(double newZVal);

// };

// std::ostream& operator<<(std::ostream& out, const Vec3& other);


// An approach from Ray tracing

class vec3 {
    public:
    double e[3];  //array for holding x, y , z coordinates

    vec3() : e{0,0,0} {} //constructor for holding values
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // getters and setters
    double x() const {return e[0];}
    double y() const {return e[1];}
    double z() const {return e[2];}

    vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]);} // returns the negative of an existing array
    double operator[](int i) const{return e[i];} //returns the array index and overloads the binary operator []. Read only.
    double& operator[](int i) {return e[i];} //allows the operator function to read and write at the same time.

    // operator overloading of the +=. This allows the += binary operator to multiply
    vec3& operator +=(const vec3& v){
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];

        return *this;
    }


    //scales the operator and then returns the left hand vector
    vec3& operator*=(double t){
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;

        return *this;
    }


    vec3& operator/=(double t){
        return *this *= 1/t;
    }

    // returns the magnitude
    double length() const {
        return std::sqrt(length_squared());
    }

    double length_squared() const{
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

};


// Vector utility functions

// printing
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// + operator
inline vec3 operator+(const vec3& u, const vec3& v){
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

//  - pperator
inline vec3 operator-(const vec3& u, const vec3& v){
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(
        u.e[0] * v.e[0],
        u.e[1] * v.e[1],
        u.e[2] * v.e[2]
    );
}


inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, double t){
    return (1/t) * v;
}

inline double dot(const vec3& u, const vec3& v){
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v){
    return v/v.length();
}

#endif