#include "pile.h"



void initPile( T_Pile * P)
{
  P->nbElts=0;
}


int pilepleine(const  T_Pile *P)
{
if(P->nbElts==MAX){
return 1;
}
else return 0;
}



int pilevide(const  T_Pile *P)
{
  if(P->nbElts==0){
return 1;
  }
else return 0;
}



int empiler( T_Pile *P, T_Elt *e) //renvoie 0 si pile pleine, sinon 1
{
if(P->nbElts<MAX){
P->Elts[P->nbElts]=*e;
P->nbElts++;
return 1;
}
else return 0;
}



int depiler( T_Pile *P, T_Elt *pelt)  //renvoie 0 si pile vide, sinon 1
{
if(P->nbElts!=0){
P->nbElts--;
return 1;
}
else return 0;
}



T_Elt sommet(const  T_Pile *P)
{
  int i=P->nbElts;
T_Elt value= P->Elts[i-1];
return value;
}



int hauteur(const  T_Pile *P)
{
int value;
value=P->nbElts;
return value;
}


void afficherPile(T_Pile *P)
{
  int i;
  for(i=0;i<P->nbElts;i++) 
    afficherElt(&(P->Elts[i]));
}


int testPile(T_Pile *P,T_Elt *ptrE)
{
int i;

initPile(P);
printf("pile initialisée\n");


if(pilevide(P)==1){
printf("pile vide\n");}
else printf("pile pas vide\n");

if(pilepleine(P)==1){
printf("pile pleine\n");}
else printf("pile pas pleine\n");

for(i=0;i<MAX+1;i++) {
  if(empiler(P,ptrE)==1){
  printf("pile empilée\n");
  printf("hauteur: %d\n",hauteur(P));
  }
  else printf("pile pas empilée\n");
}
if(pilevide(P)==1){
printf("pile vide\n");}
else printf("pile pas vide\n");

printf("sommet : %d\n",sommet(P));
printf("hauteur: %d\n",hauteur(P));
afficherPile(P);


if(pilepleine(P)==1){
printf("pile pleine\n");}
else printf("pile pas pleine\n");

for(i=0;i<MAX;i++) {
  if(depiler(P,ptrE)==1){
  printf("pile depilée\n");
  }
  else printf("pile pas depilée\n");
}

if(pilevide(P)==1){
printf("pile vide\n");}
else printf("pile pas vide\n");

if(pilepleine(P)==1){
printf("pile pleine\n");}
else printf("pile pas pleine\n");



return 1;
}
