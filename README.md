Backup repo for Cub3D :

Added .cub file parsing for :
  - wall textures
  - ceiling/floor colors
  - map layout

Added error handling for :
  - wall textures parsing (100%)
  - ceiling/floor colors parsing (100%)
  - map layout parsing (map presence and position) - to do : incorrect characters + wrong layout (basicaly, an open map)

no leaks + 2 invalid reads in draw_map() function.
