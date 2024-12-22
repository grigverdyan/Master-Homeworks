/* example 3 */
man(albert).
man(edward).
woman(alice).
woman(victoria).
parents(edward, victoria, albert).
parents(alice, victoria, albert).

isSister(X, Y):-woman(X), parents(X, M, F), parents(Y, M, F).

