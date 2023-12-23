//Dogaru Mihail Danut
//grupa 132
//CodeBlocks
//profesor Szmeteanca Eduard
#include<iostream>
#include<vector>
#include <typeinfo>
#include<exception>
using namespace std;

class Ex1:public exception{
public:
    virtual const char* what() const throw(){
        return "valoare invalida";
    }

}ex1;

class IOinterface{
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const= 0;

};

class Drum:public IOinterface{
protected:
    string nume;
    float km;
    int tronsoane;
public:
    Drum(){nume = "necunoscut";km = 0; tronsoane = 1;}
    ostream& afisare(ostream& out) const;
    istream& citire(istream& in);
    float cost(){return km/tronsoane;}
    friend istream& operator>>(istream& in,Drum& obj);
    friend ostream& operator<<(ostream& out,const Drum& obj);
    float getKm(){return km;}
};

istream& operator>>(istream& in,Drum& obj){ return obj.citire(in);}
ostream& operator<<(ostream& out,const Drum& obj){return obj.afisare(out);}
ostream& Drum::afisare(ostream& out)const{
    out<<"Nume drum:"<<this->nume;
    out<<"\nNr km:"<<this->km;
    out<<"\nNr tronsoane:"<<this->tronsoane;
    out<<'\n';
    return out;

}
istream& Drum::citire(istream& in){
    cout<<"Nume drum: "; in>>this->nume;
    try{
        cout<<"Nr km: ";
        in>>this->km;
        if(this->km < 0)
            throw ex1;
    }catch(exception& e){cout<<e.what(); this->km = 0;}
    try{
        cout<<"Nr tronsoane: ";
        in>>this->tronsoane;
        if(this->tronsoane < 1)
            throw ex1;
    }catch(exception& e){cout<<e.what(); this->tronsoane = 1;}
    return in;
}


class DrumNat:public Drum{
protected:
    int nrJud;
public:
    DrumNat():Drum(){nrJud = 0;}
    ostream& afisare(ostream& out) const;
    istream& citire(istream& in);
    friend istream& operator>>(istream& in,DrumNat& obj);
    friend ostream& operator<<(ostream& out,const DrumNat& obj);
};

istream& operator>>(istream& in,DrumNat& obj){ return obj.citire(in);}
ostream& operator<<(ostream& out,const DrumNat& obj){return obj.afisare(out);}
ostream&  DrumNat::afisare(ostream& out)const{
    Drum::afisare(out);
    out<<"Nr judete:"<<this->nrJud;
    out<<'\n';
    return out;
}

istream& DrumNat::citire(istream& in){
    Drum::citire(in);
    try{
        cout<<"Nr de judete:"; in>>this->nrJud;
        if(nrJud < 0)
            throw ex1;
    }catch(exception& e){cout<<e.what();this->nrJud = 0;}
}

class DrumEuro:public virtual Drum{
protected:
    int nrTari;
public:
    DrumEuro():Drum(){nrTari = 0;}
    ostream& afisare(ostream& out) const;
    istream& citire(istream& in);

    friend istream& operator>>(istream& in,DrumEuro& obj);
    friend ostream& operator<<(ostream& out,const DrumEuro& obj);
};

istream& operator>>(istream& in,DrumEuro& obj){ return obj.citire(in);}
ostream& operator<<(ostream& out,const DrumEuro& obj){return obj.afisare(out);}

ostream&  DrumEuro::afisare(ostream& out)const{
    Drum::afisare(out);
    out<<"Nr tari:"<<this->nrTari;
    out<<'\n';
    return out;
}

istream& DrumEuro::citire(istream& in){
    Drum::citire(in);
    try{
        cout<<"Nr de tari:"; in>>this->nrTari;
        if(nrTari < 0)
            throw ex1;
    }catch(exception& e){cout<<e.what();this->nrTari = 0;}
}


class Autos:public virtual Drum{
protected:
    int benzi;
public:
    Autos():Drum(){benzi = 2;}
    ostream& afisare(ostream& out) const;
    istream& citire(istream& in);

    friend istream& operator>>(istream& in,Autos& obj);
    friend ostream& operator<<(ostream& out,const Autos& obj);
};

istream& operator>>(istream& in,Autos& obj){ return obj.citire(in);}
ostream& operator<<(ostream& out,const Autos& obj){return obj.afisare(out);}

