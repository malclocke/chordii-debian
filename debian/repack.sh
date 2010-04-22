#!/bin/sh

# This script unpacks original source, removes the included debian directory
# and repacks it with an added +repack to version. The version is taken from
# the shipped NEWS file.

ACT=$(head -n 1 NEWS | cut -d ' ' -f 4)

if [ -e '../chordii_'$ACT'.orig.tar.gz' ]; then
	# Cleaning
	rm -rf ../temp
	rm -rf ../chordii_$ACT+repack.orig.tar.gz

	# Repacking
	mkdir ../temp
	tar xfz ../chordii_$ACT.orig.tar.gz -C ../temp
	rm -rf ../temp/chordii-$ACT/debian
	rm -f ../temp/chordii-$ACT/examples/everybody-hurts.cho
	rm -f ../temp/chordii-$ACT/examples/love-me-tender.cho
	mv ../temp/chordii-$ACT ../temp/chordii-$ACT+repack
	tar cfz ../temp/chordii_$ACT+repack.orig.tar.gz -C ../temp chordii-$ACT+repack
	mv ../temp/chordii_$ACT+repack.orig.tar.gz ../
	rm -rf ../temp

	# Finish
	if [ -e ../chordii_$ACT+repack.orig.tar.gz ]; then
		echo Repack successful!
	fi
else
	echo Tarball not found. Maybe you\'re not in the source directory?
fi
