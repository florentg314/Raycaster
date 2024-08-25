#include "../includes/header.h"

player_t *get_player(const map_t *map)
{
    player_t *player = malloc(sizeof(player_t));

    player->position = (sfVector2f){((float)map->height * map->cell_size.y) / 2.0f,
                                    ((float)map->width * map->cell_size.x) / 2.0f};
    player->size = (sfVector2f){10, 10};
    player->stick_size = (sfVector2f){15, 2};
    player->square = sfRectangleShape_create();
    player->stick = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(player->square, sfTransparent);
    sfRectangleShape_setOutlineColor(player->stick, sfTransparent);
    sfRectangleShape_setFillColor(player->square, sfRed);
    sfRectangleShape_setFillColor(player->stick, sfRed);
    sfRectangleShape_setSize(player->square, player->size);
    sfRectangleShape_setSize(player->stick, player->stick_size);
    sfRectangleShape_setPosition(player->square, player->position);
    sfRectangleShape_setPosition(player->stick, player->position);
    sfRectangleShape_setOrigin(player->square, (sfVector2f){player->size.x / 2.0f, player->size.y / 2.0f});
    return player;
}
