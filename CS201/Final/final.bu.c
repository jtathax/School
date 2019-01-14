#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int dartTtl = 1;
    double floatNumOut1 = 0.0, floatNumOut2 = 0.0;
    int dartsInside = 0;
    double pi = 0.0;
//    double pi = 3.14159;

    dartTtl = atoi(argv[1]);

//    printf("\ndartTtl = %d\n", dartTtl);
   
	printf("\nCS 201 - Final Exam - Jaime Landers\n");

//    void srand48(0);
    srand48(0);

    for (int i = 0; i < dartTtl; i++)
    {
//        double xCoord = .543;
      double xCoord = drand48();

//        double yCoord = 0.98;
      double yCoord = drand48();

//        printf("\nxCoord = %g\n", xCoord); // Temp
//      printf("\nxCoord = %ld\n", xCoord);
//        printf("\nyCoord = %g\n", yCoord); // Temp
//      printf("\nyCoord = %ld\n", yCoord);
    
        asm volatile("      fldl     %2                       \n"
                     "      fldl     %2                       \n"
                     "      fmull    %3                       \n"
                     "      fldl     %3                       \n"
                     "      fldl     %3                       \n"
                     "      fmull    %3                       \n"
                     "      fadd    %%ST(2), %%ST(0)         \n"
                     "      fsqrt                            \n"
                     "      fstl     %0                       \n"
                     :      "=m" (floatNumOut1),                 // Output %0 
                            "=m" (floatNumOut2)                  // Output %1
                     :      "m" (xCoord),                        // Inputs %2
                            "m" (yCoord)                         // Inputs %3
                     :      "eax", "ebx", "ecx"                  // Clobbers
        ); // Close asm

//        floatNumOut1 = 2; // Test

//     printf("\nfloatNumOut1 = %g\n", floatNumOut1); // Temp
//    printf("\nfloatNumOut1 = %d\n", floatNumOut1);

        if (floatNumOut1 <= 1)
        {
//            printf("\nInside Circle\n"); // Temp
            dartsInside++;
        }
/*        else if ((long int) floatNumOut1 > 1) // Temp
        { 
            printf("\nOutside Circle\n"); // Temp
        }
        else // Temp
            printf("\nDice Error\n"); // Temp
*/    
    } // close for loop   

//    printf("\ndartsInside = %d\n", dartsInside); // Temp

    pi = (4 * dartsInside/dartTtl);
//    pi = (dartsInside/dartTtl);
//    printf("\npi = %g\n", pi); // Temp

//    printf("\nintNumOut = %d\n", intNumOut);
//    printf("\nfloatNumOut1 = %lle\n", floatNumOut1);
//    printf("\nfloatNumOut1 = %ld\n\n", floatNumOut1);
//    printf("\nfloatNumOut2 = %el\n\n", floatNumOut2);
//    printf("\nfloatNumOut = %e\n\n", floatNumOut);

    printf("\n%d darts: pi = %0.10e\n\n", dartTtl, pi);

    return 0;

}

//double drand48()

//srand48(0);

