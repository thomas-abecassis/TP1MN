#include <stdio.h>
#include <stdlib.h>

#include "poly_creux.h"

#include <x86intrin.h>
#include <math.h>

p_polyf_creux_t creer_polynome (int nbDegree)
{
  p_polyf_creux_t p ;
  
  p = (p_polyf_creux_t) malloc (sizeof (p_polyf_creux_t)) ;
  p->nbDegree = nbDegree ;

  p->elements = (float *) malloc ((nbDegree+1) * sizeof (struct element))  ;

  return p ;
}

//pré-requis : les tableaux degres et coeffs de taille nbDegre
p_polyf_creux_t creer_polynome_tab (int nbDegre, int* degres, float* coeffs){
   p_polyf_creux_t p = creer_polynome(nbDegre);

   for(int i=0; i<nbDegre; i++){
     p->elements[i]->degre=degres[i];
     p->elements[i]->coeff=coeffs[i];
   }
   return p;
}


void detruire_polynome (p_polyf_creux_t p)
{
  

  return ;
}

void init_polynome (p_polyf_creux_t p, float x)
{
  register unsigned int i ;

  for (i = 0 ; i <= p->nbDegree; ++i){
    p->elements[i] = malloc(sizeof(struct element));
    p->elements[i]->coeff = x ;
    p->element[i]->degre=i;
  }

  return ;
}

void ecrire_polynome_float (p_polyf_creux_t p)
{
  

  return ;
}

int egalite_polynome (p_polyf_creux_t p1, p_polyf_creux_t p2)
{
  if(p1->nbDegree != p2->nbDegree)
    return 0;
  for(int i=0; i<p1->nbDegree+1; i++){
    if(p1->elements[i]->degre != p2->elements[i]->degre || p1->elements[i]->coeff != p2->elements[i]->coeff)
      return 0;
  }
  return 1;
}

p_polyf_creux_t addition_polynome (p_polyf_creux_t p1, p_polyf_creux_t p2)
{
  return NULL;
}

p_polyf_creux_t multiplication_polynome_scalaire (p_polyf_creux_t p, float alpha)
{
  

  return NULL ;
}

float eval_polynome (p_polyf_creux_t p, float x)
{

  float resultat=0;

  for(int i=0; i<p->degre+1; i++){
    resultat+= p->coeff[i] * pow(x, i);
  }
  return NULL;
}


p_polyf_creux_t multiplication_polynomes (p_polyf_creux_t p1, p_polyf_creux_t p2)
{
  

  return NULL;
}

p_polyf_creux_t puissance_polynome (p_polyf_creux_t p, int n)
{
  /* 
     p^n
  */

  return NULL ;
}

p_polyf_creux_t composition_polynome (p_polyf_creux_t p, p_polyf_creux_t q)
{
  


  return NULL;
}

