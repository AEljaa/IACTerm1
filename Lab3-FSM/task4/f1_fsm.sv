module f1_fsm (
    input logic clk,
    input logic en,
    input logic trigger,
    input logic rst,
    output logic [7:0] data_out, // Output data
    output logic cmd_seq, // Control signal for sequencing
    output logic cmd_delay // Control signal for delay component
);

// Define states
typedef enum {S0, S1, S2, S3, S4, S5, S6, S7, S8} states;

states current_state, next_state;

// State transition
always_ff @(posedge clk, posedge rst)
    if (rst)
        current_state <= S0;
    else begin
        if (trigger)
            current_state <= next_state;
    end

// Next state logic
always_comb
    case(current_state)
        S0: 
            if (en) next_state = S1;
            else next_state = current_state;
        S1: 
            if (en) next_state = S2;
            else next_state = current_state;
        S2: 
            if (en) next_state = S3;
            else next_state = current_state;
        S3: 
            if (en) next_state = S4;
            else next_state = current_state;
        S4: 
            if (en) next_state = S5;
            else next_state = current_state;
        S5: 
            if (en) next_state = S6;
            else next_state = current_state;
        S6: 
            if (en) next_state = S7;
            else next_state = current_state;
        S7: 
            if (en) next_state = S8;
            else next_state = current_state;
        S8: 
            if (en) next_state = S0;
            else next_state = current_state;
        default: 
            next_state = S0;
    endcase

// Output logic
always_comb
    case(current_state)
        S0: 
            begin
                data_out = 8'b0;
                cmd_delay = 0;
                cmd_seq=1;
            end
        S1: 
            begin
                data_out = 8'b00000001;
                cmd_delay = 0;
                cmd_seq=1;
            end
        S2: 
            begin
                data_out = 8'b00000011;
                cmd_delay = 0;
                cmd_seq=1;
            end
        S3: 
            begin
                data_out = 8'b00000111;
                cmd_delay = 0;
                cmd_seq=1;
            end
        S4: 
            begin
                data_out = 8'b00001111;
                cmd_delay = 0;
                cmd_seq=1;
            end
        S5: 
            begin
                data_out = 8'b00011111;
                cmd_delay = 0;
                cmd_seq=1;
            end
        S6: 
            begin
                data_out = 8'b00111111;
                cmd_delay = 0;
                cmd_seq=1;
            end
        S7: 
            begin
                data_out = 8'b01111111;
                cmd_delay = 0;
                cmd_seq=1;
            end
        S8: 
            begin
                data_out = 8'b11111111;
                cmd_delay = 1;
                cmd_seq=0;
            end
        default: 
            begin
                data_out = 8'b00000000;
                cmd_delay = 0;
                cmd_seq=0;
            end
    endcase
endmodule

