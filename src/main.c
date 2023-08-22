#include "../include/structs.h"
#include "../include/prototypes.h"

int main(void)
{
    sfEvent event = {0};
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfRenderWindow *window = sfRenderWindow_create(mode, "Raycaster", sfDefaultStyle, NULL);
    raycaster_t *raycaster = create_raycaster(window);
    sfClock *clock = sfClock_create();

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        if (sfClock_getElapsedTime(clock).microseconds > (62 * 1000)) {
            sfClock_restart(clock);
            move_2d_player(raycaster, window);
            cast_rays(raycaster);
            change_resolution(raycaster);
        }
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
                sfRenderWindow_close(window);
            }
        }
        display_3d_map(raycaster, window);
        display_2d_map(raycaster, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
