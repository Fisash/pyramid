#include <stdio.h>
#include "math.h"
#include "vec.h"
 

vector3 create_vector3(point s, point f)
{
    vector3 res = {f.x - s.x, f.y - s.y, f.z - s.z};
    return res;
}
float get_length(vector3 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
vector3 multiply(vector3 v, float num)
{
    vector3 res = v;
    res.x *= num;
    res.y *= num;
    res.z *= num;
    return res;
}

vector3 reverse(vector3 v)
{
    return multiply(v, -1.0);
}
vector3 add(vector3 v1, vector3 v2)
{
    vector3 res;
    res.x = v1.x + v2.x;
    res.y = v1.y + v2.y;
    res.z = v1.z + v2.z;
    return res;
}
vector3 subtraction(vector3 v1, vector3 v2)
{
    return add(v1, reverse(v2));
}
float scalar_product(vector3 v1, vector3 v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

float get_angle_between_vectors(vector3 v1, vector3 v2)
{
    float cos = scalar_product(v1, v2) / (get_length(v1) * get_length(v2));
    return acos(cos);
}

float get_angle_between_edge_and_face(vector3 edge, vector3 normal)
{
    float sin = (fabsf(scalar_product(edge, normal)))/(get_length(edge)*get_length(normal));
    return asin(sin);
}

vector3 vector_product(vector3 v1, vector3 v2)
{
    vector3 res;
    res.x = v2.z*v1.y - v1.z*v2.y;
    res.y = (v2.z*v1.x - v1.z*v2.x) * -1;
    res.z = v2.y*v1.x - v1.y*v2.x;

    return res;
}

float mixed_product(vector3 a, vector3 b, vector3 c)
{
    return scalar_product(vector_product(a, b), c);
}