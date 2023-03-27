#include <iostream>
#include <string.h>
#include <windows.h>
#include <iomanip>
using namespace std;


class Jucator{
private:
    char* numeJucator;
    int puncte;
    int incercari;
    char headX;
    char headY;
    char tailX;
    char tailY;
    char** corp;
public:
    Jucator();
    void afisareAvion();
    friend ostream& operator<<(ostream& out,const Jucator& obj);
    void setNumeJucator(char* numeJucator);
    void setPuncte(int puncte){this->puncte = puncte;}
    void setHeadX(char headX){this->headX = headX;}
    void setHeadY(char headY){this->headY = headY;}
    void setTailX(char tailX){this->tailX = tailX;}
    void setTailY(char tailY){this->tailY = tailY;}
    char getHeadX()const{return this->headX;}
    char getHeadY()const{return this->headY;}
    int getPuncte()const{return this->puncte;}
    int getIncercari()const{return this->incercari;}
    char** getCorp()const{return this->corp;}
    const char* getNumeJucator()const{return this->numeJucator;}
    void adaugaAvion();
    void puneX(char coordX,char coordY);
    Jucator& operator++();
    Jucator& operator--();
    ~Jucator();
};
Jucator& Jucator::operator--(){
    this->incercari = this->incercari - 1;
    return *this;
}
Jucator& Jucator::operator++(){
    this->puncte = this->puncte + 10;
    return *this;
}
void Jucator::afisareAvion(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0 ; i < 12 ; i++){
        for(int j = 0 ; j < 12 ; j++){
            if(this->corp[i][j] == 'X'){
                SetConsoleTextAttribute(hConsole, 12);
                cout<<this->corp[i][j]<<" ";
                SetConsoleTextAttribute(hConsole, 7);
            }
            else{
                cout<<this->corp[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
}
void Jucator::setNumeJucator(char* numeJucator){
    if(this->numeJucator != NULL){
        delete[] this->numeJucator;
        this->numeJucator = NULL;
    }
    this->numeJucator = new char[strlen(numeJucator)+1];
    strcpy(this->numeJucator,numeJucator);
}
ostream& operator<<(ostream& out,const Jucator& obj){
    out<<"Nume jucator: "<<obj.numeJucator<<endl;
    out<<"Puncte: "<<obj.puncte<<endl;
    out<<"Incercari ramase: ";
    for(int i = 0 ; i < obj.incercari ; i++)
        out<<'|';
    out<<endl<<endl;
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0 ; i < 12 ; i++){
        for(int j = 0 ; j < 12 ; j++){
            if(obj.corp[i][j] == 'X'){
                SetConsoleTextAttribute(hConsole, 12);
                out<<obj.corp[i][j]<<" ";
                SetConsoleTextAttribute(hConsole, 7);
            }
            else{
                out<<obj.corp[i][j]<<" ";
            }
        }
        out<<endl;
    }
    return out;
}
void Jucator::adaugaAvion(){
    int hX = int(headX) - 97;
    int hY = int(headY) - 48;
    int tX = int(tailX) - 97;
    int tY = int(tailY) - 48;

    if(hX == tX && hY < tY){
        for(int i = hY ; i <= tY ; i++)
            corp[hX][i] = 'O';
        corp[tX+1][tY] = 'O';
        corp[tX-1][tY] = 'O';
        for(int i = hX-2 ; i <= hX+2 ; i++)
            corp[i][hY+1] = 'O';
    }

    if(hX == tX && hY > tY){
        for(int i = hY; i >= tY ; i--)
            corp[hX][i] = 'O';
        corp[tX+1][tY] = 'O';
        corp[tX-1][tY] = 'O';
        for(int i = hX-2 ; i <= hX+2 ; i++)
            corp[i][hY-1] = 'O';
    }

    if(hY == tY && hX > tX){
        for(int i = hX ; i >= tX ; i--)
            corp[i][tY] = 'O';
        corp[tX][tY-1] = 'O';
        corp[tX][tY+1] = 'O';
        for(int i = hY-2 ; i <= hY+2 ; i++){
            corp[hX-1][i] = 'O';
        }
    }

    if(hY == tY && hX < tX){
        for(int i =  tX ; i >= hX ; i--)
            corp[i][hY]= 'O';
        corp[tX][tY-1]= 'O';
        corp[tX][tY+1]= 'O';
        for(int i = hY-2 ; i <= hY+2 ; i++)
            corp[hX+1][i] = 'O';
    }
}

void Jucator::puneX(char coordX,char coordY){
    this->corp[int(coordX) - 97][int(coordY)-48] = 'X';
}

Jucator::Jucator(){
    numeJucator = new char[strlen("Guest")+1];
    strcpy(numeJucator,"Guest");
    puncte = 0;
    incercari = 5;
    ///coord avion
    headX = 'a';
    headY = '0';
    tailX = 'a';
    tailY = '0';
    ///matricea
    corp = new char*[12];
    for(int i = 0 ; i < 12 ; i++)
        corp[i] = new char[12];

    for(int i = 0 ; i < 10 ; i++)
        for(int j = 0 ; j < 10 ; j++)
            corp[i][j] = ' ';
    for(int i = 0 ; i < 12 ; i++){
        corp[i][11] = char(97+i);
        corp[10][i] = '_';
        corp[i][10] = '|';
        corp[11][i] = char(48+i);
    }
    corp[11][11] = char(3);
}
Jucator::~Jucator(){
    ///distrus numele
     if(this->numeJucator != NULL){
        delete[] this->numeJucator;
        this->numeJucator = NULL;
    }
    ///distrus matricea
     if(this->corp != NULL){
        for(int i = 0 ; i < 12 ; i++)
            if(this->corp[i] != NULL){
                delete[] this->corp[i];
                this->corp[i] = NULL;
            }
        delete[] this->corp;
        this->corp = NULL;
        }
}

class Meniu{
private:
    Jucator j1,j2;
public:
    void start();
    void jocul();
    void turn(Jucator& obj1,Jucator& obj2);
    void hr();
};

void Meniu::start(){
    ///jucator1
    j1.afisareAvion();
    char numeAux[100];
    char x,y;
    cout<<"Player1 name:";
    cin>>numeAux;
    j1.setNumeJucator(numeAux);
    cout<<"Head coords: ";
    cin>>x>>y;
    j1.setHeadX(x);
    j1.setHeadY(y);
    cout<<"Tail coords: ";
    cin>>x>>y;
    j1.setTailX(x);
    j1.setTailY(y);
    system("CLS");
    j1.adaugaAvion();
    j1.afisareAvion();
    system("pause");

    ///jucator2
    system("CLS");
    j2.afisareAvion();
    cout<<"Player2 name:";
    cin>>numeAux;
    j2.setNumeJucator(numeAux);
    cout<<"Head coords: ";
    cin>>x>>y;
    j2.setHeadX(x);
    j2.setHeadY(y);
    cout<<"Tail coords: ";
    cin>>x>>y;
    j2.setTailX(x);
    j2.setTailY(y);
    system("CLS");
    j2.adaugaAvion();
    j2.afisareAvion();
    system("pause");
    system("CLS");
    jocul();
}
void Meniu::hr(){
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
}

void Meniu::turn(Jucator& obj1,Jucator& obj2){
    char coordX , coordY;
    cout<<setw(60)<<obj1.getNumeJucator()<<endl;hr();
    obj1.afisareAvion();
    hr();
    cout<<"Scor: "<<obj1.getPuncte()<<endl;
    cout<<"Incercari ramase:  ";
    for(int i = 0 ; i < obj1.getIncercari() ; i++)
        cout<<'|';
    cout<<endl;
    hr();
    cout<<"Loveste la ";
    cin>>coordX>>coordY;
    --obj1;
    if(obj1.getHeadX() == coordX && obj1.getHeadY() == coordY){
        system("CLS");
        cout<<obj1.getNumeJucator()<<" si-a dat singur in cap si a pierdut"<<endl;
        obj1.setPuncte(-1);
        return;
    }
    if(obj2.getHeadX() == coordX && obj2.getHeadY() == coordY){
        obj1.setPuncte(999);
        system("CLS");
    }
    else{
        if(obj2.getCorp()[int(coordX) - 97][int(coordY) - 48] == 'O')
            ++obj1;
    obj1.puneX(coordX,coordY);
    obj2.puneX(coordX,coordY);
    system("CLS");
    cout<<setw(60)<<obj1.getNumeJucator()<<endl;hr();
    obj1.afisareAvion();
    hr();
    cout<<"Scor: "<<obj1.getPuncte()<<endl;
    cout<<"Incercari ramase:  ";
    for(int i = 0 ; i < obj1.getIncercari() ; i++)
        cout<<'|';
    cout<<endl;
    system("pause");
    }
}

void Meniu::jocul(){
    while(j1.getPuncte()+j2.getPuncte() < 999 && j1.getIncercari()+j2.getIncercari() > 0){
        system("CLS");
        cout<<"Randul lui "<<j1.getNumeJucator()<<endl;
        system("pause");
        system("CLS");
        turn(j1,j2);
        if(j1.getPuncte() < 0)
            return;
        if(j1.getPuncte() == 999){
            cout<<j1.getNumeJucator()<<" wins"<<endl;
            break;
        }
        system("CLS");
        cout<<"Randul lui "<<j2.getNumeJucator()<<endl;
        system("pause");
        turn(j2,j1);
        system("CLS");
        if(j2.getPuncte() < 0)
            return;
        if(j2.getPuncte() == 999){
            cout<<j2.getNumeJucator()<<" wins"<<endl;
            break;
        }
    }
    if(j1.getIncercari()+j2.getIncercari() == 0 && j1.getPuncte()+j2.getPuncte() < 999 && j1.getPuncte() == j2.getPuncte()){
        cout<<"Remiza"<<endl;
        return;
    }
    if(j1.getIncercari()+j2.getIncercari() == 0 && j1.getPuncte()+j2.getPuncte() < 999){
        if(j1.getPuncte() > j2.getPuncte()){
            cout<<j1.getNumeJucator()<<" wins"<<endl;
            return;
        }
        if(j1.getPuncte() < j2.getPuncte()){
            cout<<j2.getNumeJucator()<<" wins"<<endl;
            return;
        }
        if(j1.getPuncte() == j2.getPuncte()){
           cout<<"Remiza";
           return;
        }
    }

}
int main()
{Meniu meniu;
meniu.start();

}
