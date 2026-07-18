#ifndef USE_AFTER_FREE_H
#define USE_AFTER_FREE_H

#include <cstddef>

struct Data
{
    int *values;
    size_t size;
};

Data *create_data(size_t n);
void process_data(Data *d);

#endif // USE_AFTER_FREE_H