module inv #(parameter WIDTH = N)
            (input  logic [N-1:0] a,
             output logic [N-1:0] y);

  assign y = ~a;
endmodule
