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

#ifndef ANCHOR_H
#define ANCHOR_H

#include "utils.h"
#include "image.h"


typedef struct Animation Animation;


struct Anchor
{
    // Spongebob
    Image image;

    // Direction
    Direction direction;

    // Speed in pixel/second
    int speed;

    // Margin
    int margin;
    int level;
};
typedef struct Anchor Anchor;


bool Anchor_load(SDL_Renderer *renderer, Anchor *anchor , const char *image);
void Anchor_destroy(Anchor *anchor);
void Anchor_setX(Anchor *anchor, int x);
void Anchor_setY(Anchor *anchor, int y);
void Anchor_setCoordinates(Anchor *anchor, int x, int y);
void Anchor_moveX(Anchor *anchor, int x);
void Anchor_moveY(Anchor *anchor, int y);
void Anchor_move(Anchor *anchor, int screenHeight, int framerate);
void Anchor_render(SDL_Renderer *renderer, Anchor *anchor);


struct Anchor1
{
    // Spongebob
    Image image;



    // Direction
    Direction direction;

    // Speed in pixel/second
    int speed;

    // Margin
    int margin;
    int level;
};
typedef struct Anchor1 Anchor1;


bool Anchor1_load(SDL_Renderer *renderer, Anchor1 *anchor1 , const char *image);
void Anchor1_destroy(Anchor1 *anchor1);
void Anchor1_setX(Anchor1 *anchor1, int x);
void Anchor1_setY(Anchor1 *anchor1, int y);
void Anchor1_setCoordinates(Anchor1 *anchor1, int x, int y);
void Anchor1_moveX(Anchor1 *anchor1, int x);
void Anchor1_moveY(Anchor1 *anchor1, int y);
void Anchor1_move(Anchor1 *anchor1, int screenHeight, int framerate);
void Anchor1_render(SDL_Renderer *renderer, Anchor1 *anchor1);



#endif // ANCHOR_H
