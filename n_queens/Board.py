


class Board:
    
    def __init__(self, width, height):
        """
        Initialize a board with width and height.
        """
        if width <= 0:
            width = 1
        if height <= 0:
            height = 1
        # should provide a message for the above cases
        self.width = width
        self.height = height
        self.squares = []
        for i in range(height):
            self.squares.append(['.'] * width)


    def print_board(self):
        """
        Print the board to stdout.
        """
        for i in range(self.height):
            for j in range(self.width):
                print(" " + self.squares[i][j] + " ", end="")
            print()


    def get_height(self):
        """
        Return the height of the board.
        """
        return self.height


    def get_width(self):
        """
        Return the width of the board.
        """
        return self.width


    def place_queen(self, row, col):
        """
        Place a queen at (row, col) on the board.
        Propagate death to any square this queen can attack.
        Return True if the queen can be placed.
        Return False otherwise.
        """
        if row < 0 or row >= self.height:
            # can't place a queen off the board
            return False
        if col < 0 or col >= self.width:
            # can't place a queen off the board
            return False
        if self.squares[row][col] == 'Q':
            # can't place the queen here if there's already a queen here.
            return False
        if self.squares[row][col] == '~':
            # can't place the queen here if another queen attacks this square.
            return False
        
        # propagate death to all row squares this queen attacks.
        for i in range(0, self.width):
            self.squares[row][i] = '~'

        # propagate death to all column squares this queen attacks.
        for i in range(0, self.height):
            self.squares[i][col] = '~'
        
        # propagate death to all \-diagonal squares this queen attacks.
        i = 0
        while True:
            i += 1
            if row + i >= self.height or col + i >= self.width:
                break
            self.squares[row + i][col + i] = '~'
        i = 0
        while True:
            i += 1
            if row - i < 0 or col - i < 0:
                break
            self.squares[row - i][col - i] = '~'

        # propagate death to all /-diagonal squares this queen attacks.
        i = 0
        while True:
            i += 1
            if row - i < 0 or col + i >= self.width:
                break
            self.squares[row - i][col + i] = '~'
        i = 0
        while True:
            i += 1
            if row + i >= self.height or col - i < 0:
                break
            self.squares[row + i][col - i] = '~'
        
        # set the queen position
        self.squares[row][col] = 'Q'
        return True


    def col_free(self, n):
        """
        Return a list of rows in column, n, where a queen can be placed.
        """
        temp = self.get_col(n)
        temp2 = []
        for i in range(len(temp)):
            if temp[i] == '.':
                temp2.append(i)
        return temp2


    def get_col(self, n):
        """
        Return a list representing the state of column n.
        """
        temp = []
        if n >= self.width:
            # should provide a message too
            return temp
        for i in range(self.height):
            temp.append(self.squares[i][n])
        return temp


    def reset(self):
        """
        Remove all queens, reset the board.
        """
        self.squares = []
        for i in range(self.height):
            self.squares.append(['.'] * self.width)

