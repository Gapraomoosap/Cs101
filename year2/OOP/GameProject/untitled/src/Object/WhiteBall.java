package Object;

import javax.imageio.ImageIO;
import java.io.IOException;

public class WhiteBall extends SuperObject{
    public WhiteBall(){
        name = "white";
        try{
            image = ImageIO.read(getClass().getResourceAsStream("/resources/object/whiteBall.png"));
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
