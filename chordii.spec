Summary: Print songsbooks (lyrics + chords)
Name: chordii
Version: 4.3
Release: 1%{?dist}
URL: http://chordii.sourceforge.net
Source: http://downloads.sourceforge.net/%{name}/%{name}-%{version}.tar.gz
Patch0: %{name}-%{version}-makefile.patch
License: GPLv3+
Group: Applications/Publishing
BuildRoot: %(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)
Obsoletes: chordie chord

%description
chordii provides guitar players and other musicians with a tool to
produce good looking, self-descriptive music sheets from text files.

chordii reads text files in chordpro format, containing the lyrics of
songs, the chords to be played, their descriptions and some other
optional data. It produces a PostScript document suitable for viewing
and printing.

chordii features include:
 - centered titles,
 - chord names above the words,
 - chord diagrams at the end of the songs,
 - multiple columns on a page,
 - multiple logical pages per physical pages (1, 2 or 4),
 - configurable fonts and sizes,
 - the complete ISO 8859-1 character set,
 - chorus marking,
 - automated chord transposition,
 - songbook creation: typeset multiple songs with page numbers and a
   table of contents.

%prep
%setup -q

# Fix Makefiles to avoid double install of manual pages.
%patch0 -p0 -b .mak

%build
%configure
make %{?_smp_mflags}

%install
rm -rf %{buildroot}
make DESTDIR=%{buildroot} INSTALL="install -p" install

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,-)
%doc README NEWS COPYING examples/
%{_bindir}/*
%{_mandir}/man1/*

%changelog
* Mon Jul 13 2009 Johan Vromans <jvromans@squirrel.nl> - 4.3-1
- Rebase on GPL Chord 3.6.4.

* Sat Jan 31 2009 Johan Vromans <jvromans@squirrel.nl> - 4.2-5
- Changed examples/* to examples/ to include all examples in a dir

* Fri Jan 30 2009 Johan Vromans <jvromans@squirrel.nl> - 4.2-4
- Fixed changelog entries involving %% to prevent macro expansion

* Fri Jan 30 2009 Johan Vromans <jvromans@squirrel.nl> - 4.2-3
- Fixed URL and Source urls
- Added %%{?dist} to Release
- Fixed missing (optional) argument to %%defattr
- Changed examples to examples/* to include all examples

* Fri Jan 30 2009 Johan Vromans <jvromans@squirrel.nl> - 4.2-2
- Update description
- Add patch to fix Makefiles to avoid double install of manual pages
- use smp_mflags
- use install -p

* Thu Jan 29 2009 Johan Vromans <jvromans@squirrel.nl> - 4.2-1
- First Fedora version
