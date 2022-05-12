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

#ifndef CHARACTER_H
#define CHARACTER_H

#include "utils.h"
#include "image.h"


typedef struct Animation Animation;
typedef struct Jellyfish Jellyfish;
typedef struct Burger Burger;
typedef struct Burger1 Burger1;


struct Spongebob
{
    // Spongebob
    Image image;
    Image image1;
    int state;

    // Direction
    Direction direction;

    // Speed in pixel/second
    int speed;

    // Margin
    int margin;
    int level;
};
typedef struct Spongebob Spongebob;


bool Spongebob_load(SDL_Renderer *renderer, Spongebob *spongebob, const char *image, const char *image1);
void Spongebob_destroy(Spongebob *spongebob);

void Spongebob_setX(Spongebob *spongebob, int x);
void Spongebob_setY(Spongebob *spongebob, int y);
void Spongebob_setCoordinates(Spongebob *spongebob, int x, int y);

void Spongebob_moveX(Spongebob *spongebob, int x);
void Spongebob_moveY(Spongebob *spongebob, int y);

void Spongebob_move(Spongebob *spongebob, Animation *animation ,Jellyfish *jellyfish,Burger *burger,Burger1 *burger1,int screenWidth, int screenHeight, int framerate);

void Spongebob_setDirection(Spongebob *spongebob, SDL_Keycode keycode);
void Spongebob_unsetDirection(Spongebob *spongebob, SDL_Keycode keycode);

void Spongebob_render(SDL_Renderer *renderer, Spongebob *spongebob);

struct Plankton
{
    // Plankton
    Image image;


    // Direction
    Direction direction;

    // Speed in pixel/second
    int speed;

    // Margin
    int margin;
    int level;
};
typedef struct Plankton Plankton;


bool Plankton_load(SDL_Renderer *renderer, Plankton *plankton, const char *image1);
void Plankton_destroy(Plankton *plankton);

void Plankton_setX(Plankton *plankton, int x);
void Plankton_setY(Plankton *plankton, int y);
void Plankton_setCoordinates(Plankton *plankton, int x, int y);

void Plankton_moveX(Plankton *plankton, int x);
void Plankton_moveY(Plankton *plankton, int y);

void Plankton_move(Plankton *plankton,Animation *animation,Jellyfish *jellyfish,Burger *burger,Burger1 *burger1, int screenWidth, int screenHeight, int framerate);

void Plankton_setDirection(Plankton *plankton, SDL_Keycode keycode);
void Plankton_unsetDirection(Plankton *plankton, SDL_Keycode keycode);

void Plankton_render(SDL_Renderer *renderer, Plankton *plankton);



#endif // spongebob_H     // Plankton_H
