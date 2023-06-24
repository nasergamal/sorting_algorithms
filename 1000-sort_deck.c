#include "deck.h"

/**
 * comparator - qsort comparison function
 * @p1: first value pointer
 * @p2: 2nd value pointer
 *
 * Return: comparison result (negative if lesser positive if bigger;
 */
int comparator(const void *p1, const void *p2)
{
	const card_t *ptr1 = (card_t *)p1;
	const card_t *ptr2 = (card_t *)p2;
	char *cards[] = {"Ace", "2", "3", "4", "5", "6", "7", "8",
			"9", "10", "Jack", "Queen", "King"};
	int i, c1 = 13, c2 = 13, d = 0;

	d = ptr1->kind - ptr2->kind;
	if (d == 0)
	{
		for (i = 0; i < 13; i++)
		{
			if (strcmp(ptr1->value, cards[i]) == 0)
			{
				c1 = i;
			}
			if (strcmp(ptr2->value, cards[i]) == 0)
			{	c2 = i; }
			d = c1 - c2;
		}
	}
	return (d);
}

/**
 * sort_deck - sort a deck of cards
 * @deck: the deck to be sorted
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	const card_t *card = (*deck)->card;

	qsort((void *)card, 52, sizeof(card_t), comparator);
}
