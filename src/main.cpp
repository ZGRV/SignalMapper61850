//
// Created by zagorodnikov on 02.04.2025.
//

#include <iostream>
#include <string>
#include "comtrade/comtrade.h"
#include "comtrade/comtrade_parser.h"

int main() {
  //std::cout << "Hello, World!" << std::endl;
  comtrade::ComtradeParser parser_instance;
  std::string file_name = "./5.2.CFF";
  std::optional<std::pair<comtrade::ComtradeFile, comtrade::ComtradeData>> buff = parser_instance.Parse(file_name);
  try {
    comtrade::ComtradeFile comp_file = buff.value().first;
    std::cout << comp_file.GetTriggerPoint().GetYear() << std::endl;
    std::cout << comp_file.GetDigitalSignal(8).GetChId() << std::endl;
    std::cout << comp_file.GetEndSamp() << " " << comp_file.GetAnalogCount() << std::endl;
  } catch(const std::bad_optional_access& e) {
      std::cerr << "Comtrade File does not exist" << std::endl;
  }
  return 0;
}
