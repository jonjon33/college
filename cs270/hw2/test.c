#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **str1;
    char str2[] = "test str";
    char str3[] = "another str";

    printf("1\n");
    str1[0] = malloc(sizeof(str2));
    //str1[0] = str2;
    printf("2\n");
    strcpy(str1[0],str2);
    printf("3\n");

    printf("%s\n",str1[0]);

    return 0;
}
