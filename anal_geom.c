#include "anal_geom.h"
#include <stdio.h>
#include <string.h>

void get_plane_equation(char * s, point a, point b, point c)
{
    float x = (b.y - a.y)*(c.z - a.z) - (b.z - a.z)*(c.y-a.y);
    float y = (b.x - a.x)*(c.z - a.z) - (b.z - a.z)*(c.x-a.x);
    float z = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x-a.x);

    float t = (-1*a.x*x)+(-1*a.y*y)+(-1*a.z*z); 

    char temp[256] = "";

    if (x != 0.0f) {
    sprintf(temp + strlen(temp), (x == (int)x) ? "%.0fx " : "%.4fx ", x);
    }

    if (y != 0.0f) {
        char y_char[32];
        sprintf(y_char, (y == (int)y) ? "%.0fy" : "%.4fy", y);
        sprintf(temp + strlen(temp), "%s%s ",
            (y > 0 && strlen(temp) > 0) ? "+" : "", y_char);
    }

    if (z != 0.0f) {
        char z_char[32];
        sprintf(z_char, (z == (int)z) ? "%.0fz" : "%.4fz", z);
        sprintf(temp + strlen(temp), "%s%s ",
            (z > 0 && strlen(temp) > 0) ? "+" : "", z_char);
    }

    if (t != 0.0f) {
        char t_char[32];
        sprintf(t_char, (t == (int)t) ? "%.0f" : "%.4f", t);
        sprintf(temp + strlen(temp), "%s%s ",
            (t > 0 && strlen(temp) > 0) ? "+" : "", t_char);
    }

    sprintf(temp + strlen(temp), "= 0");


    strcpy(s, temp);
}