#include "chainon.h"


void Link(Chainon *last,Chainon *next)
{
    if(last != NULL)
    (*last).pointer = next;
    if(next != NULL)
    (*next).precedent = last;
}

Chainon* GetNext(Chainon* occurence)
{
    if(occurence != NULL)
    return occurence->pointer;
    else
    return NULL;
}

Chainon* GetPrevious(Chainon* occurence)
{
    if(occurence != NULL)
    return occurence->precedent;
    else
    return NULL;
}

Chainon* GetLast(Chainon* first)
{
    Chainon *last= first;
    Chainon *previous = NULL;
    while(last != NULL)
    {
        previous = last;
        last = GetNext(last);
    }
    return previous;
}

Chainon* Get(Chainon* first,int t)
{
    int i=0;
    Chainon *last= first;
    Chainon *previous = NULL;
    for(i=0; i<=t; i++)
    {
        previous = last;
        last = GetNext(last);
    }
    return previous;
}




Chainon* ChainonCreate(void* element)
{
    Chainon* tmp = malloc(sizeof(Chainon));
    tmp->data = element;
    tmp->precedent = NULL;
    tmp->pointer = NULL;
    return tmp;
}

void ChainonAdd(Chainon *first, void *elemente)
{
    Chainon *last = GetLast(first);
    Chainon* tmp = malloc(sizeof(Chainon));
    Link(last,tmp);
    tmp->data = elemente;
    tmp->pointer = NULL;

}

void ChainonInsert(Chainon *first,int t,void *element)
{
    Chainon *last = Get(first,t);
    Chainon *next = GetNext(last);
    Chainon* tmp = malloc(sizeof(Chainon));
    Link(tmp,next);
    Link(last,tmp);
    tmp->data = element;
}

void *ChainonAccess(Chainon *first, int t)
{
    Chainon *last = Get(first,t);
    return (last->data);
}

void ChainonDelete(Chainon *first, int t)
{
    if(t != 0)
    {
    Chainon *last = Get(first,t);
    Chainon *previous = GetPrevious(last);
    Chainon *next = GetNext(last);
    free(last->data);
    free(last);
    Link(previous,next);
    }
}

int ChainonGetSize(Chainon *first)
{
    Chainon *last = first;
    int i = -1;
    while(last != NULL)
    {
        i++;
        last = GetNext(last);
    }
    return i+1;
}

void ChainonFree(Chainon *first)
{
    int i = ChainonGetSize(first) - 1;
    while(i > 0)
    {
        ChainonDelete(first,i);
        i--;
    }
    free(first);
}

