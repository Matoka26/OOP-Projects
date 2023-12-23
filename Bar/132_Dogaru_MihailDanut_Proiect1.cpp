#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

class Pacanea{
private:
    string numePacanea;
    char car1;
    char car2;
    char car3;
    float mana;
public:
    Pacanea();
    Pacanea(string numePacanea,char car1,char car2,char car3,float mana);
    Pacanea(const Pacanea& obj);
    //operatori
    Pacanea& operator=(const Pacanea& obj);
    friend istream& operator>>(istream& in , Pacanea& obj);
    friend ostream& operator<<(ostream& out ,const Pacanea& obj);
    bool operator<(const Pacanea& obj);
    bool operator>(const Pacanea& obj);
    bool operator==(const Pacanea& obj);
    Pacanea operator+(Pacanea obj);
    Pacanea operator+(float mana);
    Pacanea operator-(Pacanea obj);
    Pacanea operator-(float mana);
    Pacanea& operator++();
    Pacanea operator++(int);
    Pacanea& operator--();
    Pacanea operator--(int);
    char operator[](int index);
    operator float();
    friend Pacanea operator+(int numar , Pacanea obj);
    //functii
    void daMana();
    bool castigator();

    //setter
    void setNumePacanea(string numePacanea){this->numePacanea = numePacanea;}
    void setCar1(char car1){this->car1 = car1;}
    void setCar2(char car2){this->car2 = car2;}
    void setCar3(char car3){this->car3 = car3;}
    void setMana(float mana){this->mana = mana;}
    //getteri
    string getNumePacanea()const{return this->numePacanea;}
    char getCar1()const{return this->car1;}
    char getCar2()const{return this->car2;}
    char getCar3()const{return this->car3;}
    float getMana()const{return this->mana;}
    //destructor
    ~Pacanea();
};
Pacanea::operator float(){
    return this->mana;
}
void Pacanea::daMana(){
    this->car1 = char(65+rand()%3);
    this->car2 = char(65+rand()%3);
    this->car3 = char(65+rand()%3);
}
bool Pacanea::castigator(){
    if(car1 == car2 && car2 == car3) return 1;
    return 0;
}
Pacanea::Pacanea(){
    numePacanea = "Nimic";
    car1 = '-';
    car2 = '-';
    car3 = '-';
    mana = 0;
}
Pacanea::Pacanea(string numePacanea,char car1,char car2,char car3,float mana){
    this->numePacanea = numePacanea;
    this->car1 = car1;
    this->car2 = car2;
    this->car3 = car3;
    this->mana = mana;

}
Pacanea::Pacanea(const Pacanea& obj){
    this->numePacanea = obj.numePacanea;
    this->car1 = obj.car1;
    this->car2 = obj.car2;
    this->car3 = obj.car3;
    this->mana = obj.mana;
}

Pacanea& Pacanea::operator=(const Pacanea& obj){
    this->numePacanea = obj.numePacanea;
    this->car1 = obj.car1;
    this->car2 = obj.car2;
    this->car3 = obj.car3;
    this->mana = obj.mana;
    return *this;
}
istream& operator>>(istream& in , Pacanea& obj){
    cout<<"Numele pacanelei, bossule"<<endl;
    in>>obj.numePacanea;
    cout<<"Ce linie ti-a dat?"<<endl;
    in>>obj.car1>>obj.car2>>obj.car3;
    cout<<"Cat costa mana?"<<endl;
    in>>obj.mana;
    return in;
}
ostream& operator<<(ostream& out ,const Pacanea& obj){
    out<<"Numele pacanelei: "<<obj.numePacanea<<endl;
    out<<"Ti-a picat: "<<obj.car1<<"-"<<obj.car2<<"-"<<obj.car3<<endl;
    out<<"Mana costa: "<<obj.mana<<endl;
    return out;
}
bool Pacanea::operator==(const Pacanea& obj){
    if(this->mana == obj.mana) return 1;
    return 0;
}
bool Pacanea::operator<(const Pacanea& obj){
    if(this->mana < obj.mana) return 1;
    return 0;
}
bool Pacanea::operator>(const Pacanea& obj){
    if(this->mana > obj.mana) return 1;
    return 0;
}
Pacanea Pacanea::operator+(Pacanea obj){
    obj.mana = obj.mana + this->mana;
    return obj;
}
Pacanea Pacanea::operator+(float mana){
    Pacanea copie(*this);
    copie.mana = copie.mana + mana;
    return copie;
}
Pacanea Pacanea::operator-(Pacanea obj){
    obj.mana = obj.mana - this->mana;
    return obj;
}
Pacanea Pacanea::operator-(float mana){
    Pacanea copie(*this);
    copie.mana = copie.mana - mana;
    return copie;
}
Pacanea& Pacanea::operator++(){
    this->mana = this->mana +0.2;
    return *this;
}
Pacanea Pacanea::operator++(int){
    Pacanea copie(*this);
    this->mana = this-> mana +0.2;
    return copie;
}
Pacanea& Pacanea::operator--(){
    if(this->mana > 0.4)
        this->mana = this->mana - 0.2;
    else
        this->mana = 0.2;

    return *this;
}
Pacanea Pacanea::operator--(int){
    Pacanea copie(*this);
    if(this->mana >0.4)
        this->mana = this->mana-0.2;
    else
        this->mana = 0.2;
    return copie;
}
char Pacanea::operator[](int index){
    if(index < 0) return '/';// throw runtime_error("invalid index");
    if(index > this->numePacanea.size()-1) return '/';// throw runtime_error("index invalid");
    return this->numePacanea[index];
}
Pacanea operator+(int numar , Pacanea obj){
    obj.mana = obj.mana +numar;
    return obj;
}
Pacanea::~Pacanea(){
    this->numePacanea = "Nimic";
    this->car1 = '-';
    this->car2 = '-';
    this->car3 = '-';
    this->mana = 0;
    }

