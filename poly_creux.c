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

  for (int i = 0 ; i < p->nb_degre; ++i){
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
  
  for (int i=0; i<p->nb_degre; i++){
    free(p->elements[i]);
  }
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
  for (int i=1;i<p->nb_degre;i++){
    printf("+ %f * X^%d",p->elements[i]->coeff,p->elements[i]->degre);
  }
  printf("\n");

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
    if(p1->elements[i1]->degre==p2->elements[i2]->degre){
      nb_degre++;
      i1++;
      i2++;
      
    }
    else{
      if(p1->elements[i1]->degre < p1->elements[i2]->degre){
        nb_degre++;
        i2++;
      }
      else{
        nb_degre++;
        i1++;
      }

    }
  }
  nb_degre+=(p1->nb_degre-i1)+(p2->nb_degre-i2);


  p_polyf_creux_t p=creer_polynome(nb_degre);
  i1=0;
  i2=0;
  int i=0;
  for(i=0;i<nb_degre;i++){
    if(i2==p2->nb_degre){
      break;
    }
    if(i1==p1->nb_degre){
      break;
    }
    if(p1->elements[i1]->degre == p2->elements[i2]->degre){
      p->elements[i]->coeff = p1->elements[i1]->coeff+p2->elements[i2]->coeff;
      p->elements[i]->degre = p1->elements[i1]->degre;
      i1++;
      i2++;
    }
    else{
      if(p1->elements[i1]->degre > p2->elements[i2]->degre){
      p->elements[i]->coeff = p2->elements[i2]->coeff;
      p->elements[i]->degre = p2->elements[i2]->degre;
      i2++;
      }
      else{
        if(p1->elements[i1]->degre < p2->elements[i2]->degre){
          p->elements[i]->coeff = p1->elements[i1]->coeff;
          p->elements[i]->degre = p1->elements[i1]->degre;
          i1++;
          }
      }
    }
    
  }
  if(i2==p2->nb_degre){
    for(int j=i1;j<p1->nb_degre;j++){
      p->elements[i]->coeff = p1->elements[j]->coeff;
      p->elements[i]->degre = p1->elements[j]->degre;
      i++;
    }
  }
  if(i1==p1->nb_degre){
    for(int j=i2;j<p2->nb_degre;j++){
      p->elements[i]->coeff = p2->elements[j]->coeff;
      p->elements[i]->degre = p2->elements[j]->degre;
      i++;
    }
  }
  return p;
}

p_polyf_creux_t multiplication_polynome_scalaire (p_polyf_creux_t p, float alpha)
{
  p_polyf_creux_t new_p=creer_polynome(p->nb_degre);
  for(int i=0;i<p->nb_degre;i++){
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


int degrePresentElements(int degreCherche, p_element* elements, int nbElements){
  for(int i=0; i<nbElements; i++){
    if(elements[i]->degre==degreCherche)
      return 1;
  }

  return 0;
}

p_polyf_creux_t multiplication_polynomes (p_polyf_creux_t p1, p_polyf_creux_t p2)
{
  p_element* nbTab = (p_element*) malloc(0);
  int nbElt = 0;

  for(int i=0; i<p1->nb_degre; i++){
    for(int j=0; j<p2->nb_degre; j++){
      int degreAddition = p1->elements[i]->degre+p2->elements[j]->degre;
      if(!degrePresentElements(degreAddition, nbTab, nbElt)){
        nbElt++;
        nbTab = (p_element*) realloc(nbTab, sizeof(p_element)*nbElt);
        nbTab[nbElt-1]=malloc(sizeof(element));
        nbTab[nbElt-1]->degre=degreAddition;
        nbTab[nbElt-1]->coeff=p1->elements[i]->coeff*p2->elements[j]->coeff;
      }
      else{
        for(int k=0; k<nbElt; k++){
          if(nbTab[k]->degre==degreAddition)
            nbTab[k]->coeff+=p1->elements[i]->coeff*p2->elements[j]->coeff;
        }
      }
    }
  }

  p_polyf_creux_t p= malloc(sizeof(polyf_creux_t));
  p->nb_degre=nbElt;
  p->elements=nbTab;
  return p; 
}

p_polyf_creux_t puissance_polynome (p_polyf_creux_t p, int n)
{
  if(n==0){
    p_polyf_creux_t q;
    q=creer_polynome(1);
    q->elements[0]->coeff=1;
    q->elements[0]->degre=0;
    return q;
  }
  if(n==1)
    return p;
  return multiplication_polynomes(p, puissance_polynome(p, n-1));
}

p_polyf_creux_t composition_polynome (p_polyf_creux_t p, p_polyf_creux_t q)
{
  p_polyf_creux_t new_p=creer_polynome(1);
  new_p->elements[0]->coeff=0;
  new_p->elements[0]->degre=0;

  for(int i=0;i<p->nb_degre;i++){   
    ecrire_polynome_float(new_p); 
    p_polyf_creux_t a_sup=puissance_polynome(q,i);
    a_sup=multiplication_polynome_scalaire(a_sup,p->elements[i]->coeff);
    new_p=addition_polynome(new_p,a_sup);
    detruire_polynome(a_sup);

  }
  return new_p;
}

