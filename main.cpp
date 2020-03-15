#include "Header.h"


int Menu(){
    int key = 0;
    int code;
    do {
        system( "cls" );
        cout << "Choose:\n";
        key = ( key + 2 ) % 2;
        if ( key == 0 ) cout<<"-> 19"<<endl;
            else  cout<<"   19"<<endl;
        if ( key == 1 ) cout<<"-> 25"<<endl;
            else  cout<<"   25"<<endl;

        code =  _getch();
        if ( code == 224 ){
            code = _getch();
            if ( code == 80 ) key ++;
            if ( code == 72 ) key --;
        }
        if ( code == 27 ){
            system( "cls" );
            exit(0);
        }
    }while( code != 13 );
    system( "cls" );
    return key;
}


int main(){
    int answer = Menu();
    switch ( answer ){
        case 0: Body19(); break;
        case 1: Body25(); break;
    }
}
