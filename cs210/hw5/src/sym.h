#ifndef SYMTBL_H
#define SYMTBL_H

struct sym {
    char * name;
    double value;
    struct sym * next;
};

struct sym * SYM_LIST_HEAD;

void symInit(void);
struct sym * symLookup(char *);
void symPrint(void);
void symBubbleSort(void);
void symSwap(struct sym *,struct sym *,struct sym *);

#endif /* SYMTBL_H */
