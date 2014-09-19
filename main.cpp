#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <string>
#include <stdlib.h>
#include <sstream>

//Screen attributes
const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *gameBoard = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *cross = NULL;
SDL_Surface *circle = NULL;

//The event structure
SDL_Event event;

//The font in use
TTF_Font *font;

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }
    //Initialize SDL_ttf
    if(TTF_Init() == -1)
    {
        return false;
    }
    //Set the window caption
    SDL_WM_SetCaption( "Tic Tac Toe", NULL );
    //If everything initialized fine
    return true;
}

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface from png file with alpha blending
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 255, 255, 255 ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

bool load_files()
{    
    gameBoard = load_image( "assets/gameboard.png" );
    cross = load_image("assets/x.png");
    circle = load_image("assets/circle.png");    

    if(gameBoard == NULL)
    {
        return false;
    }

    if(cross == NULL)
    {
        return false;
    }

    if(circle == NULL)
    {
        return false;
    }
    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surface
    SDL_FreeSurface(screen);
    SDL_FreeSurface(gameBoard);
    SDL_FreeSurface(cross);

    //Quit SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    int turn = 1;
    int x = 0;
    int y = 0;
    int i = 0;
    int sum = 0;
    int turnCount = 0;
    int gameBoardMatrix[9]= {0,0,0,0,0,0,0,0,0};
    bool appplyOrNot = false;
    bool quit = false;    
    bool gameWon = false;

    if( init() == false)
    {
        return 1;
    }

    if(load_files() == false)
    {
        return 1;
    }

    apply_surface(0, 0, gameBoard, screen );

    while(quit == false )
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    x = event.button.x;
                    y = event.button.y;
                    turnCount++;
                    //Check if square clicked is vacant then mark it accordingly X or O
                    if(x/100 == 0 && y/100 == 0 && gameBoardMatrix[0]== 0)
                    {
                        appplyOrNot = true;

                        if(turn == 1)
                        {
                            gameBoardMatrix[0] = 1;
                        }
                        else
                        {
                            gameBoardMatrix[0] = -1;
                        }

                    }
                    if(x/100 == 1 && y/100 == 0 && gameBoardMatrix[1] == 0)
                    {
                        appplyOrNot = true;

                        if(turn == 1)
                        {
                            gameBoardMatrix[1] = 1;
                        }
                        else
                        {
                            gameBoardMatrix[1] = -1;
                        }

                    }
                    if(x/100 == 2 && y/100 == 0 && gameBoardMatrix[2] == 0)
                    {
                        appplyOrNot = true;

                        if(turn == 1)
                        {
                            gameBoardMatrix[2] = 1;
                        }
                        else
                        {
                            gameBoardMatrix[2] = -1;
                        }
                    }
                    if(x/100 == 0 && y/100 == 1 && gameBoardMatrix[3] == 0)
                    {

                        appplyOrNot = true;

                        if(turn == 1)
                        {
                            gameBoardMatrix[3] = 1;
                        }
                        else
                        {
                            gameBoardMatrix[3] = -1;
                        }
                    }
                    if(x/100 == 1 && y/100 == 1 && gameBoardMatrix[4] == 0)
                    {
                        appplyOrNot = true;

                        if(turn == 1)
                        {
                            gameBoardMatrix[4] = 1;
                        }
                        else
                        {
                            gameBoardMatrix[4] = -1;
                        }
                    }
                    if(x/100 == 2 && y/100 == 1 && gameBoardMatrix[5] == 0)
                    {
                        appplyOrNot = true;

                        if(turn == 1)
                        {
                            gameBoardMatrix[5] = 1;
                        }
                        else
                        {
                            gameBoardMatrix[5] = -1;
                        }
                    }
                    if(x/100 == 0 && y/100 == 2 && gameBoardMatrix[6] == 0)
                    {
                        appplyOrNot = true;

                        if(turn == 1)
                        {
                            gameBoardMatrix[6] = 1;
                        }
                        else
                        {
                            gameBoardMatrix[6] = -1;
                        }
                    }
                    if(x/100 == 1 && y/100 == 2 && gameBoardMatrix[7] == 0)
                    {
                        appplyOrNot = true;

                        if(turn == 1)
                        {
                            gameBoardMatrix[7] = 1;
                        }
                        else
                        {
                            gameBoardMatrix[7] = -1;
                        }
                    }
                    if(x/100 == 2 && y/100 == 2 && gameBoardMatrix[8] == 0)
                    {
                        appplyOrNot = true;

                        if(turn == 1)
                        {
                            gameBoardMatrix[8] = 1;
                        }
                        else
                        {
                            gameBoardMatrix[8] = -1;
                        }
                    }
                    if(appplyOrNot == true)
                    {
                        if(turn == 1)
                        {
                            apply_surface(x/100 * 100, y/100 * 100,circle,screen);
                            turn = 2;
                        }
                        else
                        {
                            apply_surface(x/100 * 100, y/100 * 100,cross,screen);
                            turn = 1;
                        }

                        appplyOrNot = false;
                    }
                }
            }
        }
        //Check for end game conditions, win or draw
        //Check rows
        for(i=0;i<=6; i+=3)
        {
            sum = gameBoardMatrix[i] + gameBoardMatrix[i+1] + gameBoardMatrix[i+2];
            if(sum == 3)
            {
                gameWon = true;
            }
            else if(sum == -3)
            {
                gameWon = true;
            }
        }
        //Check columns
        for(i=0;i<=2;i++)
        {
            sum = gameBoardMatrix[i] + gameBoardMatrix[i+3] + gameBoardMatrix[i+6];

            if(sum == 3)
            {
                gameWon = true;
            }
            else if(sum == -3)
            {
                gameWon = true;
            }
        }
        //Check diagonals
        if(gameBoardMatrix[0] + gameBoardMatrix[4] + gameBoardMatrix[8] == 3 || gameBoardMatrix[2] + gameBoardMatrix[4] + gameBoardMatrix[6] == 3)
        {
            gameWon = true;
        }
        else if(gameBoardMatrix[0] + gameBoardMatrix[4] + gameBoardMatrix[8] == -3 || gameBoardMatrix[2] + gameBoardMatrix[4] + gameBoardMatrix[6] == -3)
        {
            gameWon = true;
        }
        //Checking if end game conditions are met
        if(gameWon == true || turnCount == 9)
        {
            apply_surface(0, 0, gameBoard, screen );

            for(i=0;i<=8;i++)
            {
                gameBoardMatrix[i]=0;
            }
            gameWon = false;
            turnCount = 0;
        }
        //Incase of user exits
        if(event.type == SDL_QUIT)
        {
            quit = true;
        }

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }

    clean_up();

    return 0;
}
