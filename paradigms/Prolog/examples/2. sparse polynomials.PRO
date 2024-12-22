/*addition*/
addition([], P, P):-!.
addition(P, [], P):-!.

addition([x(C1, K1)|P1], [x(C2, K2)|P2], [x(C1, K1)|P]):-
	K1>K2, addition(P1, [x(C2, K2)|P2], P), !.

addition([x(C1, K1)|P1], [x(C2, K2)|P2], [x(C2, K2)|P]):-
	K2>K1, addition([x(C1, K1)|P1], P2, P), !.

addition([x(C1, K)|P1], [x(C2, K)|P2], [x(C, K)|P]):-
C is C1+C2, C \= 0, addition(P1, P2, P), !.

addition([_|P1], [_|P2], P):-addition(P1, P2, P).


/*multiplication*/
multiplication([],_, []):-!.
multiplication([x(C1, K1)|P1],P2, P):- 
					multiplication1(x(C1, K1),P2, Q1), 
						multiplication(P1,P2, Q2), 
							addition(Q1, Q2, P).

multiplication1(_,[], []):-!.
multiplication1(x(C1, K1), [x(C2, K2)|P2], [x(C, K)|P]):- 
					C is C1*C2, K is K1+K2, 
					multiplication1(x(C1, K1), P2, P).

