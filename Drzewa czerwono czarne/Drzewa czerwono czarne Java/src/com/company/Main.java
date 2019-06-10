package com.company;
import java.util.Random;
import java.util.Scanner;
import static java.sql.Types.NULL;
import java.nio.*;
import java.nio.ByteBuffer;

public class Main {
    static final int RED=1;        /* stala oznaczajaca kolor wezla */
    static final int BLACK=0  ;    /* stala oznaczajaca kolor wezla */


    public static void main(String[] args) {
        drzewko ROOT = new drzewko();
        Wydruk wydruk = new Wydruk();
        //PRZYKLAD Z ZADANIA 1
        ROOT = ROOT.WSTAW(38);
        ROOT = ROOT.WSTAW(31);
        ROOT = ROOT.WSTAW(22);
        ROOT = ROOT.WSTAW(8);
        ROOT = ROOT.WSTAW(20);
        ROOT = ROOT.WSTAW(5);
        ROOT = ROOT.WSTAW(10);
        ROOT = ROOT.WSTAW(9);
        ROOT = ROOT.WSTAW(21);
        ROOT = ROOT.WSTAW(27);
        ROOT = ROOT.WSTAW(29);
        ROOT = ROOT.WSTAW(25);
        ROOT = ROOT.WSTAW(28);
        wydruk.drukuj(ROOT);
        //
        drzewko.Liczenie(ROOT);
        System.out.println("Min. glebokosc liscia = " + drzewko.min + "\nMax. glebokosc liscia = " + drzewko.max + "\nIle czerwonych: " + drzewko.ile_czerw);
        drzewko.min = 0;
        drzewko.max = 0;
        drzewko.lokalne = 0;
        drzewko.ile_czerw = 0;
        //INNY PRZYKLAD
        ROOT = new drzewko();
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        ROOT = ROOT.WSTAW(1);
        wydruk.drukuj(ROOT);
        drzewko.Liczenie(ROOT);
        System.out.println("Min. glebokosc liscia = " + drzewko.min + "\nMax. glebokosc liscia = " + drzewko.max + "\nIle czerwonych: " + drzewko.ile_czerw);
        drzewko.min = 0;
        drzewko.max = 0;
        drzewko.lokalne = 0;
        drzewko.ile_czerw = 0;
        //INNY PRZYKLAD
        ROOT = new drzewko();
        ROOT = ROOT.WSTAW(50);
        ROOT = ROOT.WSTAW(25);
        ROOT = ROOT.WSTAW(10); //PRZYPADEK 3 ROTACJA W PRAWO WOKOL KORZENIA
        ROOT = ROOT.WSTAW(5);  //PRZYPADEK 1 OJCIEC CZERWONY I BRAT OJSCA CZERWONY
        ROOT = ROOT.WSTAW(45);
        ROOT = ROOT.WSTAW(75);
        ROOT = ROOT.WSTAW(60); //PRZYPADEK 2
        ROOT = ROOT.WSTAW(65); //PRZYPADEK 2
        ROOT = ROOT.WSTAW(90); //PRZYPADEK 1 KTORY PROWADZI DO PRZYPADKU 3
        ROOT = ROOT.WSTAW(6);  //PRZYPADEK 2
        ROOT = ROOT.WSTAW(3);  //PRZYPADEK 1 KTORY PROWADZI DO PRZYPADKU 1
        ROOT = ROOT.WSTAW(4);  //PRZYPADEK 2
        ROOT = ROOT.WSTAW(1);  //PRZYPADEK 1 KTORY PROWADZI DO PRZYPADKU 3
        wydruk.drukuj(ROOT);
        drzewko.Liczenie(ROOT);
        System.out.println("Min. glebokosc liscia = " + drzewko.min + "\nMax. glebokosc liscia = " + drzewko.max + "\nIle czerwonych: " + drzewko.ile_czerw);
        drzewko.min = 0;
        drzewko.max = 0;
        drzewko.lokalne = 0;
        drzewko.ile_czerw = 0;
        //INNY PRZYKLAD
        Random generator = new Random();
        ROOT = new drzewko();
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));
        ROOT = ROOT.WSTAW((generator.nextInt(98)+1));

        wydruk.drukuj(ROOT);
        drzewko.Liczenie(ROOT);
        System.out.println("Min. glebokosc liscia = " + drzewko.min + "\nMax. glebokosc liscia = " + drzewko.max + "\nIle czerwonych: " + drzewko.ile_czerw);
        drzewko.min = 0;
        drzewko.max = 0;
        drzewko.lokalne = 0;
        drzewko.ile_czerw = 0;
        //////////////////////
    }
}
class drzewko
{
    static int max;
    static int min;
    static int lokalne;
    static int ile_czerw;
    static final int RED=1;        /* stala oznaczajaca kolor wezla */
    static final int BLACK=0  ;    /* stala oznaczajaca kolor wezla */
    int klucz;
    int kolor;
    drzewko lewy;
    drzewko prawy;
    drzewko tatus;
    //KONSTRUKTOR TWORZACY PUSTE DRZEWO
    drzewko()
    {
        //STWORZENIE DRZEWA

        //STWORZENIE WARTOWNIKA
     drzewko WARTOWNIK=new drzewko(NULL,BLACK);

     //WARTOSCI POCZATKOWE DLA PUSTEGO DRZEWKA
     this.tatus=WARTOWNIK;
     this.lewy=WARTOWNIK;
     this.prawy=WARTOWNIK;
     this.klucz=NULL;
     this.kolor=BLACK;
    }
    //PRYWATNY KONSTRUKTOR DO TWORZENIA WEZLOW
    private drzewko(int klucz, int kolor)
    {
        this.klucz=klucz;
        this.kolor=kolor;
    }
    private void USTAW_LEWY(drzewko lewy)
    {
        this.lewy=lewy;
    }
    private void USTAW_PRAWY(drzewko prawy)
    {
        this.prawy=prawy;
    }
    private void USTAW_TATUS(drzewko tatus)
    {
        this.tatus=tatus;
    }
    private void USTAW_TRZY(drzewko tatus, drzewko lewy, drzewko prawy)
    {
        USTAW_TATUS(tatus);
        USTAW_LEWY(lewy);
        USTAW_PRAWY(prawy);
    }
    drzewko Right_rotate()
    {
        drzewko x = this.lewy;
        this.lewy=x.prawy;
        if(this.lewy.klucz!=NULL) this.lewy.tatus=this; //jezeli bylo cos do przepiecia
        x.tatus=this.tatus;
        if(this.tatus.klucz!=NULL) //jezeli rotacja nie byla wokol korzenia
        {
            if (this.tatus.lewy == this) {
                this.tatus.lewy = x;
            } else {
                this.tatus.prawy = x;
            }
            this.tatus = x;
            x.prawy = this;
            return this;
        }
        else
        {
            this.tatus = x;
            x.prawy = this;
            return this.tatus;
        }




    }
    drzewko Left_rotate()
    {
        drzewko x = this.prawy;
        this.prawy=x.lewy;
        if(this.prawy.klucz!=NULL) this.prawy.tatus=this; //jezeli bylo cos do przepiecia
        x.tatus=this.tatus;
        if(this.tatus.klucz!=NULL) //jezeli rotacja nie byla wokol korzenia
        {
            if (this.tatus.prawy == this) {
                this.tatus.prawy = x;
            } else {
                this.tatus.lewy = x;
            }
            this.tatus = x;
            x.lewy = this;
            return this;
    }
        else
    {
        this.tatus = x;
        x.lewy = this;
        return this.tatus;

    }

    }
    drzewko WSTAW(int klucz) {
        drzewko ROOT = this;
        //wezel w1 teraz ma klucz i kolor czerwony, lewy,prawy,tatus - puste odwolania
        drzewko w1 = new drzewko(klucz, RED);
        //wezel w1 teraz ma lewy,prawy,tatus - odowlania do WARTOWNIKA
        w1.USTAW_TRZY(this.tatus, this.tatus, this.tatus);
        //teraz wedrujemy po zwyklym drzewie binarnym w poszukiwaniu miesjca na nowy wezel
        drzewko x = this;
        drzewko y = this.tatus;
        while (x.klucz != NULL) {
            y = x;
            if (w1.klucz < x.klucz) {
                x = x.lewy;
            } else {
                x = x.prawy;
            }
        }
        //ustawiamy tatus dla nowego wezla
        w1.tatus = y;
        //przypadek gdy drzewo bylo puste
        if (y == this.tatus) {
            this.klucz = klucz;
            //korzen zawsze czarny a w1 bylo czerwone
            this.kolor = BLACK;
        }
        //ustawiamy prawy lub lewy dla ojca nowego wezla
        else if (w1.klucz < y.klucz) {
            y.lewy = w1;
        } else {
            y.prawy = w1;
        }
        x=w1;
        this.kolor=BLACK;
        drzewko NIL = this.tatus;
        //TERAZ CZESC DLA DRZEW CZERWONO CZARNYCH
        while((x.tatus!=NIL)&&(x.tatus.kolor==RED)&&(x!=NIL)){
            if(x.tatus==x.tatus.tatus.lewy) //x.tatus jest lewym synem
            {
                y=x.tatus.tatus.prawy;      //y = brat ojca
                if(y.kolor==RED)            //przypadek 1
                {
                    x.tatus.kolor=BLACK;
                    y.kolor=BLACK;
                    x.tatus.tatus.kolor=RED;
                    x=x.tatus.tatus; //nowy x
                }
                else
                {
                    if(x==x.tatus.prawy) //przypadek 2
                    {
                        x=x.tatus;
                        x.Left_rotate();
                       // x=x.lewy; //?
                    }
                    x.tatus.kolor=BLACK; //przypadek 3
                    x.tatus.tatus.kolor=RED;
                    x=x.tatus.tatus;
                    if(x==ROOT) {
                        ROOT=x.Right_rotate();
                        x=ROOT;
                    }//?
                   // x=x.lewy;
                    else
                    {
                        x.Right_rotate();
                    }
                }
            }

            ////
            else if(x.tatus==x.tatus.tatus.prawy) //x.tatus jest prawym synem
            {
                y=x.tatus.tatus.lewy;      //y = brat ojca
                if(y.kolor==RED)            //przypadek 1
                {
                    x.tatus.kolor=BLACK;
                    y.kolor=BLACK;
                    x.tatus.tatus.kolor=RED;
                    x=x.tatus.tatus; //nowy x
                }
                else
                {
                    if(x==x.tatus.lewy) //przypadek 2
                    {
                        x=x.tatus;
                        x.Right_rotate();
                        //x=x.prawy; //?
                    }
                    x.tatus.kolor=BLACK; //przypadek 3
                    x.tatus.tatus.kolor=RED;
                    x=x.tatus.tatus;
                    if(x==ROOT) {
                        ROOT=x.Left_rotate(); //?
                        x=ROOT;
                    }
                    //x=x.prawy;
                    else
                    {
                        x.Left_rotate();
                    }
                }
            }
        }
        ROOT.kolor=BLACK;
        return ROOT;
        }