class Client{
private:
    static int contorId;
    const int clientId;
    char* numeClient;
    float balanta;
    float alcoolemie;

public:
    Client();
    Client(char* numeClient,float balanta,float alcoolemie);
    Client(const Client& obj);
        //operatori
    Client& operator=(const Client& obj);
    friend ostream& operator<<(ostream& out ,const Client& obj);
    friend istream& operator>>(istream& in ,Client& obj);
    bool operator>(const Client& obj);
    bool operator<(const Client& obj);
    bool operator==(const Client& obj);
    Client operator+(Client obj);
    Client operator+(float balanta);
    Client operator-(Client obj);
    Client operator-(float balanta);
    Client& operator++();
    Client operator++(int);
    Client& operator--();
    Client operator--(int);
    char operator[](int index);
    Client operator+(const Pacanea& obj);
    friend Client operator+(int numar,Client obj);
    operator int();
        //functii
    int varsta();
        //getteri
    const char* getNumeClient()const{return numeClient;}
    int getClientId()const{return clientId;}
    float getBalanta()const{return balanta;}
    float getAlcoolemie()const{return alcoolemie;}
        //setteri
    void setNumeClient(char* numeClient);
    void setBalanta(float balanta){this->balanta = balanta;}
    void setAlcoolemie(float alcoolemie){this->alcoolemie = alcoolemie;}
        //destructor
    ~Client();
};
Client::operator int(){
    return this->clientId;
}
Client Client::operator+(const Pacanea& obj){
    Client copie(*this);
    copie.balanta = copie.balanta + 10*obj.getMana();
    return copie;
}
int Client::varsta(){
    return (7+(this->clientId + (int)&clientId)%79);
}
void Client::setNumeClient(char* numeClient){//setter
    if(this->numeClient != NULL){
        delete[] this->numeClient;
        this->numeClient = NULL;
    }
    this->numeClient = new char[strlen(numeClient)+1];
    strcpy(this->numeClient , numeClient);
}
int Client::contorId = 123;
Client::Client():clientId(contorId++){
    numeClient = new char[strlen("Anonim")+1];
    strcpy(numeClient,"Anonim");
    balanta = 0;
    alcoolemie = 0.0;
}
Client::Client(char* numeClient,float balanta,float alcoolemie):clientId(contorId++){
    this->numeClient = new char[strlen(numeClient)+1];
    strcpy(this->numeClient,numeClient);
    this->balanta = balanta;
    this->alcoolemie = alcoolemie;
}
Client::Client(const Client& obj):clientId(obj.clientId){
    this->numeClient = new char[strlen(obj.numeClient)+1];
    strcpy(this->numeClient,obj.numeClient);
    this->balanta = obj.balanta;
    this->alcoolemie = obj.alcoolemie;
}
//operatori
Client& Client::operator=(const Client& obj){
    if(this != &obj){
        if(this->numeClient != NULL){
            delete[] this->numeClient;
            this->numeClient = NULL;
        }
        this->numeClient = new char[strlen(obj.numeClient)+1];
        strcpy(this->numeClient,obj.numeClient);
        this->balanta = obj.balanta;
        this->alcoolemie = obj.alcoolemie;
    }
    return *this;
}
ostream& operator<<(ostream& out,const Client& obj){
    out<<"Nume Client: "<<obj.numeClient<<endl;
    out<<"ID Client: "<<obj.clientId<<endl;
    out<<"Balanta: "<<obj.balanta<<endl;
    out<<"Alcoolemie: "<<obj.alcoolemie<<endl;
    return out;
}
istream& operator>>(istream& in,Client& obj){
    char numeClient[100];
    if(obj.numeClient != NULL){
        delete[] obj.numeClient;
        obj.numeClient = NULL;
    }
    cout<<"Cum il cheama pe client?"<<endl;
    in>>numeClient;
    obj.numeClient = new char[strlen(numeClient)+1];
    strcpy(obj.numeClient,numeClient);
    cout<<"Cati bani are la el?"<<endl;
    in>>obj.balanta;
    cout<<"Ce alcoolemie are la intrare?"<<endl;
    in>>obj.alcoolemie;
    return in;
}
bool Client::operator>(const Client& obj){
    if(this->alcoolemie > obj.alcoolemie) return 1;
    return 0;
}
bool Client::operator<(const Client& obj){
    if(this->alcoolemie < obj.alcoolemie) return 1;
    return 0;
}
bool Client::operator==(const Client& obj){
    if(this->alcoolemie == obj.alcoolemie) return 1;
    return 0;
}
Client Client::operator+(Client obj){
    obj.balanta = obj.balanta + this->balanta;
    return obj;
}
Client Client::operator+(float balanta){
    Client copie(*this);
    copie.balanta = copie.balanta + balanta;
    return copie;
}
Client Client::operator-(Client obj){
    obj.balanta = obj.balanta - this->balanta;
    return obj;
}
Client Client::operator-(float balanta){
    Client copie(*this);
    copie.balanta = copie.balanta - balanta;
    return copie;
}
Client& Client::operator++(){
    this->alcoolemie = this->alcoolemie +1;
    return *this;
}
Client Client::operator++(int){
    Client copie(*this);
    this->alcoolemie = this->alcoolemie +1;
    return copie;
}
Client& Client::operator--(){
    this->alcoolemie = this->alcoolemie -1;
    return *this;
}
Client Client::operator--(int){
    Client copie(*this);
    this->alcoolemie = this->alcoolemie -1;
    return copie;
}
char Client::operator[](int index){
    if(index < 0) return '/'; //throw runtime_error("index invalid");
    if(index > strlen(this->numeClient)-1) return '/'; //throw runtime_error("invalid index");
    return this->numeClient[index];

}
Client operator+(int numar,Client obj){
    obj.balanta = obj.balanta + numar;
    return obj;
}
Client::~Client(){
    if(this->numeClient != NULL){
        delete[] this->numeClient;
        this->numeClient = NULL;
    }
    this->alcoolemie = 0;
    this->balanta = 0;
}


