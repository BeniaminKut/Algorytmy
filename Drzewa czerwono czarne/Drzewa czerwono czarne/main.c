#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED 1        /* stala oznaczajaca kolor wezla */
#define BLACK 0      /* stala oznaczajaca kolor wezla */
#define SZER_EKR 180  /* szerokosc ekranu */
#define IL_POZ   7   /* ilosc poziomow drzewa, ktore beda wydrukowane   */



typedef struct drzewko{
int klucz;
int kolor;
struct drzewko *lewy, *prawy, *tatus;
} drzewko;
/////////////////////////////////////
void Left_rotate(drzewko **x)
{
    drzewko *tmp = (drzewko *)malloc(sizeof(drzewko));

    tmp=(*x)->prawy;
    if(tmp->lewy->klucz!=NULL){
    (*x)->prawy=tmp->lewy;
    tmp->lewy->tatus=(*x);
    }
    else
    {
    (*x)->prawy=tmp->lewy;
    }
    tmp->tatus=(*x)->tatus;


if((*x)->tatus->klucz!=NULL){
    if((*x)->tatus->lewy==(*x))
    {
        (*x)->tatus->lewy=tmp;
    }
    else
    {
        (*x)->tatus->prawy=tmp;
    }
}
    (*x)->tatus=tmp;
    tmp->lewy=(*x);
    (*x)=tmp;
}
/////////////////////////////////////
void Right_rotate(drzewko **x)
{
    drzewko *tmp = (drzewko *)malloc(sizeof(drzewko));

    tmp=(*x)->lewy;
    if(tmp->prawy->klucz!=NULL){
    (*x)->lewy=tmp->prawy;
    tmp->prawy->tatus=(*x);
    }
    else
    {
        (*x)->lewy=tmp->prawy;
    }
    tmp->tatus=(*x)->tatus;
if((*x)->tatus->klucz!=NULL){
    if((*x)->tatus->lewy==(*x))
    {
        (*x)->tatus->lewy=tmp;
    }
    else
    {
        (*x)->tatus->prawy=tmp;
    }
}
    (*x)->tatus=tmp;
    tmp->prawy=(*x);
    (*x)=tmp;
}
/////////////////////////////////////
void WSTAW(int klucz, drzewko **ROOT)
{
    ////////CZESC DLA DRZEW POSZUKIWAN BINARNYCH/////////
    if(*ROOT==NULL)
    {
        drzewko *WARTOWNIK = (drzewko *)malloc(sizeof(drzewko));
        WARTOWNIK->klucz=NULL;
        WARTOWNIK->lewy=WARTOWNIK;
        WARTOWNIK->prawy=WARTOWNIK;
        WARTOWNIK->tatus=WARTOWNIK;
        WARTOWNIK->kolor=BLACK;
        (*ROOT)=WARTOWNIK;
    }
    drzewko *tmp = (drzewko *)malloc(sizeof(drzewko));

     tmp->klucz=klucz;
     tmp->lewy=(*ROOT)->tatus;
     tmp->prawy=(*ROOT)->tatus;
     tmp->tatus=(*ROOT)->tatus;
     tmp->kolor=RED;

     drzewko *x = (drzewko *)malloc(sizeof(drzewko));
     drzewko *y = (drzewko *)malloc(sizeof(drzewko));
     x=(*ROOT);
     y=(*ROOT)->tatus;
     while(x!=(*ROOT)->tatus)
     {
         y=x;
         if(tmp->klucz<x->klucz)
         {
             x=x->lewy;
         }
         else
         {
             x=x->prawy;
         }
     }
     tmp->tatus=y;
     if(y==(*ROOT)->tatus)
     {
         (*ROOT)=tmp;
     }
     else if(tmp->klucz<y->klucz)
     {
         y->lewy=tmp;
     }
     else
     {
         y->prawy=tmp;
     }
     (*ROOT)->kolor=BLACK;
     //////////TERAZ CZESC DLA DRZEW CZERWONO CZARNYCH///////
     while((tmp!=(*ROOT))&&(tmp->tatus->kolor==RED))
     {
         if(tmp->tatus==tmp->tatus->tatus->lewy)
         {
             y=tmp->tatus->tatus->prawy;
             if(y->kolor==RED) //PRZYPADEK 1
             {
                 tmp->tatus->kolor=BLACK;
                 y->kolor=BLACK;
                 tmp->tatus->tatus->kolor=RED;
                 tmp=tmp->tatus->tatus;
                 continue;
             }
             else if(tmp==tmp->tatus->prawy) //PRZYPADEK 2
             {
                 tmp=tmp->tatus;
                 Left_rotate(&tmp);
                 tmp=tmp->lewy;
             }
             tmp->tatus->kolor=BLACK; //PRZYPADEK 3
             tmp->tatus->tatus->kolor=RED;
             x=tmp;
             tmp=tmp->tatus->tatus;
             Right_rotate(&tmp);
             tmp=x;
         }
         else
         {
             y=tmp->tatus->tatus->lewy;
             if(y->kolor==RED) //PRZYPADEK 1
             {
                 tmp->tatus->kolor=BLACK;
                 y->kolor=BLACK;
                 tmp->tatus->tatus->kolor=RED;
                 tmp=tmp->tatus->tatus;
                 continue;
             }
             else if(tmp==tmp->tatus->lewy) //PRZYPADEK 2
             {
                 tmp=tmp->tatus;
                 Right_rotate(&tmp);
                 tmp=tmp->prawy;
             }
             tmp->tatus->kolor=BLACK; //PRZYPADEK 3
             tmp->tatus->tatus->kolor=RED;
             x=tmp;
             tmp=tmp->tatus->tatus;
             Left_rotate(&tmp);
             tmp=x;
         }
         (*ROOT)->kolor=BLACK;
     }
}
///////////////////////////////////////
///////////////////////////////////////
char wydruk[IL_POZ+1][SZER_EKR];

