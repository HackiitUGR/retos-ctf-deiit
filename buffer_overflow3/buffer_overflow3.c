#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>

__attribute__ ((force_align_arg_pointer)) // ignore this
void win() {
	system("cat flag.txt");
}

int main() {
	setbuf(stdout, NULL);

	unsigned int value = 0;
	char answer[10];

	printf("Esta vez es imposible...\n");
	fgets(answer, 0x20, stdin);
	printf("y ahora qué?\n");
}