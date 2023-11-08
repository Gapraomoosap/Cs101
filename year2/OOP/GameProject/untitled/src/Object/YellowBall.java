package Object;

import javax.imageio.ImageIO;
import java.io.IOException;

public class YellowBall extends SuperObject{
    public YellowBall(){
        name = "yellow";
        try{
            image = ImageIO.read(getClass().getResourceAsStream("/resources/object/yellowBall.png"));
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
