#include <stdio.h>
#include <stdlib.h>

typedef struct _vElement {
    int value;
    struct _vElement *nextElement;
} vElement;

int main()
{
    vElement head_element;
    
    

    head_element.value = 7;
    head_element.nextElement = NULL;

    vElement current_element;
    vElement next_element;

    for (int i = head_element.value + 1; i < head_element.value + 11; i++ )
    {

        next_element.value = i;
        if (i == head_element.value + 1)
            head_element.nextElement = &next_element;
        else
            current_element.nextElement = &next_element;

        current_element = next_element;
    }

    current_element.nextElement = NULL;

    

    return 0;
}