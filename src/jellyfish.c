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

#include "jellyfish.h"
#include "animation.h"
#include "character.h"
bool Jellyfish_load(SDL_Renderer *renderer, Jellyfish *jellyfish, const char *image)
{
    // Load car image
    if(!Image_load(renderer, &jellyfish->image, image))
    {
        return false;
    }

    return true;
}

void Jellyfish_destroy(Jellyfish *jellyfish)
{
    Image_destroy(&jellyfish->image);
}

void Jellyfish_setX(Jellyfish *jellyfish, int x)
{
    // Car x coordinate
    jellyfish->image.rect.x = x;
}

void Jellyfish_setY(Jellyfish *jellyfish, int y)
{
    // Car y coordinate
    jellyfish->image.rect.y = y;

}

void Jellyfish_setCoordinates(Jellyfish *jellyfish, int x, int y)
{
    Jellyfish_setX(jellyfish, x);
    Jellyfish_setY(jellyfish, y);
}

void Jellyfish_moveX(Jellyfish *jellyfish, int x)
{
    Jellyfish_setX(jellyfish, jellyfish->image.rect.x + x);
}

void Jellyfish_moveY(Jellyfish *jellyfish, int y)
{
    Jellyfish_setY(jellyfish, jellyfish->image.rect.y + y);
}


void Jellyfish_render(SDL_Renderer *renderer, Jellyfish *jellyfish)
{

    // Render car
    Image_render(renderer, &jellyfish->image);
}

void Jellyfish_move(Jellyfish *jellyfish,Animation *animation,Spongebob *spongebob,int screenWidth, int framerate)
{
    int spongebobStep = jellyfish->speed / framerate;

    jellyfish->image.rect.x += jellyfish->speed / framerate;
     if(jellyfish->image.rect.x >= jellyfish->image.rect.w)
        jellyfish->image.rect.x = jellyfish->image.rect.w - jellyfish->image.rect.w;

   if(jellyfish->direction & DIRECTION_RIGHT)
    {
        if (! jellyfish->image.rect.x + jellyfish->image.rect.w + spongebobStep - jellyfish->image.rect.w <= screenWidth - jellyfish->margin) {
            Jellyfish_moveX(jellyfish, spongebobStep);
        }if (jellyfish->image.rect.x + jellyfish->image.rect.w + spongebobStep - jellyfish->image.rect.w >= screenWidth - jellyfish->margin){
            Jellyfish_setX(jellyfish, - jellyfish->image.rect.w);
        }

    }
    else if( (jellyfish->direction & DIRECTION_LEFT)
             && jellyfish->image.rect.x - spongebobStep >= jellyfish->margin)
    {
        Jellyfish_moveX(jellyfish, -spongebobStep);
     }
}
