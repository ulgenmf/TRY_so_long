#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIN_W 800
#define WIN_H 600

char *idle_frames[] = {"scaled_128x128/idle0.xpm", "scaled_128x128/idle1.xpm",
                       "scaled_128x128/idle2.xpm", "scaled_128x128/idle3.xpm",
                       NULL};

char *moving_left_frames[] = {"scaled_128x128/moving_left0.xpm",
                              "scaled_128x128/moving_left1.xpm",
                              "scaled_128x128/moving_left2.xpm",
                              "scaled_128x128/moving_left3.xpm",
                              "scaled_128x128/moving_left4.xpm",
                              "scaled_128x128/moving_left5.xpm",
                              "scaled_128x128/moving_left6.xpm",
                              "scaled_128x128/moving_left7.xpm",
                              NULL};

char *moving_right_frames[] = {"scaled_128x128/moving_right0.xpm",
                               "scaled_128x128/moving_right1.xpm",
                               "scaled_128x128/moving_right2.xpm",
                               "scaled_128x128/moving_right3.xpm",
                               "scaled_128x128/moving_right4.xpm",
                               "scaled_128x128/moving_right5.xpm",
                               "scaled_128x128/moving_right6.xpm",
                               "scaled_128x128/moving_right7.xpm",
                               NULL};

char *hit_frames[] = {"scaled_128x128/hit0.xpm", "scaled_128x128/hit1.xpm",
                      "scaled_128x128/hit2.xpm", "scaled_128x128/hit3.xpm",
                      NULL};

char *death_frames[] = {
    "scaled_128x128/death0.xpm", "scaled_128x128/death1.xpm",
    "scaled_128x128/death2.xpm", "scaled_128x128/death3.xpm", NULL};

#define TILE_SIZE 128
#define FRAME_DELAY 2500

#define IDLE_FRAME_COUNT 4
#define MOVING_LEFT_FRAME_COUNT 8
#define MOVING_RIGHT_FRAME_COUNT 8
#define HIT_FRAME_COUNT 4
#define DEATH_FRAME_COUNT 4

#define EVENT_KEY_PRESS 2
#define EVENT_KEY_PRESS 2 // From 42 Docs: ON_KEYDOWN
// Common X11 ESC keycode (use one based on your environment)
#define KEY_S 115
#define KEY_D 65361
#define KEY_A 65363
#define KEY_W 65362
#define KEY_ARROW_DOWN 65364
#define KEY_ESC 65307

typedef enum e_player_state {
  IDLE,
  MOVING_LEFT,
  MOVING_RIGHT,
  HIT,
  DEATH
} t_player_state;

typedef struct s_player {
  int x;
  int y;
  t_player_state current_state;
  int current_frame;

  void *current_displayed_img_ptr;

} t_player;

typedef struct s_game {
  void *mlx_ptr;
  void *win_ptr;
  t_player player;
  int animation_frame_counter;
  void *player_idle_imgs[IDLE_FRAME_COUNT];
  void *player_moving_left_imgs[MOVING_LEFT_FRAME_COUNT];
  void *player_moving_right_imgs[MOVING_RIGHT_FRAME_COUNT];
  void *player_hit_imgs[HIT_FRAME_COUNT];
  void *player_death_imgs[DEATH_FRAME_COUNT];

} t_game;

// int	load_player_textures(t_game *game)
// {
// 	int	i;
// 	int	temp_width;
// 	int	temp_height;

// 	i = 0;
// 	while (i < IDLE_FRAME_COUNT)
// 	{
// 		game->player_idle_imgs[i] = mlx_xpm_file_to_image(
// 			game->mlx_ptr, idle_frames[i], &temp_width,
// &temp_height); 		if (!game->player_idle_imgs[i])
// 		{
// 			write(2, "Error\nFailed to load idle frame.\n", 34);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < MOVING_LEFT_FRAME_COUNT)
// 	{
// 		game->player_moving_left_imgs[i] = mlx_xpm_file_to_image(
// 			game->mlx_ptr, moving_left_frames[i], &temp_width,
// &temp_height); 		if (!game->player_moving_left_imgs[i])
// 		{
// 			write(2, "Error\nFailed to load moving left frame.\n",
// 41); 			return (1);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < MOVING_RIGHT_FRAME_COUNT)
// 	{
// 		game->player_moving_right_imgs[i] = mlx_xpm_file_to_image(
// 			game->mlx_ptr, moving_right_frames[i], &temp_width,
// &temp_height); 		if (!game->player_moving_right_imgs[i])
// 		{
// 			write(2, "Error\nFailed to load moving right frame.\n",
// 42); 			return (1);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < HIT_FRAME_COUNT)
// 	{
// 		game->player_hit_imgs[i] = mlx_xpm_file_to_image(
// 			game->mlx_ptr, hit_frames[i], &temp_width,
// &temp_height); 		if (!game->player_hit_imgs[i])
// 		{
// 			write(2, "Error\nFailed to load hit frame.\n", 33);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < DEATH_FRAME_COUNT)
// 	{
// 		game->player_death_imgs[i] = mlx_xpm_file_to_image(
// 			game->mlx_ptr, death_frames[i], &temp_width,
// &temp_height); 		if (!game->player_death_imgs[i])
// 		{
// 			write(2, "Error\nFailed to load death frame.\n", 35);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

#include <mlx.h>

#define WIDTH 400
#define HEIGHT 200

int close_window(void *param) {
  (void)param;
  exit(0); // Allowed for exit according to subject
  return (0);
}

int key_press(int keycode, void *param) {
  (void)param;
  if (keycode == 65307) // 53 is 'ESC' on macOS,  for Linux
    exit(0);
  return (0);
}

int main(void) {
  void *mlx_ptr;
  void *win_ptr;

  mlx_ptr = mlx_init();
  if (!mlx_ptr)
    return (1);
  win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "MLX Events Demo");
  if (!win_ptr)
    return (1);
  mlx_hook(win_ptr, 2, 1L << 0, key_press, NULL); // Key press event
  mlx_hook(win_ptr, 17, 0, close_window, NULL);   // Window close (red x)
  mlx_loop(mlx_ptr);
  return (0);
}