class Bar{
private:
    float venitulSerii;
    int locuri;
    int locuriOcupate;
    bool incidente;
public:
    Bar();
    Bar(float venitulSeri,int locuri,int locuriOcupate,bool incidente);
    Bar(const Bar& obj);
    Bar& operator=(const Bar& obj);
    friend ostream& operator<<(ostream& out,const Bar& obj);
    friend istream& operator>>(istream& in , Bar& obj);
    bool operator<(const Bar& obj);
    bool operator>(const Bar& obj);
    bool operator==(const Bar& obj);
    Bar operator+(Bar obj);
    Bar operator+(int locuri);
    Bar operator-(Bar obj);
    Bar operator-(int locuri);
    Bar& operator++();
    Bar operator++(int);
    Bar& operator--();
    Bar operator--(int);
    friend Bar operator+(int numar , Bar obj);
    operator float();
    //functie
    int locuriLibere();
    //getters
    float getVenitulSerii()const{return venitulSerii;}
    int getLocuri()const{return locuri;}
    int getLocuriOcupate()const{return locuriOcupate;}
    bool getincidente()const{return incidente;}
    //setters
    void setVenitulSerii(int venitulSerii){this->venitulSerii = venitulSerii;}
    void setLocuri(int locuri){this->locuri = locuri;}
    void setLocuriOcupate(int locuriOcupate){this->locuriOcupate = locuriOcupate;}
    void setIncidente(bool incidente){this->incidente = incidente;}
    //destructor
    ~Bar();
};
Bar::operator float(){
    return this->venitulSerii;
}
int Bar::locuriLibere(){
    return (this->locuri-this->locuriOcupate);
}
Bar::Bar(){//constructor de initializare
    venitulSerii = 0;
    locuri = 0;
    locuriOcupate = 0;
    incidente = 0;
}
Bar::Bar(float venitulSerii,int locuri,int locuriOcupate,bool incidente){
    this->venitulSerii = venitulSerii;
    this->locuri = locuri;
    this->locuriOcupate = locuriOcupate;
    this->incidente = incidente;
}
Bar::Bar(const Bar& obj){
    this->venitulSerii = obj.venitulSerii;
    this->locuri = obj.locuri;
    this->locuriOcupate = obj.locuriOcupate;
    this->incidente = obj.incidente;
}

