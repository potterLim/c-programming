#include <stdio.h>
#include "health_score.h"

int main(void)
{
    solve_lab01();

    for (int i = 0; i < 7; ++i) {
        printf("%s\n", get_output_line(i));
    }

    return 0;
}
