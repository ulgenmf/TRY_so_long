#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft.h"
#include "mlxx.h"
#include "printf.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
// --- Map related shit ---

char **get_map(char *map);
// #define MAP_SIZE 1024 * 1024 * 100
#define BUFFER_SIZE 1
#ifndef DEFAULT_MAP
#define DEFAULT_MAP "t.ber"
#endif

#define TILE_SIZE = 128
// --- ERROR HANDLER ---
typedef enum e_errors {
  MAP_FILE_TOO_BIG,
  INVALID_CHAR,
  NOT_RECTANGULAR,
  UNCLOSED_MAP,
  INVALID_NAME,
  WRONG_ELEMENT_COUNT,
  NO_PATH,
  MLX_FAIL,
  UNKNOWN_ERROR
} t_errors;

t_map *create_obj(char *file_name);

char **duplicate_map(char **map);
int is_surrounded_by_walls(char **map);
int check_elements(char **map);
int is_rectangular(char **map);
void big_fat_error_handler(char **map, char *file);
int check_elements(char **map);

void free_map(char **map);
void check_file_name(char *file);
char **duplicate_map(char **map);

void error_handler(t_errors error);
void error_writer(char *str);

void wait_(int n);
// --- ERROR HANDLER ---
// --- IMAGE DATA ---
typedef struct img {
  void *img;
  char *addr;
  int bpp;
  int line_l;
  int endian;
} t_img;

int path_valid(char **map);

void flood_fill(char **map, int x, int y);
int find_player(char **map, int *px, int *py);
char **duplicate_map(char **map);
// -- COLOR shit ---
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define YELLOW 0xFFFF00
#define CYAN 0x00FFFF
#define MAGENTA 0xFF00FF
#define WHITE 0xFFFFFF
#define BLACK 0x000000
//
#define TITTLE "TOO_LONG"
#ifndef NULL
#define NULL ((void *)0)
#endif
#define W 800
#define H 600

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

//
// --- GET_NEXT_LINE ---
// size_t ft_strlen(char *str);
// char *ft_strjoin(char *leftover, char *buff);
char *ft_strjoin_gnl(char *leftover, char *buff);
// void *ft_calloc(size_t count, size_t size);
char *newline_exist(char *str);
char *get_next_line(int fd);
// --- UTILLS ---
int arr_len(char **arr);
int ft_strcmp(char *s1, char *s2);

// char *ft_strdup(char *src);
size_t f_strlen(char *str);
int ft_printf(const char *format, ...);
void writer(const char *str);

//! ----
// --- RUN_THAT_SHIT ---
void parse_map(char **map, char *file_name);

void run_that_shit(char *argv_file_name);
int is_map_solvable(char **src_map);

//
#endif
