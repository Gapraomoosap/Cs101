package Object;

import javax.imageio.ImageIO;
import java.io.IOException;

public class SkyBall extends SuperObject{
    public SkyBall(){
        name = "sky";
        try{
            image = ImageIO.read(getClass().getResourceAsStream("/resources/object/skyBall.png"));
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
