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
  free(p->element);
  free(p);

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
  printf("%f X^%d",p->element[0].coeff,p-element[0].degre);
  for (int i=1;i<=p->nb_degre,i++){
    printf("+ %f * X^%d",p->element[i].coeff,p-element[i].degre);
  }

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
  int nb_degre=0;
  int i1=0;
  int i2=0;
  while(i1!=p1->nb_degre && i2!=p2->nb_degre){
    if(p1->element[i1].degre==p1->element[i2].degre){
      nb_degre++;
      i1++;
      i2++;
    }
    if(p1->element[i1].degre<p1->element[i2].degre){
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
  i=0;
  while(i1!=p1->nb_degre && i2!=p2->nb_degre){
    if(p1->element[i1].degre==p1->element[i2].degre){
      p->element[i].coeff=p1->element[i1].coeff+p2->element[i2].coeff;
      p->element[i].degre=p1->element[i1]->degre;
      i1++;
      i++;
      i2++;
    }
    if(p1->element[i1].degre<p1->element[i2].degre){
      p->element[i].coeff=p2->element[i2].coeff;
      p->element[i].degre=p2->element[i2].degre;
      i++;
      i2++;
    }
    else{
      p->element[i].coeff=p1->element[i1].coeff;
      p->element[i].degre=p1->element[i1].degre;
      i++
      i1++;
    }
  }
  return p;
}

p_polyf_creux_t multiplication_polynome_scalaire (p_polyf_creux_t p, float alpha)
{
  p_polyf_creux_t new_p=creer_polynome(p->nb_degre);
  for(int i=0;i<=p->degre;i++){
    new_p->element[i].coeff=p->element[i].coeff*alpha;
    new_p->element[i].degre=p->element[i].degre;
  }
  

  return new_p ;
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

