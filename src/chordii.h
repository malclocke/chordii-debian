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

#ifndef CHORDII_H
#define CHORDII_H

#include "config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef HAVE_UNISTD_H
 #include <unistd.h>
#endif

#define TRUE 1
#define FALSE 0

#define MAXLINE 256
#define MAXFONTS 16   /* Maximum number of different fonts in one execution */
#define MAXTOKEN 256
#define MAX_CHORD 1024
#define CHORD_NAME_SZ   20
#define MAXNOTE 8

#define LONG_FINGERS	4
#define FRET_NONE_STR	"-"		/* fret value for unplayed strings */
#define FRET_NONE	-2		/* internal numeric value */
#define FRET_X_STR	"X"		/* fret value for muted strings */
#define FRET_X		-1		/* internal value (must be -1) */
#define NO_CHORD_STR	"N.C."		/* Indicates No-Chord */
#define BASE_FRET_STR	"base-fret"
#define FRETS_STR	"frets"

#define DELIM_STR       ": \t"

#define DEF_TEXT_SIZE 12
#define DEF_CHORD_SIZE 9
#define DEF_GRID_SIZE 30
#define DEF_TEXT_FONT "Times-Roman"
#define DEF_CHORD_FONT "Helvetica-Oblique"
#define MONOSPACED_FONT "Courier"

#define CHORD_BUILTIN	0
#define CHORD_DEFINED	1
#define CHORD_IN_CHORDRC	2

#define CHORD_EASY	0
#define CHORD_HARD	1

struct kcs {
	struct	kcs *next;
	char	chord_name[CHORD_NAME_SZ];
	int	displ;
	int	s1,s2,s3,s4,s5,s6;
	int	origin;
	int	difficult;
	} dummy_kcs;

struct chord_struct {
	struct chord_struct *next;
	struct kcs *chord;
	} dummy_chord_struct;

struct sub_title_struct {
	struct sub_title_struct *next_sub;
	char *sub_title;
	};

struct toc_struct {
	struct toc_struct *next;
	struct sub_title_struct *sub_titles;
	char *title;
	int page_label;
	};

int do_define_chord();
void build_ps_toc();
void clean_chordtab();
void clean_known_chords();
void do_chorus_line();
void do_end_of_page();
void do_end_of_phys_page();
void do_end_of_song();
void do_init_grid_ps();
void do_new_song();
void do_start_of_page();
void do_subtitle();
void do_title();
void draw_chords();
void dump_chords();
void init_known_chords();
void init_ps();
void init_values();
void print_chord_line ();
void print_re_encode();
void print_text_line();
void print_version();
void read_chordrc();
void set_chord_font();
void use_chord_font();
void use_text_font();

#ifdef  __STDC__
struct chord_struct *add_to_chordtab(char *chord);
void add_title_to_toc(char *title, int page_label);
void add_subtitle_to_toc(char *subtitle);
int do_transpose(char *chord);
struct kcs *get_kc_entry (char *chord);
void advance(int amount);
void debug(char *dbg_str);
void do_chord (int i_text, char *chord);
void do_comment(char *comment, int style);
void do_directive(char *directive);
void do_help (char *command) ;
void dump_fret(int fretnum);
void error(char *error);
void error_rt(char *error);
void moveto(int new_hpos, int new_vpos);
void process_file(FILE *source_fd);
void ps_fputc(FILE *fd, int c);
void ps_fputs(FILE *fd, char *string);
void ps_puts(char *string);
void put_in_string(char array[], int *p_index, int c, int max_index, int *p_ov_flag);
void re_encode(char *font);
void read_input_file(char source[], FILE *source_fd);
void set_text_font(int size);
char *tolower_str(char *string);
char *toupper_str(char *string);
extern      char *strtok(char *s1, const char *s2);
#else /* __STDC__ */
struct chord_struct *add_to_chordtab();
int do_transpose();
struct kcs *get_kc_entry ();
void advance();
void debug();
void do_chord ();
void do_comment();
void do_directive();
void do_help ();
void do_translate();
void dump_fret();
void error();
void error_rt();
void moveto();
void process_file();
void ps_fputc();
void ps_fputs();
void ps_puts();
void put_in_string();
void re_encode();
void read_input_file();
void set_text_font();
char *tolower_str();
char *toupper_str();
extern char *strtok();

#endif /* ANSI_C */
#endif /* CHORDII_H */
