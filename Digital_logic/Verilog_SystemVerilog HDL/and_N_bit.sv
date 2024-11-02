module and #(parameter WIDTH = N)
            (input  logic [N-1:0] a, 
            output logic       y);

   assign y = &a;

endmodule
