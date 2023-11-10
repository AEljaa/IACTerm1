module f1_fsm (
    input logic clk,
    input logic en,
    input logic rst,
    output logic [7:0] data_out //semi random output
);


//define states
typedef enum {S0,S1,S2,S3,S4,S5,S6,S7,S8} states;

states current_state, next_state;

//state transition
always_ff @(posedge clk)
    if (rst)
        current_state <= S0;
    else
        current_state <= next_state;

// next state logic
always_comb
    case(current_state)
        S0: if(en) next_state = S1;
            else next_state=current_state;

        S1: if(en) next_state = S2;
            else next_state=current_state;

        S2: if(en) next_state = S3;
            else next_state=current_state;
        
        S3: if(en) next_state = S4;
            else next_state=current_state;
        
        S4: if(en) next_state = S5;
            else next_state=current_state;
        
        S5: if(en) next_state = S6;
            else next_state=current_state;
        
        S6: if(en) next_state = S7;
            else next_state=current_state;
        
        S7: if(en) next_state = S8;
            else next_state=current_state;
        
        S8: if(en) next_state = S0;
            else next_state=current_state;
    
        default: next_state = S0;
    endcase
//output logic
always_comb
    case(current_state)
        S0: data_out=8'b0;
        S1: data_out[0] = 1'b1;
        S2: data_out[1] = 1'b1;
        S3: data_out[2] = 1'b1;
        S4: data_out[3] = 1'b1;
        S5: data_out[4] = 1'b1;
        S6: data_out[5] = 1'b1;
        S7: data_out[6] = 1'b1;
        S8: data_out[7] = 1'b1;
        default: data_out = 8'b0;
    endcase
endmodule

