#ifndef DOSEN_H_INCLUDED
#define DOSEN_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

struct dosen {
    string nama;
    string nip;
    string keahlian;
};

typedef dosen infotype_dosen; 
typedef struct elmlist_dosen *address_dosen;

struct elmlist_dosen { 
    infotype_dosen info;
    address_dosen next;
    address_dosen prev;
};

struct List_dosen {
    address_dosen first;
    address_dosen last;
};

#endif