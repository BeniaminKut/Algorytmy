package com.company;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;

public class Main {

    public static void main(String[] args) {
        Graph g = new Graph("macierzSasiedztw.txt");

        System.out.println("Przeszukiwanie grafu w glab");
        g.DFS();
        System.out.println();
        System.out.println("Przeszukiwanie grafu wszerz");
        g.BFS();
        System.out.println();
        System.out.println("//// WYPISANA MACIERZ SASIEDZTW ////");

        int[][] matrix = Graph.matrix("macierzSasiedztw.txt");
        for(int i = 0;i<matrix.length;i++){
            for(int j = 0;j<matrix.length;j++) {
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
            }

        System.out.println();
        System.out.println("//// WYPISANA LISTA SASIEDZTW ////");
        g.printList();
    }
}
    class Graph {
        private int V;   // ilosc wierzcholkow
        private LinkedList<Integer> adj[]; //Lista sasiedztw

        Graph(String fileName) {
            int[][] matrix = matrix(fileName);
            V = matrix.length;
            adj = new LinkedList[matrix.length];
            for (int i = 0; i < matrix.length; ++i)
                adj[i] = new LinkedList();
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix.length; j++) {
                    if (matrix[i][j] == 1) {
                        adj[i].add(j);
                    }
                }
            }
        }
        void BFS2(int s, boolean[] visited) {
            LinkedList<Integer> queue = new LinkedList<Integer>();

            if(!visited[s])
                 queue.add(s);
            visited[s] = true;

            while (queue.size() != 0) {
                s = queue.poll();
                System.out.print(s + " ");

                Iterator<Integer> i = adj[s].listIterator();
                while (i.hasNext()) {
                    int n = i.next();
                    if (!visited[n]) {
                        visited[n] = true;
                        queue.add(n);
                    }
                }
            }
        }
        void BFS(){
            boolean visted[] = new boolean[V];
            for(int i = 0;i<V;i++)
                BFS2(i,visted);
        }

        void DFSUtil(int v, boolean visited[]) {
            if(!visited[v])
            System.out.print(v + " ");
            visited[v] = true;

            Iterator<Integer> i = adj[v].listIterator();
            while (i.hasNext()) {
                int n = i.next();
                if (!visited[n]) {
                    DFSUtil(n, visited);
                    System.out.print(v + " ----"+n );

                }
            }
        }

        void DFS(){
            boolean visited[] = new boolean[V];
            for(int i = 0;i<V;i++)
                DFSUtil(i, visited);
        }

        public static int[][] matrix(String fileName) {
            FileReader plik = null;
            int[][] matrix = null;
            try {
                plik = new FileReader("./" + fileName);
                BufferedReader bufor = new BufferedReader(plik);
                String row;
                row = bufor.readLine();
                int N = Integer.parseInt(row);
                matrix = new int[N][N];
                for (int i = 0; i < N; i++) {
                    row = bufor.readLine();
                    for (int j = 0; j < N; j++) {
                        matrix[i][j] = Character.getNumericValue(row.charAt(j));
                    }
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return matrix;
        }
        public void printList(){
            for(int i=0;i<V;i++)
            {
                System.out.print(i);
                for(int j=0;j<adj[i].size();j++){
                    System.out.print("<--"+adj[i].get(j));
                }
                System.out.println();
            }
        }
    }


