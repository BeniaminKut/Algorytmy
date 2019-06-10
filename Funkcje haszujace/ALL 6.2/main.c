#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int zamiana(char** slowo)
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
void haszuj(int *T,int m,char **wyrazy,int ile_wyrazow)
{
        for(int i=0;i<m;i++)
        {
            T[i]=0;
        }
        for(int i=0;i<ile_wyrazow;i++)
        {
           T[zamiana(wyrazy[i])%m]++;
           //printf("%i\n",zamiana((wyrazy[i]))%m);
        }
        int max=0;
        int ile_zer=0;
        int srednia=0;
        for(int i=0;i<m;i++)
        {
            if(T[i]>max) max=T[i];
            if(T[i]==0) ile_zer++;
            else srednia+=T[i];
        }
        printf("Wartosci dla M = %i\n",m);
        printf("Ilosc zerowych pozycji w tablic T: %i\n",ile_zer);
        printf("Maksymalna wartosc w T: %i\n",max);
        printf("Srednia wartosc pozycji niezerowych: %f\n\n",(double)srednia/(m-ile_zer));
}

int main()
{
    FILE *plik;
    char nazwaPliku[]="3700.txt";
    if((plik=fopen(nazwaPliku,"r"))==NULL)
    {
            printf("Nie moglem otworzyc pliku\n");
            exit(1);
    }
        int *T = (int) malloc(3800* sizeof(int));
        char **wyrazy = (char**) malloc(3800* sizeof(char**));
        int licznik=0;
        char wyraz[100];
        while(feof(plik)==0)
        {
            wyrazy[licznik]=(char*) malloc(100*sizeof(char));
            fscanf(plik,"%s",wyrazy[licznik]);
            licznik++;
        }
printf("\n\nLicznik:%i\n\n",licznik);
    haszuj(T,2027,wyrazy,licznik);
    haszuj(T,2048,wyrazy,licznik);
    haszuj(T,1531,wyrazy,3200);
    haszuj(T,1536,wyrazy,3200);
    haszuj(T,1019,wyrazy,2024);
    haszuj(T,1024,wyrazy,2024);





fclose(plik);
return 0;
}
