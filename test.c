/**
 * @file test.c
 * @author Shivek Lekhi
 * @brief Structures 
 * @version 0.1
 * @date 2022-05-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/**
 * @brief Structure definition, can't have a member of its own type 
 *        but a pointer pointing to its own type is ok.
 *          Definitions does not acquire any memory rather it makes
 *          another type of variable.
 * 
 */

const char *n_suite[4] = {"hukum", "iit", "paan", "chidii"};
const char *n_face[13] = { "ikka", "Dukka", "Tikki", "choka",
 "panji", "chikki", "satti", "atthi",
 "nela", "dela", "gulaam", "raani", "baadshah" };

typedef struct deck
{
    char *face;
    char *suite;
} Card;                     //Instances can be incorporated in the structure definition.

Card taash[52];

void basics()
{
    Card pile2, *ps ,pile1 = {"Three", "Spades"};                        //Structures initialization methods
    pile2 = pile1;                                                       //Operations on structures are assignment operator for same type of structure objects.
    ps = &pile1;                                                         //Initialization of a pointer pointing to structure type.

    printf("struct member are %s, %s\n ", ps->face, pile1.suite);           //Access structure member using -> and . operator.
}

void print_taash()
{
    for (uint8_t patta = 0; patta < 52; patta++)
    {
        printf("patta[%d] = %s of %s \n", patta, taash[patta].face, taash[patta].suite);
    }
}

void fill()
{
    for (uint8_t patta = 0; patta < 52; patta++)
    {
        taash[patta].face = (char *)n_face[patta % 13];
        taash[patta].suite = (char *)n_suite[patta / 13];
    }
    
    print_taash();
}

void shuffle()
{
    Card temp = taash[0];
    size_t ind = 0;
    for (uint8_t patta = 0; patta < 52; patta++)
    {
        ind = rand() % 52;
        temp = taash[patta];
        taash[patta] = taash[ind];
        taash[ind] = temp;
    }
    print_taash();
}

void main()
{
    int i = 0;
    printf("Started\n");
    
    //basics();

    fill();

    printf("\n Shuffling \n");
    shuffle();

    return;
}