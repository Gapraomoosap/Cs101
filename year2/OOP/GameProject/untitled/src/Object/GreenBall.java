package Object;

import javax.imageio.ImageIO;
import java.io.IOException;

public class GreenBall extends SuperObject{
    public GreenBall(){
        name = "green";
        try{
            image = ImageIO.read(getClass().getResourceAsStream("/resources/object/greenBall.png"));
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
