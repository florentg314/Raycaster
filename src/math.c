#include "../includes/header.h"

float safe_rotation(const float angle)
{
    if (angle < 0)
        return angle + 360;
    if (angle > 359)
        return angle - 360;
    return angle;
}

float degrees_to_radians(const float degrees)
{
    return degrees * (M_PI / 180.0f);
}
