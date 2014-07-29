#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************** Globals **********************/
typedef struct
{
    char *moves;             // Needs to be a \0 terminated string
    unsigned int sharpness;
} caveman;

caveman bob;
caveman bub;

char    *ptr     = NULL;
int str_len  = 0;
int str2_len = 0;

/********************** Macro Functions **********************/
#define INIT_CAVEMAN(cm) { cm.moves = NULL; cm.sharpness = 0; }

#define PARSE_ARGS(argv) { ptr = argv[1]; do { ptr++ } while(*ptr != ',' && *ptr != '\0'); str_len = (ptr - argv[1]); bob.moves = malloc(sizeof(char) * str_len); memcpy(bob.moves, argv[1],  str_len); do { ptr++ } while(*ptr != '\0'); str2_len = (ptr - (argv[1] + str_len)); bub.moves = malloc(sizeof(char) * str2_len); memcpy(bub.moves, argv[1]+str_len, str2_len);}

#define GET_ARGS(argc, argv) (argc < 2) ? SET_BOTH('', 0) : PARSE_ARGS(argv)

#define SET_BOTH(ch, sharp) bob.moves
#define CLEAN_UP() if(bob.moves != NULL) free(bob.moves); if(bub.moves != NULL) free(bub.moves);

#define GET_SHARPNESS(cm) { ptr = cm.moves; do { } while(*ptr != '\0'); }

/********************** Main Program **********************/
int main(int argc, char **argv)
{
    INIT_CAVEMAN(bob);
    INIT_CAVEMAN(bub);

    GET_ARGS(argc, argv);

    GET_SHARPNESS(bub);
    GET_SHARPNESS(bob);

    CLEAN_UP();
    
    return 0;
}
