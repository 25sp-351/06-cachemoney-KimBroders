#include <stdio.h> // printf_s, scanf_s, gets, NULL
#include <string.h> // strcpy_s, strcat_s, strlen
#include <stdlib.h> // malloc, free
#include "cache.h"
#define CACHE_SIZE 150000

stringPtr originalProvider = moneyIntStr;
static char* moneyStr[CACHE_SIZE] = {NULL};

char* cacheMoneyIntStr(unsigned int moneyCents) { // Caches the result of moneyIntStr to avoid recomputation
	if (moneyCents >= sizeof(moneyStr)/sizeof(moneyStr[0]))
		return originalProvider(moneyCents);
	
	if (moneyStr[moneyCents] == NULL) {
		char* pStr = originalProvider(moneyCents);
		unsigned lenStr = strlen(pStr) + 1;
		moneyStr[moneyCents] = (char*)malloc(lenStr);
		strcpy_s(moneyStr[moneyCents], lenStr, pStr);
	}
	return moneyStr[moneyCents];
}

void freeCacheMoneyIntStr() {
	for (unsigned i = 0; i < sizeof(moneyStr)/sizeof(moneyStr[0]); i++) {
		if (moneyStr[i] != NULL) {
			free(moneyStr[i]);
			moneyStr[i] = NULL;
		}
	}
}