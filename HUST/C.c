/**
HUST ACM Contest - Algorithm Practice 1
http://acm.hust.edu.cn/vjudge/contest/view.action?cid=80772#overview

Labyrinth

Description
Administration of the labyrinth has decided to start a new season with new
wallpapers. For this purpose they need a program to calculate the surface area
of the walls inside the labyrinth. This job is just for you!
The labyrinth is represented by a matrix N * N (3 <= N <= 33, you see, '3' is a
magic digit!). Some matrix cells contain a dot character('.') that denotes an
empty square. Other cells contain a diesis character ('#') that denotes a square
filled by monolith block of stone wall. All squares are of the same size 3 * 3 
meters.
The walls are constructed around the labyrinth (except for the upper left and
lower right corners, which are used as entrances) and on the cells with a diesis
character. No other walls are constructed. There always will be a dot character
at the upper left and lower right corner cells of the input matrix.
Your task is to calculate the area of visible part of the wall inside the
labyrinth. In other words, the area of the wall's surface visible to a visitor
of the labyrinth. Note that there's no holes to look or to move through between
any two adjacent of the wall.The blocks are considered to be adjacent if they
touch each other in any corner. See picture for an example: visible walls inside
the labyrinth are drawn with bold lines. The height of all the walls is 3 meters.

Input
The first line of the input contains the single number N. The next N lines
contain N characters each. Each line describes one row of the labyrinth matrix.
In each line only dot and diesis characters will be used and each line will be 
terminated with a new line character. There will be no spaces in the input.

Output
Your program should print to the output a single integer - the exact value of
the area of the wallpaper needed.

Sample Input & Output
================================================================================
5
.....
...##
..#..
..###
.....
--------------------------------------------------------------------------------
198
================================================================================
 */

