/*
 * Copyright (c) 2018 Amine Ben Hassouna <amine.benhassouna@gmail.com>
 * Wesal ben saad <wessal.bensaad@medtech.tn>
 * Hiba fathallah <hiba.fathallah@medtech.tn>
 * Ines ayari
 * chaima rajah
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without
 * limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
 * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include "animation.h"

bool Animation_start(SDL_Renderer *renderer, int width, int height)
{
    Animation animation = {0};
    animation.renderer  = renderer;
    animation.width     = width;
    animation.height    = height;
    animation.gameover  = false;


    // Load animation assets
     if(!Animation_load(&animation))
      return false;


    // Initialize framerate manager : 30 FPS
      FPSmanager fpsmanager;
    SDL_initFramerate(&fpsmanager);
    SDL_setFramerate(&fpsmanager, 60);


    // Initialize start frame
    int frame = SDL_getFramecount(&fpsmanager);


    // Event loop exit flag
    bool quit = false;

    // Event loop
    while(!quit  && !animation.gameover)
    {
        SDL_Event e;

    // Get available event
    while(SDL_PollEvent(&e))
        {
            // Handle animation events
            quit = Animation_handleEvent(&animation, &e);
        }

        // Each new frame
        int currentFrame = SDL_getFramecount(&fpsmanager);

        if(currentFrame != frame)
        {
            // Update animation frame
            Animation_update(&animation, SDL_getFramerate(&fpsmanager));
            currentFrame = frame;
        }

       // Render animation
        Animation_render(&animation);



        // Update screen
        SDL_RenderPresent(renderer);



        // Delay
        SDL_framerateDelay(&fpsmanager);
    }

    Animation_destroy(&animation);
    return true;
}


void Animation_text(Animation *animation)
{
    SDL_Color textColor           = { 0x00, 0x00, 0x00, 0xFF };
    SDL_Color textBackgroundColor = { 0xFF, 0xFF, 0xFF, 0xFF };
    SDL_Surface *textSurface = TTF_RenderText_Shaded(animation->font, "YOOOOOU WIIIIIIIN", textColor, textBackgroundColor);

        if(!textSurface) {
        printf("Unable to render text surface!\n"
               "SDL2_ttf Error: %s\n", TTF_GetError());
    } else {
        // Create texture from surface pixels
        animation->text = SDL_CreateTextureFromSurface(animation->renderer , textSurface);
        if(!animation->text) {
            printf("Unable to create texture from rendered text!\n"
                   "SDL2 Error: %s\n", SDL_GetError());
        }

        // Get text dimensions
        animation->textRect.w = textSurface->w;
        animation->textRect.h = textSurface->h;

        SDL_FreeSurface(textSurface);
    }
    animation->textRect.x = 200;
    animation->textRect.y = 300;


    SDL_RenderCopy(animation->renderer, animation->text, NULL, &animation->textRect);


}

bool Animation_load(Animation *animation)
{
    // Load the ocean image



    if(!Background_load(animation->renderer, &animation->background, OCEAN_IMG))
       return false;



    // Background move direction
    animation->background.direction = DIRECTION_DOWN;




    // Background speed in pixel/second
    animation->background.speed = OCEAN_SPEED;



    if(!Spongebob_load(animation->renderer, &animation->spongebob, SPONGEBOB0_IMG,SPONGEBOB1_IMG))
        {
            Background_destroy(&animation->background);
            return false;
        }
    animation->spongebob.state=0;
    animation->spongebob.level = 2;




    animation->spongebob.margin = SPONGEBOB0_MARGIN;
     animation->spongebob.margin = SPONGEBOB1_MARGIN;



    // Set spongebob initial position
    Spongebob_setX(&animation->spongebob, 630); // Horiz. center
    Spongebob_setY(&animation->spongebob, 133);




    // Spongebob move direction
    animation->spongebob.direction = DIRECTION_STOP;




    // Spongebob move speed in pixel/second
    animation->spongebob.speed = SPONGEBOB0_SPEED;
    animation->spongebob.speed = SPONGEBOB1_SPEED;




    if(!Plankton_load(animation->renderer, &animation->plankton, PLANKTON_IMG))
    {
        Background_destroy(&animation->background);
        return false;
    }


    animation->plankton.level = 2;
    animation->plankton.level =1;

    animation->plankton.margin = PLANKTON_MARGIN;



    // Set spongebob initial position
    Plankton_setX(&animation->plankton,600); // Horiz. center
    Plankton_setY(&animation->plankton, 110);



    // Spongebob move direction
    animation->plankton.direction = DIRECTION_STOP;



    // Spongebob move speed in pixel/second
    animation->plankton.speed = PLANKTON_SPEED;





    if(!Yellow_load(animation->renderer, &animation->yellow, YELLOW_IMG))
        {
            Background_destroy(&animation->background);
            return false;
        }


    animation->yellow.margin = YELLOW_MARGIN;




    // Set spongebob initial position
    Yellow_setX(&animation->yellow, 80); // Horiz. center
    Yellow_setY(&animation->yellow, 480);




    if(!Burger_load(animation->renderer, &animation->burger, BURGER_IMG))
        {
            Background_destroy(&animation->background);
            return false;
        }


    animation->burger.margin = BURGER_MARGIN;




    // Set spongebob initial position
    Burger_setX(&animation->burger,39); // Horiz. center
    Burger_setY(&animation->burger, 50);



    if(!Burger1_load(animation->renderer, &animation->burger1, BURGER1_IMG))
        {
            Background_destroy(&animation->background);
            return false;
        }


    animation->burger1.margin = BURGER1_MARGIN;




    // Set spongebob initial position
    Burger1_setX(&animation->burger1,700); // Horiz. center
    Burger1_setY(&animation->burger1,275);



  if(!Anchor_load(animation->renderer, &animation->anchor, ANCHOR_IMG))
        {
            Background_destroy(&animation->background);
            return false;
        }


    animation->anchor.margin = ANCHOR_MARGIN;




    // Set spongebob initial position
    Anchor_setX(&animation->anchor,450); // Horiz. center
    Anchor_setY(&animation->anchor,500);





    // Spongebob move direction
    animation->anchor.direction = DIRECTION_STOP;




    // Spongebob move speed in pixel/second
    animation->anchor.speed = ANCHOR_SPEED;





    if(!Anchor1_load(animation->renderer, &animation->anchor1, ANCHOR1_IMG))
        {
            Background_destroy(&animation->background);
            return false;
        }

    animation->anchor1.margin = ANCHOR1_MARGIN;


    // Set spongebob initial position
    Anchor1_setX(&animation->anchor1,300); // Horiz. center
    Anchor1_setY(&animation->anchor1,500);


    // Spongebob move direction
    animation->anchor1.direction = DIRECTION_STOP;
    // Spongebob move speed in pixel/second
    animation->anchor1.speed = ANCHOR1_SPEED;






    if(!Jellyfish_load(animation->renderer, &animation->jellyfish, JELLYFISH_IMG))
        {
            Background_destroy(&animation->background);
            return false;
        }

    animation->jellyfish.margin = JELLYFISH_MARGIN;


    // Set spongebob initial position
    Jellyfish_setX(&animation->jellyfish,310); // Horiz. center
    Jellyfish_setY(&animation->jellyfish,335);


    // Spongebob move direction
    animation->jellyfish.direction = DIRECTION_STOP;
    // Spongebob move speed in pixel/second
    animation->jellyfish.speed = JELLYFISH_SPEED;




    animation->font = TTF_OpenFont(FONT_PATH, 40);
        if(!animation->font) {
            printf("Unable to load font: '%s'!\n"
                   "SDL2_ttf Error: %s\n", FONT_PATH, TTF_GetError());

            return 0;
        }




        // Load .WAV sound
                Mix_Chunk *sound = Mix_LoadWAV(SPONGEBOB_SOUND);
                if(!sound)
                {
                    printf(".WAV sound '%s' could not be loaded!\n"
                           "SDL_Error: %s\n", SPONGEBOB_SOUND, SDL_GetError());
                   return 0;
                }
                //Play .WAV sound
                if(Mix_PlayChannel(-1, sound, 0) == -1)
                {
                    printf("the sound could not be played!\n"
                           "SDL_Error: %s\n", SDL_GetError());
                    Mix_FreeChunk(sound);
                    return 0;
                }

       return true;
}

void Animation_destroy(Animation *animation)
{
    Spongebob_destroy(&animation->spongebob);
    Plankton_destroy(&animation->plankton);
    Yellow_destroy(&animation->yellow);
    Burger_destroy(&animation->burger);
    Burger1_destroy(&animation->burger1);
    Anchor_destroy(&animation->anchor);
    Anchor1_destroy(&animation->anchor1);
    Jellyfish_destroy(&animation->jellyfish);
    Background_destroy(&animation->background);

}

bool Animation_handleEvent(Animation *animation, SDL_Event *e )
{
    bool quit = false;

    // User requests quit
    if(e->type == SDL_QUIT)
    {
        quit = true;
    }
    else if(e->type == SDL_KEYDOWN)
    {
        switch (e->key.keysym.sym)
        {
        case SDLK_ESCAPE:
            quit = true;
            break;


        case SDLK_SPACE:
                    if(Mix_Paused(-1))
                        Mix_Resume(-1);
                    else
                        Mix_Pause(-1);
                    break;

        case SDLK_w:
        case SDLK_d:
        case SDLK_a:



        Plankton_setDirection(&animation->plankton, e->key.keysym.sym);

        break;



        case SDLK_UP:
        case SDLK_RIGHT:
        case SDLK_LEFT:



       Spongebob_setDirection(&animation->spongebob, e->key.keysym.sym);



            break;
        }
    }
    else if(e->type == SDL_KEYUP)
    {
        switch (e->key.keysym.sym)
        {
        case SDLK_w:
        //case SDLK_s:
        case SDLK_d:
        case SDLK_a:


            Plankton_unsetDirection(&animation->plankton, e->key.keysym.sym);



            break;

        case SDLK_UP:
       //case SDLK_DOWN:
        case SDLK_RIGHT:
        case SDLK_LEFT:



            Spongebob_unsetDirection(&animation->spongebob, e->key.keysym.sym);

            break;
        }
    }

    return quit;
}




void Animation_update(Animation *animation, int framerate)
{
    // Move

    Spongebob_move(&animation->spongebob,animation,&animation->jellyfish,&animation->burger,&animation->burger1, animation->width, animation->height, framerate);
    Plankton_move(&animation->plankton, animation,&animation->jellyfish,&animation->burger,&animation->burger1, animation->width, animation->height, framerate);
    Anchor_move(&animation->anchor,animation->height, framerate);
    Anchor1_move(&animation->anchor1,animation->height, framerate);
    Jellyfish_move(&animation->jellyfish,animation,&animation->spongebob, animation->width, framerate);
    Burger_move(&animation->burger,animation,&animation->spongebob, animation->width, framerate);
}




void Animation_render(Animation *animation)
{
    // Render ocean
    Background_render(animation->renderer, &animation->background, animation->width, animation->height);

    // Render spongebob
    Spongebob_render(animation->renderer, &animation->spongebob);
    Plankton_render(animation->renderer, &animation->plankton);
    Yellow_render(animation->renderer, &animation->yellow);
    Burger_render(animation->renderer, &animation->burger);
    Burger1_render(animation->renderer, &animation->burger1);
    Anchor_render(animation->renderer, &animation->anchor);
    Anchor1_render(animation->renderer, &animation->anchor1);
    Jellyfish_render(animation->renderer, &animation->jellyfish);


    if(animation->gameover)
    {

         Animation_text(animation);

    }
}
