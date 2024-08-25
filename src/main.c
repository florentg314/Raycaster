#include "../includes/header.h"

int main(int argc, char **argv)
{
    map_t *map = NULL;
    player_t *player = NULL;
    sfEvent event;
    sfRenderWindow *window = NULL;
    sfRectangleShape *rectangle = NULL;

    if (argc != 2) {
        printf("Command should be: ./raycaster <path to map file>\n");
        return 1;
    }

    map = get_map(argv[1]);

    if (!map) {
        printf("File \"%s\" not found...\n", argv[1]);
        return 1;
    }

    player = get_player(map);
    rectangle = sfRectangleShape_create();
    window = sfRenderWindow_create(sfVideoMode_getDesktopMode(), "Raycaster", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRectangleShape_setOutlineColor(rectangle, sfTransparent);
    sfRectangleShape_setSize(rectangle, map->cell_size);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);

        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }

        for (unsigned int y = 0; y < map->height; y++) {
            for (unsigned int x = 0; x < map->width; x++) {
                sfRectangleShape_setPosition(rectangle, (sfVector2f){y * map->cell_size.y, x * map->cell_size.x});
                sfRectangleShape_setFillColor(rectangle, map->cells[y][x].type == SOLID ? sfGreen : sfWhite);
                sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
            }
        }

        update_player(player);

        sfRenderWindow_drawRectangleShape(window, player->square, NULL);
        sfRenderWindow_drawRectangleShape(window, player->stick, NULL);

        sfRenderWindow_display(window);
    }
    destroy_map(map);
    return 0;
}
