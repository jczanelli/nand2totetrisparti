# nand2totetrisparti
Nand 2 Tetris Part I Week 6



Partial Assembler for Nand 2 to Tetris Part I course from Coursera.

The assembler receives a *.asm as input, parses the file and convert it to binary.

There are six *.cpp files in the Assembler:

    main.cpp;
    parser.cpp: parses the file, removing blank lines and commentaries;
    write_file.cpp: opens the *.asm file for reading;
    first_pass.cpp: analyses labels and change them for line number of reference;
    second_pass.cpp: converts the whole file to binary;
    symbol_table.cpp: list of instructions and their binary value.

There's also a header file: header.hpp.

The Assembler works with: add, max and rect. It does not work with pong because of Special Instructions (stack instructions) on the pong.asm file.
