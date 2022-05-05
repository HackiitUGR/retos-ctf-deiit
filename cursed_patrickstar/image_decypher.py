import cv2
import sys
import numpy as np

# Esta función aplica el padding a los números binarios y después descifra la imagen
# teniendo en cuenta la cantidad de bits aplicados
def bin_format_decypher(num, bits):

	num = num[2:]
	length = len(num)

	for i in range(8-length):
		num = '0' + num

	# Los bits menos significativos pasan a ser los más significativos
	# y se aplica un padding por la derecha
	num = num[8-bits:]

	for i in range(8-bits):
		num += '0'

	return num


print("                                                                         \n",
"███████ ████████ ███████ ██ ██ ████████          ██████ ████████ ███████ \n",
"██         ██    ██      ██ ██    ██            ██         ██    ██      \n",
"█████      ██    ███████ ██ ██    ██            ██         ██    █████   \n",
"██         ██         ██ ██ ██    ██            ██         ██    ██      \n",
"███████    ██    ███████ ██ ██    ██    ███████  ██████    ██    ██      \n",
"                                                                         \n")		

image = cv2.imread('cursed_patrickstar.png')

height = image.shape[0]
width = image.shape[1]

channels = 3 #RGB

print("Descifrando imagen...")

for bits in range(1, 8):
	new_image = np.zeros((height, width, channels), np.uint8)

	for i in range(height):
		for j in range(width):
			original_bits_r = bin_format_decypher(bin(image[i][j][0]), bits)
			original_bits_g = bin_format_decypher(bin(image[i][j][1]), bits)
			original_bits_b = bin_format_decypher(bin(image[i][j][2]), bits)

			new_image[i][j][0] = int(original_bits_r, 2)
			new_image[i][j][1] = int(original_bits_g, 2)
			new_image[i][j][2] = int(original_bits_b, 2)

	print("LSB que pasan a ser MSB: ", bits)
	cv2.imshow(str(bits) + "LSB", new_image)
	cv2.waitKey()
	cv2.destroyAllWindows()

#cv2.imwrite('./cursed_patrickstar.png', image)
