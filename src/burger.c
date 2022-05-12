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

#include "burger.h"

bool Burger_load(SDL_Renderer *renderer, Burger *burger, const char* image)
{
    // Load plane image
    if(!Image_load(renderer, &burger->image, image))
    {
        return false;
    }
    return true;
}


void Burger_destroy(Burger *burger)
{
    Image_destroy(&burger->image);

}

void Burger_setX(Burger *burger, int x)
{

    burger->image.rect.x = x;
}

void Burger_setY(Burger *burger, int y)
{
    // Spongebob y coordinate
    burger->image.rect.y = y;


}

void Burger_setCoordinates(Burger *burger, int x, int y)
{
    Burger_setX(burger, x);
    Burger_setY(burger, y);
}


void Burger_render(SDL_Renderer *renderer, Burger *burger)
{


    // Render plane
    Image_render(renderer, &burger->image);
}

bool Burger1_load(SDL_Renderer *renderer, Burger1 *burger1, const char* image)
{
    // Load plane image
    if(!Image_load(renderer, &burger1->image, image))
    {
        return false;
    }
    return true;
}


void Burger1_destroy(Burger1 *burger1)
{
    Image_destroy(&burger1->image);

}

void Burger1_setX(Burger1 *burger1, int x)
{

    burger1->image.rect.x = x;
}

void Burger1_setY(Burger1 *burger1, int y)
{
    // Spongebob y coordinate
    burger1->image.rect.y = y;


}

void Burger1_setCoordinates(Burger1 *burger1, int x, int y)
{
    Burger1_setX(burger1, x);
    Burger1_setY(burger1, y);
}


void Burger1_render(SDL_Renderer *renderer, Burger1 *burger1)
{


    // Render plane
    Image_render(renderer, &burger1->image);
}

void Burger_move(Burger *burger,Animation *animation,Spongebob *spongebob,int screenWidth, int framerate)
{
}




