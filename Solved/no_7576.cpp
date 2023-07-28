//beakjoon problem number 7576
//tomato 2dimension
//start date : 23-07-28
//solve date : 23-07-28

#include <iostream>
#define MAX_SIZE 1000001

class Coord{
    public:
      int x,y;
      Coord():x(0), y(0){};
      Coord(int x, int y): x(x), y(y){};
};

class Queue{
    Coord* queue = new Coord[MAX_SIZE];
    
    public:
      int front = 0;
      int end = 0;
      void enqueue(int x, int y){
        queue[end] = Coord(x,y);
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
        printf("XX%3c %3c\n",'x','y');
        for(int i=0;i<size;i++){
            temp = queue[front+1];
            printf("%2d%3d %3d\n",i,temp.x,temp.y);
        }
      }
};

int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    getchar();
    int box[M+2][N+2];

    for(int j=0;j<=N+1;j++){
        for(int k=0;k<=M+1;k++){
            box[k][j] = -2;
        }
    }

    for(int j=1;j<=N;j++){
        for(int k=1;k<=M;k++){
            scanf("%d",&box[k][j]);
        }
    }

    Queue q;
    for(int j=1;j<=N;j++){
        for(int k=1;k<=M;k++){
            if(box[k][j] == 1){
                //상하좌우 체크
                //안익은 토마토 있으면 익힌다
                if(box[k+1][j] == 0){box[k+1][j] = 2;q.enqueue(k+1,j);}
                if(box[k-1][j] == 0){box[k-1][j] = 2;q.enqueue(k-1,j);}
                if(box[k][j+1] == 0){box[k][j+1] = 2;q.enqueue(k,j+1);}
                if(box[k][j-1] == 0){box[k][j-1] = 2;q.enqueue(k,j-1);}
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
            val = box[x][y]+1;
            if(box[x+1][y] == 0){box[x+1][y] = val;q.enqueue(x+1,y);}
            if(box[x-1][y] == 0){box[x-1][y] = val;q.enqueue(x-1,y);}
            if(box[x][y+1] == 0){box[x][y+1] = val;q.enqueue(x,y+1);}
            if(box[x][y-1] == 0){box[x][y-1] = val;q.enqueue(x,y-1);}
        }
    }

    for(int j=1;j<=N;j++){
        for(int k=1;k<=M;k++){
            if(box[k][j] == 0){
                printf("-1\n");
                return 0;
            }
        }
    }

    if(val){
        val -= 2;
    }
    printf("%d", val);
    return 0;
}
