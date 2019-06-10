package com.company;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;

public class Main {

    public static void main(String[] args) {
        dwa_pola[] tablica_do_haszowania = new dwa_pola[20000];
        int x = 0;
        try {
            FileReader plik = new FileReader("E:\\Algorytmy i struktury danych\\Funkcje haszujace\\All 6.3 Java\\Nazwiska.txt");
            BufferedReader bufor = new BufferedReader(plik);
            String linia;
            do {
                linia = bufor.readLine();
                if (linia != null) {
                    //System.out.println(linia);
                    String[] linia2;
                    linia2 = linia.split(" ");
                    tablica_do_haszowania[x] = new dwa_pola(Integer.parseInt(linia2[0]), linia2[1]);
                    x++;
                }
            } while (linia != null);
        } catch (IOException e) {
            System.out.println("Brak pliku");
        }

        //for(int i=0;i<x;i++)
        //  System.out.println(i+": "+tablica_do_haszowania[i].liczba+" - "+tablica_do_haszowania[i].slowo);
////////////////////////////////// Testy
        System.out.println("\n\nTESTY:\n\n");
        dwa_pola[] shaszowane = new dwa_pola[17];

        haszuj(shaszowane, 17, tablica_do_haszowania, 10, 0);
        System.out.println("Przed usunieciem:");
        for (int i = 0; i < 17; i++) {
            if (shaszowane[i] != null) {
                System.out.println(i + ": " + shaszowane[i].liczba + " + " + shaszowane[i].slowo);
            } else
                System.out.println(i + ": NULL");
        }
        for (int i = 0; i < 10; i = i + 2) {
            USUN(tablica_do_haszowania[i].slowo, shaszowane, 17);
        }
        System.out.println("Po usunieciu:");
        for (int i = 0; i < 17; i++) {
            if (shaszowane[i] != null) {
                System.out.println(i + ": " + shaszowane[i].liczba + " + " + shaszowane[i].slowo);
            } else
                System.out.println(i + ": NULL");
        }
//////////////////////////////

//////////////////////////////
        dwa_pola[] pohaszowane = new dwa_pola[31];
        int m = 31;
        haszuj(pohaszowane, m, tablica_do_haszowania, 20, 0);
        System.out.println("Tablica wypelniona 20/31:");
        for (int i = 0; i < 31; i++) {
            if (pohaszowane[i] != null) {
                System.out.println(i + ": " + pohaszowane[i].liczba + " + " + pohaszowane[i].slowo);
            } else
                System.out.println(i + ": NULL");
        }
        for (int i = 0; i < 20; i++) {
            USUN(tablica_do_haszowania[i].slowo, pohaszowane, m);
        }
        System.out.println("Usuniecie wszystkich elementow:");

        for (int i = 0; i < 31; i++) {
            if (pohaszowane[i] != null) {
                System.out.println(i + ": " + pohaszowane[i].liczba + " + " + pohaszowane[i].slowo);
            } else
                System.out.println(i + ": NULL");
        }
        System.out.println("Ponowne wlozenie elementow (polowa starych elementow, polowa nowych):");

        haszuj(pohaszowane, m, tablica_do_haszowania, 20, 10);
        for (int i = 0; i < 31; i++) {
            if (pohaszowane[i] != null) {
                System.out.println(i + ": " + pohaszowane[i].liczba + " + " + pohaszowane[i].slowo);
            } else
                System.out.println(i + ": NULL");
        }

        ////////////////////////////

        ////////////////////////////Pomiary
        System.out.println("\n\nPOMIARY:\n\n");
        Zliczanie_DEL(9791,tablica_do_haszowania);
        Zliczanie_DEL(8699,tablica_do_haszowania);
        Zliczanie_DEL(7933,tablica_do_haszowania);
        Zliczanie_DEL(7057,tablica_do_haszowania);
        Zliczanie_DEL(4096,tablica_do_haszowania);
        Zliczanie_DEL(4093,tablica_do_haszowania);
    }


