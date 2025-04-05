//
// Created by zagorodnikov on 02.04.2025.
//
#include <string>  

#ifndef COMTRADE_PARSER_H
#define COMTRADE_PARSER_H

#define CONDITION_FOR_VAR(COND, VAR) if(COND) VAR = p_ ## VAR; else throw "Inappropriate value!";

namespace comtrade {

using std::string;

class ComtradeParser {
  public:
    ComtradeParser();
};

class AnalogSignal {
  public:
    unsigned An;
    string ch_id, ph, ccbm, uu;
    float a, b, skew, min, max, primary, secondary;
    char PS;

    AnalogSignal(unsigned p_An, string p_ch_id, string p_uu, float p_a, float p_b, float p_skew, float p_min, 
      float p_max, float p_primary, float p_secondary, char p_PS, string p_ph="", string p_ccbm=""){
        CONDITION_FOR_VAR(p_An > 0 && p_An <= 999999, An)
        CONDITION_FOR_VAR(p_ch_id.length() > 0 && p_ch_id.length() <= 128, ch_id)
        CONDITION_FOR_VAR(p_ph.length() <= 2, ph)
        CONDITION_FOR_VAR(p_ccbm.length() <= 64, ccbm)
        CONDITION_FOR_VAR(p_uu.length() > 0 && p_uu.length() <= 32, uu)
        a = p_a;
        b = p_b;
        skew = p_skew;
        if(p_min > p_max) throw "Inappropriate value!";
        CONDITION_FOR_VAR(p_min > -3.4028236e38 && p_min < 3.4028236e38, min)
        CONDITION_FOR_VAR(p_max > -3.4028236e38 && p_max < 3.4028236e38, max)
        primary = p_primary;
        secondary = p_secondary;
        CONDITION_FOR_VAR(p_PS == 'P' || p_PS == 'p' || p_PS == 'S' || p_PS == 's', PS)
      }
};

class DigitalSignal {
  public:
    unsigned Dn; 
    string ch_id, ph, ccbm;
    bool y;
    
    DigitalSignal(unsigned p_Dn, string p_ch_id, bool p_y, string p_ph="", string p_ccbm=""){
      CONDITION_FOR_VAR(p_Dn > 0 && p_Dn <= 999999, Dn)
      CONDITION_FOR_VAR(p_ch_id.length() > 0 && p_ch_id.length() <= 128, ch_id)
      CONDITION_FOR_VAR(p_ph.length() <= 2, ph)
      CONDITION_FOR_VAR(p_ccbm.length() <= 64, ccbm)
      y = p_y;
      }
};

} // comtrade

#endif //COMTRADE_PARSER_H
