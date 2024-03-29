#include <stdio.h>
#include <stdlib.h>
#include <string.h> //nice for substrings

int main(int argc, char *argv[]){
	FILE *fp = NULL;
	char *line = NULL;
	size_t linecap = 0;

    if (argc <= 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    if (argc >= 3 && (fp = fopen(argv[2], "r")) == NULL) {
        printf("wgrep: cannot open file\n");
        exit(1);
    }

    if (argc == 2)
        fp = stdin;

    while (getline(&line, &linecap, fp) > 0)
        if (strstr(line, argv[1]))
            printf("%s", line);

    fclose(fp);
    return 0;
}
