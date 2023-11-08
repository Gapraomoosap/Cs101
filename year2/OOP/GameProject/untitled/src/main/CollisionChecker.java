package main;
import entity.Entity;
public class CollisionChecker {
    GamePanel gp;

    public CollisionChecker(GamePanel gp){
        this.gp = gp;
    }
    public void checkTile(Entity entity){
        int entityLeftWorldX = entity.x + entity.solidArea.x;
        int entityRightWorldX = entity.x + entity.solidArea.x + entity.solidArea.width;
        int entityTopWorldY = entity.y + entity.solidArea.y;
        int entityBottomWorldY = entity.y + entity.solidArea.y + entity.solidArea.height;

        int entityLeftCol = entityLeftWorldX/gp.titalSize;
        int entityRightCol = entityRightWorldX/gp.titalSize;
        int entityTopRow = entityTopWorldY/gp.titalSize;
        int entityBottomRow = entityBottomWorldY/gp.titalSize;

        int tileNum1,tileNum2;

        if(entity.direction=="up"){
            entityTopRow = (entityTopWorldY - entity.speed)/gp.titalSize;
            tileNum1 = gp.tileM.mapTileNum[entityLeftCol][entityTopRow];
            tileNum2 = gp.tileM.mapTileNum[entityRightCol][entityTopRow];
            if(gp.tileM.tile[tileNum1].collision == true || gp.tileM.tile[tileNum2].collision == true){
                entity.collisionOn = true;
            }
        } else if (entity.direction == "down") {
            entityBottomRow = (entityBottomWorldY + entity.speed)/gp.titalSize;
            tileNum1 = gp.tileM.mapTileNum[entityLeftCol][entityBottomRow];
            tileNum2 = gp.tileM.mapTileNum[entityRightCol][entityBottomRow];
            if(gp.tileM.tile[tileNum1].collision == true || gp.tileM.tile[tileNum2].collision == true){
                entity.collisionOn = true;
            }

        } else if (entity.direction == "left") {
            entityLeftCol = (entityLeftWorldX - entity.speed)/gp.titalSize;
            tileNum1 = gp.tileM.mapTileNum[entityLeftCol][entityTopRow];
            tileNum2 = gp.tileM.mapTileNum[entityLeftCol][entityBottomRow];
            if(gp.tileM.tile[tileNum1].collision == true || gp.tileM.tile[tileNum2].collision == true){
                entity.collisionOn = true;
            }
        } else if (entity.direction == "right") {
            entityRightCol = (entityRightWorldX + entity.speed)/gp.titalSize;
            tileNum1 = gp.tileM.mapTileNum[entityRightCol][entityTopRow];
            tileNum2 = gp.tileM.mapTileNum[entityRightCol][entityBottomRow];
            if(gp.tileM.tile[tileNum1].collision == true || gp.tileM.tile[tileNum2].collision == true){
                entity.collisionOn = true;
            }
            
        }
    }
    public int checkObject(Entity entity,boolean player){
        int index = 999;
        for(int i = 0 ;i < gp.obj.length; i++){
            if(gp.obj[i] != null){
                entity.solidArea.x = entity.x + entity.solidArea.x;
                entity.solidArea.y = entity.y + entity.solidArea.y;
                gp.obj[i].solidArea.x = gp.obj[i].worldX + gp.obj[i].solidArea.x;
                gp.obj[i].solidArea.y = gp.obj[i].worldY + gp.obj[i].solidArea.y;
                if(entity.direction == "up"){
                    entity.solidArea.y -= entity.speed;
                    if(entity.solidArea.intersects(gp.obj[i].solidArea)){
                        if(gp.obj[i].collision == true){
                            entity.collisionOn = true;
                        }
                        if(player == true){
                            index = i;
                        }
                    }
                }
                else if(entity.direction == "down"){
                    entity.solidArea.y += entity.speed;
                    if(entity.solidArea.intersects(gp.obj[i].solidArea)){
                        if(gp.obj[i].collision == true){
                            entity.collisionOn = true;
                        }
                        if(player == true){
                            index = i;
                        }
                    }
                }
                else if(entity.direction == "left"){
                    entity.solidArea.x -= entity.speed;
                    if(entity.solidArea.intersects(gp.obj[i].solidArea)){
                        if(gp.obj[i].collision == true){
                            entity.collisionOn = true;
                        }
                        if(player == true){
                            index = i;
                        }
                    }
                }
                else if(entity.direction == "right"){
                    entity.solidArea.x += entity.speed;
                    if(entity.solidArea.intersects(gp.obj[i].solidArea)){
                        if(gp.obj[i].collision == true){
                            entity.collisionOn = true;
                        }
                        if(player == true){
                            index = i;
                        }
                    }
                }
                entity.solidArea.x = entity.solidAreaDefaultX;
                entity.solidArea.y = entity.solidAreaDefaultY;
                gp.obj[i].solidArea.x = gp.obj[i].solidAreaDefaultX;
                gp.obj[i].solidArea.y = gp.obj[i].solidAreaDefaultY;

            }
        }
        return index;
    }
}
