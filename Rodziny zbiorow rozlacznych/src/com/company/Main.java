package com.company;

public class Main {

    public static void main(String[] args) {
	Wezel[] Z = new Wezel[10];
	for(int i = 0; i<10; i++)
    {
        Z[i] = new Wezel(i);
    }

        Wezel.Union(Wezel.FindSet(Z[0]),Wezel.FindSet(Z[1]));
        Wezel.Union(Wezel.FindSet(Z[2]),Wezel.FindSet(Z[3]));
        Wezel.Union(Wezel.FindSet(Z[1]),Wezel.FindSet(Z[2]));
        Wezel.Union(Wezel.FindSet(Z[5]),Wezel.FindSet(Z[6]));
        Wezel.Union(Wezel.FindSet(Z[7]),Wezel.FindSet(Z[8]));
        Wezel.Union(Wezel.FindSet(Z[3]),Wezel.FindSet(Z[5]));
        Wezel.Union(Wezel.FindSet(Z[0]),Wezel.FindSet(Z[7]));

        for(int i = 0;i<10;i++)
        {
            Wezel tmp = Z[i];
            int j =0;
            do {
            System.out.println("Z[" + i + "].parent."+j+" = " + tmp.parent.klucz);
            tmp=tmp.parent;
            j++;
        }while(tmp.parent!=tmp);
        }
        System.out.println("------------ KRUSKAL -----------------");
        /*
                 10
            0--------1
            |  \     |
           6|   5\   |15
            |      \ |
            2--------3
                4
        */
        Krawedzie[] E = new Krawedzie[5];
        E[0]=new Krawedzie(0,1,10);
        E[1]=new Krawedzie(0,2,6);
        E[2]=new Krawedzie(0,3,5);
        E[3]=new Krawedzie(1,3,15);
        E[4]=new Krawedzie(2,3,4);
        int ilK=5;
        int ilW=4;
        Wezel.Kruskal(ilW,ilK,E);

    }
}
class Wezel {
   int klucz;
   Wezel parent;
    int rank;

    public Wezel(int klucz) //MakeSet(klucz)
    {
        this.klucz = klucz;
        this.parent = this;
        this.rank = 0;
    }


    public static Wezel FindSet(Wezel x){
        if(x!=x.parent)
            x.parent = FindSet(x.parent);
        return x.parent;
    }


    static void Union(Wezel x, Wezel y)
    {
        if(x.rank > y.rank)
        {
            y.parent = x;
        }
        else
        {
            x.parent = y;
            if(x.rank==y.rank)
            {
                y.rank++;
                x.rank++;
            }
        }
    }

    static void Kruskal(int ilW, int ilK, Krawedzie[] E)
    {
        Wezel[] V = new Wezel[ilW];
        for(int i=0;i<ilW;i++)
        {
            V[i]=new Wezel(i);
        }
        for(int i=0;i<E.length;i++)
            for(int j=0;j<E.length;j++)
            {
                if(E[i].waga<E[j].waga)
                {
                    Krawedzie tmp=E[i];
                    E[i]=E[j];
                    E[j]=tmp;
                }
            }
            for(int i=0;i<ilK;i++)
            {
                Wezel ru = FindSet(V[E[i].u]);
                Wezel rv = FindSet(V[E[i].v]);
                if(ru!=rv){
                    System.out.println(E[i].u+"---- "+E[i].waga+" ----"+E[i].v);
                    Union(ru,rv);
                }
            }
    }
}
class Krawedzie
{
    int u;
    int v;
    int waga;

    public Krawedzie(int u, int v, int waga)
    {
        this.u=u;
        this.v=v;
        this.waga=waga;
    }
}