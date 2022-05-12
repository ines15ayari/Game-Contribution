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

#ifndef BURGER_H
#define BURGER_H


#include "utils.h"
#include "image.h"

typedef struct Animation Animation;
typedef struct Spongebob Spongebob ;


struct Burger
{
    // Yellow

    Image image;

    // Margin
    int margin;


   // bool shown;

};
typedef struct Burger Burger;

bool Burger_load(SDL_Renderer *renderer, Burger *burger, const char* image);
void Burger_destroy(Burger *burger);
void Burger_setX(Burger *burger, int x);
void Burger_setY(Burger *burger, int y);
void Burger_setCoordinates(Burger *burger, int x, int y);
void Burger_render(SDL_Renderer *renderer, Burger *burger);
void Burger_move(Burger *burger,Animation *animation,Spongebob *spongebob, int screenWidth, int framerate);


struct Burger1
{
    // Yellow

    Image image;

    // Margin
    int margin;


   // bool shown;

};
typedef struct Burger1 Burger1;

bool Burger1_load(SDL_Renderer *renderer, Burger1 *burger1, const char* image);
void Burger1_destroy(Burger1 *burger1);
void Burger1_setX(Burger1 *burger1, int x);
void Burger1_setY(Burger1 *burger1, int y);
void Burger1_setCoordinates(Burger1 *burger1, int x, int y);
void Burger1_render(SDL_Renderer *renderer, Burger1 *burger1);

#endif // BURGER_H
