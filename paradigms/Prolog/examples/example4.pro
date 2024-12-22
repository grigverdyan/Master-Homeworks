/* example 4 */
thief(john).
likes(mary, food).
likes(mary, wine).
likes(john, X):-likes(X,wine).
can_steal(X, Y):-thief(X), likes(X, Y).