/* File header: graph.h */

#ifndef GRAPH_H
#define GRAPH_H

#include "../boolean/boolean.h"
#include "../listlinier/listlinier.h"

#define Nil NULL

typedef struct tElmtGraph *addrGraph;

typedef struct tElmtGraph {
  int infoG;
  addrGraph NextParent;
  addrGraph2 FirstChild;
} ElmtGraph;

typedef struct {
  addrGraph FirstG;
} Graph;

/* Definisi Graph :
  Graph utama (G) kosong : FirstG(G) = Nil
  Graph anak (G2) kosong : FirstChild(G2) = Nil
/* Setiap elemen dengan addrGraph P dapat diacu InfoG(P), NextP(P), FirstChild(P) */
/* Setiap elemen dengan addrGraph2 P2 dapat diacu InfoG2(P2), NextChild(P2) */
/* Elemen terakhir graph utama : jika addressnya Last, maka Next(Last)=Nil */
/* Elemen terakhir graph anak  : jika addressnya Last2, maka Next(Last2)=Nil */


/* ********** SELEKTOR ********** */
#define InfoG(P)      (P)->infoG
#define NextP(P)      (P)->NextParent
#define FirstChild(P) (P)->FirstChild
#define InfoG2(P2)    (P2)->infoG2
#define NextChild(P2) (P2)->NextChild
#define FirstG(L)     ((L).FirstG)

/* ********** KONSTRUKTOR ********** */
void MakeEmptyGraph (Graph * G);
/* Konstruktor : create Graph kosong  */
/* I.S. sembarang */
/* F.S. Terbentuk graph kosong */

/****************** Manajemen Memori ******************/

addrGraph AlokasiGraph1 (urutan X);
/* Mengirimkan addrGraph hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrGraph tidak Nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil, FirstChild(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiGraph1 (addrGraph * G);

/* I.S. P terdefinisi; */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrGraph1 P */

boolean IsEmptyGraph (Graph G);

/* *** Test tabel penuh *** */

boolean IsFullGraph (Graph G);
/* Mengirimkan true jika Graph G penuh, mengirimkan false jika tidak */

boolean IsEmptyParent (addrGraph P);
/* Mengirimkan true jika addrGraph P kosong, mengirimkan false jika tidak */

/* ********** KELOMPOK BACA/TULIS ********** */

void BacaGraph (Graph * G);
/* I.S. Graph G terdefinisi */
/* F.S. Graph G berisi hubungan-hubungan antar bangunan */

void TulisGraph (Graph G);
// ! Ingat MakeEmptyGraph dan AddParent dulu
// TODO: Prosedur ini dimasukkan ke ADT Mesin Kata

/* I.S. G terdefinisi */
/* F.S. Hubungan antar bangunan ditampilkan ke layar.
        Jika tidak ada hubungan maka muncul '0' di layar.
        Jika ada hubungan maka muncul '1' di layar.       */
/* Contoh: menulis matriks 3x3
0 1 1
1 0 0
1 0 0
*/

int NbElmtGraph (Graph G);
/* Mengirimkan banyaknya elemen parent graph; mengirimkan 0 jika graph kosong */

#endif
