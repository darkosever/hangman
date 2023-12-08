//
//  main.cpp
//  vaja6
//
//  Created by Darko Sever on 07/12/2023.
//

#include <iostream>
#include <time.h>
#include <chrono>

// scenariji
const char *scenarij1 =
"       *  * * * *     \n"
"       * *      *     \n"
"       **             \n"
"       *              \n"
"       *              \n"
"       *              \n"
"       *              \n"
"      * *             \n"
"     *   *            \n";


const char *scenarij2 =
"       *  * * * *     \n"
"       * *      *     \n"
"       **      -O-    \n"
"       *              \n"
"       *              \n"
"       *              \n"
"       *              \n"
"      * *             \n"
"     *   *            \n";


const char *scenarij3 =
"       *  * * * *     \n"
"       * *      *     \n"
"       **      -O-    \n"
"       *        |     \n"
"       *        |     \n"
"       *       |      \n"
"       *              \n"
"      * *             \n"
"     *   *            \n";


const char *scenarij4 =
"       *  * * * *     \n"
"       * *      *     \n"
"       **      -O-    \n"
"       *        |     \n"
"       *        |     \n"
"       *       | |    \n"
"       *              \n"
"      * *             \n"
"     *   *            \n";

const char *scenarij5 =
"       *  * * * *     \n"
"       * *      *     \n"
"       **      -O-    \n"
"       *       =|     \n"
"       *        |     \n"
"       *       | |    \n"
"       *              \n"
"      * *             \n"
"     *   *            \n";

const char *scenarij6 =
"       *  * * * *     \n"
"       * *      *     \n"
"       **      -O-    \n"
"       *       =|=    \n"
"       *        |     \n"
"       *       | |    \n"
"       *              \n"
"      * *             \n"
"     *   *            \n";

const char *scenarij7 =
"       *  * * * *     \n"
"       * *      *     \n"
"       **      -O-    \n"
"       *      -=|=    \n"
"       *        |     \n"
"       *       | |    \n"
"       *              \n"
"      * *             \n"
"     *   *            \n";

const char *scenarij8 =
"       *  * * * *     \n"
"       * *      *     \n"
"       **      -O-    \n"
"       *      -=|=-   \n"
"       *        |     \n"
"       *       | |    \n"
"       *              \n"
"      * *             \n"
"     *   *            \n";

const char *scenarij9 =
"       *  * * * *     \n"
"       * *      *     \n"
"       **      -O-    \n"
"       *     --=|=-   \n"
"       *        |     \n"
"       *       | |    \n"
"       *              \n"
"      * *             \n"
"     *   *            \n";


const char *scenarij10 =
"       *  * * * *     \n"
"       * *      *     \n"
"       **      -O-    \n"
"       *     --=|=--  \n"
"       *        |     \n"
"       *       | |    \n"
"       *              \n"
"      * *  GAME OVER! \n"
"     *   *            \n";

const char *scenariji[] = {scenarij1, scenarij2, scenarij3, scenarij4, scenarij5, scenarij6, scenarij7, scenarij8, scenarij9, scenarij10};

// 100 besed za nakjlučno izbiro
std::string slovenske_besede[] = {
        "jabolko", "hisnica", "sonce", "miza", "racunalnik", "gora", "reka", "knjiga", "svetloba", "pot",
        "roza", "trava", "drevo", "ribnik", "voda", "zelje", "ptica", "kamen", "oblak", "list",
        "soncnica", "veter", "pesek", "hisica", "kruh", "kava", "trgovina", "zvezda", "luna", "cas",
        "letalo", "vlak", "avto", "bajta", "igraca", "umetnost", "sola", "pisarna", "zabava", "telefon",
        "stran", "skodelica", "kosara", "boga", "film", "glasba", "svet", "barva", "slika", "sreca",
        "mesto", "cesta", "most", "torta", "morje", "otok", "svincknik", "kemija", "fizika", "matematika",
        "glas", "rokavica", "klobuk", "torba", "hrana", "trikotnik", "krog", "kvadrat", "oseba", "mesto",
        "zival", "rastlina", "zivljenje", "hrast", "smreka", "javor", "igra", "zivljenje", "deznik", "vrata",
        "cebela", "zima", "poletje", "jesen", "pomlad", "veter", "soncni zahod", "luna", "casopis", "radio",
        "lonec", "prenosnik", "kodiranje", "programiranje", "radiator", "pivo", "vino", "jeger", "vodka", "gin"
};

// Strukture
struct igralecStruktura{
    int id = 0;
    std::string ime = "igralec";
    std::string geslo = "beseda";
    int poskusov = 0;
    float cas = 0;
    std::string ugibanja = "";
};

