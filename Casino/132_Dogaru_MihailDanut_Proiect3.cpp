#include <iostream>
#include <fstream>
#include <strings.h>
#include <windows.h>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <typeinfo>
#include <ctime>
#include <iomanip>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
using namespace std;
using std::runtime_error;

class Exceptie1:public exception{
public:
    virtual const char* what() const throw(){
        return "Valoare invalida\n";
    }
}nrInvalid;

class Player{
private:
    float balanta;
    vector<pair<string,string>> mana;
public:
    Player(){balanta = 100;mana.clear();}
    Player(int balanta){this->balanta = balanta;this->mana = mana;}
    Player(const Player& obj){this->balanta = obj.balanta; this->mana = obj.mana;}
    friend ostream& operator<<(ostream& out,const Player& obj);
    void setBalanta(float idk){this->balanta -= idk;}
    float getBalanta(){return this->balanta;}
    friend istream& operator>>(istream& in,Player& obj);

    ~Player(){}
};

ostream& operator<<(ostream& out,const Player& obj){
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    if(!obj.mana.empty())
        out<<"\n\nMana: ";
    for(auto it = obj.mana.begin() ; it != obj.mana.end() ; it++){
            if(it->second == "rosie"){
                SetConsoleTextAttribute(h,79);
                out<<it->first<<char(3)<<" ";
            }
            if(it->second == "romb"){
                SetConsoleTextAttribute(h,79);
                out<<it->first<<char(4)<<" ";
            }
            if(it->second == "neagra"){

                SetConsoleTextAttribute(h,7);
                out<<it->first<<char(6)<<" ";
            }
            if(it->second == "trefla"){
                SetConsoleTextAttribute(h,7);
                out<<it->first<<char(5)<<" ";
            }
        }
        SetConsoleTextAttribute(h,7);
        out<<'\n';
    out<<"Balanta: "<<obj.balanta<<'\n';
    return out;
}
istream& operator>>(istream& in,Player& obj){
    obj.mana.clear();
    cout<<"Cati bani ai la tine?\n";
    try{
        in>>obj.balanta;
        if(in.fail())
            throw nrInvalid;
        if(obj.balanta < 0)
            throw 1;
    }
    catch(exception& ex){cout<<ex.what();}
    catch(int){cout<<"Jucatorul nu are bani si mai are si datorii\n";obj.balanta = 0;}
    return in;
}

/// ////////////////////////// CARTI
class JocCarti{
protected:
    vector<pair<string,string>> pachet;
public:
    virtual void afisare() = 0;
    JocCarti();
    JocCarti(vector<pair<string,string>> pachet){this->pachet = pachet;}
    JocCarti(const JocCarti& obj){this->pachet = obj.pachet;}
    JocCarti& operator=(const JocCarti& obj);
    friend ostream& operator<<(ostream& out , const JocCarti& obj);
    friend istream& operator>>(istream& in , JocCarti& obj);
    vector<pair<string,string>> getPachet()const{return pachet;}
    int size(){return pachet.size();}
    pair<string,string> &operator[](int index){return pachet[index];}
    pair<string,string> trageCarte();
    ~JocCarti(){};

};

