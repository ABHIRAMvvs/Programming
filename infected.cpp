#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, k;
    cin >> n >> d >> k;

    int infected = 1, dormant = 0, dead = 0;

    for (int i = 1; i <= n; i++) {
        int new_infected = 0;
        if (dead == 0) { // virus is still active
            new_infected = infected * k; // each infected mouse infects k new mice
            new_infected = min(new_infected, (int)pow(2, dormant)); // can infect at most 2^dormant mice
            dormant += infected; // add previously infected mice to dormant count
            infected = new_infected; // update infected count
        }
        if (i == d + 1) { // dormant period is over
            infected -= 1;
            dormant -= 1;
        }
        if (i == k + 1) { // dead period is over
            dead = 1;
            infected = 0;
        }
    }

    cout << infected << endl;
    return 0;
}
