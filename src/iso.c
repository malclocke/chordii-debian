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

#include <stdio.h>

void print_re_encode ()
{
	printf("%%  iso.ps  reencodeing of ISO 8859-1 8-bit french characters\n");
	printf("%%\n");
	printf("/reencodedict 5 dict def\n");
	printf("/ReEncode\n");
	printf("  { reencodedict begin\n");
	printf("      /newencoding exch def\n");
	printf("      /newfontname exch def\n");
	printf("      /basefontname exch def\n");
	printf("\n");
	printf("      /basefontdict basefontname findfont def\n");
	printf("\n");
	printf("      /newfont basefontdict maxlength dict def\n");
	printf("\n");
	printf("      basefontdict\n");
	printf("      {  exch dup dup /FID ne exch /Encoding ne and\n");
	printf("	{ exch newfont 3 1 roll put }\n");
	printf("	{ pop pop }\n");
	printf("	ifelse\n");
	printf("      } forall\n");
	printf("      newfont /FontName newfontname put\n");
	printf("      newfont /Encoding newencoding put\n");
	printf("      newfontname newfont definefont pop\n");
	printf("      end\n");
	printf("   } def\n");
	printf("\n");
	printf("/ISO 256 array def\n");
	printf("\n");
	printf("0 1 255 { ISO exch /.notdef put } for\n");
	printf("ISO\n");
	printf("\n");
	printf("  dup 8#040 /space put\n");
	printf("  dup 8#041 /exclam put\n");
	printf("  dup 8#042 /quotedbl put\n");
	printf("  dup 8#043 /numbersign put\n");
	printf("  dup 8#044 /dollar put\n");
	printf("  dup 8#045 /percent put\n");
	printf("  dup 8#046 /ampersand put\n");
	printf("  dup 8#047 /quotesingle put\n");
	printf("  dup 8#050 /parenleft put\n");
	printf("  dup 8#051 /parenright put\n");
	printf("  dup 8#052 /asterisk put\n");
	printf("  dup 8#053 /plus put\n");
	printf("  dup 8#054 /comma put\n");
	printf("  dup 8#055 /hyphen put\n");
	printf("  dup 8#056 /period put\n");
	printf("  dup 8#057 /slash put\n");
	printf("  dup 8#060 /zero put\n");
	printf("  dup 8#061 /one put\n");
	printf("  dup 8#062 /two put\n");
	printf("  dup 8#063 /three put\n");
	printf("  dup 8#064 /four put\n");
	printf("  dup 8#065 /five put\n");
	printf("  dup 8#066 /six put\n");
	printf("  dup 8#067 /seven put\n");
	printf("  dup 8#070 /eight put\n");
	printf("  dup 8#071 /nine put\n");
	printf("  dup 8#072 /colon put\n");
	printf("  dup 8#073 /semicolon put\n");
	printf("  dup 8#074 /less put\n");
	printf("  dup 8#075 /equal put\n");
	printf("  dup 8#076 /greater put\n");
	printf("  dup 8#077 /question put\n");
	printf("  dup 8#100 /at put\n");
	printf("  dup 8#101 /A put\n");
	printf("  dup 8#102 /B put\n");
	printf("  dup 8#103 /C put\n");
	printf("  dup 8#104 /D put\n");
	printf("  dup 8#105 /E put\n");
	printf("  dup 8#106 /F put\n");
	printf("  dup 8#107 /G put\n");
	printf("  dup 8#110 /H put\n");
	printf("  dup 8#111 /I put\n");
	printf("  dup 8#112 /J put\n");
	printf("  dup 8#113 /K put\n");
	printf("  dup 8#114 /L put\n");
	printf("  dup 8#115 /M put\n");
	printf("  dup 8#116 /N put\n");
	printf("  dup 8#117 /O put\n");
	printf("  dup 8#120 /P put\n");
	printf("  dup 8#121 /Q put\n");
	printf("  dup 8#122 /R put\n");
	printf("  dup 8#123 /S put\n");
	printf("  dup 8#124 /T put\n");
	printf("  dup 8#125 /U put\n");
	printf("  dup 8#126 /V put\n");
	printf("  dup 8#127 /W put\n");
	printf("  dup 8#130 /X put\n");
	printf("  dup 8#131 /Y put\n");
	printf("  dup 8#132 /Z put\n");
	printf("  dup 8#133 /bracketleft put\n");
	printf("  dup 8#134 /backslash put\n");
	printf("  dup 8#135 /bracketright put\n");
	printf("  dup 8#136 /asciicircum put\n");
	printf("  dup 8#137 /underscore put\n");
	printf("  dup 8#140 /grave put\n");
	printf("  dup 8#141 /a put\n");
	printf("  dup 8#142 /b put\n");
	printf("  dup 8#143 /c put\n");
	printf("  dup 8#144 /d put\n");
	printf("  dup 8#145 /e put\n");
	printf("  dup 8#146 /f put\n");
	printf("  dup 8#147 /g put\n");
	printf("  dup 8#150 /h put\n");
	printf("  dup 8#151 /i put\n");
	printf("  dup 8#152 /j put\n");
	printf("  dup 8#153 /k put\n");
	printf("  dup 8#154 /l put\n");
	printf("  dup 8#155 /m put\n");
	printf("  dup 8#156 /n put\n");
	printf("  dup 8#157 /o put\n");
	printf("  dup 8#160 /p put\n");
	printf("  dup 8#161 /q put\n");
	printf("  dup 8#162 /r put\n");
	printf("  dup 8#163 /s put\n");
	printf("  dup 8#164 /t put\n");
	printf("  dup 8#165 /u put\n");
	printf("  dup 8#166 /v put\n");
	printf("  dup 8#167 /w put\n");
	printf("  dup 8#170 /x put\n");
	printf("  dup 8#171 /y put\n");
	printf("  dup 8#172 /z put\n");
	printf("  dup 8#173 /braceleft put\n");
	printf("  dup 8#174 /bar put\n");
	printf("  dup 8#175 /braceright put\n");
	printf("  dup 8#176 /asciitilde put\n");
	printf("  dup 8#241 /exclamdown put\n");
	printf("  dup 8#242 /cent put\n");
	printf("  dup 8#243 /sterling put\n");
	printf("  dup 8#244 /currency put\n");
	printf("  dup 8#245 /yen put\n");
	printf("  dup 8#246 /bar put\n");
	printf("  dup 8#247 /section put\n");
	printf("  dup 8#250 /dieresis put\n");
	printf("  dup 8#251 /copyright put\n");
	printf("  dup 8#252 /ordfeminine put\n");
	printf("  dup 8#253 /guillemotleft put\n");
	printf("  dup 8#254 /.notdef put\n");
	printf("  dup 8#255 /endash put\n");
	printf("  dup 8#256 /registered put\n");
	printf("  dup 8#257 /tilde put\n");
	printf("  dup 8#260 /ring put\n");
	printf("  dup 8#261 /.notdef put\n");
	printf("  dup 8#262 /.notdef put\n");
	printf("  dup 8#263 /.notdef put\n");
	printf("  dup 8#264 /acute put\n");
	printf("  dup 8#265 /.notdef put\n");
	printf("  dup 8#266 /paragraph put\n");
	printf("  dup 8#267 /.notdef put\n");
	printf("  dup 8#270 /cedilla put\n");
	printf("  dup 8#271 /.notdef put\n");
	printf("  dup 8#272 /ordmasculine put\n");
	printf("  dup 8#273 /guillemotright put\n");
	printf("  dup 8#274 /.notdef put\n");
	printf("  dup 8#275 /circumflex put\n");
	printf("  dup 8#276 /dotlessi put\n");
	printf("  dup 8#277 /questiondown put\n");
	printf("  dup 8#300 /Agrave put\n");
	printf("  dup 8#301 /Aacute put\n");
	printf("  dup 8#302 /Acircumflex put\n");
	printf("  dup 8#303 /Atilde put\n");
	printf("  dup 8#304 /Adieresis put\n");
	printf("  dup 8#305 /Aring put\n");
	printf("  dup 8#306 /AE put\n");
	printf("  dup 8#307 /Ccedilla put\n");
	printf("  dup 8#310 /Egrave put\n");
	printf("  dup 8#311 /Eacute put\n");
	printf("  dup 8#312 /Ecircumflex put\n");
	printf("  dup 8#313 /Edieresis put\n");
	printf("  dup 8#314 /Igrave put\n");
	printf("  dup 8#315 /Iacute put\n");
	printf("  dup 8#316 /Icircumflex put\n");
	printf("  dup 8#317 /Idieresis put\n");
	printf("  dup 8#320 /.notdef put\n");
	printf("  dup 8#321 /Ntilde put\n");
	printf("  dup 8#322 /Ograve put\n");
	printf("  dup 8#323 /Oacute put\n");
	printf("  dup 8#324 /Ocircumflex put\n");
	printf("  dup 8#325 /Otilde put\n");
	printf("  dup 8#326 /Odieresis put\n");
	printf("  dup 8#327 /.notdef put\n");
	printf("  dup 8#330 /Oslash put\n");
	printf("  dup 8#331 /Ugrave put\n");
	printf("  dup 8#332 /Uacute put\n");
	printf("  dup 8#333 /Ucircumflex put\n");
	printf("  dup 8#334 /Udieresis put\n");
	printf("  dup 8#335 /.notdef put\n");
	printf("  dup 8#336 /.notdef put\n");
	printf("  dup 8#337 /germandbls put\n");
	printf("  dup 8#340 /agrave put\n");
	printf("  dup 8#341 /aacute put\n");
	printf("  dup 8#342 /acircumflex put\n");
	printf("  dup 8#343 /atilde put\n");
	printf("  dup 8#344 /adieresis put\n");
	printf("  dup 8#345 /aring put\n");
	printf("  dup 8#346 /ae put\n");
	printf("  dup 8#347 /ccedilla put\n");
	printf("  dup 8#350 /egrave put\n");
	printf("  dup 8#351 /eacute put\n");
	printf("  dup 8#352 /ecircumflex put\n");
	printf("  dup 8#353 /edieresis put\n");
	printf("  dup 8#354 /igrave put\n");
	printf("  dup 8#355 /iacute put\n");
	printf("  dup 8#356 /icircumflex put\n");
	printf("  dup 8#357 /idieresis put\n");
	printf("  dup 8#360 /.notdef put\n");
	printf("  dup 8#361 /ntilde put\n");
	printf("  dup 8#362 /ograve put\n");
	printf("  dup 8#363 /oacute put\n");
	printf("  dup 8#364 /ocircumflex put\n");
	printf("  dup 8#365 /otilde put\n");
	printf("  dup 8#366 /odieresis put\n");
	printf("  dup 8#367 /.notdef put\n");
	printf("  dup 8#370 /oslash put\n");
	printf("  dup 8#371 /ugrave put\n");
	printf("  dup 8#372 /uacute put\n");
	printf("  dup 8#373 /ucircumflex put\n");
	printf("  dup 8#374 /udieresis put\n");
	printf("  dup 8#375 /ydieresis put\n");
	printf("  dup 8#376 /.notdef put\n");
	printf("  pop\n");
	printf("\n");
	printf("\n");
}

void re_encode (font)
char *font;
	{
	printf("/%s /%s ISO ReEncode\n", font, font); 
	}
