/* File header: graph.c */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "graph.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Graph kosong  */
void MakeEmptyGraph (Graph * G) {
  /* KAMUS LOKAL */

  /* ALGORITMA */
  FirstG(*G) = Nil;
}

/****************** Manajemen Memori ******************/
addrGraph AlokasiGraph1 (urutan X) {
  /* KAMUS LOKAL */
  addrGraph P;
  /* ALGORITMA */
  P = (addrGraph) malloc (sizeof(ElmtGraph));
  //P = malloc (sizeof(addrGraph));
  if (P != NULL) {
    InfoG(P) = X;
    NextP(P) = Nil;
    FirstChild(P) = Nil;
  } else /* P == NULL */ {
    P = Nil;
  }
  return P;
}


void DealokasiGraph1 (addrGraph * G) {
/* I.S. P terdefinisi; */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrGraph P */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  free(*G);
}


/* ********** TEST GRAPH KOSONG ********** */
boolean IsEmptyGraph (Graph G) {
/* Mengirimkan true jika Graph G kosong, mengirimkan false jika tidak */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (FirstG(G) == Nil);
}

boolean IsEmptyParent (addrGraph P) {
/* Mengirimkan true jika addrGraph P kosong, mengirimkan false jika tidak */

  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (FirstChild(P) == Nil);
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaGraph (Graph * G);
// ! Ingat MakeEmptyGraph dulu
// TODO: Prosedur ini dimasukkan ke ADT Mesin Kata
/* I.S. Graph G terdefinisi */
/* F.S. Graph G berisi hubungan-hubungan antar bangunan */

void TulisGraph (Graph G) {
// ? Untuk debugging doang kayaknya
  /* KAMUS LOKAL */
  IdxType i, j;
  addrGraph P;
  addrGraph2 C;

  /* ALGORITMA */
  i = 1;

  while (i <= NbElmtGraph(G)) {
    P = SearchP(G, i);
    j = 1;

    while (j < NbElmtGraph(G)) {
      C = SearchChild(P, j);

      if (C != Nil) {
        printf("1 ");
      } else /* C == Nil */ {
        printf("0 ");
      }

      j++;
    }

    C = SearchChild(P, j);
    if (C != Nil) {
      printf("1\n");
    } else /* C == Nil */ {
      printf("0\n");
    }

    i++;
  }
}

/****************** PROSES SEMUA ELEMEN PARENT GRAPH ******************/
int NbElmtGraph (Graph G) {
/* Mengirimkan banyaknya elemen parent graph; mengirimkan 0 jika graph kosong */

  /* KAMUS LOKAL */
  addrGraph P;
  int total;

  /* ALGORITMA */
  if (IsEmptyGraph(G)) {
    return 0;
  } else /* !IsEmptyGraph(G) */ {
    P = FirstG(G);
    total = 0;
    while (P != Nil) {
      P = NextP(P);
      total++;
    }
    return total;
  }
}
