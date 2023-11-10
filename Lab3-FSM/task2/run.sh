#!/bin/sh
# cleanup
rm -rf obj_dir
rm -r Vf1_fsm.vcd


# run Verilator so we can translate .sv into .cpp, and pass this to our C++ testbench


verilator -Wall --cc --trace f1_fsm.sv --exe f1_fsm_tb.cpp

#build the C++ project through make automatically generated by verilator

make -j -C obj_dir/ -f Vf1_fsm.mk Vf1_fsm

#run the executable simulation file

obj_dir/Vf1_fsm

