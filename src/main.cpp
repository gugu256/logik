#include <iostream>
#include <string>

using namespace std;

// BASIC LOGIC GATE STRUCTURE

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

// STRUCTURE FOR A 1 INPUT LOGIC GATE

struct logic_gate_1 {
    int truth_table[2][2] = {
        {0, 0},
        {0, 0}
    };

    std::string name = "NONE1";

    int eval(int arg1) {
        for (int i = 0; i < 2; i++) {
            if (arg1 == truth_table[i][0]) {
                return truth_table[i][1];
            }
        }
        return -1;
    }

    void define_truthtable(int *results) {
        for (int i = 0; i < 2; i++) {
            truth_table[i][1] = results[i];
        }
    }

    void define(std::string gate_name, int *truth_table_results) {
        name = gate_name;
        define_truthtable(truth_table_results);
    }
};



int main() {

    // LOGIC GATES DECLARATIONS

    logic_gate orgate; // NOT
    int truth_table_results[4] = {1, 0};
    orgate.define("NO", truth_table_results); // IM HERE

    logic_gate orgate; // AND
    int truth_table_results[4] = {0, 0, 0, 1};
    orgate.define("AND", truth_table_results);

    logic_gate orgate; // OR
    int truth_table_results[4] = {0, 1, 1, 1};
    orgate.define("OR", truth_table_results);

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
