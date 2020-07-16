#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função que insere um elemento no nosso jogo da velha
int InserirElemento(char elemento, char matriz[3][3], int i, int j){

    if(matriz[i][j] == 'X' || matriz[i][j] == 'O'){
        printf ("ERROR :: Ja jogaram neste lugar. Digite novamente.\n");
        return 0;
    }
    else if (i<0 || i>2 || j<0 || j>2){
        printf ("ERROR :: Comando invalido. Digite novamente.\n");
        return 0;
    }
    else{
        matriz[i][j]=elemento;
        return 1;
    }
}

//Função responsável por imprimir a matriz
void ImprimirJogo(char matriz[3][3]){
    int i, j;

    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            if (matriz[i][j] == 'X'){
                printf (" X ");
            }else if (matriz[i][j] == 'O'){
                printf (" O ");
            }else {
                printf ("   ");
            }

            if (j != 2){
                printf("|");
            }

        }
        if (i != 2){
            printf("\n--- --- ---\n");
        }
    }

    printf("\n");
}

//Função para limpar a tela
void LimparTel(){
    system("cls");
}


void VezJogador(int vez, char Player[100], char M[3][3]){
    int i, j;
    int error;

    printf ("Agora eh a vez do(a) %s\n", Player);
    printf ("Digite as coordenadas\n");
     if (vez == 1){

            do{
                printf ("Linha: ");
                scanf ("%i", &i);
                printf ("Coluna: ");
                scanf ("%i", &j);
                error = InserirElemento('X',M,i-1,j-1);
            }while(error==0);

    }
     else{

            do{
                printf ("Linha: ");
                scanf ("%i", &i);
                printf ("Coluna: ");
                scanf ("%i", &j);
                error = InserirElemento('O',M,i-1,j-1);
            }while(error==0);
        }
}



int VerificaVitoria (char M[3][3], char elemento){

    if (M[0][0] == M[0][1] && M[0][1] == M[0][2] && M[0][2] == elemento){
        return 1;
    }
    else if (M[1][0] == M[1][1] && M[1][1] == M[1][2] && M[1][2] == elemento){
        return 1;
    }
    else if (M[2][0] == M[2][1] && M[2][1] == M[2][2] && M[2][2] == elemento){
        return 1;
    }
    else if (M[0][0] == M[1][0] && M[1][0] == M[2][0] && M[2][0] == elemento){
        return 1;
    }
    else if (M[0][1] == M[1][1] && M[1][1] == M[2][1] && M[2][1] == elemento){
        return 1;
    }
    else if (M[0][2] == M[1][2] && M[1][2] == M[2][2] && M[2][2] == elemento){
        return 1;
    }
    else if (M[0][0] == M[1][1] && M[1][1] == M[2][2] && M[2][2] == elemento){
        return 1;
    }
    else if (M[0][2] == M[1][1] && M[1][1] == M[2][0] && M[2][0] == elemento){
        return 1;
    }
    else{
        return 0;
    }
}


void DigitarNome(char Player[100], int user){
    printf ("Digite o nome do jogador %i: ", user);
    scanf ("%[^\n]", Player);
    fflush(stdin);
}

int main(){

    char M[3][3];
    int fim=0;
    char Player1[100];
    char Player2[100];
    int vez = 1;
    int i, j;


    DigitarNome(Player1, 1);
    DigitarNome(Player2, 2);


    do{
        LimparTel();
        ImprimirJogo(M);
        if (vez == 1){
            VezJogador(vez,Player1,M);
            fim = VerificaVitoria(M, 'X');
            vez=2;

        }
        else{
            VezJogador(vez,Player2,M);
            fim = VerificaVitoria(M, 'O');
            vez=1;
        }

    }while (fim == 0);
    LimparTel();
    ImprimirJogo(M);

    if (vez==1) vez = 2;
    else vez = 1;

    printf("Parabens pela vitoria jogador(a) %i!\n", vez);

    return 0;
}
