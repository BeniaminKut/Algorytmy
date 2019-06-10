#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct dwa_pola{
int liczba;
char *slowo;
} dwa_pola;

int zamiana(char *slowo)
{
    int do_zwrocenia;
    int dlugosc;
    dlugosc = strlen(slowo);
    if(dlugosc<2)
    {
        return 111*(int)slowo[0];
    }
    do_zwrocenia=(111*(int)slowo[0]+(int)slowo[1]);
    for(int i=2;i<dlugosc;i++)
    {
        do_zwrocenia=do_zwrocenia*111 + (int)slowo[i];
    }
    if(do_zwrocenia<0)
    return do_zwrocenia*(-1);
    else return do_zwrocenia;
}

void haszuj(dwa_pola *T,int m,dwa_pola *do_schaszowania,int ile_wyrazow)
{
    int j=0;
    int x=0;
    //adresowanie otwarte kwadratowe
    //h(k,j)=(h(k)+i^2)mod m
        for(int i=0;i<ile_wyrazow;i++)
        {
            j=0;
           while(1)
           {
               x=pow(j,2);
               if(T[(zamiana(do_schaszowania[i].slowo)+x)%m].slowo==NULL||T[(zamiana(do_schaszowania[i].slowo)+x)%m].slowo=="DEL")
               {
                   T[(zamiana(do_schaszowania[i].slowo)+x)%m].slowo=do_schaszowania[i].slowo;
                   T[(zamiana(do_schaszowania[i].slowo)+x)%m].liczba=do_schaszowania[i].liczba;
                   break;
               }
               else
                j++;
           }
        }
}

void USUN(char *slowo, dwa_pola *T,int m)
{
    int tmp=zamiana(&slowo);
    dwa_pola tmp1;
    int i=0;
    int x=0;
    printf("%s\n",slowo);
    while(1)
    {

        x=pow(i,2);
        if(strcmp(T[(tmp+x)%m].slowo,slowo)==0)
        {
            printf("%s\n",slowo);
            T[(tmp+x)%m].slowo="nienowak";
            break;
        }
        else i++;
    }
}
int main()
{
    int licznik=0;
    //
    FILE *plik;
    int liczba;
    char nazwisko[50];
    //nazwa pliku wejsciowego
    char nazwaPliku[]="Nazwiska.txt";
    if((plik=fopen(nazwaPliku,"r"))==NULL)
    {
            printf("Nie moglem otworzyc pliku\n");
            exit(1);
    }
    dwa_pola tablica_do_haszowania[20000];
    while(feof(plik)==0)
    {
        fscanf(plik,"%i",&tablica_do_haszowania[licznik].liczba);
        tablica_do_haszowania[licznik].slowo=(char*) malloc(50*sizeof(char));
        fscanf(plik,"%s",tablica_do_haszowania[licznik].slowo);

        licznik++;
    }

    dwa_pola tablica_haszowan[20000];

    //wypelnienie tablicy do 80%
    haszuj(tablica_haszowan,443,tablica_do_haszowania,300);

    // USUN("Nowak",tablica_haszowan,17);
     int xyz=0;
    for(int i=0;i<443;i++)
    {
        printf("%i: %i %s\n",i,tablica_haszowan[i].liczba,tablica_haszowan[i].slowo);
    }




    return 0;
}
