#include <stdio.h>
#include <stdlib.h>

#include "poly.h"


int main (int argc, char **argv)
{
  p_polyf_t p1, p2, p3 ;
  
  if (argc != 3)
    {
      fprintf (stderr, "deux paramètres (polynomes,fichiers) sont à passer \n") ;
      exit (-1) ;
    }
      
  p1 = lire_polynome_float (argv [1]) ;
  p2 = lire_polynome_float (argv [2]) ;

  ecrire_polynome_float (p1) ;
  ecrire_polynome_float (p2) ;

  printf("sont-ils égaux ? %d \n", egalite_polynome(p1, p2));
  printf("résultat pour p1 avec x=2 ? %f \n", eval_polynome(p1, 2));

  p3 = composition_polynome(p1, p2);
  ecrire_polynome_float(p3);

  /*
    ajouter du code pour tester les fonctions
    sur les polynomes
  */
}
