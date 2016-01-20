#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <linux/limits.h> // for_PATH_MAX

#include "lib/lib.h"


int main(int argc, char *argv[])
{

int alloclen = 128; 
int i = 0;
char pathbuf[PATH_MAX];

	
	for (i = 1; i < argc; i++) {
	char *s;
	ssize_t len, buflen;
	char *bufSL;
	
	if (check_pid_argument(argv[i]) == 0 )
		buflen = 10 + strlen(argv[i]) + 1; 
		/* Constant 10 is the length of strings "/proc/" + "/cwd" + 1 \0 simbol */
	

		bufSL = malloc(buflen);
		snprintf(bufSL, buflen, "/proc/%s/cwd", argv[i]); 
		printf("bufSL = %s\n", bufSL);

		printf("pathbuf= %s: \n", pathbuf);
		len = readlink(bufSL, pathbuf, PATH_MAX);
	
		free(bufSL);

		printf("pathbuf= %s: \n", pathbuf);
			pathbuf[len]='\0';
			s = pathbuf;
		

		printf("%s: %s\n", argv[i], s );
	}
	
	
	
	return 0;
}
