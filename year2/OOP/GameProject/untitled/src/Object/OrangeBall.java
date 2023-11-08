package Object;

import javax.imageio.ImageIO;
import java.io.IOException;

public class OrangeBall extends SuperObject{
    public OrangeBall(){
        name = "orange";
        try{
            image = ImageIO.read(getClass().getResourceAsStream("/resources/object/orangeBall.png"));
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
