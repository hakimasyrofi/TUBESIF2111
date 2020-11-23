/*	Nama : Muhammad Asyrofi Al Hakim
	NIM	: 18219049
*/

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X, int prio){
	*P = (address) malloc(sizeof(ElmtQueue));

    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
        Prio(*P) = prio;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X,
        Next(P)=Nil, dan Prio(P)=prio */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address  P){
	free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty (Queue Q){
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q){
	if (IsEmpty(Q))
    {
        return 0;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue * Q){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = Nil dan Tail(Q) = Nil) */
/*** Primitif Add/Delete ***/
void Enqueue (Queue * Q, infotype X, int prio){
	address P;
	/* Algoritma */
	Alokasi(&P,X,prio);
	if (P != Nil) {
	if (IsEmpty(*Q)) {
		Head(*Q) = P;
	} 
	else {
		Next(Tail(*Q)) = P;
	}
	Tail(*Q) = P;
	}
}
/* Proses: Mengalokasi X dan menambahkan X pada posisi setelah element dengan 
   prioritas yang lebih tinggi/sama, dan sebelum element dengan prioritas yang 
   lebih rendah jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X diletakkan setelah setelah element dengan prioritas yang lebih 
   tinggi/sama, dan sebelum element dengan prioritas yang lebih rendah.
   Apabila X diletakkan di posisi terakhir, maka TAIL = element X. */
void Dequeue (Queue * Q, infotype * X){
	address P;
	/* Algoritma */
	*X = InfoHead(*Q);
	P = Head(*Q);
	Head(*Q) = Next(Head(*Q));
	if (Head(*Q)==Nil) {
		Tail(*Q) = Nil;
	}
	Next(P) = Nil;
	Dealokasi(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

