#ifndef ANAL_GEOM_H
#define ANAL_GEOM_H

#include "vec.h"

vector3 normal_vector(point a, point b, point c);

void get_plane_equation(char *s, point a, point b, point c);


void get_canon_line_equation(char *s, vector3 guiding, point m);

#endif