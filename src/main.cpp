#include <iostream>
#include <string>
#include <vector>

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
        {1, 0}
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



void tokenize(std::string code) {
    std::vector<std::string> toks;
    string tok = "";
    cout << code << "\n";
    for (int i = 0; i < code.size(); i++) {
        tok += code[i];
        if (tok == ">") {
            toks.push_back("INDXUP");
            tok = "";
        } else if (tok == "<") {
            toks.push_back("INDXDOWN");
            tok = "";
        } else if (tok == "+") {
            toks.push_back("PLUS");
            tok = "";
        } else if (tok == "-") {
            toks.push_back("MINUS");
            tok = "";
        } else if (tok == "NOT" or tok == "not") {
            toks.push_back("NOTGATE");
            tok = "";
        }
    }
    for (int i = 0; i < toks.size(); i++) {
        cout << toks[i] << ", ";
    }
}

int main() {

    // LOGIC GATES DECLARATIONS

    logic_gate_1 notgate; // NOT
    int not_truth_table_results[2] = {1, 0};
    notgate.define("NOT", not_truth_table_results); // IM HERE

    logic_gate andgate; // AND
    int and_truth_table_results[4] = {0, 0, 0, 1};
    andgate.define("AND", and_truth_table_results);

    logic_gate orgate; // OR
    int or_truth_table_results[4] = {0, 1, 1, 1};
    orgate.define("OR", or_truth_table_results);

    logic_gate xorgate; // XOR
    int xor_truth_table_results[4] = {0, 1, 1, 0};
    xorgate.define("XOR", xor_truth_table_results);

    // INTERPRETING/TESTING
    /*std::string code;
    do {
        cout << ">>> ";
        cin >> code;
        tokenize(code);
    } while (code != "quit");*/
    int inp1, inp2;
    cin >> inp1;
    cin >> inp2;
    cout << "\n" << notgate.name << "\n";
    cout << notgate.eval(inp1) << "\n";
    cout << "\n" << andgate.name << "\n";
    cout << andgate.eval(inp1, inp2) << "\n";
    cout << "\n" << orgate.name << "\n";
    cout << orgate.eval(inp1, inp2) << "\n";
    cout << "\n" << xorgate.name << "\n";
    cout << xorgate.eval(inp1, inp2) << "\n";
    return 0;
}