JocCarti::JocCarti(){
    for(int i = 2 ; i <= 10 ; i++){
        this->pachet.push_back({to_string(i),"rosie"});
        this->pachet.push_back({to_string(i),"neagra"});
        this->pachet.push_back({to_string(i),"romb"});
        this->pachet.push_back({to_string(i),"trefla"});
    }
    this->pachet.push_back({"A","rosie"});
    this->pachet.push_back({"A","neagra"});
    this->pachet.push_back({"A","romb"});
    this->pachet.push_back({"A","trefla"});

    this->pachet.push_back({"J","rosie"});
    this->pachet.push_back({"J","neagra"});
    this->pachet.push_back({"J","romb"});
    this->pachet.push_back({"J","trefla"});

    this->pachet.push_back({"Q","rosie"});
    this->pachet.push_back({"Q","neagra"});
    this->pachet.push_back({"Q","romb"});
    this->pachet.push_back({"Q","trefla"});

    this->pachet.push_back({"K","rosie"});
    this->pachet.push_back({"K","neagra"});
    this->pachet.push_back({"K","romb"});
    this->pachet.push_back({"K","trefla"});

    this->pachet.push_back({"Joker","rosie"});
    this->pachet.push_back({"Joker","neagra"});

}
JocCarti& JocCarti::operator=(const JocCarti& obj){
    if( this != &obj){
        this->pachet = obj.pachet;
    }
    return *this;
}
ostream& operator<<(ostream& out , const JocCarti& obj){
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    out<<"CARTILE DIN PACHET\n"<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<"\n";
    for(auto it = obj.pachet.begin() ; it != obj.pachet.end() ; it++){
            if(it->second == "rosie"){
                SetConsoleTextAttribute(h,79);
                out<<it->first<<char(3)<<" ";
            }
            if(it->second == "romb"){
                SetConsoleTextAttribute(h,79);
                out<<it->first<<char(4)<<" ";
            }
            if(it->second == "neagra"){

                SetConsoleTextAttribute(h,7);
                out<<it->first<<char(6)<<" ";
            }
            if(it->second == "trefla"){
                SetConsoleTextAttribute(h,7);
                out<<it->first<<char(5)<<" ";
            }
        }
        SetConsoleTextAttribute(h,7);
        out<<'\n';
        return out;
}
istream& operator>>(istream& in , JocCarti& obj){
    cout<<"Cate carti are pachetul?\n";
    int n;
    try{
        in>>n;
        if(in.fail() || n < 0)
            throw nrInvalid;
    }catch(exception& ex){cout<<ex.what(); n = 0;}

    string aux;
    obj.pachet.clear();
    for(int i = 0 ; i < n ; i++){
        cout<<"cartea "<<i<<":";
        try{
            in>>aux;
            if(in.fail())
                throw 's';
        }catch(char){cout<<"String invalid";}

        obj.pachet.push_back({aux,"rosie"});
        obj.pachet.push_back({aux,"neagra"});
        obj.pachet.push_back({aux,"romb"});
        obj.pachet.push_back({aux,"trefla"});
    }

    return in;
}
pair<string,string> JocCarti::trageCarte(){
    pair<string,string> carte = this->pachet[0];
    this->pachet.erase(this->pachet.begin()+1);
    return carte;
}

class BlackJack:public virtual JocCarti{
protected:
    int suma;
    unordered_map<string,int>valoriCarti;
public:
    BlackJack();
    BlackJack(vector<pair<string,string>> pachet,unordered_map<string,int> valoriCarti);
    BlackJack(const BlackJack& obj);
    BlackJack& operator=(const BlackJack& obj);
    friend ostream& operator<<(ostream& out,const BlackJack& obj);
    friend istream& operator>>(istream& in , BlackJack& obj);
    void afisare();
    ~BlackJack(){};
};

void BlackJack::afisare(){
    cout<<setw(65)<<"BlackJack\n\n\n";

}

BlackJack::BlackJack():JocCarti(){
    for(auto it = pachet.begin() ; it != pachet.end() ; it++)
    if(it->first == "Joker"){
        pachet.erase(it);
        it--;
        }

    for(int i = 2 ; i <= 10 ; i++)
        valoriCarti[to_string(i)] = i;
    valoriCarti["A"] = 11;
    valoriCarti["Q"] = 10;
    valoriCarti["K"] = 10;
    valoriCarti["J"] = 10;
}


BlackJack::BlackJack(vector<pair<string,string>> pachet,unordered_map<string,int> valoriCarti):JocCarti(pachet){
    this->valoriCarti = valoriCarti;
}
BlackJack::BlackJack(const BlackJack& obj){
        this->pachet = obj.pachet;
        this->valoriCarti = obj.valoriCarti;
}
BlackJack& BlackJack::operator=(const BlackJack& obj){
    if(this != &obj){
        JocCarti::operator=(obj);
        this->valoriCarti = obj.valoriCarti;
    }
    return *this;
}
ostream& operator<<(ostream& out,const BlackJack& obj){
    out<<(JocCarti&)obj;
    out<<"\nValorile Cartilor:\n"<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<'\n';
    for(auto it = obj.valoriCarti.begin() ; it != obj.valoriCarti.end() ; it++)
        out<<it->first<<": "<<it->second<<'\n';
    return out;
}
istream& operator>>(istream& in , BlackJack& obj){
    in>>(JocCarti&)obj;
    int aux;
    obj.valoriCarti.clear();
    cout<<"Alegeti valori pt carti\n";
    for(auto it = obj.pachet.begin() ; it != obj.pachet.end() ; it += 4){
        cout<<"Cartile cu "<<it->first<<':';
        try{
            in>>aux;
            if(aux < 0)
                throw runtime_error("trebuie sa fie totusi pozitiv");
        }catch(runtime_error& e){cout<<"Nu e buna valoarea,ii punem 0\n"; aux = 0; }
        obj.valoriCarti[it->first] = aux;
    }

    return in;
}

