#include <stdio.h>
#include <stdlib.h>

#include "poly_creux.h"


int main (int argc, char **argv)
{
  p_polyf_creux_t p1, p2;

    //d'abord on créer des tableaux pour créer les polynomes
    int* degres = malloc(sizeof(int)*3);
    degres[0] = 1; degres[1] = 2; degres[2] = 3;
    float* coeffs = malloc(sizeof(float)*3);
    coeffs[0] = 3; coeffs[1] = 1; coeffs[2] = 1;

    float* coeffs2 = malloc(sizeof(float)*3);
    coeffs2[0] = 5; coeffs2[1] = 6; coeffs2[2] = 5;

    p1 = creer_polynome_tab(3,degres,coeffs);
    p2 = creer_polynome_tab(3,degres,coeffs2);


    printf("sont-ils égaux ? %d \n", egalite_polynome(p1, p2));
    printf("p1 avec x=2 : %f \n", eval_polynome(p1, 2));

}
