#include <stdio.h>
#include <stdlib.h>

#include "poly_creux.h"

#include <x86intrin.h>
#include <math.h>

p_polyf_creux_t creer_polynome (int nb_degre)
{
  p_polyf_creux_t p ;
  
  p = (p_polyf_creux_t) malloc (sizeof (p_polyf_creux_t)) ;
  p->nb_degre = nb_degre ;

  p->elements = (p_element *) malloc ((nb_degre) * sizeof (p_element))  ;

  for (int i = 0 ; i <= p->nb_degre; ++i){
    p->elements[i] = malloc(sizeof(element));
  }

  return p ;
}

//pré-requis : les tableaux degres et coeffs de taille nb_degre
p_polyf_creux_t creer_polynome_tab (int nb_degre, int* degres, float* coeffs){
   p_polyf_creux_t p = creer_polynome(nb_degre);

   for(int i=0; i<nb_degre; i++){
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

  for (i = 0 ; i <= p->nb_degre; ++i){
    p->elements[i]->coeff = x ;
    p->elements[i]->degre=i;
  }

  return ;
}

void ecrire_polynome_float (p_polyf_creux_t p)
{
  

  return ;
}

int egalite_polynome (p_polyf_creux_t p1, p_polyf_creux_t p2)
{
  if(p1->nb_degre != p2->nb_degre)
    return 0;
  for(int i=0; i<p1->nb_degre; i++){
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

  for(int i=0; i<p->nb_degre; i++){
    resultat+= p->elements[i]->coeff * pow(x, p->elements[i]->degre);
  }
  return resultat; 
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

