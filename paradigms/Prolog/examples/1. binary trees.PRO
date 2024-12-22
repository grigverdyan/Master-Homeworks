/************************************************************************/
/*                       ***** BINARY TREES *****                       */
/************************************************************************/
/*an instance */
bt_instance(bTree(bTree(nil, b, nil), a, bTree(bTree(nil, d, nil), c, nil))).


/**************************** OPERATIONS ********************************/

/* size*/
size(nil, 0):-!.
size(bTree(L, _, R), N):-size(L, N1), size(R, N2), N is N1 + N2 + 1.

/* height */
height(nil, -1):-!.
height(bTree(L, _, R), N):-height(L, N1), height(R, N2), max(N1, N2, M), N is M + 1.

max(N1, N2, N1):-N1>=N2, !.
max(_, N2, N2). 

/* number of leaves */
numberOfLeaves(nil, 0):-! .
numberOfLeaves(bTree(nil, _, nil), 1):-!.
numberOfLeaves(bTree(L, _, R), N):-numberOfLeaves(L, N1), numberOfLeaves(R, N2), N is N1+N2. 


