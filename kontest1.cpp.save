#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Card {
    char rank;    // достоинство
    char suit;    // мать
};

int comparator (const void *string1, const void *string2);

int main()
{
    int kolvo = 0 ;
    scanf ("%i\n", &kolvo);

    char karta[2] ;
    Card* cards = (Card*) calloc (kolvo, sizeof (Card));

    for (int i = 0; i < kolvo; )
    {
        scanf ("%c", &(karta[0]));
        scanf ("%c", &(karta[1]));

        cards[i].rank = karta[0];
        cards[i].suit = karta[1];

        i++;
    }

    qsort (cards, kolvo, sizeof (Card), comparator);

    for (int i = 0; i < kolvo; )
    {
        printf("%c%c", cards[i].rank, cards[i].suit);
        i++;
    }
    printf("\n");
    free(cards);
    return 0;




}


int comparator (const void *string1, const void *string2)
{
    Card* card1 = (Card*) string1;
    Card* card2 = (Card*) string2;
    int rank1 = 0;
    int rank2 = 0;
    int suit1 = 0;
    int suit2 = 0;
    //printf("%c%c", card1->rank, card1->suit);
    //printf("%c%c\n", card2->rank, card2->suit);

    switch (card1->rank)
    {
        case '2' :
            rank1 = 1; break;
        case '3' :
            rank1 = 2; break;
        case '4' :
            rank1 = 3; break;
        case '5' :
            rank1 = 4; break;
        case '6' :
            rank1 = 5; break;
        case '7' :
            rank1 = 6; break;
        case '8' :
            rank1 = 7; break;
        case '9' :
            rank1 = 8; break;
        case 'T' :
            rank1 = 9; break;
        case 'J' :
            rank1 = 10; break;
        case 'Q' :
            rank1 = 11; break;
        case 'K' :
            rank1 = 12; break;
        case 'A' :
            rank1 = 13; break;
    }
// printf ("rank 1 = %i\n", rank1);

    switch (card2->rank)
    {
        case '2' :
            rank2 = 1; break;
        case '3' :
            rank2 = 2; break;
        case '4' :
            rank2 = 3; break;
        case '5' :
            rank2 = 4; break;
        case '6' :
            rank2 = 5; break;
        case '7' :
            rank2 = 6; break;
        case '8' :
            rank2 = 7; break;
        case '9' :
            rank2 = 8; break;
        case 'T' :
            rank2 = 9; break;
        case 'J' :
            rank2 = 10; break;
        case 'Q' :
            rank2 = 11; break;
        case 'K' :
            rank2 = 12; break;
        case 'A' :
            rank2 = 13; break;
    }
//printf ("rank 2 = %i\n", rank2);

    switch (card1->suit)
    {
        case 'c' :
            suit1 = 1; break;
        case 's' :
            suit1 = 2; break;
        case 'h' :
            suit1 = 3; break;
        case 'd' :
            suit1 = 4; break;

    }

    switch (card2->suit)
    {
        case 'c' :
            suit2 = 1; break;
        case 's' :
            suit2 = 2; break;
        case 'h' :
            suit2 = 3; break;
        case 'd' :
            suit2 = 4; break;

    }

    if (rank1 < rank2)
        return -1;
    if (rank1 > rank2)
        return 1;
    if (rank1 == rank2)
    {
        if (suit1 < suit2)
            return -1;
        if (suit1 > suit2)
            return 1;
        if (suit1 == suit2)
            return 0;
    }
//char xuimeniazaebalkontest_pravila_oformlenia_zasunte_sebe_v_o44444ko ="xui";
    return 0;
}



