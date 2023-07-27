//beakjoon problem number 7569
//tomato
//start date : 23-07-27
//solve date : 23-07-27

#include <iostream>
#define MAX_SIZE 1000001

class Coord{
    public:
      int x,y,z;
      Coord():x(0), y(0), z(0){};
      Coord(int x, int y, int z): x(x), y(y), z(z){};
};

class Queue{
    Coord* queue = new Coord[MAX_SIZE];
    
    public:
      int front = 0;
      int end = 0;
      void enqueue(int x, int y, int z){
        queue[end] = Coord(x,y,z);
        end++;
        if (end > 1000000 ){
            end = 0;
        }
      }
      void enqueue(Coord c){
        queue[end] = c;
        end++;
        if (end > 1000000 ){
            end = 0;
        }
      }
      Coord dequeue(){
        Coord temp = queue[front];
        front++;
        if (front > 1000000 ){
            front = 0;
        }
        return temp;
      }
      void printQ(){
        int size = end-front;
        Coord temp;
        printf("===Queue===\n");
        printf("XX%3c %3c %3c\n",'x','y','z');
        for(int i=0;i<size;i++){
            temp = queue[front+1];
            printf("%2d%3d %3d %3d\n",i,temp.x,temp.y,temp.z);
        }
      }
};

int main(){
    int M,N,H;
    scanf("%d %d %d",&M,&N,&H);
    getchar();
    int box[M+2][N+2][H+2];

    for(int i=0;i<=H+1;i++){
        for(int j=0;j<=N+1;j++){
            for(int k=0;k<=M+1;k++){
                box[k][j][i] = -2;
            }
        }
    }
    
    for(int i=1;i<=H;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                scanf("%d",&box[k][j][i]);
            }
        }
    }

    Queue q;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                if(box[k][j][i] == 1){
                    //상하좌우 체크
                    //안익은 토마토 있으면 익힌다
                    if(box[k+1][j][i] == 0){box[k+1][j][i] = 2;q.enqueue(k+1,j,i);}
                    if(box[k-1][j][i] == 0){box[k-1][j][i] = 2;q.enqueue(k-1,j,i);}
                    if(box[k][j+1][i] == 0){box[k][j+1][i] = 2;q.enqueue(k,j+1,i);}
                    if(box[k][j-1][i] == 0){box[k][j-1][i] = 2;q.enqueue(k,j-1,i);}
                    if(box[k][j][i+1] == 0){box[k][j][i+1] = 2;q.enqueue(k,j,i+1);}
                    if(box[k][j][i-1] == 0){box[k][j][i-1] = 2;q.enqueue(k,j,i-1);}
                }
            }
        }
    }
    
    int x,y,z;
    int val=0;
    int finish;
    while(q.front!=q.end){
        //q.printQ();
        finish = q.end;
        while(q.front!=finish){
            Coord temp = q.dequeue();
            x = temp.x;
            y = temp.y;
            z = temp.z;
            val = box[x][y][z]+1;
            if(box[x+1][y][z] == 0){box[x+1][y][z] = val;q.enqueue(x+1,y,z);}
            if(box[x-1][y][z] == 0){box[x-1][y][z] = val;q.enqueue(x-1,y,z);}
            if(box[x][y+1][z] == 0){box[x][y+1][z] = val;q.enqueue(x,y+1,z);}
            if(box[x][y-1][z] == 0){box[x][y-1][z] = val;q.enqueue(x,y-1,z);}
            if(box[x][y][z+1] == 0){box[x][y][z+1] = val;q.enqueue(x,y,z+1);}
            if(box[x][y][z-1] == 0){box[x][y][z-1] = val;q.enqueue(x,y,z-1);}
        }
    }

    for(int i=1;i<=H;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                if(box[k][j][i] == 0){
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }

    if(val){
        val -= 2;
    }
    printf("%d", val);
    return 0;
}