Bar& Bar::operator=(const Bar& obj){
    this->venitulSerii = obj.venitulSerii;
    this->locuri = obj.locuri;
    this->locuriOcupate = obj.locuriOcupate;
    this->incidente = obj.incidente;
    return *this;
}
ostream& operator<<(ostream& out,const Bar& obj){
    out<<"Venitul din seara asta este: "<<obj.venitulSerii<<endl;
    out<<"Numarul de locuri din bar: "<<obj.locuri<<endl;
    out<<"Numarul de locuri ocupate din bar: "<<obj.locuriOcupate<<endl;
    out<<"Incidente in seara asta:";
    if(obj.incidente) out<<"da"<<endl;
    else  out<<"nu"<<endl;
    return out;
}
istream& operator>>(istream& in, Bar& obj){
    cout<<"Cati bani s-au facut pana acum?"<<endl;
    in>>obj.venitulSerii;
    cout<<"Cate locuri are barul?"<<endl;
    in>>obj.locuri;
    cout<<"Cate locuri sunt ocupate in bar?"<<endl;
    in>>obj.locuriOcupate;
    cout<<"Au fost incidente in seara asta?(0 sau 1)"<<endl;
    in>>obj.incidente;
    return in;
}
bool Bar::operator<(const Bar& obj){
    if(this->locuri < obj.locuri) return 1;
    return 0;
}
bool Bar::operator>(const Bar& obj){
    if(this->locuri > obj.locuri) return 1;
    return 0;
}
bool Bar::operator==(const Bar& obj){
    if(this->locuri == obj.locuri) return 1;
    return 0;
}
Bar Bar::operator+(Bar obj){
    obj.venitulSerii = obj.venitulSerii + this->venitulSerii;
    obj.locuri = obj.locuri + this->locuri;
    obj.locuriOcupate = obj.locuriOcupate + this->locuriOcupate;
    return obj;
}
Bar Bar::operator+(int locuriOcupate){
    Bar copie(*this);
    copie.locuriOcupate = copie.locuriOcupate + locuriOcupate;
    return copie;
}
Bar Bar::operator-(Bar obj){
    obj.venitulSerii = obj.venitulSerii - this->venitulSerii;
    obj.locuri = obj.locuri - this->locuri;
    obj.locuriOcupate = obj.locuriOcupate - this->locuriOcupate;
    return obj;
}
Bar Bar::operator-(int locuriOcupate){
    Bar copie(*this);
    copie.locuriOcupate = copie.locuriOcupate - locuriOcupate;
    return copie;
}
Bar& Bar::operator++(){
    this->locuri = this->locuri + 1;
    return *this;
}
Bar Bar::operator++(int){
    Bar copie(*this);
    this->locuri = this->locuri + 1;
    return copie;
}
Bar& Bar::operator--(){
    this->locuri = this->locuri - 1;
    return *this;
}
Bar Bar::operator--(int){
    Bar copie(*this);
    this->locuri = this->locuri -1;
    return copie;
}
Bar operator+(int numar, Bar obj){
    obj.locuri = obj.locuri + numar;
    return obj;
}
Bar::~Bar(){
    this->venitulSerii = 0;
    this->locuri = 0;
    this->locuriOcupate = 0;
    this->incidente = 0;
}

class Bauturi{
private:
    char* numeBautura;
    int pret;
    double procentAlcool;
    int nrVolume;
    float* volume;
public:
    Bauturi();
    Bauturi(char* numeBautura,int pret,double procentAlcool,int nrVolume,float* volume);
    Bauturi(const Bauturi& obj);
    Bauturi& operator=(const Bauturi& obj);
    friend ostream& operator<<(ostream& out,const Bauturi& obj);
    friend istream& operator>>(istream& in,Bauturi& obj);
    bool operator<(const Bauturi& obj);
    bool operator>(const Bauturi& obj);
    bool operator==(const Bauturi& obj);
    Bauturi operator+(Bauturi obj);
    Bauturi operator+(int pret);
    Bauturi operator-(Bauturi obj);
    Bauturi operator-(int pret);
    Bauturi& operator++();
    Bauturi operator++(int);
    Bauturi& operator--();
    Bauturi operator--(int);
    float operator[](int index);
    friend Bauturi operator+(int numar , Bauturi obj);
    operator int();
    //functie
    bool contineAlcool();
    //getters
    const char* getNumeBautura()const{return numeBautura;}
    int getPret()const{return pret;}
    double getProcentAlcool()const{return procentAlcool;}
    int getNrVolume()const{return nrVolume;}
    const float* getVolume()const{return this->volume;}
    //setters
    void setNumeBautura(char* numeBautura);
    void setPret(int pret){this->pret = pret;}
    void setProcentAlcool(double procentAlcool){this->procentAlcool = procentAlcool;}
    void setNrVolume(int nrVolume){this->nrVolume = nrVolume;}
    void setVolume(float* volume);

    ~Bauturi();
};
Bauturi::operator int(){
    return this->nrVolume;
}
bool Bauturi::contineAlcool(){
    if(procentAlcool > 0) return 1;
    return 0;
}
void Bauturi::setVolume(float* volume){
    if(this->volume != NULL){
        delete[] this->volume;
        this->volume = NULL;
    }
    this->volume = new float[this->nrVolume];
    for(int i = 0 ; i < this->nrVolume ; i++)
        this->volume[i] = volume[i];

}
void Bauturi::setNumeBautura(char* numeBautura){//setter
    if(this->numeBautura != NULL){
        delete[] this->numeBautura;
        this->numeBautura = NULL;
    }
    this->numeBautura = new char[strlen(numeBautura)+1];
    strcpy(this->numeBautura , numeBautura);
}
Bauturi::Bauturi(){
    numeBautura = new char[strlen("Nimic")+1];
    strcpy(numeBautura,"Nimic");
    pret = 0;
    procentAlcool = 0;
    nrVolume = 0;
    volume = NULL;
}
Bauturi::Bauturi(char* numeBautura, int pret, double procentAlcool,int nrVolume,float* volume){
    this->numeBautura = new char[strlen(numeBautura)+1];
    strcpy(this->numeBautura,numeBautura);
    this->pret = pret;
    this->procentAlcool = procentAlcool;
    this->nrVolume = nrVolume;
    this->volume = new float[nrVolume];
    for(int i = 0 ; i < nrVolume ; i++)
        this->volume[i] = volume[i];
}
Bauturi::Bauturi(const Bauturi& obj){
    this->numeBautura = new char[strlen(obj.numeBautura)+1];
    strcpy(this->numeBautura,obj.numeBautura);
    this->volume = new float[obj.nrVolume];
    this->pret = obj.pret;
    this->procentAlcool = obj.procentAlcool;
    this->nrVolume = obj.nrVolume;
    for(int i = 0; i< obj.nrVolume; i++){
        this->volume[i] = obj.volume[i];
    }
}

