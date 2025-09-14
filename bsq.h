#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct elements
{
	int lines;
	char empty;
	char obstacle;
	char full;
} t_elements;

typedef struct map
{
	char **map;
	int width;
	int height;
	int best;
	int start_i;
	int start_j;
} t_map;
