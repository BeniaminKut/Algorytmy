#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
char* slowo;
struct lista *poprzednik, *nastepnik;
} lista;

void WSTAW(char* slowo, lista **HEAD)
{
    if(*HEAD==NULL)
    {
        lista *WARTOWNIK = (lista *)malloc(sizeof(lista));
        WARTOWNIK->slowo=NULL;
        WARTOWNIK->nastepnik=WARTOWNIK;
        WARTOWNIK->poprzednik=WARTOWNIK;
        (*HEAD)=WARTOWNIK;
    }
    lista *tmp = (lista *)malloc(sizeof(lista));

     tmp->slowo=slowo;
     tmp->poprzednik=(*HEAD)->poprzednik;
     (*HEAD)->poprzednik->nastepnik=tmp;
     (*HEAD)->poprzednik=tmp;
     tmp->nastepnik=(*HEAD);
     (*HEAD)=tmp;



}
void DRUKUJ(lista **HEAD)
{
    lista *tmp=(*HEAD);
    while(tmp->slowo!=NULL)
    {
        printf("%s\n",tmp->slowo);
        tmp=tmp->nastepnik;
    }
}
char* SZUKAJ(char* slowo,lista **HEAD)
{
        lista *tmp=(*HEAD);
        char* do_zwrocenia=NULL;
    while(tmp->slowo!=NULL)
    {
        if(tmp->slowo==slowo)
        {
            do_zwrocenia=tmp->slowo;
            break;
        }
        tmp=tmp->nastepnik;
    }
    return do_zwrocenia;
}
void USUN(char* slowo,lista **HEAD)
{
        lista *tmp=(*HEAD);
    while(tmp->slowo!=NULL)
    {
        if(tmp->slowo==slowo)
        {
            tmp->poprzednik->nastepnik=tmp->nastepnik;
            tmp->nastepnik->poprzednik=tmp->poprzednik;
            if(tmp==(*HEAD))
            {
                (*HEAD)=(*HEAD)->nastepnik;
            }
            break;
        }
        tmp=tmp->nastepnik;
    }
}
void KASUJ(lista **HEAD)
{
    (*HEAD)=NULL;
        lista *WARTOWNIK = (lista *)malloc(sizeof(lista));
        WARTOWNIK->slowo=NULL;
        WARTOWNIK->nastepnik=WARTOWNIK;
        WARTOWNIK->poprzednik=WARTOWNIK;
        (*HEAD)=WARTOWNIK;
}
lista * BEZPOWTORZEN(lista **HEAD)
{
    lista *do_zwrocenia=NULL;
    lista *tmp=(*HEAD);
    tmp=tmp->poprzednik->poprzednik;
    if((*HEAD)->slowo==NULL||(*HEAD)==NULL) //sprawdzenie czy lista jest pusta, jesli tak zwracam pusta liste
    {
        lista *WARTOWNIK = (lista *)malloc(sizeof(lista));
        WARTOWNIK->slowo=NULL;
        WARTOWNIK->nastepnik=WARTOWNIK;
        WARTOWNIK->poprzednik=WARTOWNIK;
        do_zwrocenia=WARTOWNIK;
    }
    else//jesli nie jest pusta zwracam liste bez powtorzen
    {

    //kopiowanie listy
    while(tmp->slowo!=NULL)
    {
        WSTAW(tmp->slowo,&do_zwrocenia);
        tmp=tmp->poprzednik;
    }
    //usuwanie powtorzen
    tmp=do_zwrocenia;
    lista *tmp2=do_zwrocenia;

    while(tmp->slowo!=NULL)
    {
        tmp2=tmp->nastepnik;
        while(tmp2->slowo!=NULL)
        {
            if(tmp2->slowo==tmp->slowo)
            {
                USUN(tmp->slowo,&tmp2);
                continue;//omijam inkrementacje na wypadek gdyby byly powtarzajace sie oboko siebie
            }
            tmp2=tmp2->nastepnik;
        }
        tmp=tmp->nastepnik;
    }
    }
    return do_zwrocenia;
}
lista * SCAL(lista **HEAD,lista **HEAD2)
{
    lista *do_zwrocenia=NULL;
    lista *tmp;
        lista *WARTOWNIK3 = (lista *)malloc(sizeof(lista));
        WARTOWNIK3->slowo=NULL;
        WARTOWNIK3->nastepnik=WARTOWNIK3;
        WARTOWNIK3->poprzednik=WARTOWNIK3;
        do_zwrocenia=WARTOWNIK3;
    if((*HEAD)==NULL)
    {
        lista *WARTOWNIK = (lista *)malloc(sizeof(lista));
        WARTOWNIK->slowo=NULL;
        WARTOWNIK->nastepnik=WARTOWNIK;
        WARTOWNIK->poprzednik=WARTOWNIK;
        (*HEAD)=WARTOWNIK;
    }
    if((*HEAD2)==NULL)
    {
        lista *WARTOWNIK2 = (lista *)malloc(sizeof(lista));
        WARTOWNIK2->slowo=NULL;
        WARTOWNIK2->nastepnik=WARTOWNIK2;
        WARTOWNIK2->poprzednik=WARTOWNIK2;
        (*HEAD2)=WARTOWNIK2;
    }
    tmp=(*HEAD2)->poprzednik->poprzednik;
    while(tmp->slowo!=NULL)
    {
        WSTAW(tmp->slowo,&do_zwrocenia);
        tmp=tmp->poprzednik;
    }
    tmp=(*HEAD)->poprzednik->poprzednik;
    while(tmp->slowo!=NULL)
    {
        WSTAW(tmp->slowo,&do_zwrocenia);
        tmp=tmp->poprzednik;
    }
    KASUJ(HEAD);
    KASUJ(HEAD2);
    return do_zwrocenia;
}
int main()
{
lista *HEAD=NULL;
WSTAW("Banany", &HEAD);
WSTAW("Jablka", &HEAD);
WSTAW("Daktyle", &HEAD);
printf("Drukowanie wstawionych elementow:\n");
DRUKUJ(&HEAD);
printf("\nSzukanie slowa Banany: %s",SZUKAJ("Banany",&HEAD));
printf("\nSzukanie slowa Jablka: %s",SZUKAJ("Jablka",&HEAD));
printf("\nSzukanie slowa Daktyle: %s",SZUKAJ("Daktyle",&HEAD));
printf("\nSzukanie slowa Mango (nie ma go na liscie): %s\n\n",SZUKAJ("Mango",&HEAD));
WSTAW("Kiwi", &HEAD);
WSTAW("Gruszka", &HEAD);
WSTAW("Pomelo", &HEAD);
WSTAW("Brzoskwinia", &HEAD);
printf("Dodaje kilka elementow\n");
DRUKUJ(&HEAD);
printf("\nUsuwam pierwszy element\n");
USUN("Brzoskwinia",&HEAD);
DRUKUJ(&HEAD);
printf("\nUsuwam 2 elementy ze srodka\n");
USUN("Daktyle",&HEAD);
USUN("Kiwi",&HEAD);
DRUKUJ(&HEAD);
printf("\nUsuwam ostatni element\n");
USUN("Banany",&HEAD);
DRUKUJ(&HEAD);
printf("\nKasuje wszystkie elementy listy:\n");
KASUJ(&HEAD);
DRUKUJ(&HEAD);
printf("\nTworze liste z powtorzeniami:\n");
WSTAW("aaa", &HEAD);
WSTAW("aaa", &HEAD);
WSTAW("ccc", &HEAD);
WSTAW("ddd", &HEAD);
WSTAW("aaa", &HEAD);
WSTAW("bbb", &HEAD);
WSTAW("ccc", &HEAD);
WSTAW("ccc", &HEAD);
WSTAW("ccc", &HEAD);
WSTAW("bbb", &HEAD);
WSTAW("ccc", &HEAD);
WSTAW("ddd", &HEAD);
WSTAW("aaa", &HEAD);
WSTAW("bbb", &HEAD);
WSTAW("ccc", &HEAD);
WSTAW("ddd", &HEAD);
WSTAW("aaa", &HEAD);
WSTAW("bbb", &HEAD);
WSTAW("ddd", &HEAD);
WSTAW("ddd", &HEAD);
WSTAW("ddd", &HEAD);
DRUKUJ(&HEAD);
lista *zwrocona=BEZPOWTORZEN(&HEAD);
printf("\nLista bez powtorzen:\n");
DRUKUJ(&zwrocona);
//SCALANIE
printf("\nScalanie list:\n");
lista *L1=NULL;
lista *L2=NULL;
WSTAW("aaa",&L1);
WSTAW("bbb",&L1);
WSTAW("ccc",&L1);
WSTAW("ddd",&L1);
WSTAW("eee",&L1);
WSTAW("AAA",&L2);
WSTAW("BBB",&L2);
WSTAW("CCC",&L2);
WSTAW("DDD",&L2);
WSTAW("EEE",&L2);
printf("Lista 1 przed:\n");
DRUKUJ(&L1);
printf("Lista 2 przed:\n");
DRUKUJ(&L2);
lista *L3=SCAL(&L1,&L2);
printf("Lista 1 po:\n");
DRUKUJ(&L1);
printf("Lista 2 po:\n");
DRUKUJ(&L2);
printf("Lista scalona:\n");
DRUKUJ(&L3);
printf("\nProba scalenia pustych list: \n");
lista *L4=NULL;
lista *L5=NULL;
lista *L6=SCAL(&L4,&L5);
DRUKUJ(&L6);
printf("\nProba scalenia listy z elementami z pusta lista: \n");
WSTAW("Bulki",&L4);
WSTAW("Chleb",&L4);
WSTAW("Tosty",&L4);
L6=SCAL(&L4,&L5);
DRUKUJ(&L6);
return 0;
}
