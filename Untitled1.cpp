#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <ctype.h>
#include <assert.h>

struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt; // left top
    struct Point rb; // right bottom
};

struct Rect transform (struct Rect r);

int main()
{
    struct Rect rect, a = {{2, 4}, {7, 1}};
    rect = transform(a);
    printf("%d %d %d %d\n", rect.lt.x, rect.lt.y, rect.rb.x, rect.rb.y);
    return 0;
}

struct Rect transform (struct Rect r)
{
    struct Rect g;

    g.lt.x = r.lt.x;
    g.lt.y = r.rb.y;
    g.rb.x = r.lt.x + (r.lt.y - r.rb.y);
    g.rb.y = r.rb.y - (r.rb.x - r.lt.x);

    return g;
}


