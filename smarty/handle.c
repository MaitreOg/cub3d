#include "cube3d.h"

char	**handle_map(char c, char **map)
{
    static char	**m;

    if (c == 'p')
        m = map;
    return (m);
}
