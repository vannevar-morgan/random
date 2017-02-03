import java.util.Map;
import java.util.HashMap;

class test{
    private Map<Pair<Integer, Integer>, Integer> m;
    private Map<Pair<Integer, Ship>, Ship> shipMap;

    public static void main(String[] args){
	test t = new test();
	t.doTest();
    }
    
    public test(){
	this.init();
    }
    
    private void init(){
	this.m = new HashMap<Pair<Integer, Integer>, Integer>();
	this.shipMap = new HashMap<Pair<Integer, Ship>, Ship>();
    }
    
    public void doTest(){
	System.out.println("Size of map: " + this.m.size());
	this.m.put(new Pair<Integer, Integer>(1, 1), 52);
	System.out.println("Size of map: " + this.m.size());
	if(this.m.containsKey(new Pair<Integer, Integer>(1, 1))){
	    System.out.println("found the pair in the map...");
	}else{
	    System.out.println("something isn't correct finding objects in the map...");
	}
	
	System.out.println("testing shipMap...");
	System.out.println("Size of map: " + this.shipMap.size());
	Carrier c1 = new Carrier();
	Carrier c2 = new Carrier();
	this.shipMap.put(new Pair<Integer, Ship>(1, c1), c2);
	System.out.println("Size of map: " + this.shipMap.size());
	if(this.shipMap.containsKey(new Pair<Integer, Ship>(1, c1))){
	    System.out.println("found the pair in the map...");
	}else{
	    System.out.println("something isn't correct finding objects in the map...");
	}
	
	System.out.println("testing pair hashcodes...");
	Pair<Integer, Ship> p1 = new Pair<Integer, Ship>(1, new Carrier());
	Pair<Integer, Ship> p2 = new Pair<Integer, Ship>(1, new Carrier());
	System.out.println("hashcode, first pair: " + p1.hashCode());
	System.out.println("hashcode, second pair: " + p2.hashCode());
    }
}