Bauturi& Bauturi::operator=(const Bauturi& obj){
    if(this->numeBautura != NULL){
        delete[] this->numeBautura;
        this->numeBautura = NULL;
    }
    this->numeBautura = new char[strlen(obj.numeBautura)+1];
    strcpy(this->numeBautura,obj.numeBautura);
    this->pret = obj.pret;
    this->procentAlcool = obj.procentAlcool;
    this->nrVolume = obj.nrVolume;
    if(this->volume != NULL){
        delete[] this->volume;
        this->volume = NULL;
    }
    this->volume = new float[obj.nrVolume];
    for(int i = 0; i< obj.nrVolume; i++){
        this->volume[i] = obj.volume[i];
    }
    return *this;
}
ostream& operator<<(ostream& out,const Bauturi& obj){
    out<<"Numele bauturii: "<<obj.numeBautura<<endl;
    out<<"Pretul pe litru este de: "<<obj.pret<<endl;
    out<<"Procentaj Alcool: "<<obj.procentAlcool<<endl;
    if(obj.nrVolume == 1) out<<"La o singura dimensiune"<<endl;
        else
            out<<"La "<<obj.nrVolume<<" dimensiuni"<<endl;
    if(obj.nrVolume != 0){
        out<<"La sticle de: ";
        for(int i = 0; i < obj.nrVolume; i++)
            out<<obj.volume[i]<<"L ";
    }
    out<<endl;
    return out;
}
istream& operator>>(istream& in,Bauturi& obj){
    char numeBautura[100];
    cout<<"Cum sa se numeasca bautura?"<<endl;
    in>>numeBautura;
    if(obj.numeBautura != NULL){
        delete[] obj.numeBautura;
        obj.numeBautura = NULL;
    }
    obj.numeBautura = new char[strlen(numeBautura)+1];
    strcpy(obj.numeBautura,numeBautura);
    cout<<"Cat sa coste? "<<endl;
    in>>obj.pret;
    cout<<"Cat alcool ar avea? "<<endl;
    in>>obj.procentAlcool;
    cout<<"La ce volume sa fie? "<<endl;
    in>>obj.nrVolume;
    if(obj.volume != NULL){
        delete[] obj.volume;
        obj.volume = NULL;
    }
    obj.volume = new float[obj.nrVolume];
    for(int i = 0; i < obj.nrVolume; i++){
        cout<<"Care e dimensiunea "<<i+1<<"?"<<endl;
        in>>obj.volume[i];
    }
    return in;
}
bool Bauturi::operator<(const Bauturi& obj){
    if(this->pret < obj.pret) return 1;
    return 0;
}
bool Bauturi::operator>(const Bauturi& obj){
    if(this->pret > obj.pret) return 1;
    return 0;
}
bool Bauturi::operator==(const Bauturi& obj){
    if(this->pret == obj.pret && this->procentAlcool == obj.procentAlcool) return 1;
    return 0;
}
Bauturi Bauturi::operator+(Bauturi obj){
    obj.pret = obj.pret + this->pret;
    return obj;
}
Bauturi Bauturi::operator+(int pret){
    Bauturi copie(*this);
    copie.pret = copie.pret + pret;
    return copie;
}
Bauturi Bauturi::operator-(Bauturi obj){
    obj.pret = obj.pret - this->pret;
    return obj;
}
Bauturi Bauturi::operator-(int pret){
    Bauturi copie(*this);
    copie.pret = copie.pret - pret;
    return copie;
}
Bauturi& Bauturi::operator++(){
    this->pret = this->pret +1;
    return *this;
}
Bauturi Bauturi::operator++(int){
    Bauturi copie(*this);
    this->pret = this->pret +1;
    return copie;
}
Bauturi& Bauturi::operator--(){
    this->pret = this->pret -1;
    return *this;
}
Bauturi Bauturi::operator--(int){
    Bauturi copie(*this);
    this->pret = this->pret -1;
    return copie;
}
float Bauturi::operator[](int index){
    if(index < 0) return -1; //throw runtime_error("invalid index");
    if(index >= this->nrVolume) return -1;// throw runtime_error("invalid index");
    return this->volume[index];
}
Bauturi operator+(int numar, Bauturi obj){
    obj.pret = obj.pret + numar;
    return obj;
}

Bauturi::~Bauturi(){
    if(this->numeBautura != NULL){
        delete[] this->numeBautura;
        this->numeBautura = NULL;
    }
    if(this->volume != NULL){
        delete[] this->volume;
        this->volume = NULL;
    }
    this->pret = 0;
    this-> procentAlcool = 0;
    this-> nrVolume = 0;
}




