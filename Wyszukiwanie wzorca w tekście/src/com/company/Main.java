package com.company;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        String wzorzec = "";
        String tekst = "";
        //int[] tab = WyszukiwanieWzorcaWTekscie.prefixFunction(wzorzec);
        //for(int i=0;i<tab.length;i++)
        //    System.out.println(tab[i]);
        System.out.println("TESTY DLA PUSTEGO WZORCA:");
        System.out.println(wzorzec+" - wzorzec\n"+tekst+" - tekst");
        System.out.println("Algorytm naiwny:");
        WyszukiwanieWzorcaWTekscie.naiwny(wzorzec,tekst);
        System.out.println("Algorytm Rabin-karp:");
        WyszukiwanieWzorcaWTekscie.rabinKarp(wzorzec,tekst,101);
        System.out.println("Algorytm KMP:");
        WyszukiwanieWzorcaWTekscie.KMP(wzorzec,tekst);
        /////////////////////////////////////////////////////
        wzorzec = "ABA";
        tekst = "ABABABABABABABABABABABA";
        System.out.println("TESTY DLA WZORCA NAKLADAJACEGO SIE:");
        System.out.println(wzorzec+" - wzorzec\n"+tekst+" - tekst");
        System.out.println("Algorytm naiwny:");
        WyszukiwanieWzorcaWTekscie.naiwny(wzorzec,tekst);
        System.out.println("Algorytm Rabin-karp:");
        WyszukiwanieWzorcaWTekscie.rabinKarp(wzorzec,tekst,101);
        System.out.println("Algorytm KMP:");
        WyszukiwanieWzorcaWTekscie.KMP(wzorzec,tekst);
        ////////////////////////////////////////////////////
        System.out.println("TESTY Z PLIKOW PRZYKLAD ctfgctccct:");
        FileReader plik = null;
        try {
            plik = new FileReader("./wzorzec.txt");
            BufferedReader bufor = new BufferedReader(plik);
            String linia;
            wzorzec="";
            do {
                linia = bufor.readLine();
                if (linia != null) {
                    wzorzec+=linia;
                }
            } while (linia != null);
            System.out.println("wzorzec.txt - "+wzorzec);
            System.out.println(wzorzec.length());
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            plik = new FileReader("./tekst.txt");
            BufferedReader bufor = new BufferedReader(plik);
            String linia;
            tekst="";
            do {
                linia = bufor.readLine();
                if (linia != null) {
                    tekst+=linia;
                }
            } while (linia != null);
            System.out.println("tekst.txt - "+tekst);
            System.out.println(tekst.length());

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        ///////////////////ZMIENNE DO POMIARU CZASU/////////////////
        long czasRozpoczecia;
        long czasZakonczenia;
        long czasTrwania[] = new long[6];
        ///////////////////////////////////////////////////////////
        System.out.println(wzorzec+" - wzorzec\n"+tekst+" - tekst");
        System.out.println("Algorytm naiwny:");
        czasRozpoczecia = System.currentTimeMillis();
        WyszukiwanieWzorcaWTekscie.naiwny(wzorzec,tekst);
        czasZakonczenia = System.currentTimeMillis();
        czasTrwania[0]=czasZakonczenia-czasRozpoczecia;
        System.out.println("Algorytm Rabin-karp:");
        czasRozpoczecia = System.currentTimeMillis();
        WyszukiwanieWzorcaWTekscie.rabinKarp(wzorzec,tekst,8837);
        czasZakonczenia = System.currentTimeMillis();
        czasTrwania[1]=czasZakonczenia-czasRozpoczecia;
        System.out.println("Algorytm KMP:");
        czasRozpoczecia = System.currentTimeMillis();
        WyszukiwanieWzorcaWTekscie.KMP(wzorzec,tekst);
        czasZakonczenia = System.currentTimeMillis();
        czasTrwania[2]=czasZakonczenia-czasRozpoczecia;
        //////////////////////////////////////////////////////////
        System.out.println("TEST Z PLIKOW PRZYKLAD ababababa:");
        plik = null;
        try {
            plik = new FileReader("./wzorzec1.txt");
            BufferedReader bufor = new BufferedReader(plik);
            String linia;
            wzorzec="";
            do {
                linia = bufor.readLine();
                if (linia != null) {
                    wzorzec+=linia;
                }
            } while (linia != null);
            System.out.println("wzorzec1.txt - "+wzorzec);
            System.out.println(wzorzec.length());
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            plik = new FileReader("./tekst1.txt");
            BufferedReader bufor = new BufferedReader(plik);
            String linia;
            tekst="";
            do {
                linia = bufor.readLine();
                if (linia != null) {
                    tekst+=linia;
                }
            } while (linia != null);
            System.out.println("tekst1.txt - "+tekst);
            System.out.println(tekst.length());

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println(wzorzec+" - wzorzec\n"+tekst+" - tekst");
        System.out.println("Algorytm naiwny:");
        czasRozpoczecia = System.currentTimeMillis();
        WyszukiwanieWzorcaWTekscie.naiwny(wzorzec,tekst);
        czasZakonczenia = System.currentTimeMillis();
        czasTrwania[3]=czasZakonczenia-czasRozpoczecia;
        System.out.println("Algorytm Rabin-karp:");
        czasRozpoczecia = System.currentTimeMillis();
        WyszukiwanieWzorcaWTekscie.rabinKarp(wzorzec,tekst,547);
        czasZakonczenia = System.currentTimeMillis();
        czasTrwania[4]=czasZakonczenia-czasRozpoczecia;
        System.out.println("Algorytm KMP:");
        czasRozpoczecia = System.currentTimeMillis();
        WyszukiwanieWzorcaWTekscie.KMP(wzorzec,tekst);
        czasZakonczenia = System.currentTimeMillis();
        czasTrwania[5]=czasZakonczenia-czasRozpoczecia;
        System.out.println("ALGORYTM--|-ZESTAW1-|-ZESTAW2-----");
        System.out.println("---------------------------------");
        System.out.println("NAIWNY    |"+ czasTrwania[0]+"ms      |"+ czasTrwania[3]+"ms");
        System.out.println("Rabin-karp|"+ czasTrwania[1]+"ms     |"+ czasTrwania[4]+"ms");
        System.out.println("KMP       |"+ czasTrwania[2]+"ms  |"+ czasTrwania[5]+"ms");


    }
}
class WyszukiwanieWzorcaWTekscie {
    static void naiwny(String wzorzec, String tekst) {
        int dlugoscTekstu = tekst.length();
        int dlugoscWzorca = wzorzec.length();
        if(dlugoscWzorca>0) {
            for (int i = 0; i <= dlugoscTekstu - dlugoscWzorca; i++) {
                Boolean wzorPasuje = true;
                for (int j = 0; j < dlugoscWzorca; j++) {
                    if (wzorzec.charAt(j) != tekst.charAt(i + j)) {
                        wzorPasuje = false;
                        break;
                    }
                }
                if (wzorPasuje) {
                    //wypisz pozycje w tekscie na ktorej znaleziono dopasowanie
                    System.out.println("Wystapienie wzorca w tekscie na pozycji: " + i);
                }
            }
        }
    }

