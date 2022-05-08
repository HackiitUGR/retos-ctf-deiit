#include <stdio.h>
#include <stdlib.h>

void win() {
	system("cat flag.txt");
}

int main() {
	setbuf(stdout, NULL);

	unsigned int value = 0;
	char answer[10];

	printf("Esta vez no te será tan fácil\n");
	fgets(answer, 0x10, stdin);

	if (value == 0) {
		printf("Lo estás intentando de verdad?\n");
	} else if (value != 0x00004142) {
		printf("Va mejorando la cosa: %08x\n", value);
	} else {
		printf("Yayyy!\n");
		win();
	}
}