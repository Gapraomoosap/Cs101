package year2.OOP.lab8.lab8_7;

import java.util.*;
public class Lab8_7 {

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int n=input.nextInt();
        int m=input.nextInt();
        int[][] a=new int[m][n];
        for(int i=0;i<m;i++){
            int s=input.nextInt();
            for(int j=0;j<s;j++){
                a[i][j]=input.nextInt();
            }
        }
        int begin;
        int q=input.nextInt();
        for(int i=0;i<q;i++){
            begin=input.nextInt();
            end=input.nextInt();
            find(a,begin,0);
            if(count==1000000000){
                System.out.println("Impossible");
            }
            else{
                System.out.println(count);
            }
            count=1000000000;
        }
    }
    static int count=1000000000,end;
    
    static void find(int[][] t,int station,int time){
        int[][] train=new int[t.length][t[0].length];
        ArrayList<Integer> check=new ArrayList<Integer>();
        boolean c1=false,c2=false;
        for(int i=0;i<t.length;i++){
            for(int j=0;j<t[i].length;j++){
                train[i][j]=t[i][j];
                if(train[i][0]!=-1){
                    if(train[i][j]==station){
                        c1=true;
                    }
                    else if(train[i][j]==end){
                        c2=true;
                    } 
                    if(c1&&c2){
                        if(time==0){
                            count=time;
                            return;
                        }
                        else if(count>time){
                            count=time;
                        }
                    }
                    else if(train[i][j]==station&&!check.contains(i)){
                        check.add(i);
                    }
                }
            }
            c1=false;
            c2=false;
        }
        
        for(int i=0;i<check.size();i++){
            int j=0,temp=train[check.get(i)][0];
            train[check.get(i)][0]=-1;
            while(train[check.get(i)][j]!=0){
                if(j==0) find(train,temp,time+1);
                else find(train,train[check.get(i)][j],time+1);
                j++;
            }
        }
        
    }
}