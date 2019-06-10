#include <stdio.h>
#include <stdlib.h>
////////////////////////////////////////
//Procedura Hipify z rekursja
////////////////////////////////////////
//Heapify przywraca porzadek kopcowy dla podanego i oraz jego synow.
//Jezeli zostanie dokonana zamiana to procedura wywoluje sie dla syna i dla ktorego zostala dokonana zamiana
/*
void Heapify(int *A,int i, int heapSize)
{
    int largest;
    int Lewy_syn = 2*i+1;
    int Prawy_syn = 2*i+2;
    if((Lewy_syn<=heapSize)&&(A[Lewy_syn]>A[i]))
        largest=Lewy_syn;
    else
        largest=i;
    if((Prawy_syn<=heapSize)&&(A[Prawy_syn]>A[largest]))
        largest=Prawy_syn;
    if(largest!=i)
    {
        int tmp=A[i];
        A[i]=A[largest];
        A[largest]=tmp;
        Heapify(A,largest, heapSize);
    }
}
*/
////////////////////////////////////////
//Iteracyjna wersja procedury Hipify
void Heapify(int *A,int i, int heapSize)
{
    int F;
    int largest;
    do
    {
    F=0;
    int Lewy_syn = 2*i+1;
    int Prawy_syn = 2*i+2;
    if((Lewy_syn<=heapSize)&&(A[Lewy_syn]>A[i]))
        largest=Lewy_syn;
    else
        largest=i;
    if((Prawy_syn<=heapSize)&&(A[Prawy_syn]>A[largest]))
        largest=Prawy_syn;
    if(largest!=i)
    {
        F=1;
        int tmp=A[i];
        A[i]=A[largest];
        A[largest]=tmp;
        i=largest;
    }
    }while(F>0);
}
////////////////////////////////////////
//Procedura, ktora buduje kopiec z otrzymanej tablicy.
//Zaczyna od ojca ostatniego elementu tablicy do korzenia
void BuildHeap(int *A,int heapSize)
{
    for(int i=(heapSize-1)/2;i>=0;i--)
    {
    Heapify(A,i,heapSize);
    }
}
////////////////////////////////////////
//Glowna procedura sortujaca.
void HeapSort(int *A, int heapSize)
{
    BuildHeap(A,heapSize); //stworzenie kopca
    for(int i=heapSize;i>=1;i--)
    {
        //zamiana ostatniego elementu kopca z pierwszym
        int tmp=A[0];
        A[0]=A[i];
        A[i]=tmp; //na i-tym elemencie zostaje aktualnie najwyzsza wartosc z kopca
        //zmniejszenie rozmiaru kopca i przywrocenie porzadku kopca
        heapSize=heapSize-1;
        Heapify(A,0,heapSize);
    }
}
////////////////////////////////////////

////////////////////////////////////////
int main()
{
    int zmienna;
    int licznik=0;
    FILE *fp;
    FILE *fp2;
    //nazwa pliku wejsciowego
    char nazwaPlikuWejsciowego[]="przyklad.txt";
    //nazwa pliku wyjsciowego
    char nazwaPlikuWyjsciowego[]="przyklad2.txt";
    if((fp=fopen(nazwaPlikuWejsciowego,"r"))==NULL)
    {
            printf("Nie moglem otworzyc pliku\n");
            exit(1);
    }
    //Petla zliczajaca ilosc liczb w pliku wejsciowym, zeby mozna bylo alokowac pamiec dla odpowiedniej tablicy
    while(feof(fp)==0)
    {
    fscanf(fp,"%i",&zmienna);
    licznik++;
    }

//alokuje pamiec na tablice dla liczb z pliku
int rozmiarTablicy=licznik;
rewind(fp);
int *tab = (int*) malloc(rozmiarTablicy * sizeof(*tab));
for(int i=0;i<rozmiarTablicy;i++)
    fscanf(fp,"%i",&tab[i]);
fclose(fp);


//sortowanie przez kopcowanie na stworzonej wczesniej tablicy
HeapSort(tab,rozmiarTablicy-1);//przekazujemy rozmiarTablic - 1 bo indeksowanie jest od 0

//wypisanie posortowanej tablicy do pliku
    if((fp2=fopen(nazwaPlikuWyjsciowego,"w"))==NULL)
    {
            printf("Nie moglem otworzyc pliku\n");
            exit(1);
    }
for(int i=0;i<rozmiarTablicy;i++)
    fprintf(fp2,"%i\n",tab[i]);
printf("W pliku %s znajduje sie posortowany kopcowo zestaw liczb",nazwaPlikuWyjsciowego);
}
