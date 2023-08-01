#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

//using namespace std;

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



std::vector<std::string> tokenize(std::string code) {
    code += "\n";
    std::vector<std::string> toks;
    std::string tok = "";
    std::string num = "";
    bool innum = false;
    for (int i = 0; i < code.size(); i++) {
        tok += code[i];
        if (tok == " " or tok == "\n" or tok == "\t") {
            if (num != "") {
                toks.push_back(num);
                num = "";
                innum = false;
            }
            tok = "";
        } else if (tok == ">") {
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
        } else if (tok == "NOT") {
            toks.push_back("NOTGATE");
            tok = "";
        } else if (tok == "BUF") {
            toks.push_back("BUFGATE");
            tok = "";
        } else if (tok == "AND") {
            toks.push_back("ANDGATE");
            tok = "";
        } else if (tok == "NAND") {
            toks.push_back("NANDGATE");
            tok = "";
        } else if (tok == "NOR") {
            toks.push_back("NORGATE");
            tok = "";
        } else if (tok == "OR") {
            toks.push_back("ORGATE");
            tok = "";
        } else if (tok == "XOR") {
            toks.push_back("XORGATE");
            tok = "";
        } else if (tok == "XNOR") {
            toks.push_back("XNORGATE");
            tok = "";
        } else if (tok == ".") {
            toks.push_back("PRINT");
            tok = "";
        } else if (tok == ",") {
            toks.push_back("INPUT");
            tok = "";
        } else if (tok == "0" or tok == "1" or tok == "2" or tok == "3" or tok == "4" or tok == "5" or tok == "6" or tok == "7" or tok == "8" or tok == "9") {
            if (innum) {
                num += tok;
                tok = "";
            } else {
                innum = true;
                num += tok;
                tok = "";
            }
        }
    }
    return toks;
}

