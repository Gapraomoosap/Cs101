package Object;

import javax.imageio.ImageIO;
import java.io.IOException;

public class PurpleBall extends SuperObject{
    public PurpleBall(){
        name = "purple";
        try{
            image = ImageIO.read(getClass().getResourceAsStream("/resources/object/purpleBall.png"));
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