class Meniu{
private:
    Bauturi b1,b2,b3,b4;
    vector<Client*>listaClienti;
    vector<Bauturi*>listaBauturi;
    Pacanea aparat;
    Bar bar;
public:
   // Meniu();
    void configurareBar();//setter bar
    void configPacanea(); //setter aparat
    void jocPacanea(Client& obj);
    bool dublaj(int guess);
    void setBautura(Bauturi& obj,char* numeBautura,int pret,double procentAlcool,int nrVolume,float*);
    void start();
    void header();
    void jocCastig(Client& obj);
    void adaugareClient();
    void ceVreiSaBei(Client& obj);
    void setareListaBauturiInitiala();
    void servire(Client& obj);
    void afisareMeniu(Client& obj);
    void hr();
    void beaCeva(Client& objClient , Bauturi& objBautura ,int volumAles,Bar& objBar);
    Bar getBar(){return this->bar;}
    //~Meniu();
};
//Meniu::Meniu(){}
bool Meniu::dublaj(int guess){
    int nrRandom;
    nrRandom = (rand()+(int)&guess)%3;
    if(nrRandom < 2 ) return 0;
    return 1;
}

void Meniu::beaCeva(Client& objClient , Bauturi& objBautura ,int volumAles,Bar& objBar){
    objClient.setBalanta(objClient.getBalanta() - objBautura[volumAles-1]*objBautura.getPret());
    objClient.setAlcoolemie(objClient.getAlcoolemie() + objBautura[volumAles-1]*objBautura.getProcentAlcool());
    objBar.setVenitulSerii(objBar.getVenitulSerii() + objBautura[volumAles-1]*objBautura.getPret());
}
void Meniu::ceVreiSaBei(Client& obj){
    int bauturaAleasa;
    header();
    cout<<"BALANTA: "<<obj.getBalanta()<<"    "<<"ALCOOLEMIE: "<<obj.getAlcoolemie()<<endl;
    hr();
    for(int i = 0 ; i < this->listaBauturi.size() ; i++)
        cout<<i+1<<"."<<(*this->listaBauturi[i]).getNumeBautura()<<endl;
    hr();
    cout<<"Ce vrei sa bei, "<<obj.getNumeClient()<<"?"<<endl;
    cin>>bauturaAleasa;
    hr();
    cout<<"La cat?"<<endl<<endl;
    int volumAles;
    for(int i = 0 ; i < (*this->listaBauturi[bauturaAleasa-1]).getNrVolume() ; i++){
        cout<<i+1<<". "<<(*this->listaBauturi[bauturaAleasa-1]).getVolume()[i]<<"L ->";
        cout<<(*this->listaBauturi[bauturaAleasa-1]).getVolume()[i] * (*this->listaBauturi[bauturaAleasa-1]).getPret()<<"RON , ";
        cout<<(*this->listaBauturi[bauturaAleasa-1]).getVolume()[i] * (*this->listaBauturi[bauturaAleasa-1]).getProcentAlcool()<<" +alcoolemie"<<endl;
    }
    cout<<endl;
    cout<<(*this->listaBauturi[bauturaAleasa-1]).getNrVolume()+1<<". Sau poti sa te intorci la meniu"<<endl;
    cout<<endl;
    cin>>volumAles;
    if(volumAles == (*this->listaBauturi[bauturaAleasa-1]).getNrVolume()+1) afisareMeniu(obj);
    header();
    if(obj.getBalanta() < (*this->listaBauturi[bauturaAleasa-1]).getVolume()[volumAles-1] * (*this->listaBauturi[bauturaAleasa-1]).getPret()){//daca comanzi ceva mai scump decat iti permiti
        cout<<"Nu ai destui bani pentru asta,incearca altceva"<<endl;
        system("pause");
        ceVreiSaBei(obj);
    }
    else{
        beaCeva(obj,*this->listaBauturi[bauturaAleasa-1],volumAles,this->bar);
        if(obj.getAlcoolemie() > 100){
            header();
            cout<<"Ati baut cam mult, ma tem ca va trebui sa parasiti localul, "<<obj.getNumeClient()<<endl<<endl;
            cout<<"1. OK :("<<endl;
            cout<<"2. Refuz"<<endl;
            int checkDatAfara;
            cin>>checkDatAfara;
            if(checkDatAfara == 2){
                cout<<"*** "<<obj.getNumeClient()<<" a fost dat afara pe brate de BGS ***"<<endl;
                this->bar.setIncidente(1);
                system("pause");
                return;
            }
            return;
        }
        header();
        cout<<"Te mai putem servi cu ceva?"<<endl<<endl;
        cout<<"1. Mai vreau sa vad meniul"<<endl;
        cout<<"2. Mai vreau sa beau ceva"<<endl;
        cout<<"3. Vreau la pacanea"<<endl;
        cout<<"4. Plec"<<endl;
    int x;
    cin>>x;
    switch(x){
        case(1):{
            afisareMeniu(obj);
            break;
        }
        case(2):{
            ceVreiSaBei(obj);
            break;
        }
        case(3):{
            configPacanea();
            jocPacanea(obj);
            break;
        }
        case(4):{
            header();
            cout<<"Pa "<<obj.getNumeClient()<<"!"<<endl;
            system("pause");
            break;
        }
    }
    }
}

