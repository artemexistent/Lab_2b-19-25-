#include "Header.h"


class List{

public:
    List();
    ~List();

    void push( int x );
    void Find( int x );

private:
    class Node{
    public:
        Node *up;
        Node *down;
        Node *left;
        Node *right;
        int elem;

        Node( int elem = 0, Node *left = 0, Node *down = 0, Node *up = 0, Node *right = 0 ){
            this->elem = elem;
            this->left = left;
            this->right = right;
            this->down = down;
            this->up = up;
        }

    };
    Node *head;
};


List::List(){
    head = 0;
};
List::~List(){
};



void List::push( int x ){
    Node *current = this->head;
    int hight = 2;
    srand(time(0));
    while (rand()%2==1){
        hight ++;
    }

    if (current == 0){
        bool f=false;
        Node *re = 0;
         while (hight > 0){
            Node * cur = new Node(x);
            if (f){
                re->up = cur;
            }else f=true;
            cur->down = re;
            cur->left = 0;
            cur->right = 0;
            cur->up = 0;
            re=cur;
            head = cur;
            hight --;
        }
        return;
    }



    while (current->down != 0){

        if (current->right!=0 && current->right->elem < x )
            current = current->right;
        else  current = current ->down;


    }

    Node *re = 0;
    bool f=false;
    while (hight > 0){
        Node * cur = new Node(x);

        cur->right = current->right;
        current->right = cur;
        cur->left = current;

        if (f){
            re->up = cur;
        }else f=true;
        cur->down = re;
        cur->left = 0;
        cur->right = 0;
        cur->up = 0;
        re=cur;
        while (current->up != 0 && current->left !=0)
            current = current ->left;
        current = current->up;
        hight --;
    }


}


void List::Find( int x ){
    Node *current = this->head;
    while (current->down != 0){

        if (current->right!=0){
            if (current->right->elem < x)
            current = current->right;
            else if (current->right->elem == x){ cout << "item found"; return; }
            else current = current->right;
        }
        else current = current ->down;

    }


}

void Demo1();
void Bench1();
void P25();

void Body25()
{
  int answer = menu();
    switch ( answer ){
        case 0: P25(); break;
        case 1: Demo1(); break;
        case 2: Bench1(); break;
    }
}



void Demo1(){
    List n;
    srand(time(0));
    int Kol=rand()%15+1;

    cout << "push " << Kol << " elem\n";
    n.push(0);
    Sleep(3000);
    for (int i=1;i<=Kol;i++){
        int x=rand()%1000;
        cout << "elem " << x << " added\n";
        n.push(x);
        Sleep(500);
    }
    Sleep(3000);
    for (int i=1;i<=Kol;i++){
        int x=rand()%1000;
        cout << "Find " << x << "  ";
        n.Find(x);
        cout << "\n";
        Sleep(500);
    }

}



void Bench1(){

    ofstream out("Benchmark25.txt");

    clock_t start, end;

    start = clock();
    end = clock();
    srand(time(0));
    for (int Kol=1;Kol<=100;Kol+=10){
        List n;
        for (int i=1;i<=Kol;i++){
            int x=rand()%1000;
            n.push(x);
            //cout << "elem " << x << " added\n";
        }

        for (int i=1;i<=Kol;i++){
            int x=rand()%1000;
            //cout << "Find " << x << "  ";
            n.Find(x);
        }
        end = clock();
        out << Kol << "  " << ((double) end - start) / ((double) CLOCKS_PER_SEC)  << "   " <<Kol*sizeof(List) << "\n";

    }

}


int menu2();

void P25(){
    List n;
    n.push(0);
    while(true){
        int answer = menu2();
        switch ( answer ){
            case 0: {cout << "enter item:"; int x; cin >> x; n.push(x); }break;
            case 1:{ cout << "enter item:"; int x; cin >> x; n.Find(x); }break;
            case 2: return; break;
        }
    }



}



int menu2(){

    int key = 0;
    int code;
    do {
        system( "cls" );
        cout << "Choose:\n";
        key = ( key + 3 ) % 3;
        if ( key == 0 ) cout<<"-> Push"<<endl;
            else  cout<<"   Push"<<endl;
        if ( key == 1 ) cout<<"-> Find"<<endl;
            else  cout<<"   Find"<<endl;
        if ( key == 2 ) cout<<"-> End"<<endl;
            else  cout<<"   End"<<endl;

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
