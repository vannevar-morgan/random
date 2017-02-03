import java.util.Map;
import java.util.HashMap;
//import java.util.ArrayList;

class ViewScreen{
    // represents what a player sees in battleship.
    // functions to update the viewscreen.
    // function to print the viewscreen.
    //ArrayList<Pair<Integer, Integer>> 
    private Map<Pair<Integer, Integer>, Integer> shotMap;
    private int mapWidth;
    private int mapHeight;
    
    public ViewScreen(int width, int height){
	this.init(width, height);
    }
    
    private void init(int width, int height){
	this.mapWidth = width;
	this.mapHeight = height;
	this.shotMap = new HashMap<Pair<Integer, Integer>, Integer>();
    }
    
    public void addShot(Pair<Integer, Integer> pos, int hitCode){
	if(!this.shotMap.containsKey(pos) && 
	   pos.first() >= 0 && 
	   pos.first() < this.mapWidth && 
	   pos.second() >= 0 &&
	   pos.second() < this.mapHeight){
	    this.shotMap.put(pos, hitCode);
	}
    }
    
    public int getHeight(){
	return this.mapHeight;
    }
    
    public Map<Pair<Integer, Integer>, Integer> getShotMap(){
	return this.shotMap;
    }
    
    public int getWidth(){
	return this.mapWidth;
    }
    
    public void printMap(){
	for(int j = 0; j < this.mapHeight; ++j){
	    for(int i = 0; i < this.mapWidth; ++i){
		Pair<Integer, Integer> pos = new Pair<Integer, Integer>(i, j);
		if(this.shotMap.containsKey(pos)){
		    int hitCode = this.shotMap.get(pos);
		    if(hitCode == -1){
			System.out.print(" . ");
		    }else if(hitCode == 0){
			System.out.print(" X ");
		    }else{
			System.out.print(" X ");
		    }
		}else{
		    System.out.print(" ~ ");
		}
	    }
	    System.out.println();
	}
    }
    
    public static void main(String[] args){
	testViewScreen();
    }
    
    private static void testViewScreen(){
	//	ViewScreen v = new ViewScreen();
	System.out.println("testing ViewScreen...\n");
	System.out.println("Test Creating ViewScreen...");
	ViewScreen v = new ViewScreen(10, 10);
	System.out.println("Test printMap()...");
	v.printMap();
	System.out.println("Test addShot() with miss...");
	v.addShot(new Pair<Integer, Integer>(5,5), -1);
	v.printMap();
	System.out.println("Test addShot() with hit...");
	v.addShot(new Pair<Integer, Integer>(6,6), 0);
	v.printMap();
	System.out.println("Test addShot() with sink...");
	v.addShot(new Pair<Integer, Integer>(7,7), 1);
	v.printMap();
	System.out.println("Test getShotMap()...");
	Map<Pair<Integer, Integer>, Integer> m = v.getShotMap();
	System.out.println(m);
	
	System.out.println("Test addShot() with miss at bounds...");
	v.addShot(new Pair<Integer, Integer>(0,0), -1);
	v.printMap();
	System.out.println("Test addShot() with miss at bounds...");
	v.addShot(new Pair<Integer, Integer>(1,1), -1);
	v.printMap();
	System.out.println("Test addShot() with miss at bounds...");
	v.addShot(new Pair<Integer, Integer>(9,9), -1);
	v.printMap();
	System.out.println("Test addShot() with miss at bounds...");
	v.addShot(new Pair<Integer, Integer>(10,10), -1);
	v.printMap();
	
	System.out.println("Test addShot() skew coords...");
	v.addShot(new Pair<Integer, Integer>(2,5), -1);
	v.printMap();
    }
}
