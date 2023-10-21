package year2.OOP.lab7.lab7_6;
import java.util.*;

class ma{
    int x;
    int y;
    int d;
    ma(int x,int y){
        this.x = x;
        this.y = y;
    }
    ma(int x,int y,int d){
        this.x = x;
        this.y = y;
        this.d = d;
    }
}
public class Lab7_6 {

    static int xB,yB;
    static int xE,yE;
    static int Bombcount = 0;
    static int shortest = 0;
    static int rowNum[] = {-1, 0, 0, 1}; 
    static int colNum[] = {0, -1, 1, 0};
    static boolean isValid(int[][]maze,int x, int y) 
    { 
        return (x >= 0 && x < maze.length && y >= 0 && y < maze[0].length); 
    }
    static int BFS(int maze[][]) 
    {
        boolean [][]visited = new boolean[maze.length][maze[0].length]; 
        visited[xB][yB] = true; 
        ArrayList <ma> k = new ArrayList<ma>(); 
        k.add(new ma(xB,yB,1));
        while (!k.isEmpty()) 
        { 
            ma curr = k.get(0);

            if (curr.x == xE && curr.y == yE){
                Bombcount++;
                return curr.d; 
            }
            k.remove(0);
            for (int i=0;i<4;i++) 
            { 
                int row = curr.x + rowNum[i]; 
                int col = curr.y + colNum[i]; 

                if (isValid(maze,row,col) && maze[row][col] == 1 && !visited[row][col]) 
                { 
                    visited[row][col] = true; 
                    k.add(new ma(row,col,curr.d+1)); 
                } 
            } 
        } 
        return -1; 
    }    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);       
        int[][] maze;
        int maze_width = sc.nextInt();
        int maze_height = sc.nextInt();
        ArrayList <ma> wn = new ArrayList<>(); 
        maze = new int[maze_width][maze_height];      
        xB = sc.nextInt();
        yB = sc.nextInt();        
        xE = sc.nextInt();
        yE = sc.nextInt();       
        xB--;yB--;
        xE--;yE--;       
        for(int i=0;i<maze.length;i++){
            for(int j=0;j<maze[0].length;j++){
                maze[i][j] = sc.nextInt();
                if(maze[i][j]==0) wn.add(new ma(i,j));
            }
        }
        int[][] maze_copy = new int[maze.length][maze[0].length];
        
        for(ma G : wn){
            for(int i=0;i<maze_copy.length;i++){
                for(int j=0;j<maze_copy[i].length;j++){
                    maze_copy[i][j] = maze[i][j];
                }
            }
            maze_copy[G.x][G.y] = 1;
            int P = BFS(maze_copy);
            if(P!=(-1)){
                if(Bombcount==1){
                    shortest = P;
                }
                else{
                    if(shortest > P) shortest = P;
                }
            }
        }
        System.out.println(Bombcount+"\n"+shortest);
    }
}
