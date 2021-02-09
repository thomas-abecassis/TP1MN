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
  free(p->elements);
  free(p);

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
  printf("%f X^%d",p->elements[0]->coeff,p->elements[0]->degre);
  for (int i=1;i<=p->nb_degre;i++){
    printf("+ %f * X^%d",p->elements[i]->coeff,p->elements[i]->degre);
  }

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
  int nb_degre=0;
  int i1=0;
  int i2=0;
  while(i1!=p1->nb_degre && i2!=p2->nb_degre){
    if(p1->elements[i1]->degre==p1->elements[i2]->degre){
      nb_degre++;
      i1++;
      i2++;
    }
    if(p1->elements[i1]->degre<p1->elements[i2]->degre){
      nb_degre++;
      i2++;
    }
    else{
      nb_degre++;
      i1++;
    }
  }
  p_polyf_creux_t p=creer_polynome(nb_degre);
  i1=0;
  i2=0;
  int i=0;
  while(i1!=p1->nb_degre && i2!=p2->nb_degre){
    if(p1->elements[i1]->degre==p1->elements[i2]->degre){
      p->elements[i]->coeff=p1->elements[i1]->coeff+p2->elements[i2]->coeff;
      p->elements[i]->degre=p1->elements[i1]->degre;
      i1++;
      i++;
      i2++;
    }
    if(p1->elements[i1]->degre<p1->elements[i2]->degre){
      p->elements[i]->coeff=p2->elements[i2]->coeff;
      p->elements[i]->degre=p2->elements[i2]->degre;
      i++;
      i2++;
    }
    else{
      p->elements[i]->coeff=p1->elements[i1]->coeff;
      p->elements[i]->degre=p1->elements[i1]->degre;
      i++;
      i1++;
    }
  }
  return p;
}

p_polyf_creux_t multiplication_polynome_scalaire (p_polyf_creux_t p, float alpha)
{
  p_polyf_creux_t new_p=creer_polynome(p->nb_degre);
  for(int i=0;i<=p->nb_degre;i++){
    new_p->elements[i]->coeff=p->elements[i]->coeff*alpha;
    new_p->elements[i]->degre=p->elements[i]->degre;
  }
  

  return new_p ;
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
  p_polyf_creux_t new_p;
  for(int i=0;i<=p->nb_degre;)
  return NULL;
}

