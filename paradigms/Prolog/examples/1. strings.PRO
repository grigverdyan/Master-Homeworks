/* ***** ROUND/SQUARE/FIGURE BRACKETs ***** */
checkBrackets(S):-checkBrackets1(S, []).

checkBrackets1([], []):-!.

checkBrackets1(['('|S], Stack):- !,	checkBrackets1(S, ['('|Stack]).
checkBrackets1(['['|S], Stack):- !,	checkBrackets1(S, ['['|Stack]).
checkBrackets1(['{'|S], Stack):- !,	checkBrackets1(S, ['{'|Stack]), !.

checkBrackets1([')'|S], ['('|Stack]):-!,	checkBrackets1(S,Stack).
checkBrackets1([']'|S], ['['|Stack]):-!,	checkBrackets1(S,Stack).
checkBrackets1(['}'|S], ['{'|Stack]):-!,	checkBrackets1(S,Stack).

checkBrackets1([')'|_], _):-		!, fail.
checkBrackets1([']'|_], _):-		!, fail.
checkBrackets1(['}'|_], _):-		!, fail.

checkBrackets1([_|S], Stack):-		checkBrackets1(S,Stack).


