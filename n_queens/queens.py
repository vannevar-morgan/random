#! /usr/bin/python3.4

import sys
from Board import Board
import random


def solve(b, width, height, n_queens):
    """
    Solve board b by placing n queens on the board.
    
    It is assumed the board is square.
    
    Note that the queens are placed in random columns,
    they can be placed (more efficiently) left to right.
    
    I've placed them in random columns because it makes 
    for more interesting arrangements when the number of
    queens is less than the board width. (so you can see
    the lines of death).

    If a queen can't be placed in a column then the board
    is reset and setting queens begins again from scratch.
    I realize there are more efficient ways to solve the
    n-queens problem, but I can't print a board larger 
    than 42x42 on my screen.  Resetting each time is much
    slower but it's sufficient limited to 42x42 boards.
    """
    while True:
        print("begin solve...")
        free_cols = []
        for i in range(width):
            free_cols.append(i)
        
        board_success = True
        for i in range(n_queens):
            col_index = random.randint(0, len(free_cols) - 1)
            col = free_cols[col_index]
            free = b.col_free(col)
            if len(free) == 0:
                board_success = False
                print("nowhere to place queen for column " + str(col))                
                break
            else:
                queen_success = b.place_queen(free[random.randint(0, len(free) - 1)], col)
                if queen_success:
                    print("placed queen for column " + str(col))
                    del free_cols[col_index]
                else:
                    print("failed to place queen for column " + str(col))

        if board_success:
            break
        else:
            b.reset()
            if width == height and width >= n_queens:
                continue
            else:
                print("failed to place all queens...")
                cont = input("retry? (y/n) ")
                if cont is 'y':
                    continue
                else:
                    print("you chose not to retry, so exiting.  couldn't solve for the given board dimensions...")
                    break



USAGE_MESSAGE_GENERAL = "usage: ./queens board_width board_height #_of_queens"

if len(sys.argv) != 4:
    print(USAGE_MESSAGE_GENERAL)
    sys.exit(0)

width = int(sys.argv[1])
height = int(sys.argv[2])
n_queens = int(sys.argv[3])

if width < 4:
    width = 4
    height = 4
    n_queens = 4
    print("minimum board size is 4x4, board dimensions have been set to 4x4, queens set to 4")
if height < 4:
    width = 4
    height = 4
    n_queens = 4
    print("minimum board size is 4x4, board dimensions have been set to 4x4, queens set to 4")

if width < n_queens and height < n_queens:
    print("specified # of queens is greater than both board dimensions!\nthis board is not solvable given the number of queens requested... exiting.")
    sys.exit(0)

if width > 42 or height > 42:
    print("board dimensions are too large, so exiting.  (i can only print 42x42 boards on my screen, sorry)")
    sys.exit(0)

b = Board(width, height)
solve(b, width, height, n_queens)
b.print_board()