/// //////////////Pacanea
class Pacanea{
private:
    vector<char> slot;
public:
    Pacanea();
    Pacanea(string numePac,vector<char>slot,map<string,int>){this->slot = slot;}
    Pacanea(const Pacanea& obj){this->slot = obj.slot;}
    Pacanea& operator=(const Pacanea& obj);
    char &operator[](int index){return slot[index];}
    int size(){return slot.size();}
    friend istream& operator>>(istream& in,Pacanea& obj);
    friend ostream& operator<<(ostream& out,const Pacanea& obj);
    void afisare(){cout<<(*this);}
    void joaca(Player& obj,float miza);
    ~Pacanea(){}

};

void Pacanea::joaca(Player& obj,float miza){
    if(this->slot[3] == this->slot[4]){
        obj.setBalanta(obj.getBalanta() + miza*5);
        if(this->slot[4] == this->slot[5])
            obj.setBalanta(obj.getBalanta() + miza*5);
    }
}

Pacanea::Pacanea(){
    for(int i = 0 ; i < 3 ; i++){
        this->slot.push_back('J');
        this->slot.push_back('Q');
        this->slot.push_back('K');
    }
}
Pacanea& Pacanea::operator=(const Pacanea& obj){
    if(this != &obj){
        this->slot = obj.slot;
    }
    return *this;
}
ostream& operator<<(ostream& out,const Pacanea& obj){
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    out<<setw(57)<<"Pacanea"<<"\n"<<setw(48)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<"\n";
    out<<setw(50);
    for(int i = 0 ; i < 9 ; i++){
        if( (i >= 3 && i <= 5)&&((obj.slot[3] == obj.slot[4] && obj.slot[4] == obj.slot[5]) || obj.slot[3] == obj.slot[4]))
            SetConsoleTextAttribute(h,10);
        if( obj.slot[4] != obj.slot[5] && i == 5  ) SetConsoleTextAttribute(h,7);
        out<<obj.slot[i]<<"  ";
        SetConsoleTextAttribute(h,7);
        if(!(i%3 -2)){
            out<<'\n';
            out<<setw(50);
        }
    }
    return out;
}
istream& operator>>(istream& in, Pacanea& obj){
    obj.slot.clear();
    cout<<"Cate simboluri ai?\n";
    int n;
    string aux;
    try{
        in>>n;
        if(in.fail())
            throw nrInvalid;
        }catch(exception& ex){cout<<ex.what(); n = 0;}

    for(int i = 0 ; i < n ; i++){
        cout<<"Caracterul "<<i<<": ";
        try{
            in>>aux;
            if(aux.size() > 1)
                throw nrInvalid;
            }catch(exception& ex){cout<<ex.what(); aux = "-";}
       obj.slot.push_back(aux[0]);
    }
    if(n < 9){
        for(int i = 9 - n ; i > 0 ; i--)
            obj.slot.push_back('-');
    }
    return in;
}
/// /////////RULETA

class Ruleta{
private:
    vector<int> numere;
    int bila;
    map<string,int> cote;
    list<int> prev;

public:
    Ruleta();
    Ruleta(vector<int> numere, int bila){this->numere = numere;this->bila = bila;this->cote = cote;this->prev = prev;}
    Ruleta(const Ruleta& obj){this->numere = obj.numere; this->bila = obj.bila;this->cote = obj.cote;this->prev = obj.prev;}
    Ruleta& operator=(const Ruleta& obj);
    int operator[](int nr){return bila;}
    int size(){return numere.size();}
    void setBila(int nr){this->bila = nr;}
    friend ostream& operator<<(ostream& out , const Ruleta& obj);
    friend istream& operator>>(istream& in, Ruleta& obj);
    void amesteca(){srand(time(nullptr)); this->bila = rand()% this->size();}
    void afisare(){cout<<(*this);}

};

