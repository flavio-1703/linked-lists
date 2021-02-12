#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    float value;
    list * next_ptr;
}list;

//initalize list
void init(list** ptrptr)
{
    //node to null
    *ptrptr = NULL;
}

//iterate through the list
void iterate(list* ptr)
{
    while (ptr != NULL)
    {
        printf("%f", ptr->value)
        ptr = ptr->next_ptr;
    }
}

//search the list
Boolean search(list* ptr, float value, list** ptrptr)
{
   Boolean found = FALSE;

   while (ptr != && found == FALSE)
   {
       if(ptr->value == value)
       {
           found == TRUE;
           *ptrptr = ptr;
       }
       else
       {
           ptr = ptr->next_ptr;
       }
   }
   return found;
}

//insert an element to the head of the list
void head_insert(list** ptrptr, float value)
{
    list* tmp_ptr;

    tmp_ptr = *ptrptr;
    *ptrptr = (list*)malloc(sizeof(list));
    (*ptrptr)->value = value;
    (*ptrptr)->next_ptr = tmp_ptr;
}

//remove the first element (head) from the list
Boolean consume_first(list** ptrptr, float value, float* value_ptr)
{
    list* tmp_ptr;

    if(*ptrptr != NULL)
    {
        *value_ptr = (*ptrptr)->value;
        tmp_ptr = *ptrptr;
        free(tmp_ptr);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//inserrt an element at the end of the list
Boolean tail_insert(list** ptrptr, float value)
{
    //slides to the end of the list and inserts the element
    while (*ptrptr != NULL)
    {
        ptrptr = &((*ptrptr)->next_ptr);
    }
    head_insert(ptrptr, value);
}

//insert an ordered element in an ordered list
//list is assumed to be ordered
void ord_insert(list** ptrptr, float value)
{
    while (*ptrptr != NULL && (*ptrptr)->value < value)
    {
        ptrptr = &((*ptrptr)->next_ptr);
    }
    head_insert(ptrptr, value);
}