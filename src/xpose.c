/*
    This file is part of Chordii.

    Chordii is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Chordii is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Chordii.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "chordii.h"

extern int grid_size;
extern int transpose;

extern char *mesg;

int do_transpose ( chord )
char *chord;
{

/*

attempting parsing

1) look for a known note name at start of name
2) copy literally until delimiter found 
3) repeat

*/
int i,j;
int p_chord, p_new_chord;
int sharp, flat, new_i;
char new_chord[MAXTOKEN];
static char *notes[] = { "C", "D", "E", "F", "G", "A", "B" };

p_chord = 0;
p_new_chord = 0;

while (TRUE)
	{
	/* Find basic note */
	i=0;
	while ( (i < 7) && (strncmp ( chord + p_chord, notes[i], strlen (notes[i]))) )
		i++;
	
	if (i >= 7) 
		return(1);
	
	/* Look for sharp or flat */
	p_chord += strlen(notes[i]);
	flat = ( chord[p_chord] == 'b');
	sharp = ( chord[p_chord] == '#');
	if (sharp || flat) p_chord++;
	
	
	/*compute new chord name */
	
	new_i = i;


	/* moving upscale ... */
	if (transpose > 0) 
		for (j=0; j < transpose; j++)
			if (sharp)
				{
				sharp = 0;
				new_i = (new_i + 1) % 7;
				}
			else
				if (flat)
					flat = 0;
				else 
					if ((new_i == 2) || (new_i == 6))
						new_i = (new_i + 1) % 7;
					else 
						sharp++;
	

	/* moving downscale ... */
	else
		for (j=0; j > transpose; j--)
			if (flat)
				{
				flat = 0;
				new_i = (new_i + 6) % 7;
				}
			else
				if (sharp)
					sharp = 0;
				else 
					if ((new_i == 3) || (new_i == 0))
						new_i = (new_i + 6) % 7;
					else 
						flat++;
	
	
	sprintf ( (char*)new_chord+p_new_chord, "%s", notes[new_i]);
	p_new_chord += strlen(notes[new_i]);
	
	if (sharp) sprintf( (char*)new_chord + p_new_chord++, "#");
	if (flat) sprintf( (char*)new_chord + p_new_chord++, "b");
	
	while ((chord[p_chord] != '/') && (chord[p_chord] != '\0'))
		new_chord[p_new_chord++] = chord[p_chord++];
	
	if (chord[p_chord] == '\0')
		{
		new_chord[p_new_chord] = '\0';
		sprintf (mesg, "[%s] becomes [%s]", chord, new_chord);
		debug (mesg);
		strcpy(chord, new_chord);
		return(0);
		}

	p_chord++;
	new_chord[p_new_chord++] = '/';
	}
}
