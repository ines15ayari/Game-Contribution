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

#include "character.h"
#include "animation.h"
#include "jellyfish.h"
#include "burger.h"


bool Spongebob_load(SDL_Renderer *renderer, Spongebob *spongebob, const char *image, const char *image1)
{
    // Load spongebob image
    if(!Image_load(renderer, &spongebob->image, image))
    {
        return false;
    }

    if(!Image_load(renderer, &spongebob->image1, image1))
    {
        return false;
    }

    return true;
}
void Spongebob_destroy(Spongebob *spongebob)
{
    Image_destroy(&spongebob->image);
    Image_destroy(&spongebob->image1);
}
void Spongebob_setX(Spongebob *spongebob, int x)
{
    spongebob->image.rect.x = x;
    spongebob->image1.rect.x = x;
}
void Spongebob_setY(Spongebob *spongebob, int y)
{
    // Spongebob y coordinate
    spongebob->image.rect.y = y;
    spongebob->image1.rect.y = y;
}
void Spongebob_setCoordinates(Spongebob *spongebob, int x, int y)
{
    Spongebob_setX(spongebob, x);
    Spongebob_setY(spongebob, y);
}
void Spongebob_moveX(Spongebob *spongebob, int x)
{
    Spongebob_setX(spongebob, spongebob->image.rect.x + x);
}
void Spongebob_moveY(Spongebob *spongebob, int y)
{
    Spongebob_setY(spongebob, spongebob->image.rect.y + y);
}
void Spongebob_setDirection(Spongebob *spongebob, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_UP:
        spongebob->direction &= ~DIRECTION_DOWN;
        spongebob->direction |= DIRECTION_UP;

        break;
   case SDLK_DOWN:
        spongebob->direction &= ~DIRECTION_UP;
        spongebob->direction |= DIRECTION_DOWN;
        break;
    case SDLK_RIGHT:
        spongebob->direction &= ~DIRECTION_LEFT;
        spongebob->direction |= DIRECTION_RIGHT;
        break;
    case SDLK_LEFT:
        spongebob->direction &= ~DIRECTION_RIGHT;
        spongebob->direction |= DIRECTION_LEFT;
        break;
    }
}
void Spongebob_unsetDirection(Spongebob *spongebob, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_UP:
        spongebob->direction &= ~DIRECTION_UP;
        break;
    case SDLK_DOWN:
        spongebob->direction &= ~DIRECTION_DOWN;
        break;
    case SDLK_RIGHT:
        spongebob->direction &= ~DIRECTION_RIGHT;
        break;
    case SDLK_LEFT:
        spongebob->direction &= ~DIRECTION_LEFT;
        break;
    }
}
void Spongebob_render(SDL_Renderer *renderer, Spongebob *spongebob)
{
    // Render spongebob
    if(spongebob->state==0)
    {
        Image_render(renderer, &spongebob->image);
    }
    if(spongebob->state==1)
    {
        Image_render(renderer, &spongebob->image1);
    }

}
void Spongebob_move(Spongebob *spongebob,Animation *animation,Jellyfish *jellyfish,Burger *burger,Burger1 *burger1, int screenWidth, int screenHeight, int framerate)
{
    int spongebobStep = spongebob->speed / framerate;
    if( (spongebob->direction & DIRECTION_UP))
    {


        Spongebob_moveY(spongebob, -spongebobStep);

        spongebob->state++;
        if(spongebob->state==2)
        {
            spongebob->state=0;
        }

        if (spongebob->level == 2 && spongebob->image.rect.y < 10){
            Spongebob_setDirection(spongebob, SDLK_DOWN);
        }
        else if(spongebob->level ==1 && spongebob->image.rect.y<200)
        {
            Spongebob_setDirection(spongebob, SDLK_DOWN);
        }
        else if(spongebob->level ==0 && spongebob->image.rect.y<430)
        {
            Spongebob_setDirection(spongebob, SDLK_DOWN);
        }
        }
    else if( (spongebob->direction & DIRECTION_DOWN)
             && spongebob->image.rect.y + spongebob->image.rect.h + spongebobStep <= screenHeight - spongebob->margin)
    {
        if (spongebob->level == 2 && spongebob->image.rect.y < 10) {
            Spongebob_moveY(spongebob, spongebobStep);
        } else if (spongebob->level == 1 && spongebob->image.rect.y < 300) {
            Spongebob_moveY(spongebob, spongebobStep);
        }  else if (spongebob->level == 0 && spongebob->image.rect.y < 500) {
            Spongebob_moveY(spongebob, spongebobStep);
        }


        else {
            Spongebob_unsetDirection(spongebob, SDLK_DOWN);
        }
        // spongebob collision with jellyfish
         if (spongebob->image.rect.y + spongebob->image.rect.h >animation->jellyfish.image.rect.y
                &&animation->jellyfish.image.rect.y>spongebob->image.rect.y)
        {
           // animation->gameover= true;
             Jellyfish_setY(jellyfish, -jellyfish->image.rect.h);
        }

    }
   if( (spongebob->direction & DIRECTION_RIGHT)
            && spongebob->image.rect.x + spongebob->image.rect.w + spongebobStep <= screenWidth - spongebob->margin)
    {
        Spongebob_moveX(spongebob, spongebobStep);


        spongebob->state++;
        if(spongebob->state==2)
        {
            spongebob->state=0;
        }

        if (spongebob->image.rect.x > 650) {
            spongebob->level = 0;
            Spongebob_setDirection(spongebob, SDLK_DOWN);
     }
        // spongebob collision with burger
      if (spongebob->image.rect.x + spongebob->image.rect.w >animation->burger1.image.rect.x
                &&animation->burger1.image.rect.x>spongebob->image.rect.x
                &&spongebob->image.rect.y + spongebob->image.rect.h >animation->burger1.image.rect.y)
        {

           Burger1_setY(burger1, -burger1->image.rect.h);

        }

    }
    else if( (spongebob->direction & DIRECTION_LEFT)
             && spongebob->image.rect.x - spongebobStep >= spongebob->margin)
    {

        Spongebob_moveX(spongebob, -spongebobStep);
        spongebob->state++;
        if(spongebob->state==2)
        {
            spongebob->state=0;
        }

        if (spongebob->image.rect.x < 70) {
            spongebob->level = 1;
            Spongebob_setDirection(spongebob, SDLK_DOWN);
        }
        // spongebob collision with key
        if (spongebob->image.rect.x + spongebob->image.rect.w >animation->yellow.image.rect.x
                &&animation->yellow.image.rect.x>spongebob->image.rect.x
                &&spongebob->image.rect.y + spongebob->image.rect.h >animation->yellow.image.rect.y)
        {
            animation->gameover= true;

        }

        // spongebob collision with burger
      if (spongebob->image.rect.x + spongebob->image.rect.w >animation->burger.image.rect.x
                &&animation->burger.image.rect.x>spongebob->image.rect.x
                &&spongebob->image.rect.y + spongebob->image.rect.h >animation->burger.image.rect.y)
        {

           Burger_setY(burger, -burger->image.rect.h);

        }
    }

}

