import java.io.*;
import java.util.Random;

class Game{
    private static BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    private static Random rnd = new Random();
    private Board p1;
    private Board p2;
    private ViewScreen v1;
    private ViewScreen v2;
	
    public static void main(String[] args){
	int width;
	int height;
	if(args.length == 0){
	    width = 10;
	    height = 10;
	}else if(args.length == 2){
	    width = Integer.parseInt(args[0]);
	    height = Integer.parseInt(args[1]);
	}else{
	    System.out.println("usage: ./Game [board_width board_height]");
	    return;
	}
	
	System.out.println("play battleship!");
	Game g = new Game(width, height);
	g.run(g);
    }
    
    public Game(int width, int height){
	this.init(width, height);
    }
    
    private void init(int width, int height){
	String name_prompt = "enter your admiral name: ";
	String name1 = this.getUserInput("player 1, " + name_prompt);
	String name2 = this.getUserInput("player 2, " + name_prompt);
	this.p1 = this.makeBoard(width, height, name1);
	this.p2 = this.makeBoard(width, height, name2);
	this.v1 = new ViewScreen(width, height);
	this.v2 = new ViewScreen(width, height);
    }
    
    public void run(Game g){
	boolean player1Turn = rnd.nextBoolean();
	
	while(this.p1.isAlive() && this.p2.isAlive()){
	    if(player1Turn){
		player1Turn = !player1Turn;
		this.doPlayerTurn(this.p1, this.v1, this.p2);
	    }else{
		player1Turn = !player1Turn;
		this.doPlayerTurn(this.p2, this.v2, this.p1);
	    }
	    // loop for number of shots for player:
	    //    get users guesses
	    //    test user guesses for hit (should return the ship hit if one is hit)
	    //       display message
	    //    test opposite player if they're alive
	    //       display message if dead
	    //       display game over if dead
	}
	return;
    }
    
    private void doPlayerTurn(Board b1, ViewScreen vs1, Board b2){
	System.out.println("This is what you see...");
	vs1.printMap();

	int shots = b1.getShots();
	for(int i = 0; i < shots; ++i){
	    String pos = this.getUserInput(b1.getName() + " enter guess: ");
	    String[] coords = pos.split(",");
	    int x = Integer.parseInt(coords[0]) - 1;
	    int y = Integer.parseInt(coords[1]) - 1;
	    if(x < 0 || x >= b2.getWidth() || y < 0 || y >= b2.getHeight()){
		System.out.println("that shot went off the board...");
	    }else{
		Pair<Integer, Integer> p = new Pair<Integer, Integer>(x, y);
		Pair<Integer, Ship> hitInfo = b2.checkHit(p);
		int hitCode = hitInfo.first();
		vs1.addShot(p, hitCode); // update the player viewscreen
		vs1.printMap();
		if(hitCode < 0){
		    System.out.println("Miss...");
		}else{
		    System.out.println("Hit the " + hitInfo.second().getName() + "!");
		    if(hitCode == 1){
			System.out.println("Sank the " + hitInfo.second().getName() + "!");
			if(!b2.isAlive()){
			    System.out.println("Game is over, " + b1.getName() + " wins, all forces of " + b2.getName() + " are wiped out...");
			    break;
			}
		    }
		}
	    }
	}
	return;
    }
        
    private Board makeBoard(int width, int height, String name){
	Board b = new Board(width, height, name);
	b.addShip(new Carrier());
	b.addShip(new Cruiser());
	b.addShip(new Destroyer());
	b.addShip(new Submarine());
	b.addShip(new Minesweeper());
	return b;
    }

    public String getUserInput(String prompt){
	String data = null;
	try{
	    System.out.println(prompt);
	    data = this.cin.readLine();
	}catch(IOException e){
	    System.out.println("there was an error reading data from stdin..." + e);
	}
	return data;
    }
}
