#include <stdio.h>
#include <stdlib.h>

#include "poly_creux.h"

#include <x86intrin.h>
#include <math.h>
p_polyf_creux_t creer_polynome (int degre)
{
  
}

void detruire_polynome (p_polyf_creux_t p)
{
  

  return ;
}

void init_polynome (p_polyf_creux_t p, float x)
{
  register unsigned int i ;

  for (i = 0 ; i <= p->degre; ++i)
    p->coeff [i] = x ;

  return ;
}



p_polyf_creux_t lire_polynome_float (char *nom_fichier)
{
  FILE *f ;
  p_polyf_creux_t p ;
  int degre ;
  int i  ;
  int cr ;
  
  f = fopen (nom_fichier, "r") ;
  if (f == NULL)
    {
      fprintf (stderr, "erreur ouverture %s \n", nom_fichier) ;
      exit (-1) ;
    }
  
  cr = fscanf (f, "%d", &degre) ;
  if (cr != 1)
    {
      fprintf (stderr, "erreur lecture du degre\n") ;
      exit (-1) ;
    }
  p = creer_polynome (degre) ;
  
  for (i = 0 ; i <= degre; i++)
    { 
      cr = fscanf (f, "%f", &p->coeff[i]) ;
       if (cr != 1)
    {
      fprintf (stderr, "erreur lecture coefficient %d\n", i) ;
      exit (-1) ;
    }
       
    }

  fclose (f) ;

  return p ;
}

void ecrire_polynome_float (p_polyf_creux_t p)
{
  

  return ;
}

int egalite_polynome (p_polyf_creux_t p1, p_polyf_creux_t p2)
{
  
  return 0;
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

