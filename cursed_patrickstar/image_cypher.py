import cv2
import sys
import numpy as np

# Le aplicamos un padding a los números binarios para que tengan exactamente 8 bits
def bin_format(num):

	num = num[2:]
	length = len(num)

	for i in range(8-length):
		num = '0' + num

	return num

# Comprobamos que se ha pasado la cantidad correcta de bits a coger de la flag
if(len(sys.argv) != 2):
	print("\nUsage: python3 image_cypher.py <number of bits>\n")
	exit()

# Almacenamos en esta variable los bits a codificar
bits = int(sys.argv[1])

# Leemos las dos imágenes, la que se llama "original" es la que va a contener la imagen con la flag
original = cv2.imread('image.png')
flag = cv2.imread('image2.png')

# Puesto que es necesario que la imagen con la flag sea como mucho tan grande como la imagen que la va a contener,
# hacemos esta comprobación
if(original.shape[0] < flag.shape[0] or original.shape[1] < flag.shape[1]):
	print("\nLa imagen con la flag debe ser mas pequeña que la imagen que la va a contener.\n")
	print("Tamaños actuales:")
	print("   Imagen sin flag -> ", str(original.shape[0]) + "x" + str(original.shape[1]))
	print("   Imagen con flag -> ", str(flag.shape[0]) + "x" + str(flag.shape[1]) + "\n")
	exit()

# Almacenamos los tamaños de ambas imagenes
original_height = original.shape[0]
original_width = original.shape[1]

flag_height = flag.shape[0]
flag_width = flag.shape[1]

channels = 3 #RGB

# Creamos la imagen nueva inicialmente en negro
new_image = np.zeros((original_height, original_width, channels), np.uint8)

# Vamos rellenando la imagen nueva
for i in range(original_height):
	for j in range(original_width):

		# Unimos las dos imagenes, si estamos en un pixel que no estamos en la flag, lo rellenamos con
		# los pixeles originales al completo
		if(i < flag_height and j < flag_width):
			original_bits_r = bin_format(bin(original[i][j][0]))
			original_bits_g = bin_format(bin(original[i][j][1]))
			original_bits_b = bin_format(bin(original[i][j][2]))

			flag_bits_r = bin_format(bin(flag[i][j][0]))
			flag_bits_g = bin_format(bin(flag[i][j][1]))
			flag_bits_b = bin_format(bin(flag[i][j][2]))

			new_image[i][j][0] = int(original_bits_r[0:8-bits] + flag_bits_r[8-bits:8], 2)
			new_image[i][j][1] = int(original_bits_g[0:8-bits] + flag_bits_g[8-bits:8], 2)
			new_image[i][j][2] = int(original_bits_b[0:8-bits] + flag_bits_b[8-bits:8], 2)
		else:
			new_image[i][j] = original[i][j]


# Por ultimo, guardamos la imagen 
cv2.imwrite('./cursed_patrickstar.png', new_image)
