CLI Battleship in C++
=============================================

Summary:
-------------------
CLI Battleship is a battleship implementation for CLI.

It's meant to be extensible, with a message passing system between players and boards (to abstract the idea of a player for possible AI players or networked players).

This game is written as an exercise and posted as a reference for those learning C++
(I think writing battleship in a language is a good exercise for students to learn the language.)


Known Issues:
-------------------
The board display isn't ideal.  No grid indexes are provided visually, so for example, to shoot a square (8,5) on large boards it can be unwieldy to identify the correct coordinates.

The board is zero based i.e., for a 10x10 board the top left square is (0,0) the bottom right square is (9,9).  This may be unexpected by players.

Some C++11 features not fully taken advantage of.


Building / Cleaning:
-------------------
>make
>make clean


Usage:
-------------------
>./battleship board_width board_height player1_name player2_name


License Information
-------------------

All code is released under [GNU GPLv3.0](http://www.gnu.org/copyleft/gpl.html).

If you find any errors please message about them.
