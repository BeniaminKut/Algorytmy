#include <stdio.h>
#include <stdlib.h>


void counting_sort(char **A,char **Pomocnicza,int *dlugosci,int pozycja,int ilosc)
{
    int *dlugosc_pomocnicza = (int*) malloc(ilosc * sizeof(*dlugosc_pomocnicza));

    for(int i=0;i<ilosc;i++)
    {
        dlugosc_pomocnicza[i]=dlugosci[i];
    }
    for(int i=0;i<ilosc;i++)
    {
        Pomocnicza[i]=A[i];
    }
    int tablica_zliczajaca[27];
    for(int i=0;i<27;i++)
    {
        tablica_zliczajaca[i]=0;
    }
    for(int i=0;i<ilosc;i++)
    {
        if(dlugosci[i]-1<pozycja)
            tablica_zliczajaca[0]++;
        else
            tablica_zliczajaca[(int)A[i][pozycja]-96]++;
    }
    for(int i=1;i<27;i++)
    {
        tablica_zliczajaca[i]+=tablica_zliczajaca[i-1];
    }
    for(int i=ilosc-1;i>=0;i--)
    {
        if(dlugosc_pomocnicza[i]-1<pozycja)
        {
            tablica_zliczajaca[0]--;
            A[tablica_zliczajaca[0]]=Pomocnicza[i];
            dlugosci[tablica_zliczajaca[0]]=dlugosc_pomocnicza[i];
        }
        else
        {
        tablica_zliczajaca[(int)Pomocnicza[i][pozycja]-96]--;
        A[tablica_zliczajaca[(int)Pomocnicza[i][pozycja]-96]]=Pomocnicza[i];
        dlugosci[tablica_zliczajaca[(int)Pomocnicza[i][pozycja]-96]]=dlugosc_pomocnicza[i];
        }

    }


}
void Radix_sort(char **A,char **Pomocnicza,int *dlugosci,int ilosc)
{
    int max_index=0;
    for(int i=0;i<ilosc;i++)
        if(dlugosci[i]>max_index) max_index=i;

    for(int i=max_index-1;i>=0;i--)
    {
        counting_sort(A,Pomocnicza,dlugosci,i,ilosc);
    }
}
int main()
{

    int licznik=0;
    //
    FILE *plik;
    char nazwisko[50];
    //nazwa pliku wejsciowego
    char nazwaPliku[]="Nazwiska2.txt";
    if((plik=fopen(nazwaPliku,"r"))==NULL)
    {
            printf("Nie moglem otworzyc pliku\n");
            exit(1);
    }
    while(feof(plik)==0)
    {
        fscanf(plik,"%s",nazwisko);
        licznik++;
    }
    char **pomocnicza = (char**) malloc(licznik * sizeof(char**));
    char **nazwiska = (char**) malloc(licznik * sizeof(char**));
    int *dlugosc_nazwisk = (int*) malloc(licznik * sizeof(*dlugosc_nazwisk));
    rewind(plik);
    int j=0;
    for(int i=0;i<licznik;i++)
    {
        pomocnicza[i]=(char*) malloc(50*sizeof(char));
        nazwiska[i]=(char*) malloc(50 * sizeof(char));
        fscanf(plik,"%s",nazwiska[i]);
        j=0;
        while(nazwiska[i][j]!=NULL)
        {
            dlugosc_nazwisk[i]=j;
            j++;
        }
        dlugosc_nazwisk[i]++;
    }


    Radix_sort(nazwiska,pomocnicza,dlugosc_nazwisk,licznik);
                FILE *plik2;
        plik2=fopen("posort.txt","w");
        for(int i=0;i<licznik;i++)
    {
        fprintf(plik2,"%s\n",nazwiska[i]);
    }
    //sprawdzenie
    for(int i=0;i<licznik;i++)
    {
        printf("%i: %s\n",i+1,nazwiska[i]);
    }
        printf("Licznik: %i\n",licznik);





fclose(plik);}
fclose(plik2);








/*

     //Fragment ktory przekonwertowal plik
    FILE *fp;
    FILE *fp2;
    char zmienna[50];
    //nazwa pliku wejsciowego
    char nazwaPlikuWejsciowego[]="Nazwiska.txt";
    //nazwa pliku wyjsciowego
    char nazwaPlikuWyjsciowego[]="c.txt";
    if((fp=fopen(nazwaPlikuWejsciowego,"r"))==NULL)
    {
            printf("Nie moglem otworzyc pliku\n");
            exit(1);
    }
    if((fp2=fopen(nazwaPlikuWyjsciowego,"w"))==NULL)
    {
            printf("Nie moglem otworzyc pliku\n");
            exit(1);
    }
    while(feof(fp)==0)
    {
    fscanf(fp,"%s",zmienna);
    if((int)zmienna[0]>60)
    {
        if((int)zmienna[0]<97)
        {
            zmienna[0]+=32;
        }
    fprintf(fp2,"%s\n",zmienna);
    }

    }
            fclose(fp);
            fclose(fp2);


}

*/



