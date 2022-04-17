#include <iostream>

int licznik = 0;

class silnik {
private:
    bool czy_uruchomiony;
    char bieg;
public:
    silnik() : czy_uruchomiony(false), bieg('N') {};
    ~silnik(){};
    bool uruchomiony() { return czy_uruchomiony; }
    void uruchom()
    {
        if (czy_uruchomiony)
        {
            std::cout << "samochod jest juz uruchomiony" << std::endl;
        }
        else
            czy_uruchomiony = true;
        std::cout << "uruchomiles samochod" << std::endl;
    }
    void zgas()
    {
        if (czy_uruchomiony)
        {
            czy_uruchomiony = false;
            std::cout << "zgasiles samochod" << std::endl;
        }
        else
            std::cout << "samochod jest juz zgaszony" << std::endl;
    }
    void zmien_bieg(char zmiana)
    {
        if (zmiana== 'N' || zmiana == 'R' || zmiana == '1' || zmiana == '2' || zmiana == '3' || zmiana == '4' || zmiana == '5')
        {
            bieg = zmiana;
            std::cout << "Zmieniles bieg na " << bieg << std::endl;
        }
        else
            std::cout << "nie ma takiego biegu" << std::endl;
  //         throw std::invalid_argument("nie ma takiego biegu");
    }
};
class pojazd_silnikowy : public silnik {
private:
    std::string marka;
    std::string model;
    int calkowity_przebieg;
    int rocznik;
    silnik silnik1;
public:
    pojazd_silnikowy() : marka("marka"), model("model"), calkowity_przebieg(0), rocznik(2020){};
    pojazd_silnikowy(std::string _marka, std::string _model, int _calkowity_przebieg, int _rocznik) : marka(_marka), model(_model),
        calkowity_przebieg(_calkowity_przebieg), rocznik(_rocznik) {};
    pojazd_silnikowy(const pojazd_silnikowy& poj1) : marka(poj1.marka), model(poj1.model), calkowity_przebieg(poj1.calkowity_przebieg), rocznik(poj1.rocznik), silnik1(poj1.silnik1) {};

    void przebieg(int dystans) { calkowity_przebieg += dystans; }

    friend void operator<<(std::ostream& x, pojazd_silnikowy& poj);
    virtual void przejedz_x_kilometrow(int ile) {};
    ~pojazd_silnikowy() {};

};
class samochod : public pojazd_silnikowy{
private:

    double zuzycie_paliwa;
    double poziom_paliwa;
    double pojemnosc_baku;
    pojazd_silnikowy s1;
    silnik s2;

public:

    samochod(
        std::string _marka,
        std::string _model,
        double _poziom_paliwa, 
        double _pojemnosc_baku, 
        double _zuzycie_paliwa, 
        int _calkowity_przebieg, 
        int _rocznik) : pojazd_silnikowy(_marka, _model, _calkowity_przebieg, _rocznik), 
        zuzycie_paliwa(_zuzycie_paliwa), poziom_paliwa(_poziom_paliwa), pojemnosc_baku(_pojemnosc_baku) {};

    samochod(const samochod& sam1) : pojazd_silnikowy(sam1), zuzycie_paliwa(sam1.zuzycie_paliwa), poziom_paliwa(sam1.poziom_paliwa), pojemnosc_baku(sam1.pojemnosc_baku) {};
    void przejedz_x_kilometrow(int ile)
    {
        if (uruchomiony())
        {
            if (poziom_paliwa - ile * zuzycie_paliwa > 0)
            {
                poziom_paliwa -= double(ile * zuzycie_paliwa);
                std::cout << "Przejechales: " << ile << " km" << std::endl;
                przebieg(ile);

            }
            else
            {
                std::cout << "Masz za malo paliwa" << std::endl;
            }

        }
        else
            std::cout << "musisz najpierw wlaczyc samochod!" << std::endl;
    }
    void zatankuj_x_litrow(double litry)
    {
        if ((poziom_paliwa + litry) <= pojemnosc_baku)
        {
            poziom_paliwa += litry;
        }
        else
        {
            throw std::invalid_argument("Tyle paliwa sie nie zmiesci w baku");
        }
        
    }
    double paliwko() { return poziom_paliwa; }
  /*  void pokaz()
    {
        std::cout << "marka = " << marka << std::endl;
        std::cout << "model = " << model << std::endl;
        std::cout << "poziom paliwa = " << poziom_paliwa << std::endl;
        std::cout << "pojemnosc baku = " << pojemnosc_baku << std::endl;
        std::cout << "calkowity przebieg = " <<calkowity_przebieg << std::endl;
        std::cout << "rocznik = " << rocznik << std::endl;
        std::cout << "zuzycie paliwa = " << zuzycie_paliwa << std::endl;
    }*/
    ~samochod(){};
};

