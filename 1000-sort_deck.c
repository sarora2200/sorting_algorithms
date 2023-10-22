#include "deck.h"

int _strcomp(const char *s1, const char *s2);
char getValue(deck_node_t *card);
void insertionSortDeckKind(deck_node_t **deck);
void insertionSortDeckValue(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
* _strcomp - function compares two strings.
* @s1: first string to be compared.
* @s2: second string to be compared.
* Return: Positive byte difference if s1 > s2
*         0 if s1 == s2
*         Negative byte difference if s1 < s2
*/
int _strcomp(const char *s1, const char *s2)
{
while (*s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
}

if (*s1 != *s2)
return (*s1 - *s2);
return (0);
}

/**
* getValue - function get the numerical value of a card.
* @card: A pointer to a deck_node_t card.
* Return: The numerical value of the card.
*/
char getValue(deck_node_t *card)
{
if (_strcomp(card->card->value, "Ace") == 0)
return (0);
if (_strcomp(card->card->value, "1") == 0)
return (1);
if (_strcomp(card->card->value, "2") == 0)
return (2);
if (_strcomp(card->card->value, "3") == 0)
return (3);
if (_strcomp(card->card->value, "4") == 0)
return (4);
if (_strcomp(card->card->value, "5") == 0)
return (5);
if (_strcomp(card->card->value, "6") == 0)
return (6);
if (_strcomp(card->card->value, "7") == 0)
return (7);
if (_strcomp(card->card->value, "8") == 0)
return (8);
if (_strcomp(card->card->value, "9") == 0)
return (9);
if (_strcomp(card->card->value, "10") == 0)
return (10);
if (_strcomp(card->card->value, "Jack") == 0)
return (11);
if (_strcomp(card->card->value, "Queen") == 0)
return (12);
return (13);
}

/**
* insertionSortDeckKind - function sort deck of cards from spades to diamonds.
* @deck: A pointer to the head of a deck_node_t doubly-linked list.
*/
void insertionSortDeckKind(deck_node_t **deck)
{
deck_node_t *it, *put, *temp;

for (it = (*deck)->next; it != NULL; it = temp)
{
temp = it->next;
put = it->prev;
while (put != NULL && put->card->kind > it->card->kind)
{
put->next = it->next;
if (it->next != NULL)
it->next->prev = put;
it->prev = put->prev;
it->next = put;
if (put->prev != NULL)
put->prev->next = it;
else
*deck = it;
put->prev = it;
put = it->prev;
}
}
}

/**
* insertionSortDeckValue - function sort a deck of cards sorted from
*                             spades to diamonds from ace to king.
* @deck: A pointer to the head of a deck_node_t doubly-linked list.
*/
void insertionSortDeckValue(deck_node_t **deck)
{
deck_node_t *it, *put, *temp;

for (it = (*deck)->next; it != NULL; it = temp)
{
temp = it->next;
put = it->prev;
while (put != NULL &&
put->card->kind == it->card->kind &&
getValue(put) > getValue(it))
{
put->next = it->next;
if (it->next != NULL)
it->next->prev = put;
it->prev = put->prev;
it->next = put;
if (put->prev != NULL)
put->prev->next = it;
else
*deck = it;
put->prev = it;
put = it->prev;
}
}
}

/**
* sort_deck - Sort a deck of cards from ace to king and
*             from spades to diamonds.
* @deck: A pointer to the head of a deck_node_t doubly-linked list.
*/
void sort_deck(deck_node_t **deck)
{
if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
return;

insertionSortDeckKind(deck);
insertionSortDeckValue(deck);
}
