public class RoachPopulation {
    private int number;
    public RoachPopulation(){

    }
    public RoachPopulation(int num){
        number = num;
    }

    public void Wait(){
        number = number * 2;
    }
    public void spray(){
        number = number - (number / 10);
    }
    public int getRoaches(){
        return number;
    }

}
