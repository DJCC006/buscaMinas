#include <iostream>
#include <string>
#include <ctime>
#include<iomanip>


using namespace std;

//Variables Globales

//variables solo para inicializar las funciones con el tablero
const int xTablero=8;
const int yTablero=8;

//struct para manejar de forma más ordenada la información del juego
struct gameInfo{
    string dificultad;
    int numMinas;
    int filas;
    int columnas;
};


//Quitar quiza
struct Mina{
    int x;
    int y;
    bool activada;
};

//prototipos
void showMenuPrincipal();
void printTablero(const gameInfo saver, const char tableroLogic[xTablero][yTablero]);
void colocarMinas(const gameInfo saver, char tableroLogic[xTablero][yTablero], int contador, int x, int y);
void fillTablero(const gameInfo saver, char tableroLogic[xTablero][yTablero]);

int main()
{
    srand(time(0));
    int opcion=0;
    gameInfo saver;

    do{
        showMenuPrincipal();
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion){



            case 1:{
                int difOpcion=0;
                cout<<"\n---Dificultades---"<<endl;
                cout<<"1.Facil"<<endl;
                cout<<"2.Intermedio"<<endl;
                cout<<"3.Dificil"<<endl;
                cout<<"Seleccione una dificultad: ";
                cin>>difOpcion;


                //set de dificultad
                if(difOpcion==1){
                    saver.dificultad="Facil";
                    saver.filas=8;
                    saver.columnas=8;
                    saver.numMinas=10;

                }else if(difOpcion==2){
                    saver.dificultad="Intermedio";
                    saver.filas=16;
                    saver.columnas=16;
                    saver.numMinas=40;

                }else if(difOpcion==3){

                    saver.dificultad="Dificil";
                    saver.filas=30;
                    saver.columnas=16;
                    saver.numMinas=99;
                }

                char tableroLogic [xTablero][yTablero];


                //InitGame
                fillTablero(saver, tableroLogic);
                colocarMinas(saver, tableroLogic, 0, 0,0);
                printTablero(saver, tableroLogic);


                break;
            }

            case 2:{
                cout<<"Cerrando Sesion..."<<endl;
                break;
            }
        }


    }while(opcion!=2);




    return 0;
}



void showMenuPrincipal(){
    cout<<"====BUSCA MINAS C++===="<<endl;
    cout<<"1. Jugar"<<endl;
    cout<<"2. Salir"<<endl;
}



void colocarMinas(const gameInfo saver, char tableroLogic[xTablero][yTablero], int contador, int x, int y){
    if(contador==saver.numMinas){
        return;
    }

    int fila=x;
    int columna =y;

    if(tableroLogic[fila][columna]=='B'){
        colocarMinas(saver, tableroLogic, contador, rand()%saver.filas, rand()%saver.columnas);
    }else{
        tableroLogic[fila][columna]='B';
        colocarMinas(saver, tableroLogic, contador++, rand()%saver.filas, rand()%saver.columnas);
    }
}

void printTablero(const gameInfo saver, const char tableroLogic[xTablero][yTablero]){
    for(int i=0; i< saver.filas; i++){
        for(int j=0; j<saver.columnas; j++){
            cout<<setw(5)<<tableroLogic[i][j];
        }
        cout<<endl;
    }
}

void fillTablero(const gameInfo saver, char tableroLogic[xTablero][yTablero]){
    for(int i=0; i< saver.filas; i++){
        for(int j=0; j<saver.columnas; j++){
            tableroLogic[i][j]='*';
        }
    }
}


