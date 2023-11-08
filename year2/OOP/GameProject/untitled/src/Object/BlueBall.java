package Object;

import javax.imageio.ImageIO;
import java.io.IOException;

public class BlueBall extends SuperObject{
    public BlueBall(){
        name = "blue";
        try{
            image = ImageIO.read(getClass().getResourceAsStream("/resources/object/blueBall.png"));
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
