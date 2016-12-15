#ifndef CHAINON_HPP
#define CHAINON_HPP
#include <stdlib.h>


typedef struct Chainon
{
    void* data;
    struct Chainon* pointer;
    struct Chainon* precedent;

} Chainon;

// Prive, Ne pas Utiliser
void Link(Chainon *last,Chainon *next);
Chainon* GetNext(Chainon* occurence);
Chainon* GetPrevious(Chainon* occurence);
Chainon* GetLast(Chainon* first);
Chainon* Get(Chainon* first,int t);

// Public, A Utiliser
Chainon* ChainonCreate(void *element);
void ChainonAdd(Chainon *first,void *elemente);
void* ChainonAccess(Chainon *first, int t);
void ChainonDelete(Chainon *first, int t);
int ChainonGetSize(Chainon *first);
void ChainonFree(Chainon *first);
void ChainonInsert(Chainon *first,int t,void *element);


#endif // CHAINON_HPP
