#ifndef VEC_H
#define VEC_H

typedef struct {
    float x;
    float y;
    float z;
} point;

typedef struct {
    float x;
    float y;
    float z;
} vector3;

vector3 create_vector3(point s, point f);
float get_length(vector3 v);
vector3 multiply(vector3 v, float num);
vector3 reverse(vector3 v);

vector3 add(vector3 v1, vector3 v2);
vector3 subtraction(vector3 v1, vector3 v2);

float scalar_product(vector3 v1, vector3 v2);

float get_angle_between_vectors(vector3 v1, vector3 v2);

float get_angle_between_edge_and_face(vector3 edge, vector3 normal);

vector3 vector_product(vector3 v1, vector3 v2);

float mixed_product(vector3 a, vector3 b, vector3 c);

#endif