//
// Created by zagorodnikov on 02.04.2025.
//

#ifndef COMTRADE_PARSER_H
#define COMTRADE_PARSER_H
#include "comtrade.h"

namespace comtrade {

class ComtradeParser {
  public:
    ComtradeFile GenerateComtradeParser(const std::string& file_name);
};

} // comtrade

#endif //COMTRADE_PARSER_H
