## Process this file with automake to produce Makefile.in
common = chordii.h common.c getopt.h
bin_PROGRAMS = chordii a2crd
chordii_SOURCES = $(common) chordii.c xpose.c iso.c grid.c getopt.c toc.c
a2crd_SOURCES = $(common) a2crd.c
chordii_LDADD = $(LIBOBJS)
a2crd_LDADD = $(LIBOBJS)
