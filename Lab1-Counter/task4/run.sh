#!/bin/sh
# cleanup
rm -rf obj_dir
rm -r Vbin2bcd.vcd


# run Verilator so we can translate .sv into .cpp, and pass this to our C++ testbench


verilator -Wall --cc --trace bin2bcd.sv top.sv counter.sv --exe top_tb.cpp

#build the C++ project through make automatically generated by verilator

make -j -C obj_dir/ -f Vbin2bcd.mk Vbin2bcd 

#run the executable simulation file

obj_dir/Vbin2bcd


