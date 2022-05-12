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

#ifndef JELLYFISH_H
#define JELLYFISH_H


#include "utils.h"
#include "image.h"


typedef struct Animation Animation;
typedef struct Spongebob Spongebob ;

struct Jellyfish
{

    Image image;

    // Direction
    Direction direction;


    // Speed in pixel/second
    int speed;

    // Margin
    int margin;
    int level;
};
typedef struct Jellyfish Jellyfish;

bool Jellyfish_load(SDL_Renderer *renderer, Jellyfish *jellyfish , const char *image);
void Jellyfish_destroy(Jellyfish *jellyfish);
void Jellyfish_setX(Jellyfish *jellyfish, int x);
void Jellyfish_setY(Jellyfish *jellyfish, int y);
void Jellyfish_setCoordinates(Jellyfish *jellyfish, int x, int y);
void Jellyfish_moveX(Jellyfish *jellyfish, int x);
void Jellyfish_moveY(Jellyfish *jellyfish, int y);
void Jellyfish_move(Jellyfish *jellyfish,Animation *animation,Spongebob *spongebob, int screenWidth, int framerate);
void Jellyfish_render(SDL_Renderer *renderer,Jellyfish *jellyfish);
#endif // JELLYFISH_H
