#include <stdio.h>

void display(int arr[3][3]){
    for(int i = 0;i < 3;i++){
         printf("\n");
        for(int j = 0;j < 3;j++){
            printf("%d", arr[i][j]);
            printf(" | ");
        }
        printf("\b\b \n");
        if(i != 2){
            printf("----------");
        }
    }

}

void selection(int arr[3][3], int n){
    int choice;
    int i, j;
    do{
        printf("choice: ");
        scanf("%d", &choice);
        choice--;
        j = choice % 3;
        i = choice/3;
        if(arr[i][j] == 0){
            arr[i][j]=n;
            break;
        }
        else{
            printf("Please choose an empty space\n");
            display(arr);
        }
    }while(1);
}

int checkWin(int arr[3][3]){
    int i=0, j=0;

    if(arr[i][j] == arr[i+1][j+1] && arr[i+1][j+1] == arr[i+2][j+2]){
        return arr[i][j];
    }

    for(i = 0, j = 0; i < 3; i++){
        if(arr[i][j] == arr[i][j+1] && arr[i][j+1] == arr[i][j+2]){
            return arr[i][j];
        }
    }

    if(arr[i][j] == arr[i+1][j-1] && arr[i+1][j-1] == arr[j][i]){
        return arr[i][j];
    }

    for(i=0, j = 0; j < 3; j++){
        if(arr[i][j] == arr[i+1][j] && arr[i+1][j] == arr[i+2][j]){
            return arr[i][j];
        }
    }

    if(arr[i][j] == arr[i+1][j-1] && arr[i+1][j-1] == arr[j][i]){
        return arr[i][j];
    }
    return 0;
}

char restart(){
    char re;
    printf("\nwould you like to play again?(y/n):");
        getchar();
        scanf("%c", &re);
        if (re == 'y') {
           return re;
        }else{
            printf("\nexiting program...");
        }
}

int main(){
    int arr[3][3]={0};
    int winner, player, q=0;
    char replay;
    do {display(arr);
        while(q != 9){
            for(player = 1; player < 3; player++){
                printf("player %d move:-\n", player);
                selection(arr, player);
                display(arr);
                q++;
                winner = checkWin(arr);
                //printf("winner = %d", winner);
                if(winner != 0){
                    break;
                }  
                //printf("%d", player);
                if(player == 2){
                    player = player-2;
                }
            }
        }
        if(winner !=0){ 
            printf("Player %d has won!", player);
        } else {printf("\nDraw\n");}
        q = 0;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                arr[i][j] = 0;
            }
        }    
        replay = restart();
    } while(replay == 'y');
}
