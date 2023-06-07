#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DynamicArr_t
{
    int *_arr;
    unsigned _size, _capacity;
}dynamicArr;

void dArr_init(dynamicArr *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

bool dArr_isEmpty(dynamicArr *darray)
{
    return (darray->_size == 0);
}

void dArr_pushBack(dynamicArr *darray, int value)
{
    if(darray->_size + 1 > darray->_capacity)
    {
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        int i;
        for(i = 0; i < darray->_size; i++)
            newArr[i] = darray->_arr[i];

        int *oldArr = darray->_arr;
        darray->_arr = newArr;
        free(oldArr);
    }
    darray->_arr[darray->_size++] = value;
}

void dArr_popBack(dynamicArr *darray)
{
    if(!dArr_isEmpty(darray))
    {
        darray->_size--;
    }
    else return;
}

int dArr_back(dynamicArr *darray)
{
    if(!dArr_isEmpty(darray)) return darray->_arr[darray->_size - 1];
    else return 0;
}

int dArr_front(dynamicArr *darray)
{
    if(!dArr_isEmpty(darray)) return darray->_arr[0];
    else return 0;
}

void dArr_insertAt(dynamicArr *darray, unsigned index, int value)
{
    if(index >= darray->_size) index = darray->_size;
    if(darray->_size + 1 > darray->_capacity)
    {
        darray->_capacity *= 2;
        int *newArr = (int *)malloc(sizeof(newArr) * darray->_capacity);
    }
        if(!dArr_isEmpty(darray))
        {
            int *newArr = (int *) malloc(sizeof(newArr));
            int i, j = 0;

            for(i = 0; i < darray->_size + 1; i++)
            {
                if(i == index) 
                {
                    newArr[i] = value;
                }
                else 
                {   
                    newArr[i] = darray->_arr[j];
                    j++;
                }
            }
            int *oldArr = darray->_arr;
            darray->_arr = newArr;
            free(oldArr);
    }
            darray->_size++;
}

void dArr_removeAt(dynamicArr *darray, int index)
{
    if(!dArr_isEmpty(darray))
    {
        int *newArr = (int*) malloc(sizeof(newArr));
        int i, j = 0;
        for(i = 0; i < darray->_size; i++)
        {
            if(i == index) continue;
            else 
            {
                newArr[j] = darray->_arr[i];
                j++;
            }
        }
        int *oldArr = darray->_arr;
        darray->_arr = newArr;
        free(oldArr);
        darray->_size--;
    }
}

void dArr_setAt(dynamicArr *darray, unsigned index, int value)
{
    if(!dArr_isEmpty(darray))
    {
    if(index + 1 >= darray->_size)
        darray->_arr[darray->_size - 1] = value;
    else darray->_arr[index] = value;
    }
}

int dArr_getAt(dynamicArr *darray, unsigned index)
{
    if(!dArr_isEmpty(darray))
    {
        if(index + 1 >= darray->_size)
            return darray->_arr[darray->_size - 1];
        else return darray->_arr[index];
    }
}

int main()
{
    dynamicArr myArr;
    dArr_init(&myArr);

    dArr_pushBack(&myArr, 1);
    dArr_pushBack(&myArr, 6);
    dArr_pushBack(&myArr, 8);
    dArr_pushBack(&myArr, 7);

    dArr_insertAt(&myArr, 10, 5);
    int i;
    for(i = 0; i < myArr._size; i++)
    {
        printf("%d ", dArr_getAt(&myArr, i));
    }

    printf("\nBack \t : %d\n", dArr_getAt(&myArr, myArr._size - 1));
    printf("Front \t : %d\n", dArr_getAt(&myArr, 0));
    
    dArr_setAt(&myArr, 1, 12);
    

    while(!dArr_isEmpty(&myArr))
    {
        printf("%d ", dArr_back(&myArr));
        dArr_popBack(&myArr);
    }

}
