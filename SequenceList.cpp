//
// Created by 何翔宇 on 2021/8/19.
//

#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "SequenceList.h"

Status InitList_Sq(SqList *L)
{

    (*L).elem=(LElemType_Sq*) malloc(LIST_INIT_SIZE*sizeof(LELEMTYPE_SQ));
    if(!(*L).elem)
        exit(OVERFLOW);
    (*L).length=0;
    (*L).listsize=LIST_INIT_SIZE;

    return OK;
}

void ClearList_Sq(SqList *L)
{
    (*L).length=0;
}

void DestroyList_Sq(SqList *L)
{
    free((*L).elem);

    (*L).elem=NULL;
    (*L).length=0;
    (*L).listsize=0;
}

Status ListEmpty_Sq(SqList L)
{
    return L.length==0?TRUE:FALSE;
}

int ListLength_Sq(SqList L)
{
    return L.length;
}

Status GetElem_Sq(SqList L,int i,LElemType_Sq *e)
{
    if(i<1||i>L.length)
        return ERROR;
    else
        *e=L.elem[i-1];

    return OK;
}

int LocateELem_Sq(SqList L,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq))
{
    int i=1;
    while(i<L.length&&!Compare(e,L.elem[i-1]))
        ++i;
    if(i<=L.length)
        return i;
    else
        return 0;
}

Status PriorElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *pre_e)
{
    int i=1;
    if(L.elem[0]!=cur_e)
    {
        while(i<L.length&&L.elem[i]!=cur_e)
            ++i;
        if(i<L.length)
        {
            *pre_e=L.elem
        }

    }
}