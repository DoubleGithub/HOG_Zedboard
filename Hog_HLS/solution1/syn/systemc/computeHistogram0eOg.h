// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.4
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef __computeHistogram0eOg_H__
#define __computeHistogram0eOg_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct computeHistogram0eOg_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 11;
  static const unsigned AddressRange = 256;
  static const unsigned AddressWidth = 8;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(computeHistogram0eOg_ram) {
        ram[0] = "0b00000000000";
        ram[1] = "0b00000000101";
        ram[2] = "0b00000001011";
        ram[3] = "0b00000010001";
        ram[4] = "0b00000010110";
        ram[5] = "0b00000011100";
        ram[6] = "0b00000100010";
        ram[7] = "0b00000100111";
        ram[8] = "0b00000101101";
        ram[9] = "0b00000110011";
        ram[10] = "0b00000111000";
        ram[11] = "0b00000111110";
        ram[12] = "0b00001000100";
        ram[13] = "0b00001001001";
        ram[14] = "0b00001001111";
        ram[15] = "0b00001010101";
        ram[16] = "0b00001011010";
        ram[17] = "0b00001100000";
        ram[18] = "0b00001100110";
        ram[19] = "0b00001101011";
        ram[20] = "0b00001110001";
        ram[21] = "0b00001110111";
        ram[22] = "0b00001111100";
        ram[23] = "0b00010000010";
        ram[24] = "0b00010001000";
        ram[25] = "0b00010001101";
        ram[26] = "0b00010010011";
        ram[27] = "0b00010011001";
        ram[28] = "0b00010011110";
        ram[29] = "0b00010100100";
        ram[30] = "0b00010101010";
        ram[31] = "0b00010101111";
        ram[32] = "0b00010110101";
        ram[33] = "0b00010111011";
        ram[34] = "0b00011000000";
        ram[35] = "0b00011000110";
        ram[36] = "0b00011001100";
        ram[37] = "0b00011010001";
        ram[38] = "0b00011010111";
        ram[39] = "0b00011011101";
        ram[40] = "0b00011100010";
        ram[41] = "0b00011101000";
        ram[42] = "0b00011101110";
        ram[43] = "0b00011110011";
        ram[44] = "0b00011111001";
        ram[45] = "0b00011111111";
        ram[46] = "0b00100000100";
        ram[47] = "0b00100001010";
        ram[48] = "0b00100010000";
        ram[49] = "0b00100010101";
        ram[50] = "0b00100011011";
        ram[51] = "0b00100100001";
        ram[52] = "0b00100100110";
        ram[53] = "0b00100101100";
        ram[54] = "0b00100110010";
        ram[55] = "0b00100110111";
        ram[56] = "0b00100111101";
        ram[57] = "0b00101000011";
        ram[58] = "0b00101001000";
        ram[59] = "0b00101001110";
        ram[60] = "0b00101010100";
        ram[61] = "0b00101011001";
        ram[62] = "0b00101011111";
        ram[63] = "0b00101100101";
        ram[64] = "0b00101101010";
        ram[65] = "0b00101110000";
        ram[66] = "0b00101110110";
        ram[67] = "0b00101111011";
        ram[68] = "0b00110000001";
        ram[69] = "0b00110000111";
        ram[70] = "0b00110001100";
        ram[71] = "0b00110010010";
        ram[72] = "0b00110011000";
        ram[73] = "0b00110011101";
        ram[74] = "0b00110100011";
        ram[75] = "0b00110101001";
        ram[76] = "0b00110101110";
        ram[77] = "0b00110110100";
        ram[78] = "0b00110111010";
        ram[79] = "0b00110111111";
        ram[80] = "0b00111000101";
        ram[81] = "0b00111001011";
        ram[82] = "0b00111010000";
        ram[83] = "0b00111010110";
        ram[84] = "0b00111011100";
        ram[85] = "0b00111100001";
        ram[86] = "0b00111100111";
        ram[87] = "0b00111101101";
        ram[88] = "0b00111110010";
        ram[89] = "0b00111111000";
        ram[90] = "0b00111111110";
        ram[91] = "0b01000000011";
        ram[92] = "0b01000001001";
        ram[93] = "0b01000001111";
        ram[94] = "0b01000010100";
        ram[95] = "0b01000011010";
        ram[96] = "0b01000100000";
        ram[97] = "0b01000100101";
        ram[98] = "0b01000101011";
        ram[99] = "0b01000110001";
        ram[100] = "0b01000110110";
        ram[101] = "0b01000111100";
        ram[102] = "0b01001000010";
        ram[103] = "0b01001001000";
        ram[104] = "0b01001001101";
        ram[105] = "0b01001010011";
        ram[106] = "0b01001011001";
        ram[107] = "0b01001011110";
        ram[108] = "0b01001100100";
        ram[109] = "0b01001101010";
        ram[110] = "0b01001101111";
        ram[111] = "0b01001110101";
        ram[112] = "0b01001111011";
        ram[113] = "0b01010000000";
        ram[114] = "0b01010000110";
        ram[115] = "0b01010001100";
        ram[116] = "0b01010010001";
        ram[117] = "0b01010010111";
        ram[118] = "0b01010011101";
        ram[119] = "0b01010100010";
        ram[120] = "0b01010101000";
        ram[121] = "0b01010101110";
        ram[122] = "0b01010110011";
        ram[123] = "0b01010111001";
        ram[124] = "0b01010111111";
        ram[125] = "0b01011000100";
        ram[126] = "0b01011001010";
        ram[127] = "0b01011010000";
        ram[128] = "0b01011010101";
        ram[129] = "0b01011011011";
        ram[130] = "0b01011100001";
        ram[131] = "0b01011100110";
        ram[132] = "0b01011101100";
        ram[133] = "0b01011110010";
        ram[134] = "0b01011110111";
        ram[135] = "0b01011111101";
        ram[136] = "0b01100000011";
        ram[137] = "0b01100001000";
        ram[138] = "0b01100001110";
        ram[139] = "0b01100010100";
        ram[140] = "0b01100011001";
        ram[141] = "0b01100011111";
        ram[142] = "0b01100100101";
        ram[143] = "0b01100101010";
        ram[144] = "0b01100110000";
        ram[145] = "0b01100110110";
        ram[146] = "0b01100111011";
        ram[147] = "0b01101000001";
        ram[148] = "0b01101000111";
        ram[149] = "0b01101001100";
        ram[150] = "0b01101010010";
        ram[151] = "0b01101011000";
        ram[152] = "0b01101011101";
        ram[153] = "0b01101100011";
        ram[154] = "0b01101101001";
        ram[155] = "0b01101101110";
        ram[156] = "0b01101110100";
        ram[157] = "0b01101111010";
        ram[158] = "0b01101111111";
        ram[159] = "0b01110000101";
        ram[160] = "0b01110001011";
        ram[161] = "0b01110010000";
        ram[162] = "0b01110010110";
        ram[163] = "0b01110011100";
        ram[164] = "0b01110100001";
        ram[165] = "0b01110100111";
        ram[166] = "0b01110101101";
        ram[167] = "0b01110110010";
        ram[168] = "0b01110111000";
        ram[169] = "0b01110111110";
        ram[170] = "0b01111000011";
        ram[171] = "0b01111001001";
        ram[172] = "0b01111001111";
        ram[173] = "0b01111010100";
        ram[174] = "0b01111011010";
        ram[175] = "0b01111100000";
        ram[176] = "0b01111100101";
        ram[177] = "0b01111101011";
        ram[178] = "0b01111110001";
        ram[179] = "0b01111110110";
        ram[180] = "0b01111111100";
        ram[181] = "0b10000000010";
        ram[182] = "0b10000000111";
        ram[183] = "0b10000001101";
        ram[184] = "0b10000010011";
        ram[185] = "0b10000011000";
        ram[186] = "0b10000011110";
        ram[187] = "0b10000100100";
        ram[188] = "0b10000101001";
        ram[189] = "0b10000101111";
        ram[190] = "0b10000110101";
        ram[191] = "0b10000111010";
        ram[192] = "0b10001000000";
        ram[193] = "0b10001000110";
        ram[194] = "0b10001001011";
        ram[195] = "0b10001010001";
        ram[196] = "0b10001010111";
        ram[197] = "0b10001011100";
        ram[198] = "0b10001100010";
        ram[199] = "0b10001101000";
        ram[200] = "0b10001101101";
        ram[201] = "0b10001110011";
        ram[202] = "0b10001111001";
        ram[203] = "0b10001111110";
        ram[204] = "0b10010000100";
        ram[205] = "0b10010001010";
        ram[206] = "0b10010010000";
        ram[207] = "0b10010010101";
        ram[208] = "0b10010011011";
        ram[209] = "0b10010100001";
        ram[210] = "0b10010100110";
        ram[211] = "0b10010101100";
        ram[212] = "0b10010110010";
        ram[213] = "0b10010110111";
        ram[214] = "0b10010111101";
        ram[215] = "0b10011000011";
        ram[216] = "0b10011001000";
        ram[217] = "0b10011001110";
        ram[218] = "0b10011010100";
        ram[219] = "0b10011011001";
        ram[220] = "0b10011011111";
        ram[221] = "0b10011100101";
        ram[222] = "0b10011101010";
        ram[223] = "0b10011110000";
        ram[224] = "0b10011110110";
        ram[225] = "0b10011111011";
        ram[226] = "0b10100000001";
        ram[227] = "0b10100000111";
        ram[228] = "0b10100001100";
        ram[229] = "0b10100010010";
        ram[230] = "0b10100011000";
        ram[231] = "0b10100011101";
        ram[232] = "0b10100100011";
        ram[233] = "0b10100101001";
        ram[234] = "0b10100101110";
        ram[235] = "0b10100110100";
        ram[236] = "0b10100111010";
        ram[237] = "0b10100111111";
        ram[238] = "0b10101000101";
        ram[239] = "0b10101001011";
        ram[240] = "0b10101010000";
        ram[241] = "0b10101010110";
        ram[242] = "0b10101011100";
        ram[243] = "0b10101100001";
        ram[244] = "0b10101100111";
        ram[245] = "0b10101101101";
        ram[246] = "0b10101110010";
        ram[247] = "0b10101111000";
        ram[248] = "0b10101111110";
        ram[249] = "0b10110000011";
        ram[250] = "0b10110001001";
        ram[251] = "0b10110001111";
        ram[252] = "0b10110010100";
        ram[253] = "0b10110011010";
        ram[254] = "0b10110100000";
        ram[255] = "0b10110100101";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(computeHistogram0eOg) {


static const unsigned DataWidth = 11;
static const unsigned AddressRange = 256;
static const unsigned AddressWidth = 8;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


computeHistogram0eOg_ram* meminst;


SC_CTOR(computeHistogram0eOg) {
meminst = new computeHistogram0eOg_ram("computeHistogram0eOg_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~computeHistogram0eOg() {
    delete meminst;
}


};//endmodule
#endif
