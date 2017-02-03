class Destroyer extends Ship{
    
    String[] destroyerNames = {"USS Arleigh Burke",
                               "USS John Paul Jones",
                               "USS Russell",
                               "USS Fitzgerald",
                               "USS The Sullivans",
                               "USS Laboon"};
    int destroyerSize = 3;
    int destroyerShots = 3;
    
    public Destroyer(){
	init(destroyerNames[(int) (Math.random() * destroyerNames.length)], destroyerSize, destroyerShots);
    }

}
