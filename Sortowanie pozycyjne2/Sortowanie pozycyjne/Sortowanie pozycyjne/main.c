#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////////////////////////////////////
int porownanie_lancuchow(char *A, char *B)
{
    int i=0;
    while(A[i]!=NULL || B[i]!=NULL)
    {
        if((int)A[i]<(int)B[i]) return 1;
        if((int)A[i]>(int)B[i]) return 0;
        i++;
    }
    if(A[i]==NULL && B[i]==NULL) return 1;
    if(A[i]==NULL && B[i]!=NULL) return 1;
    else return 0;
}
///////////////////////////////////////////////
int Partition(int **A,int p, int r)
{
    char* x=A[r-1];   //element wyznaczajacy podzial
    int i=p-1;
    char* tmp;
    for(int j=p;j<r;j++)
    {
        //if(A[j]<=x)
        if(porownanie_lancuchow(A[j],x))
        {
            i++;
            tmp=A[j];
            A[j]=A[i];
            A[i]=tmp;
        }
    }
    if(i<r) return i;
    else return i-1;
}
void Quicksort(int **A,int p, int r)
{
    int q;
    if(p<r)
    {
        q=Partition(A,p,r);
        Quicksort(A,p,q);
        Quicksort(A,q+1,r);
    }


}


///////////////////////////////////////////////

void counting_sort(char **A,char **Pomocnicza,int *dlugosci,int pozycja,int ilosc)
{
    int *dlugosc_pomocnicza = (int*) malloc(ilosc * sizeof(*dlugosc_pomocnicza));

   /* for(int i=0;i<ilosc;i++)
    {
        dlugosc_pomocnicza[i]=dlugosci[i];
    }
    for(int i=0;i<ilosc;i++)
    {
        Pomocnicza[i]=A[i];
    }
    */
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
        if(dlugosci[i]-1<pozycja)
        {
            tablica_zliczajaca[0]--;
            Pomocnicza[tablica_zliczajaca[0]]=A[i];
            dlugosc_pomocnicza[tablica_zliczajaca[0]]=dlugosci[i];
        }
        else
        {
        tablica_zliczajaca[(int)A[i][pozycja]-96]--;
        Pomocnicza[tablica_zliczajaca[(int)A[i][pozycja]-96]]=A[i];
        dlugosc_pomocnicza[tablica_zliczajaca[(int)A[i][pozycja]-96]]=dlugosci[i];
        }

    }
for(int i=0;i<ilosc;i++)
{
    dlugosci[i]=dlugosc_pomocnicza[i];
    A[i]=Pomocnicza[i];
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
    char **nazwiska_dla_quicksort = (char**) malloc(licznik * sizeof(char**));
    int *dlugosc_nazwisk = (int*) malloc(licznik * sizeof(*dlugosc_nazwisk));
    rewind(plik);
    int j=0;
    for(int i=0;i<licznik;i++)
    {
        pomocnicza[i]=(char*) malloc(50*sizeof(char));
        nazwiska[i]=(char*) malloc(50 * sizeof(char));
        nazwiska_dla_quicksort[i]=(char*) malloc(50 * sizeof(char));
        fscanf(plik,"%s",nazwiska[i]);
        j=0;
        while(nazwiska[i][j]!=NULL)
        {
            dlugosc_nazwisk[i]=j;
            j++;
        }
        dlugosc_nazwisk[i]++;
        nazwiska_dla_quicksort[i]=nazwiska[i];
    }


    clock_t start;
    double czas1,czas2,czas3,czas4;


    start=clock();
    Quicksort(nazwiska_dla_quicksort,0,licznik);
    czas1=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
                    FILE *plik2;
        plik2=fopen("posortowaneQuicksortem.txt","w");
        for(int i=0;i<licznik;i++)
    {
        fprintf(plik2,"%s\n",nazwiska_dla_quicksort[i]);
    }


    start=clock();
    Radix_sort(nazwiska,pomocnicza,dlugosc_nazwisk,licznik);
    czas2=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
                FILE *plik3;
        plik3=fopen("posortowaneRadixSortem.txt","w");
        for(int i=0;i<licznik;i++)
    {
        fprintf(plik3,"%s\n",nazwiska[i]);
    }
    printf("Czas wykonania Quicksort: %f\n",czas1);
printf("Czas wykonania RadixSort: %f\n",czas2);



//DLA JEDNAKOWEJ DLUGOSCI
  srand(time(NULL));
int x=200000;
      char **dla_jednakowej_dlugosci_1 = (char**) malloc(x * sizeof(char**));
      char **dla_jednakowej_dlugosci_2 = (char**) malloc(x * sizeof(char**));
      char **dla_jednakowej_dlugosci_3 = (char**) malloc(x * sizeof(char**));
for(int i = 0; i<x;i++)
  {
      dla_jednakowej_dlugosci_1[i]=(char*) malloc(3*sizeof(char));
      dla_jednakowej_dlugosci_2[i]=(char*) malloc(3*sizeof(char));
      dla_jednakowej_dlugosci_3[i]=(char*) malloc(3*sizeof(char));
      for(int j=0;j<3;j++)
      {
          dla_jednakowej_dlugosci_1[i][j]=(char)((rand()%26)+97);
          dla_jednakowej_dlugosci_2[i][j]=dla_jednakowej_dlugosci_1[i][j];
      }
  }
      start=clock();
    Quicksort(dla_jednakowej_dlugosci_1,0,x);
    czas3=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
                    FILE *plik4;
        plik4=fopen("posortowaneQuicksortemTeSamejDlugosci.txt","w");
        for(int i=0;i<x;i++)
    {
        fprintf(plik4,"%s\n",dla_jednakowej_dlugosci_1[i]);
    }

    int dlugosc_niepotrzebna[200000];
    for(int i=0;i<x;i++)
        dlugosc_niepotrzebna[i]=3;
    start=clock();
    Radix_sort(dla_jednakowej_dlugosci_2,dla_jednakowej_dlugosci_3,dlugosc_niepotrzebna,x);
    czas4=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
                FILE *plik5;
        plik5=fopen("posortowaneRadixSortemTeSamejDlugosci.txt","w");
        for(int i=0;i<x;i++)
    {
        fprintf(plik5,"%s\n",dla_jednakowej_dlugosci_2[i]);
    }


printf("Czas wykonania Quicksort dla tej samej dlugosci: %f\n",czas3);
printf("Czas wykonania RadixSort dla tej samej dlugosci: %f\n",czas4);
fclose(plik);
fclose(plik2);
fclose(plik3);
fclose(plik4);
fclose(plik5);
}


