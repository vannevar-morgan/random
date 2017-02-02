OBJS_BATTLESHIP = main.o Ship.o Carrier.o Cruiser.o Destroyer.o Submarine.o Minesweeper.o HumanPlayer.o ViewScreen.o Board.o Game.o
OBJS_TEST_SHIP_CLASSES = test_classes.o Ship.o Carrier.o Cruiser.o Destroyer.o Submarine.o Minesweeper.o
OBJS_TEST_BOARD = test_board.o Ship.o Carrier.o Cruiser.o Destroyer.o Submarine.o Minesweeper.o Board.o
OBJS_TEST_HUMAN = test_human.o HumanPlayer.o ViewScreen.o
# test_viewscreen no longer needed because HumanPlayer is expected to manage the ViewScreen, test_human essentially tests ViewScreen now.
# OBJS_TEST_VIEWSCREEN = test_viewscreen.o ViewScreen.o HumanPlayer.o
CC = g++
CFLAGS = -c -Wall -std=c++11
LFLAGS = -Wall

all : battleship test_ship_classes test_board test_human


battleship : $(OBJS_BATTLESHIP)
	$(CC) $(LFLAGS) $(OBJS_BATTLESHIP) -o battleship

test_ship_classes : $(OBJS_TEST_SHIP_CLASSES)
	$(CC) $(LFLAGS) $(OBJS_TEST_SHIP_CLASSES) -o test_ship_classes

test_board : $(OBJS_TEST_BOARD)
	$(CC) $(LFLAGS) $(OBJS_TEST_BOARD) -o test_board

test_human : $(OBJS_TEST_HUMAN)
	$(CC) $(LFLAGS) $(OBJS_TEST_HUMAN) -o test_human

# test_viewscreen : $(OBJS_TEST_VIEWSCREEN)
# 	$(CC) $(LFLAGS) $(OBJS_TEST_VIEWSCREEN) -o test_viewscreen

main.o : main.cpp Ship.hpp Carrier.hpp Cruiser.hpp Destroyer.hpp Submarine.hpp Minesweeper.hpp Player.hpp HumanPlayer.hpp ViewScreen.hpp Board.hpp Game.hpp
	$(CC) $(CFLAGS) main.cpp

test_classes.o : test_classes.cpp Ship.hpp Carrier.hpp Cruiser.hpp Destroyer.hpp Submarine.hpp Minesweeper.hpp
	$(CC) $(CFLAGS) test_classes.cpp

test_board.o : test_board.cpp Ship.hpp Carrier.hpp Cruiser.hpp Destroyer.hpp Submarine.hpp Minesweeper.hpp Board.hpp
	$(CC) $(CFLAGS) test_board.cpp

test_human.o : test_human.cpp Player.hpp HumanPlayer.hpp ViewScreen.hpp
	$(CC) $(CFLAGS) test_human.cpp

# test_viewscreen.o : test_viewscreen.cpp ViewScreen.hpp Player.hpp HumanPlayer.hpp
# 	$(CC) $(CFLAGS) test_viewscreen.cpp

Ship.o : Ship.cpp Ship.hpp
	$(CC) $(CFLAGS) Ship.cpp

Carrier.o : Carrier.cpp Carrier.hpp Ship.hpp
	$(CC) $(CFLAGS) Carrier.cpp

Cruiser.o : Cruiser.cpp Cruiser.hpp Ship.hpp
	$(CC) $(CFLAGS) Cruiser.cpp

Destroyer.o : Destroyer.cpp Destroyer.hpp Ship.hpp
	$(CC) $(CFLAGS) Destroyer.cpp

Submarine.o : Submarine.cpp Submarine.hpp Ship.hpp
	$(CC) $(CFLAGS) Submarine.cpp

Minesweeper.o : Minesweeper.cpp Minesweeper.hpp Ship.hpp
	$(CC) $(CFLAGS) Minesweeper.cpp

Board.o : Board.cpp Board.hpp Ship.hpp
	$(CC) $(CFLAGS) Board.cpp

HumanPlayer.o : HumanPlayer.cpp HumanPlayer.hpp Player.hpp ViewScreen.hpp
	$(CC) $(CFLAGS) HumanPlayer.cpp

ViewScreen.o : ViewScreen.cpp ViewScreen.hpp
	$(CC) $(CFLAGS) ViewScreen.cpp

Game.o : Game.cpp Game.hpp Ship.hpp Board.hpp ViewScreen.hpp Player.hpp
	$(CC) $(CFLAGS) Game.cpp


clean:
	\rm -rf *.o