ostream&  Autos::afisare(ostream& out)const{
    Drum::afisare(out);
    out<<"Nr benzi:"<<this->benzi;
    out<<'\n';
    return out;
}

istream& Autos::citire(istream& in){
    Drum::citire(in);
    try{
        cout<<"Nr de benzi:"; in>>this->benzi;
        if(benzi < 2)
            throw ex1;
    }catch(exception& e){cout<<e.what();this->benzi = 2;}
}


class AutosEuro:public Autos,public DrumEuro{
public:
    AutosEuro():Autos(),DrumEuro(){}
    ostream& afisare(ostream& out) const;
    istream& citire(istream& in);

    friend istream& operator>>(istream& in,AutosEuro& obj);
    friend ostream& operator<<(ostream& out,const AutosEuro& obj);
};

istream& operator>>(istream& in,AutosEuro& obj){ return obj.citire(in);}
ostream& operator<<(ostream& out,const AutosEuro& obj){return obj.afisare(out);}
ostream&  AutosEuro::afisare(ostream& out)const{
    Drum::afisare(out);
    out<<"Nr benzi:"<<this->benzi;
    out<<"\nNr tari:"<<this->nrTari;
    out<<'\n';
    return out;
}

istream& AutosEuro::citire(istream& in){
    Drum::citire(in);
    try{
        cout<<"Nr de benzi:"; in>>this->benzi;
        if(benzi < 2)
            throw ex1;
    }catch(exception& e){cout<<e.what();this->benzi = 2;}

    try{
        cout<<"Nr de tari:"; in>>this->nrTari;
        if(nrTari < 0)
            throw ex1;
    }catch(exception& e){cout<<e.what();this->nrTari = 0;}
}



class Contract:public IOinterface{
private:
    static int contor;
    const int id;
    string nume;
    string cif;
    Drum* drum;
    float cost;
public:
    Contract():id(contor++){nume = "necunoscut";cif="necunoscut";drum = NULL;cost = 0;}
    ostream& afisare(ostream& out)const;
    istream& citire(istream& in);
    operator string(){return nume;}


    friend istream& operator>>(istream& in,Contract& obj);
    friend ostream& operator<<(ostream& out,const Contract& obj);
};
int Contract::contor = 0;

istream& operator>>(istream& in,Contract& obj){ return obj.citire(in);}
ostream& operator<<(ostream& out,const Contract& obj){return obj.afisare(out);}
ostream& Contract::afisare(ostream& out)const{
    out<<"Nume contract:"<<this->nume;
    out<<"\nID:"<<this->id;
    out<<"\nCif:"<<this->cif;
    out<<"\nCost:"<<this->cost;
    out<<"\nDrumul:\n"<<this->drum;
    out<<'\n';
    return out;
}
istream& Contract::citire(istream& in){
    cout<<"Nume contract:" ;in>>this->nume;
    cout<<"Cif:";in>>this->cif;
    cout<<"Tipul de drum:"
        <<"\n1.National"
        <<"\n2.European"
        <<"\n3.Autostrada"
        <<"\n4.Autostrada Europeana";
    int k;
    in>>k;
    Drum* aux;
    switch(k){
    case 1:
        drum = new DrumNat();
         aux =  dynamic_cast<DrumNat*>(drum);
       // in>>(*aux);
        this->cost = 3000*drum->cost();
        break;
    case 2:
        drum = new DrumEuro();
        aux =  dynamic_cast<DrumEuro*>(drum);

        //in>>*drum;
        this->cost = 3000*drum->cost() + 500*drum->cost();
        break;
    case 3:
        drum = new Autos();
        aux =  dynamic_cast<Autos*>(drum);

        //in>>*drum;
        this->cost = 2500*drum->cost();
        break;
    case 4:
        drum = new AutosEuro();
        aux =  dynamic_cast<AutosEuro*>(drum);

        //in>>*drum;
        this->cost = 2500*drum->cost() + 500*drum->cost();

        break;
    default:
        drum = new Drum();
        aux =  dynamic_cast<Drum*>(drum);

        //in>>*drum;
        this->cost = 3000*drum->cost();
        break;
    }

    return in;
}

