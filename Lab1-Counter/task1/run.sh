#!/bin/sh
# cleanup
rm -rf obj_dir
rm -r counter.vcd


# run Verilator so we can translate .sv into .cpp, and pass this to our C++ testbench


verilator -Wall --cc --trace counter.sv --exe counter_tb.cpp

#build the C++ project through make automatically generated by verilator

make -j -C obj_dir/ -f Vcounter.mk Vcounter

#run the executable simulation file

obj_dir/Vcounter

#open gtkWave

gtkWave Vcounter.vcd
