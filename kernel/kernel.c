#include<stdio.h>
#include<string.h>
#include <stdbool.h>

bool compKey(char key[], char read[]);
void cyclic_xor(char key[]);

char flag[] = {0x12,0x1b,0x1c,0x1d,0x10,0x3,0x34,0x1d,0x67,0x2f,0x32,0x3d,0x3c,0x67,0x3d,0x8,0x2c,0x7b,0x20,0x6,0x10,0x7f,0x3b,0xb,0x2e,0x38,0x7f,0x1b,0x2d,0x6a,0x33,0x32};

int main(){

char key[] = "WOOTY";
char read[10];

printf("                                                                         \n"
"███████ ████████ ███████ ██ ██ ████████          ██████ ████████ ███████ \n"
"██         ██    ██      ██ ██    ██            ██         ██    ██      \n"
"█████      ██    ███████ ██ ██    ██            ██         ██    █████   \n"
"██         ██         ██ ██ ██    ██            ██         ██    ██      \n"
"███████    ██    ███████ ██ ██    ██    ███████  ██████    ██    ██      \n"
"                                                                         \n");

printf(
"Bienvenido CTFnauta, hemos encontrado al gato Kernel,\n" 
"pero está en peligro :c, ha sido capturado por un grupo \n"
"de ex-estudiantes de la ETSIIT que buscan legitimar su \n"
"dolor empleando al gato como mártir.\n\n"
);


printf("     __,_____    _                _._     _,-'\"\"`-._\n"
"    / __.==--\"  |_D               (,-.`._,'(       |\\`-/|\n"
"   /#(-'                               `-.-' \\ )-`( , o o)\n"
"   `-'                                       `-    \\`_`\"'-\n");


printf(
"\nKernel corre peligro, pero hay una oportunidad de salvarlo,\n"
"adivina la palabra secreta que hará que el gato Kernel se\n"
"teletransporte a un lugar seguro, dispones de 3\n"
"intentos antes de que los ex-estudiantes acaben con \n" 
"él, ¡confiamos en ti!\n"
);

printf("\nClave: ");
scanf("%s", read);

if(compKey(key, read)){
	return 0;
}

printf("     __,_____          _          _._     _,-'\"\"`-._\n"
"    / __.==--\"        |_D         (,-.`._,'(       |\\`-/|\n"
"   /#(-'                               `-.-' \\ )-`( , o o)\n"
"   `-'                                       `-    \\`_`\"'-\n");

printf("\n¡Noo!, esa no es la clave, te quedan 2 intentos\n");

printf("\n\nClave: ");
scanf("%s", read);

if(compKey(key, read)){
	return 0;
}

printf("     __,_____                _    _._     _,-'\"\"`-._\n"
"    / __.==--\"              |_D   (,-.`._,'(       |\\`-/|\n"
"   /#(-'                               `-.-' \\ )-`( , o o)\n"
"   `-'                                       `-    \\`_`\"'-\n");

printf("\n¡POR FAVOR, INTENTALO MÁS FUERTE, KERNEL CORRE PELIGRO!\n");

printf("\n\nClave: ");
scanf("%s", read);

if(compKey(key, read)){
	return 0;
}

printf("\n\nKernel ha fallecido, para ganar 3 intentos extra\n"
"inserta 1 moneda y ejecuta el comando ./kernel\n\n");


printf("      .-\"\"\"\"\"\"-.\n"
"    .'          '.\n"
"   /   O      O   \\\n"
"  :           `    :\n"
"  |                |\n"   
"  :    .------.    :\n"
"   \\  \'        \'  /\n"
"    '.          .'\n"
"      '-......-'\n\n");

return 0;

}

bool compKey(char key[], char read[]){

	if(strcmp(key, read) == 0){
		printf("\n¡Enhorabuena, salvaste al gato Kernel!, antes de irse\n"
		"te ha dejado un regalo ;D\n\n");

		cyclic_xor(key);
		printf("%s\n\n", flag);

		return true;
	}

	return false;
}

void cyclic_xor(char key[]){
	int length = sizeof(flag) / sizeof(char);
	for(int i = 0; i < length; i++){
		flag[i] = flag[i] ^ key[i%5];
	}
}