void interpret(std::vector<std::string> tokens) {
    // LOGIC GATES DECLARATIONS

    logic_gate_1 notgate; // NOT
    int not_truth_table_results[2] = {1, 0};
    notgate.define("NOT", not_truth_table_results);

    logic_gate_1 bufgate; // BUF
    int buf_truth_table_results[2] = {0, 1};
    bufgate.define("BUF", buf_truth_table_results);

    logic_gate andgate; // AND
    int and_truth_table_results[4] = {0, 0, 0, 1};
    andgate.define("AND", and_truth_table_results);

    logic_gate nandgate; // NAND
    int nand_truth_table_results[4] = {1, 1, 1, 0};
    nandgate.define("NAND", nand_truth_table_results);

    logic_gate norgate; // NOR
    int nor_truth_table_results[4] = {1, 0, 0, 0};
    norgate.define("NOR", nor_truth_table_results);

    logic_gate orgate; // OR
    int or_truth_table_results[4] = {0, 1, 1, 1};
    orgate.define("OR", or_truth_table_results);

    logic_gate xorgate; // XOR
    int xor_truth_table_results[4] = {0, 1, 1, 0};
    xorgate.define("XOR", xor_truth_table_results);

    logic_gate xnorgate; // XNOR
    int xnor_truth_table_results[4] = {1, 0, 0, 1};
    xnorgate.define("XNOR", xnor_truth_table_results);

    int data[256];
    std::fill(std::begin(data), std::end(data), 0);
    int data_pointer = 0;
    
    int i = 0;
    while (i < tokens.size()) {
        // int day = (int) argv[1];
        if (tokens[i] == "INDXUP") {
            data_pointer++;
            i++;
        } else if (tokens[i] == "INDXDOWN") {
            data_pointer--;
            i++;
        } else if (tokens[i] == "PLUS") {
            data[data_pointer]++;
            i++;
        } else if (tokens[i] == "MINUS") {
            data[data_pointer]--;
            i++;
        } else if (tokens[i] == "PRINT") {
            std::cout << data[data_pointer] << "\n";
            i++;
        } else if (tokens[i] == "INPUT") {
            int user_input;
            std::cin >> user_input;
            data[data_pointer] = user_input;
            i++;
        } else { // Past this point, we evaluate statements that have arguments.

            if (tokens[i] == "BUFGATE") {
                int arg = data[std::stoi(tokens[i+1])];
                int return_place = std::stoi(tokens[i+2]);
                int return_value = bufgate.eval(arg);
                data[return_place] = return_value;
                i+=3;

            } else if (tokens[i] == "NOTGATE") {
                int arg = data[std::stoi(tokens[i+1])];
                int return_place = std::stoi(tokens[i+2]);
                int return_value = notgate.eval(arg);
                data[return_place] = return_value;
                i+=3;

            } else if (tokens[i] == "ANDGATE") {
                int inp1 = data[std::stoi(tokens[i+1])];
                int inp2 = data[std::stoi(tokens[i+2])];
                int return_place = std::stoi(tokens[i+3]);
                int return_value = andgate.eval(inp1, inp2);
                data[return_place] = return_value;
                i+=4;
                
            } else if (tokens[i] == "NANDGATE") {
                int inp1 = data[std::stoi(tokens[i+1])];
                int inp2 = data[std::stoi(tokens[i+2])];
                int return_place = std::stoi(tokens[i+3]);
                int return_value = nandgate.eval(inp1, inp2);
                data[return_place] = return_value;
                i+=4;
                
            } else if (tokens[i] == "NORGATE") {
                int inp1 = data[std::stoi(tokens[i+1])];
                int inp2 = data[std::stoi(tokens[i+2])];
                int return_place = std::stoi(tokens[i+3]);
                int return_value = norgate.eval(inp1, inp2);
                data[return_place] = return_value;
                i+=4;

            } else if (tokens[i] == "ORGATE") {
                int inp1 = data[std::stoi(tokens[i+1])];
                int inp2 = data[std::stoi(tokens[i+2])];
                int return_place = std::stoi(tokens[i+3]);
                int return_value = orgate.eval(inp1, inp2);
                data[return_place] = return_value;
                i+=4;

            } else if (tokens[i] == "XORGATE") {
                int inp1 = data[std::stoi(tokens[i+1])];
                int inp2 = data[std::stoi(tokens[i+2])];
                int return_place = std::stoi(tokens[i+3]);
                int return_value = xorgate.eval(inp1, inp2);
                data[return_place] = return_value;
                i+=4;

            } else if (tokens[i] == "XNORGATE") {
                int inp1 = data[std::stoi(tokens[i+1])];
                int inp2 = data[std::stoi(tokens[i+2])];
                int return_place = std::stoi(tokens[i+3]);
                int return_value = xnorgate.eval(inp1, inp2);
                data[return_place] = return_value;
                i+=4;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // LOGIC GATES DECLARATIONS

    logic_gate_1 notgate; // NOT
    int not_truth_table_results[2] = {1, 0};
    notgate.define("NOT", not_truth_table_results);

    logic_gate_1 bufgate; // BUF
    int buf_truth_table_results[2] = {0, 1};
    bufgate.define("BUF", buf_truth_table_results);

    logic_gate andgate; // AND
    int and_truth_table_results[4] = {0, 0, 0, 1};
    andgate.define("AND", and_truth_table_results);

    logic_gate nandgate; // NAND
    int nand_truth_table_results[4] = {1, 1, 1, 0};
    nandgate.define("NAND", nand_truth_table_results);

    logic_gate norgate; // NOR
    int nor_truth_table_results[4] = {1, 0, 0, 0};
    norgate.define("NOR", nor_truth_table_results);

    logic_gate orgate; // OR
    int or_truth_table_results[4] = {0, 1, 1, 1};
    orgate.define("OR", or_truth_table_results);

    logic_gate xorgate; // XOR
    int xor_truth_table_results[4] = {0, 1, 1, 0};
    xorgate.define("XOR", xor_truth_table_results);

    logic_gate xnorgate; // XNOR
    int xnor_truth_table_results[4] = {1, 0, 0, 1};
    xnorgate.define("XNOR", xnor_truth_table_results);

    try
    {
        std::string filename = argv[1];
        std::string filecontent;
        std::ifstream inputFile(filename);
        if (!inputFile) {
            std::cerr << "Error opening .lk file: " << filename << std::endl;
            return 1;
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            filecontent += line + "\n";
        }
        inputFile.close();
        std::vector <std::string> toks = tokenize(filecontent);
        interpret(toks);

    }
    catch(const std::exception& e)
    {
        std::cout << "Usage : logik <filename>.lk";
        //std::cerr << e.what() << '\n';
    }
    
    

    



    // INTERPRETING/TESTING
    //interpret();
    
    return 0;
}