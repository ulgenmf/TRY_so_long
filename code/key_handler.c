/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:55:05 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/05 14:55:31 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int key_hook(int keycode, t_game *mlx_obj) {
  if (keycode == 65307) // Escape key
  {
    //
    // Free resources here (images, window, mlx etc.)
    // Example:
    // mlx_destroy_window(mlx, win);
    // mlx_destroy_display(mlx);
    // free(mlx);

    free_mlx_obj(&mlx_obj);
    exit(EXIT_SUCCESS);
  }

  // Check for W, A, S, D keys and print which one was pressed
  if (keycode == 119 || keycode == 87) // W or w
    ft_printf("Key pressed: W\n");
  else if (keycode == 97 || keycode == 65) // A or a
    ft_printf("Key pressed: A\n");
  else if (keycode == 115 || keycode == 83) // S or s
    ft_printf("Key pressed: S\n");
  else if (keycode == 100 || keycode == 68) // D or d
    ft_printf("Key pressed: D\n");

  return (0);
}
