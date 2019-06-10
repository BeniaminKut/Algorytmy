package com.company;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Podaj pierwszy wyraz:");
        String wyraz1 = input.next();
        System.out.println("Podaj drugi wyraz:");
        String wyraz2 = input.next();
        System.out.println("Wszystkie najdluzsze podciagi podanych wyrazow to:");
        NWP(wyraz1,wyraz2);
        //PRZYKLADY
        System.out.println("Wszystkie najdluzsze podciagi abcdefghijklm i mlkjihgfedcba to:");
        NWP("abcdefghijklm","mlkjihgfedcba");
        System.out.println("Wszystkie najdluzsze podciagi abcdefghijklm i mlkjihgfedcbab to:");
        NWP("abcdefghijklm","mlkjihgfedcbab");
        System.out.println("Wszystkie najdluzsze podciagi aabca i cabba to:");
        NWP("aabca","cabba");
        System.out.println("Wszystkie najdluzsze podciagi alibaba i kalimalba to:");
        NWP("alibaba","kalimalba");
    }
    static void NWP(String wyraz1, String wyraz2)
    {
      int m = wyraz1.length();
      int n = wyraz2.length();
      int[][] c = new int[m+1][n+1];
      String[][] b = new String[m][n];
      for(int i=0;i<=m;i++)
      {
       c[i][0]=0;
      }
      for(int i=0;i<=n;i++)
      {
          c[0][i]=0;
      }
      for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
              if(wyraz1.charAt(i)==wyraz2.charAt(j))
              {
                  c[i+1][j+1]=c[i][j]+1;
                  b[i][j]="\\";
                  ///////////////

                  if (c[i + 1][j] == c[i][j + 1]) {
                      b[i][j] += ("|-");
                  } else if (c[i][j + 1] >= c[i + 1][j]) {
                      b[i][j] += ("|");
                  } else {
                      b[i][j] += ("-");
                  }
                  ///////////////
              }
              else {
                  if (c[i + 1][j] == c[i][j + 1]) {
                      c[i + 1][j + 1] = c[i][j + 1];
                      b[i][j] += ("|-");
                  } else if (c[i][j + 1] >= c[i + 1][j]) {
                      c[i + 1][j + 1] = c[i][j + 1];
                      b[i][j] += ("|");
                  } else {
                      c[i + 1][j + 1] = c[i + 1][j];
                      b[i][j] += ("-");
                  }
              }

          }
      }
      ////

//SZUKANIE MAX'A I WYPISYWANIE TABLICY
        //System.out.println();
        //NIE TRZEBA SZUKAC MAXA BO JEST W OSTATNIM WIERSZU OSTATNIEJ KOLUMNIE
        int max=0;
        for(int a1=0;a1<m+1;a1++){
            for(int a2=0;a2<n+1;a2++) {
                //System.out.print(c[a1][a2]+" ");
                if(c[a1][a2]>max) max=c[a1][a2];
            }
            //System.out.println();
            }
        //System.out.println(max);
        //System.out.println();
        for(int a1=0;a1<m;a1++){
            for(int a2=0;a2<n;a2++) {
                //System.out.print(b[a1][a2]+"   ");
            }
            //System.out.println();
        }
        //System.out.println();
        Set<String> lista = new TreeSet<String>();

        //wpisanie do tablicy najdluzsze ciagi bez powtorzen
        drukuj(wyraz1,wyraz2,b,m,n,max,"",lista);


        //wypisanie listy bez powtorzen
        for(String xyz: lista)
        {
            System.out.println(xyz);
        }


    }
    static void drukuj(String wyraz1, String wyraz2, String[][] b, int i, int j, int max, String tmp, Set<String> lista)
    {
        if(i==0 || j==0) {
            if(tmp.length()>=max) {
                StringBuilder tmp1 = new StringBuilder();
                tmp1.append(tmp);
                tmp1.reverse();
                //System.out.println(tmp1);
                lista.add(tmp1.toString());
            }
            return;
        }
        if(b[i-1][j-1].contains("\\"))
        {
            tmp+=wyraz1.charAt(i-1);
            drukuj(wyraz1,wyraz2,b,i-1,j-1,max,tmp,lista);
            tmp=tmp.substring(0, tmp.length() - 1);
        }
            if(b[i-1][j-1].contains("|")) {

                drukuj(wyraz1, wyraz2, b, i - 1, j, max, tmp,lista);
            }
            if(b[i-1][j-1].contains("-")) {
                drukuj(wyraz1, wyraz2, b, i, j - 1, max, tmp,lista);
            }
        }
    }

