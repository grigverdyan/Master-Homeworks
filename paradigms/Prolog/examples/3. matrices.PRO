/* ***** DIAGONAL ***** */
diagonal([], []):-!.
diagonal([[X|_]|M], [X|D]):-removeFirstColumn(M, M1), diagonal(M1, D).
removeFirstColumn([], []):-!.
removeFirstColumn([[_]|_], []):-!.
removeFirstColumn([[_|R]|M], [R|M1]):-removeFirstColumn(M, M1).


/* ***** TRANSPOSITION ***** */
transposition([], []):-!.
transposition([R|M], M1):-createColumn(R, C), transposition(M,M2),addColumnToMatrix(C, M2, M1).

createColumn([], []):-!.
createColumn([X|R], [[X]|C]):-createColumn(R, C).

addColumnToMatrix(C, [], C):-!.
addColumnToMatrix([[X]|C], [R|M1], [[X|R]|M]):-addColumnToMatrix(C, M1, M).



