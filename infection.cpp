#include <iostream>
using namespace std;
int main(){
    int day,dormant,dead;
    int infected =1;
    for(int i=0;i<day;i++){
        if(dead==0){
            infected = infected * k;
            infected = min(infected, (int)pow(2, dormant));
            dormant += infected;
            infected = new_infected;
        }
        if(i==d+1){
            infected -= 1;
            dormant -= 1;
        }
        if(i==k+1){
            dead = 1;
            infected = 0;
        }
    }
    cout << infected << endl;
}