class samochod_elektryczny : public pojazd_silnikowy{
private:
    double  naladowanie_baterii;
    double maksymalny_zasieg;
 //   int licznik = 0;
public:
    samochod_elektryczny(
        std::string _marka,
        std::string _model,
        int _calkowity_przebieg,
        int _rocznik,
        double _naladowanie_baterii,
        double _maksymalny_zasieg
    ) : pojazd_silnikowy(_marka, _model, _calkowity_przebieg, _rocznik), naladowanie_baterii(_naladowanie_baterii), maksymalny_zasieg(_maksymalny_zasieg) {
        licznik++;
    };
    void przejedz_x_kilometrow(int ile)
    {
        if (uruchomiony())
        {
            if (naladowanie_baterii >= ile)
            {
                naladowanie_baterii -= ile;
                std::cout << "Przejechales : " << ile << " km samochodem elektrycznym" << std::endl;
                przebieg(ile);
            }
            else
            {
                std::cout << "Masz za malo baterii zeby przemierzyc taki dystans " << std::endl;
            }

        }
        else
            std::cout << "musisz najpierw wlaczyc samochod elektryczny!" << std::endl;
    }

    void doladuj()
    {
        naladowanie_baterii = maksymalny_zasieg;
    }
    void ile_obiektow() {
        std::cout << "Aktualnie obiektow : " << ::licznik << std::endl;
    }
    void bateria()
    {
        std::cout << "zasieg twojego samochodu to: " << naladowanie_baterii << std::endl;
    }
    ~samochod_elektryczny() { licznik--; }
};
void operator<<(std::ostream& x, pojazd_silnikowy& poj)
{
    x << "\n -------------------------------------- \n" << std::endl;
    x << "marka: " << poj.marka << std::endl;
    x << "model: " << poj.model << std::endl;
    x << "calkowity przebieg samochodu to: " << poj.calkowity_przebieg << " km" << std::endl;
    x << "rocznik: " << poj.rocznik <<std::endl;
    x << "\n -------------------------------------- \n" << std::endl;
}



int main()
{
    samochod s1("Ford", "Focus ST", 23.1, 40.0, 0.1, 23432, 2019);
    samochod s2(s1);
    samochod_elektryczny se1("Tesla", "model S", 12323, 2020, 32, 800);
    samochod_elektryczny se2("Tesla", "model X", 100, 2022, 672, 850);

    samochod* px1;
    samochod_elektryczny* px2;
    samochod_elektryczny* px3;
    px1 = &s2;
    px2 = &se1;
    std::cout << *px1;
 //   px1->przejedz_x_kilometrow(6);
    px1->uruchom();

  //  s1.pokaz();
    //std::cout << "\n\n";
    //s1.przejedz_x_kilometrow(45);
    //s1.pokaz();
    //std::cout << "\n\n";
    //s1.zatankuj_x_litrow(15.2);
    //s1.pokaz();
    //std::cout << "\nsamochod 2:";
    //s2.pokaz();
 //   s1.przejedz_x_kilometrow(30);
//    s1.zgas();
    se1.ile_obiektow();
 //   std::cout << s1;
 //   std::cout << se1;
    px1->zmien_bieg('7');
    std::cout << "\naktualnie masz: " << px1->paliwko() << " litrow paliwa" << std::endl;
    px1->przejedz_x_kilometrow(100);
    std::cout << "zostalo ci: " << px1->paliwko() << " litrow paliwa\n" << std::endl;
    std::cout<< px1->uruchomiony() <<std::endl;
    try {
       px1->zatankuj_x_litrow(20);
      
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
       
    }
    std::cout << *px1;
    std::cout << "zostalo ci: " << px1->paliwko() << " litrow paliwa\n" << std::endl;
    px1->zgas();
    std::cout << px1->uruchomiony() << std::endl;
    std::cout << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx \n\n" << std::endl;
    px2->uruchom();
    px2->bateria();
    px2->przejedz_x_kilometrow(33);
    px2->doladuj();
    px2->bateria();
    px2->przejedz_x_kilometrow(33);
    px2->bateria();
    px2->zgas();

    return 0;
 
}


