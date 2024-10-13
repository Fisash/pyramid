#include <stdio.h>
#include "vec.h"
#include "input_output.h"
#include "math.h"
#include "anal_geom.h"

int main(void)
{
    point A, B, C, D;
   
    if (input_point(&A, "A") && input_point(&B, "B") && input_point(&C, "C") && input_point(&D, "D")){
        vector3 AB = create_vector3(A, B);
        print_vector_info(AB, "AB");
        vector3 AC = create_vector3(A, C);
        print_vector_info(AC, "AC");
        vector3 AD = create_vector3(A, D);
        print_vector_info(AD, "AD");
        vector3 BC = create_vector3(B, C);
        print_vector_info(BC, "BC");
        vector3 BD = create_vector3(B, D);
        print_vector_info(BD, "BD");
        vector3 CD = create_vector3(C, D);
        print_vector_info(CD, "CD");
        printf(INDENT);

        printf("\nAngles of ABC triangle:\n");
        float a_angle = get_angle_between_vectors(AB, AC);
        float b_angle = get_angle_between_vectors(BC, reverse(AB));
        float c_angle = get_angle_between_vectors(reverse(BC), reverse(AC));
        printf("1)A angle = %f rad = %f deg\n", a_angle, (a_angle*180/3.1415));
        printf("2)B angle = %f rad = %f deg\n", b_angle, (b_angle*180/3.1415));
        printf("3)C angle = %f rad = %f deg\n", c_angle, (c_angle*180/3.1415));
        printf(INDENT);

        float ABC_area = 0.5 * get_length(vector_product(AB, AC));
        printf("Area of ABC is %f\n", ABC_area);
        printf(INDENT);

        float mixed_p = mixed_product(AB, AC, AD);
        float volume = (1.0/6.0) * fabsf(mixed_p);
        printf("(Mixed product AB AC AD is %f)\n", mixed_p);
        printf("Volume of ABCD pyramide is %f\n", volume);
        printf(INDENT);
        
        float height = volume / ABC_area * 3;
        printf("ABCD pyramid height is %f\n", height);
        printf(INDENT);

        vector3 ABC_normal = normal_vector(A, B, C);
        float AD_ABC_angle = get_angle_between_edge_and_face(AD, ABC_normal);
        printf("Angle between AD edge and ABC plane = %f rad = %f deg\n", AD_ABC_angle, (AD_ABC_angle*180/3.1415));
        printf(INDENT);
        
        char pl_equat[64];
        get_plane_equation(pl_equat, A, B, C);
        printf("ABC plane equation: %s\n", pl_equat);
        printf(INDENT);

        char AD_equat[64];
        get_canon_line_equation(AD_equat, AD, A);
        printf("AD line canon equatuin: %s\n", AD_equat);
        printf(INDENT);

        char AH_equat[64];
        get_canon_line_equation(AH_equat, ABC_normal, D);
        printf("Height line canon equatuin: %s\n", AH_equat);
        printf(INDENT);
      
        getchar();
    }
    else
    {
        printf("Incorrect format for entering coordinates for points (enter three numbers separated by a space for each point)\n");
    }
    printf("Press any key to finish\n");
    getchar();
}