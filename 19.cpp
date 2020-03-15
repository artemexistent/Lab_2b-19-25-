#include "Header.h"

int menu();
void Demo();
void Bench();

string s2(int n){

    string ans="";

    while (n/2 != 0){
        ans = ans + char(n%2 + '0');
        n/=2;
    }
    if (n!=0)
    ans = ans + char(n%2 + '0');

    return ans;
}

int rec(int n, int k)
{
    if (n<k)
        swap(n,k);
    if(n==k)
        return 1;
    if(k==1)
        return n%2;
    return (rec(n-1, k-1)+rec(n-1, k))%2;
}

void P19()
{
    string s;
    cin >> s;
    int Kol=1;
    int t=2;
    while (t < s.size() ){
        Kol ++;
        t*=2;
    }
    vector <string>res;
    for (int i=0;i<s.size();i++){
        string str=s2(i);
        if (str.size()!=Kol)
            str = str + '0';
        res.push_back(s2(i));
    }

    vector <int> a;
    a.push_back(s[0]-'0');
    a.push_back((s[0]+s[1]-2*'0')%2);
    for (int i=2;i<s.size();i++){
        int res2=s[0]-'0';
        for (int j=1;j<i+1;j++){
            res2 = (res2 + (rec(i,j)%2)*(s[j]-'0'))%2;
        }
        a.push_back(res2);
    }


    bool f=false;
    for (int i=0;i<a.size();i++){
        if (a[i]==1){
            if (f)
                cout << "+";
            else f=true;
            for (int j=Kol-1;j>=0;j--){
                if (res[i][j]=='1'){
                    cout << "x(" << Kol-j << ")";
                }
            }
        }
    }
    return;
}

void Body19(){
    int answer = menu();
    switch ( answer ){
        case 0: P19(); break;
        case 1: Demo(); break;
        case 2: Bench(); break;
    }

}

void Demo(){

    string s="";
    srand(time(0));

    int te=pow(2,rand()%5+1);
    for (int i=0;i<te;i++){
        s=s+char(rand()%2+'0');
    }
    cout << s << "\n";
    int Kol=1;
    int t=2;
    while (t < s.size() ){
        Kol ++;
        t*=2;
    }
    vector <string>res;
    for (int i=0;i<s.size();i++){
        string str=s2(i);
        if (str.size()!=Kol)
            str = str + '0';
        res.push_back(s2(i));
    }

    vector <int> a;
    a.push_back(s[0]-'0');
    a.push_back((s[0]+s[1]-2*'0')%2);
    for (int i=2;i<s.size();i++){
        int res2=s[0]-'0';
        for (int j=1;j<i+1;j++){
            res2 = (res2 + (rec(i,j)%2)*(s[j]-'0'))%2;
        }
        a.push_back(res2);
    }


    bool f=false;
    for (int i=0;i<a.size();i++){
        if (a[i]==1){
            if (f)
                cout << "+";
            else f=true;
            for (int j=Kol-1;j>=0;j--){
                if (res[i][j]=='1'){
                    cout << "x(" << Kol-j << ")";
                }
            }
        }
    }
    return;
}


void Bench(){
    ofstream out("Benchmark19.txt");
    int te=2;
    clock_t start, end;

    start = clock();
    end = clock();
    srand(time(0));
    for (int i=1;i<5;i++){
        string s="";
        for (int i=0;i<te;i++){
            s=s+char(rand()%2+'0');
        }
        int Kol=1;
        int t=2;
        while (t < s.size() ){
            Kol ++;
            t*=2;
        }
        vector <string>res;
        for (int i=0;i<s.size();i++){
            string str=s2(i);
            if (str.size()!=Kol)
                str = str + '0';
            res.push_back(s2(i));
        }

        vector <int> a;
        a.push_back(s[0]-'0');
        a.push_back((s[0]+s[1]-2*'0')%2);
        for (int i=2;i<s.size();i++){
            int res2=s[0]-'0';
            for (int j=1;j<i+1;j++){
                res2 = (res2 + (rec(i,j)%2)*(s[j]-'0'))%2;
            }
            a.push_back(res2);
        }
        end = clock();
        out << "2^" << i << "  " << ((double) end - start) / ((double) CLOCKS_PER_SEC)  << "   " << sizeof(s)*s.size() << "\n";
        te*=2;
    }



}



int menu(){
    int key = 0;
    int code;
    do {
        system( "cls" );
        cout << "Choose:\n";
        key = ( key + 3 ) % 3;
        if ( key == 0 ) cout<<"-> Interactive"<<endl;
            else  cout<<"   Interactive"<<endl;
        if ( key == 1 ) cout<<"-> Demonstration"<<endl;
            else  cout<<"   Demonstration"<<endl;
        if ( key == 2 ) cout<<"-> Benchmark"<<endl;
            else  cout<<"   Benchmark"<<endl;

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

