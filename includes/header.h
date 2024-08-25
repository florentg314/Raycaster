#ifndef RAYCASTER_HEADER_H
    #define RAYCASTER_HEADER_H
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #define KEYS_NUMBER 6

typedef enum {
    SOLID,
    AIR
} wall_type;

typedef struct cell_s {
    wall_type type;
} cell_t;

typedef struct map_s {
    unsigned int width;
    unsigned int height;
    cell_t **cells;
    sfVector2f cell_size;
} map_t;

typedef struct player_s {
    sfVector2f size;
    sfVector2f stick_size;
    sfRectangleShape *square;
    sfRectangleShape *stick;
    sfVector2f position;
    float rotation;
} player_t;

map_t *get_map(const char *filepath);
void destroy_map(map_t *map);
player_t *get_player(const map_t *map);
void update_player(player_t *player);

float safe_rotation(const float angle);
float degrees_to_radians(const float degrees);

#endif //RAYCASTER_HEADER_H
