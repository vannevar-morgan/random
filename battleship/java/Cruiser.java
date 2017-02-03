class Cruiser extends Ship{
    
    String[] cruiserNames = {"USS Astoria",
                             "USS Portland",
                             "USS Indianapolis",
                             "USS Juneau",
                             "USS Lake Erie",
                             "USS Augusta"};
    int cruiserSize = 4;
    int cruiserShots = 4;
    
    public Cruiser(){
	init(cruiserNames[(int) (Math.random() * cruiserNames.length)], cruiserSize, cruiserShots);
    }
}
