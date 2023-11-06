package Tiles;

import main.GamePanel;

import javax.imageio.ImageIO;
import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Tilemanager {
    GamePanel gp;
    public Tile[] tile;
    public int mapTileNum[][];
    public Tilemanager(GamePanel gp)
    {
        this.gp = gp;
        tile = new Tile[10];
        mapTileNum = new int[gp.maxWorldCol][gp.maxWorldRow];
        getTileImage();
        loadMap();
    }
    public void getTileImage(){
        try{
            tile[0] = new Tile();
            tile[0].image = ImageIO.read(getClass().getResourceAsStream("/resources/tiles/sky.png"));

            tile[1] = new Tile();
            tile[1].image = ImageIO.read(getClass().getResourceAsStream("/resources/tiles/block2.png"));
            tile[1].collision = true;

        }catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public void loadMap(){
        try {
            InputStream is = getClass().getResourceAsStream("/resources/map/map2.txt");
            BufferedReader br = new BufferedReader(new InputStreamReader(is));

            int col = 0;
            int row = 0;
            while (col < gp.maxWorldCol && row < gp.maxWorldRow){
                String line = br.readLine();
                while(col < gp.maxWorldCol){
                    String numbers[] = line.split(" ");
                    int num = Integer.parseInt(numbers[col]);
                    mapTileNum[col][row] = num;
                    col++;
                }
                if(col == gp.maxWorldCol){
                    col = 0;
                    row++;
                }
            }
            br.close();
        }catch (Exception e){

        }
    }

    public void draw(Graphics2D g2)
    {
        int worldCol = 0;
        int worldRow = 0;

        while (worldCol < gp.maxWorldCol && worldRow<gp.maxWorldRow){
            int tileNum = mapTileNum[worldCol][worldRow];
            int worldX = worldCol * gp.titalSize;
            int worldY = worldRow * gp.titalSize;
            int screenX = worldX - gp.player.x + gp.player.screenX;
            int screenY = worldY - gp.player.y + gp.player.screenY;

            if(worldX + gp.titalSize > gp.player.x - gp.player.screenX &&
               worldX - gp.titalSize < gp.player.x + gp.player.screenX &&
               worldY + gp.titalSize > gp.player.y - gp.player.screenY &&
               worldY - gp.titalSize < gp.player.y + gp.player.screenY){
                g2.drawImage(tile[tileNum].image,screenX,screenY,gp.titalSize,gp.titalSize,null);
            }
            worldCol++;

            if(worldCol == gp.maxWorldCol)
            {
                worldCol = 0;

                worldRow++;

            }
        }
    }
}
