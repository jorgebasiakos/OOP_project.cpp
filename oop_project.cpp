#include <iostream>
#include <limits>
#include <math.h>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <unistd.h>

using namespace std;

#define KEY_UP      119   //press w
#define KEY_DOWN    115   //press s
#define KEY_LEFT     97   //press a
#define KEY_RIGHT   100   //press d
#define KEY_PAUSE   112   //press p
#define KEY_EXIT    120   //press x
#define KEY_FILTER  117   //press u

static int magicf = 1;
static int q = 0;
static int death_w = 0;
static int death_v = 0;
static int day_night = 0;

class Map {
private:
    int x, y;
    char team;

public:
    void set_dim_x(int);
    void set_dim_y(int, int);
    void set_team(char);
    
    int get_dim_x() const;
    int get_dim_y() const;
    char get_team() const;
    
};

class Ancestor {
protected:

public:
    virtual void move(int i, int j, char f) = 0;
    virtual ~Ancestor(){} 
};

class Tree : public Ancestor {
public:
    void move(int i, int j, char f) {}
    virtual ~Tree(){}
};

class Water : public Ancestor {
public:
    void move(int i, int j, char f) {}
    virtual ~Water(){}
};

class Filter : public Ancestor {
public:
    void move(int i, int j, char f) {}
    virtual ~Filter(){}
};

class Avatar : public Ancestor {
private:    
    Ancestor*** p;
    string** A;
    Map* arena;
    Filter* hpr7;
    int *magicf;
    

public:
    Avatar(Ancestor*** pp, string** AA, Map *arena1, Filter* hpr7a, int *magicf1)
    {
        p = pp;
        A = AA;
        arena = arena1;
        hpr7 = hpr7a;
        magicf = magicf1;
    }

    virtual ~Avatar(){}

    void move(int i, int j, char f) {
        
        
        //system("clear");
        
        if (f == KEY_DOWN) {
            if(i+2 <= arena->get_dim_x()){
                if (p[i + 1][j] == NULL) {
                    p[i + 1][j] = p[i][j];
                    p[i][j] = NULL;
                    A[i + 1][j] = A[i][j];
                    A[i][j] = { '0', '0', '0' };
                    for (int l = 0; l < arena->get_dim_x(); l++) {
                        for (int m = 0; m < arena->get_dim_y(); m++) {
                            cout << " " << A[l][m];
                        }
                        cout << endl;
                    }
                }
                else if (p[i + 1][j] == hpr7) {
                    (*magicf)++;
                    p[i + 1][j] = p[i][j];
                    p[i][j] = NULL;
                    A[i + 1][j] = A[i][j];
                    A[i][j] = { '0', '0', '0' };
                    for (int l = 0; l < arena->get_dim_x(); l++) {
                        for (int m = 0; m < arena->get_dim_y(); m++) {
                            cout << " " << A[l][m];
                        }
                        cout << endl;
                    }
                }
            

            }
            else {
                cout << "sorry i cannot move :(" << endl;
            }

        }

        if (f == KEY_UP) {
            if(i - 1 >= 0){
                if (p[i - 1][j] == NULL) {
                    p[i - 1][j] = p[i][j];
                    p[i][j] = NULL;
                    A[i - 1][j] = A[i][j];
                    A[i][j] = { '0', '0', '0' };
                    for (int l = 0; l < arena->get_dim_x(); l++) {
                        for (int m = 0; m < arena->get_dim_y(); m++) {
                            cout << " " << A[l][m];
                        }
                        cout << endl;
                    }
                }
                else if (p[i - 1][j] == hpr7) {
                    (*magicf)++;
                    p[i - 1][j] = p[i][j];
                    p[i][j] = NULL;
                    A[i - 1][j] = A[i][j];
                    A[i][j] = { '0', '0', '0' };
                    for (int l = 0; l < arena->get_dim_x(); l++) {
                        for (int m = 0; m < arena->get_dim_y(); m++) {
                            cout << " " << A[l][m];
                        }
                        cout << endl;
                    }
                }
            }
            else {
                cout << "sorry i cannot move :(" << endl;
            }
            
        }

        if (f == KEY_LEFT) {
            if(j-1 >= 0){
                if (p[i][j - 1] == NULL) {
                    p[i][j - 1] = p[i][j];
                    p[i][j] = NULL;
                    A[i][j - 1] = A[i][j];
                    A[i][j] = { '0', '0', '0' };
                    for (int l = 0; l < arena->get_dim_x(); l++) {
                        for (int m = 0; m < arena->get_dim_y(); m++) {
                            cout << " " << A[l][m];
                        }
                        cout << endl;
                    }
                }
                else if (p[i][j - 1] == hpr7) {
                    (*magicf)++;
                    p[i][j - 1] = p[i][j];
                    p[i][j] = NULL;
                    A[i][j - 1] = A[i][j];
                    A[i][j] = { '0', '0', '0' };
                    for (int l = 0; l < arena->get_dim_x(); l++) {
                        for (int m = 0; m < arena->get_dim_y(); m++) {
                            cout << " " << A[l][m];
                        }
                        cout << endl;
                    }
                }
            }       
            else {
                cout << "sorry i cannot move :(" << endl;
            }
        }

        if (f == KEY_RIGHT) {
            if(j+2 <= arena->get_dim_y()){
                if (p[i][j + 1] == NULL) {
                    p[i][j + 1] = p[i][j];
                    p[i][j] = NULL;
                    A[i][j + 1] = A[i][j];
                    A[i][j] = { '0', '0', '0' };
                    for (int l = 0; l < arena->get_dim_x(); l++) {
                        for (int m = 0; m < arena->get_dim_y(); m++) {
                            cout << " " << A[l][m];
                        }
                        cout << endl;
                    }
                }
                else if (p[i][j + 1] == hpr7) {
                    (*magicf)++;
                    p[i][j + 1] = p[i][j];
                    p[i][j] = NULL;
                    A[i][j + 1] = A[i][j];
                    A[i][j] = { '0', '0', '0' };
                    for (int l = 0; l < arena->get_dim_x(); l++) {
                        for (int m = 0; m < arena->get_dim_y(); m++) {
                            cout << " " << A[l][m];
                        }
                        cout << endl;
                    }
                }
            }  
            else {
                cout << "sorry i cannot move :(" << endl;
            }

        }

        if(f == KEY_PAUSE){
            cout << "deaths of W are: " << death_w << endl;
            cout << "deaths of v are: " << death_v << endl;
            cout << "number of filters is: " << *magicf << endl;
            sleep(2);
        }

        if(f == KEY_EXIT){
            cout << "deaths of W are: " << death_w << endl;
            cout << "deaths of v are: " << death_v << endl;
            cout << "number of filters is: " << *magicf << endl;
            exit(1);
        }

        
    }

};

