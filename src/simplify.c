#include <stdlib.h>
#include <string.h>

#include <simplify.h>

#define DEFAULT_CAPACITY 12

static double simplify_get_radial_square_distance(const struct simplify_point *p1, const struct simplify_point *p2)
{
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return dx * dx + dy * dy;
}

static struct simplify_path* simplify_radial_distance(const struct simplify_path *path, double sq_tolerance)
{
    int i;
    int n = 0;
    struct simplify_point *temp = NULL;
    struct simplify_point *prev = path->points;
    struct simplify_point *next = path->points;
    struct simplify_path *simplified = calloc(1, sizeof(struct simplify_path));

    simplified->length = DEFAULT_CAPACITY;
    simplified->points = calloc(DEFAULT_CAPACITY, sizeof(struct simplify_point));

    for (i = 1; i < path->length; i++) {
        next = path->points + i;

        if (simplify_get_radial_square_distance(next, prev) > sq_tolerance) {
            if (simplified->length >= n) {
                n += DEFAULT_CAPACITY >> 1;
                temp = simplified->points;
                simplified->points = calloc(n, sizeof(struct simplify_point));
                free(temp);
            }

            memcpy(simplified->points, next, sizeof(struct simplify_point));
            simplified->length++;
            prev = next;
        }
    }

    return simplified;
}

struct simplify_path* simplify(const struct simplify_path *path, double tolerance)
{
    return simplify_radial_distance(path, tolerance * tolerance);
}

