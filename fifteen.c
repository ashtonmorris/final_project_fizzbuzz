/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init(void)
{
    // TODO
    //get number of spaces in board
    int spaces = d * d;
    //add tiles to board
    //for each row
    for (int i = 0; i < d; i++)
    {
        //for each column
        for (int j = 0; j < d; j++)
        {
        //set value for tile
        board[i][j] = --spaces;
        }
    }
    
    //switch 2 tile with 1 tile if number of spaces is even using modulo to check
    if ((d * d) % 2 == 0)
    {
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    //print the tiles values
    //for each row
    for (int i = 0; i < d; i++)
    {
        //for each column
        for (int j = 0; j < d; j++)
        {
            //print tile's value
            //if tile has no value, use underscore instead
            if (board[i][j] == 0)
                printf(" _");
            //if tile is in double digits, print without extra space
            else if (board[i][j] > 9)
                printf("%i", board[i][j]);
            //if tile is in single digits, print %2i for an extra space
            else if (board[i][j] > 0)
                printf("%2i", board[i][j]);
        }
    //print new line
    printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    //check for valid tile
    //if(tile > (d * d) - 1 || tile < 1)
    //{
        //printf("Ilegal move. \n");
       // return false;
    //}
    
    int x;
    int y;
    
    // TODO
    //search rows to find tile
    for (int row = 0; row < d; row++)
    {
        //search columns to find tile
        for (int col = 0; col < d; col++)
        {
            //check tile location
            if(board[row][col] == tile)
            {
                x = row;
                y = col;
            }
        }
    }
     
            //check adjacent spaces for the empty space
                    //switch tile with blank space
                    //keep track of blank space location
            if (x - 1 >= 0 && board[x - 1][y] == 0)
            {
                board[x- 1][y] = board[x][y];
                board[x][y] = 0;
                return true;
            }
            else if (x + 1 < d && board[x + 1][y] == 0)
            {
                 board[x + 1][y] = board[x][y];
                 board[x][y] = 0;
                return true;
            }
            else if (y - 1 >= 0 && board[x][y - 1] == 0)
            {
                board[x][y - 1] = board[x][y];
                board[x][y] = 0;
                return true;
            }
            else if (y + 1 < d && board[x][y + 1] == 0)
            {
                board[x][y + 1] = board[x][y];
                board[x][y] = 0;
                return true;
            }
    
            return false;
}
          

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    // initialize counter
    int counter = 1;
    
    //iterate over board and check the values
    
    //check rows
    for (int row = 0; row < d; row++)
    {
        //check columns
        for (int col = 0; col < d; col++)
        {
            //if any value is incorrect, return false
            if (board[row][col] == 0)
            counter = 0;
            
            if (board[row][col] != counter)
            return false;
        
        counter++; 
        
        }
    }
    //return true once all tiles are checked
    return true;
}
