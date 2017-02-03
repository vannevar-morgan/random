class Minesweeper extends Ship{
    
    String[] minesweeperNames = {"USS Planter",
                                 "USS Barricade",
                                 "USS Picket",
                                 "USS Obstructor",
                                 "USS Buttress",
                                 "USS Camanche"};
    int minesweeperSize = 2;
    int minesweeperShots = 2;
    public Minesweeper(){
	init(minesweeperNames[(int) (Math.random() * minesweeperNames.length)], minesweeperSize, minesweeperShots);
    }
}
