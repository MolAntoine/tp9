#include "file.h" 


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
  ptrF->Tete=-1;
  ptrF -> Queue=-1;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
  if (ptrF->Tete==ptrF->Queue) return 0;
  else if (ptrF->Tete==MAX-1) {
      initFile(ptrF);
      return 0;
      }
      else {
        ptrF->Tete++;
        return 1;
      }
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
  int i;
  if (ptrF->Queue==MAX-1 && ptrF->Tete>-1) {
    for(i=ptrF->Tete;i<MAX;i++) {
      ptrF->Elts[i-ptrF->Tete]=ptrF->Elts[i];
    }
  ptrF->Queue=(ptrF->Queue-ptrF->Tete);
  ptrF->Tete=-1;
  ptrF->Elts[ptrF->Queue]=*ptrE;
  return 1;
  }
  else 
  {
    if (ptrF->Queue==MAX-1) return 0;
      else {
        ptrF->Queue++;
        ptrF->Elts[ptrF->Queue]=*ptrE;
        return 1;
      }
  }
} 



int fileVide(const  T_File *ptrF) // qd Tete == 0 
{
  if (ptrF->Tete==ptrF->Queue)
    return 1;
  else 
    return 0;
}


int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
  if(ptrF->Tete==-1 && ptrF->Queue==MAX-1)
    return 1;
  else
    return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
  T_Elt value=ptrF->Elts[ptrF->Tete];
return value;
}

void afficherFile(T_File *ptrF)
{
  int i;
  for(i=ptrF->Tete+1;i<=ptrF->Queue;i++) {
    afficherElt(&(ptrF->Elts[i]));
  }
}




int testFile(T_File *F,T_Elt *ptrE)
{
int i;

initFile(F);
printf("file initialisée\n");

if(fileVide(F)==1){
printf("file vide\n");}
else printf("file pas vide\n");


if(filePleine(F)==1){
printf("file pleine\n");}
else printf("file pas pleine\n");

for(i=0;i<MAX+1;i++) {
  if(ajouter(F,ptrE)==1){
    
  printf("file empilée\n");
  
  }
  else printf("file pas empilée\n");
}
afficherFile(F);

if(fileVide(F)==1){
printf("file vide\n");}
else printf("file pas vide\n");

if(filePleine(F)==1){
printf("file pleine\n");}
else printf("file pas pleine\n");

for(i=0;i<MAX;i++) {
  if(retirer(F,ptrE)==1){
  printf("file depilée\n");
  }
  else printf("file pas depilée\n");
}

if(fileVide(F)==1){
printf("file vide\n");}
else printf("file pas vide\n");

if(filePleine(F)==1){
printf("file pleine\n");}
else printf("file pas pleine\n");

return 1;
}




/* typedef struct  
{
T_Elt Elts[MAX];  // stockage d'éléments de la case 0 à la case MAX-1
int Tete;
int Queue; 
} T_File; */