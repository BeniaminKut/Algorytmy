package com.company;

import com.sun.xml.internal.ws.commons.xmlutil.Converter;

import java.io.*;
import java.rmi.server.ExportException;
import java.util.ArrayList;
import java.util.Random;

public class Main {

    public static void main(String[] args) {
        //utworzenie pliku z cyframi
        int mianownik = 150;
        try {
            Random generator = new Random();
            FileWriter file = new FileWriter("E:\\Algorytmy i struktury danych\\Algorytm Huffmana\\cyfry.txt");
            BufferedWriter bufor = new BufferedWriter(file);
            int zmienna=0;
            for(int i = 0; i<5000; i++) {
                zmienna=generator.nextInt(8);
                //TO JEST TAKIE SITO KTORE SPOWODUJE ZE NIEKTORE CYFRY BEDA RZADZIEJ
                if(zmienna==1)
                    zmienna=generator.nextInt(8);
                if(zmienna==2)
                    zmienna=generator.nextInt(8);
                if(zmienna==3)
                    zmienna=generator.nextInt(8);
                if(zmienna==4)
                    zmienna=generator.nextInt(8);
                //
                bufor.write(Integer.toString(zmienna));
                bufor.write(Integer.toString(zmienna));
                mianownik=300;
            }
            bufor.close();
        }
        catch(Exception ex)
        {
            System.out.println("Cos poszlo nie tak");
        }
        //liczenie po jednym znaku z pliku
        try {
            FileReader plik = new FileReader("E:\\\\Algorytmy i struktury danych\\\\Algorytm Huffmana\\\\cyfry.txt");
            BufferedReader bufor = new BufferedReader(plik);
            int text=0;
            int[] tablica_wystapien = {0,0,0,0,0,0,0,0};
            while(text != -1)
            {
                text=bufor.read();
                System.out.println((char)text);
                int pozycja = (char)text - '0';
                if(text!=-1)
                {
                    tablica_wystapien[pozycja]++;
                }
            }
            bufor.close();
            plik.close();
            /////////////////
            FileReader plik2 = new FileReader("E:\\\\Algorytmy i struktury danych\\\\Algorytm Huffmana\\\\cyfry.txt");
            BufferedReader bufor2 = new BufferedReader(plik2);
            text=0;
            String tmp2="";
            int[][] tablica_wystapien2 = new int[8][8];
            for(int i=0;i<8;i++) {
                for (int j = 0; j < 8; j++) {
                    tablica_wystapien2[i][j]=0;
                }
            }
            while(text != -1)
            {
                text=bufor2.read();
                if(text == -1) break;
                tmp2+=(char)text;
                text=bufor2.read();
                if(text == -1) break;
                tmp2+=(char)text;
                System.out.println(tmp2);
                int n=Character.getNumericValue(tmp2.charAt(0));
                int m=Character.getNumericValue(tmp2.charAt(1));
                tmp2="";
                tablica_wystapien2[n][m]++;
            }
            bufor2.close();
            plik2.close();
            for(int i=0;i<8;i++) {
                for (int j = 0; j < 8; j++) {
                    System.out.print(tablica_wystapien2[i][j] + " ");
                }
                System.out.println();
            }
            /////////////////
            ArrayList<Wezel> wezly = new ArrayList<Wezel>();
            for(int i=0;i<8;i++) {
                wezly.add(new Wezel(Integer.toString(i),tablica_wystapien[i]));
                System.out.println(i + ": " + wezly.get(i).ilosc_wystapien+"  "+wezly.get(i).znak);
            }


            ///////////////////
            ArrayList<Wezel> wezly2 = new ArrayList<Wezel>();
            for(int i=0;i<8;i++) {
                for (int j = 0; j < 8; j++) {
                    wezly2.add(new Wezel(Integer.toString(i) + Integer.toString(j), tablica_wystapien2[i][j]));
                }
            }
                 for(Wezel a : wezly2)
                    System.out.println(a.ilosc_wystapien + "  " + a.znak);

            Wezel.Huffman(wezly);
            Wezel.Wypisz_liscie(wezly.get(0));
            int ilosc = Wezel.Dlugosc_kodowania(wezly.get(0),0);
            Wezel.Huffman(wezly2);
            Wezel.Wypisz_liscie(wezly2.get(0));
            /////////////////
            System.out.println("Dlugosc kodowania dla jednego znaku: "+ilosc+" - kompresja na poziomie "+(float)ilosc/mianownik+"%");
            ilosc = Wezel.Dlugosc_kodowania(wezly2.get(0),0);
            System.out.println("Dlugosc kodowania dla dwoch znakow: "+ilosc+" - kompresja na poziomie "+(float)ilosc/mianownik+"%");
        }
        catch (IOException e)
        {
            System.out.println("Blad");
        }
    }
}
class Wezel
{
    String znak;
    int ilosc_wystapien;
    String kodHuffmana;
    Wezel lewy;
    Wezel prawy;
    Wezel(){}
    Wezel(String znak,int ilosc_wystapien)
    {
        this.znak=znak;
        this.ilosc_wystapien=ilosc_wystapien;
    }
    static Wezel extract_min(ArrayList<Wezel> wezly)
    {
        Wezel tmp = new Wezel("zero",-1);
        for(Wezel i : wezly)
        {
            if(i.ilosc_wystapien<tmp.ilosc_wystapien||tmp.ilosc_wystapien==-1) tmp=i;
        }
        wezly.remove(wezly.indexOf(tmp));
        return tmp;
    }
    static void Huffman (ArrayList<Wezel> wezly){
        while(wezly.size()>1) {
            Wezel x = Wezel.extract_min(wezly);
            Wezel y = Wezel.extract_min(wezly);
            Wezel z = new Wezel();
            z.ilosc_wystapien = x.ilosc_wystapien + y.ilosc_wystapien;
            z.lewy = x;
            z.prawy = y;
            wezly.add(z);
        }
        Wezel ROOT = wezly.get(0);
        Wezel.Kodowanie(ROOT,"");
    }
    static void Kodowanie(Wezel w, String kod){
        if(w.prawy==null&&w.lewy==null)
        {
            w.kodHuffmana=kod;
        }
        if(w.lewy!=null)
        {
            Kodowanie(w.lewy,kod+"0");
        }
        if(w.prawy!=null)
        {
            Kodowanie(w.prawy,kod+"1");
        }
    }
    static void Wypisz_liscie(Wezel w)
    {
        if(w.prawy==null&&w.lewy==null)
        {
            System.out.println("znak: "+w.znak+",ilosc wystapien: "+w.ilosc_wystapien+", kod Huffmana: "+w.kodHuffmana);
        }
        if(w.lewy!=null)
        {
            Wypisz_liscie(w.lewy);
        }
        if(w.prawy!=null)
        {
            Wypisz_liscie(w.prawy);
        }
    }
    static int Dlugosc_kodowania(Wezel w, int ilosc)
    {
        if(w.prawy==null&&w.lewy==null)
        {
            ilosc+=w.ilosc_wystapien*w.kodHuffmana.length();
        }
        if(w.lewy!=null)
        {
            ilosc=Dlugosc_kodowania(w.lewy,ilosc);
        }
        if(w.prawy!=null)
        {
            ilosc=Dlugosc_kodowania(w.prawy,ilosc);
        }
        return ilosc;
    }

}
