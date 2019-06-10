// struktura wezla B-drzewa i przyklad zapisu i odczytu na plik
// budowanie B-drzewa o zadanej wysokosci i drukowanie
// Uwaga: w odró¿nieniu od pseudokodu, tutaj tablice kluczy
// i "wskaŸników" do synów s¹ indeksowane od 0

#include <stdio.h>
#define T 3   // stopien B-drzewa

typedef struct{
  short n;        //ilosc kluczy (-1 oznacza wezel usuniety)
  short leaf;     // czy lisc
  int k[2*T-1];   // klucze (numerowane od pozyji 0)
  int c[2*T];     // "wskaŸniki" do synow (pozycje w pliku: 0,1,2 ...)
  //int info[2*T-1];  // "wskazniki" do informacji skojarzonej z kluczem
                    // (pozycje w innym pliku); tutaj nie beda uzyte
} Wezel;

int POZYCJA=0;
int rozmiarw = sizeof(Wezel); // rozmiar wezla w bajtach
FILE *drzewo;  // plik drzewa (zawierajacy wezly)

void zapisz(int i,Wezel *w){
  // zapisuje *w jako i-ty zapis w pliku drzewa
  fseek(drzewo,(long)i*rozmiarw,SEEK_SET);
  fwrite(w,rozmiarw,1,drzewo);
  //  printf("z%d ",i);
}

void odczytaj(int i,Wezel *w){
  // odczytuje i-ty zapis w pliku drzewa i wpisuje do *w
  fseek(drzewo,(long)i*rozmiarw,SEEK_SET);
  fread(w,rozmiarw,1,drzewo);
  //  printf("o%d ",i);
}

void usun(int i){
  // usuwa i-ty zapis w pliku drzewa
  // w tej wersji nie wykorzystujemy usunietych pozycji,
  // tylko zaznaczamy jako usuniete
  Wezel w;
  odczytaj(i,&w);
  w.n=-1;
  zapisz(i,&w);
}

int budujB(int g, int n){
  // buduje B-drzewo o wysokosci g, w kazdym wezle jest n kluczy
  // wynikiem jest pozycja korzenia w pliku - jest to ostatni
  // zapis w pliku, co jest wazne dla dalszych zapisow do pliku
  // ktore trzeba robic zaczynajac od kolejnej pozycji
  static int klucz=0; // kolejny klucz
  static int pozycja=0; // wolna pozycja w pliku
  Wezel w;
  w.n=n;
  int i;
  if (g==0){  // lisc
    for (i=0;i<n;i++){
      w.c[i]= -1; // w lisc
      w.k[i]= klucz++;
    }
    w.c[n]= -1;
    w.leaf=1;
  } else {  // wezel wewnetrzny
    for (i=0;i<n;i++){
      w.c[i]= budujB(g-1,n);
      w.k[i]= klucz++;
    }
    w.c[n]= budujB(g-1,n);;
    w.leaf=0;
  }

  zapisz(pozycja++,&w);
  return pozycja-1;
}

