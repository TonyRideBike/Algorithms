/**
HUST ACM Contest - Algorithm Practice 1
http://acm.hust.edu.cn/vjudge/contest/view.action?cid=80772#overview

Pots

Description
You are given two pots, having the volume of A and B liters respectively. The
following operations can be performed:
    1. FILL(i)      fill the pot i (1 <= i <= 2) from the tap;
    2. DROP(i)      empty the pot i to the drain;
    3. POUR(i, j)   pour from pot i to pot j; after this operation either the
    pot j is full (and there may be some water left in the pot i), or the pot i
    is empty (and all its contents have been moved to the pot j).
Write a program to find the shortest possible sequence of these operations that
will fill yield exactly C liters in one of the pots.

Input
On the first and only line are the numbers A, B, and C. These are all integers
in the range from 1 to 100 and C <= max(A, B).

Output
The first line of the output must contain the length of the sequence of
operations K. The following K lines must each describe one operation. If there
are several sequences of minimal length, output any one of them. If the desired
result can't be achieved, the first and only line of the file must contain the
word 'impossible'.

Sample Input & Output
================================================================================
3 5 4
--------------------------------------------------------------------------------
6
FILL(2)
POUR(2,1)
DROP(1)
POUR(2,1)
FILL(2)
POUR(2,1)
================================================================================
 */