    static void Zliczanie_DEL(int m,dwa_pola tablica_do_haszowania[])
    {
        dwa_pola Tablica[] = new dwa_pola[20000];
        //pierwsze haszowanie
        haszuj(Tablica,m,tablica_do_haszowania,m/10*8,0);
        //usuwanie co drugi element (co drugi w kolejnosci wstawiania)
        for(int i=0;i<m/10/2*8;i++)
        {
            USUN(tablica_do_haszowania[2*i].slowo,Tablica,m);
        }
        //wstawienie tyle samo elementow co sie usunelo ale teraz inne
        haszuj(Tablica,m,tablica_do_haszowania,m/10/2*8,10000);
        //wypisanie tablicy po operacjach
//        for(int i=0;i<m;i++)
//        {
//            if(Tablica[i]!=null) {
//                System.out.println(i+": "+Tablica[i].liczba + " + " + Tablica[i].slowo);
//            }
//            else
//                System.out.println(i+": NULL");
//        }
        //zliczenie znacznikow "DEL"
        int DEL_LICZNIK=0;
        for(int i=0;i<m;i++)
        {
            if(Tablica[i]!=null) {
                if(Tablica[i].slowo.equals("DEL")) {
                    DEL_LICZNIK++;
                    //System.out.println(i + ": " + Tablica[i].liczba + " + " + Tablica[i].slowo);
                }
            }
        }
        System.out.println("Ilosc znacznikow DEL w tablicy "+m+"-elementowej (zapelniona do 80%, usuniecie 40%, dopelnienie do 80%) = "+DEL_LICZNIK);



    }

    static int zamiana(String slowo)
    {
        int do_zwrocenia;
        int dlugosc;
        dlugosc = slowo.length();
        if(dlugosc<2)
        {
            return 111*(int)slowo.charAt(0);
        }
        do_zwrocenia=(111*(int)slowo.charAt(0)+(int)slowo.charAt(1));
        for(int i=2;i<dlugosc;i++)
        {
            do_zwrocenia=do_zwrocenia*111 + (int)slowo.charAt(i);
        }
        if(do_zwrocenia<0)
            return do_zwrocenia*(-1);
        else return do_zwrocenia;
    }
    static void haszuj(dwa_pola T[],int m,dwa_pola do_schaszowania[],int ile_wyrazow,int od_ktorego_wyrazu)
    {
        int j=0;
        int x=0;
        //adresowanie otwarte kwadratowe
        //h(k,j)=(h(k)+i^2)mod m
        for(int i=od_ktorego_wyrazu;i<ile_wyrazow+od_ktorego_wyrazu;i++)
        {
            j=0;
            while(true)
            {
                x=(int)Math.pow((double)j,(double)2);
                if(T[(zamiana(do_schaszowania[i].slowo)+x)%m]==null||T[(zamiana(do_schaszowania[i].slowo)+x)%m].slowo.equals("DEL"))
                {
                    if(T[(zamiana(do_schaszowania[i].slowo)+x)%m]==null) {
                        T[(zamiana(do_schaszowania[i].slowo)+x)%m]=new dwa_pola(do_schaszowania[i].liczba,do_schaszowania[i].slowo);
                    }
                    else
                    {
                        T[(zamiana(do_schaszowania[i].slowo)+x)%m]=new dwa_pola(do_schaszowania[i].liczba,do_schaszowania[i].slowo);
                    }
                    break;
                }
                else
                    j++;
            }
        }
    }
    static void USUN(String slowo_do_usuniecia, dwa_pola schaszowane[],int m)
    {
        int tmp=zamiana(slowo_do_usuniecia);
        int i=0;
        int x=0;
        while(true)
        {
            x=(int)Math.pow((double)i,(double)2);
            //System.out.println("x: "+x+" i: "+i+" tmp: "+tmp+" (tmp + x) % m: "+(tmp + x) % m+" slowo: "+slowo_do_usuniecia);
            if(schaszowane[(tmp+x)%m]!=null) {
                if (schaszowane[(tmp + x) % m].slowo.equals(slowo_do_usuniecia)) {
                    schaszowane[(tmp + x) % m].slowo = "DEL";
                    schaszowane[(tmp + x) % m].liczba = 0;
                    break;
                } else i++;
            }
            else i++;
        }

    }
}
class dwa_pola
{
    String slowo;
    int liczba;
    dwa_pola(int liczba, String nazwisko)
    {
        this.slowo=nazwisko;
        this.liczba=liczba;
    }

}