class Werewolf : public Ancestor{
private:
    Ancestor*** p;
    string** A;
    Map* arena;
    Filter* hpr7;
    int giatriko, defence, attack, health;

public:
    Werewolf(Ancestor*** pp, string** AA, Map *arena1, Filter* hpr7a, int a4, int a5, int a6, int a7){
        p = pp;
        A = AA;
        arena = arena1;
        hpr7 = hpr7a;
        giatriko = a4;
        defence = a5;
        attack = a6;
        health = a7;
    }

     virtual ~Werewolf(){}

    friend class Game;

    void set_giatriko(int a12){
        giatriko = a12;
    }
    void set_defence(int a13){
        defence = a13;
    }
    void set_attack(int a14){
        attack = a14;
    }
    void set_health(int a15){
        health = a15;
    }
    int get_giatriko(){ return giatriko; }
    int get_defence(){ return defence; }
    int get_attack(){ return attack; }
    int get_health(){ return health; }

    void move(int i, int j, char f){ 
        cout << "do smth werewolf" << endl; 
        
    }

};

class Vampire : public Ancestor{
private:
    Ancestor*** p;
    string** A;
    Map* arena;
    Filter* hpr7;
    int giatriko, defence, attack, health;

public:
    Vampire(Ancestor*** pp, string** AA, Map *arena1, Filter* hpr7a, int a8, int a9, int a10, int a11){
        p = pp;
        A = AA;
        arena = arena1;
        hpr7 = hpr7a;
        giatriko = a8;
        defence = a9;
        attack = a10;
        health = a11;
    }

    virtual ~Vampire(){}

    friend class Game;

    void set_giatriko(int a16){
        giatriko = a16;
    }
    void set_defence(int a17){
        defence = a17;
    }
    void set_attack(int a18){
        attack = a18;
    }
    void set_health(int a19){
        health = a19;
    }
    int get_giatriko(){ return giatriko; }
    int get_defence(){ return defence; }
    int get_attack(){ return attack; }
    int get_health(){ return health; }

	void move(int i, int j, char f ){ 
        cout << "do smth vimpire" << endl;

    }

};


void Map::set_dim_x(int a1) {
    try {
        if (a1 >= 4 && a1 <= 65) {
            x = a1;
        }
        else {
            throw (invalid_argument("something is not right"));
        }
    }
    catch (invalid_argument& inpt) {
        cerr << inpt.what() << endl;
        q++;
    }
}

