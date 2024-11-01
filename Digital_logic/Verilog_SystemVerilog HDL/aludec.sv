module aludecoder(input  logic [1:0] ALUOp,
                  input  logic [2:0] funct3,
                  input  logic op_5, funct7_5,
                  output logic [2:0] ALUControl);

        assign ALUControl[2] = (ALUOp[1]) & (~ALUOp[0]) & (~funct3[2]) & (funct3[1]) & ~(funct3[0]);

        assign ALUControl[1] = ((ALUOp[1]) & (~ALUOp[0]) & (funct3[2]) & (funct3[1]) & (~funct3[0])) |
                           ((ALUOp[1]) & (~ALUOp[0]) & (funct3[2]) & (funct3[1]) & (funct3[0]));

        assign ALUControl[0] = ((~ALUOp[1]) & (ALUOp[0])) |
						((ALUOp[1]) & (~ALUOp[0]) & (~funct3[2]) & (~funct3[1]) & (~funct3[0]) & (op_5) & (funct7_5)) |
						((ALUOp[1]) & (~ALUOp[0]) & (~funct3[2]) & (funct3[1]) & (~funct3[0])) |
						((ALUOp[1]) & (~ALUOp[0]) & (funct3[2]) & (funct3[1]) & (~funct3[0]));

endmodule