        /////////////////////////////
    //max,min glebokosc ile czerw lisci
    ////////////////////////////////
    static void Liczenie(drzewko x)
    {
        //System.out.println("WEZEL: "+x.klucz+" min: "+min+" min_lokalne: "+lokalne+" max: "+max+" max_lokalne: "+lokalne);
        if(x.klucz==NULL)
        {
            if(lokalne<min||min==0)
            {
                min=lokalne;
            }
            if(lokalne>max)
            {
                max=lokalne;
            }
            lokalne--;

            return;
        }
        lokalne++;
        Liczenie(x.lewy);
        lokalne++;
        Liczenie(x.prawy);
        lokalne--;
        if(x.kolor==RED) ile_czerw++;
    }

    }

    ///////////////////////////////////////
    class Wydruk {
        static final int RED=1;        /* stala oznaczajaca kolor wezla */
        static final int BLACK=0  ;    /* stala oznaczajaca kolor wezla */
        static final int IL_POZ=7;        /* stala oznaczajaca kolor wezla */
        static final int SZER_EKR=180  ;    /* stala oznaczajaca kolor wezla */
        char[][] wydruk=new char[IL_POZ+1][SZER_EKR];

        void drukujost(drzewko w, int l, int p, int poziom) {
            int srodek = (l + p) / 2;
            if (w.klucz == NULL) return;
            wydruk[poziom][srodek] = '*';
        }

        void drukujwew(drzewko w, int l, int p, int poziom) {
            int srodek = (l + p) / 2;
            int i, dl;
            String tmp;
            char[] s=new char[19];
            if (w.klucz == NULL) return;
            if (w.kolor == BLACK) {
                tmp=String.format("%d",w.klucz);
                dl=tmp.length();
                //dl = sprintf(s, "%d", w.klucz);
            }
            else{
                tmp=String.format("%+d",w.klucz);
                dl=tmp.length();
                //dl = sprintf(s, "%+d", w.klucz);
            }
            for(int r=0;r<dl;r++)
            {
                s[r]=tmp.charAt(r);
            }
            for (i = 0; i < dl; i++)
                wydruk[poziom][srodek - dl / 2 + i] = s[i];
            if (++poziom < IL_POZ) {
                drukujwew(w.lewy, l, srodek, poziom);
                drukujwew(w.prawy, srodek + 1, p, poziom);
            } else {
                drukujost(w.lewy, l, srodek, poziom);
                drukujost(w.prawy, srodek + 1, p, poziom);
            }
        }

        void drukuj(drzewko w) {
            int j, i;

            for (i = 0; i <= IL_POZ; i++)
                for (j = 0; j < SZER_EKR; j++)
                    wydruk[i][j] = ' ';
            drukujwew( w, 0, SZER_EKR, 0);
            for (i = 0; i <= IL_POZ; i++) {
                for (j = 0; j < SZER_EKR; j++)
                    System.out.print(wydruk[i][j]);
                System.out.print("\n");
            }
        }
    }
///////////////////////////////////////