void drukujost(drzewko **w, int l, int p,int poziom){
       int srodek = (l+p)/2;
       if ((*w)->klucz==NULL)   return;
       wydruk[poziom][srodek]='*';
}

void drukujwew(drzewko *w, int l, int p,int poziom){
       int srodek = (l+p)/2;
       int i,dl;
       char s[19];
       if (w->klucz==NULL)    return;
       if (w->kolor==BLACK)
         dl=sprintf(s,"%d",w->klucz);
       else

       dl=sprintf(s,"%+d",w->klucz);
       for (i=0;i<dl;i++)
         wydruk[poziom][srodek-dl/2+i]=s[i];
       if (++poziom<IL_POZ){
         drukujwew(w->lewy,l,srodek,poziom) ;
         drukujwew(w->prawy,srodek+1,p,poziom) ;
       }
       else {
         drukujost(w->lewy,l,srodek,poziom) ;
         drukujost(w->prawy,srodek+1,p,poziom) ;
       }
}

void drukuj(drzewko **w){
  int j,i;
  for (i=0;i<=IL_POZ;i++)
    for (j=0;j<SZER_EKR;j++)
      wydruk[i][j] = ' ';
  drukujwew((*w),0,SZER_EKR,0);
  for (i=0;i<=IL_POZ;i++){
      for (j=0;j<SZER_EKR;j++)
        putchar(wydruk[i][j]);
      printf("\n");
  }
}
///////////////////////////////////////
///////////////////////////////////////


int main()
{
drzewko *ROOT=NULL;
WSTAW(38,&ROOT);
WSTAW(31,&ROOT);
WSTAW(22,&ROOT);
//WSTAW(8,&ROOT);
//WSTAW(20,&ROOT);
//WSTAW(5,&ROOT);
//WSTAW(10,&ROOT);
//WSTAW(9,&ROOT);
//WSTAW(21,&ROOT);
//WSTAW(27,&ROOT);
//WSTAW(29,&ROOT);
//WSTAW(25,&ROOT);
//WSTAW(28,&ROOT);
drukuj(&ROOT);
printf("///////////   %i     ///////////\n",ROOT->klucz);
//Left_rotate(&ROOT);
//drukuj(&ROOT);
return 0;
}
