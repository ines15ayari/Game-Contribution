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

#include "anchor.h"


bool Anchor_load(SDL_Renderer *renderer, Anchor *anchor, const char *image)
{
    // Load plane image
    if(!Image_load(renderer, &anchor->image, image))
    {
        return false;
    }


    return true;

}


void Anchor_destroy(Anchor *anchor)
{
    Image_destroy(&anchor->image);

}

void Anchor_setX(Anchor *anchor, int x)
{

    anchor->image.rect.x = x;
}

void Anchor_setY(Anchor *anchor, int y)
{
    //  y coordinate
    anchor->image.rect.y = y;


}

void Anchor_setCoordinates(Anchor *anchor, int x, int y)
{
    Anchor_setX(anchor, x);
    Anchor_setY(anchor, y);
}

void Anchor_moveX(Anchor *anchor, int x)
{
    Anchor_setX(anchor, anchor->image.rect.x + x);
}

void Anchor_moveY(Anchor *anchor, int y)
{
    Anchor_setY(anchor, anchor->image.rect.y + y);
}

void Anchor_render(SDL_Renderer *renderer, Anchor *anchor)
{


    // Render plane
    Image_render(renderer, &anchor->image);
}

void Anchor_move(Anchor *anchor, int screenHeight, int framerate)
{
    int planeStep = anchor->speed / framerate;
    anchor->image.rect.y += anchor->speed / framerate;
     if(anchor->image.rect.y >= anchor->image.rect.h)
        anchor->image.rect.y = anchor->image.rect.y - anchor->image.rect.h;



    if(anchor->direction & DIRECTION_UP)
      {
          if (! anchor->image.rect.y + anchor->image.rect.h + planeStep - anchor->image.rect.h <= screenHeight - anchor->margin) {
              Anchor_moveY(anchor, planeStep);
          }if (anchor->image.rect.y + anchor->image.rect.h + planeStep - anchor->image.rect.h >= screenHeight - anchor->margin){
              Anchor_setY(anchor, - anchor->image.rect.h);
          }

       }

         else if( (anchor->direction & DIRECTION_DOWN)
                && anchor->image.rect.y - planeStep >= anchor->margin)
       {
           Anchor_moveY(anchor, -planeStep);
       }

   }
bool Anchor1_load(SDL_Renderer *renderer, Anchor1 *anchor1, const char *image)
{
    // Load plane image
    if(!Image_load(renderer, &anchor1->image, image))
    {
        return false;
    }


    return true;

}


void Anchor1_destroy(Anchor1 *anchor1)
{
    Image_destroy(&anchor1->image);

}

void Anchor1_setX(Anchor1 *anchor1, int x)
{

    anchor1->image.rect.x = x;
}

void Anchor1_setY(Anchor1 *anchor1, int y)
{
    //  y coordinate
    anchor1->image.rect.y = y;


}

void Anchor1_setCoordinates(Anchor1 *anchor1, int x, int y)
{
    Anchor1_setX(anchor1, x);
    Anchor1_setY(anchor1, y);
}

void Anchor1_moveX(Anchor1 *anchor1, int x)
{
    Anchor1_setX(anchor1, anchor1->image.rect.x + x);
}

void Anchor1_moveY(Anchor1 *anchor1, int y)
{
    Anchor1_setY(anchor1, anchor1->image.rect.y + y);
}

void Anchor1_render(SDL_Renderer *renderer, Anchor1 *anchor1)
{


    // Render plane
    Image_render(renderer, &anchor1->image);
}

void Anchor1_move(Anchor1 *anchor1, int screenHeight, int framerate)
{
    int planeStep = anchor1->speed / framerate;
    anchor1->image.rect.y += anchor1->speed / framerate;
     if(anchor1->image.rect.y >= anchor1->image.rect.h)
        anchor1->image.rect.y = anchor1->image.rect.y - anchor1->image.rect.h;

    if(anchor1->direction & DIRECTION_UP)
      {
          if (! anchor1->image.rect.y + anchor1->image.rect.h + planeStep - anchor1->image.rect.h <= screenHeight - anchor1->margin) {
              Anchor1_moveY(anchor1, planeStep);
          }if (anchor1->image.rect.y + anchor1->image.rect.h + planeStep - anchor1->image.rect.h >= screenHeight - anchor1->margin){
              Anchor1_setY(anchor1, - anchor1->image.rect.h);
          }

       }

         else if( (anchor1->direction & DIRECTION_DOWN)
                && anchor1->image.rect.y - planeStep >= anchor1->margin)
       {
           Anchor1_moveY(anchor1, -planeStep);
       }

   }



