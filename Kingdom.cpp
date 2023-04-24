#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // initialize variables
    string input;
    map<char, int> gems;
    map<char, int>::iterator it;
    int count;

    // read input
    getline(cin, input);

    // iterate over input
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        // check if character is a gem
        if (isalpha(c)) {
            // increment gem count
            gems[c]++;

            // check if gem count is greater than 1
            if (gems[c] > 1) {
                // append count to gem
                input[i] = gems[c] + '0';
            }
        }
        // check if character is a box
        else if (c == '$' || c == '%' || c == '&' || c == '#' || c == '*') {
            // find corresponding lid
            char lid;
            switch (c) {
                case '$': lid = ';'; break;
                case '%': lid = ':'; break;
                case '&': lid = ','; break;
                case '#': lid = '.'; break;
                case '*': lid = '+'; break;
            }

            // count number of gems inside box
            count = 0;
            for (int j = i + 1; j < input.length(); j++) {
                if (input[j] == c) {
                    count++;
                }
                else if (input[j] == lid) {
                    // check if count is a multiple of a number
                    int multiple = -1;
                    if (count > 1) {
                        for (int k = 2; k <= count; k++) {
                            if (count % k == 0) {
                                multiple = k;
                                break;
                            }
                        }
                    }

                    // append count and multiple (if applicable) to box
                    input[i] = count + '0';
                    if (multiple > 0) {
                        input[j] = 'x';
                        input.insert(j + 1, to_string(multiple));
                    }

                    // update iterator
                    it = gems.begin();

                    // iterate over gems
                    while (it != gems.end()) {
                        // check if gem count is greater than 1
                        if (it->second > 1) {
                            // append count to gem
                            for (int k = 0; k < input.length(); k++) {
                                if (input[k] == it->first) {
                                    input[k] = it->first + to_string(it->second);
                                }
                            }
                        }
                        it++;
                    }

                    // break out of inner loop
                    break;
                }
            }
        }
    }

    // create sorted output string
    string output;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (gems.count(c) > 0) {
            output += c;
            if (gems[c] > 1) {
                output += to_string(gems[c]);
            }
        }
    }

    // output result
    cout << output << endl;

    return 0;
}
