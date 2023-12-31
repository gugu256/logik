# Logik

An esoteric programming language inspired by BrainFuck and logic gates.

Like in brainfuck, you start with an array of integers that is 256 elements long. Indexing starts at 0.

## Instructions :

#### Regular BrainFuck Instructions :
`+` : Increases the current cell by 1<br>
`-` : Decreases the current cell by 1<br>
`.` : Prints the current cell's value<br>
`,` : Sets the current cell's value to whatever the user inputs<br>

#### Logic Gates :
`NOT` : NOT gate. Accepts 1 argument.<br>
`BUF` : Buffer Gate. Accepts 1 argument and returns the exact same argument. It's useful for copying values from one cell to another<br>
`AND` : AND gate. Accepts 2 arguments.<br>
`NAND` : NAND gate. Accepts 2 arguments.<br>
`NOR` : NOR gate. Accepts 2 arguments.<br>
`OR` : OR gate. Accepts 2 arguments.<br>
`XOR` : XOR gate. Accepts 2 arguments.<br>
`XNOR` : XNOR gate. Accepts 2 arguments

#### Example Syntax :

Example Logic Gate Syntax :

`NOT 30 31` : The program takes the value from the 30th cell in the array, passes it through a NOT gate and returns the value of the NOT gate in the 31st cell of the array.

`XOR 12 13 20` : The program takes the values from the 12th and 13th cells in the array, then passes those values in an XOR logic gate and returns the value of the XOR logic gate in the 20th cell of the array. Of course, you can replace the `XOR` gate by any other logic gate that The Logik Programming Language supports.

`BUF 6 8` : The program takes the value from the 6th cell in the array and copies it to the 8th cell of the array.

`, > , AND 0 1 2 > .` : In this small program, the user defines the values of the first two cells (0 and 1). Then, the program checks if those values are both `1` using the `AND` Gate. Then, the data pointer moves the the third cell of the program's array and prints its value. If the value is 0, then the user did not write 1 and 1, if the value is 1, then the user wrote 1 and 1.

And that's it!<br>
All of these logic gates have their truth tables documented [here.](https://en.wikipedia.org/wiki/Logic_gate#Symbols)

Example 2-bit adder : 
```
+>+>+<<

XOR 0 1 10
AND 0 1 12

XOR 10 2 20
AND 10 2 15

OR 15 12 21

>>>>>>>>>>>>>>>>>>>>.>.
```

## Usage :

First, download the `logik.exe` file [here](/build/logik.exe)

Then, execute this line of code in your terminal :<br>
`$ logik.exe program.lk`

*If you want to port the project to your system, just `g++ main.cpp` and open a pull request with your executable!*

### Built with
![Built With C++](https://skillicons.dev/icons?i=cpp)