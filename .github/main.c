#include <stdio.h> // printf, scanf_s
#include "cache.h"

int main(int argc, char*argv[]) {
	provider = cacheMoneyIntStr; // remove this line to use uncached version

	unsigned int moneyCents = 0;
	while ((scanf_s("%u", &moneyCents) != EOF)) {
		char* moneyStr = provider(moneyCents);
		printf("Money: %u = %s\n", moneyCents, moneyStr);
	}
	freeCacheMoneyIntStr();
}