#ifndef PATHFINDER_CONST
#define PATHFINDER_CONST

#define INT_MAX 2147483647

static const char* PATH_STR = "Path: ";
static const char* ROUTE_STR = "Route: ";
static const char* DIST_STR = "Distance: ";
static const char* ARROW_STR = " -> ";
static const char* EQUALS_STR = " = ";
static const char* PLUS_STR = " + ";
static const char SEPARATOR_CH = '=';

static const char* USAGE_ERR = "usage: ./pathfinder [filename]\n";
static const char* FILE_ERR = "error: file ";
static const char* NO_EXIST_ERR = " does not exist\n";
static const char* FILE_EMTY_ERR = " is empty\n";
static const char* FIRST_LINE_ERR = "error: line 1 is not valid\n";
static const char* ISLAND_NUM_ERR = "error: invalid number of islands\n";
static const char* DUPLICATE_ERR = "error: duplicate bridges\n";
static const char* BRIDGES_SUM_ERR = "error: sum of bridges lengths is too big\n";

#endif
