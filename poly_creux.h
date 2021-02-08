typedef struct{
    int degre;
    float coeff;
}element, *p_element;

typedef struct{
    int nb_degre;
    p_element* elements;
} polyf_creux_t, *p_polyf_creux_t;

p_polyf_creux_t creer_polynome (int degre) ;

p_polyf_creux_t creer_polynome_tab (int nbDegre, int* degres, float* coeffs) ;

void init_polynome (p_polyf_creux_t p, float x) ;

void detruire_polynome (p_polyf_creux_t p) ;

void ecrire_polynome_float (p_polyf_creux_t p) ;

int egalite_polynome (p_polyf_creux_t p1, p_polyf_creux_t p2) ;

p_polyf_creux_t addition_polynome (p_polyf_creux_t p1, p_polyf_creux_t p2) ;

p_polyf_creux_t multiplication_polynome_scalaire (p_polyf_creux_t p, float alpha) ;

float eval_polynome (p_polyf_creux_t p, float x) ;

p_polyf_creux_t multiplication_polynomes (p_polyf_creux_t p1, p_polyf_creux_t p2) ;

p_polyf_creux_t puissance_polynome (p_polyf_creux_t p, int n) ;

p_polyf_creux_t composition_polynome (p_polyf_creux_t p, p_polyf_creux_t q) ;