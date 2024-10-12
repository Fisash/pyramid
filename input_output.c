#include <stdio.h>
#include "vec.h"
#include "input_output.h"

int input_point(point *p, char name[])
{
    printf("Enter %s point coordinates: ", name);
    return scanf("%f %f %f", &p->x, &p->y, &p->z) == 3;
}

void print_vector_info(vector3 vec, char name[])
{
    printf(INDENT);
    printf("%s vector.\n", name);
    printf("Coordinates: (%f, %f, %f)\n", vec.x, vec.y, vec.z);
    printf("Length: %f\n", get_length(vec));
}