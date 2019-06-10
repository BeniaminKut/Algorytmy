#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insert_sort(int *A[],int p, int n)
{
    int tmp;
    int j;
    for(int i=p+1;i<n;i++)
    {
        tmp=A[i];
        j=i-1;
        while((j>=p)&&(A[j]>tmp))
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=tmp;
    }
}
////////////////////////////////
int Partition(int *A[],int p, int r)
{
    int x=A[r-1];   //element wyznaczajacy podzial
    int i=p-1;
    int tmp;
    for(int j=p;j<r;j++)
    {
        if(A[j]<=x)
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
void Quicksort(int *A[],int p, int r)
{
    int q;
    if(p<r)
    {
        q=Partition(A,p,r);
        Quicksort(A,p,q);
        Quicksort(A,q+1,r);
    }


}
/////////////////////////////////
void Quicksort_z_wstawianiem(int *A[],int p, int r, int c)
{
    int q;
    if(p<r-c)
    {
        q=Partition(A,p,r);
        Quicksort_z_wstawianiem(A,p,q,c);
        Quicksort_z_wstawianiem(A,q+1,r,c);
    }
    else
        insert_sort(A,p,r);



}
/////////////////////////////////
void wypelnij_tablice_losowo(int *A[],int rozmiar)
{
    for(int i=0;i<rozmiar;i++)
    {
        A[i]=rand()%30000;
    }
}
void wypelnij_tablice_malejaco(int *A[],int rozmiar)
{
    for(int i=rozmiar-1;i>=0;i--)
    {
        A[i]=i;
    }
}
void kopia_tablicy(int *A[],int *B[],int rozmiar)
{
    for(int i=0;i<rozmiar;i++)
        B[i]=A[i];
}
int main()
{
srand(time(NULL));
int x=20;//liczba losowan do usredniania wyniku
int rozmiarTablicy=200000;
int *tab = malloc(sizeof(tab)*rozmiarTablicy);
int *tab2 = malloc(sizeof(tab2)*rozmiarTablicy);
if(0==0)//sprawdzenie czy algorytmy dzialaja
{
//sprawdzenie dzialania algorytmu podstawowego
wypelnij_tablice_losowo(tab,100);
printf("Sprawdzenie dzialania algorytmu podstawowego\n");
printf("Tablica przed\n");
for(int i=0;i<100;i++)
    printf("%i: %i\n",i,tab[i]);
printf("Tablica po\n");
Quicksort(tab,0,100);
for(int i=0;i<100;i++)
    printf("%i: %i\   \n",i,tab[i]);
wypelnij_tablice_losowo(tab,100);
printf("Sprawdzenie dzialania algorytmu quicksort ze wstawianiem\n");
printf("Tablica przed\n");
for(int i=0;i<100;i++)
    printf("%i: %i   \n",i,tab[i]);
printf("Tablica po\n");
Quicksort_z_wstawianiem(tab,0,100,10);
for(int i=0;i<100;i++)
    printf("%i: %i\n",i,tab[i]);
}
if(0==0)//wyswietla wyniki czasowe algorytmow
    {
printf("\nDane losowe\n");
printf("  Rozmiar  |        Quicksort      |  Quicksort z wstawianiem  |  Quicksort z wstawianiem   |  Quicksort z wstawianiem   |  Quicksort z wstawianiem   |\n");
printf("  tablicy  |   (srednia z %3i)     |     (srednia z %3i)   c=5 |    (srednia z %3i)    c=10 |    (srednia z %3i)    c=15 |    (srednia z %3i)    c=20 |\n",x,x,x,x,x);
double czas1,czas2,czas3,czas4,czas5;
clock_t start;

for(int i=10000;i<=rozmiarTablicy;i=i+10000)
{
czas1=0;
czas2=0;
czas3=0;
czas4=0;
czas5=0;
int j=0;
while(j<x)
{
wypelnij_tablice_losowo(tab,i);
kopia_tablicy(tab,tab2,i);
start=clock();
Quicksort(tab2,0,i);
czas1+=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
kopia_tablicy(tab,tab2,i);
start=clock();
Quicksort_z_wstawianiem(tab2,0,i,5);
czas2+=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
kopia_tablicy(tab,tab2,i);
start=clock();
Quicksort_z_wstawianiem(tab2,0,i,10);
czas3+=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
kopia_tablicy(tab,tab2,i);
start=clock();
Quicksort_z_wstawianiem(tab2,0,i,15);
czas4+=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
kopia_tablicy(tab,tab2,i);
start=clock();
Quicksort_z_wstawianiem(tab2,0,i,20);
czas5+=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
j++;
}
printf("-----------|-----------------------|---------------------------|----------------------------|----------------------------|----------------------------|\n");
printf("%6i     |      %7.3f ms       |      %7.3f ms           |          %7.3f ms        |           %7.3f ms       |          %7.3f ms        |\n",i,czas1/x,czas2/x,czas3/x,czas4/x,czas5/x);
printf("-----------|-----------------------|---------------------------|----------------------------|----------------------------|----------------------------|\n");

}

  free(tab);
  free (tab2);
/////////////
printf("\nDane niekorzystne\n");
printf("Ze wzgledu na niekorzystne dane, przeskoki ilosci danych sa mniejsze\n");
printf("  Rozmiar  |        Quicksort      |Quicksort z wstawianiem c=5|Quicksort z wstawianiem c=10|Quicksort z wstawianiem c=15|Quicksort z wstawianiem c=20|\n");
rozmiarTablicy=20000;
int *tab3 = malloc(sizeof(tab3)*rozmiarTablicy);
for(int i=1000;i<=rozmiarTablicy;i=i+1000)
{
czas1=0;
czas2=0;
czas3=0;
czas4=0;
czas5=0;
wypelnij_tablice_malejaco(tab3,i);
start=clock();
Quicksort(tab3,0,i);
czas1=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
wypelnij_tablice_malejaco(tab3,i);
start=clock();
Quicksort_z_wstawianiem(tab3,0,i,5);
czas2=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
wypelnij_tablice_malejaco(tab3,i);
start=clock();
Quicksort_z_wstawianiem(tab3,0,i,10);
czas3=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
wypelnij_tablice_malejaco(tab3,i);
start=clock();
Quicksort_z_wstawianiem(tab3,0,i,15);
czas4=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
wypelnij_tablice_malejaco(tab3,i);
start=clock();
Quicksort_z_wstawianiem(tab3,0,i,20);
czas5=((double)(1000*(clock()-start))/CLOCKS_PER_SEC);
printf("-----------|-----------------------|---------------------------|----------------------------|----------------------------|----------------------------|\n");
printf("%6i     |      %8.3f ms      |      %8.3f ms          |          %8.3f ms       |           %8.3f ms      |          %8.3f ms       |\n",i,czas1,czas2,czas3,czas4,czas5);
printf("-----------|-----------------------|---------------------------|----------------------------|----------------------------|----------------------------|\n");

}
}

}
