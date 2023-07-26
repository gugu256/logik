#include <iostream>
#include <string>

using namespace std;

// LOGIC GATE STRUCTURE

struct logic_gate {
    int truth_table[4][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 0}
    };

    std::string name = "NONE";

    int eval(int arg1, int arg2) {
        for (int i = 0; i < 4; i++) {
            if (arg1 == truth_table[i][0] && arg2 == truth_table[i][1]) {
                return truth_table[i][2];
            }
        }
        return -1;
    }

    void define_truthtable(int *results) {
        for (int i = 0; i < 4; i++) {
            truth_table[i][2] = results[i];
        }
    }

    void define(std::string gate_name, int *truth_table_results) {
        name = gate_name;
        define_truthtable(truth_table_results);
    }
};



int main() {

    // LOGIC GATES DECLARATIONS

    logic_gate xorgate; // XOR
    int truth_table_results[4] = {0, 1, 1, 0};
    xorgate.define("XOR", truth_table_results);

    // INTERPRETING/TESTING
    int inp1, inp2;
    cout << xorgate.name << endl;
    cin >> inp1;
    cin >> inp2;
    cout << "--> " << xorgate.eval(inp1, inp2) << endl;
    return 0;
}
