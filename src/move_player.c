#include "../includes/header.h"

static float b = 1;

static void move_up(player_t *player)
{
    player->position.x -= cos(degrees_to_radians(player->rotation));
    player->position.y -= sin(degrees_to_radians(player->rotation));
}

static void move_down(player_t *player)
{
    player->position.x += cos(degrees_to_radians(player->rotation));
    player->position.y += sin(degrees_to_radians(player->rotation));
}

static void rotate_left(player_t *player)
{
    player->rotation -= b;
}

static void rotate_right(player_t *player)
{
    player->rotation += b;
}

void update_player(player_t *player)
{
    static const sfKeyCode keys[KEYS_NUMBER] = {sfKeyDown, sfKeyUp, sfKeyLeft, sfKeyRight};
    static void (*move[KEYS_NUMBER])(player_t *player) =
            {&move_up, &move_down, &rotate_left, &rotate_right};

    // TODO: call move updates with clock
    for (int i = 0; i < KEYS_NUMBER; i++)
        if (sfKeyboard_isKeyPressed(keys[i])) {
            move[i](player);
            sfRectangleShape_setRotation(player->stick, player->rotation);
            sfRectangleShape_setPosition(player->square, player->position);
            sfRectangleShape_setPosition(player->stick, player->position);
            break;
        }
}
