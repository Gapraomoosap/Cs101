package Object;

import javax.imageio.ImageIO;
import java.io.IOException;

public class Objcoin extends SuperObject{
    public Objcoin(){
        name = "key";
        try{
            image = ImageIO.read(getClass().getResourceAsStream("/resources/object/Coin.png"));
        }catch(IOException e){
            e.printStackTrace();
        }
        collision = true;
    }
}
