class Submarine extends Ship{
    
    String[] submarineNames = {"USS Ohio",
                               "USS Seawolf",
                               "USS Los Angeles",
                               "USS Gato",
                               "USS Texas",
                               "USS Charlotte"};
    int submarineSize = 3;
    int submarineShots = 3;
    
    public Submarine(){
	init(submarineNames[(int) (Math.random() * submarineNames.length)], submarineSize, submarineShots);
    }
}
