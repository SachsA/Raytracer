/*
** lib_bmp.h for wolf3d in /home/lombar_e/rendu/Infographie/wolf3d
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Tue Jan 03 10:02:50 2017 Thomas Lombard
** Last update Fri May 26 05:22:30 2017 Theodore Marestin
*/

#ifndef LIB_BMP_H_
# define LIB_BMP_H_

# if !defined (__LITTLE_ENDIAN__) && !defined (__BIG_ENDIAN__)
#  define __LITTLE_ENDIAN__
# endif /* ! __LITTLE_ENDIAN__ && __BIG_ENDIAN__ */

# ifdef __LITTLE_ENDIAN__
#  define SIGN_SUPPORT 0x4d42
# else
#  define SIGN_SUPPORT 0x424d
# endif /* ! __LITTLE_ENDIAN__ */

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "errors.h"

# pragma pack(push, 1)

typedef struct	s_fhbmp
{
  uint16_t	signature;
  uint32_t	size;
  uint32_t	reserved;
  uint32_t	bitsoffset;
}		t_fhbmp;

typedef struct	s_hbmp
{
  uint32_t	headersize;
  int32_t	width;
  int32_t	height;
  uint16_t	planes;
  uint16_t	bitcount;
  uint32_t	compression;
  uint32_t	sizeimage;
  int32_t	ppmx;
  int32_t	ppmy;
  uint32_t	clrused;
  uint32_t	clrimportant;
  uint32_t	redmask;
  uint32_t	greenmask;
  uint32_t	bluemask;
  uint32_t	alphamask;
  uint32_t	cstype;
  uint32_t	endpoints[9];
  uint32_t	gammared;
  uint32_t	gammagreen;
  uint32_t	gammablue;
}		t_hbmp;

typedef struct	s_rgba
{
  uint8_t	r;
  uint8_t	g;
  uint8_t	b;
  uint8_t	a;
}		t_rgba;

typedef struct	s_bgra
{
  uint8_t	b;
  uint8_t	g;
  uint8_t	r;
  uint8_t	a;
}		t_bgra;

typedef struct	s_bitmap
{
  t_rgba	*bitmap;
  int32_t	width;
  int32_t	height;
}		t_bitmap;

# pragma pack(pop)

typedef struct	s_bit_stream
{
  int32_t	len;
  uint8_t	*line;
  uint8_t	*inc;
}		t_bit_stream;

typedef struct	s_bmp
{
  t_fhbmp	hdr_file;
  t_hbmp	hdr_data;
  t_bgra	*table;
  t_bitmap	*bitmap;
  t_bit_stream	stream;
}		t_bmp;

typedef struct	s_size
{
  int32_t	x;
  int32_t	y;
}		t_size;

# define S_UINT		sizeof(uint32_t)
# define S_INT		sizeof(int32_t)
# define S_USHRT	sizeof(uint16_t)
# define S_SHRT		sizeof(int16_t)
# define S_UCHAR	sizeof(uint8_t)
# define S_CHAR		sizeof(int8_t)
# define S_FHBMP	sizeof(t_fhbmp)
# define S_HBMP		sizeof(t_hbmp)
# define S_BRGA		sizeof(t_bgra)
# define S_RGBA		sizeof(t_rgba)

int		fill_1_byte(int *, t_bitmap *, t_bit_stream *, t_bgra *);
int		fill_4_byte(int *, t_bitmap *, t_bit_stream *, t_bgra *);
int		fill_8_byte(int *, t_bitmap *, t_bit_stream *, t_bgra *);
int		fill_16_byte(int *, t_bitmap *, t_bit_stream *);
int		fill_24_byte(int *, t_bitmap *, t_bit_stream *);
int		fill_32_byte(int *, t_bitmap *, t_bit_stream *);

void	*bmp_calloc(uint64_t nmemb, uint64_t nsize);
void	bmp_memset(void *ptr, char reset, int64_t size);

int	parser_init(int fd, t_bmp *process);

t_bitmap	*load_bmp_file(const char *filename);

int	parser_bitmap(int fd, t_bmp *process);

#endif /* !LIB_BMP_H_ */
