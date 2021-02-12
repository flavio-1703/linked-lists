#include <stdio.h>
#include <stdio.h>

typedef struct record
{
    float value;
    int next;
}record;

typedef struct list
{
    int first;
    int free;
    int size;
    record* buffer;
}list;

//initializing the list
void init(list* ptr, int size)
{
    //allocating the memory
    ptr->buffer = (record*)malloc(size*sizeof(record));
    //size will be equal to the parameter given
    ptr->size = size;
    ptr->first = ptr->size;
    ptr->free = 0;

    for(int count = 0; count < ptr->size; count++)
    {
        ptr->buffer[count].next = count + 1;
    }
}

//iterating through the list
void iterate(list* ptr)
{
    //keeping track of our position
    int pos;

    pos = ptr->first;

    while (pos != ptr->size)
    {
        printf("%f", ptr->buffer[pos].value);
        pos = ptr->bufferp[pos].next;
    }
}

//search the list
Boolean search(list* ptr, float value)
{
    int pos = ptr->first;
    Boolean found = FALSE;
    
    while (found == FALSE && pos != ptr->size)
    {
        if(ptr->bufferp[pos].value = value)
        {
            found = TRUE;
        }
        else
        {
            pos = ptr->buffer[pos].next;
        }
    }    
}

//insert an element in the head of the list
Boolean head_insert(list* ptr, float value)
{
    int moved;

    if(ptr->free != ptr->size)
    {
        moved = ptr->free
        ptr->free = ((ptr->buffer)[ptr->free]).next;

        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = ptr->first;
        ptr->first = moved;

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//insert an element at the end of the list
Boolean tail_insert(list* ptr, float value)
{
    int moved;
    int *pos_ptr;

    if(ptr->free != ptr->size)
    {
        moved = ptr->free;
        ptr->free = ((ptr->buffer)[ptr->free]).next;

        pos_ptr = &ptr->first;

        while (*pos_ptr != ptr->size)
        {
            pos_ptr = &(ptr->buffer[*pos_ptr].next);
            *pos_ptr = moved;
            ptr->buffer[moved].value = value;
            ptr->buffer[moved].next = ptr->size;
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}

//insert an element in an ordered list
//the list must be ordered already
Boolean ord_insert(list* ptr, float value)
{
    int moved;
    int *pos_ptr;

    if(ptr->free != ptr->size)
    {
        moved = ptr->free;
        ptr->free = ((ptr->buffer)[ptr->free]).next;

        pos_ptr = &ptr->first;

        while (*pos_ptr != ptr->size && ptr->buffer[*pos_ptr].value < value)
        {
            pos_ptr = &(ptr->buffer[*pos_ptr].next);
            ptr->buffer[moved].value = value;
            ptr->buffer[moved].next = *pos_ptr;
            *pos_ptr = moved;
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
