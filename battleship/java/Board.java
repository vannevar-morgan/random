import java.util.ArrayList;

class Board{
    
    private String boardName;
    private int boardWidth;
    private int boardHeight;
    private ArrayList<Ship> ships;
    private static int MAX_BOARD_WIDTH = 100;
    private static int MAX_BOARD_HEIGHT = 100;
    private boolean boardAlive;
    private static int SHIP_PLACING_TIMEOUT = 1000; // number of times to try placing a ship
    
    public Board(int w, int h, String name) throws IllegalArgumentException{
	init(w, h, name);
    }
    
    public static void main(String[] args){
	testBoardClass(args);
    }
        
    public boolean addShip(Ship s){
	//
	// Places a ship on the board.
	// Returns true if the ship was able to be placed, false otherwise.
	//
	if(s.getSize() > this.boardWidth || s.getSize() > this.boardHeight){
	    // throw exception
	}
	ArrayList<Pair<Integer, Integer>> temp_cells;
	for(int i = 0; i < SHIP_PLACING_TIMEOUT; ++i){
	    Pair<Integer, Integer> pos = new Pair<Integer, Integer>( (int) (Math.random() * this.boardWidth), (int) (Math.random() * this.boardHeight) );
	    int dir = (int) (Math.random() * 2);
	    temp_cells = makeCellsList(pos, dir, s.getSize(), this.boardWidth, this.boardHeight);
	    if(temp_cells != null && !checkConflicting(temp_cells)){
		s.setCells(temp_cells);
		this.ships.add(s);
		return true;
	    }
	}
	return false;
    }
    
    private static ArrayList<Pair<Integer, Integer>> makeCellsList(Pair<Integer, Integer> pos, int dir, int size, int width, int height){
	//
	// Makes a list of cells starting from pos, in direction dir, of length size.
	//
	// If dir == 0 the direction is interpreted as horizontal.
	// Otherwise direction is interpreted as vertical.
	//
	// If the cells would go beyond the size of the board then null is returned.
	//
	if(dir == 0){
	    if(pos.first() + size > width){
		return null;
	    }
	}else{
	    if(pos.second() + size > height){
		return null;
	    }
	}
	
	ArrayList<Pair<Integer, Integer>> cells = new ArrayList<Pair<Integer, Integer>>();
	cells.add(pos);
	int x = pos.first();
	int y = pos.second();
	for(int i = 1; i < size; ++i){
	    if(dir == 0){
		x += 1;
	    }else{
		y += 1;
	    }
	    cells.add(new Pair<Integer, Integer>(x, y));
	}
	return cells;
    }
    
    private boolean checkConflicting(ArrayList<Pair<Integer, Integer>> cells){
	//
	// Checks if a ship overlaps with another ship already on the board.
	// Returns true if the ship overlaps, false otherwise.
	//
	for(Pair<Integer, Integer> pos : cells){
	    for(Ship s : this.ships){
		if(s.getCells().contains(pos)){
		    return true;
		}
	    }
	}
	return false;
    }
    
    public Pair<Integer, Ship> checkHit(Pair<Integer, Integer> pos){
	//
	// Checks if a position represents a hit on any ship on the board.
	//
	// Output: Pair<Integer, Ship>
	// If position is:
	//                 miss - Pair< -1, null>
	//                  hit - Pair<  0, Ship>
	//                 sink - Pair<  1, Ship>
	//
	for(Ship s : this.ships){
	    if(s.checkHit(pos)){
		if(!s.isAlive()){
		    this.ships.remove(s);
		    if(this.ships.size() == 0){
			this.boardAlive = false;
		    }
		    return new Pair<Integer, Ship>(1, s);
		}
		return new Pair<Integer, Ship>(0, s);
	    }
	}
	return new Pair<Integer, Ship>(-1, null);
    }
    
    public String getName(){
	return this.boardName;
    }
    
    public int getHeight(){
	return this.boardHeight;
    }
    
    public int getMaxHeight(){
	return this.MAX_BOARD_HEIGHT;
    }
    
    public int getMaxWidth(){
	return this.MAX_BOARD_WIDTH;
    }
    
    public ArrayList<Ship> getShips(){
	return this.ships;
    }
    
    public int getShots(){
	int shots = 0;
	for(Ship s : this.ships){
	    shots += s.getShots();
	}
	return shots;
    }
    
    public int getWidth(){
	return this.boardWidth;
    }
    
    protected void init(int w, int h, String name) throws IllegalArgumentException{
	if(w > MAX_BOARD_WIDTH || w < 1){
	    throw new IllegalArgumentException("specified board width is out of range... 0 < w < " + MAX_BOARD_WIDTH + " but w = " + w);
	}
	if(h > MAX_BOARD_HEIGHT || h < 1){
	    throw new IllegalArgumentException("specified board height is out of range... 0 < h < " + MAX_BOARD_HEIGHT + " but h = " + h);
	}
	this.boardWidth = w;
	this.boardHeight = h;
	this.boardName = name;
	this.ships = new ArrayList<Ship>();
	this.boardAlive = true;	
    }
    
    public boolean isAlive(){
	return this.boardAlive;
    }
    
    public void setName(String name){
	this.boardName = name;
    }
    
    private static void testBoardClass(String[] args){
	// just to test the class
	if(args.length != 2){
	    System.out.println("usage: ./Board width height");
	    return;
	}
	int x;
	int y;
	try{
	    x = Integer.parseInt(args[0]);
	    y = Integer.parseInt(args[1]);
	}catch(NumberFormatException e){
	    System.out.println("usage: ./Board (int)width (int)height");
	    return;
	}
	Board b = new Board(x, y, "TEST");
	b.addShip(new Carrier());
	b.addShip(new Cruiser());
	b.addShip(new Destroyer());
	b.addShip(new Submarine());
	b.addShip(new Minesweeper());
	System.out.println(b.getShips());
	ArrayList<Ship> temp_ships = b.getShips();
	for(Ship s : temp_ships){
	    ArrayList<Pair<Integer, Integer>> pairs = s.getCells();
	    for(Pair<Integer, Integer> p : pairs){
		System.out.println("(" + p.first() + ", " + p.second() + ")");
	    }
	}	
    }
}
