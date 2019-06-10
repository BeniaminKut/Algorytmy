#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
printf("cos\n ");
clock_t start2=clock();
for(long int i=0;i<1000000;i++){
  for(long int j=0;j<1000;j++){

}
}
double czas6=((1000*(clock()-start2))/CLOCKS_PER_SEC);
printf("czas: %.3f ",czas6);
}
