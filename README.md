# filler
**school project:** competitive 2D-board filling algorithm

*NOT TO BE CONFUSED WITH ANOTHER SCHOOL PROJECT: [fillit](https://github.com/rikikoo/fillit)*

## ABOUT filler
The program compiled by the Makefile is a virtual "player" designed to compete against other virtual players in the game of filler, which is run in the virtual machine `resources/filler_vm`.

The way I see it, filler is a sort of augmented tic-tac-toe, where each player is given a random "piece" that they have to fit onto the playing field (an arbitrarily sized 2D board) until no more pieces can be placed. The player that was able to place more pieces wins.

*GAME RULES:*
  - On the board, the starting points of the players are randomly decided. P1 gets to place the first piece.
  - Both players take turns placing pieces. Player 1 is `O` and player 2 is `X`.
  - On each turn, the player is given a random piece by the `filler_vm` in a "token" in which the actual piece is. The token's size varies and the shape of the piece in the token is random on each turn.
  - One cell of the piece has to overlap with exactly one cell of previously placed pieces of the same player.
  - Players have to give the coordinates of the _token's_ top-left corner to `stdout`. Those coordinates can be outside the board.

*EXAMPLE GAME:*

```
$>./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr

$$$ exec p1 : [user1]
$$$ exec p2 : [user2]

Plateau 14 30:
    012345678901234567890123456789
000 ..............................
001 ..............................
002 ..............................
003 ..............................
004 ......X.......................
005 ..............................
006 ..............................
007 ..........................O...
008 ..............................
009 ..............................
010 ..............................
011 ..............................
012 ..............................
013 ..............................
Piece 3 6:
.****.
**....
*.....

<got (O) : [7 24] (7,24)
Plateau 14 30:
    012345678901234567890123456789
000 ..............................
001 ..............................
002 ..............................
003 ..............................
004 ......X.......................
005 ..............................
006 ..............................
007 .........................oooo.
008 ........................oo....
009 ........................o.....
010 ..............................
011 ..............................
012 ..............................
013 ..............................
Piece 3 8:
......*.
......**
.......*

<got (X) : [4 0] (4,0)
Plateau 14 30:
    012345678901234567890123456789
000 ..............................
001 ..............................
002 ..............................
003 ..............................
004 ......x.......................
005 ......xx......................
006 .......x......................
007 .........................OOOO.
008 ........................OO....
009 ........................O.....
010 ..............................
011 ..............................
012 ..............................
013 ..............................

[...]
```

## ABOUT THE PROJECT
First of all, this project -- like all other school projects -- was written in accordance with the 42 norm (e.g. no `for` loops, max 25 lines per function, one variable declaration per line, no libc functions allowed except for `read` `write` `malloc` `free`, ...)

I tried different approaches to make sure my algorithm would end up with more placed pieces, ranging from a "compass" method where the program would check the direction of the opponent relative to my pieces to a method where pieces would be first placed towards the side of the board where the opponent is and then where there's more clear space on the board...
After struggling with these approaches I heard of a "heatmap" approach that turned out to be the most simple and effective.

The heatmap is an `int` representation of the playing board, updated on each turn, where 
  - opponent-filled cells are given a high positive value (1000 in the current version, because the board most likely won't be over 1000 by 1000 cells)
  - cells filled by my pieces are given a negative value
  - The empty cells are given a value that decreases by one outwards from all of the opponent's cells.

After that it's easy to try and place the piece on the heatmap where the current piece's cells land on cells on the map that have the the highest sum. This way the highest sum must be closest to my opponent. I want to get close to the opponent so that I could surround their pieces with mine, so that the rest of the board was reachable only by my pieces.

*EXAMPLE:*
Here the opponent is given a value of 9 and my player value of 0. Idea is the same even though the values aren't.

Board:
```
    0 1 2 3 4 5 6 7
000 . . . O . . . .
001 . . . . . . . .
002 . . . . . . . .
003 . . . . . . . .
004 . . . . . . . X
```
Heatmap:
```
    1 1 1 0 2 3 4 5
    1 1 1 2 3 4 5 6
    1 1 2 3 4 5 6 7
    1 2 3 4 5 6 7 8
    2 3 4 5 6 7 8 9 
```
The piece we need to place:
```
***
.*.
.**
```

The highest sum is achieved when placing the piece like so:
```
    0 1 2 3 4 5 6 7
000 . . . o o o . .
001 . . . . o . . .
002 . . . . o o . .
003 . . . . . . . .
004 . . . . . . . X
```
Which would correspond to 0+2+3+3+4+5 = 17 on the heatmap. Any other placement would result in a lower sum.

## Usage
`make all`

`cd resources`

assuming my algo is player 1 and we are playing against "superjeannot" and we play on a medium size map

`./filler_vm -p1 ../rkyttala.filler -p2 players/superjeannot.filler -f maps/map01`

**the filler virtual machine (`filler_vm`) will not run unless you are in the directory where it's located (`resources`) .** I haven't bothered to figure out why that's the case.

If you want to see the game being played out much more prettily than on a strobe command line, just pipe the last command to `visual`, like so (when in the `resources` directory):
`./filler_vm -p1 ../rkyttala.filler -p2 players/superjeannot.filler -f maps/map01 | ./visual`

The visualizer was made by the awesome [avocadohooman](https://github.com/avocadohooman/42-filler/tree/master/visualiser), a fellow student at Hive Helsinki. 
