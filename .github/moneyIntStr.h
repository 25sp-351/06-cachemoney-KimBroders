#ifndef MONEYINTSTR_H
#define MONEYINTSTR_H

// a type for it
typedef char* (*stringPtr)(unsigned int cents);

extern stringPtr provider;

char* moneyIntStr(unsigned int moneyCents);

#endif // MONEYINTSTR_H