import java.util.ArrayList;

abstract class Ship{
    String shipName;
    ArrayList<Pair<Integer, Integer>> shipCells;
    ArrayList<Pair<Integer, Integer>> shipHits;
    int shipShots;
    int shipSize;
    boolean shipAlive;
    
    /*
    public Ship(String name, int size, int shots){
	// actually this shouldn't be here, just testing, ship should be abstract
	this.init(name, size, shots);
    }
    */
    
    public boolean checkHit(Pair<Integer, Integer> pos){
	if(shipCells == null || shipCells == null){
	    return false;
	}
	if(shipCells.contains(pos) && !shipHits.contains(pos)){
	    shipHits.add(pos);
	    if(shipHits.size() == shipCells.size()){
		shipAlive = false;
	    }
	    return true;
	}
	return false;
    }
    
    public ArrayList<Pair<Integer, Integer>> getCells(){
	return this.shipCells;
    }

    public ArrayList<Pair<Integer, Integer>> getHits(){
	return this.shipHits;
    }
    
    public String getName(){
	return this.shipName;
    }
    
    public int getShots(){
	return this.shipShots;
    }

    public int getSize(){
	return this.shipSize;
    }


    public int hashCode() {
	int hashName = this.shipName != null ? this.shipName.hashCode() : 0;
	int hashCells = this.shipCells != null ? this.shipCells.hashCode() : 0;
	int hashHits = this.shipHits != null ? this.shipHits.hashCode() : 0;
	int hashShots = this.shipShots;
	int hashSize = this.shipSize;
	int hashAlive = this.shipAlive ? 2 : 1;
	
	int hash = (43 * hashName) + (47 * hashCells) + (53 * hashHits) + (59 * hashShots) + (61 * hashSize) + (67 * hashAlive);

	return hash;
    }


    
    protected void init(String name, int size, int shots){
	this.shipName = name;
	this.shipSize = size;
	this.shipShots = shots;
	this.shipAlive = true;
	this.shipCells = new ArrayList<Pair<Integer, Integer>>();
	this.shipHits = new ArrayList<Pair<Integer, Integer>>();
    }
    
    public boolean isAlive(){
	return this.shipAlive;
    }
    
    public void setCells(ArrayList<Pair<Integer, Integer>> cells){
	this.shipCells = cells;
    }
}
