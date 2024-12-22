/************************************************************************/
/*                        ***** SEARCH TREES *****                      */
/************************************************************************/

/*an instance */
st_instance(bTree(bTree(nil, 1, nil), 
		  2, 
		  bTree(bTree(nil, 3, nil), 
		      	   4, 
		              nil
		  )
             )
).

   
/*************************** OPERATIONS *********************************/

/*search*/
search(X, bTree(_, X, _)):-!.
search(X, bTree(L, Y, _) ):-X<Y, search(X, L), !.
search(X, bTree(_, _, R) ):-search(X, R). 

/*insert*/
insert(X, nil, bTree(nil, X, nil)):-!.
insert(X, bTree(L, Y, R), bTree(L1, Y, R)):-X<Y, insert(X, L, L1), !.
insert(X, bTree(L, Y, R), bTree(L, Y, R1)):-insert(X, R, R1).

/*remove*/
remove(_, nil, nil):-!.
remove(X, bTree(L, Y, R), bTree(L1, Y, R)):-
						X<Y, remove(X, L, L1), !.
remove(X, bTree(L, Y, R), bTree(L, Y, R1)):-
						X>Y, remove(X, R, R1), !.
remove(X, bTree(nil, X, R), R):-!.
remove(X, bTree(L, X, nil), L):-!.
remove(X, bTree(L, X, R), bTree(L, Y, R1)):-
						min(R, Y), remove(Y, R, R1).

min(bTree(nil, X, _), X):-!.
min(bTree(L, _, _), Y):-min(L, Y).