bool Plankton_load(SDL_Renderer *renderer, Plankton *plankton, const char *image)
{
    // Load spongebob image
    if(!Image_load(renderer, &plankton->image, image))
    {
        return false;
    }


    return true;
}

void Plankton_destroy(Plankton *plankton)
{
    Image_destroy(&plankton->image);

}

void Plankton_setX(Plankton *plankton, int x)
{
    // Spongebob x coordinate
    plankton->image.rect.x = x;


}
void Plankton_setY(Plankton *plankton, int y)
{
    // Spongebob y coordinate
    plankton->image.rect.y = y;
}

void Plankton_setCoordinates(Plankton *plankton, int x, int y)
{
    Plankton_setX(plankton, x);
    Plankton_setY(plankton, y);
}

void Plankton_moveX(Plankton *plankton, int x)
{
    Plankton_setX(plankton, plankton->image.rect.x + x);
}

void Plankton_moveY(Plankton *plankton, int y)
{
    Plankton_setY(plankton, plankton->image.rect.y + y);
}

void Plankton_setDirection(Plankton *plankton, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_w:
        plankton->direction &= ~DIRECTION_DOWN;
        plankton->direction |= DIRECTION_UP;
        break;

    case SDLK_s:
        plankton->direction &= ~SDLK_UP;
       plankton->direction |= DIRECTION_DOWN;
        break;

    case SDLK_d:
        plankton->direction &= ~SDLK_LEFT;
        plankton->direction |= DIRECTION_RIGHT;
        break;

    case SDLK_a:
        plankton->direction &= ~DIRECTION_RIGHT;
        plankton->direction |= DIRECTION_LEFT;
        break;
    }
}