class Meniu{
private:
        vector<Drum*>drumuri;
        vector<Contract*> contracte;
        Meniu(){}
        Meniu(vector<Drum*>,vector<Contract>) = delete;
        Meniu(const Meniu&) = delete;
        Meniu& operator=(const Meniu&) = delete;
        ~Meniu();
public:
    Meniu& getInstance();
    void start();
    void lungimi();
    void rezilieri();
    float sumaCost();
};

Meniu& Meniu::getInstance(){
    static Meniu inst;
    return inst;
}

Meniu::~Meniu(){
    if(!drumuri.empty())
        for(int i = 0 ; i < drumuri.size(); i++)
            delete drumuri[i];
        drumuri.clear();

    if(!contracte.empty())
        for(int i = 0 ; i < contracte.size() ; i++)
            delete contracte[i];

        contracte.clear();
}
void Meniu::rezilieri(){
    cout<<"CIF-ul de sters:";
    string aux; cin>>aux;
    for(auto i = contracte.begin() ; i != contracte.end(); i++)
        if(string(**i) == aux){
            contracte.erase(i);
            i--;
        }

}
float Meniu::sumaCost(){ //nu e dupa denumire, timpul :(, suma totala a tuturor drumurilor
    float sum = 0 ;
    for(int i = 0 ; i < drumuri.size() ; i++){
        sum += drumuri[i]->cost();
    }
    return sum;

}
void Meniu::lungimi(){
    float sum = 0,sumAu = 0;
    for(int i = 0; i < drumuri.size() ; i++){
        sum += drumuri[i]->getKm();
        if(typeid(*drumuri[i]) == typeid(Autos) || typeid(*drumuri[i]) == typeid(AutosEuro))
            sumAu += drumuri[i]->getKm();
    }
    cout<<"Suma km:"<<sum;
    cout<<"\nDintre care autostrazi:"<<sumAu;

};

void Meniu::start(){
    bool ok = 1;
    while(ok){
       cout<<"\n1.Adauga Drum National"
           <<"\n2.Adauga Drum European"
           <<"\n3.Adauga Austostrada"
           <<"\n4.Adauga Autostrada Europeana"
           <<"\n5.Adauga Contract"
           <<"\n6.Afiseaza drumuri"
           <<"\n7.Afiseaza contracte"
           <<"\n8.Total km"
           <<"\n9.Reziliaza/Rezilieaza?"
           <<"\n10.Suma costurilor"
           <<"\n11.Out\n";
        int optiune;
        cin>>optiune;
        switch(optiune){
        case 1:
            drumuri.push_back(new DrumNat());
            cin>>*drumuri.back();
            break;
        case 2:
            drumuri.push_back(new DrumEuro());
            cin>>*drumuri.back();
            break;
        case 3:
            drumuri.push_back(new Autos());
            cin>>*drumuri.back();
            break;
        case 4:
            drumuri.push_back(new AutosEuro());
            cin>>*drumuri.back();
            break;
        case 5:
            contracte.push_back(new Contract());
            cin>>*contracte.back();
            break;
        case 6:
            for(int i = 0 ; i < drumuri.size(); i++){
                if(typeid(*drumuri[i]) == typeid(DrumNat)){
                    DrumNat* aux = dynamic_cast<DrumNat*>(drumuri[i]);
                    cout<<*aux;
                }
                if(typeid(*drumuri[i]) == typeid(DrumEuro)){
                    DrumEuro* aux = dynamic_cast<DrumEuro*>(drumuri[i]);
                    cout<<*aux;
                }
                if(typeid(*drumuri[i]) == typeid(Autos)){
                    Autos* aux = dynamic_cast<Autos*>(drumuri[i]);
                    cout<<*aux;
                }
                if(typeid(*drumuri[i]) == typeid(AutosEuro)){
                    AutosEuro* aux = dynamic_cast<AutosEuro*>(drumuri[i]);
                    cout<<*aux;
                }

            }
            break;
        case 7:
            for(int i = 0 ; i < contracte.size(); i++)
                cout<<*contracte[i];
        case 8:
            lungimi();
            break;
        case 9:
            rezilieri();
            break;
        case 10:
            cout<<"Suma costurilor:"<<sumaCost();
            break;
        case 11:
            return;

    }



    }
}
int main(){
Meniu& men = men.getInstance();
men.start();
return 0;
}