void drukujB(int r, int p){
  // drukuje B-drzewo o korzeniu r (pozycja w pliku)
  // wydruk przesuniety o p w prawo
  Wezel w;
  int i,j;
  odczytaj(r,&w);
  if (w.leaf){
    for (i=0;i<p;i++) printf(" ");
    for (i=0;i<w.n;i++) printf("%d ",w.k[i]);
    printf("\n");
  } else {
    drukujB(w.c[w.n],p+4);
    for (i=w.n-1;i>=0;i--){
      for (j=0;j<p;j++) printf(" ");
      printf("%d\n",w.k[i]);
      drukujB(w.c[i],p+4);
    }
  }
}
/////////SZUKANIE////////////
int BTreeSearch(int x,int k){
// szuka klucza k w poddrzewie o korzeniu x
  Wezel w;
  odczytaj(x,&w);
int i=0;
while ((i<=w.n)&&(k>=w.k[i]))
{
if ((i<=w.n)&&(k==w.k[i]))
    {
        //printf("\n%i\n",w.k[i]);
        return x;
    }
    i++;
}
if (w.leaf){
return -1; //klucza nie ma
}
else{
return BTreeSearch(w.c[i],k);
}
}
///////////////////////
/////////ROZBIJANIE//////////////
void BtreeSplitChild(int klucz_ojciec,int i,int klucz_syn, int root){
//
    int xx, yy;
    xx = BTreeSearch(root, klucz_ojciec);
    yy = BTreeSearch(root, klucz_syn);
    //i = 1;


// rozbija wêze³ y, który jest i-tym synem wêz³a x
Wezel z; // nowy wêze³
Wezel x;
Wezel y;
odczytaj(xx,&x);
odczytaj(yy,&y);
z.leaf = y.leaf; // z jest liœciem, je¿eli y by³ liœciem
z.n = y.n/2;
for(int j=0;j<z.n;j++) // przepisujemy czêœæ kluczy do z
    z.k[j]= y.k[j+z.n+1];
if (y.leaf!=1)
{
    for (int j=0;j<z.n+1;j++) // przepisujemy odpowiednich synów do z
        z.c[j]= y.c[j+z.n+1];
}

for (int j=x.n+1;j>i;j--) // robimy miejsce na nowego syna w x
    x.c[j]= x.c[j-1];
for (int j=x.n;j>i;j--) // robimy miejsce na nowy klucz w x
    x.k[j]= x.k[j-1];
x.k[i] = y.k[z.n]; // œrodkowy klucz wêz³a y jest tym nowym kluczem
x.n = x.n+1;
y.n = y.n-z.n-1;
/////tu skonczylem
//DISK-WRITE(y)
zapisz(yy,&y);
//DISK-WRITE(z)
zapisz(POZYCJA, &z);
x.c[i+1] = POZYCJA; // z jest tym synem
POZYCJA+=rozmiarw;
//DISK-WRITE(x)
zapisz(xx,&x);
}
///////////////////////
//Wstawianie do poddrzewa, którego korzeñ jest niepe³ny
void BTREEINSERTNONFULL(int xx, int k, int root){
// wstawia klucz k do poddrzewa o korzeniu x
// wêze³ x jest niepe³ny (x.n < 2*t-1)
Wezel x;
odczytaj(xx,&x);
int i = x.n;
if (x.leaf) // wstawiamy k do x zachowuj¹c porz¹dek
{
    while ((i>=1)&&(k < x.k[i-1])){
        x.k[i] = x.k[i-1];
        i = i-1;
}
x.k[i] = k;
x.n = x.n + 1;
zapisz(xx,&x);
}
else{ // rekursywne zejœcie w dó³ drzewa
while ((i>=1)&&(k < x.k[i-1]))
    i = i-1;

Wezel tmp;
odczytaj(x.c[i],&tmp);
if (tmp.n == 2*T - 1)
{
    BtreeSplitChild(x.k[0],i,tmp.k[0],root);
        if (k > x.k[i+1]){
            i = i+1;
        }

        BTREEINSERTNONFULL(xx,k,root);
}
else
BTREEINSERTNONFULL(x.c[i],k,root);
}
}
///////////////////////
//Wstawianie do B-drzewa
int BTREEINSERT(int root,int k){
// wstawia klucz k do drzewa T
Wezel r;
odczytaj(root, &r);

if (r.n == 2*T - 1){
Wezel s;
s.leaf = 0;
s.n = 0;
s.c[0] = root;
zapisz(POZYCJA, &s);
int pozycja_s=POZYCJA;
POZYCJA+=rozmiarw;
BtreeSplitChild(pozycja_s,0,root, root);
BTREEINSERTNONFULL(pozycja_s,k,root);
root=pozycja_s;
return root;
}
else
{
    BTREEINSERTNONFULL(root,k,root);
    return root;
}
}
///////////////////////
int main(){
    drzewo = fopen("bdrzewo.txt","w+");
    int root;
    root=budujB(2,3);
    POZYCJA = root + rozmiarw;
    drukujB(root,0);
    printf("\n//////Rysuje podrzewo w ktorego korzeniu jest szukana liczba////////\n");
    int iks,iks2;
    iks=BTreeSearch(root,27);
    iks2=BTreeSearch(root,5);
    drukujB(iks,0);
    //ODCZEPIENIE WEZLA I WSTAWIENIE INNEGO
    //Wezel tmp;
    //odczytaj(iks2, &tmp);
    //zapisz(iks, &tmp);
    printf("\n/////////////\n");
    //drukujB(root,0);
    //MODYFIKACJA WEZLA

    //BtreeSplitChild(31,23,&POZYCJA, root);
   // BtreeSplitChild(31,55,&POZYCJA, root);
   // BtreeSplitChild(31,27,&POZYCJA, root);
   // BtreeSplitChild(35,33,&POZYCJA, root);
//    Wezel tmp;
//    odczytaj(yy,&tmp);
//    tmp.k[0]=999;
//    zapisz(yy,&tmp);
    //drukujB(root,0);
     printf("\n/////////////\n");
    //BTREEINSERTNONFULL(root,1,root,&POZYCJA);
  //  BTREEINSERTNONFULL(root,1,root,&POZYCJA);
     //   drukujB(root,0);
   // BTREEINSERTNONFULL(root,1,root,&POZYCJA);
 //   BtreeSplitChild(47,39,&POZYCJA, root);
    //drukujB(root,0);
    printf("\n//////WSTAWIANIE///////\n");
    root=BTREEINSERT(root, 65);
    root=BTREEINSERT(root, 66);
    root=BTREEINSERT(root, 67);
    root=BTREEINSERT(root, 68);
    root=BTREEINSERT(root, 69);
    root=BTREEINSERT(root, 57);
    root=BTREEINSERT(root, 57);
printf("//PO WSTAWIENIU KOLEJNO 65, 66, 67, 68, 69, 57, 57\n");
    drukujB(root,0);
    // BtreeSplitChild(55,2,57,&POZYCJA, root);
    root=BTREEINSERT(root, 57);
    printf("//PO WSTAWIENIU 57\n");
    drukujB(root,0);
    //BtreeSplitChild(47,3,57, root);
    root=BTREEINSERT(root, 66);
    root=BTREEINSERT(root, 64);
    root=BTREEINSERT(root, 63);
    printf("//PO WSTAWIENIU KOLEJNO 66 ,64, 63\n");
    drukujB(root,0);
    root=BTREEINSERT(root, 64);
    root=BTREEINSERT(root, 66);
    root=BTREEINSERT(root, 72);
    printf("//PO WSTAWIENIU KOLEJNO 64, 66, 72 ,66 ,66 ,66\n");
root=BTREEINSERT(root, 66);
root=BTREEINSERT(root, 66);
root=BTREEINSERT(root, 66);

    //BTREEINSERTNONFULL(root,57,root,&POZYCJA);
    drukujB(root,0);
    fclose(drzewo);
}
