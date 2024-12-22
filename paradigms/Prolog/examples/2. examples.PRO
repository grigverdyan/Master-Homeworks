/* factorial computation*/
fact(0, 1) :- !.
fact(N, P) :- K is N-1, fact(K, Q), P is Q*N.


/*gcd computation*/
gcd(X, X, X) :- !.
gcd(X, Y, D) :- X>Y, X1 is X-Y, gcd(X1, Y, D), !.
gcd(X, Y, D) :- Y1 is Y-X, gcd(X, Y1, D).


/*power computation*/
power(_, 0, 1) :-!.
power(X, N, Y) :-  0 is N mod 2, M is N//2, power(X, M, Z), Y is Z*Z, !.
power(X, N, Y) :-  M is N//2, power(X, M, Z), Y is Z*Z*X.



/* Fibonacci series*/
fib1(1, 1, 1) :- !.
fib1(N, X1, X) :- N1 is N-1, fib1(N1, X2, X1), X is X2+X1.
fib(0, 1) :- !. 
fib(N, X) :- fib1(N, _, X).
