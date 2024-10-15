#include "anal_geom.h"
#include <stdio.h>
#include <string.h>

vector3 normal_vector(point a, point b, point c)
{
    vector3 res;
    res.x = (b.y - a.y)*(c.z - a.z) - (b.z - a.z)*(c.y-a.y);
    res.y = (b.x - a.x)*(c.z - a.z) - (b.z - a.z)*(c.x-a.x);
    res.z = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x-a.x);
    return res;
}

void get_plane_equation(char * s, point a, point b, point c)
{
    vector3 n = normal_vector(a, b, c);
    float t = (-1*a.x*n.x)-(a.y*n.y)-(a.z*n.z); 
    char temp[256] = "";

    if (n.x != 0.0f) {
        sprintf(temp + strlen(temp), (n.x == (int)n.x) ? "%.0fx " : "%.4fx ", n.x);
    }

    if (n.y != 0.0f) {
        char y_char[32];
        sprintf(y_char, (n.y == (int)n.y) ? "%.0fy" : "%.4fy", n.y);
        sprintf(temp + strlen(temp), "%s%s ",
            (n.y > 0 && strlen(temp) > 0) ? "+" : "", y_char);
    }

    if (n.z != 0.0f) {
        char z_char[32];
        sprintf(z_char, (n.z == (int)n.z) ? "%.0fz" : "%.4fz", n.z);
        sprintf(temp + strlen(temp), "%s%s ",
            (n.z > 0 && strlen(temp) > 0) ? "+" : "", z_char);
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

void get_canon_line_equation(char *s, vector3 guiding, point m)
{
    
    char format_mx[10], format_my[10], format_mz[10];
    sprintf(format_mx, (m.x == (int)m.x) ? "%.0f" : "%f", m.x);
    sprintf(format_my, (m.y == (int)m.y) ? "%.0f" : "%f", m.y);
    sprintf(format_mz, (m.z == (int)m.z) ? "%.0f" : "%f", m.z);

   
    char format_gx[10], format_gy[10], format_gz[10];
    sprintf(format_gx, (guiding.x == (int)guiding.x) ? "%.0f" : "%f", guiding.x);
    sprintf(format_gy, (guiding.y == (int)guiding.y) ? "%.0f" : "%f", guiding.y);
    sprintf(format_gz, (guiding.z == (int)guiding.z) ? "%.0f" : "%f", guiding.z);

    sprintf(s, "(x-%s)/%s = (y-%s)/%s = (z-%s)/%s",
        format_mx, format_gx,
        format_my, format_gy,
        format_mz, format_gz
    );
}