void Meniu::configPacanea(){
    header();
    cout<<"La ce joc vrei sa bagi?"<<endl;
    string numeJoc;
    cin>>numeJoc;
    this->aparat.setNumePacanea(numeJoc);
    float bet;
    cout<<"Pe ce bet?"<<endl;
    cin>>bet;
    this->aparat.setMana(bet);
}
void Meniu::jocCastig(Client& obj){
    header();
    HANDLE  hConsole;
    int k;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<setw(50)<<"~~~ "<<this->aparat.getNumePacanea()<<" ~~~"<<endl<<endl<<endl;
    cout<<setw(50)<<this->aparat.getCar1()<<" - "<<this->aparat.getCar2()<<" - "<<this->aparat.getCar3()<<endl<<endl;
    cout<<"BET: "<<this->aparat.getMana()*10<<" Credits"<<endl;
    cout<<"BALANTA: "<<obj.getBalanta()*10<<" Credits"<<endl;
                int castigPotential = this->aparat.getMana()*10;
                int gamble = 0;
                do{
                    k = 10;
                    SetConsoleTextAttribute(hConsole, k);
                    hr();
                    cout<<setw(63)<<"!!!CASTIGATOR!!!"<<setw(45)<<"CASTIG: "<<castigPotential*10<<"CREDITS"<<endl;
                    hr();
                    cout<<"GAMBLE?"<<endl<<endl;
                    cout<<"1. DA!!!"<<endl;
                    cout<<"2. mnu, incasare"<<endl;
                    cin>>gamble;
                    if(gamble == 1){
                        hr();
                        k = 12;
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<setw(70)<<"(1)ROSIE || (2)NEAGRA"<<endl;
                        k = 7;
                        SetConsoleTextAttribute(hConsole,k);
                        cin>>gamble;
                        if(dublaj(gamble))
                            castigPotential = castigPotential*2;
                        else
                            break;
                    }
                    else{
                        k = 7;
                        SetConsoleTextAttribute(hConsole, k);
                        obj= obj +castigPotential;
                        jocPacanea(obj);
                    }
                }while(gamble == 1);

}
void Meniu::jocPacanea(Client& obj){
    header();
    cout<<setw(50)<<"~~~ "<<this->aparat.getNumePacanea()<<" ~~~"<<endl<<endl<<endl;
    cout<<setw(50)<<this->aparat.getCar1()<<" - "<<this->aparat.getCar2()<<" - "<<this->aparat.getCar3()<<endl<<endl;
    cout<<"BET: "<<this->aparat.getMana()*10<<" Credits"<<endl;
    cout<<"BALANTA: "<<obj.getBalanta()*10<<" Credits"<<endl;
    hr();
    cout<<"1.Da o mana"<<setw(53)<<"2.++BET"<<setw(55)<<"3.--BET"<<endl;
    hr();
    cout<<endl<<endl<<"4.Ceva de baut?"<<endl;
    cout<<"5.Inapoi la meniu"<<endl<<endl;

    int optiunePacanea;
    cin>>optiunePacanea;
    switch(optiunePacanea){
        case(1):{
            if(obj.getBalanta() >= this->aparat.getMana()){
                this->aparat.daMana();
                obj.setBalanta(obj.getBalanta() - this->aparat.getMana());
                if(this->aparat.castigator())
                    jocCastig(obj);
            }
            else{
                cout<<"Fonduri insuficiente"<<endl;
                system("pause");
                jocPacanea(obj);
                break;
                }
            jocPacanea(obj);
            break;
        }
        case(2):{
            ++this->aparat;
            jocPacanea(obj);
            break;
        }
        case(3):{
            --this->aparat;
            jocPacanea(obj);
            break;
        }
        case(4):{
            afisareMeniu(obj);
            break;
        }
        case(5):{
            servire(obj);
            break;
        }

    }

}
void Meniu::start(){
    configurareBar();
    header();
    setareListaBauturiInitiala();
    if(this->bar.locuriLibere() <= 0 ){cout<<"Barul este plin din pacate :("<<endl<<"Va asteptam in alta zi"<<endl<<endl; return;}
    int nrClienti;
    cout<<"Bine ati venit!"<<endl;
    cout<<"In numar de cati sunteti?"<<endl;
    cin>>nrClienti;
    header();
    if(nrClienti > this->bar.locuriLibere()){
        cout<<endl<<"Din pacate nu avem suficiente locuri,va trebui ca "<<nrClienti-this->bar.locuriLibere()<<" sa plece :/"<<endl<<endl<<endl;
        system("pause");
        nrClienti =this-> bar.locuriLibere();
    }
    for(int i = 0 ; i < nrClienti ; i++){
        adaugareClient();
        if((*this->listaClienti[i]).varsta() < 18){
            cout<<"Din pacate "<<(*this->listaClienti[i]).getNumeClient()<<" nu are 18 ani,il rugam sa plece"<<endl;
            system("pause");
            this->listaClienti.pop_back();
        }
        else if((*this->listaClienti[i]).getAlcoolemie() >= 100){
            cout<<"Ai baut cam mult inainte. Din pacate va trebui sa pleci"<<endl;
            system("pause");
            //header();
            this->listaClienti.pop_back();
        }
        else
            this->bar.setLocuriOcupate(this->bar.getLocuriOcupate() + 1);
    }
    for(int i = 0 ; i < this->listaClienti.size() ; i++)
        servire(*this->listaClienti[i]);
    header();
    cout<<"Barul a facut in seara asta "<<this->bar.getVenitulSerii()<<"RON"<<endl;
    if(this->bar.getincidente()) cout<<"Din pacate au fost iesiri violente ale clientilor, iar paza a intervenit"<<endl;
        else cout<<"A fost o seara linistita"<<endl;
}

