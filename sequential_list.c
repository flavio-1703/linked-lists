#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int size;
    int head;
    int tail;
    float* buffer;
}list;

//init the list, giving it a size
void init(list* ptr, int size)
{
    //allocating the memory
    ptr->buffer = (float*)malloc(size*sizeof(float));
    //setting the size to the parameter
    ptr->size = size;
    //init the head and tail to 0
    ptr->head = 0;
    ptr->tail = 0;
}

//instert a value at the end(tail) of the list
Boolean tail_instert(list* ptr, float value)
{
    //first we check that the position next to tail
    //is not equal to the head
    if( ((ptr->tail + 1)%ptr->size) != ptr->head)
    {
        //we inster the value in the buffer
        ptr->buffer[ptr->tail] = value;
        //move the tail next
        ptr->tail = (ptr->tail + 1)%ptr->size;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//Iterate through the list
void iterate(list* ptr)
{
    //keepin track of our position
    int pos;
    //we start at the head and check if we have not reach the end(tail)
    for(pos = ptr->head; pos != ptr->tail; pos = (pos + 1)%ptr->size)
    {
        //we print the visited element
        printf("%f", ptr->buffer[pos]);
    }
}

//Search the list
Boolean search(list* ptr, float value)
{
    Boolean found;
    int pos;
    //we simply iterate through the list until we find the element
    //starting at the head
    pos = ptr->head;
    found = FALSE;

    while (found == FALSE && pos != ptr->tail)
    {
        //if the value of the parameter is the same as
        //the value of the list we have found our element
        if(ptr->buffer[pos] == value)
        {
            found = TRUE;
        }
        //else we just keep iterateng
        else
        {
            pos = (pos + 1)%ptr->size;
        }
    }
}