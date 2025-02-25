#ifndef CACHE_H
#define CACHE_H

#include "moneyIntStr.h"

extern stringPtr originalProvider;

char* cacheMoneyIntStr(unsigned int moneyCents);
void freeCacheMoneyIntStr();

#endif // CACHE_H