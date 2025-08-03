
MAP RENDERING IS DONE

# MiniLibX Core Setup

```
□ Window Initialization
  □ mlx_init() - Initialize MiniLibX connection
  □ mlx_new_window() - Create game window (map_width * tile_size, map_height * tile_size)
  □ Store mlx_ptr and win_ptr in game structure
  □ Set window title and properties

□ Texture Asset Loading
  □ Load wall texture (.xpm) using mlx_xpm_file_to_image()
  □ Load floor/empty space texture
  □ Load player sprite texture
  □ Load collectible sprite texture
  □ Load exit sprite texture
  □ Store all texture pointers and dimensions in texture structure
  □ Validate all textures loaded successfully (error handling)

□ Event Hook Registration
  □ mlx_hook() for window close event (17, 0, close_game_function)
  □ mlx_key_hook() for key press events
  □ mlx_expose_hook() for window refresh events
  □ Ensure all hooks properly reference game structure
```

# Rendering System Architecture

```
□ Tile-Based Rendering Core
  □ Calculate tile dimensions (typically 32x32 or 64x64 pixels)
  □ Create render_map() function that iterates through map grid
  □ For each grid position, determine sprite type and render
  □ Use mlx_put_image_to_window() for each tile placement

□ Sprite Positioning Logic
  □ Convert grid coordinates (x,y) to pixel coordinates (x*tile_size, y*tile_size)
  □ Layer sprites correctly (floor → collectibles → player → walls)
  □ Implement z-order rendering to prevent sprite overlap issues

□ Dynamic Element Updates
  □ Track player position changes in game state
  □ Mark collectibles as collected in map data
  □ Update only changed regions instead of full map redraw
  □ Clear previous player position before drawing new position
```

# Input Processing System

```
□ Key Mapping Implementation
  □ Define key codes: W(119), A(97), S(115), D(100) or arrow keys
  □ Map ZQSD if needed: Z(122), Q(113), S(115), D(100)
  □ ESC key code (65307) for game exit

□ Movement Validation Pipeline
  □ Calculate target position (current_pos + direction_vector)
  □ Check bounds: target_x >= 0 && target_x < map_width
  □ Check wall collision: map[target_y][target_x] != '1'
  □ Return boolean for valid/invalid move

□ Event Handler Functions
  □ key_press_handler(int keycode, t_game *game)
    - Switch statement for different keys
    - Call movement validation
    - Update game state if move valid
    - Trigger render update
  □ close_handler(t_game *game)
    - Free all allocated memory
    - Destroy textures and window
    - Exit program cleanly
```

# Game State Management

```
□ Movement Processing
  □ validate_move(t_game *game, int new_x, int new_y)
    - Boundary checks
    - Wall collision detection
    - Return move validity
  □ execute_move(t_game *game, int new_x, int new_y)
    - Update player coordinates in game structure
    - Increment move counter
    - Print move count to stdout: printf("Moves: %d\n", moves)
    - Check for collectible at new position
    - Trigger appropriate game events

□ Collision Detection System
  □ check_collectible(t_game *game, int x, int y)
    - If map[y][x] == 'C': collect item, update count, change map to '0'
  □ check_exit(t_game *game, int x, int y)
    - If map[y][x] == 'E' && all_collected: trigger win condition
    - If map[y][x] == 'E' && !all_collected: block movement or allow but no win

□ Render Trigger System
  □ Call render_game() after each valid move
  □ Update only necessary screen regions
  □ Maintain smooth 60fps if possible
```

# Error Handling & Cleanup

```
□ Texture Loading Validation
  □ Check each mlx_xpm_file_to_image() return value
  □ If NULL returned: print error, cleanup existing resources, exit
  □ Verify texture dimensions match expected tile size

□ Window Management Error Handling
  □ Validate mlx_init() success
  □ Validate mlx_new_window() success
  □ Handle window creation failures gracefully

□ Memory Cleanup Functions
  □ destroy_textures(t_game *game) - mlx_destroy_image() for each texture
  □ cleanup_mlx(t_game *game) - mlx_destroy_window(), mlx_destroy_display()
  □ Register cleanup function to be called on all exit paths

