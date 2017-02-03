class Carrier extends Ship{
    
    String[] carrierNames = {"USS Wasp",
                             "USS Hornet",
                             "USS Essex",
                             "USS Lexington",
                             "USS Saratoga",
                             "USS Oriskany"};
    int carrierSize = 5;
    int carrierShots = 5;
    
    public Carrier(){
	init(carrierNames[(int) (Math.random() * carrierNames.length)], carrierSize, carrierShots);
    }
}