Ruleta::Ruleta(){
    srand(time(nullptr));
    bila = -1;
    for(int i = 0 ; i < 36 ; i++)
        numere.push_back(i);
    cote["rosie"] = 2;
    cote["neagra"] = 2;
    cote["nrExact"] = numere.size();
    cote["par"] = 2;
    cote["impar"] = 2;
    cote["0"] = 14;
    prev.clear();
    for(int i = 0 ; i < 7 ; i++)
        prev.push_back(rand()%this->size());
}
Ruleta& Ruleta::operator=(const Ruleta& obj){
    if(this != &obj){
        this->numere = numere;
        this->bila = bila;
        this->cote = cote;
        this->prev = prev;
    }
    return *this;
}
ostream& operator<<(ostream& out , const Ruleta& obj){
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    out<<setw(65)<<"Ruleta\n\n\n";
    SetConsoleTextAttribute(h,175);
    out<<obj.numere[0];
    for(auto it = obj.numere.begin()+1 ; it != obj.numere.end() ; it++){
        if(*it%2)   SetConsoleTextAttribute(h,79);
        else        SetConsoleTextAttribute(h,7);
        out<<*it;
    }
    SetConsoleTextAttribute(h,7);
    out<<'\n';
    if(obj.bila < 0) out<<"Bila nu a fost inca aruncata!!!\n";
    if(obj.bila == 0) out<<"O";
    if(obj.bila < obj.numere.back() && obj.bila > 0){
        for(int i = 0 ; i < obj.bila ; i++)
            for(int j = 0 ; j < to_string(i).length() ; j++)
                out<<" ";
        out<<"O";
    }
    out<<'\n';
    out<<"Ultimele maini :";
    if(!obj.prev.empty()){
        for(auto it = obj.prev.rbegin() ; it != obj.prev.rend() ; it++){
            if((*it == 0))    SetConsoleTextAttribute(h,175);
            if(*it % 2)     SetConsoleTextAttribute(h,79);
            if(!(*it % 2)&& *it)  SetConsoleTextAttribute(h,7);
            out<<*it<<" ";
        }
        SetConsoleTextAttribute(h,7);
        out<<'\n';
    }else
        out<<"Jocul nu a inceput inca!\n";

    out<<"\nCote\n"<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<char(196)<<"\n";
    for(auto it = obj.cote.begin() ; it != obj.cote.end() ; it++)
        out<<it->first<<"->x"<<it->second<<'\n';

    return out;
}
istream& operator>>(istream& in,Ruleta& obj){
    obj.numere.clear();
    int x;
    cout<<"Cate numere sa aibe?\n";
    try{
        in>>x;
        if(in.fail() || x < 1)
            throw nrInvalid;
        }catch(exception& ex){cout<<ex.what(); x = 36;}
    for(int i = 0 ; i < x ; i++)
        obj.numere.push_back(i);
    obj.bila = -1;
    obj.cote["nrExact"] = obj.size();
    return in;
}

template<typename T>
    void amesteca(T& joc){
        srand(time(nullptr));
            T aux = joc;
            vector<bool> v(joc.size());
            for(int i = 0 ; i < joc.size() ; i++){
                int idk = rand() % joc.size();
                while(v[idk])
                    idk = (idk+1)%joc.size();

                joc[idk] = aux[i];
                v[idk] = 1;
            }
    }
void amesteca(Ruleta& r){
    srand(time(nullptr));
    r.setBila(rand()%r.size());
}


template<class T>
class MasaJoc{
private:
    T joc;
    int nrJucatori;
    float miza;
    vector<Player*>bots;
public:
    MasaJoc(){bots.clear();this->nrJucatori = 0;this->miza = 0.2;}
    MasaJoc(T joc,int juc,vector<Player*> bots,float miza){this->joc = joc;this->nrJucatori = juc;this->bots = bots;this->miza = miza;}
    MasaJoc(const MasaJoc& obj){this->joc = obj.joc; this->nrJucatori = obj.nrJucatori;this->bots = obj.bots;this->miza = miza;}
    MasaJoc& operator=(const MasaJoc& obj){
         if(this != &obj){
            this->joc = obj.joc;
            this->nrJucatori = obj.nrJucatori;
            this->bots = obj.bots;
            this->miza = miza;
        }
        return *this;
    }
    template<typename Q> friend ostream& operator<<(ostream& out,const MasaJoc<Q> &obj);
    float getMiza()const{return this->miza;}
    void afisare(){joc.afisare();}
    void schimbaMiza(){
        system("cls");
        cout<<"Pe cat joci?\n";
        float nr;
        cin>>nr;
        this->miza = nr;
        system("cls");
        }
    //void joaca(Player& obj){joc.joaca(obj,miza);} /// in fiecare clasa de joc tre sa ai metoda asta
    ~MasaJoc(){
        int aux = nrJucatori;
        for(int i = aux ; i > 0 ; i--)
            delete bots[i-1];

        }
};
    template<typename Q> ostream& operator<<(ostream& out,const MasaJoc<Q> &obj){out<<obj.joc<<"Numarul de jucatori:"<<obj.nrJucatori<<'\n'<<"Miza:"<<obj.miza;return out;};

