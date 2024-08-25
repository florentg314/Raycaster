#include "../includes/header.h"

static void count_map_size(map_t *map, const char *line)
{
    if (map->width == 0)
        map->width = strlen(line) - 1;
    map->height++;
}

static void get_map_content(map_t *map, const char *line)
{
    static unsigned int index_y = 0;
    map->cells[index_y] = malloc(sizeof(cell_t) * map->width);
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\n')
            continue;
        if (line[i] == '#')
            map->cells[index_y][i].type = SOLID;
        else
            map->cells[index_y][i].type = AIR;
    }
    index_y++;
}

static int parse_file(const char *filepath, map_t *map)
{
    static int mode = 1;
    FILE *stream = fopen(filepath, "r");
    char *line = NULL;
    size_t size = 0;

    if (!stream) {
        return 1;
    }
    while (getline(&line, &size, stream) != -1) {
        if (mode)
            count_map_size(map, line);
        else
            get_map_content(map, line);
    }
    mode = 0;
    free(line);
    fclose(stream);
    return 0;
}

map_t *get_map(const char *filepath)
{
    map_t *map = malloc(sizeof(map_t));

    map->width = 0;
    map->height = 0;
    map->cell_size = (sfVector2f){30, 30};
    if (parse_file(filepath, map)) {
        free(map);
        return NULL;
    }
    map->cells = malloc(sizeof(cell_t *) * map->height);
    parse_file(filepath, map);
    return map;
}

void destroy_map(map_t *map)
{
    for (unsigned int y = 0; y < map->height; y++)
        free(map->cells[y]);
    free(map->cells);
    free(map);
}
