#include "beer_song.h"

void recite(unsigned int start_bottles, unsigned int take_down, char *buffer)
{

	int start_over = 99;

	for(; take_down != 0; start_bottles--, take_down--)
	{

		size_t buffer_len;

		if(start_bottles == 2)
		{
			buffer_len = sprintf(buffer,
			"%i bottles of beer on the wall, %i bottles of beer.\n"
			"Take one down and pass it around, %i bottle of beer on the wall.\n"
			, start_bottles, start_bottles, start_bottles - 1);
		}
		else if(start_bottles == 1)
		{
			buffer_len = sprintf(buffer,
			"%i bottle of beer on the wall, %i bottle of beer.\n"
			"Take it down and pass it around, no more bottles of beer on the wall.\n"
			, start_bottles, start_bottles);
		}
		else if(start_bottles == 0)
		{
			buffer_len = sprintf(buffer,
			"No more bottles of beer on the wall, no more bottles of beer.\n"
			"Go to the store and buy some more, %i bottles of beer on the wall.\n"
			, start_over);
		}
		else
		{
			buffer_len = sprintf(buffer,
			"%i bottles of beer on the wall, %i bottles of beer.\n"
			"Take one down and pass it around, %i bottles of beer on the wall.\n"
			, start_bottles, start_bottles, start_bottles - 1);
		}

		buffer += buffer_len;

		if(take_down > 1)
		{
			buffer_len = sprintf(buffer, "%c", '\n');
			buffer += buffer_len;
		}

	}
}