void Map::set_dim_y(int a2, int a3) {
    try {
        if (a2 >= 4 && a2 <= 65 && a3 * a2 >= 60 && a3 * a2 <= 260) {
            y = a2;
        }
        else {
            throw (invalid_argument("something is not right"));
        }
    }
    catch (invalid_argument& inpt) {
        cerr << inpt.what() << endl;
        q++;
    }
}

void Map::set_team(char ch) {
    try {
        if (ch == 'w' || ch == 'v') {
            team = ch;
        }
        else {
            throw (invalid_argument("something is not right"));
        }
    }
    catch (invalid_argument& inpt) {
        cerr << inpt.what() << endl;
        q++;
    }


}


int Map::get_dim_x() const {
    return x;
}

int Map::get_dim_y() const {
    return y;
}

char Map::get_team() const {
    return team;
}


class Game{
private:  
    Ancestor ***p;
    string** A;
    Map* arena;
    Werewolf **hpr1;
    Vampire **hpr2;
public:
    Game(Ancestor ***pp, string** AA, Map *arena1, Werewolf **ppp, Vampire **pppp){
        p = pp;
        A = AA;
        arena = arena1;
        hpr1 = ppp;
        hpr2 = pppp;
    }

    ~Game(){}

    int k, x, l, m, newhealth;
    void play(int i, int j, int n, int pl){
        
        if(p[i][j] == hpr1[n]){                         //if werewolf

            x = rand() % 4;

            if(x == 0){                                 //koita katw
                if(i+2 <= arena -> get_dim_x()){
                    if(p[i+1][j] == NULL){              //if kenh thesh
                        p[i+1][j] = p[i][j];
                        p[i][j] = NULL;
                        A[i+1][j] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }            
                    }
                    for(k = 0; k < pl; k++){
                        if(p[i+1][j] == hpr1[k]){                      //if another werewolf w2
                            if( hpr1[n] -> health < 3 ){               //if w1.h < 3
                                if( hpr1[k] -> giatriko > 0 ){          //if w2.g > 0

                                    hpr1[n] -> set_health(hpr1[n] -> health + 1);
                                    hpr1[k] -> set_giatriko(hpr1[k] -> giatriko - 1); 

                                }
                            }

                            if( hpr1[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr1[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr1[k] -> set_health(hpr1[k] -> health + 1);
                                    hpr1[n] -> set_giatriko(hpr1[n] -> giatriko -1);
                                
                                }
                            }
                        }

                        if(p[i+1][j] == hpr2[k]){                      //if V => W vs V
                            if(hpr1[n] -> get_attack() >= hpr2[k] -> get_attack()){

                                newhealth = hpr2[k] -> get_health() - abs( hpr2[k] -> get_defence() - hpr1[n] -> get_attack() );
                                hpr2[k] -> set_health(newhealth);

                            }

                            if(hpr2[k] -> health <= 0){

                                death_v++;
                                p[i+1][j] = p[i][j];
                                A[i+1][j] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }



                        }
                        
                    }

                }

                
            }

            if(x == 1){                                 //koita panw
                if(i-1 >= 0){
                    if(p[i-1][j] == NULL){   //if kenh thesh
                        p[i-1][j] = p[i][j];
                        p[i][j] = NULL;
                        A[i-1][j] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }
                    }
                    for(k = 0; k < pl; k++){
                        if(p[i-1][j] == hpr1[k]){
                            if( hpr1[n] -> health < 3 ){               //if w1.h < 3
                                if( hpr1[k] -> giatriko > 0 ){          //if w2.g > 0

                                    hpr1[n] -> set_health(hpr1[n] -> health + 1);
                                    hpr1[k] -> set_giatriko(hpr1[k] -> giatriko - 1); 

                                }
                            }

                            if( hpr1[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr1[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr1[k] -> set_health(hpr1[k] -> health + 1);
                                    hpr1[n] -> set_giatriko(hpr1[n] -> giatriko -1);
                                
                                }
                            }
                        }

                        if(p[i-1][j] == hpr2[k]){
                            if(hpr1[n] -> get_attack() >= hpr2[k] -> get_attack()){

                                newhealth = hpr2[k] -> get_health() - abs( hpr2[k] -> get_defence() - hpr1[n] -> get_attack() );
                                hpr2[k] -> set_health(newhealth);

                            }

                            if(hpr2[k] -> health <= 0){

                                death_v++;
                                p[i-1][j] = p[i][j];
                                A[i-1][j] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }
                        }
                    }
                }





            }

            if(x == 2){                                 //koita aristera
                if(j-1 >= 0){
                    if(p[i][j-1] == NULL){
                        p[i][j-1] = p[i][j];
                        p[i][j] = NULL;
                        A[i][j-1] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }
                    }
                    for(k = 0; k < pl; k++){
                        if(p[i][j-1] == hpr1[k]){
                            if( hpr1[n] -> health < 3 ){               //if w1.h < 3
                                if( hpr1[k] -> giatriko > 0 ){          //if w2.g > 0

                                    hpr1[n] -> set_health(hpr1[n] -> health + 1);
                                    hpr1[k] -> set_giatriko(hpr1[k] -> giatriko - 1); 

                                }
                            }

                            if( hpr1[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr1[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr1[k] -> set_health(hpr1[k] -> health + 1);
                                    hpr1[n] -> set_giatriko(hpr1[n] -> giatriko -1);
                                
                                }
                            }
                        }

                        if(p[i][j-1] == hpr2[k]){
                            if(hpr1[n] -> get_attack() >= hpr2[k] -> get_attack()){

                                newhealth = hpr2[k] -> get_health() - abs( hpr2[k] -> get_defence() - hpr1[n] -> get_attack() );
                                hpr2[k] -> set_health(newhealth);

                            }

                            if(hpr2[k] -> health <= 0){

                                death_v++;
                                p[i][j-1] = p[i][j];
                                A[i][j-1] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }
                        }
                    }
                }
                




            }

            if(x == 3){
                if(j+2 <= arena -> get_dim_y()){
                    if(p[i][j+1] == NULL){
                        p[i][j+1] = p[i][j];
                        p[i][j] = NULL;
                        A[i][j+1] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }
                    }
                    for(k = 0; k < pl; k++){
                        if(p[i][j+1] == hpr1[k]){
                            if( hpr1[k] -> giatriko > 0 ){          //if w2.g > 0

                                hpr1[n] -> set_health(hpr1[n] -> health + 1);
                                hpr1[k] -> set_giatriko(hpr1[k] -> giatriko - 1); 

                            }

                            if( hpr1[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr1[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr1[k] -> set_health(hpr1[k] -> health + 1);
                                    hpr1[n] -> set_giatriko(hpr1[n] -> giatriko -1);
                                
                                }
                            }
                        }
                    
                        if(p[i][j+1] == hpr2[k]){
                            if(hpr1[n] -> get_attack() >= hpr2[k] -> get_attack()){

                                newhealth = hpr2[k] -> get_health() - abs( hpr2[k] -> get_defence() - hpr1[n] -> get_attack() );
                                hpr2[k] -> set_health(newhealth);

                            }

                            if(hpr2[k] -> health <= 0){

                                death_v++;
                                p[i][j+1] = p[i][j];
                                A[i][j+1] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }
                        }
                    }
                }
            }
  
        }


        if(p[i][j] == hpr2[n]){                          //if vampire

            x = rand() % 8;

            if( x == 0 ){
                if(i+2 <= arena -> get_dim_x()){
                    if(p[i+1][j] == NULL){              //if kenh thesh
                        p[i+1][j] = p[i][j];
                        p[i][j] = NULL;
                        A[i+1][j] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }            
                    }
                    for(k = 0; k<pl; k++){
                        if(p[i+1][j] == hpr2[k]){
                            if( hpr2[n] -> health < 3 ){               //if w1.h < 3
                                if( hpr2[k] -> giatriko > 0 ){          //if w2.g > 0

                                    hpr2[n] -> set_health(hpr2[n] -> health + 1);
                                    hpr2[k] -> set_giatriko(hpr2[k] -> giatriko - 1); 

                                }
                            }

                            if( hpr2[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr2[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr2[k] -> set_health(hpr2[k] -> health + 1);
                                    hpr2[n] -> set_giatriko(hpr2[n] -> giatriko -1);
                                
                                }
                            }
                        }

                        if(p[i+1][j] == hpr1[k]){
                            if(hpr2[n] -> get_attack() >= hpr1[k] -> get_attack()){

                                newhealth = hpr1[k] -> get_health() - abs( hpr1[k] -> get_defence() - hpr2[n] -> get_attack() );
                                hpr1[k] -> set_health(newhealth);

                            }

                            if(hpr1[k] -> health <= 0){

                                death_w++;
                                p[i+1][j] = p[i][j];
                                A[i+1][j] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }
                        }
                    }


                }
            }

            if( x == 1 ){
                if(i-1 >= 0){
                    if(p[i-1][j] == NULL){   //if kenh thesh
                        p[i-1][j] = p[i][j];
                        p[i][j] = NULL;
                        A[i-1][j] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }
                    }
                    for(k = 0; k < pl; k++){
                        if(p[i-1][j] == hpr2[k]){
                            if( hpr2[n] -> health < 3 ){               //if w1.h < 3
                                if( hpr2[k] -> giatriko > 0 ){          //if w2.g > 0

                                    hpr2[n] -> set_health(hpr2[n] -> health + 1);
                                    hpr2[k] -> set_giatriko(hpr2[k] -> giatriko - 1); 

                                }
                            }

                            if( hpr2[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr2[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr2[k] -> set_health(hpr2[k] -> health + 1);
                                    hpr2[n] -> set_giatriko(hpr2[n] -> giatriko -1);
                                
                                }
                            }
                        }

                        if(p[i-1][j] == hpr1[k]){
                            if(hpr2[n] -> get_attack() >= hpr1[k] -> get_attack()){

                                newhealth = hpr1[k] -> get_health() - abs( hpr1[k] -> get_defence() - hpr2[n] -> get_attack() );
                                hpr1[k] -> set_health(newhealth);

                            }

                            if(hpr1[k] -> health <= 0){

                                death_w++;
                                p[i-1][j] = p[i][j];
                                A[i-1][j] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }
                        }
                    }
                }




            }

            if( x == 2 ){
                if(j-1 >= 0){
                    if(p[i][j-1] == NULL){
                        p[i][j-1] = p[i][j];
                        p[i][j] = NULL;
                        A[i][j-1] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }
                    }
                    for(k = 0; k < pl; k++){
                        if(p[i][j-1] == hpr2[k]){
                            if( hpr2[n] -> health < 3 ){               //if w1.h < 3
                                if( hpr2[k] -> giatriko > 0 ){          //if w2.g > 0

                                    hpr2[n] -> set_health(hpr2[n] -> health + 1);
                                    hpr2[k] -> set_giatriko(hpr2[k] -> giatriko - 1); 

                                }
                            }

                            if( hpr2[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr2[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr2[k] -> set_health(hpr2[k] -> health + 1);
                                    hpr2[n] -> set_giatriko(hpr2[n] -> giatriko -1);
                                
                                }
                            }
                        }

                        if(p[i][j-1] == hpr1[k]){
                            if(hpr2[n] -> get_attack() >= hpr1[k] -> get_attack()){

                                newhealth = hpr1[k] -> get_health() - abs( hpr1[k] -> get_defence() - hpr2[n] -> get_attack() );
                                hpr1[k] -> set_health(newhealth);

                            }

                            if(hpr1[k] -> health <= 0){

                                death_w++;
                                p[i][j-1] = p[i][j];
                                A[i][j-1] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }
                        }
                    } 
                }


            }

            if( x == 3 ){
                if(j+2 <= arena -> get_dim_y()){
                   if(p[i][j+1] == NULL){
                        p[i][j+1] = p[i][j];
                        p[i][j] = NULL;
                        A[i][j+1] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }
                    } 
                    for(k = 0; k < pl; k++){
                        if(p[i][j+1] == hpr2[k]){
                            if( hpr2[k] -> giatriko > 0 ){          //if w2.g > 0

                                hpr2[n] -> set_health(hpr2[n] -> health + 1);
                                hpr2[k] -> set_giatriko(hpr2[k] -> giatriko - 1); 

                            }

                            if( hpr2[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr2[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr2[k] -> set_health(hpr2[k] -> health + 1);
                                    hpr2[n] -> set_giatriko(hpr2[n] -> giatriko -1);
                                
                                }
                            }
                        }

                        if(p[i][j+1] == hpr1[k]){
                            if(hpr2[n] -> get_attack() >= hpr1[k] -> get_attack()){

                                newhealth = hpr1[k] -> get_health() - abs( hpr1[k] -> get_defence() - hpr2[n] -> get_attack() );
                                hpr1[k] -> set_health(newhealth);

                            }

                            if(hpr1[k] -> health <= 0){

                                death_w++;
                                p[i][j+1] = p[i][j];
                                A[i][j+1] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }
                        }
                    }
                }
                
            

            }           

            if( x == 4 ){
                if(i-1 >= 0 && j-1 >= 0){
                    if(p[i-1][j-1] == NULL){              //if kenh thesh
                        p[i-1][j-1] = p[i][j];
                        p[i][j] = NULL;
                        A[i-1][j-1] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }            
                    }
                    for(k = 0; k<pl; k++){
                        if(p[i-1][j-1] == hpr2[k]){
                            if( hpr2[n] -> health < 3 ){               //if w1.h < 3
                                if( hpr2[k] -> giatriko > 0 ){          //if w2.g > 0

                                    hpr2[n] -> set_health(hpr2[n] -> health + 1);
                                    hpr2[k] -> set_giatriko(hpr2[k] -> giatriko - 1); 

                                }
                            }

                            if( hpr2[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr2[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr2[k] -> set_health(hpr2[k] -> health + 1);
                                    hpr2[n] -> set_giatriko(hpr2[n] -> giatriko -1);
                                
                                }
                            }                            
                        }

                        if(p[i-1][j-1] == hpr1[k]){
                            if(hpr2[n] -> get_attack() >= hpr1[k] -> get_attack()){

                                newhealth = hpr1[k] -> get_health() - abs( hpr1[k] -> get_defence() - hpr2[n] -> get_attack() );
                                hpr1[k] -> set_health(newhealth);

                            }

                            if(hpr1[k] -> health <= 0){

                                death_w++;
                                p[i-1][j-1] = p[i][j];
                                A[i-1][j-1] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }

                        }
                    }               
               
                }


                
            }

            if( x == 5 ){
                if(i-1 >= 0 && j+2 <= arena->get_dim_y()){
                    if(p[i-1][j+1] == NULL){              //if kenh thesh
                        p[i-1][j+1] = p[i][j];
                        p[i][j] = NULL;
                        A[i-1][j+1] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }           
                    }
                    for(k = 0; k<pl; k++){
                        if(p[i-1][j+1] == hpr2[k]){
                            if( hpr2[n] -> health < 3 ){               //if w1.h < 3
                                if( hpr2[k] -> giatriko > 0 ){          //if w2.g > 0

                                    hpr2[n] -> set_health(hpr2[n] -> health + 1);
                                    hpr2[k] -> set_giatriko(hpr2[k] -> giatriko - 1); 

                                }
                            }

                            if( hpr2[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr2[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr2[k] -> set_health(hpr2[k] -> health + 1);
                                    hpr2[n] -> set_giatriko(hpr2[n] -> giatriko -1);
                                
                                }
                            }
                        }

                        if(p[i-1][j+1] == hpr1[k]){
                            if(hpr2[n] -> get_attack() >= hpr1[k] -> get_attack()){

                                newhealth = hpr1[k] -> get_health() - abs( hpr1[k] -> get_defence() - hpr2[n] -> get_attack() );
                                hpr1[k] -> set_health(newhealth);

                            }

                            if(hpr1[k] -> health <= 0){

                                death_w++;
                                p[i-1][j+1] = p[i][j];
                                A[i-1][j+1] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }
                        }
                    }
                }
            }

            if( x == 6 ){
                if(i+2 <= arena -> get_dim_x() && j-1 >= 0){
                    if(p[i+1][j-1] == NULL){              //if kenh thesh
                        p[i+1][j-1] = p[i][j];
                        p[i][j] = NULL;
                        A[i+1][j-1] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }            
                    }
                    for(k = 0; k<pl; k++){
                        if(p[i+1][j-1] == hpr2[k]){
                           if( hpr2[n] -> health < 3 ){               //if w1.h < 3
                                if( hpr2[k] -> giatriko > 0 ){          //if w2.g > 0

                                    hpr2[n] -> set_health(hpr2[n] -> health + 1);
                                    hpr2[k] -> set_giatriko(hpr2[k] -> giatriko - 1); 

                                }
                            }

                            if( hpr2[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr2[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr2[k] -> set_health(hpr2[k] -> health + 1);
                                    hpr2[n] -> set_giatriko(hpr2[n] -> giatriko -1);
                                
                                }
                            } 
                        }

                        if(p[i+1][j-1] == hpr1[k]){
                            if(hpr2[n] -> get_attack() >= hpr1[k] -> get_attack()){

                                newhealth = hpr1[k] -> get_health() - abs( hpr1[k] -> get_defence() - hpr2[n] -> get_attack() );
                                hpr1[k] -> set_health(newhealth);

                            }

                            if(hpr1[k] -> health <= 0){

                                death_w++;
                                p[i+1][j-1] = p[i][j];
                                A[i+1][j-1] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }
                        }
                    }


                }
            }

            if( x == 7 ){
                if(i+2 <= arena -> get_dim_x() && j+2 <= arena -> get_dim_y()){
                    if(p[i+1][j+1] == NULL){              //if kenh thesh
                        p[i+1][j+1] = p[i][j];
                        p[i][j] = NULL;
                        A[i+1][j+1] = A[i][j];
                        A[i][j] = {'0', '0', '0'};
                        for ( l=0; l<arena -> get_dim_x(); l++ ){
                            for(m=0; m<arena -> get_dim_y(); m++){
                                cout << " " << A[l][m];    
                            }
                            cout << endl;
                        }            
                    }
                    for(k = 0; k<pl; k++){
                        if(p[i+1][j+1] == hpr2[k]){
                            if( hpr2[n] -> health < 3 ){               //if w1.h < 3
                                if( hpr2[k] -> giatriko > 0 ){          //if w2.g > 0

                                    hpr2[n] -> set_health(hpr2[n] -> health + 1);
                                    hpr2[k] -> set_giatriko(hpr2[k] -> giatriko - 1); 

                                }
                            }

                            if( hpr2[k] -> health < 3 ){               //if w2.h < 3
                                if(hpr2[n] -> giatriko > 0){            //if w1.g > 0

                                    hpr2[k] -> set_health(hpr2[k] -> health + 1);
                                    hpr2[n] -> set_giatriko(hpr2[n] -> giatriko -1);
                                
                                }
                            }
                        }

                        if(p[i+1][j+1] == hpr1[k]){
                            if(hpr2[n] -> get_attack() >= hpr1[k] -> get_attack()){

                                newhealth = hpr1[k] -> get_health() - abs( hpr1[k] -> get_defence() - hpr2[n] -> get_attack() );
                                hpr1[k] -> set_health(newhealth);

                            }

                            if(hpr1[k] -> health <= 0){

                                death_w++;
                                p[i+1][j+1] = p[i][j];
                                A[i+1][j+1] = A[i][j];
                                p[i][j] = NULL;
                                A[i][j] = {'0', '0', '0'};

                            }

                            for ( l=0; l<arena -> get_dim_x(); l++ ){
                                for(m=0; m<arena -> get_dim_y(); m++){
                                    cout << " " << A[l][m];    
                                }
                                cout << endl;
                            }
                        }
                    }
                }


            }

        }

    }

}; 


