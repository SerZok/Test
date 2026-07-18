// CWE-416: Использование после освобождения (use-after-free)
#include "use_after_free.h"
#include <iostream>

Data *create_data(size_t n)
{
    Data *d = new Data;
    d->values = new int[n];
    d->size = n;
    return d;
}

void process_data(Data *d)
{
    delete[] d->values;
    delete d;
    // Уязвимость: обращение к освобождённой памяти
    std::cout << "Размер после освобождения: " << d->size << std::endl; // ПЛОХО: use-after-free
}