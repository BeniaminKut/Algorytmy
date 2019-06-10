#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int zmienna;
    srand(time(NULL));
   FILE *fp;
   if((fp=fopen("przyklad.txt","w")==NULL))
   {
       printf("Nie moglem otworzyc pliku/n");
        exit(1);
   }
for(int i=0;i<100;i++)
    fprintf(fp,"%i\n",rand()%10);
   fclose(fp);
}
