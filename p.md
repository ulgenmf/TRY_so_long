

---

````md
## 🧱 MAP STRUCTURE: `t_map`

### ✅ Purpose

The `t_map` struct holds all relevant data extracted from the `.ber` file after parsing and validation.  
It is the internal representation of your game map.

---

### 🧩 Definition

```c
typedef struct s_map
{
    char    **grid;                // 2D array: map[y][x]
    int     width;                // number of columns (tiles per row)
    int     height;               // number of rows
    int     player_count;         // must be exactly 1
    int     exit_count;           // must be exactly 1
    int     collectible_count;    // must be ≥ 1
}   t_map;
````

---

### 🔍 Field Descriptions

| Field               | Type      | Meaning                                                 |
| ------------------- | --------- | ------------------------------------------------------- |
| `grid`              | `char **` | 2D array of characters; each string is a row of the map |
| `width`             | `int`     | Number of tiles (columns) in each row                   |
| `height`            | `int`     | Number of rows (total lines in map)                     |
| `player_count`      | `int`     | Count of `'P'` characters; must be **1**                |
| `exit_count`        | `int`     | Count of `'E'` characters; must be **1**                |
| `collectible_count` | `int`     | Count of `'C'` characters; must be **1 or more**        |

---

### 🧪 Example

Given this `.ber` file:

```
1111
1P01
1C0E
1111
```

After parsing:

```c
map.grid = {
    "1111",
    "1P01",
    "1C0E",
    "1111"
};

map.width = 4;
map.height = 4;
map.player_count = 1;
map.exit_count = 1;
map.collectible_count = 1;
```

---

### 🧼 Memory Ownership

* You must allocate `grid` dynamically (via `ft_split`).
* You must later write `free_map(t_map *map)` to:

  * Free each row in `grid[y]`
  * Free the `grid` pointer itself

---

### 🧠 Integration

This `t_map` will be stored inside your main `t_game` struct:

```c
typedef struct s_game {
    ...
    t_map map;
    ...
} t_game;
```

---

### ✅ Done When:

* Map data is loaded into `t_map.grid`
* `width`, `height` are correct
* All counts (`P`, `E`, `C`) are set and validated
* No memory leaks when freeing `grid`

```
```
```
