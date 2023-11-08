package main;
import Object.*;

public class AssetSetter {
    GamePanel gp;
    public AssetSetter(GamePanel gp)
    {
        this.gp = gp;
    }
    public void setObject(){
        gp.obj[0] = new Objcoin();
        gp.obj[0].worldX = 10 * gp.titalSize;
        gp.obj[0].worldY = 10 * gp.titalSize;

        gp.obj[9] = new Objcoin();
        gp.obj[9].worldX = 47 * gp.titalSize;
        gp.obj[9].worldY = 16 * gp.titalSize;

        gp.obj[10] = new Objcoin();
        gp.obj[10].worldX = 12 * gp.titalSize;
        gp.obj[10].worldY = 44 * gp.titalSize;

        gp.obj[11] = new Objcoin();
        gp.obj[11].worldX = 47 * gp.titalSize;
        gp.obj[11].worldY = 33 * gp.titalSize;

        gp.obj[12] = new Objcoin();
        gp.obj[12].worldX = 26 * gp.titalSize;
        gp.obj[12].worldY = 33 * gp.titalSize;

        gp.obj[8] = new Objcoin();
        gp.obj[8].worldX = 15 * gp.titalSize;
        gp.obj[8].worldY = 15 * gp.titalSize;

        gp.obj[1] = new Exit();
        gp.obj[1].worldX = 25 * gp.titalSize;
        gp.obj[1].worldY = 48 * gp.titalSize;

        gp.obj[2] = new BlueBall();
        gp.obj[2].worldX =  2*gp.titalSize;
        gp.obj[2].worldY =  2*gp.titalSize;

        gp.obj[3] = new GreenBall();
        gp.obj[3].worldX = 25 *  gp.titalSize;
        gp.obj[3].worldY =   gp.titalSize;

        gp.obj[4] = new OrangeBall();
        gp.obj[4].worldX = 48 *  gp.titalSize;
        gp.obj[4].worldY = gp.titalSize;

        gp.obj[5] = new PurpleBall();
        gp.obj[5].worldX =  gp.titalSize;
        gp.obj[5].worldY = 48 *  gp.titalSize;

        gp.obj[6] = new YellowBall();
        gp.obj[6].worldX = 16*gp.titalSize;
        gp.obj[6].worldY = 30*gp.titalSize;

        gp.obj[7] = new SkyBall();
        gp.obj[7].worldX = 47 *  gp.titalSize;
        gp.obj[7].worldY = 40 *  gp.titalSize;
    }
}
