#! nmake -f makefile

CHORDII_OBJS=chordii.obj \
	common.obj \
	xpose.obj \
	iso.obj \
	grid.obj \
	getopt.obj \
	toc.obj

A2CRD_OBJS=a2crd.obj \
	common.obj \
	getopt.obj

CFLAGS = /nologo /DHAVE_CONFIG_H /I. /I..\src

all :: chordii.exe a2crd.exe

chordii.exe :: $(CHORDII_OBJS)
	$(CC) $(CFLAGS) -o chordii.exe $(CHORDII_OBJS)

a2crd.exe :: $(A2CRD_OBJS)
	$(CC) $(CFLAGS) -o a2crd.exe $(A2CRD_OBJS)

{..\src}.c.obj :
	$(CC) $(CFLAGS) -c $<

getopt.obj :: getopt.h getopt.c
	$(CC) $(CFLAGS) -c getopt.c

clean ::
	del *.obj
	del *.exe
