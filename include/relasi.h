#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "dosen.h"
#include "mahasiswa.h"
using namespace std;

#define nextDosen(P) P->nextDosen
#define nextMhs(P) P->nextMhs
#define dosen(P) P->dosen
#define mahasiswa(P) P->mahasiswa

typedef struct elmlist_relasi *address_relasi;






#endif