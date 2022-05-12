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

#include "yellow.h"
bool Yellow_load(SDL_Renderer *renderer, Yellow *yellow, const char* image)
{
    // Load plane image
    if(!Image_load(renderer, &yellow->image, image))
    {
        return false;
    }
    return true;
}

void Yellow_destroy(Yellow *yellow)
{
    Image_destroy(&yellow->image);

}

void Yellow_setX(Yellow *yellow, int x)
{

    yellow->image.rect.x = x;
}

void Yellow_setY(Yellow *yellow, int y)
{
    //  y coordinate
    yellow->image.rect.y = y;


}

void Yellow_setCoordinates(Yellow *yellow, int x, int y)
{
    Yellow_setX(yellow, x);
    Yellow_setY(yellow, y);
}


void Yellow_render(SDL_Renderer *renderer, Yellow *yellow)
{


     //Render plane
   Image_render(renderer, &yellow->image);

}