    ///////////////////////////////////////////////
    static void KMP(String wzorzec, String tekst) {
        if (wzorzec.length() > 0) {
            int[] pi = prefixFunction(wzorzec);
            int dlugoscTekstu = tekst.length();
            int dlugoscWzorca = wzorzec.length();
            int j = 0;
            int i = 0;
            while (i < dlugoscTekstu) {
                if (wzorzec.charAt(j) == tekst.charAt(i)) {
                    j++;
                    i++;
                }
                if (j == dlugoscWzorca) {
                    System.out.println("Wystapienie wzorca w tekscie na pozycji: " + (i - j));
                    j = pi[j - 1];
                }

                // mismatch after j matches
                else if (i < dlugoscTekstu && wzorzec.charAt(j) != tekst.charAt(i)) {
                    if (j != 0)
                        j = pi[j - 1];
                    else
                        i = i + 1;
                }
            }
        }
    }

    static int[] prefixFunction(String wzorzec) {
        String prefiks_i;
        String prefiks;
        String sufiks;
        int m = wzorzec.length();
        int[] prefixTable = new int[m];
        prefixTable[0] = 0;
        for (int i = 2; i <= m; i++) {
            prefixTable[i - 1] = 0;
            int k = i - 1;
            prefiks_i = wzorzec.substring(0, i);
            while (k > 0) {
                prefiks = prefiks_i.substring(0, k);
                sufiks = prefiks_i.substring(i - k);
                //  System.out.println("i: " + i + "Prefix_1.l - " + prefiks_i.length() + "Prefix.l - " + prefiks.length() + " sufiks.l - " + sufiks.length());
                //  System.out.println("prefiks_i - " + prefiks_i + " prefiks - " + prefiks + " sufiks - " + sufiks + " k = " + k);
                if (prefiks.equals(sufiks)) {
                    prefixTable[i - 1] = k;
                    break;
                }
                k--;
            }
        }
        return prefixTable;
    }

    ///////////////////////////////////
    static void rabinKarp(String P, String T, int q) {
// P - wzorzec, tablica [1..m],
// T- tekst, tablica [1..n],
// d - rozmiar alfabetu (np. 128),
// q - liczba pierwsza (np. 27077)
        if (P.length() > 0) {
            int d = 256;
            int h = 1;
            for (int i = 0; i < P.length() - 1; i++)
                h = (h * d) % q; // wyliczy h = (d do potęgi m-1) modulo q
            int p = 0;
            int t = 0;
            for (int i = 0; i < P.length(); i++) {
                p = (d * p + P.charAt(i)) % q;
                t = (d * t + T.charAt(i)) % q;
            }
// wyliczone: wartość p "kodująca" P[1..m]
// oraz wartość t "kodująca" T[s+1..s+m] dla s==0
// kodowanie niejednoznaczne! (haszowanie)
            for (int s = 0; s <= T.length() - P.length(); s++) {
                if (p == t) {
                    Boolean czyRowne = true;
                    for (int i = 0; i < P.length(); i++) {
                        if (P.charAt(i) != T.charAt(s + i)) { // tu porównujemy m znaków (w pętli)
                            czyRowne = false;
                            break;
                        }
                    }
                    if (czyRowne) {
                        System.out.println("znalezione wystąpienie wzorca od pozycji " + s);
                    }
                }
                if (s < T.length() - P.length()) { // czy tekst się nie skończył?
                    int t1 = (T.charAt(s) * h) % q;
                    if (t < t1) t = t + q;
                    t = (d * (t - t1) + T.charAt(s + P.length())) % q;
                }
// czyli t = (d*(t-T[s+1]*h)+T[s+1+m])%q, gdzie arytmetyka jest
// modulo q (mnożenie i odejmowanie)
// to wylicza wartość t "kodującą" T[s+2, ... , s+m,s+1+m]
// na podstawie wartości t "kodującej" T[s+1,s+2, ... , s+m]
            }
        }
    }
}