void Meniu::servire(Client& obj){
    header();
    cout<<"Ce doresti, "<<obj.getNumeClient()<<"?"<<endl;
    cout<<"1.Sa vad meniul"<<endl;
    cout<<"2.Merg la pacaneaua din colt"<<endl;
    cout<<"3.Sa plec"<<endl<<endl;
    int x;
    cin>>x;
    switch(x){
        case(1):{
            afisareMeniu(obj);
            break;
        }
        case(2):{
            configPacanea();
            jocPacanea(obj);
            break;
        }
        case(3):{
            header();
            cout<<"Pa "<<obj.getNumeClient()<<"!"<<endl;
            system("pause");
            break;
        }
    }

}

void Meniu::afisareMeniu(Client& obj){
    header();
    for(int i = 0 ; i < this->listaBauturi.size() ; i++)
        cout<<*this->listaBauturi[i]<<endl;
    int x;
    hr();
    cout<<"BALANTA: "<<obj.getBalanta()<<"    "<<"ALCOOLEMIE: "<<obj.getAlcoolemie()<<endl;
    hr();
    cout<<"1.As vrea sa ma intorc la optiuni"<<endl;
    cout<<"2.Doresc sa comand"<<endl;
    cout<<"3.As vrea sa sterg ceva din meniu"<<endl;
    cout<<"4.In meniu ar merge adaugat ceva"<<endl<<endl;
    cin>>x;
    switch(x){
        case(1):{
            servire(obj);
            break;
            }
        case(2):{
            if(listaBauturi.size() < 1 ){
                cout<<"Din pacate nu mai avem alte bauturi"<<endl;
                system("pause");
                afisareMeniu(obj);
                    break;
                    }
            ceVreiSaBei(obj);
            break;
            }
        case(3):{
                if(listaBauturi.size() < 1 ){
                    cout<<"Din pacate nu mai avem alte bauturi"<<endl;
                    system("pause");
                    afisareMeniu(obj);
                    break;
                    }
                int bauturaEliminata;
                header();
                cout<<"Ce ai vrea sa stergi?"<<endl<<endl;
                for(int i = 0 ; i < this->listaBauturi.size() ; i++)
                    cout<<i+1<<"."<<(*this->listaBauturi[i]).getNumeBautura()<<endl;
                cin>>bauturaEliminata;
                header();
                vector<Bauturi*>::iterator ptr;
                ptr = this->listaBauturi.begin()+bauturaEliminata-1;
                this->listaBauturi.erase(ptr);
                afisareMeniu(obj);
                break;
            }
        case(4):{
                header();
                Bauturi auxBautura;
                cin>>auxBautura;
                this->listaBauturi.push_back(new Bauturi());
                *this->listaBauturi.back() = auxBautura;
                header();
                cout<<"Multumim de sugestie! :)"<<endl;
                system("pause");
                header();
                cout<<"1.Reveniti la meniu"<<endl<<"2.Plecati"<<endl;
                int z;
                cin>>z;
                if(z == 1) afisareMeniu(obj);
                break;
            }
        }

}
void Meniu::setareListaBauturiInitiala(){
    float f[] = {0.5,1,2};
    float g[] = {0.5,2};
    float h[] = {0.5,2,2.5};
    float l[] = {0.2};
    Bauturi b1("cola",10,0,3,f),b2("vin",15,12,2,g),b3("bere",10,4.5,3,h),b4("tuica",13,80,1,l);
    this->listaBauturi.push_back(new Bauturi());
    *this->listaBauturi.back() = b1;
    this->listaBauturi.push_back(new Bauturi());
    *this->listaBauturi.back() = b2;
    this->listaBauturi.push_back(new Bauturi());
    *this->listaBauturi.back() = b3;
    this->listaBauturi.push_back(new Bauturi());
    *this->listaBauturi.back() = b4;
}
void Meniu::adaugareClient(){
    header();
    this->listaClienti.push_back(new Client());
    cin>>(*listaClienti.back());
    header();

}
void Meniu::configurareBar(){
    cin>>this->bar;
    system("CLS");
}
void Meniu::hr(){
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
}
void Meniu::header(){
    system("CLS");
    cout<<endl<<"**************************************************CARCIUMA VALEA STANII*************************************************"<<endl<<endl<<endl;
}

//Meniu::~Meniu(){}

int main(){
    Meniu meniu;
    meniu.start();
    return 0;
}
