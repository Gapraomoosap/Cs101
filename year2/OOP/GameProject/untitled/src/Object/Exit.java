package Object;

import javax.imageio.ImageIO;
import java.io.IOException;

public class Exit extends SuperObject{
    public Exit(){
        name = "Exit";
        try{
            image = ImageIO.read(getClass().getResourceAsStream("/resources/object/Exit.png"));
        }catch(IOException e){
            e.printStackTrace();
        }
        collision = true;
    }
}
