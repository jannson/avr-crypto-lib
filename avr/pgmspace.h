
/*
 * https://github.com/vancegroup-mirrors/avr-libc/blob/06cc6ff5e6120b36f1b246871728addee58d3f87/avr-libc/tests/simulate/progmem.h
*/

# define PROGMEM
# define PSTR(s)		(s)
# define pgm_read_byte(addr)	(*(unsigned char *)(addr))
# define pgm_read_word(addr)	(*(unsigned int *)(addr))
# define pgm_read_dword(addr)	(*(unsigned long *)(addr))
# define pgm_read_float(addr)	(*(float *)(addr))
# define pgm_read_qword(addr)	(*(unsigned long long *)(addr))
# define strlen_P		strlen
# define strcmp_P		strcmp
# define strcpy_P		strcpy
# define memcpy_P		memcpy
