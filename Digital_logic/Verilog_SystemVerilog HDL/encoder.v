module encoder(input Y0,Y1,Y2,Y3,
                output [1:0]A);

    assign A[0] = Y2 | Y3;
    assign A[1] = Y1 | Y3;

endmodule

// Can work on both SystemVerilog and Verilog HDL
