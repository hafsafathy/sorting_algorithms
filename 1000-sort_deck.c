#include "deck.h"

int strcomp(const char *s1, const char *s2);
char getval(deck_node_t *card);
void kind(deck_node_t **deck);
void value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * strcomp - Compares two strings
 * @s1: The first string to be compare
 * @s2: The second string to be compare
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int strcomp(const char *s1, const char *s2)
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
 * getval - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 * Return: The numerical value of the card.
 */
char getval(deck_node_t *card)
{
	if (strcomp(card->card->value, "Ace") == 0)
		return (0);
	if (strcomp(card->card->value, "1") == 0)
		return (1);
	if (strcomp(card->card->value, "2") == 0)
		return (2);
	if (strcomp(card->card->value, "3") == 0)
		return (3);
	if (strcomp(card->card->value, "4") == 0)
		return (4);
	if (strcomp(card->card->value, "5") == 0)
		return (5);
	if (strcomp(card->card->value, "6") == 0)
		return (6);
	if (strcomp(card->card->value, "7") == 0)
		return (7);
	if (strcomp(card->card->value, "8") == 0)
		return (8);
	if (strcomp(card->card->value, "9") == 0)
		return (9);
	if (strcomp(card->card->value, "10") == 0)
		return (10);
	if (strcomp(card->card->value, "Jack") == 0)
		return (11);
	if (strcomp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * kind - Sort a deck of cards
 * @deck: pointer
 * Return: nothing
 */
void kind(deck_node_t **deck)
{
	deck_node_t *i, *ins, *t;

	for (i = (*deck)->next; i != NULL; i = t)
	{
		t = i->next;
		ins = i->prev;
		while (ins != NULL && ins->card->kind > i->card->kind)
		{
			ins->next = i->next;
			if (i->next != NULL)
				i->next->prev = ins;
			i->prev = ins->prev;
			i->next = ins;
			if (ins->prev != NULL)
				ins->prev->next = i;
			else
				*deck = i;
			ins->prev = i;
			ins = i->prev;
		}
	}
}

/**
 * value - Sort a deck of cards sorted from
 * @deck: pointer
 * Return: nothing
 */
void value(deck_node_t **deck)
{
	deck_node_t *i, *ins, *t;

	for (i = (*deck)->next; i != NULL; i = t)
	{
		t = i->next;
		ins = i->prev;
		while (ins != NULL &&
		       ins->card->kind == i->card->kind &&
		       getval(ins) > getval(i))
		{
			ins->next = i->next;
			if (i->next != NULL)
				i->next->prev = ins;
			i->prev = ins->prev;
			i->next = ins;
			if (ins->prev != NULL)
				ins->prev->next = i;
			else
				*deck = i;
			ins->prev = i;
			ins = i->prev;
		}
	}
}

/**
 * sort_deck -  function that sorts a deck of cards
 * @deck: pointer
 * Return: nothing
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	kind(deck);
	value(deck);
}