// Funkcije
void inicializacijaIgralcev(igralecStruktura igralec[]){
    for(int i = 0; i < 5; i++){
        // za vsakega igralca gre skoz
        igralec[i].id = i;
        
        // nastavitev imena
        std::cout<<"Vpisi svoje uporabnisko ime: "; std::cin>>igralec[i].ime;
        
        // generacija gesla
        int x = rand()%100;
        igralec[i].geslo = slovenske_besede[x];
        std::cout<<"Prirejeno geslo je: "<<igralec[i].geslo<<"\n\n";
        
    }
}
void game(igralecStruktura igralec[]){
    // igra
    bool ugotovil = false;
    int poskusov = 0;
    char crka = ' ';
    std::string crkevpisane = "";
    
    std::string geslo_ = "";
    
    
    for(int i = 0; i < 5; i++){
        
        auto start_time = std::chrono::high_resolution_clock::now();
        
        geslo_ = igralec[i].geslo;
        ugotovil = false;
        poskusov = 0;
        crkevpisane = "";
        
        for(int l=0; l<geslo_.length(); l++){
            geslo_[l] = '_';
        }
        
        while(!ugotovil && poskusov < 10){
            
            std::cout<<"\n\n\n\n\n"<<scenariji[poskusov];
            
            if(poskusov < 9){
                std::cout<<"\n\n"<<geslo_<<"\n";
                std::cout<<"\nPoskus: "<<poskusov+1<<"/10\n\nPorabljene crke: "<<crkevpisane<<"\nVpisi crko ("<<igralec[i].ime<<"): ";
                std::cin>>crka;
                crkevpisane += crka+std::string(" ");
                igralec[i].ugibanja += crka+std::string(" ");
                std::cout<<"\n\n";
            }else{
                // ovi cing get
                
                igralec[i].poskusov = 10;
                
                std::cout<<"\n\n\n\nPRITISNI [ENTER] ZA NADALJEVANJE.";
                std::cin.get();
                std::cin.get();
            }
            
            bool jecrka = false;
            for(int j=0; j<igralec[i].geslo.length(); j++){
                if(igralec[i].geslo[j] == crka){
                    geslo_[j]=crka;
                    jecrka = true;
                }
            }
            
            if(jecrka){
                // ostanejo isti poskusi
            }else{
                poskusov++;
            }
            
            if(geslo_ == igralec[i].geslo){
                ugotovil = 1;
                igralec[i].poskusov = poskusov+1;
            };
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
        igralec[i].cas = elapsed_time;
    }
}
void razvstiIgralce(igralecStruktura igralec[]){
    int id;
    std::string ime;
    std::string geslo;
    float cas;
    std::string ugibanja;
    
    for(int i = 0; i < 5; i++){
        for(int j = i; j < 5; j++){
            if(igralec[i].poskusov > igralec[j].poskusov){
                // obrni podatke
                id = igralec[i].id;
                ime = igralec[i].ime;
                geslo = igralec[i].geslo;
                cas = igralec[i].cas;
                ugibanja = igralec[i].ugibanja;

                igralec[i].id = igralec[j].id;
                igralec[i].ime = igralec[j].ime;
                igralec[i].geslo = igralec[j].geslo;
                igralec[i].cas = igralec[j].cas;
                igralec[i].ugibanja = igralec[j].ugibanja;
                
                igralec[j].id = id;
                igralec[j].ime = ime;
                igralec[j].geslo = geslo;
                igralec[j].cas = cas;
                igralec[j].ugibanja = ugibanja;
                
                
            }
        }
    }
}
void izpisRezultatov(igralecStruktura igralec[]){
    std::cout<<"\n\n\n\n\nid - Clovek - geslo - poskusov - cas - uginave crke";
    for(int i=0; i<5; i++){
        std::cout<<"\n"<<igralec[i].id<<" - "<<igralec[i].ime<<" - '"<<igralec[i].geslo<<"' - "<<igralec[i].poskusov<<" - "<<igralec[i].cas<<"s - '"<<igralec[i].ugibanja<<"'";
    }
}
std::string ustvariHtmlNiz(igralecStruktura igralec[]){
    std::string casStr;
    std::string poskusovStr;
    std::string barvaOdzadja;
    
    std::string niz = "<table><tr style='border:1px solid black;'><th>Uporabnik</th><th>Geslo</th><th>Poskusov</th><th>Cas</th></tr>";
    for(int i=0; i<5; i++){
        
        barvaOdzadja = (i % 2 == 0) ? "lightgray" : "white";
        
        poskusovStr = std::to_string(igralec[i].poskusov);
        casStr = std::to_string(igralec[i].cas);
        niz += "<tr style='background-color:" + barvaOdzadja + "'><td>" + igralec[i].ime + "</td><td>" + igralec[i].geslo + "</td><td>" + poskusovStr + "</td><td>" + casStr + " s</td></tr>";
    }
    niz += "</table>";
    
    return niz;
}

int main(int argc, const char * argv[]) {
    // vislice tukaj ...
    srand(static_cast<unsigned int>(time(nullptr)));
    
    igralecStruktura igralec[5]; // inicializacija igralcev
    
    inicializacijaIgralcev(igralec); // zgeneriramo, oz vprašamo po podatkih
    
    game(igralec); // dejanska igra
    
    razvstiIgralce(igralec); // razvrsti igralce
    
    izpisRezultatov(igralec); // izpis tabele c++
    
    std::cout<<"\n\n"<<ustvariHtmlNiz(igralec); // pridobitev in pirkaz HTML niza zmagovalcev
    
    std::cout << "\n\n\n";
    return 0;
}