void Plankton_unsetDirection(Plankton *plankton, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_w:
        plankton->direction &= ~DIRECTION_UP;
        break;

    case SDLK_s:
       plankton->direction &= ~DIRECTION_DOWN;
        break;

    case SDLK_d:
       plankton->direction &= ~DIRECTION_RIGHT;
       break;

    case SDLK_a:
        plankton->direction &= ~DIRECTION_LEFT;
        break;
    }
}

void Plankton_render(SDL_Renderer *renderer, Plankton *plankton)
{

    // Render spongebob
    Image_render(renderer, &plankton->image);
}

void Plankton_move(Plankton *plankton,Animation *animation,Jellyfish *jellyfish,Burger *burger,Burger1 *burger1, int screenWidth, int screenHeight, int framerate)
{
    int planktonStep = plankton->speed / framerate;

    if( (plankton->direction & DIRECTION_UP))

    {
        Plankton_moveY(plankton, -planktonStep);
        if (plankton->level == 2 && plankton->image.rect.y < 10){
            Plankton_setDirection(plankton, SDLK_s);
            }
            else if(plankton->level ==1 && plankton->image.rect.y<600)
            {
                Plankton_setDirection(plankton, SDLK_s);
            }
            else if(plankton->level ==0 && plankton->image.rect.y<430)
            {
                Plankton_setDirection(plankton, SDLK_s);
            }
            }

    else if( (plankton->direction & DIRECTION_DOWN)
             && plankton->image.rect.y + plankton->image.rect.h + planktonStep <= screenHeight - plankton->margin)
    {
        if (plankton->level == 2 && plankton->image.rect.y < 100) {
        Plankton_moveY(plankton,  planktonStep);
        } else if (plankton->level == 1 && plankton->image.rect.y < 300) {
            Plankton_moveY(plankton,  planktonStep);
        }else if (plankton->level == 0 && plankton->image.rect.y < 500) {
            Plankton_moveY(plankton,  planktonStep);
        }
        else {
            Plankton_unsetDirection(plankton, SDLK_s);
        }

        // plankton collision with jellyfish
        if (plankton->image.rect.y + plankton->image.rect.h >animation->jellyfish.image.rect.y
                &&animation->jellyfish.image.rect.y>plankton->image.rect.y)
        {
            Jellyfish_setY(jellyfish, -jellyfish->image.rect.h);
        }

    }
    if( (plankton->direction & DIRECTION_RIGHT)
            && plankton->image.rect.x + plankton->image.rect.w +  planktonStep <= screenWidth - plankton->margin)
    {
        Plankton_moveX(plankton,  planktonStep);
        if (plankton->image.rect.x > 650) {
            plankton->level = 0;
            Plankton_setDirection(plankton, SDLK_s);
        }
        // plankton collision with burger
        if (plankton->image.rect.x + plankton->image.rect.w >animation->burger1.image.rect.x
                 &&animation->burger1.image.rect.x>plankton->image.rect.x
                 &&plankton->image.rect.y + plankton->image.rect.h >animation->burger1.image.rect.y)
         {
             Burger1_setY(burger1, -burger1->image.rect.h);
         }


    }
    else if( (plankton->direction & DIRECTION_LEFT)
             && plankton->image.rect.x -  planktonStep >= plankton->margin)
    {
        Plankton_moveX(plankton, - planktonStep);
        if (plankton->image.rect.x < 70) {
            plankton->level = 1;
            Plankton_setDirection(plankton, SDLK_s);
        }
         // plankton collision with key
        if (plankton->image.rect.x + plankton->image.rect.w >animation->yellow.image.rect.x
                &&animation->yellow.image.rect.x>plankton->image.rect.x
                &&plankton->image.rect.y + plankton->image.rect.h >animation->yellow.image.rect.y)
        {
            animation->gameover= true;
        }

        // plankton collision with burger
       if (plankton->image.rect.x + plankton->image.rect.w >animation->burger.image.rect.x
                &&animation->burger.image.rect.x>plankton->image.rect.x
                &&plankton->image.rect.y + plankton->image.rect.h >animation->burger.image.rect.y)
        {
            Burger_setY(burger, -burger->image.rect.h);
        }


    }
}

