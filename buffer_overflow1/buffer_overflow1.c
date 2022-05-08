#include <stdio.h>
#include <stdlib.h>

void win() {
	system("cat flag.txt");
}

int main() {
	setbuf(stdout, NULL);

	unsigned int value = 0;
	char answer[10];

	printf("Sabes cómo funciona la stack?\n");
	fgets(answer, 12, stdin);

	if (value == 0) {
		printf("Ya veo que no mucho..\n");
	} else if (value != 0x58) {
		printf("Va mejorando la cosa: %08x\n", value);
	} else {
		printf("Yayyy!\n");
		win();
	}
}