int main() {

    srand(time(NULL));

    int dimx, dimy;
    char myteam;
    Map arena;
    int l = 0, m = 0;
    
    cout << "select x dimension. Must x >= 4 and x <=65" << endl;
    cin >> dimx;

    arena.set_dim_x(dimx);
    if (q) return 0;

    cout << "select y dimension. Must y >= 4 and y <=65 and x*y >= 60 and x*y <= 260" << endl;
    cin >> dimy;

    arena.set_dim_y(dimy, dimx);
    if (q) return 0;

    cout << "select your team, between werewolfs ('w') and vimpires ('v'):" << endl;
    cin >> myteam;

    arena.set_team(myteam);
    if (q) return 0;

    cout << "Your arena is a: " << arena.get_dim_x() << "*"
        << arena.get_dim_y() << " box" << endl;
    cout << "Your team is: " << arena.get_team() << endl;

    ///////////////////////////////////////////////////////////////////////////////////        x and y and team are ready

    int crowd, crowd_w, crowd_v, crowd_tr, crowd_wa;

    crowd = dimx * dimy / 15;
    crowd_w = crowd / 2;
    crowd_v = crowd_w;
    crowd_tr = crowd_w;
    crowd_wa = crowd_w;
    cout << "crowd_w is:" << crowd_w << endl <<
        "crowd_v is:" << crowd_v << endl <<
        "crowd_tr is:" << crowd_tr << endl <<
        "crowd_wa is:" << crowd_wa << endl;

    sleep(2);

    ///////////////////////////////////////////////////////////////////////////////////         crowd_x and crowd_y are ready
    Ancestor*** p = new Ancestor**[arena.get_dim_x()];
    for(int i =0 ; i< arena.get_dim_x(); i++)
        p[i] = new Ancestor * [arena.get_dim_y()];


    string** A = new string*[arena.get_dim_x()];
    for (int i = 0; i < arena.get_dim_x(); i++)
        A[i] = new string[arena.get_dim_y()];    

    Ancestor* hpr4[4 * crowd_v + 2];
    Werewolf* hpr1[crowd_tr];
    Vampire* hpr2[crowd_tr];
    Avatar* hpr3;
    Tree* hpr5[crowd_w];
    Water* hpr6[crowd_w];
    Filter* hpr7;
    hpr7 = new Filter();
    hpr3 = new Avatar(p, A, &arena, hpr7, &magicf);
    string B[4 * crowd_v + 2];

    int i, j, a, b, c, n;


    for (i = 0; i < crowd_v; i++) {                                         // o hpr1 exei ta werewolfs
        hpr1[i] = new Werewolf(p, A, &arena, hpr7, rand() % 3, 1 + rand() % 2, 1 + rand() % 3, 3);
        hpr4[i] = hpr1[i];
        B[i] = { 'w','e', (char)(i + 97) };
    }

    for (i = 0; i < crowd_v; i++) {                                         // o hpr2 exei ta vampires
        hpr2[i] = new Vampire(p, A, &arena, hpr7, rand() % 3, 1 + rand() % 2, 1 + rand() % 3, 3);
        hpr4[crowd_v + i] = hpr2[i];
        B[crowd_v + i] = { 'v','a', (char)(i + 97) };
    }

            

    for (i = 0; i < crowd_v; i++) {                                         // o hpr5 exei ta trees
        hpr5[i] = new Tree();
        hpr4[2 * crowd_v + i] = hpr5[i];
        B[2 * crowd_v + i] = { 't','r', (char)(i + 97) };
    }

    for (i = 0; i < crowd_v; i++) {                                         // o hpr6 exei ta waters
        hpr6[i] = new Water();
        hpr4[3 * crowd_v + i] = hpr6[i];
        B[3 * crowd_v + i] = { 'w','a', (char)(i + 97) };
    }

    hpr4[4 * crowd_v] = hpr3;
    B[4 * crowd_v] = { 'a', 'v', 'a' };

    hpr4[4 * crowd_v + 1] = hpr7;
    B[4 * crowd_v + 1] = { 'f', 'f', 'f' };

    for (i = 0; i < 4 * crowd_v + 2; i++) {                         // o hpr4 {werewolfs, vampires, trees, waters, avatar, filter}
        cout << B[i] << endl;                                   // o B {werewolfs, vampires, trees, waters, avatar, filter}
    }

    //////////////////////////////////////////////////

    for (i = 0; i < arena.get_dim_x(); i++) {
        for (j = 0; j < arena.get_dim_y(); j++) {
            p[i][j] = NULL;
        }
    }

    for (i = 0; i < arena.get_dim_x(); i++) {
        for (j = 0; j < arena.get_dim_y(); j++) {
            A[i][j] = { '0', '0', '0' };
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////

    string str1 = A[1][1];

    for (a = 0; a < 4 * crowd_v + 2; a++) {                                                    ///////tyxaia topothethsh se pinaka

        if (a == 0) {
            b = rand() % dimx;
            c = rand() % dimy;
            A[b][c] = B[a];
            p[b][c] = hpr4[a];
        }
        else {
            b = rand() % dimx;
            c = rand() % dimy;
            string str2 = A[b][c];

            if (str1 != str2) {
                while (str1 != str2) {
                    b = rand() % dimx;
                    c = rand() % dimy;
                    str2 = A[b][c];

                }
                A[b][c] = B[a];
                p[b][c] = hpr4[a];
            }
            else {
                A[b][c] = B[a];
                p[b][c] = hpr4[a];
            }
        }
    }


    /////////////////////////////////////////////////////////////////////////////////////////////        petyxa hpr4[i] === B[i]


    for (i = 0; i < arena.get_dim_x(); i++) {                                                 /////1h ektypvsh pinaka
        for (j = 0; j < arena.get_dim_y(); j++) {
            cout << " " << A[i][j];
        }
        cout << endl;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////

    Game *hpr8;
    hpr8 = new Game(p, A, &arena, hpr1, hpr2);
    char ff = 'f';
    int kk;

    while (death_w != crowd_tr && death_v != crowd_tr) {

        day_night++;

        for (i = 0; i < arena.get_dim_x(); i++) {
            for (j = 0; j < arena.get_dim_y(); j++) {
                if (p[i][j] != NULL) {

                    if (p[i][j] == hpr3) {          // if avatar
                        cout << "Avatar is going to move " << endl; 
                        cin >> ff;

                        if(ff == KEY_FILTER){
                            if(myteam == 'w' && day_night % 2 == 0){
                                magicf--;
                                for(kk=0; kk<crowd_tr; kk++){
                                    hpr1[kk] -> set_health(3);       
                                }
                                cout << "magicf in action for Werewolfs!" << endl;
                                sleep(2);
                            }

                            if(myteam == 'v'){
                                magicf--;
                                for(kk=0; kk<crowd_tr; kk++){
                                    hpr2[kk] -> set_health(3);       
                                }
                                cout << "magicf in action for Vampires!" << endl;
                                sleep(2);
                            }

                        }
                        else{
                            hpr3->move(i, j, ff);
                        }
                        
                        
                    }                               // end if avatar

                    for(n=0; n<crowd_tr; n++){     // if werewolf or vampire 
                         if( p[i][j] == hpr1[n] || p[i][j] == hpr2[n] ){
                            
                            p[i][j] -> move(i,j,ff);
                            hpr8 -> play(i,j, n, crowd_tr);

                        }
                    }                              //werewolf or vampire
                }

            }

        }

        if(death_w == crowd_tr){
            cout << "vimpires are winners" << endl;
        }

        if(death_v == crowd_tr){
            cout << "werewolfs are winners" << endl;
        }
        

    }

    cout << "Game ends after : " << day_night << " " << "repeats" << endl;

    return 0;
}