class Casino{
private:
    static Casino* obiect;
    MasaJoc<Ruleta> roulette;
    MasaJoc<BlackJack> blackj;
    MasaJoc<Pacanea> paca;
    Player obj;
    float fonduri;


    Casino();
    Casino(MasaJoc<Ruleta> roulette,MasaJoc<BlackJack> blackj,MasaJoc<Pacanea> paca,Player obj) = delete;
    Casino(const Casino& obj) = delete;
    Casino& operator=(const Casino& obj) = delete;

public:
    static Casino* getInstance(){
        if(!obiect)
            obiect = new Casino();
        return obiect;
    }
    template<typename Q> void start(Q& joc,Player& obj);
    ~Casino(){}
    void start();
    void hr();
    void scriere();
};
Casino* Casino::obiect = nullptr;

void Casino::scriere(){
    ofstream out("bani.in");
    out<<"fonduri:"<<this->fonduri;
    out.close();
}

Casino::Casino(){
    ifstream in("bani.in",ifstream::binary);
    if(in){
        in.seekg(0,in.end);
        int lung = in.tellg();
        in.seekg(0,in.beg);

        char* buffer = new char[lung];
        in.read(buffer,lung);
        in.close();
        char* p = strtok(buffer,":");
        p = strtok(NULL,":");
        if(p)
            this->fonduri = atoi(p);
        else
            throw runtime_error("Fonduri corupte");
        delete[] buffer;
    }

}


template<typename Q>
void Casino::start(Q& joc,Player& obj){
    system("cls");
    joc.afisare();
    cout<<obj;
    cout<<"Miza: "<<joc.getMiza()<<'\n';
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"1.Joaca\n"
        <<"2.Schimba miza\n"
        <<"3.Pleaca la alta masa \n"
        <<"4.Out\n";
    string aux ;
    int k;

    try{
        cin>>aux;
        k = stoi(aux);
        if(to_string(stoi(aux)).size() != aux.size())
            throw logic_error("Numar incorect\n");
        if(k > 4 || k < 1)
            throw 'a';
        }catch(char){
            cout<<"Optiunea nu e in posibila\n";
            system("pause");
            system("cls");
            start(joc,obj);}
         catch(logic_error& c){
             cin.clear();
             cin.ignore(256, '\n');
            cout<<"Invalid\n";system("pause"); start(joc,obj);
        }


    switch(k){
        case(1):
                 if(obj.getBalanta() - joc.getMiza() >= 0){
                    obj.setBalanta(obj.getBalanta() - joc.getMiza());
                    //joc.joaca(obj);
                 }
                 else{
                    system("cls");
                    cout<<"Fonduri insuficiente\n"
                        <<"Apasati 1 pentru a iesi";
                    int i;
                    cin>>i;
                    if(i == 1) return;

                 }
                 break;

        case(2): joc.schimbaMiza();
                 start(joc,obj);
                 break;
        case(3): start();
                 break;
        case(4): return;
    }
}
void Casino::hr(){cout<<setw(60)<<"CASINO\n"<<setw(62)<<"~~~~~~~~~~~\n\n";}
void Casino::start(){
    system("cls");
    hr();
    cout<<"Alegeti joc:\n";
    cout<<"\t1.Pacanea\n"
        <<"\t2.Ruleta\n"
        <<"\t3.BlackJack\n";
    string aux;
    int k;
    try{
        cin>>aux;
        k = stoi(aux);
        if(to_string(stoi(aux)).size() != aux.size())
            throw logic_error("Numar incorect\n");
        if(k > 4 || k < 1)
            throw 'a';
        }catch(char){
            cout<<"Optiunea nu e in posibila\n";
            system("pause");
            system("cls");
            start();}
         catch(logic_error& c){
             cin.clear();
             cin.ignore(256, '\n');
            cout<<"Invalid\n";system("pause"); start();
        }
    switch(k){
        case(1):
            start(paca,obj);
            break;
        case(2):
            start(roulette,obj);
            break;
        case(3):
            start(blackj,obj);
            break;

    }
}

int main()
{  Casino *superbet = superbet->getInstance();
  // superbet->start();
//superbet->scriere();

Ruleta r;BlackJack b;Pacanea pa;
cout<<r;
system("pause"); system("cls");
amesteca(r);
cout<<r;
system("pause"); system("cls");
cout<<b;
system("pause"); system("cls");
amesteca(b);
cout<<b;
system("pause"); system("cls");
cout<<pa;
amesteca(pa);
system("pause"); system("cls");

cout<<pa;
system("pause"); system("cls");


 return 0;
}
